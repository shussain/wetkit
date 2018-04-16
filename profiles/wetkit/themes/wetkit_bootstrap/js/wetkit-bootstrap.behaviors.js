// Generated by CoffeeScript 1.6.3
(function($) {
  /*
  The recommended way for producing HTML markup through JavaScript is to write
  theming functions. These are similiar to the theming functions that you might
  know from 'phptemplate' (the default PHP templating engine used by most
  Drupal themes including Omega). JavaScript theme functions accept arguments
  and can be overriden by sub-themes.

  In most cases, there is no good reason to NOT wrap your markup producing
  JavaScript in a theme function.
  */

  Drupal.theme.prototype.wetkitBootstrapExampleButton = function(path, title) {
    return $("<a href=\"" + path + "\" title=\"" + title + "\">" + title + "</a>");
  };
  /*
  Behaviors are Drupal's way of applying JavaScript to a page. The advantage
  of behaviors over simIn short, the advantage of Behaviors over a simple
  document.ready() lies in how it interacts with content loaded through Ajax.
  Opposed to the 'document.ready()' event which is only fired once when the
  page is initially loaded, behaviors get re-executed whenever something is
  added to the page through Ajax.

  You can attach as many behaviors as you wish. In fact, instead of overloading
  a single behavior with multiple, completely unrelated tasks you should create
  a separate behavior for every separate task.

  In most cases, there is no good reason to NOT wrap your JavaScript code in a
  behavior.

  @param context
  The context for which the behavior is being executed. This is either the
  full page or a piece of HTML that was just added through Ajax.
  @param settings
  An array of settings (added through drupal_add_js()). Instead of accessing
  Drupal.settings directly you should use this because of potential
  modifications made by the Ajax callback that also produced 'context'.
  */

  return Drupal.behaviors.wetkitBootstrapExampleBehavior = {
    attach: function(context, settings) {
      return $(".some-selector", context).once("foo", function() {
        var $anchor;
        $anchor = Drupal.theme("wetkitBootstrapExampleButton", settings.myExampleLinkPath, settings.myExampleLinkTitle);
        return $anchor.appendTo(this);
      });
    }
  };

  /*
  Fix for youtube z-index issue.
   */
  return Drupal.behaviors.wetkitBootstrapYoutubeBehavior = {
    attach: function(context, settings) {
      return $(document).ready(function() {
        $("iframe").each(function() {
          var char, url;
          url = $(this).attr("src");
          char = "?";
          if (url.indexOf("?") !== -1) {
            char = "&";
          }
          $(this).attr("src", url + char + "wmode=transparent");
        });
      });
    }
  };
})(jQuery);
