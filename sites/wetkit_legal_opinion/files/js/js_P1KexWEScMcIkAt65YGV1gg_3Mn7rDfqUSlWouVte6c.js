/******************************************************************************************************************************

 * @ Original idea by by Binny V A, Original version: 2.00.A 
 * @ http://www.openjs.com/scripts/events/keyboard_shortcuts/
 * @ Original License : BSD
 
 * @ jQuery Plugin by Tzury Bar Yochay 
        mail: tzury.by@gmail.com
        blog: evalinux.wordpress.com
        face: facebook.com/profile.php?id=513676303
        
        (c) Copyrights 2007
        
 * @ jQuery Plugin version Beta (0.0.3)
 * @ License: jQuery-License.
 
TODO:
    add queue support (as in gmail) e.g. 'x' then 'y', etc.
    add mouse + mouse wheel events.

USAGE:
    $.hotkeys.add('Ctrl+c', function(){ alert('copy anyone?');});
    $.hotkeys.add('Ctrl+c', {target:'div#editor', type:'keyup', propagate: true},function(){ alert('copy anyone?');});>
    $.hotkeys.remove('Ctrl+c'); 
    $.hotkeys.remove('Ctrl+c', {target:'div#editor', type:'keypress'}); 
    
******************************************************************************************************************************/
(function (jQuery) {

  this.version = '(beta)(0.0.3)';

  this.all = {};

  this.special_keys = {
    27: 'esc', 9: 'tab', 32:'space', 13: 'return', 8:'backspace', 145: 'scroll', 20: 'capslock', 
    144: 'numlock', 19:'pause', 45:'insert', 36:'home', 46:'del',35:'end', 33: 'pageup', 
    34:'pagedown', 37:'left', 38:'up', 39:'right',40:'down', 112:'f1',113:'f2', 114:'f3', 
    115:'f4', 116:'f5', 117:'f6', 118:'f7', 119:'f8', 120:'f9', 121:'f10', 122:'f11', 123:'f12'};        

  this.shift_nums = { "`":"~", "1":"!", "2":"@", "3":"#", "4":"$", "5":"%", "6":"^", "7":"&", 
    "8":"*", "9":"(", "0":")", "-":"_", "=":"+", ";":":", "'":"\"", ",":"<", 
    ".":">",  "/":"?",  "\\":"|" };        

  this.add = function(combi, options, callback) {
    if (jQuery.isFunction(options)) {
      callback = options;
      options = {};
    }
    var opt = {};
    var defaults = {type: 'keydown', propagate: false, disableInInput: false, target: 'html'};
    var that = this;
    var opt = jQuery.extend( opt , defaults, options || {} );
    combi = combi.toLowerCase();        
        
    // inspect if keystroke matches
    var inspector = function(event) {
      event = jQuery.event.fix(event); // jQuery event normalization.
      var selector = event.data.selector;
      var element = jQuery(event.target);

      // Disable shortcut keys in Input, Textarea fields
      if(opt['disableInInput'] && element.is('textarea, input')) {
        return;
      }

      var
        code = event.which,
        type = event.type,
        character = String.fromCharCode(code).toLowerCase(),
        special = that.special_keys[code],
        shift = event.shiftKey,
        ctrl = event.ctrlKey,
        alt= event.altKey,
        propagate = true, // default behaivour
        mapPoint = null;

      var cbMap = that.all[selector].events[type].callbackMap;
      if(!shift && !ctrl && !alt) { // No Modifiers
        mapPoint = cbMap[special] ||  cbMap[character]
      }
      
      // deals with combinaitons (alt|ctrl|shift+anything)
      else{
        var modif = '';
        if(alt) modif +='alt+';
        if(ctrl) modif+= 'ctrl+';
        if(shift) modif += 'shift+';
        // modifiers + special keys or modifiers + characters or modifiers + shift characters
        mapPoint = cbMap[modif+special] || cbMap[modif+character] || cbMap[modif+that.shift_nums[character]]
      }

      if (mapPoint){
        mapPoint.cb(event);
        if(!mapPoint.propagate) {
          event.stopPropagation();
          event.preventDefault();
          return false;
        }
      }
    };

    // first hook for this element
    if (!this.all[opt.target]){
      this.all[opt.target] = {events:{}};
    }
    if (!this.all[opt.target].events[opt.type]){
      this.all[opt.target].events[opt.type] = {callbackMap: {}}
      jQuery(opt.target).bind(opt.type, {selector: opt.target}, inspector);
    }
    this.all[opt.target].events[opt.type].callbackMap[combi] =  {cb: callback, propagate:opt.propagate};                
    return jQuery;
	};    

  this.remove = function(exp, opt) {
    opt = opt || {};
    target = opt.target || 'html';
    type = opt.type || 'keydown';
    exp = exp.toLowerCase();
    jQuery(target).unbind(type);
    delete this.all[target].events[type].callbackMap[exp];
    return jQuery;
	};
	
  jQuery.hotkeys = this;
  return jQuery;    

})(jQuery);;

/**
 * Cookie plugin 1.0
 *
 * Copyright (c) 2006 Klaus Hartl (stilbuero.de)
 * Dual licensed under the MIT and GPL licenses:
 * http://www.opensource.org/licenses/mit-license.php
 * http://www.gnu.org/licenses/gpl.html
 *
 */
