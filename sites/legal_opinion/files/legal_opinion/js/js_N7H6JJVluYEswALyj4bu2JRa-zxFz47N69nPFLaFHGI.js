function showpage(){jQuery("html").show()}function hidepage(){jQuery("html").hide()}jQuery(document).ready(function(e){var t=Drupal.settings.splashify.js_mode;if(t=="redirect"){hidepage()}var n=new Date;var r=n.getTime()/1e3;var i=document.referrer+"";var s=window.location.hostname+"";var o=e.jStorage.get("splash",0);var u=Drupal.settings.splashify.js_splash_always;var a=Drupal.settings.splashify.js_mode_settings.urls;var f=Drupal.settings.splashify.js_disable_referrer_check;if(i.indexOf("?")!=-1){i=i.substr(0,i.indexOf("?"))}if(i.search(s)!=-1&&!f||jQuery.inArray(window.location.pathname,a)>-1){showpage();return}var l=false;if(!o||o<r||u=="1"){l=true}if(l){var c=Drupal.settings.splashify.js_expire_after;var h=e.jStorage.get("splashlasturl","");var p="";e.jStorage.set("splash",r+c);if(Drupal.settings.splashify.js_mode_settings.system_splash!=""){p=Drupal.settings.splashify.js_mode_settings.system_splash}else if(Drupal.settings.splashify.js_mode_settings.mode=="sequence"){var d=0;var v=jQuery.inArray(h,a);if(v>-1&&v+1<Drupal.settings.splashify.js_mode_settings.total_urls){d=v+1}p=a[d]}else if(Drupal.settings.splashify.js_mode_settings.mode=="random"){var d=Math.floor(Math.random()*Drupal.settings.splashify.js_mode_settings.total_urls);p=a[d]}e.jStorage.set("splashlasturl",p);if(t=="redirect"){window.location.replace(p)}else if(t=="colorbox"){e.colorbox({transition:"elastic",iframe:true,href:p,width:Drupal.settings.splashify.js_mode_settings.size_width,height:Drupal.settings.splashify.js_mode_settings.size_height})}else if(t=="window"){window.open(p,"splash",Drupal.settings.splashify.js_mode_settings.size)}}else if(t=="redirect"){showpage()}});;
/**
 *  @file
 *  Module overrides.
 */

(function ($) {

/**
 * Default jQuery dialog options used when creating the Linkit modal.
 */
if(typeof(Drupal.linkit) != "undefined"){
  Drupal.linkit.modalOptions = function() {
    return {
      dialogClass: 'linkit-wrapper',
      modal: true,
      draggable: false,
      resizable: false,
      width: 520,
      position: ['center', 90],
      minHeight: 0,
      zIndex: 210000,
      close: Drupal.linkit.modalClose,
      open: function (event, ui) {
        // Change the overlay style.
        $('.ui-widget-overlay').css({
          opacity: 0.5,
          filter: 'Alpha(Opacity=50)',
        });
      },
      title: 'Linkit'
    };
  };
}
})(jQuery);
;
