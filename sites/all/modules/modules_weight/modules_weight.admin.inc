<?php

/**
 * @file
 * Calls results to administration's pages.
 */

require_once dirname(__FILE__) . '/modules_weight.helpers.inc';

/**
 * Form constructor for Module Weight form.
 *
 * @param array $form
 *   The form element.
 * @param array $form_state
 *   The form state.
 */
function modules_weight_admin_config_page_form(array $form, array &$form_state) {
  $form['modules']['#tree'] = TRUE;

  // Getting the module list.
  $modules = _modules_weight_modules_list();
  // Iterate over each of the modules.
  foreach ($modules as $module_name => $module) {
    // The rows info.
    // Module name.
    $form['modules'][$module_name]['name'] = array(
      '#markup' => $module['name'],
    );
    // Module description.
    $form['modules'][$module_name]['description'] = array(
      '#markup' => $module['description'],
    );
    // Module weight.
    $form['modules'][$module_name]['weight'] = array(
      '#type' => 'weight',
      '#default_value' => $module['weight'],
      '#delta' => _modules_weight_prepare_delta($module['weight']),
    );
    // Module old weight value, used to see if we need to update the weight.
    $form['modules'][$module_name]['old_weight_value'] = array(
      '#type' => 'hidden',
      '#value' => $module['weight'],
    );
    // Module package.
    $form['modules'][$module_name]['package'] = array(
      '#markup' => $module['package'],
    );
  }
  // The form button.
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Save Changes'));
  return $form;
}

/**
 * Form submit handler for the modules_weight_admin_config_page_form form.
 *
 * @param array $form
 *   The form element.
 * @param array $form_state
 *   The form state.
 */
function modules_weight_admin_config_page_form_submit(array $form, array &$form_state) {
  // Variable to see if we have uptaded some module weight.
  $printed = FALSE;

  foreach ($form_state['values']['modules'] as $name => $weight) {
    if ($weight['weight'] != $weight['old_weight_value']) {
      // Setting the new weight.
      _modules_weight_module_set_weight($name, $weight['weight']);
      // Printing the update message.
      if (!$printed) {
        drupal_set_message(t('The modules weight was updated.'));
        $printed = TRUE;
      }

      $variables = [
        '@module_name' => system_get_info('module', $name)['name'],
        '@weight' => $weight['weight'],
      ];
      // Printing information about the modules weight.
      drupal_set_message(t('@module_name have now as weight: @weight', $variables));
    }
  }
  // Printing message if there are not module that has changed.
  if (!$printed) {
    drupal_set_message(t("You don't have changed the weight for any module."), 'warning');
  }
}

/**
 * Form constructor for Module Weight Configuration form.
 *
 * @param array $form
 *   The form element.
 * @param array $form_state
 *   The form state.
 */
function modules_weight_configuration_form(array $form, array &$form_state) {
  $form['modules_weight_show_system_modules'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show system modules'),
    '#return_value' => 1,
    '#default_value' => variable_get('modules_weight_show_system_modules'),
    '#description' => t("Cautions: This module just display non-core modules by default, if you check this option you will be able to change the core modules weight and as you might notice, all core modules has 0 as weight value by default."),
  );

  return system_settings_form($form);
}