jQuery.cookie=function(b,j,m){if(typeof j!="undefined"){m=m||{};if(j===null){j="";m.expires=-1}var e="";if(m.expires&&(typeof m.expires=="number"||m.expires.toUTCString)){var f;if(typeof m.expires=="number"){f=new Date();f.setTime(f.getTime()+(m.expires*24*60*60*1000))}else{f=m.expires}e="; expires="+f.toUTCString()}var l=m.path?"; path="+(m.path):"";var g=m.domain?"; domain="+(m.domain):"";var a=m.secure?"; secure":"";document.cookie=[b,"=",encodeURIComponent(j),e,l,g,a].join("")}else{var d=null;if(document.cookie&&document.cookie!=""){var k=document.cookie.split(";");for(var h=0;h<k.length;h++){var c=jQuery.trim(k[h]);if(c.substring(0,b.length+1)==(b+"=")){d=decodeURIComponent(c.substring(b.length+1));break}}}return d}};
;
(function ($, Drupal, undefined) {

// Store all l10n_client related data + methods in its own object
  Drupal.l10nClient = {
    // Set "selected" string to unselected, i.e. -1
    selected: -1,

    // Keybindings
    keys: {'toggle': 'ctrl+shift+s', 'clear': 'esc'}, // Keybindings

    // Keybinding functions
    key: function (pressed) {
      var $l10nClient = Drupal.l10nClient.$l10nClient;
      switch (pressed) {
        case 'toggle':
          // Grab user-hilighted text & send it into the search filter
          var userSelection = window.getSelection ? window.getSelection() : document.getSelection ? document.getSelection() : document.selection.createRange().text;
          userSelection = String(userSelection);
          if (userSelection.length > 0) {
            this.filter(userSelection);
            this.toggle(1);
            $l10nClient.find('.string-search').val(userSelection).focus();
          } else {
            if ($l10nClient.is('.l10n-client-minimized')) {
              this.toggle(1);
              if (!$.browser.safari) {
                $l10nClient.find('.string-search').focus();
              }
            }
            else {
              this.toggle(0);
            }
          }
          break;
        case 'clear':
          this.filter(false);
          break;
      }
    },

    // Toggle the l10nclient
    toggle: function (state) {
      var $l10nClient = Drupal.l10nClient.$l10nClient;
      var $clientWrapper = $('#l10n-client-string-select, #l10n-client-string-editor, #l10n-client .labels .label');
      if (!!state == true) {
        $clientWrapper.show();
        $l10nClient.removeClass('l10n-client-minimized').addClass('l10n-client-maximized').find('.labels .toggle').text('X');
        $('body').addClass('toggle-expanded');
        $.cookie('Drupal_l10n_client', '1', {expires: 7, path: '/'});
      } else {
        $clientWrapper.hide();
        $l10nClient.removeClass('l10n-client-maximized').addClass('l10n-client-minimized').find('.labels .toggle').text(Drupal.t('Translate Text'));
        $('body').removeClass('toggle-expanded');
        $.cookie('Drupal_l10n_client', '0', {expires: 7, path: '/'});
      }
    },

    // Get a string from the DOM tree
    getString: function (index, type) {
      return $('#l10n-client-data').find('div:eq(' + index + ') .' + type).text();
    },

    // Set a string in the DOM tree
    setString: function (index, data) {
      $('#l10n-client-data').find('div:eq(' + index + ') .target').text(data);
    },

    // Filter the the string list by a search string
    filter: function (search) {
      var $l10nClient = Drupal.l10nClient.$l10nClient;
      var $stringSearch = $l10nClient.find('.string-search');
      var $stringSelect = $('#l10n-client-string-select').find('li');
      if (search === false || search === '') {
        $('#l10n-client-search-filter-clear').focus();
        $stringSelect.show();
        $stringSearch.val('').focus();
      } else if (search.length > 0) {
        $stringSelect.show().not(':contains(' + search + ')').hide();
      }
    }
  };

  // Attaches the localization editor behavior to all required fields.
  Drupal.behaviors.l10nClient = {
    attach: function (context) {
      $('#l10n-client').once('l10n-client', function () {
        $('body').addClass('l10n-client');
        var $l10nClient = $(this);
        var $l10nClientForm = $('#l10n-client-form');
        var $stringEditor = $('#l10n-client-string-editor');
        var $stringEditorSoruceText = $stringEditor.find('.source-text');
        var $stringSelect = $('#l10n-client-string-select');
        var cookie = parseInt($.cookie('Drupal_l10n_client'), 2);
        Drupal.l10nClient.$l10nClient = $l10nClient;
        Drupal.l10nClient.toggle(isNaN(cookie) ? 0 : cookie);

        // If the selection changes, copy string values to the source and target fields.
        // Add class to indicate selected string in list widget.
        $stringSelect.find('li').click(function () {
          var $this = $(this);
          var $lis = $stringSelect.find('li');
          var index = $lis.index(this);

          $lis.removeClass('active');
          $this.addClass('active');

          $stringEditorSoruceText.text(Drupal.l10nClient.getString(index, 'source'));
          $l10nClientForm.find('.translation-target').val(Drupal.l10nClient.getString(index, 'target'));
          $l10nClientForm.find('.source-textgroup').val(Drupal.l10nClient.getString(index, 'textgroup'));
          $l10nClientForm.find('.source-context').val(Drupal.l10nClient.getString(index, 'context'));
          $stringEditor.find('.context').text(Drupal.l10nClient.getString(index, 'context'));

          Drupal.l10nClient.selected = index;
          $l10nClientForm.find('.form-submit').removeAttr("disabled");
        });

        // When l10n_client window is clicked, toggle based on current state.
        $l10nClient.find('.labels .toggle').click(function () {
          Drupal.l10nClient.toggle($l10nClient.is('.l10n-client-minimized'));
        });

        // Copy source text to translation field on button click.
        $l10nClientForm.find('.edit-copy').click(function () {
          $l10nClientForm.find('.translation-target').val($stringEditorSoruceText.text());
          return false;
        });

        // Clear translation field on button click.
        $l10nClientForm.find('.edit-clear').click(function () {
          $l10nClientForm.find('.translation-target').val('');
          return false;
        });

        // Register keybindings using jQuery hotkeys
        if ($.hotkeys) {
          $.hotkeys.add(Drupal.l10nClient.keys.toggle, function () {
            Drupal.l10nClient.key('toggle');
          });
          $.hotkeys.add(Drupal.l10nClient.keys.clear, {target: '#l10n-client .string-search', type: 'keyup'}, function () {
            Drupal.l10nClient.key('clear');
          });
        }

        // Custom listener for l10n_client livesearch
        $l10nClient.find('.string-search').keyup(function () {
          Drupal.l10nClient.filter($l10nClient.find('.string-search').val());
        });

        // Clear search
        $l10nClient.find('#l10n-client-search-filter-clear').click(function () {
          Drupal.l10nClient.filter(false);
          return false;
        });

        // Send AJAX POST data on form submit.
        $l10nClientForm.submit(function () {
          var $this = $(this);

          // Prevent submit empty strings.
          $this.find('.form-submit').attr("disabled", true);
          $this.find('.edit-save').after('<div class="ajax-progress ajax-progress-throbber">' +
            '<div class="throbber">&nbsp;</div><div class="message">' +
            Drupal.t('Please wait...') + '</div></div>');

          $.ajax({
            type: "POST",
            url: $this.attr('action'),
            // Send source and target strings.
            data: {
              source: $stringEditorSoruceText.text(),
              target: $this.find('.translation-target').val(),
              textgroup: $this.find('.source-textgroup').val(),
              context: $stringEditor.find('.context').text(),
              'form_token': $this.find('input[name=form_token]').val()
            },
            success: function (data) {
              var $translationTarget = $l10nClientForm.find('.translation-target');
              var newTranslation = $translationTarget.val();
              // Store string in local js
              Drupal.l10nClient.setString(Drupal.l10nClient.selected, newTranslation);

              // Figure out the display of the new translation in the selection list.
              var newTranslationStripped = newTranslation.replace(/<\/?[^<>]+>/gi, '')
                .replace(/&quot;/g, '"')
                .replace(/&lt;/g, "<")
                .replace(/&gt;/g, ">")
                .replace(/&amp;/g, "&");

              // Only contains HTML tags (edge case). Keep the whole string.
              // HTML tags will show up in the selector, but that is normal in this case.
              var newTranslationDisplay = newTranslation;
              if (newTranslationStripped.length > 81) {
                // Long translation, strip length to display only first part.
                // We strip at 78 chars and add three dots, if the total length is
                // above 81.
                newTranslationDisplay = newTranslationStripped.substr(0, 78) + '...';
              }

              // Mark string as translated.
              $stringSelect.find('li')
                .eq(Drupal.l10nClient.selected)
                .removeClass('untranslated active')
                .addClass('translated')
                .text(newTranslationDisplay);

              // Empty input fields.
              $stringEditorSoruceText.html(data);
              $translationTarget.val('');
              $this.find('div.ajax-progress-throbber').remove();
            },
            error: function (xmlhttp) {
              alert(Drupal.t('An HTTP error @status occured.', { '@status': xmlhttp.status }));
            }
          });
          return false;
        });
      });
    }
  };
})(jQuery, Drupal);
;
(function(){function C(){var a="{}";if("userDataBehavior"==h){d.load("jStorage");try{a=d.getAttribute("jStorage")}catch(b){}try{q=d.getAttribute("jStorage_update")}catch(c){}l.jStorage=a}D();w();E()}function t(){var a;clearTimeout(F);F=setTimeout(function(){if("localStorage"==h||"globalStorage"==h)a=l.jStorage_update;else if("userDataBehavior"==h){d.load("jStorage");try{a=d.getAttribute("jStorage_update")}catch(b){}}if(a&&a!=q){q=a;var m=n.parse(n.stringify(c.__jstorage_meta.CRC32)),k;C();k=n.parse(n.stringify(c.__jstorage_meta.CRC32));
var e,y=[],g=[];for(e in m)m.hasOwnProperty(e)&&(k[e]?m[e]!=k[e]&&"2."==String(m[e]).substr(0,2)&&y.push(e):g.push(e));for(e in k)k.hasOwnProperty(e)&&(m[e]||y.push(e));r(y,"updated");r(g,"deleted")}},25)}function r(a,b){a=[].concat(a||[]);var c,k,e,d;if("flushed"==b){a=[];for(c in f)f.hasOwnProperty(c)&&a.push(c);b="deleted"}c=0;for(e=a.length;c<e;c++){if(f[a[c]])for(k=0,d=f[a[c]].length;k<d;k++)f[a[c]][k](a[c],b);if(f["*"])for(k=0,d=f["*"].length;k<d;k++)f["*"][k](a[c],b)}}function u(){var a=(+new Date).toString();
if("localStorage"==h||"globalStorage"==h)try{l.jStorage_update=a}catch(b){h=!1}else"userDataBehavior"==h&&(d.setAttribute("jStorage_update",a),d.save("jStorage"));t()}function D(){if(l.jStorage)try{c=n.parse(String(l.jStorage))}catch(a){l.jStorage="{}"}else l.jStorage="{}";z=l.jStorage?String(l.jStorage).length:0;c.__jstorage_meta||(c.__jstorage_meta={});c.__jstorage_meta.CRC32||(c.__jstorage_meta.CRC32={})}function v(){if(c.__jstorage_meta.PubSub){for(var a=+new Date-2E3,b=0,m=c.__jstorage_meta.PubSub.length;b<
m;b++)if(c.__jstorage_meta.PubSub[b][0]<=a){c.__jstorage_meta.PubSub.splice(b,c.__jstorage_meta.PubSub.length-b);break}c.__jstorage_meta.PubSub.length||delete c.__jstorage_meta.PubSub}try{l.jStorage=n.stringify(c),d&&(d.setAttribute("jStorage",l.jStorage),d.save("jStorage")),z=l.jStorage?String(l.jStorage).length:0}catch(k){}}function p(a){if("string"!=typeof a&&"number"!=typeof a)throw new TypeError("Key name must be string or numeric");if("__jstorage_meta"==a)throw new TypeError("Reserved key name");
return!0}function w(){var a,b,m,k,e=Infinity,d=!1,g=[];clearTimeout(G);if(c.__jstorage_meta&&"object"==typeof c.__jstorage_meta.TTL){a=+new Date;m=c.__jstorage_meta.TTL;k=c.__jstorage_meta.CRC32;for(b in m)m.hasOwnProperty(b)&&(m[b]<=a?(delete m[b],delete k[b],delete c[b],d=!0,g.push(b)):m[b]<e&&(e=m[b]));Infinity!=e&&(G=setTimeout(w,Math.min(e-a,2147483647)));d&&(v(),u(),r(g,"deleted"))}}function E(){var a;if(c.__jstorage_meta.PubSub){var b,m=A;for(a=c.__jstorage_meta.PubSub.length-1;0<=a;a--)if(b=
c.__jstorage_meta.PubSub[a],b[0]>A){var m=b[0],k=b[1];b=b[2];if(s[k])for(var e=0,d=s[k].length;e<d;e++)try{s[k][e](k,n.parse(n.stringify(b)))}catch(g){}}A=m}}var x=window.jQuery||window.$||(window.$={}),n={parse:window.JSON&&(window.JSON.parse||window.JSON.decode)||String.prototype.evalJSON&&function(a){return String(a).evalJSON()}||x.parseJSON||x.evalJSON,stringify:Object.toJSON||window.JSON&&(window.JSON.stringify||window.JSON.encode)||x.toJSON};if("function"!==typeof n.parse||"function"!==typeof n.stringify)throw Error("No JSON support found, include //cdnjs.cloudflare.com/ajax/libs/json2/20110223/json2.js to page");
var c={__jstorage_meta:{CRC32:{}}},l={jStorage:"{}"},d=null,z=0,h=!1,f={},F=!1,q=0,s={},A=+new Date,G,B={isXML:function(a){return(a=(a?a.ownerDocument||a:0).documentElement)?"HTML"!==a.nodeName:!1},encode:function(a){if(!this.isXML(a))return!1;try{return(new XMLSerializer).serializeToString(a)}catch(b){try{return a.xml}catch(c){}}return!1},decode:function(a){var b="DOMParser"in window&&(new DOMParser).parseFromString||window.ActiveXObject&&function(a){var b=new ActiveXObject("Microsoft.XMLDOM");b.async=
"false";b.loadXML(a);return b};if(!b)return!1;a=b.call("DOMParser"in window&&new DOMParser||window,a,"text/xml");return this.isXML(a)?a:!1}};x.jStorage={version:"0.4.11",set:function(a,b,d){p(a);d=d||{};if("undefined"==typeof b)return this.deleteKey(a),b;if(B.isXML(b))b={_is_xml:!0,xml:B.encode(b)};else{if("function"==typeof b)return;b&&"object"==typeof b&&(b=n.parse(n.stringify(b)))}c[a]=b;for(var k=c.__jstorage_meta.CRC32,e=n.stringify(b),l=e.length,g=2538058380^l,h=0,f;4<=l;)f=e.charCodeAt(h)&
255|(e.charCodeAt(++h)&255)<<8|(e.charCodeAt(++h)&255)<<16|(e.charCodeAt(++h)&255)<<24,f=1540483477*(f&65535)+((1540483477*(f>>>16)&65535)<<16),f^=f>>>24,f=1540483477*(f&65535)+((1540483477*(f>>>16)&65535)<<16),g=1540483477*(g&65535)+((1540483477*(g>>>16)&65535)<<16)^f,l-=4,++h;switch(l){case 3:g^=(e.charCodeAt(h+2)&255)<<16;case 2:g^=(e.charCodeAt(h+1)&255)<<8;case 1:g^=e.charCodeAt(h)&255,g=1540483477*(g&65535)+((1540483477*(g>>>16)&65535)<<16)}g^=g>>>13;g=1540483477*(g&65535)+((1540483477*(g>>>
16)&65535)<<16);k[a]="2."+((g^g>>>15)>>>0);this.setTTL(a,d.TTL||0);r(a,"updated");return b},get:function(a,b){p(a);return a in c?c[a]&&"object"==typeof c[a]&&c[a]._is_xml?B.decode(c[a].xml):c[a]:"undefined"==typeof b?null:b},deleteKey:function(a){p(a);return a in c?(delete c[a],"object"==typeof c.__jstorage_meta.TTL&&a in c.__jstorage_meta.TTL&&delete c.__jstorage_meta.TTL[a],delete c.__jstorage_meta.CRC32[a],v(),u(),r(a,"deleted"),!0):!1},setTTL:function(a,b){var d=+new Date;p(a);b=Number(b)||0;
return a in c?(c.__jstorage_meta.TTL||(c.__jstorage_meta.TTL={}),0<b?c.__jstorage_meta.TTL[a]=d+b:delete c.__jstorage_meta.TTL[a],v(),w(),u(),!0):!1},getTTL:function(a){var b=+new Date;p(a);return a in c&&c.__jstorage_meta.TTL&&c.__jstorage_meta.TTL[a]?(a=c.__jstorage_meta.TTL[a]-b)||0:0},flush:function(){c={__jstorage_meta:{CRC32:{}}};v();u();r(null,"flushed");return!0},storageObj:function(){function a(){}a.prototype=c;return new a},index:function(){var a=[],b;for(b in c)c.hasOwnProperty(b)&&"__jstorage_meta"!=
b&&a.push(b);return a},storageSize:function(){return z},currentBackend:function(){return h},storageAvailable:function(){return!!h},listenKeyChange:function(a,b){p(a);f[a]||(f[a]=[]);f[a].push(b)},stopListening:function(a,b){p(a);if(f[a])if(b)for(var c=f[a].length-1;0<=c;c--)f[a][c]==b&&f[a].splice(c,1);else delete f[a]},subscribe:function(a,b){a=(a||"").toString();if(!a)throw new TypeError("Channel not defined");s[a]||(s[a]=[]);s[a].push(b)},publish:function(a,b){a=(a||"").toString();if(!a)throw new TypeError("Channel not defined");
c.__jstorage_meta||(c.__jstorage_meta={});c.__jstorage_meta.PubSub||(c.__jstorage_meta.PubSub=[]);c.__jstorage_meta.PubSub.unshift([+new Date,a,b]);v();u()},reInit:function(){C()},noConflict:function(a){delete window.$.jStorage;a&&(window.jStorage=this);return this}};(function(){var a=!1;if("localStorage"in window)try{window.localStorage.setItem("_tmptest","tmpval"),a=!0,window.localStorage.removeItem("_tmptest")}catch(b){}if(a)try{window.localStorage&&(l=window.localStorage,h="localStorage",q=l.jStorage_update)}catch(c){}else if("globalStorage"in
window)try{window.globalStorage&&(l="localhost"==window.location.hostname?window.globalStorage["localhost.localdomain"]:window.globalStorage[window.location.hostname],h="globalStorage",q=l.jStorage_update)}catch(f){}else if(d=document.createElement("link"),d.addBehavior){d.style.behavior="url(#default#userData)";document.getElementsByTagName("head")[0].appendChild(d);try{d.load("jStorage")}catch(e){d.setAttribute("jStorage","{}"),d.save("jStorage"),d.load("jStorage")}a="{}";try{a=d.getAttribute("jStorage")}catch(n){}try{q=
d.getAttribute("jStorage_update")}catch(g){}l.jStorage=a;h="userDataBehavior"}else{d=null;return}D();w();"localStorage"==h||"globalStorage"==h?"addEventListener"in window?window.addEventListener("storage",t,!1):document.attachEvent("onstorage",t):"userDataBehavior"==h&&setInterval(t,1E3);E();"addEventListener"in window&&window.addEventListener("pageshow",function(a){a.persisted&&t()},!1)})()})();;
(function ($) {

/**
 * Attaches double-click behavior to toggle full path of Krumo elements.
 */
Drupal.behaviors.devel = {
  attach: function (context, settings) {

    // Add hint to footnote
    $('.krumo-footnote .krumo-call').once().before('<img style="vertical-align: middle;" title="Click to expand. Double-click to show path." src="' + settings.basePath + 'misc/help.png"/>');

    var krumo_name = [];
    var krumo_type = [];

    function krumo_traverse(el) {
      krumo_name.push($(el).html());
      krumo_type.push($(el).siblings('em').html().match(/\w*/)[0]);

      if ($(el).closest('.krumo-nest').length > 0) {
        krumo_traverse($(el).closest('.krumo-nest').prev().find('.krumo-name'));
      }
    }

    $('.krumo-child > div:first-child', context).dblclick(
      function(e) {
        if ($(this).find('> .krumo-php-path').length > 0) {
          // Remove path if shown.
          $(this).find('> .krumo-php-path').remove();
        }
        else {
          // Get elements.
          krumo_traverse($(this).find('> a.krumo-name'));

          // Create path.
          var krumo_path_string = '';
          for (var i = krumo_name.length - 1; i >= 0; --i) {
            // Start element.
            if ((krumo_name.length - 1) == i)
              krumo_path_string += '$' + krumo_name[i];

            if (typeof krumo_name[(i-1)] !== 'undefined') {
              if (krumo_type[i] == 'Array') {
                krumo_path_string += "[";
                if (!/^\d*$/.test(krumo_name[(i-1)]))
                  krumo_path_string += "'";
                krumo_path_string += krumo_name[(i-1)];
                if (!/^\d*$/.test(krumo_name[(i-1)]))
                  krumo_path_string += "'";
                krumo_path_string += "]";
              }
              if (krumo_type[i] == 'Object')
                krumo_path_string += '->' + krumo_name[(i-1)];
            }
          }
          $(this).append('<div class="krumo-php-path" style="font-family: Courier, monospace; font-weight: bold;">' + krumo_path_string + '</div>');

          // Reset arrays.
          krumo_name = [];
          krumo_type = [];
        }
      }
    );
  }
};

})(jQuery);
;
(function($) {
  Drupal.behaviors.custom_search = {
    attach: function(context) {

      if (!Drupal.settings.custom_search.solr) {
        // Check if the search box is not empty on submit
        $('form.search-form', context).submit(function(){
          var $this = $(this);
          var box = $this.find('input.custom-search-box');
          if (box.val() != undefined && box.val() == '') {
            $this.find('input.custom-search-box').addClass('error');
            return false;
          }
          // If basic search is hidden, copy or value to the keys
          if ($this.find('#edit-keys').parents('div.element-invisible').attr('class') == 'element-invisible') {
            $this.find('#edit-keys').val($this.find('#edit-or').val());
            $this.find('#edit-or').val('');
          }
          return true;
        });
      }

      // Search from target
      $('form.search-form').attr('target', Drupal.settings.custom_search.form_target);

      // Displays Popup.
      $('form.search-form input.custom-search-box', context).bind('click focus', function(e){
        var $parentForm = $(this).parents('form');
        // check if there's something in the popup and displays it
        var popup = $parentForm.find('fieldset.custom_search-popup');
        if (popup.find('input,select').length && !popup.hasClass('opened')) {
          popup.fadeIn().addClass('opened');
        }
        e.stopPropagation();
      });
      $(document).bind('click focus', function(){
        $('fieldset.custom_search-popup').hide().removeClass('opened');
      });

      // Handle checkboxes
      $('.custom-search-selector input:checkbox', context).each(function(){
        var el = $(this);
        if (el.val() == 'c-all') {
          el.change(function(){
            $(this).parents('.custom-search-selector').find('input:checkbox[value!=c-all]').attr('checked', false);
          });
        }
        else {
          if (el.val().substr(0,2) == 'c-') {
            el.change(function(){
              $('.custom-search-selector input:checkbox').each(function(){
                if ($(this).val().substr(0,2) == 'o-') {
                  $(this).attr('checked', false);
                }
              });
              $(this).parents('.custom-search-selector').find('input:checkbox[value=c-all]').attr('checked', false);
            });
          } else {
            el.change(function(){
              $(this).parents('.custom-search-selector').find('input:checkbox[value!=' + el.val() + ']').attr('checked', false);
            });
          }
        }
      });

      // Handle popup.
      var popup = $('fieldset.custom_search-popup:not(.custom_search-processed)', context).addClass("custom_search-processed");
      popup.click(function(e){
        e.stopPropagation();
      })
      popup.append('<a class="custom_search-popup-close" href="#">' + Drupal.t('Close') + '</a>');
      $('a.custom_search-popup-close').click(function(e){
        $('fieldset.custom_search-popup.opened').hide().removeClass('opened');
        e.preventDefault();
      });

    }
  }
})(jQuery);
;
// Generated by CoffeeScript 1.6.3
/*
 @file
 Custom JS for administering WetKit Bean.
*/

