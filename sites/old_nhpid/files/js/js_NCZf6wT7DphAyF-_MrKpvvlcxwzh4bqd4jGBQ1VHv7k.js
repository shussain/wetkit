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
  $('.form-autocomplete > .dropdown').each(function () {
    this.owner.hidePopup();
  });

  // Always return true to make it possible to submit even when there was an
  // autocomplete suggestion list open.
    return true;
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
(function($) {
  // Unbind core state.js from document first so we can then override below.
  $(document).unbind('state:disabled');

  /**
   * Global state change handlers. These are bound to "document" to cover all
   * elements whose state changes. Events sent to elements within the page
   * bubble up to these handlers. We use this system so that themes and modules
   * can override these state change handlers for particular parts of a page.
   */
  $(document).bind('state:disabled', function(e) {
    // Only act when this change was triggered by a dependency and not by the
    // element monitoring itself.
    if (e.trigger) {
      $(e.target)
        .attr('disabled', e.value)
        .closest('.form-item, .form-submit, .form-wrapper').toggleClass('form-disabled', e.value)
        .find(':input').attr('disabled', e.value);

      // Note: WebKit nightlies don't reflect that change correctly.
      // See https://bugs.webkit.org/show_bug.cgi?id=23789
    }
  });
})(jQuery);
;
