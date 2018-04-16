(function ($) {

  /**
   * Add an asterisk or other marker to the changed row.
   */
  Drupal.tableDrag.prototype.row.prototype.markChanged = function () {
    var $cell = $('td:first', this.element);
    // Find the first appropriate place to insert the marker.
    var $target = $($cell.find('.file-size').get(0) || $cell.find('.file').get(0) || $cell.find('.tabledrag-handle').get(0));
    if (!$cell.find('.tabledrag-changed').length) {
      $target.after(' ' + Drupal.theme('tableDragChangedMarker') + ' ');
    }
  };

})(jQuery);
;
(function ($) {

/**
 * Override Drupal's AJAX prototype beforeSend function so it can append the
 * throbber inside the pager links.
 */
Drupal.ajax.prototype.beforeSend = function (xmlhttprequest, options) {
  // For forms without file inputs, the jQuery Form plugin serializes the form
  // values, and then calls jQuery's $.ajax() function, which invokes this
  // handler. In this circumstance, options.extraData is never used. For forms
  // with file inputs, the jQuery Form plugin uses the browser's normal form
  // submission mechanism, but captures the response in a hidden IFRAME. In this
  // circumstance, it calls this handler first, and then appends hidden fields
  // to the form to submit the values in options.extraData. There is no simple
  // way to know which submission mechanism will be used, so we add to extraData
  // regardless, and allow it to be ignored in the former case.
  if (this.form) {
    options.extraData = options.extraData || {};

    // Let the server know when the IFRAME submission mechanism is used. The
    // server can use this information to wrap the JSON response in a TEXTAREA,
    // as per http://jquery.malsup.com/form/#file-upload.
    options.extraData.ajax_iframe_upload = '1';

    // The triggering element is about to be disabled (see below), but if it
    // contains a value (e.g., a checkbox, textfield, select, etc.), ensure that
    // value is included in the submission. As per above, submissions that use
    // $.ajax() are already serialized prior to the element being disabled, so
    // this is only needed for IFRAME submissions.
    var v = $.fieldValue(this.element);
    if (v !== null) {
      options.extraData[this.element.name] = v;
    }
  }

  var $element = $(this.element);

  // Disable the element that received the change to prevent user interface
  // interaction while the Ajax request is in progress. ajax.ajaxing prevents
  // the element from triggering a new request, but does not prevent the user
  // from changing its value.
  $element.addClass('progress-disabled').attr('disabled', true);

  // Insert progressbar or throbber.
  if (this.progress.type == 'bar') {
    var progressBar = new Drupal.progressBar('ajax-progress-' + this.element.id, eval(this.progress.update_callback), this.progress.method, eval(this.progress.error_callback));
    if (this.progress.message) {
      progressBar.setProgress(-1, this.progress.message);
    }
    if (this.progress.url) {
      progressBar.startMonitoring(this.progress.url, this.progress.interval || 500);
    }
    this.progress.element = $(progressBar.element).addClass('ajax-progress ajax-progress-bar');
    this.progress.object = progressBar;
    $element.closest('.file-widget,.form-item').after(this.progress.element);
  }
  else if (this.progress.type == 'throbber') {
    this.progress.element = $('<div class="ajax-progress ajax-progress-throbber"><i class="glyphicon glyphicon-refresh glyphicon-spin"></i></div>');
    if (this.progress.message) {
      $('.throbber', this.progress.element).after('<div class="message">' + this.progress.message + '</div>');
    }

    // If element is an input type, append after.
    if ($element.is('input')) {
      $element.after(this.progress.element);
    }
    else if ($element.is('select')) {
      var $inputGroup = $element.closest('.form-item').find('.input-group-addon, .input-group-btn');
      if (!$inputGroup.length) {
        $element.wrap('<div class="input-group">');
        $inputGroup = $('<span class="input-group-addon">');
        $element.after($inputGroup);
      }
      $inputGroup.append(this.progress.element);
    }
    // Otherwise append the throbber inside the element.
    else {
      $element.append(this.progress.element);
    }
  }
};

})(jQuery);
;
(function ($) {

/**
 * Attaches the autocomplete behavior to all required fields.
 */
Drupal.behaviors.autocomplete = {
  attach: function (context) {
    var $context = $(context);
    var acdb = [];
    $context.find('input.autocomplete').once('autocomplete', function () {
      var uri = this.value;
      if (!acdb[uri]) {
        acdb[uri] = new Drupal.ACDB(uri);
      }
      var $input = $context.find('#' + this.id.substr(0, this.id.length - 13))
        .attr('autocomplete', 'OFF')
        .attr('aria-autocomplete', 'list');
      $context.find($input[0].form).submit(Drupal.autocompleteSubmit);
      $input.parents('.form-item')
        .attr('role', 'application')
        .append($('<span class="element-invisible" aria-live="assertive"></span>')
          .attr('id', $input.attr('id') + '-autocomplete-aria-live')
      );
      new Drupal.jsAC($input, acdb[uri], $context);
    });
  }
};

/**
 * Prevents the form from submitting if the suggestions popup is open
 * and closes the suggestions popup when doing so.
 */
Drupal.autocompleteSubmit = function () {
  return $('.form-autocomplete > .dropdown').each(function () {
    this.owner.hidePopup();
  }).length == 0;
};

/**
 * Highlights a suggestion.
 */
Drupal.jsAC.prototype.highlight = function (node) {
  if (this.selected) {
    $(this.selected).removeClass('active');
  }
  $(node).addClass('active');
  this.selected = node;
  $(this.ariaLive).html($(this.selected).html());
};

/**
 * Unhighlights a suggestion.
 */
Drupal.jsAC.prototype.unhighlight = function (node) {
  $(node).removeClass('active');
  this.selected = false;
  $(this.ariaLive).empty();
};

/**
 * Positions the suggestions popup and starts a search.
 */
Drupal.jsAC.prototype.populatePopup = function () {
  var $input = $(this.input);
  // Show popup.
  if (this.popup) {
    $(this.popup).remove();
  }
  this.selected = false;
  this.popup = $('<div class="dropdown"></div>')[0];
  this.popup.owner = this;
  $input.parent().after(this.popup);

  // Do search.
  this.db.owner = this;
  this.db.search(this.input.value);
};

/**
 * Fills the suggestion popup with any matches received.
 */
Drupal.jsAC.prototype.found = function (matches) {
  // If no value in the textfield, do not show the popup.
  if (!this.input.value.length) {
    return false;
  }

  // Prepare matches.
  var ul = $('<ul class="dropdown-menu"></ul>');
  var ac = this;
  ul.css({
    display: 'block',
    right: 0
  });
  for (var key in matches) {
    $('<li></li>')
      .html($('<a href="#"></a>').html(matches[key]).on('click', function (e) { e.preventDefault(); }))
      .on('mousedown', function () { ac.hidePopup(this); })
      .on('mouseover', function () { ac.highlight(this); })
      .on('mouseout', function () { ac.unhighlight(this); })
      .data('autocompleteValue', key)
      .appendTo(ul);
  }

  // Show popup with matches, if any.
  if (this.popup) {
    if (ul.children().length) {
      $(this.popup).empty().append(ul).show();
      $(this.ariaLive).html(Drupal.t('Autocomplete popup'));
    }
    else {
      $(this.popup).css({ visibility: 'hidden' });
      this.hidePopup();
    }
  }
};

Drupal.jsAC.prototype.setStatus = function (status) {
  var $throbber = $(this.input).parent().find('.glyphicon-refresh, .autocomplete-throbber').first();
  var throbbingClass = $throbber.is('.autocomplete-throbber') ? 'throbbing' : 'glyphicon-spin';
  switch (status) {
    case 'begin':
      $throbber.addClass(throbbingClass);
      $(this.ariaLive).html(Drupal.t('Searching for matches...'));
      break;
    case 'cancel':
    case 'error':
    case 'found':
      $throbber.removeClass(throbbingClass);
      break;
  }
};

// Save the previous autocomplete prototype.
var oldPrototype = Drupal.jsAC.prototype;

/**
 * Override the autocomplete constructor.
 */
Drupal.jsAC = function ($input, db, context) {
  var ac = this;

  // Context is normally passed by Drupal.behaviors.autocomplete above. However,
  // if a module has manually invoked this method they will likely not know
  // about this feature and a global fallback context to document must be used.
  // @see https://www.drupal.org/node/2594243
  // @see https://www.drupal.org/node/2315295
  this.$context = context && $(context) || $(document);

  this.input = $input[0];
  this.ariaLive = this.$context.find('#' + this.input.id + '-autocomplete-aria-live');
  this.db = db;
  $input
    .keydown(function (event) { return ac.onkeydown(this, event); })
    .keyup(function (event) { ac.onkeyup(this, event); })
    .blur(function () { ac.hidePopup(); ac.db.cancel(); });
};

// Restore the previous prototype.
Drupal.jsAC.prototype = oldPrototype;

})(jQuery);
;
(function ($) {
  // Override core JS so it works with "button" tags.
  /**
   * Attach behaviors to the file upload and remove buttons.
   */
  Drupal.behaviors.fileButtons = {
    attach: function (context) {
      $(':input.form-submit', context).bind('mousedown', Drupal.file.disableFields);
      $('div.form-managed-file :input.form-submit', context).bind('mousedown', Drupal.file.progressBar);
    },
    detach: function (context) {
      $(':input.form-submit', context).unbind('mousedown', Drupal.file.disableFields);
      $('div.form-managed-file :input.form-submit', context).unbind('mousedown', Drupal.file.progressBar);
    }
  };
  if (Drupal.file) {
    /**
     * Prevent file uploads when using buttons not intended to upload.
     */
    Drupal.file.disableFields = function (event){
      var clickedButton = this;

      // Only disable upload fields for Ajax buttons.
      if (!$(clickedButton).hasClass('ajax-processed')) {
        return;
      }

      // Check if we're working with an "Upload" button.
      var $enabledFields = [];
      if ($(this).closest('div.form-managed-file').length > 0) {
        $enabledFields = $(this).closest('div.form-managed-file').find(':input.form-file');
      }

      // Temporarily disable upload fields other than the one we're currently
      // working with. Filter out fields that are already disabled so that they
      // do not get enabled when we re-enable these fields at the end of behavior
      // processing. Re-enable in a setTimeout set to a relatively short amount
      // of time (1 second). All the other mousedown handlers (like Drupal's Ajax
      // behaviors) are excuted before any timeout functions are called, so we
      // don't have to worry about the fields being re-enabled too soon.
      // @todo If the previous sentence is true, why not set the timeout to 0?
      var $fieldsToTemporarilyDisable = $('div.form-managed-file :input.form-file').not($enabledFields).not(':disabled');
      $fieldsToTemporarilyDisable.attr('disabled', 'disabled');
      setTimeout(function (){
        $fieldsToTemporarilyDisable.attr('disabled', false);
      }, 1000);
    };
    /**
     * Add progress bar support if possible.
     */
    Drupal.file.progressBar = function (event) {
      var clickedButton = this;
      var $progressId = $(clickedButton).closest('div.form-managed-file').find(':input.file-progress');
      if ($progressId.length) {
        var originalName = $progressId.attr('name');

        // Replace the name with the required identifier.
        $progressId.attr('name', originalName.match(/APC_UPLOAD_PROGRESS|UPLOAD_IDENTIFIER/)[0]);

        // Restore the original name after the upload begins.
        setTimeout(function () {
          $progressId.attr('name', originalName);
        }, 1000);
      }
      // Show the progress bar if the upload takes longer than half a second.
      setTimeout(function () {
        $(clickedButton).closest('div.form-managed-file').find('div.ajax-progress-bar').slideDown();
      }, 500);
    };

    /**
     * Styling invalid file extension error message (Issue #2331595 by NetTantra).
     */
    Drupal.file.validateExtension = function (event) {
      // Remove any previous errors.
      $('.file-upload-js-error').remove();

      // Add client side validation for the input[type=file].
      var extensionPattern = event.data.extensions.replace(/,\s*/g, '|');
      if (extensionPattern.length > 1 && this.value.length > 0) {
        var acceptableMatch = new RegExp('\\.(' + extensionPattern + ')$', 'gi');
        if (!acceptableMatch.test(this.value)) {
          var error = Drupal.t("The selected file %filename cannot be uploaded. Only files with the following extensions are allowed: %extensions.", {
            // According to the specifications of HTML5, a file upload control
            // should not reveal the real local path to the file that a user
            // has selected. Some web browsers implement this restriction by
            // replacing the local path with "C:\fakepath\", which can cause
            // confusion by leaving the user thinking perhaps Drupal could not
            // find the file because it messed up the file path. To avoid this
            // confusion, therefore, we strip out the bogus fakepath string.
            '%filename': this.value.replace('C:\\fakepath\\', ''),
            '%extensions': extensionPattern.replace(/\|/g, ', ')
          });
          $(this).closest('div.form-managed-file').parents('.form-item').first().prepend('<div class="alert alert-danger alert-dismissible messages error file-upload-js-error" aria-live="polite" role="alert">\
            <button type="button" class="close" data-dismiss="alert">\
              <span aria-hidden="true">&times;</span>\
              <span class="sr-only">Close</span>\
            </button>' + error + '</div>');
          this.value = '';
          return false;
        }
      }
    };
  }
})(jQuery);
;
(function ($, Drupal) {

  Drupal.BootstrapPassword = function (element) {
    var self = this;
    var $element = $(element);
    this.settings = Drupal.settings.password;
    this.$wrapper = $element.parent().parent();
    this.$row = $('<div class="row">').prependTo(this.$wrapper);

    // The password object.
    this.password = {
      $input: $element,
      $label: $element.parent().find('label'),
      $wrapper: $element.parent().addClass('col-sm-6 col-md-4 has-feedback').appendTo(self.$row)
    };
    this.password.$icon = $('<span class="glyphicon form-control-feedback"></span>').appendTo(this.password.$wrapper);

    // Strength meter.
    this.strength = {
      $label: $('<div class="label" aria-live="assertive"></div>').appendTo(this.password.$label),
      $progress: $('<div class="progress"><div class="progress-bar" role="progressbar" aria-valuenow="0" aria-valuemin="0" aria-valuemax="100"></div></div>').appendTo(this.password.$wrapper)
    };
    this.strength.$bar = this.strength.$progress.find('.progress-bar');

    // The confirmation object.
    this.confirm = {
      $input: this.$wrapper.find('input.password-confirm')
    };
    this.confirm.$wrapper = this.confirm.$input.parent().addClass('col-sm-6 col-md-4 has-feedback').appendTo(self.$row);
    this.confirm.$icon = $('<span class="glyphicon form-control-feedback"></span>');

    // Bind events.
    this.password.$input.on('keyup focus blur', function () {
      self.validateStrength();
    });
    this.confirm.$input.on('keyup blur', function () {
      self.validateMatch();
    });

    // Add password help at the of row.
    this.$helpBlock = $('<div class="help-block password-help"></div>').appendTo(this.$row);

    return this;
  };

  /**
   * Helper method to switch classes on elements based on status.
   *
   * @param {jQuery} $element
   *   The jQuery element to modify.
   * @param {string} type
   *   The name of the class to switch to. Can be one of: "danger", "info",
   *   "success" or "warning".
   * @param {string} prefix
   *   The prefix to use. Typically this would be something like "label" or
   *   "progress-bar".
   */
  Drupal.BootstrapPassword.prototype.switchClass = function ($element, type, prefix) {
    prefix = prefix + '-' || '';
    var types = prefix === 'has-' ? ['error', 'warning', 'success'] : ['danger', 'info', 'success', 'warning'];
    if (type) {
      type = types.splice($.inArray(type, types), 1).shift();
      $element.addClass(prefix + type);
    }
    $element.removeClass(prefix + types.join(' ' + prefix));
  };

  /**
   * Validates the strength of a password.
   */
  Drupal.BootstrapPassword.prototype.validateStrength = function () {
    var result = Drupal.evaluatePasswordStrength(this.password.$input.val(), Drupal.settings.password);

    // Ensure visibility.
    this.$helpBlock.show();
    this.strength.$label.show();
    this.strength.$bar.show();

    // Update the suggestions for how to improve the password.
    this.$helpBlock.html(result.message);

    // Only show the description box if there is a weakness in the password.
    this.$helpBlock[result.strength === 100 ? 'hide' : 'show']();

    // Update the strength indication text.
    this.strength.$label.html(result.indicatorText);

    // Adjust the length of the strength indicator.
    this.strength.$bar.attr('aria-valuenow', result.strength);
    this.strength.$bar.css('width', result.strength + '%');

    // Change the classes (color) of the strength meter based on result level.
    switch (result.indicatorText) {
      case this.settings.weak:
        this.switchClass(this.password.$wrapper, 'error', 'has');
        this.switchClass(this.strength.$label, 'danger', 'label');
        this.switchClass(this.strength.$bar, 'danger', 'progress-bar');
        this.password.$icon.addClass('glyphicon-remove').removeClass('glyphicon-warning-sign glyphicon-ok');
        break;

      case this.settings.fair:
      case this.settings.good:
        this.switchClass(this.password.$wrapper, 'warning', 'has');
        this.switchClass(this.strength.$label, 'warning', 'label');
        this.switchClass(this.strength.$bar, 'warning', 'progress-bar');
        this.password.$icon.addClass('glyphicon-warning-sign').removeClass('glyphicon-remove glyphicon-ok');
        break;

      case this.settings.strong:
        this.switchClass(this.password.$wrapper, 'success', 'has');
        this.switchClass(this.strength.$label, 'success', 'label');
        this.switchClass(this.strength.$bar, 'success', 'progress-bar');
        this.password.$icon.addClass('glyphicon-ok').removeClass('glyphicon-warning-sign glyphicon-remove');
        break;
    }
    this.validateMatch();
  };

  /**
   * Validates both original and confirmation passwords to ensure they match.
   */
  Drupal.BootstrapPassword.prototype.validateMatch = function () {
    var password = this.password.$input.val();

    // Passwords match.
    if (password && password === this.confirm.$input.val()) {
      this.switchClass(this.password.$wrapper, 'success', 'has');
      this.switchClass(this.confirm.$wrapper, 'success', 'has');
      this.$helpBlock.hide();
      this.strength.$label.hide();
      this.strength.$bar.hide();
      this.password.$icon.addClass('glyphicon-ok').removeClass('glyphicon-warning-sign glyphicon-remove');
      this.confirm.$icon.addClass('glyphicon-ok').removeClass('glyphicon-remove');
    }
    // Passwords do not match.
    else if (password) {
      this.switchClass(this.confirm.$wrapper, 'error', 'has');
      this.confirm.$icon.addClass('glyphicon-remove').removeClass('glyphicon-ok');
    }
    // No password.
    else {
      this.confirm.$icon.removeClass('glyphicon-ok glyphicon-remove');
      this.confirm.$input.val('');
      this.switchClass(this.confirm.$wrapper, '', 'has');
    }
  };

  /**
   * Overrides core JS for password strength and confirmation.
   *
   * Attach handlers to evaluate the strength of any password fields and to check
   * that its confirmation is correct.
   */
  Drupal.behaviors.password = {
    attach: function (context) {
      $('input.password-field', context).once('password', function () {
        new Drupal.BootstrapPassword(this);
      });
    }
  };

})(jQuery, window.Drupal);
;
(function ($) {

  function updateFilterHelpLink () {
    var $link = $(this).parents('.filter-wrapper').find('.filter-help > a');
    var originalLink = $link.data('originalLink');
    if (!originalLink) {
      originalLink = $link.attr('href');
      $link.data('originalLink', originalLink);
    }
    $link.attr('href', originalLink + '/' + $(this).find(':selected').val());
  }

  $(document).on('change', '.filter-wrapper select.filter-list', updateFilterHelpLink);

  /**
   * Override core's functionality.
   */
  Drupal.behaviors.filterGuidelines = {
    attach: function (context) {
      $(context).find('.filter-wrapper select.filter-list').once('filter-list', updateFilterHelpLink);
    }
  };

})(jQuery);
;