(function($) {
  return Drupal.behaviors.WxTSlideOut = {
    attach: function(context, settings) {
      $('#opener').on('click', function() {
        var panel = $('#slide-panel');

        // Panel display logic.
        if (panel.hasClass("visible")) {
          panel.removeClass('visible').animate({'margin-right':'-250px'});
        } else {
          panel.addClass('visible').animate({'margin-right':'0px'});
        }

        // ESC to close Panel.
        $(document).bind("keydown", function(e) {
          if (e.keyCode == 27) {
            panel.removeClass('visible').animate({'margin-right':'-250px'});
          }
        });

        return false;
      });
    }
  };
})(jQuery);
;
(function($) {

Drupal.behaviors.navbarDestination = {
  attach: function (context) {
    var $destination = window.location.pathname;
    $destination = ($destination.substring(1, $destination.length));

    if ($destination.length > 0) {
      var $href = $('#navbar-link-admin-flush-cache').attr('href');
      $('#navbar-link-admin-flush-cache').attr('href', $href + '?destination=' + $destination);

      var $parent = $('#navbar-link-admin-flush-cache').closest('li');
      $('.icon', $parent).each(function(){
        $href = $(this).attr('href');
        $(this).attr('href', $href + '?destination=' + $destination);
      });
    }
  }
};

})(jQuery);
;
(function ($) {

/**
 * A progressbar object. Initialized with the given id. Must be inserted into
 * the DOM afterwards through progressBar.element.
 *
 * method is the function which will perform the HTTP request to get the
 * progress bar state. Either "GET" or "POST".
 *
 * e.g. pb = new progressBar('myProgressBar');
 *      some_element.appendChild(pb.element);
 */
Drupal.progressBar = function (id, updateCallback, method, errorCallback) {
  var pb = this;
  this.id = id;
  this.method = method || 'GET';
  this.updateCallback = updateCallback;
  this.errorCallback = errorCallback;

  // The WAI-ARIA setting aria-live="polite" will announce changes after users
  // have completed their current activity and not interrupt the screen reader.
  this.element = $('<div class="progress-wrapper" aria-live="polite"></div>');
  this.element.html('<div id ="' + id + '" class="progress progress-striped active">' +
                    '<div class="progress-bar" role="progressbar" aria-valuemin="0" aria-valuemax="100" aria-valuenow="0">' +
                    '<div class="percentage sr-only"></div>' +
                    '</div></div>' +
                    '</div><div class="percentage pull-right"></div>' +
                    '<div class="message">&nbsp;</div>');
};

/**
 * Set the percentage and status message for the progressbar.
 */
Drupal.progressBar.prototype.setProgress = function (percentage, message) {
  if (percentage >= 0 && percentage <= 100) {
    $('div.progress-bar', this.element).css('width', percentage + '%');
    $('div.progress-bar', this.element).attr('aria-valuenow', percentage);
    $('div.percentage', this.element).html(percentage + '%');
  }
  $('div.message', this.element).html(message);
  if (this.updateCallback) {
    this.updateCallback(percentage, message, this);
  }
};

/**
 * Start monitoring progress via Ajax.
 */
Drupal.progressBar.prototype.startMonitoring = function (uri, delay) {
  this.delay = delay;
  this.uri = uri;
  this.sendPing();
};

/**
 * Stop monitoring progress via Ajax.
 */
Drupal.progressBar.prototype.stopMonitoring = function () {
  clearTimeout(this.timer);
  // This allows monitoring to be stopped from within the callback.
  this.uri = null;
};

/**
 * Request progress data from server.
 */
Drupal.progressBar.prototype.sendPing = function () {
  if (this.timer) {
    clearTimeout(this.timer);
  }
  if (this.uri) {
    var pb = this;
    // When doing a post request, you need non-null data. Otherwise a
    // HTTP 411 or HTTP 406 (with Apache mod_security) error may result.
    $.ajax({
      type: this.method,
      url: this.uri,
      data: '',
      dataType: 'json',
      success: function (progress) {
        // Display errors.
        if (progress.status == 0) {
          pb.displayError(progress.data);
          return;
        }
        // Update display.
        pb.setProgress(progress.percentage, progress.message);
        // Schedule next timer.
        pb.timer = setTimeout(function () { pb.sendPing(); }, pb.delay);
      },
      error: function (xmlhttp) {
        pb.displayError(Drupal.ajaxError(xmlhttp, pb.uri));
      }
    });
  }
};

/**
 * Display errors on the page.
 */
Drupal.progressBar.prototype.displayError = function (string) {
  var error = $('<div class="alert alert-block alert-error"><a class="close" data-dismiss="alert" href="#">&times;</a><h4>Error message</h4></div>').append(string);
  $(this.element).before(error).hide();

  if (this.errorCallback) {
    this.errorCallback(this);
  }
};

})(jQuery);
;

