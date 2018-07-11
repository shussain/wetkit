<?php

/**
 * @file
 * Helper functions.
 */

/**
 * Prepares the delta for the weight field on the administration form.
 *
 * If a module has a weight higher then 100 (or lower than 100), it will use
 * that value as delta and the '#weight' field will turn into a textfield most
 * likely.
 *
 * @param int $weight
 *   The weight.
 *
 * @return int
 *   The weight.
 */
function _modules_weight_prepare_delta($weight) {
  $delta = 100;

  // Typecasting to int.
  $weight = (int) $weight;

  if ($weight > $delta) {
    return $weight;
  }

  if ($weight < -100) {
    return $weight * -1;
  }

  return $delta;
}

/**
 * Return the modules list.
 *
 * @param bool $force
 *   Force to show the core modules.
 *
 * @return array
 *   The modules list.
 */
function _modules_weight_modules_list($force = FALSE) {
  $modules = [];
  // Get current list of modules.
  $installed_modules = system_get_info('module');

  if ($force) {
    $show_system_modules = TRUE;
  }
  else {
    // Getting the config to know if we should show or not the core modules.
    $show_system_modules = variable_get('modules_weight_show_system_modules');
  }

  // Iterate through each of the modules.
  foreach ($installed_modules as $module_name => $module_info) {
    // We don't want to show the hidden modules, or the Core modules
    // (if the configuration is set to FALSE).
    if (!isset($module_info['hidden']) && ($show_system_modules || $module_info['package'] != 'Core')) {
      $modules[$module_name]['name'] = $module_info['name'];
      $modules[$module_name]['description'] = $module_info['description'];
      $modules[$module_name]['weight'] = _modules_weight_module_get_weight($module_name);
      $modules[$module_name]['package'] = $module_info['package'];
    }
  }
  // Sorting all modules by their weight.
  uasort($modules, 'sort_by_weight_and_name');

  return $modules;
}

/**
 * Sets weight of a particular module.
 *
 * @param string $module
 *   The name of the module (without the .module extension).
 * @param int $weight
 *   An integer representing the weight of the module.
 */
function _modules_weight_module_set_weight($module, $weight) {
  // The query.
  $query = "UPDATE {system}
            SET weight = :weight
            WHERE type = 'module' AND name = :name";
  // Executing the query.
  db_query($query, array(':weight' => $weight, ':name' => $module));
}

/**
 * Gets weight of a particular module.
 *
 * @param string $module
 *   The name of the module (without the .module extension).
 *
 * @return int
 *   An integer representing the weight of the module.
 */
function _modules_weight_module_get_weight($module) {
  // The query.
  $query = "SELECT weight
            FROM {system}
            WHERE type = 'module' AND name = :name";
  // Executing the query and getting the module weight.
  $weight = db_query($query, array(':name' => $module))->fetchObject()->weight;

  return $weight;
}

/**
 * Sorts a structured array by the 'weight' and 'name element.
 *
 * Note that the sorting is by the 'weight' array element, not by the render
 * element property '#weight'.
 *
 * Callback for uasort().
 *
 * @param array $a
 *   First item for comparison. The compared items should be associative
 *   arrays that optionally include a 'weight' element. For items without a
 *   'weight' element, a default value of 0 will be used.
 * @param array $b
 *   Second item for comparison.
 *
 * @return int
 *   The comparison result for uasort().
 */
function sort_by_weight_and_name(array $a, array $b) {
  $a_weight = is_array($a) && isset($a['weight']) ? $a['weight'] : 0;
  $b_weight = is_array($b) && isset($b['weight']) ? $b['weight'] : 0;

  if ($a_weight == $b_weight) {
    return ($a['name'] < $b['name'] ? -1 : 1);
  }

  return $a_weight < $b_weight ? -1 : 1;
}
