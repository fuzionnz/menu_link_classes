<?php

/**
 * @file
 * Administration for Menu Link Classes.
 */

/**
 * System settings form for Menu Link Classes.
 */
function menu_link_classes_admin_form() {
  $form['menu_link_classes_default_state'] = array(
    '#type' => 'radios',
    '#title' => t('Default State'),
    '#default_value' => variable_get('menu_link_classes_default_state', TRUE),
    '#options' => array(
      1 => 'On',
      0 => 'Off',
    ),
    '#description' => t('Default behaviour for new / undefined menu entries.'),
  );
  $options_value = array();
  $options = variable_get('menu_link_classes_options', array());
  foreach ($options as $key => $value) {
    $options_value[] = t('@key|@value', array('@key' => $key, '@value' => $value));
  }
  $options_value = implode("\n", $options_value);
  $form['menu_link_classes_options'] = array(
    '#type' => 'textarea',
    '#title' => t('Classes'),
    '#default_value' => $options_value,
    '#description' => t('Classes, in <em>option|Label</em> format.'),
  );
  return system_settings_form($form);
}

/**
 * Validation handler.
 *
 * Changes format for storing menu_link_classes_options variable.
 */
function menu_link_classes_admin_form_validate($form, &$form_state) {
  $options = array();
  if (!empty($form_state['values']['menu_link_classes_options'])) {
    $lines = explode("\n", $form_state['values']['menu_link_classes_options']);
    foreach ($lines as $line) {
      $option = explode('|', $line);
      if (count($option) > 2) {
        form_set_error('menu_link_classes_options', t('Only one pipe (|) character per line in the <em>Classes</em> field.'));
      }
      if (count($option) == 1) {
        $option[1] = $option[0];
      }
      $options[$option[0]] = $option[1];
    }
  }
  $form_state['values']['menu_link_classes_options'] = $options;
}
