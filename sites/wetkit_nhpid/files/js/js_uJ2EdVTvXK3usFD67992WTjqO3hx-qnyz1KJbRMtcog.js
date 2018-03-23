/**
 * @file
 * Plugin URL.
 */

jQuery.url = function () {
  'use strict';
  var segments = {};
  var parsed = {};
  var options = {
    url: window.location,
    strictMode: false,
    key: ['source', 'protocol', 'authority', 'userInfo', 'user', 'password', 'host', 'port', 'relative', 'path',
          'directory', 'file', 'query', 'anchor'],
    q: {name: 'queryKey', parser: '/(?:^|&)([^&=]*)=?([^&]*)/g'},
    parser: {
      strict: /^(?:([^:\/?#]+):)?(?:\/\/((?:(([^:@]*):?([^:@]*))?@)?([^:\/?#]*)(?::(\d*))?))?((((?:[^?#\/]*\/)*)([^?#]*))(?:\?([^#]*))?(?:#(.*))?)/,
      loose: /^(?:(?![^:@]+:[^:@\/]*@)([^:\/?#.]+):)?(?:\/\/)?((?:(([^:@]*):?([^:@]*))?@)?([^:\/?#]*)(?::(\d*))?)(((\/(?:[^?#](?![^?#\/]*\.[^?#\/.]+(?:[?#]|$)))*\/?)?([^?#\/]*))(?:\?([^#]*))?(?:#(.*))?)/
    }
  };
  var parseUri = function () {
    var str = decodeURI(options.url);
    var m = options.parser[options.strictMode ? 'strict' : 'loose'].exec(str);
    var uri = {};
    var i = 14;
    while (i--) {
      uri[options.key[i]] = m[i] || '';
    }
    uri[options.q.name] = {};
    uri[options.key[12]].replace(options.q.parser, function ($0, $1, $2) {
      if ($1) {
        uri[options.q.name][$1] = $2;
      }
    });
    return uri;
  };
  var key = function (key) {
    if (!parsed.length) {
      setUp();
    }
    if (key === 'base') {
      if (parsed.port !== null && parsed.port !== '') {
        return parsed.protocol + '://' + parsed.host + ':' + parsed.port + '/';
      }
      else {
        return parsed.protocol + '://' + parsed.host + '/';
      }
    }
    return (parsed[key] === '') ? null : parsed[key];
  };
  var param = function (item) {
    if (!parsed.length) {
      setUp();
    }
    return (parsed.queryKey[item] === null) ? null : parsed.queryKey[item];
  };
  var setUp = function () {
    parsed = parseUri();
    getSegments();
  };
  var getSegments = function () {
    var p = parsed.path;
    segments = [];
    segments = parsed.path.length === 1 ? {} : (p.charAt(p.length - 1) === '/' ? p.substring(1,
      p.length - 1) : p.substring(1)).split('/');
  };
  return {
    setMode: function (mode) {
      return mode === 'strict';
    }, setUrl: function (newUri) {
      if (typeof newUri !== 'undefined' && newUri !== null) {
        options.url = newUri;
      }
      else {
        options.url = window.location;
      }
      setUp();
      return this;
    }, segment: function (pos) {
      if (!parsed.length) {
        setUp();
      }
      if (typeof pos === 'undefined') {
        return segments.length;
      }
      return (segments[pos] === '' || (typeof segments[pos] === 'undefined')) ? null : segments[pos];
    }, attr: key, param: param
  };
}();
;
/**
 * @file
 * Plugin on UserExit.
 */

// This is the var that determines if the unload was caused by a user leaving, or navigating in the site.
var movingWithinSite = false;
var keyCode;
var codeToExecute = function () {
  'use strict';
};

function userMovingWithinSite() {
  'use strict';
  movingWithinSite = true;
}

// Code to detect refreshing of the page through keyboard use.
var ctrlKeyIsDown = false;
function interceptKeyUp(e) {
  'use strict';
  if (!e) {
    if (window.event) {
      e = window.event;
    }
    else {
      return;
    }
  }

  keyCode = e.keyCode;
  if (keyCode === 17) {
    ctrlKeyIsDown = false;
  }
}

function interceptKeyDown(e) {
  'use strict';
  if (!e) {
    if (window.event) {
      e = window.event;
    }
    else {
      return;
    }
  }

  keyCode = e.keyCode;
  // F5 detected.
  if (keyCode === 116) {
    userMovingWithinSite();
  }

  if (keyCode === 17) {
    ctrlKeyIsDown = true;
  }

  // Then they are pressing Ctrl+R.
  if (ctrlKeyIsDown && keyCode === 82) {
    userMovingWithinSite();
  }
}

function interceptKeyPress(e) {
  'use strict';
  if (!e) {
    if (window.event) {
      e = window.event;
    }
    else {
      return;
    }
  }

  if (e.which) {
    keyCode = e.keyCode ? e.keyCode : e.which;
  }
  else {
    keyCode = e.keyCode ? e.keyCode : void 0;
  }
  if (e.charCode === null || e.charCode === 0) {
    // F5 pressed.
    if (keyCode === 116) {
      userMovingWithinSite();
    }
  }
}

function attachEventListener(obj, type, func, capture) {
  'use strict';
  if (window.addEventListener) {
    // Mozilla, Netscape, Firefox.
    obj.addEventListener(type, func, capture);
  }
  else {
    // IE.
    obj.attachEvent('on' + type, func);
  }
}

(function ($) {
  'use strict';
  $.fn.onUserExit = function (options) {
    var defaults = {
      execute: '',
      executeConfirm: '',
      internalURLs: ''
    };
    options = $.extend(defaults, options);

    if (options.execute === '') {
      alert('The onUserExit jQuery Plugin has been misconfigured.  Please add the function you wish to execute.');
    }
    if (options.internalURLs === '') {
      alert(
        'The onUserExit jQuery Plugin has been misconfigured.  Please add internal URLs so it know when the user is navigating internally.');
    }
    codeToExecute = options.execute;

    // Add onClick function to all internal links.
    $('a, button').each(function () {
      var obj = $(this);
      var linkIsInternal = false;
      var href = obj.attr('href');

      var myInternalURLs = options.internalURLs.split('|');

      if ((typeof href !== 'undefined') && !linkIsInternal) {
        var i;
        for (i = 0; i < myInternalURLs.length; i++) {
          if (href.indexOf(myInternalURLs[i]) !== -1) {
            linkIsInternal = true;
          }
        }
      }

      if (linkIsInternal === true) {
        obj.bind('click', function () {
          userMovingWithinSite();
        });
      }
    });

    $('form').each(function () {
      var obj = $(this);
      var currentonSubmit = obj.attr('onSubmit');
      if (typeof currentonSubmit === 'undefined') {
        currentonSubmit = '';
      }
      obj.attr('onSubmit', currentonSubmit + ' userMovingWithinSite();');
    });

    // For Refresh Detection.
    attachEventListener(document, 'keydown', interceptKeyDown, true);
    attachEventListener(document, 'keyup', interceptKeyUp, true);
    attachEventListener(document, 'keypress', interceptKeyPress, true);
    window.onbeforeunload = function () {
      if (movingWithinSite === false) {
        return options.executeConfirm();
      }
    };
  };

  window.onunload = function () {
    // Unloading the page when the user is leaving.
    if (movingWithinSite === false) {
      codeToExecute();
    }
  };
})(jQuery);
;
