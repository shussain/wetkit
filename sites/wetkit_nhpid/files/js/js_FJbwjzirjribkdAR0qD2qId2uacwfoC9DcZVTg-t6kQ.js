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