(function($) {

Drupal.behaviors.HierarchicalSelect = {
  attach: function (context) {
    $('.hierarchical-select-wrapper:not(.hierarchical-select-wrapper-processed)', context)
    .addClass('hierarchical-select-wrapper-processed').each(function() {
      var hsid = $(this).attr('id').replace(/^hierarchical-select-(.+)-wrapper$/, "$1");
      Drupal.HierarchicalSelect.initialize(hsid);
    });
  }
};

Drupal.HierarchicalSelect = {};

Drupal.HierarchicalSelect.state = [];

Drupal.HierarchicalSelect.context = function() {
  return $("form .hierarchical-select-wrapper");
};

Drupal.HierarchicalSelect.initialize = function(hsid) {
  // Prevent JS errors when Hierarchical Select is loaded dynamically.
  if (undefined == Drupal.settings.HierarchicalSelect || undefined == Drupal.settings.HierarchicalSelect.settings["hs-" + hsid]) {
    return false;
  }

  // If you set Drupal.settings.HierarchicalSelect.pretendNoJS to *anything*,
  // and as such, Hierarchical Select won't initialize its Javascript! It
  // will seem as if your browser had Javascript disabled.
  if (undefined != Drupal.settings.HierarchicalSelect.pretendNoJS) {
    return false;
  }

  var form = $('#hierarchical-select-'+ hsid +'-wrapper').parents('form');

  // Pressing the 'enter' key on a form that contains an HS widget, depending
  // on which browser, usually causes the first submit button to be pressed
  // (likely an HS button).  This results in unpredictable behaviour.  There is
  // no way to determine the 'real' submit button, so disable the enter key.
  form.find('input').keypress(function(event) {
    if (event.keyCode == 13) {
      event.preventDefault();
      return false;
    }
  });

  // Turn off Firefox' autocomplete feature. This causes Hierarchical Select
  // form items to be disabled after a hard refresh.
  // See http://drupal.org/node/453048 and
  // http://www.ryancramer.com/journal/entries/radio_buttons_firefox/
  if (navigator.userAgent.toLowerCase().indexOf('firefox') > -1) {
    form.attr('autocomplete', 'off');
  }

  // Enable *all* submit buttons in this form, as well as all input-related
  // elements of the current hierarchical select, in case we reloaded while
  // they were disabled.
  form.add('#hierarchical-select-' + hsid +'-wrapper .hierarchical-select .selects select')
      .add('#hierarchical-select-' + hsid +'-wrapper .hierarchical-select input')
      .attr('disabled', false);

  if (this.cache != null) {
    this.cache.initialize();
  }

  Drupal.settings.HierarchicalSelect.settings["hs-" + hsid]['updatesEnabled'] = true;
  if (undefined == Drupal.HierarchicalSelect.state["hs-" + hsid]) {
    Drupal.HierarchicalSelect.state["hs-" + hsid] = {};
  }

  this.transform(hsid);
  if (Drupal.settings.HierarchicalSelect.settings["hs-" + hsid].resizable) {
    this.resizable(hsid);
  }
  Drupal.HierarchicalSelect.attachBindings(hsid);

  if (this.cache != null && this.cache.status()) {
    this.cache.load(hsid);
  }

  Drupal.HierarchicalSelect.log(hsid);
};

Drupal.HierarchicalSelect.log = function(hsid, messages) {
  // Only perform logging if logging is enabled.
  if (Drupal.settings.HierarchicalSelect.initialLog == undefined || Drupal.settings.HierarchicalSelect.initialLog["hs-" + hsid] == undefined) {
    return;
  }
  else {
    Drupal.HierarchicalSelect.state["hs-" + hsid].log = [];
  }

  // Store the log messages. The first call to this function may not contain a
  // message: the initial log included in the initial HTML rendering should be
  // used instead..
  if (Drupal.HierarchicalSelect.state["hs-" + hsid].log.length == 0) {
    Drupal.HierarchicalSelect.state["hs-" + hsid].log.push(Drupal.settings.HierarchicalSelect.initialLog["hs-" + hsid]);
  }
  else {
      Drupal.HierarchicalSelect.state["hs-" + hsid].log.push(messages);
  }

  // Print the log messages.
  console.log("HIERARCHICAL SELECT " + hsid);
  var logIndex = Drupal.HierarchicalSelect.state["hs-" + hsid].log.length - 1;
  for (var i = 0; i < Drupal.HierarchicalSelect.state["hs-" + hsid].log[logIndex].length; i++) {
    console.log(Drupal.HierarchicalSelect.state["hs-" + hsid].log[logIndex][i]);
  }
  console.log(' ');
};

Drupal.HierarchicalSelect.transform = function(hsid) {
  var removeString = $('#hierarchical-select-'+ hsid +'-wrapper .dropbox .dropbox-remove:first', Drupal.HierarchicalSelect.context).text();

  $('#hierarchical-select-'+ hsid +'-wrapper', Drupal.HierarchicalSelect.context)
  // Remove the .nojs div.
  .find('.nojs').hide().end()
  // Find all .dropbox-remove cells in the dropbox table.
  .find('.dropbox .dropbox-remove')
  // Hide the children of these table cells. We're not removing them because
  // we want to continue to use the "Remove" checkboxes.
  .find('*').css('display', 'none').end() // We can't use .hide() because of collapse.js: http://drupal.org/node/351458#comment-1258303.
  // Put a "Remove" link there instead.
  .append('<a href="">'+ removeString +'</a>');
};

Drupal.HierarchicalSelect.resizable = function(hsid) {
  var $selectsWrapper = $('#hierarchical-select-' + hsid + '-wrapper .hierarchical-select .selects', Drupal.HierarchicalSelect.context);

  // No select wrapper present: the user is creating a new item.
  if ($selectsWrapper.length == 0) {
    return;
  }

  // Append the drag handle ("grippie").
  $selectsWrapper.append($('<div class="grippie"></div>'));

  // jQuery object that contains all selects in the hierarchical select, to
  // speed up DOM manipulation during dragging.
  var $selects = $selectsWrapper.find('select');

  var defaultPadding = parseInt($selects.slice(0, 1).css('padding-top').replace(/^(\d+)px$/, "$1")) + parseInt($selects.slice(0, 1).css('padding-bottom').replace(/^(\d+)px$/, "$1"));
  var defaultHeight = Drupal.HierarchicalSelect.state["hs-" + hsid].defaultHeight = $selects.slice(0, 1).height() + defaultPadding;
  var defaultSize = Drupal.HierarchicalSelect.state["hs-" + hsid].defaultSize = $selects.slice(0, 1).attr('size');
  defaultSize = (defaultSize == 0) ? 1 : defaultSize;
  var margin = Drupal.HierarchicalSelect.state["hs-" + hsid].margin = parseInt($selects.slice(0, 1).css('margin-bottom').replace(/^(\d+)px$/, "$1"));

  // Bind the drag event.
  $('.grippie', $selectsWrapper)
  .mousedown(startDrag)
  .dblclick(function() {
    if (Drupal.HierarchicalSelect.state["hs-" + hsid].resizedHeight == undefined) {
      Drupal.HierarchicalSelect.state["hs-" + hsid].resizedHeight = defaultHeight;
    }
    var resizedHeight = Drupal.HierarchicalSelect.state["hs-" + hsid].resizedHeight = (Drupal.HierarchicalSelect.state["hs-" + hsid].resizedHeight > defaultHeight + 2) ? defaultHeight : 4.6 / defaultSize * defaultHeight;
    Drupal.HierarchicalSelect.resize($selects, defaultHeight, resizedHeight, defaultSize, margin);
  });

  function startDrag(e) {
    staticOffset = $selects.slice(0, 1).height() - e.pageY;
    $selects.css('opacity', 0.25);
    $(document).mousemove(performDrag).mouseup(endDrag);
    return false;
  }

  function performDrag(e) {
    var resizedHeight = staticOffset + e.pageY;
    Drupal.HierarchicalSelect.resize($selects, defaultHeight, resizedHeight, defaultSize, margin);
    return false;
  }

  function endDrag(e) {
    var height = $selects.slice(0, 1).height();

    $(document).unbind("mousemove", performDrag).unbind("mouseup", endDrag);
    $selects.css('opacity', 1);
    if (height != Drupal.HierarchicalSelect.state["hs-" + hsid].resizedHeight) {
      Drupal.HierarchicalSelect.state["hs-" + hsid].resizedHeight = (height > defaultHeight) ? height : defaultHeight;
    }
  }
};

Drupal.HierarchicalSelect.resize = function($selects, defaultHeight, resizedHeight, defaultSize, margin) {
  if (resizedHeight == undefined) {
    resizedHeight = defaultHeight;
  }

  $selects
  .attr('size', (resizedHeight > defaultHeight) ? 2 : defaultSize)
  .height(Math.max(defaultHeight + margin, resizedHeight)); // Without the margin component, the height() method would allow the select to be sized to low: defaultHeight - margin.
};

Drupal.HierarchicalSelect.disableForm = function(hsid) {
  // Disable *all* submit buttons in this form, as well as all input-related
  // elements of the current hierarchical select.
  $('form:has(#hierarchical-select-' + hsid +'-wrapper) :submit')
  .add('#hierarchical-select-' + hsid +'-wrapper .hierarchical-select .selects select')
  .add('#hierarchical-select-' + hsid +'-wrapper .hierarchical-select :input')
  .attr('disabled', true);

  // Add the 'waiting' class. Default style: make everything transparent.
  $('#hierarchical-select-' + hsid +'-wrapper').addClass('waiting');

  // Indicate that the user has to wait.
  $('body').css('cursor', 'wait');
};

Drupal.HierarchicalSelect.enableForm = function(hsid) {
  // This method undoes everything the disableForm() method did.

  $e = $('form:has(#hierarchical-select-' + hsid +'-wrapper) :submit')
  .add('#hierarchical-select-' + hsid +'-wrapper .hierarchical-select :input:not(:submit)');

  // Don't enable the selects again if they've been disabled because the
  // dropbox limit was exceeded.
  dropboxLimitExceeded = $('#hierarchical-select-' + hsid +'-wrapper .hierarchical-select-dropbox-limit-warning').length > 0;
  if (!dropboxLimitExceeded) {
    $e = $e.add($('#hierarchical-select-' + hsid +'-wrapper .hierarchical-select .selects select'));
  }
  $e.removeAttr("disabled");

  // Don't enable the 'Add' button again if it's been disabled because the
  // dropbox limit was exceeded.
  if (dropboxLimitExceeded) {
    $('#hierarchical-select-' + hsid +'-wrapper .hierarchical-select :submit')
    .attr('disabled', true);
  }

  $('#hierarchical-select-' + hsid +'-wrapper').removeClass('waiting');

  $('body').css('cursor', 'auto');
};

Drupal.HierarchicalSelect.throwError = function(hsid, message) {
  // Show the error to the user.
  alert(message);

  // Log the error.
  Drupal.HierarchicalSelect.log(hsid, [ message ]);

  // Re-enable the form to allow the user to retry, but reset the selection to
  // the level label if possible, otherwise the "<none>" option if possible.
  var $select = $('#hierarchical-select-' + hsid +'-wrapper .hierarchical-select .selects select:first');
  var levelLabelOption = $('option[value^=label_]', $select).val();
  if (levelLabelOption !== undefined) {
    $select.val(levelLabelOption);
  }
  else {
    var noneOption = $('option[value=none]', $select).val();
    if (noneOption !== undefined) {
      $select.val(noneOption);
    }
  }
  Drupal.HierarchicalSelect.enableForm(hsid);
};

Drupal.HierarchicalSelect.prepareGETSubmit = function(hsid) {
  // Remove the name attributes of all form elements that end up in GET,
  // except for the "flat select" form element.
  $('#hierarchical-select-'+ hsid +'-wrapper', Drupal.HierarchicalSelect.context)
  .find('input, select')
  .not('.flat-select')
  .removeAttr('name');

  // Update the name attribute of the "flat select" form element
  var $flatSelect = $('#hierarchical-select-'+ hsid +'-wrapper .flat-select', Drupal.HierarchicalSelect.context);
  var newName = $flatSelect.attr('name').replace(/^([a-zA-Z0-9_\-]*)(?:\[flat_select\]){1}(\[\])?$/, "$1$2");
  $flatSelect.attr('name', newName);

  Drupal.HierarchicalSelect.triggerEvents(hsid, 'prepared-GET-submit', {});
};

Drupal.HierarchicalSelect.attachBindings = function(hsid) {
  var updateOpString = $('#hierarchical-select-'+ hsid +'-wrapper .update-button').val();
  var addOpString = $('#hierarchical-select-'+ hsid +'-wrapper .hierarchical-select .add-to-dropbox', Drupal.HierarchicalSelect.context).val();
  var createNewItemOpString = $('#hierarchical-select-'+ hsid +'-wrapper .hierarchical-select .create-new-item-create', Drupal.HierarchicalSelect.context).val();
  var cancelNewItemOpString = $('#hierarchical-select-'+ hsid +'-wrapper .hierarchical-select .create-new-item-cancel', Drupal.HierarchicalSelect.context).val();

  var data = {};
  data.hsid = hsid;

  $('#hierarchical-select-'+ hsid +'-wrapper', this.context)
  // "disable-updates" event
  .unbind('disable-updates').bind('disable-updates', data, function(e) {
    Drupal.settings.HierarchicalSelect.settings["hs-" + e.data.hsid]['updatesEnabled'] = false;
  })

  // "enforce-update" event
  .unbind('enforce-update').bind('enforce-update', data, function(e, extraPost) {
     Drupal.HierarchicalSelect.update(e.data.hsid, 'enforced-update', { opString: updateOpString, extraPost: extraPost });
  })

  // "prepare-GET-submit" event
  .unbind('prepare-GET-submit').bind('prepare-GET-submit', data, function(e) {
    Drupal.HierarchicalSelect.prepareGETSubmit(e.data.hsid);
  })

  // "update-hierarchical-select" event
  .find('.hierarchical-select .selects select').unbind().change(function(_hsid) {
    return function() {
      if (Drupal.settings.HierarchicalSelect.settings["hs-" + _hsid]['updatesEnabled']) {
        Drupal.HierarchicalSelect.update(_hsid, 'update-hierarchical-select', { opString: updateOpString, select_id : $(this).attr('id') });
      }
    };
  }(hsid)).end()

  // "create-new-item" event
  .find('.hierarchical-select .create-new-item .create-new-item-create').unbind().click(function(_hsid) {
    return function() {
      Drupal.HierarchicalSelect.update(_hsid, 'create-new-item', { opString : createNewItemOpString });
      return false; // Prevent the browser from POSTing the page.
    };
  }(hsid)).end()

  // "cancel-new-item" event"
  .find('.hierarchical-select .create-new-item .create-new-item-cancel').unbind().click(function(_hsid) {
    return function() {
      Drupal.HierarchicalSelect.update(_hsid, 'cancel-new-item', { opString : cancelNewItemOpString });
      return false; // Prevent the browser from POSTing the page (in case of the "Cancel" button).
    };
  }(hsid)).end()

  // "add-to-dropbox" event
  .find('.hierarchical-select .add-to-dropbox').unbind().click(function(_hsid) {
    return function() {
      Drupal.HierarchicalSelect.update(_hsid, 'add-to-dropbox', { opString : addOpString });
      return false; // Prevent the browser from POSTing the page.
    };
  }(hsid)).end()

  // "remove-from-dropbox" event
  // (anchors in the .dropbox-remove cells in the .dropbox table)
  .find('.dropbox .dropbox-remove a').unbind().click(function(_hsid) {
    return function() {
      var isDisabled = $('#hierarchical-select-'+ hsid +'-wrapper', Drupal.HierarchicalSelect.context).attr('disabled');

      // If the hierarchical select is disabled, then ignore this click.
      if (isDisabled) {
        return false;
      }

      // Check the (hidden, because JS is enabled) checkbox that marks this
      // dropbox entry for removal.
      $(this).parent().find('input[type=checkbox]').attr('checked', true);
      Drupal.HierarchicalSelect.update(_hsid, 'remove-from-dropbox', { opString: updateOpString });
      return false; // Prevent the browser from POSTing the page.
    };
  }(hsid));
};

Drupal.HierarchicalSelect.preUpdateAnimations = function(hsid, updateType, lastUnchanged, callback) {
  switch (updateType) {
    case 'update-hierarchical-select':
      // Drop out the selects of the levels deeper than the select of the
      // level that just changed.
      var animationDelay = Drupal.settings.HierarchicalSelect.settings["hs-" + hsid]['animationDelay'];
      var $animatedSelects = $('#hierarchical-select-'+ hsid +'-wrapper .hierarchical-select .selects select', Drupal.HierarchicalSelect.context).slice(lastUnchanged);
      if ($animatedSelects.size() > 0) {
        $animatedSelects.hide();
        for (var i = 0; i < $animatedSelects.size(); i++) {
          if (i < $animatedSelects.size() - 1) {
            $animatedSelects.slice(i, i + 1).hide("drop", { direction: "left" }, animationDelay);
          }
          else {
            $animatedSelects.slice(i, i + 1).hide("drop", { direction: "left" }, animationDelay, callback);
          }
        }
      }
      else if (callback) {
        callback();
      }
      break;
    default:
      if (callback) {
        callback();
      }
      break;
  }
};

Drupal.HierarchicalSelect.postUpdateAnimations = function(hsid, updateType, lastUnchanged, callback) {
  if (Drupal.settings.HierarchicalSelect.settings["hs-" + hsid].resizable) {
    // Restore the resize.
    Drupal.HierarchicalSelect.resize(
      $('#hierarchical-select-' + hsid + '-wrapper .hierarchical-select .selects select', Drupal.HierarchicalSelect.context),
      Drupal.HierarchicalSelect.state["hs-" + hsid].defaultHeight,
      Drupal.HierarchicalSelect.state["hs-" + hsid].resizedHeight,
      Drupal.HierarchicalSelect.state["hs-" + hsid].defaultSize,
      Drupal.HierarchicalSelect.state["hs-" + hsid].margin
    );
  }

  switch (updateType) {
    case 'update-hierarchical-select':
      var $createNewItemInput = $('#hierarchical-select-'+ hsid +'-wrapper .hierarchical-select .create-new-item-input', Drupal.HierarchicalSelect.context);
      // Hide the loaded selects after the one that was just changed, then
      // drop them in.
      var animationDelay = Drupal.settings.HierarchicalSelect.settings["hs-" + hsid]['animationDelay'];
      var $animatedSelects = $('#hierarchical-select-'+ hsid +'-wrapper .hierarchical-select .selects select', Drupal.HierarchicalSelect.context).slice(lastUnchanged);
      if ($animatedSelects.size() > 0) {
        $animatedSelects.hide();
        for (var i = 0; i < $animatedSelects.size(); i++) {
          if (i < $animatedSelects.size() - 1) {
            $animatedSelects.slice(i, i + 1).show("drop", { direction: "left" }, animationDelay);
          }
          else {
            $animatedSelects.slice(i, i + 1).show("drop", { direction: "left" }, animationDelay, callback);
          }
        }
      }
      else if (callback) {
        callback();
      }
      if ($createNewItemInput.size() == 0) {
        // Give focus to the level below the one that has changed, if it
        // exists.
        setTimeout(
          function() {
            $('#hierarchical-select-'+ hsid +'-wrapper .hierarchical-select .selects select', Drupal.HierarchicalSelect.context)
              .slice(lastUnchanged, lastUnchanged + 1)
              .focus();
          },
          animationDelay + 100
        );
      }
      else {
        // Give focus to the input field of the "create new item/level"
        // section, if it exists, and also select the existing text.
        $createNewItemInput.focus();
        $createNewItemInput[0].select();
      }
      break;

    case 'create-new-item':
      // Make sure that other Hierarchical Selects that represent the same
      // hierarchy are also updated, to make sure that they have the newly
      // created item!
      var cacheId = Drupal.settings.HierarchicalSelect.settings["hs-" + hsid].cacheId;
      for (var otherHsid in Drupal.settings.HierarchicalSelect.settings) {
        if (Drupal.settings.HierarchicalSelect.settings[otherHsid].cacheId == cacheId) {
          $('#hierarchical-select-'+ otherHsid +'-wrapper')
          .trigger('enforce-update');
        }
      }
      // TRICKY: NO BREAK HERE!

    case 'cancel-new-item':
      // After an item/level has been created/cancelled, reset focus to the
      // beginning of the hierarchical select.
      $('#hierarchical-select-'+ hsid +'-wrapper .hierarchical-select .selects select', Drupal.HierarchicalSelect.context)
      .slice(0, 1)
      .focus();

      if (callback) {
        callback();
      }
      break;

    default:
      if (callback) {
        callback();
      }
      break;
  }
};

Drupal.HierarchicalSelect.triggerEvents = function(hsid, updateType, settings) {
  $('#hierarchical-select-'+ hsid +'-wrapper', Drupal.HierarchicalSelect.context)
  .trigger(updateType, [ hsid, settings ]);
};

Drupal.HierarchicalSelect.update = function(hsid, updateType, settings) {
  var post = $('form:has(#hierarchical-select-' + hsid +'-wrapper)', Drupal.HierarchicalSelect.context).formToArray();
  var hs_current_language = Drupal.settings.HierarchicalSelect.hs_current_language;

  // Pass the hierarchical_select id via POST.
  post.push({ name : 'hsid', value : hsid });
  // Send the current language so we can use the same language during the AJAX callback.
  post.push({ name : 'hs_current_language', value : hs_current_language});
  // Emulate the AJAX data sent normally so that we get the same theme.
  post.push({ name : 'ajax_page_state[theme]', value : Drupal.settings.ajaxPageState.theme });
  post.push({ name : 'ajax_page_state[theme_token]', value : Drupal.settings.ajaxPageState.theme_token });

  // If a cache system is installed, let the server know if it's running
  // properly. If it is running properly, the server will send back additional
  // information to maintain a lazily-loaded cache.
  if (Drupal.HierarchicalSelect.cache != null) {
    post.push({ name : 'client_supports_caching', value : Drupal.HierarchicalSelect.cache.status() });
  }

  // updateType is one of:
  // - 'none' (default)
  // - 'update-hierarchical-select'
  // - 'enforced-update'
  // - 'create-new-item'
  // - 'cancel-new-item'
  // - 'add-to-dropbox'
  // - 'remove-from-dropbox'
  switch (updateType) {
    case 'update-hierarchical-select':
      var value = $('#'+ settings.select_id).val();
      var lastUnchanged = parseInt(settings.select_id.replace(/^.*-hierarchical-select-selects-(\d+)/, "$1")) + 1;
      var optionClass = $('#'+ settings.select_id).find('option[value="'+ value +'"]').attr('class');

      // Don't do anything (also no callback to the server!) when the selected
      // item is:
      // - the '<none>' option and the renderFlatSelect setting is disabled, or
      // - a level label, or
      // - an option of class 'has-no-children', and
      //   (the renderFlatSelect setting is disabled or the dropbox is enabled)
      //   and
      //   (the createNewLevels setting is disabled).
      if ((value == 'none' && Drupal.settings.HierarchicalSelect.settings["hs-" + hsid]['renderFlatSelect'] == false)
          || value.match(/^label_\d+$/)
          || (optionClass == 'has-no-children'
             &&
             (
               (Drupal.settings.HierarchicalSelect.settings["hs-" + hsid]['renderFlatSelect'] == false
                || $('#hierarchical-select-'+ hsid +'-wrapper .dropbox').length > 0
               )
               &&
               Drupal.settings.HierarchicalSelect.settings["hs-" + hsid]['createNewLevels'] == false
             )
           )
         )
      {
        Drupal.HierarchicalSelect.preUpdateAnimations(hsid, updateType, lastUnchanged, function() {
          // Remove the sublevels.
          $('#hierarchical-select-'+ hsid +'-wrapper .hierarchical-select .selects select', Drupal.HierarchicalSelect.context)
          .slice(lastUnchanged)
          .remove();

          // The selection of this hierarchical select has changed!
          Drupal.HierarchicalSelect.triggerEvents(hsid, 'change-hierarchical-select', settings);
        });
        return;
      }
      post.push({ name : 'op', value : settings.opString });
      break;

    case 'enforced-update':
      post.push({ name : 'op', value : settings.opString });
      post = post.concat(settings.extraPost);
      break;

    case 'create-new-item':
    case 'cancel-new-item':
    case 'add-to-dropbox':
    case 'remove-from-dropbox':
      post.push({ name : 'op', value : settings.opString });
      break;

    default:
      break;
  }

  // Construct the URL the request should be made to.
  var url = Drupal.settings.HierarchicalSelect.settings["hs-" + hsid].ajax_url;

  // Construct the object that contains the options for a callback to the
  // server. If a client-side cache is found however, it's possible that this
  // won't be used.
  var ajaxOptions = $.extend({}, Drupal.ajax.prototype, {
    url:        url,
    type:       'POST',
    dataType:   'json',
    data:       post,
    effect:     'fade',
    wrapper:    '#hierarchical-select-' + hsid + '-wrapper',
    beforeSend: function() {
      Drupal.HierarchicalSelect.triggerEvents(hsid, 'before-' + updateType, settings);
      Drupal.HierarchicalSelect.disableForm(hsid);
    },
    error: function (XMLHttpRequest, textStatus, errorThrown) {
      // When invalid HTML is received in Safari, jQuery calls this function.
      Drupal.HierarchicalSelect.throwError(hsid, Drupal.t('Received an invalid response from the server.'));
    },
    success: function(response, status) {
      // An invalid response may be returned by the server, in case of a PHP
      // error. Detect this and let the user know.
      if (response === null || response.length == 0) {
        Drupal.HierarchicalSelect.throwError(hsid, Drupal.t('Received an invalid response from the server.'));
        return;
      }

      // Execute all AJAX commands in the response. But pass an additional
      // hsid parameter, which is then only used by the commands written
      // for Hierarchical Select.

      // This is another hack because of the non-Drupal ajax implementation
      // of this module, one of the response that can come from a drupal
      // ajax command is insert, which expects a Drupal.ajax object as the first
      // arguments and assumes that certain functions/settings are available.
      // Because we are calling a Drupal.ajax.command but providing the regular
      // jQuery ajax object itself, we are allowing Drupal.ajax.prototype.commands
      // to misserably fail.
      //
      // This hack attempts to fix one issue with an insert command,
      // @see https://www.drupal.org/node/2393695, allowing it to work properly
      // Other hacks might be necessary for other ajax commands if they are added
      // by external modules.
      this.effect = 'none';
      this.getEffect = Drupal.ajax.prototype.getEffect;

      for (var i in response) {
        if (response[i]['command'] && Drupal.ajax.prototype.commands[response[i]['command']]) {
          Drupal.ajax.prototype.commands[response[i]['command']](this, response[i], status, hsid);
        }
      }

      // Attach behaviors. This is just after the HTML has been updated, so
      // it's as soon as we can.
      Drupal.attachBehaviors($('#hierarchical-select-' + hsid + '-wrapper').parents('div.form-type-hierarchical-select')[0]);

      // Transform the hierarchical select and/or dropbox to the JS variant,
      // make it resizable again and re-enable the disabled form items.
      Drupal.HierarchicalSelect.enableForm(hsid);

      Drupal.HierarchicalSelect.postUpdateAnimations(hsid, updateType, lastUnchanged, function() {
        // Update the client-side cache when:
        // - information for in the cache is provided in the response, and
        // - the cache system is available, and
        // - the cache system is running.
        if (response.cache != null && Drupal.HierarchicalSelect.cache != null && Drupal.HierarchicalSelect.cache.status()) {
          Drupal.HierarchicalSelect.cache.sync(hsid, response.cache);
        }

        if (response.log != undefined) {
          Drupal.HierarchicalSelect.log(hsid, response.log);
        }

        Drupal.HierarchicalSelect.triggerEvents(hsid, updateType, settings);

        if (updateType == 'update-hierarchical-select') {
          // The selection of this hierarchical select has changed!
          Drupal.HierarchicalSelect.triggerEvents(hsid, 'change-hierarchical-select', settings);
        }
      });
    }
  });

  // Use the client-side cache to update the hierarchical select when:
  // - the hierarchical select is being updated (i.e. no add/remove), and
  // - the renderFlatSelect setting is disabled, and
  // - the createNewItems setting is disabled, and
  // - the cache system is available, and
  // - the cache system is running.
  // Otherwise, perform a normal dynamic form submit.
  if (updateType == 'update-hierarchical-select'
      && Drupal.settings.HierarchicalSelect.settings["hs-" + hsid]['renderFlatSelect'] == false
      && Drupal.settings.HierarchicalSelect.settings["hs-" + hsid]['createNewItems'] == false
      && Drupal.HierarchicalSelect.cache != null
      && Drupal.HierarchicalSelect.cache.status())
  {
    Drupal.HierarchicalSelect.cache.updateHierarchicalSelect(hsid, value, settings, lastUnchanged, ajaxOptions);
  }
  else {
    Drupal.HierarchicalSelect.preUpdateAnimations(hsid, updateType, lastUnchanged, function() {
      // Adding current theme to prevent conflicts, @see ajax.js
      // @TODO, try converting to use Drupal.ajax instead.

      // Prevent duplicate HTML ids in the returned markup.
      // @see drupal_html_id()
      var ids = [];
      $('[id]').each(function () {
        ids.push(this.id);
      });

      ajaxOptions.data.push({ name : 'ajax_html_ids[]', value : ids });

      ajaxOptions.data.push({ name : 'ajax_page_state[theme]', value : Drupal.settings.ajaxPageState.theme });
      ajaxOptions.data.push({ name : 'ajax_page_state[theme_token]', value : Drupal.settings.ajaxPageState.theme_token });
      for (var key in Drupal.settings.ajaxPageState.css) {
        ajaxOptions.data.push({ name : 'ajax_page_state[css][' + key + ']', value : 1});
      }
      for (var key in Drupal.settings.ajaxPageState.js) {
        ajaxOptions.data.push({ name : 'ajax_page_state[js][' + key + ']', value : 1});
      }

      // Make it work with jquery update
      if (Drupal.settings.ajaxPageState.jquery_version) {
        ajaxOptions.data.push({ name : 'ajax_page_state[jquery_version]', value : Drupal.settings.ajaxPageState.jquery_version });
      }

      $.ajax(ajaxOptions);
    });
  }
};

Drupal.ajax.prototype.commands.hierarchicalSelectUpdate = function(ajax, response, status, hsid) {
  // Replace the old HTML with the (relevant part of) retrieved HTML.
  $('#hierarchical-select-'+ hsid +'-wrapper', Drupal.HierarchicalSelect.context)
  .parent('.form-item')
  .replaceWith($(response.output));
};

Drupal.ajax.prototype.commands.hierarchicalSelectSettingsUpdate = function(ajax, response, status, hsid) {
  Drupal.settings.HierarchicalSelect.settings["hs-" + response.hsid] = response.settings;
};

})(jQuery);
;
(function ($) {

Drupal.behaviors.textarea = {
  attach: function (context, settings) {
    $('.form-textarea-wrapper.resizable', context).once('textarea', function () {
      var staticOffset = null;
      var textarea = $(this).addClass('resizable-textarea').find('textarea');
      var grippie = $('<div class="grippie"></div>').mousedown(startDrag);

      grippie.insertAfter(textarea);

      function startDrag(e) {
        staticOffset = textarea.height() - e.pageY;
        textarea.css('opacity', 0.25);
        $(document).mousemove(performDrag).mouseup(endDrag);
        return false;
      }

      function performDrag(e) {
        textarea.height(Math.max(32, staticOffset + e.pageY) + 'px');
        return false;
      }

      function endDrag(e) {
        $(document).unbind('mousemove', performDrag).unbind('mouseup', endDrag);
        textarea.css('opacity', 1);
      }
    });
  }
};

})(jQuery);
;
(function ($) {

/**
 * Toggle the visibility of a fieldset using smooth animations.
 */
Drupal.toggleFieldset = function (fieldset) {
  var $toggle = $($(fieldset).find('[data-toggle=collapse]').data('target'));
  if ($toggle.length) {
    $toggle.collapse('toggle');
  }
};

/**
 * Scroll a given fieldset into view as much as possible.
 */
Drupal.collapseScrollIntoView = function (node) {
  var h = document.documentElement.clientHeight || document.body.clientHeight || 0;
  var offset = document.documentElement.scrollTop || document.body.scrollTop || 0;
  var posY = $(node).offset().top;
  var fudge = 55;
  if (posY + node.offsetHeight + fudge > h + offset) {
    if (node.offsetHeight > h) {
      window.scrollTo(0, posY);
    }
    else {
      window.scrollTo(0, posY + node.offsetHeight - h + fudge);
    }
  }
};

Drupal.behaviors.collapse = {
  attach: function (context, settings) {
    $('fieldset.collapsible', context).once('collapse', function () {
      var $fieldset = $(this);
      // Expand fieldset if there are errors inside, or if it contains an
      // element that is targeted by the URI fragment identifier.
      var anchor = location.hash && location.hash != '#' ? ', ' + location.hash : '';
      if ($fieldset.find('.error' + anchor).length) {
        $fieldset.removeClass('collapsed');
      }

      var summary = $('<span class="summary"></span>');
      $fieldset.
        bind('summaryUpdated', function () {
          var text = $.trim($fieldset.drupalGetSummary());
          summary.html(text ? ' (' + text + ')' : '');
        })
        .trigger('summaryUpdated');

      // Turn the legend into a clickable link, but retain span.fieldset-legend
      // for CSS positioning.
      var $legend = $('> legend .fieldset-legend', this);

      $('<span class="fieldset-legend-prefix element-invisible"></span>')
        .append($fieldset.hasClass('collapsed') ? Drupal.t('Show') : Drupal.t('Hide'))
        .prependTo($legend);

      $fieldset.find('[data-toggle=collapse]').on('click', function (e) {
        e.preventDefault();
      });

      // Bind Bootstrap events with Drupal core events.
      $fieldset
        .append(summary)
        .on('show.bs.collapse', function () {
          $fieldset
            .removeClass('collapsed')
            .find('> legend span.fieldset-legend-prefix').html(Drupal.t('Hide'));
        })
        .on('shown.bs.collapse', function () {
          $fieldset.trigger({ type: 'collapsed', value: false });
          Drupal.collapseScrollIntoView($fieldset.get(0));
        })
        .on('hide.bs.collapse', function () {
          $fieldset
            .addClass('collapsed')
            .find('> legend span.fieldset-legend-prefix').html(Drupal.t('Show'));
        })
        .on('hidden.bs.collapse', function () {
          $fieldset.trigger({ type: 'collapsed', value: true });
        });
    });
  }
};

})(jQuery);
;
(function($) {
  Drupal.behaviors.chosen = {
    attach: function(context, settings) {
      settings.chosen = settings.chosen || Drupal.settings.chosen;

      // Prepare selector and add unwantend selectors.
      var selector = settings.chosen.selector;

      // Function to prepare all the options together for the chosen() call.
      var getElementOptions = function (element) {
        var options = $.extend({}, settings.chosen.options);

        // The width default option is considered the minimum width, so this
        // must be evaluated for every option.
        if (settings.chosen.minimum_width > 0) {
          if ($(element).width() < settings.chosen.minimum_width) {
            options.width = settings.chosen.minimum_width + 'px';
          }
          else {
            options.width = $(element).width() + 'px';
          }
        }

        // Some field widgets have cardinality, so we must respect that.
        // @see chosen_pre_render_select()
        if ($(element).attr('multiple') && $(element).data('cardinality')) {
          options.max_selected_options = $(element).data('cardinality');
        }

        return options;
      };

      // Process elements that have opted-in for Chosen.
      // @todo Remove support for the deprecated chosen-widget class.
      $('select.chosen-enable, select.chosen-widget', context).once('chosen', function() {
        options = getElementOptions(this);
        $(this).chosen(options);
      });

      $(selector, context)
        // Disabled on:
        // - Field UI
        // - WYSIWYG elements
        // - Tabledrag weights
        // - Elements that have opted-out of Chosen
        // - Elements already processed by Chosen
        .not('#field-ui-field-overview-form select, #field-ui-display-overview-form select, .wysiwyg, .draggable select[name$="[weight]"], .draggable select[name$="[position]"], .chosen-disable, .chosen-processed')
        .filter(function() {
          // Filter out select widgets that do not meet the minimum number of
          // options.
          var minOptions = $(this).attr('multiple') ? settings.chosen.minimum_multiple : settings.chosen.minimum_single;
          if (!minOptions) {
            // Zero value means no minimum.
            return true;
          }
          else {
            return $(this).find('option').length >= minOptions;
          }
        })
        .once('chosen', function() {
          options = getElementOptions(this);
          $(this).chosen(options);
        });
    }
  };
})(jQuery);
;
