<?php
/**
 * @file
 * node_exort_from_legal_opinion.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function node_exort_from_legal_opinion_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function node_exort_from_legal_opinion_node_info() {
  $items = array(
    'dlsu_contact' => array(
      'name' => t('DLSU Contact'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'format' => array(
      'name' => t('Format'),
      'base' => 'node_content',
      'description' => t('Legal opinion original format'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'nnhpd_bureau_project' => array(
      'name' => t('NNHPD Bureau/Project'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'opinion' => array(
      'name' => t('Opinion'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'pick_list' => array(
      'name' => t('Pick list'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'priority' => array(
      'name' => t('Priority'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'requester' => array(
      'name' => t('Requester'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'requesting_unit' => array(
      'name' => t('Requesting Unit'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'space' => array(
      'name' => t('Space'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'space_root' => array(
      'name' => t('All Spaces'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'status' => array(
      'name' => t('Status'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
