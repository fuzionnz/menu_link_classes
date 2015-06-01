(function ($) {
  Drupal.behaviors.menu_link_classes = {
    attach: function (context, settings) {
      $('input.menu-class', $(this).closest('tr')).attr('disabled', !this.checked);
      $('#menu-overview-form td.checkbox input[type="checkbox"]', context).on('change', function () {
        $('input.menu-class', $(this).closest('tr')).attr('disabled', !this.checked);
      });
      $('#menu-overview-form', context).on('submit', function () {
        $('#menu-overview-form input.menu-class').attr('disabled', false);
      });
    }
  };
})(jQuery);
