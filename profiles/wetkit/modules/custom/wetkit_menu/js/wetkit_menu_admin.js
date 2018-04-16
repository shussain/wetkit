// Generated by CoffeeScript 1.6.3
/*
 @file
 Custom JS for administering WetKit Menu.
*/

/*
 In admin menu edit, this hides and closes the WET config depending on
 whether a minipanel is selected.
*/

(function($) {
  return Drupal.behaviors.menuMiniPanelsAdmin = {
    attach: function(context, settings) {
      var toggleHoverSettings;
      toggleHoverSettings = function() {
        if ($("#edit-options-minipanel").val() === "" && $("#menu-minipanels-hover-settings").is(":visible")) {
          return $("#menu-minipanels-hover-settings").slideUp(500);
        } else {
          if ($("#edit-options-minipanel").val() !== "") {
            return $("#menu-minipanels-hover-settings").slideDown(500);
          }
        }
      };
      $("#edit-options-minipanel").change(function(e) {
        return toggleHoverSettings();
      });
      return toggleHoverSettings();
    }
  };
})(jQuery);