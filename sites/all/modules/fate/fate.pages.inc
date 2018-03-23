<?php
/**
 * @file
 * Edit functionality for the FATE mdoule.
 */

/**
 * Page callback to edit an entity field.
 */
function fate_field_edit_page($entity_type, $entity, $field_name, $langcode = NULL) {
  // Ensure the entity type is valid:
  if (empty($entity_type)) {
    return MENU_NOT_FOUND;
  }

  $entity_info = entity_get_info($entity_type);
  if (!$entity_info) {
    return MENU_NOT_FOUND;
  }

  if (!isset($langcode)) {
    $langcode = entity_language($entity_type, $entity);
  }

  // Load the subform.
  list($entity_id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);
  $field_instance = field_info_instance($entity_type, $field_name, $bundle);
  $subform_id = 'fate_field_edit_field_form';

  if (empty($field_instance)) {
    return MENU_NOT_FOUND;
  }

  $path = entity_uri($entity_type, $entity);
  $form_state = array(
    'entity_type' => $entity_type,
    'entity' => $entity,
    'field_name' => $field_name,
    'langcode' => $langcode,
    'no_redirect' => TRUE,
    'redirect' => $path['path'],
    'field_instance' => $field_instance,
    'bundle' => $bundle,
    'subform_id' => $subform_id,
  );

  // Set the page title.
  $title = $field_instance['label'];
  if (module_exists('i18n_string')){  
    $name = "field:$field_name:$bundle:label";
    $options=array('langcode'=>$GLOBALS['language']->language);
    $title = i18n_string_translate($name, $title, $options);
  }    
  drupal_set_title(t('Edit <em>@title</em> field', array('@title' => $title)), PASS_THROUGH);  
    
  // Compile the form.
  $output = drupal_build_form('fate_field_edit_form', $form_state);

  // Save the form when it's submitted.
  if (!empty($form_state['executed'])) {
    entity_save($entity_type, $form_state['entity']);
    drupal_goto($form_state['redirect']);
  }

  return $output;
}

/**
 * Field editing form.
 */
function fate_field_edit_form($form, &$form_state) {
  // Since we could edit a number of different things here, immediately
  // add whatever else is needed.
  $form_state['subform_id']($form, $form_state);
  $form['#parents'] = array();

  $entity_type = $form_state['entity_type'];
  $entity = $form_state['entity'];
  $bundle = $form_state['bundle'];

  list($support_revisions, $control_revisions, $default_revisions) = _fate_entity_allows_revisions($entity_type, $bundle);

  if ($support_revisions) {
    $form_state['use revisions'] = TRUE;
    $form['revision_information'] = array(
      '#weight' => 11,
    );

    $form['revision_information']['revision'] = array(
      '#type' => 'checkbox',
      '#title' => t('Create new revision'),
      '#default_value' => $default_revisions,
      '#id' => 'edit-revision',
      '#access' => $control_revisions,
    );

    if ($control_revisions || $default_revisions) {
      $form['revision_information']['log'] = array(
        '#type' => 'textarea',
        '#title' => t('Log message'),
        '#description' => t('Provide an explanation of the changes you are making. This will help other authors understand your motivations.'),
        '#default_value' => $entity->log,
        '#states' => array(
          'visible' => array(
            ':input[name=revision]' => array('checked' => TRUE),
          ),
        ),
      );
    }
  }

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  // Ensure this actually gets on there.
  $form['#submit'][] = 'fate_field_edit_form_submit';

  return $form;
}

/**
 * Subform to edit a field instance.
 *
 * This isn't a true form. As such it modifies the $form by reference.
 */
function fate_field_edit_field_form(&$form, &$form_state) {
  $form['#parents'] = array();

  $entity_type = $form_state['entity_type'];
  $entity = $form_state['entity'];
  $field_name = $form_state['field_name'];
  $field_instance = $form_state['field_instance'];
  $langcode = $form_state['langcode'];
  $bundle = $form_state['bundle'];

  ctools_include('fields');
  // If no language is provided use the default site language.
  $options = array(
    'language' => field_valid_language($langcode),
    'default' => TRUE,
  );

  $form += (array) ctools_field_invoke_field($field_instance, 'form', $entity_type, $entity, $form, $form_state, $options);

  $form['#pre_render'][] = '_field_extra_fields_pre_render';
  $form['#entity_type'] = $entity_type;
  $form['#bundle'] = $bundle;

  // Let other modules make changes to the form.

  // Exclude some modules.
  $excluded_modules = array(
    'field_group',
    'metatag',
    'panelizer',
    'redirect',
  );
  // Avoid module_invoke_all() to let parameters be taken by reference.
  foreach (module_implements('field_attach_form') as $module) {
    if (in_array($module, $excluded_modules)) {
      continue;
    }
    $function = $module . '_field_attach_form';
    $function($entity_type, $entity, $form, $form_state, $langcode);
  }

  $form['#validate'][] = 'fate_field_edit_field_form_validate';
  $form['#submit'][] = 'fate_field_edit_field_form_submit';
}

/**
 * Validate field editing form
 */
function fate_field_edit_field_form_validate($form, &$form_state) {
  ctools_include('fields');

  $entity_type = $form_state['entity_type'];
  $entity = $form_state['entity'];
  $field_name = $form_state['field_name'];
  $field_instance = $form_state['field_instance'];
  $langcode = $form_state['langcode'];

  // Extract field values from submitted values.
  ctools_field_invoke_field_default($field_instance, 'extract_form_values', $entity_type, $entity, $form, $form_state);

  $errors = array();
  // Check generic, field-type-agnostic errors first.
  ctools_field_invoke_field_default($field_instance, 'validate', $entity_type, $entity, $errors);
  // Check field-type specific errors.
  ctools_field_invoke_field($field_instance, 'validate', $entity_type, $entity, $errors);

  // Let other modules validate the entity.
  // Avoid module_invoke_all() to let $errors be taken by reference.
  foreach (module_implements('field_attach_validate') as $module) {
    $function = $module . '_field_attach_validate';
    $function($entity_type, $entity, $errors);
  }

  if ($errors) {
    // Pass field-level validation errors back to widgets for accurate error
    // flagging.
    foreach ($errors as $field_errors) {
      foreach ($field_errors as $langcode => $errors) {
        $field_state = field_form_get_state($form['#parents'], $field_name, $langcode, $form_state);
        $field_state['errors'] = $errors;
        field_form_set_state($form['#parents'], $field_name, $langcode, $form_state, $field_state);
      }
    }
    ctools_field_invoke_field_default($field_instance, 'form_errors', $entity_type, $entity, $form, $form_state);
  }
}

/**
 * Submit field editing form
 */
function fate_field_edit_field_form_submit($form, &$form_state) {
  $entity_type = $form_state['entity_type'];
  $entity = $form_state['entity'];
  $field_name = $form_state['field_name'];
  $field_instance = $form_state['field_instance'];
  $langcode = $form_state['langcode'];

  // Extract field values from submitted values.
  ctools_field_invoke_field_default($field_instance, 'extract_form_values', $entity_type, $entity, $form, $form_state);

  ctools_field_invoke_field_default($field_instance, 'submit', $entity_type, $entity, $form, $form_state);

  // Let other modules act on submitting the entity.
  // Avoid module_invoke_all() to let $form_state be taken by reference.
  foreach (module_implements('field_attach_submit') as $module) {
    $function = $module . '_field_attach_submit';
    $function($entity_type, $entity, $form, $form_state);
  }
}

/**
 * General submit callback. Simply handles the revision.
 */
function fate_field_edit_form_submit($form, &$form_state) {
  $entity = $form_state['entity'];
  if (!empty($form_state['use revisions'])) {
    $entity->revision = $form_state['values']['revision'];
    $entity->log = '';
    if (isset($form_state['values']['log'])) {
      $entity->log = $form_state['values']['log'];
    }
  }
}

/**
 * Determine if an entity uses revisions.
 *
 * @param string $entity_type
 * @param string $bundle
 *
 * @return
 *   An array where the first item is whether revisions are supported by this
 *   entity bundle, the second item is whether the current user has permission
 *   to control whether or not revisions are created, the third whether a new
 *   revision is created by default.
 *
 *   Much of this is specific to entity types, so entities that are not nodes
 *   that support revisions may not handle this quite correctly without help.
 */
function _fate_entity_allows_revisions($entity_type, $bundle) {
  $retval = array(FALSE, FALSE, FALSE);

  switch ($entity_type) {
    case 'node':
      $node_options = variable_get('node_options_' . $bundle, array('status', 'promote'));
      $retval[0] = TRUE;
      $retval[1] = user_access('administer nodes');
      $retval[2] = in_array('revision', $node_options);
      break;

    default:
      $entity_info = entity_get_info($entity_type);
      $retval[0] = !empty($entity_info['revision table']);
      break;
  }

  // Trigger hook_fate_entity_allow_revisions().
  drupal_alter('fate_entity_allow_revisions', $retval, $entity_type, $bundle);

  return $retval;
}
