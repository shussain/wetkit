<?php


//***  * The admin panel * ***
global $fields_additional_detail;
global $fields_restriction;
global $fields_no_limit;
$fields_additional_detail = array('field_additional_detail_e', 'field_additional_detail_f');
$fields_restriction = array('field_restriction_desc_e', 'field_restriction_desc_f');
$fields_no_limit = array('field_old_rationale');

/***
 * Field allowed length setting
 */   

function nhpid_field_length_limit_form($form, &$form_state=NULL) {
  global $fields_additional_detail;
  global $fields_restriction;
  global $fields_no_limit;
  $table_name=NHPID_FILED_LENGTH_LIMIT_TABLE;
  $default_limit_general = variable_get('nhpid_field_length_limit_default_general', 200);
  $default_limit_additional_detail = variable_get('nhpid_field_length_limit_default_additional_detail', 1000);
  $default_limit_restriction = variable_get('nhpid_field_length_limit_default_restriction', 2000);
  $default_no_limit = -1;
  $fields_not_checked=array('field_legacy_nid'=>array(),'field_parent_space'=>array(),'field_workflow'=>array());
  $trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
  $form['#tree']=true;
	$trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
  $form['help'] = array(
    '#type' => 'item',
    '#markup' => t("This setting defines the max allowed length of fields. Default values is $default_limit_additional_detail for <em>" . implode(', ', $fields_additional_detail) ."</em>, $default_limit_restriction for <em>" . implode(', ', $fields_restriction) ."</em>, no limit for <em>" . implode(', ', $fields_no_limit) . "</em>, $default_limit_general for others." ),
  );
  $form['data_storage'] = array(
    '#type' => 'item',
    '#markup' => t('This settings is stored in the database table <em>!table</em>.', array('!table'=>$table_name)),
   );

  $types = get_all_nhpid_data_node_types();
  //$types = array_slice($types, 0, 1);
  $form['node_types']=array(
		'#type' => 'value',
		'#value' => $types,
  );
  foreach ($types as $node_type => $node_name) {
		$fields = get_node_type_field_name_title_mapping($node_type);
		$fields = array_diff_key($fields,$fields_not_checked);
		$form[$node_type] = array(
			'#title' => $node_name,
			'#type' => 'fieldset',
			'#theme' => 'nhpid_field_length_limit_form_wrapper',
			//'#theme_wrappers' => array('nhpid_field_length_limit_form_wrapper'),			
			'#collapsible' => TRUE, 
			'#collapsed' => True,
		);

		$sql = db_select($table_name, 'x')
				->fields('x', array('field_name', 'node_type','length_limit'))
				->condition('node_type', $node_type)
				->orderBy('field_name')
				->execute();
		$data = $sql ->fetchAllAssoc('field_name');

		foreach ($fields as $key => $name) {
			$default=null;
			if (in_array($key, $fields_additional_detail)) {
			$default = $default_limit_additional_detail;
			}
			else if (in_array($key, $fields_restriction)) {
				$default = $default_limit_restriction;
			}
			else if(in_array($key, $fields_no_limit)) {
				$default = $default_no_limit;
			}
			else {
				$default = $default_limit_general;
			}
			$limit = isset($data[$key]->length_limit)? $data[$key]->length_limit:$default;
			$form[$node_type][$key] = array(
			  '#type' => 'textfield', 
			  //'#title' => "$name", 
			  '#default_value' => $limit,
			  '#maxlength' => 5,
			  '#size' => 5,
			);
		}
    }
  
  $form['submit'] = array(
  '#type' => 'submit',
  '#value' => t('Save Field Length Limit Field Setting')
  );
  
  $form['restore-default'] = array(
  '#type' => 'submit',
  '#value' => t('Restore Default'),
  '#attributes' => array('onclick' => 'return confirm("Danger!!! This will reset to default setting.");'),
  );
  $form['defaults'] = array(
    '#title' => "Field Length Limit Default",
    '#type' => 'fieldset', 
    '#collapsible' => TRUE, 
    '#collapsed' => True,
  );
  $form['defaults']['default_general'] = array(
    '#type' => 'textfield', 
    '#title' => "New general default", 
    '#default_value' => $default_limit_general,
    '#maxlength' => 5,
    '#size' => 5,
  );
  $form['defaults']['default_additional_detail'] = array(
    '#type' => 'textfield', 
    '#title' => "New default for fields <em>" . implode(', ', $fields_additional_detail) .'</em>', 
    '#default_value' => $default_limit_additional_detail,
    '#maxlength' => 5,
    '#size' => 5,
  );
  $form['defaults']['default_restriction'] = array(
    '#type' => 'textfield', 
    '#title' => "New default for fields <em>" . implode(', ', $fields_restriction) .'</em>', 
    '#default_value' => $default_limit_restriction,
    '#maxlength' => 5,
    '#size' => 5,
  );
  //drupal_set_message(nhpid_api_dump($form, 'red', TRUE));
  //dpm($form);
  return $form;  
}

function nhpid_field_length_limit_form_submit($form, &$form_state) {
  //dpm($form_state['values']);
  global $fields_additional_detail;
  global $fields_restriction;
  global $fields_no_limit;
  $node_types = $form_state['values']['node_types'];
  
  //$form_state['storage']['values'] = $form_state['values'];
  if ($form_state['values']['defaults']['default_general']) {
    variable_set('nhpid_field_length_limit_default_general', $form_state['values']['defaults']['default_general']);
  }
   if ($form_state['values']['defaults']['default_additional_detail']) {
    variable_set('nhpid_field_length_limit_default_additional_detail', $form_state['values']['defaults']['default_additional_detail']);
  }
   if ($form_state['values']['defaults']['default_restriction']) {
    variable_set('nhpid_field_length_limit_default_restriction', $form_state['values']['defaults']['default_restriction']);
  }
	$operations = array();
  	foreach ($node_types as $node_type => $node_name) {
		foreach ($form_state['values'][$node_type] as $field_name => $limit) {
			if($form_state['clicked_button']['#id'] == 'edit-restore-default'){
				$default=null;
				if (in_array($field_name, $fields_additional_detail)) {
					$default = $form_state['values']['defaults']['default_additional_detail'];
				}
				else if (in_array($field_name, $fields_restriction)) {
					$default = $form_state['values']['defaults']['default_restriction'];
				}
				else if(in_array($field_name, $fields_no_limit)) {
					$default = -1;
				}
				else {
					$default = $form_state['values']['defaults']['default_general'];
				}
				$limit=$default;
			}
			$item=array('node_type'=>$node_type, 'field_name'=>$field_name, 'limit'=>$limit);
			$operations[] = array('_nhpid_reset_field_length_limit', array($item));
		}
	}
	
	
	$batch = array(
	  'operations' => $operations,
	  'finished' => 'batch_re_gnerate_title_body_finished',
	  // We can define custom messages instead of the default ones.
	  'title' => t('Reset field length limit...'),
	  'init_message' => t('Starting.'),
	  'progress_message' => t('Processed @current out of @total items.'),
	  'error_message' => t('Resetting field length has encountered an error.'),
	  'file' => drupal_get_path('module', 'nhpid'). '/nhpid_forms.inc',
	);

	batch_set($batch);
	batch_process();
}
/***
 * Field allowed requiredness setting
 */ 
function nhpid_required_field_form($form, &$form_state=NULL) {
	$form['#tree']=true;
	$trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
	$form['help'] = array(
		'#type' => 'item',
		'#markup' => t('This setting defines required NHPID data node fields. Default values are values of the required attribute of global settings of cck fields. Since NHPID node types share cck fields, only fields which are required by all sharing node types are set to required globally.' ),
	);
	$form['data_storage'] = array(
    '#type' => 'item',
    '#markup' => t('This settings reset the required field of field instance directly'),
   );

  $types = get_all_nhpid_data_node_types();
	$form['node_types']=array(
		'#type' => 'value',
		'#value' => $types,
	);
  foreach ($types as $node_type => $node_name) {
    $fields = get_node_type_field_name_title_mapping($node_type);
		$instances = field_info_instances('node', $node_type);
      $form[$node_type] = array(
        '#title' => $node_name,
        '#type' => 'fieldset', 
        '#collapsible' => TRUE, 
        '#collapsed' => True,
      );
      foreach ($fields as $key => $name) {
        $instance = $instances[$key];
        //drupal_set_message(nhpid_api_dump($instance , 'blue', TRUE));
				$default = $instance['required'];
        $form[$node_type][$key] = array(
          '#type' => 'checkbox', 
          '#title' => "$name", 
          '#default_value' => $default,
          '#attributes' => array('var' => array('node_type' => $node_type, 'field' => $key)),
        );
      }
    }
    
  $form['submit'] = array(
  '#type' => 'submit',
  '#value' => t('Save Required Field Setting')
  );

  return $form;  
}

function nhpid_required_field_form_submit($form, &$form_state) {
	//dpm($form_state['values']);
	$node_types = $form_state['values']['node_types'];
  if ($form_state['clicked_button']['#id'] == 'edit-submit') {
    //node_types_rebuild();
    foreach ($node_types as $node_type => $label) {
		foreach($form_state['values'][$node_type] as $field_name => $value){
			$instance = field_info_instance('node', $field_name, $node_type);
			if ($instance['required'] != $value){
				$instance['required'] = $value;
				field_update_instance($instance);
			}
		}
	}
  }
}
/***
 * Field conditionally requiredness setting
 */ 
function nhpid_conditionally_required_field_form($form, &$form_state=NULL) {
  $allowed_field_types = array('text', 'list_text', 'text_long', 'number_decimal', 'number_integer', 'number_float',  'date', 'datestamp', 'datetime', 'flexifield', 'link', 'entityreference' ); ## must be in lower case
  $trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
	$form['help'] = array(
    '#type' => 'item',
    '#markup' => t('This setting defines conditionally required NHPID data node fields. Conditionally required fields are fields which reuiredness is depended on other fields.' ),
  );
  $form['data_storage'] = array(
    '#type' => 'item',
	'#markup' => t('This settings is stored in variable <em>nhpid_[node_type]_is_conditionally_required </em>.' ),
   );

  $types = get_all_nhpid_data_node_types();
  foreach ($types as $node_type => $node_name) {
    $type_fields = get_node_type_field_name_title_mapping($node_type, NULL, TRUE);
    $allowed_fields = array();
    $header = array('Field Name', 'Field Label', 'Field Name', 'Field Label');
    $rows = array();
    $row = array();
    $new_line = true;
    foreach($type_fields as $type_field => $label){
      $field_info = field_info_field($type_field);
      if (in_array(strtolower ($field_info['type']), $allowed_field_types)){
        $allowed_fields[] = $type_field;
        if ($new_line){
          $row=array($type_field, $label);
        }
        else{
          $row = array_merge($row, array($type_field, $label));
          $rows[]=$row;
        }
        
        $new_line = !$new_line;
      }
    }
    if(!$new_line) $rows[] = $row;
   
    $form[$node_type] = array(
      '#title' => $node_name,
      '#type' => 'fieldset', 
      '#collapsible' => TRUE, 
      '#collapsed' => True,
    );
    $form[$node_type]['fields'] = array(
      '#title' => 'Available fields (only field types: ' . implode(', ', $allowed_field_types) . ')',
      '#type' => 'item', 
      '#markup' => theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => Null, 'caption' => Null,'colgroups' => Null,'sticky' => True,'empty' => '',)),
    );
    $required = "nhpid_" . $node_type  . "_is_conditionally_required";
    $default = variable_get($required, '');
    $form[$node_type][$required] = array(
      '#title' => 'Conditionally required fields',
      '#type' => 'textarea', 
      '#default_value' => $default,
      '#description' => "Enclode each rule in '{}'. The basic format of a rule is {rule=>check_multi_value}. <br>A rule is a formula containing field names and logical operators '&', '^',  or '|'. '&' indicates that items on both sides are require. '|' indicates at least one item is required. '^' indicates either item, only one item is required. Enclose sub-group in '()'. 
                        <br> Flag check_multi_value (either TRUE or FALSE, default is FALSE) indicates that the validation should check the rule by comparing whole fields (FALSE) or by comparing each value of fields (TRUE).  
                        <p> For example, '{field_1&(field_2|field_3)=>FALSE}' indicated that field_1 and either field_2 or field_3 or both must be filled, or all fields must be empty. Whole fields will be compared. <p> '{field_1&(field_2^field_3)=>TRUE}' indicates that field_1 and either field_2 or field_3 must be filled, or all fields must be empty. Each value of fields will be compared.",
    );
    $form[$node_type]["$node_type" . "_allowed_fields"] = array(
      '#type' => 'value',
      '#value' => $allowed_fields,
    );
  }
  
  $form['submit'] = array(
  '#type' => 'submit',
  '#value' => t('Save Conditionally Required Field Setting')
  
  );
  $form['#validate'][] ='nhpid_conditionally_required_field_form_validate';
  
  
  return $form;  
}
function nhpid_conditionally_required_field_form_validate($form, &$form_state) {
  //$form_state['values'] = $form_state['values'];
  
  if ($form_state['clicked_button']['#id'] == 'edit-submit'){
    foreach ($form_state['values'] as $key => $value) {
      if (stristr($key, '_is_conditionally_required') and $value) {
        $node_type = str_replace('_is_conditionally_required', '', $key);
        $node_type = str_replace('nhpid_', '', $node_type);
        ## remove spaces
        $value = str_replace(' ', '', $value);
        $value = trim($value);
        ##format checking
        if ($value[0] != '{'){
          drupal_set_message("Format of node type $node_type is not correct. Most left { is missing.", 'error');
        }
        if ($value[strlen($value)-1] != '}'){
          drupal_set_message("Format of node type $node_type is not correct. Most right { is missing.", 'error');
        }
        if (substr_count($value, '}') != substr_count($value, '{')){
          drupal_set_message("Format of node type $node_type is not correct. The counts of { and } are not equal.", 'error');
        }
        if (substr_count($value, ')') != substr_count($value, '(')){
          drupal_set_message("Format of node type $node_type is not correct. The counts of ( and ) are not equal.", 'error');
        }
        
        $type_fields = get_node_type_field_name_title_mapping($node_type);
        $allowed_fields = $form_state['values']["$node_type" . "_allowed_fields"];
       
        //drupal_set_message(nhpid_api_dump($allowed_fields , 'red', TRUE));
        //drupal_set_message(nhpid_api_dump($node_type , 'red', TRUE));
        $pattern = '/field_\w*/';
        $fields = array();
        preg_match_all($pattern,$value,$fields);
        foreach ($fields[0] as $field){
          if ($field and !in_array($field, $allowed_fields)){
            form_set_error($key, "Field $field of node type " . $node_type . " is not a valid field.");
          }
        }
        
      }
    }
  }
  
}

function nhpid_conditionally_required_field_form_submit($form, &$form_state) {
  //$form_state['storage']['values'] = $form_state['values'];
  foreach ($form_state['storage']['values'] as $key => $value) {
    if (stristr($key, '_is_conditionally_required')) {
      if ($form_state['clicked_button']['#id'] == 'edit-submit') {
        ## remove spaces
        $value = str_replace(' ', '', $value);
        $value = trim($value);
        variable_set($key, $value);
      }
    } 
  }
}
/***
 * Unique node and node field setting
 */ 
function nhpid_unique_node_field_form($form, &$form_state=NULL) {
  $variable_name='nhpid_unique_node_types';
  $trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
  $form['help'] = array(
    '#type' => 'item',
    '#markup' => t('This setting defines unique NHPID data node types and unique fields.  <br> Unique node types do not accept duplicated nodes with the same "title" or with the same value of any of unique fields.' ),
  );
  $form['data_storage'] = array(
		'#type' => 'item',
		'#markup' => t('This settings is stored in the variable <em>!variable_name</em>.', array('!variable_name' => $variable_name)),
  );
  
  $defaults_pattern = array("code_.+", );
  
  $node_types = get_all_nhpid_data_node_types();
  $default_types = array();
  foreach ($node_types as $type => $name) {
    foreach ($defaults_pattern as $pattern) {
      $pattern = "/^$pattern/";
      $default_types[$type] = 0;
      if (preg_match($pattern, $type)) {
        $default_types[$type] = $type;
        break;
      }
    }
  }
  //drupal_set_message(nhpid_api_dump($default_types, 'red', TRUE));
  $components = variable_get($variable_name, $default_types);
  $form['nhpid_unique_node'] = array(
    '#type' => 'fieldset',
    '#title' => t('NHPID unique node types'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['nhpid_unique_node']['nhpid_unique_node_types'] = array(
    '#type' => 'checkboxes', 
    //'#title' => 'NHPID unique node types',
    '#options' => $node_types,
    '#default_value' => $components,
    '#required' => FALSE,
    '#description' => t('Check if the node type is a unique NHPID data node type.'),
  );
  $form['nhpid_unique_node']['default_type'] = array(
    '#type' => 'hidden',
    '#value' => serialize($default_types),
  );
  $form['nhpid_unique_node']['submit_type'] = array(
    '#type' => 'submit',
    '#value' => t('Save setting')
  );
  $form['nhpid_unique_node']['restore_default_type'] = array(
    '#type' => 'submit',
    '#value' => t('Restore default')
  );
  
  $form['nhpid_unique_field'] = array(
    '#type' => 'fieldset',
    '#title' => t('NHPID unique node fields'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $defaults_fields = array("field_code" => "field_code", "field_ingredient_name" => "field_ingredient_name", "field_name_e" => "field_name_e" , "field_name_f" => "field_name_f", );
  foreach ($node_types as $type => $name) {
    if (nhpid_is_a_unique_node_type($type)) {
      $fields = get_node_type_field_name_title_mapping($type); 
      $unique_field_id = "nhpid_$type" . '_unique_fields';
      $form['nhpid_unique_field'][$type] = array(
        '#type' => 'fieldset',
        '#title' => t($name),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form['nhpid_unique_field'][$type][$unique_field_id] = array(
        '#type' => 'checkboxes', 
        //'#title' => 'NHPID unique node types',
        '#options' => $fields,
        '#default_value' => variable_get($unique_field_id, $defaults_fields),
        '#required' => FALSE,
        '#description' => t('Check if the node field is a NHPID unique field. <br> Save unique node types first before setting unique fields.'),
      );
    }
  }
  $form['nhpid_unique_field']['submit_field'] = array(
    '#type' => 'submit',
    '#value' => t('Save setting')
  );
  
  return $form;
}
function nhpid_unique_node_field_form_submit($form, &$form_state) {
  //drupal_set_message(nhpid_api_dump($form, 'red', TRUE));
  if ($form_state['clicked_button']['#id'] == 'edit-restore-default-type') {
    $value_type = unserialize($form_state['values']['default_type']);
  }
  else {
    $value_type = $form_state['values']['nhpid_unique_node_types'];
  }
  variable_set("nhpid_unique_node_types", $value_type);
  foreach ($form_state['values'] as $id => $field_value) {
  
  }
  foreach ($value_type as $type => $setting) {
    $unique_field_id =  "nhpid_$type" . '_unique_fields';
    variable_set($unique_field_id, $form_state['values'][$unique_field_id]);
  }
  //variable_set("nhpid_unique_node_type", $form_state['values']['nhpid_unique_node_type']);
  //variable_set("nhpid_unique_nhpid_fields", $form_state['values']['nhpid_unique_nhpid_fields']);
  $form_state['storage']['values'] = $form_state['values'];
}


/***
 * NHPID data node  setting
 */ 
function nhpid_data_node_type_form($form, &$form_state=NULL) {
    $variable_name_all='nhpid_data_node_types';
	$variable_name_mono='nhpid_monograph_data_node_types';
	$variable_name_ing='nhpid_ingredient_data_node_types';
	$trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
	$form['help'] = array(
    '#type' => 'item',
    '#markup' => t('This setting defines node types storing NHPID data.' ),
	);
	$form['data_storage'] = array(
		'#type' => 'item',
		'#markup' => t('This settings is stored in the variable <em>!variable_name_all and !variable_name_mono and !variable_name_ing</em>.', array('!variable_name_all' => $variable_name_all,'!variable_name_mono' => $variable_name_mono,'!variable_name_ing' => $variable_name_ing)),
    );
  $defaults_pattern = array("als_.+", "brals_.+", "homeopathic_.+", "herbal_.+", "code_.+", "mono_.+", "naming_.+", "nonnhp_.+", "mi_.+", "nmi_.+", "subing_.+");

  $node_types = array();
  $default_types = array();
  $node_objs = node_type_get_types();
  foreach ($node_objs as $type => $obj) {
    $node_types[$type] = $obj -> name . " ($type)";
    foreach ($defaults_pattern as $pattern) {
      $pattern = "/^$pattern/";
      $default_types[$type] = 0;
      if (preg_match($pattern, $type)) {
        $default_types[$type] = $type;
        break;
      }
    }
  }
  //drupal_set_message(nhpid_api_dump($default_types, 'red', TRUE));
  $components = variable_get($variable_name_all, $default_types);
  $form['nhpid_content'] = array(
    '#type' => 'fieldset',
    '#title' => 'ALL NHPID Data Node Types',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['nhpid_content']['nhpid_data_node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => 'NHPID data node types',
    '#options' => $node_types,
    '#default_value' => $components,
    '#required' => FALSE,
    '#description' => t('Check if the node type is a NHPID data node type.'),
  );
  $form['nhpid_monograph_content'] = array(
    '#type' => 'fieldset',
    '#title' => 'NHPID Monograph Data Node Types',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $components = variable_get($variable_name_mono, array());
  $form['nhpid_monograph_content']['nhpid_monograph_data_node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => 'Monograph data node types',
    '#options' => $node_types,
    '#default_value' => $components,
    '#required' => FALSE,
    '#description' => t('Check if the node type is a monograph data node type.'),
  );
  $form['nhpid_ingredient_content'] = array(
    '#type' => 'fieldset',
    '#title' => 'NHPID Ingredient Data Node Types',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $components = variable_get($variable_name_ing, array());
  $form['nhpid_ingredient_content']['nhpid_ingredient_data_node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => 'Ingredient data node types',
    '#options' => $node_types,
    '#default_value' => $components,
    '#required' => FALSE,
    '#description' => t('Check if the node type is a ingredient data node type.'),
  );
  $form['default'] = array(
    '#type' => 'hidden',
    '#value' => serialize($default_types),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save setting')
  );
  $form['restore_default'] = array(
    '#type' => 'submit',
    '#value' => t('Restore default')
  );
  //drupal_set_message(nhpid_api_dump($form, 'red', TRUE));
  return $form;
}
function nhpid_data_node_type_form_submit($form, &$form_state) {
  $value = null;
  // nhpid data node types
  if ($form_state['clicked_button']['#id'] == 'edit-restore-default') {
    $value = unserialize($form_state['values']['default']);
  }
  else {
    $value = $form_state['values']['nhpid_data_node_types'];
  }
  variable_set("nhpid_data_node_types", $value);
  // nhpid monograph data node sub-types
  $value = $form_state['values']['nhpid_monograph_data_node_types'];
  variable_set("nhpid_monograph_data_node_types", $value);
  $value = $form_state['values']['nhpid_ingredient_data_node_types'];
  variable_set("nhpid_ingredient_data_node_types", $value);
  $form_state['storage']['values'] = $form_state['values'];

}


/***
 * NHPID ITS link url setting
 */ 
function nhpid_its_url_form($form, &$form_state=NULL) {
  $variable_name='nhpid_its_url';
  $trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
  $form['help'] = array(
    '#type' => 'item',
    '#markup' => t('Drupal NHPID links NHPID ITS issues to NHPID data records. This setting defines the base URL of the NHPID ITS issue page and updates all existing ITS ids. <br>'),
  );
  $form['data_storage'] = array(
		'#type' => 'item',
		'#markup' => t('This settings is stored in the variable <em>!variable_name</em>.', array('!variable_name' => $variable_name)),
  );
  $components = variable_get($variable_name, '');
  $form['nhpid_its_url'] = array(
    '#type' => 'textfield',
    '#title' => t('NHPID ITS URL'),
    '#default_value' => $components,
    '#maxwidth' => 20,
    '#required' => TRUE,
    '#description' => t("Enter the NHPID ITS base url (replace the issue id with '#'), such as https://nnhprd.hres.ca/its/node/#."),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save ITS URL')
  );
  return $form;
}
function nhpid_its_url_form_submit($form, &$form_state) {
  $new_url = $form_state['values']['nhpid_its_url'];
  $sql = "update {field_data_field_its_ids} set field_its_ids_url=replace(:new_url, '#', field_its_ids_title)";
  db_query($sql, array(':new_url' => $new_url));
  drupal_flush_all_caches();

  variable_set("nhpid_its_url", $new_url);
}

/***
 * Auto title and auto body message setting
 */ 
function nhpid_auto_title_form($form, $form_state=NULL) {

  $form['#theme'] = 'nhpid_auto_title_form';
  $form['#tree'] = TRUE;
  $trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
  $form['help'] = array(
    '#type' => 'item',
    '#markup' => t('Drupal NHPID can automatically fill the title and body fields of newly created or modified nodes. This setting defines which fields will be used as values of the title and body fields of the node type.'),
  );

  $default_types = array();
  foreach ($types as $type => $value) {
    $default_types[$type] = $type;
  }
  
  //drupal_set_message(nhpid_api_dump($form_state, 'red', TRUE));
  //drupal_set_message(nhpid_api_dump($default_types, 'green', TRUE));
  $selected_node_types = !empty($form_state['values']['re-generate-title-body']['node_types']) ? $form_state['values']['re-generate-title-body']['node_types'] : array();
  if ($selected_node_types == 'all') $selected_node_types = $default_types;
  if ($selected_node_types == 'none') $selected_node_types = array();
  //drupal_set_message(nhpid_api_dump($selected_node_types, 'green', TRUE));
  $form['re-generate-title-body'] = array(
    '#type' => 'fieldset',
    '#title' => 'Regenerate Title and Body',
    '#collapsible' => TRUE,
    //'#collapsed' => isset($form_state['clicked_button']) and ($form_state['clicked_button']['#id'] == 'edit-re-generate-title-body-uncheck-all' or $form_state['clicked_button']['#id'] == 'edit-re-generate-title-body-check-all'),
    '#collapsed' => true,
	);

  $ntype_header=array('type'=>"Node Type");
  $form['re-generate-title-body']['node_types'] = array(
    '#type' => 'tableselect',
    '#header' => $ntype_header,
    '#js_select' => TRUE,
    '#title' => t('Select Node types'),
    '#options' => $table_select_types,
    '#default_value' => $selected_node_types,
    '#required' => false,
    '#description' => t('Select one or more node types'),
  );
  $form['re-generate-title-body']['re-gnerate'] = array(
  '#type' => 'submit',
  '#value' => t('Re-generate title and body'),
  '#attributes' => array('onclick' => 'return confirm("Danger!!! This will reset the title and body of all nodes.");'),
  );
  $form['#validate'][] = 'nhpid_auto_title_form_validate';
  return $form;
}

function nhpid_auto_title_form_validate($form, &$form_state) {
  //drupal_set_message(nhpid_api_dump($form_state['values'], 'red', TRUE));
}
function nhpid_auto_title_form_submit(&$form, &$form_state) {
  //drupal_set_message(nhpid_api_dump($form_state, 'red', TRUE));
  switch ($form_state['clicked_button']['#id']) {
  
  case 'edit-re-generate-title-body-uncheck-all':
        $form_state['values']['re-generate-title-body']['node_types'] = 'none';
        break;
  case 'edit-re-generate-title-body-check-all':
        $form_state['values']['re-generate-title-body']['node_types'] = 'all';
        break;
  case 'edit-re-generate-title-body-re-gnerate':
    $operations = array();
    foreach ($form_state['values']['re-generate-title-body']['node_types'] as $key => $node_type) {
      if ($node_type) $operations[] = array('re_generate_title_body', array($node_type));
      //break;
    }
    //drupal_set_message(nhpid_api_dump($operations, 'red', TRUE));
    $batch = array(
      'operations' => $operations,
      'finished' => 'batch_re_gnerate_title_body_finished',
      // We can define custom messages instead of the default ones.
      'title' => t('Re-generating node title and body...'),
      'init_message' => t('Starting.'),
      'progress_message' => t('Processed @current out of @total node types.'),
      'error_message' => t('Title and body re-generation has encountered an error.'),
      'file' => drupal_get_path('module', 'nhpid'). '/nhpid_forms.inc',
    );

    
    batch_set($batch);
    batch_process();
  break;  
  }
  $form_state['storage']['values'] = $form_state['values'];
}

function _nhpid_re_generate_title_body($node_type, &$context) {
  $sql = "SELECT nid FROM {node} WHERE type=:type order by nid desc";
  $result = db_query($sql, array(':type' => $node_type));
  $sql_count = "SELECT count(nid) FROM {node} WHERE type=:type order by nid desc";
  $count = db_query($sql_count, array(':type' => $node_type))->fetchColumn(0);
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = $count;
  }
  foreach ($result as $row) {
    $node = node_load($row->nid);
    node_save($node);
    $context['results'][] = $node->nid . ' : ' . check_plain($node->title);
    $context['sandbox']['progress']++;
    $context['sandbox']['current_node'] = $node->nid;
    $context['message'] = check_plain("$node_type: $count nodes");

  }
   if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    //$context['finished'] = ($context['sandbox']['progress'] >= $context['sandbox']['max']);
  }


}
function _nhpid_reset_field_length_limit($limit, &$context) {
	$table_name=NHPID_FILED_LENGTH_LIMIT_TABLE;
	$count=count($limit);
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = $count;
  }

	$node_type=$limit['node_type'];
	$field_name=$limit['field_name'];
	$length_limit=$limit['limit'];
	db_merge($table_name)
	->key(array('field_name' => $field_name, 'node_type' => $node_type))
	->fields(array(
		  'field_name' => $field_name, 
		  'node_type' => $node_type,
		  'length_limit' => $length_limit,
	))
	->execute();

    $context['results'][] = "$node_type : $field_name";
    $context['sandbox']['progress']++;
    $context['message'] = "$node_type : $field_name is done.";


   if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    //$context['finished'] = ($context['sandbox']['progress'] >= $context['sandbox']['max']);
  }
}
function _nhpid_map_excel_column($item, $table_name, &$context) {
	$count=count($item);
	if (!isset($context['sandbox']['progress'])) {
	$context['sandbox']['progress'] = 0;
	$context['sandbox']['current_node'] = 0;
	$context['sandbox']['max'] = $count;
	}

	$node_type=$item['node_type'];
	$excel_field_name=$item['excel_field_name'] ? $item['excel_field_name'] : 'ND';
	$drupal_field_name=$item['drupal_field_name'];
	$col_order=$item['col_order']!==null ? $item['col_order'] : 100;
	$mapping_field_name=$item['drupal_field_name'];
	
	db_merge($table_name)
		->key(array('drupal_field_name' => $drupal_field_name, 'node_type' => $node_type))
		->fields(array(
			  'drupal_field_name' => $drupal_field_name, 
			  'node_type' => $node_type,
			  'excel_field_name' => $excel_field_name,
			  'mapping_field_name' => $drupal_field_name,
			  'col_order' => $col_order,
		))
		->execute();
		  

    $context['results'][] = "$node_type : $excel_field_name";
    $context['sandbox']['progress']++;
    $context['message'] = "$node_type : $excel_field_name is done.";


   if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    //$context['finished'] = ($context['sandbox']['progress'] >= $context['sandbox']['max']);
  }
}

function batch_re_gnerate_title_body_finished($success, $results, $operations) {
  if ($success) {
    // Here we could do something meaningful with the results.
    // We just display the number of nodes we processed...
    $message = count($results) . ' processed.';
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = 'An error occurred while processing ' . $error_operation[0] . ' with arguments :' . print_r($error_operation[0], TRUE);
  }
  drupal_set_message($message);
	cache_clear_all();
}
/***
 * Field dependency setting
 */ 
function nhpid_field_dependency_form($form, &$form_state=NULL) {
	$all_nhpid_types = get_all_nhpid_data_node_types();
	$referring_nhpid_types =$all_nhpid_types;
	$all_referring_fields = array();
	$all_possible_referred_fields = field_info_field_map();
	$variable_name='nhpid_entityreference_fields_settings';
	$settings=variable_get($variable_name, null);
	foreach($all_possible_referred_fields as $field_name => $data){
		if ($data['type'] != 'entityreference'){
			continue;
		}
		if ($field_name =='field_parent_space'){
			continue;
		}

		if (isset($data['bundles']['field_collection_item'])){
			//dpm($data);
			foreach($data['bundles']['field_collection_item'] as $item){
				if (strpos($item, 'field_fc_')===0){
					$instances = field_info_instances('field_collection_item',$item);
					//dpm($instances);
					foreach ($instances as $fc_field_name => $intance){
						$field=field_info_field($fc_field_name);
						//dpm($field);
						if ($field['module'] != 'entityreference'){
							continue;
						}
						$all_referring_fields[$fc_field_name]=$fc_field_name;
					}
					
				}
					
			}
		}
		if (isset($data['bundles']['node'])){
			foreach($data['bundles']['node'] as $bundle){
				if (isset($all_nhpid_types[$bundle])){
					$all_referring_fields[$field_name]=$field_name;
				}
					
			}
		}
		
	}
	ksort($all_referring_fields);
	$form['#tree'] = TRUE;
	$trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
	  $form['help'] = array(
		'#type' => 'item',
		'#markup' => t("This setting defines settings used by entityreference fields. " ),
	  );
	  $form['data_storage'] = array(
		'#type' => 'item',
		'#markup' => t('This settings is stored in the variable <em>!variable_name</em>.', array('!variable_name' => $variable_name)),
	  );
	  $form['nhpid_entityreference_referred_fields'] = array(
		'#type' => 'fieldset',
		'#title' => t('Entity Reference field referring fields'),
		'#collapsible' => TRUE,
		'#collapsed' => False,
	  );

	foreach($all_referring_fields as $referring_field => $referring_field_name){
		$field_info = field_info_field($referring_field);
		$form['nhpid_entityreference_referred_fields'][$referring_field] = array(
			'#type' => 'fieldset',
			'#title' => $referring_field_name,
			'#theme' => 'nhpid_referred_field_form_wrapper',
			'#collapsible' => TRUE,
			'#collapsed' => true,
		);
		$referred_types = array();
		if ($field_info['settings']['handler'] == 'base'){
			foreach($field_info['settings']['handler_settings']['target_bundles'] as $type => $val){
				$node_type_names = node_type_get_names();
				$referred_types[$type] = $node_type_names[$type] . ' (' . $type . ')';
			}
		}
		if ($field_info['settings']['handler'] == 'views'){
			$view_name=$field_info['settings']['handler_settings']['view']['view_name'];
			$display_name=$field_info['settings']['handler_settings']['view']['display_name'];
			$view = views_get_view($view_name);
			$filter_name= 'type';
			$display = $view->display[$display_name];
			foreach($display->display_options['filters'][$filter_name]['value'] as $type => $val){
				$node_type_names = node_type_get_names();
				$referred_types[$type] = $node_type_names[$type] . ' (' . $type . ')';
			}
		}
		
		foreach($referred_types as $referred_type=>$referred_type_name){
		
			$refered_type_fields = array();
			foreach(get_all_fields_of_node_type($referred_type) as $refered_field_name => $info){
				$refered_type_fields[$refered_field_name]=$info['label'];
			}
			$referred_fields=isset($settings[$referring_field][$referred_type])? $settings[$referring_field][$referred_type] : array();
			//$referred_fields = empty($form_state['values']['nhpid_entityreference_referred_fields'][$referring_field]['field'])? array():$form_state['values']['nhpid_entityreference_referred_fields'][$referring_field]['field'];
			
			$form['nhpid_entityreference_referred_fields'][$referring_field][$referred_type] = array(
				'#type' => 'select',
				'#title' => t($referred_type_name),
				'#options' => $refered_type_fields,
				'#default_value' => $referred_fields,
			);
		}
	}
	$form['nhpid_entityreference_referred_fields']['all_referring_fields']=array(
		'#type' => 'value',
		'#value' => $all_referring_fields,
	 );
	
	$form['nhpid_entityreference_referred_fields']['save']=array(
		'#type' => 'submit',
		'#value' => t('Save'),
		//'#access' => isset($form_state['clicked_button']) and $form_state['clicked_button']['#id'] == 'edit-nhpid-field-reference-referred-fields-update-referring-type',
		'#name' => "nhpid_entityreference_referred_fields_save",
		'#limit_validation_errors' => array(array('nhpid_entityreference_referred_fields')),
		'#submit' => array('nhpid_field_dependency_form_submit'),
	  );

	
	return $form;
}
function nhpid_field_dependency_form_($form, &$form_state=NULL) {
	$all_nhpid_types = get_all_nhpid_data_node_types();
	$referring_nhpid_types =$all_nhpid_types;
	$all_referring_fields = array();
	$all_fc_referring_fields = array();
	$all_possible_referred_fields = array();
	foreach($all_nhpid_types as $nhpid_type => $name){
		$type_fields = get_all_fields_of_node_type($nhpid_type);
		foreach ($type_fields as $field => $field_info){
			if ($field_info['type'] == 'entityreference') {
				$all_referring_fields[$nhpid_type][$field]="$field (". $field_info['label'] . ")";
			}
			if($field_info['type'] == 'text' or $field_info['type'] == 'text_long'){ //only text and text_long fields can be a referred field
				$all_possible_referred_fields[$nhpid_type][$field]="$field (". $field_info['label'] . ")";
			}
			if($field_info['type'] == 'field_collection') {
		
				$fc_field_instances = field_info_instances('field_collection_item', $field);
				foreach($fc_field_instances as $fc_field => $fc_field_instance){
					$fc_field_type = nhpid_api_get_field_type($fc_field);
					if ($fc_field_type == 'entityreference') {
					$all_fc_referring_fields[$nhpid_type][$field]['fields'][$fc_field]="$fc_field(" . $fc_field_instance['label'] .')'  ;
					$all_fc_referring_fields[$nhpid_type][$field]['label']="$field (". $field_info['label'] . ")";
					}
				}
			}
		}
	if (empty($all_referring_fields[$nhpid_type]) and empty($all_fc_referring_fields[$nhpid_type])) 	unset($referring_nhpid_types[$nhpid_type]);
	}
	//dpm($referring_nhpid_types);
  $form['#tree'] = TRUE;
  $form['help'] = array(
    '#type' => 'item',
    '#markup' => t("This setting defines settings used by field_reference fields. Click 'Reset field_reference option lists' to save the changes after and changes." ),
  );
  $form['nhpid_field_reference_referred_fields'] = array(
    '#type' => 'fieldset',
    '#title' => t('Referred fields'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE Xor (isset($form_state['clicked_button']) and $form_state['clicked_button']['#id'] == 'edit-nhpid-field-reference-referred-fields-update-referring-type'),
  );
	$form['nhpid_field_reference_referred_fields']['help'] = array(
    '#type' => 'item',
    '#markup' => t("Please notice field_reference setting is global a setting, meaning if you change a field of a content type, you change all content types containing the field. Please make sure the referred fields include all fields which are referred by the field in all content types." ),
  );
  
  $array_keys=array_keys($referring_nhpid_types);
  $referring_type = empty($form_state['values']['nhpid_field_reference_referred_fields']['referring_type'])? array_shift($array_keys):$form_state['values']['nhpid_field_reference_referred_fields']['referring_type'];
  $form['nhpid_field_reference_referred_fields']['referring_type'] = array(
	    '#type' => 'select',
	    '#title' => t("Referring Node Type (Reffering Field)"),
	    '#options' => $referring_nhpid_types,
			'#default_value' => $referring_type,
	);
  $form['nhpid_field_reference_referred_fields']['update_referring_type']=array(
    '#type' => 'submit',
    '#value' => t('Show referred fields for selected referring node type'),
    '#name' => "nhpid_field_reference_referred_fields_update_referring_type",
    '#limit_validation_errors' => array(array('nhpid_field_reference_referred_fields', 'referring_type')),
	'#submit' => array('nhpid_field_dependency_form_submit'),
  );
	
  $form['nhpid_field_reference_referred_fields']['fields']=array(
    '#type' => 'value',
    '#value' => $all_referring_fields[$referring_type],
  );
  if (isset($all_fc_referring_fields[$referring_type])){
	  $form['nhpid_field_reference_referred_fields']['fc_fields']=array(
		'#type' => 'value',
		'#value' => $all_fc_referring_fields[$referring_type],
	  );
  }
	$referring_fields = $all_referring_fields[$referring_type];
	foreach($referring_fields as $referring_field => $referring_field_name){
		$referring_field_field = field_info_field($referring_field);
		$form['nhpid_field_reference_referred_fields'][$referring_field] = array(
	    '#type' => 'fieldset',
	    '#title' => t("Referring field: $referring_field_name"),
	    '#collapsible' => TRUE,
	    '#collapsed' => false,
	  );
		//drupal_set_message(nhpid_api_dump($referring_field_field['settings']['fields']['node'], 'blue', TRUE));
		$referred_types = isset($referring_field_field['settings']['fields']['node'])? $referring_field_field['settings']['fields']['node'] : array();
		$form['nhpid_field_reference_referred_fields'][$referring_field]['old_referred_types'] = array(
	    '#type' => 'fieldset',
	    '#title' => t("Existing Referred Fields"),
	    '#collapsible' => TRUE,
	    '#collapsed' => false,
			'#access'=>!empty($referring_field_field['settings']['fields']['node']),
	  );
    $referred_nhpid_types = array_diff_key($all_nhpid_types,$referred_types);
  	foreach($referred_types as $referred_type=>$referred_fields){

      $form['nhpid_field_reference_referred_fields'][$referring_field]['old_referred_types'][$referred_type] = array(
		    '#type' => 'fieldset',
		    '#title' => t("Referred Fields from node type $referred_type"),
		    '#collapsible' => TRUE,
		    '#collapsed' => false,
		  );
			$form['nhpid_field_reference_referred_fields'][$referring_field]['old_referred_types'][$referred_type]['fields'] = array(
		    '#type' => 'checkboxes',
		    //'#title' => t("Referred field: $referred_type"),
		    '#options' => $all_possible_referred_fields[$referred_type],
		    '#default_value' => $referred_fields,
		  );
      unset($nhpid_types[$referred_type]);
		}

    $form['nhpid_field_reference_referred_fields'][$referring_field]['new_referred_types'] = array(
	    '#type' => 'fieldset',
	    '#title' => t("New Referred Fields"),
	    '#collapsible' => TRUE,
	    '#collapsed' => TRUE,
	  );

		foreach($referred_nhpid_types as $possible_referred_type=>$possible_referring_type_name){
    	//if(in_array($possible_referred_type, array_keys($referred_types))) continue;
			$form['nhpid_field_reference_referred_fields'][$referring_field]['new_referred_types'][$possible_referred_type] = array(
		    '#type' => 'fieldset',
		    '#title' => t($possible_referring_type_name),
		    '#collapsible' => TRUE,
		    '#collapsed' => TRUE,
		  );
			 if (isset($all_possible_referred_fields[$possible_referred_type])){
				$possible_referred_fields = $all_possible_referred_fields[$possible_referred_type];
				$form['nhpid_field_reference_referred_fields'][$referring_field]['new_referred_types'][$possible_referred_type]['fields'] = array(
				'#type' => 'radios',
				'#title' => t("Referred Fields"),
				'#options' => $possible_referred_fields,
			  );
			}
		}
	}
	$nhpid_types = get_all_nhpid_data_node_types();
	if (isset($all_fc_referring_fields[$referring_type])){
		$fc_referring_fields = $all_fc_referring_fields[$referring_type];
		foreach($fc_referring_fields as $fc_referring_field => $fc_referring_field_info){
			$fc_referring_field_label = $fc_referring_field_info['label'];
			$fc_referring_field_fields = $fc_referring_field_info['fields'];
			$form['nhpid_field_reference_referred_fields'][$fc_referring_field] = array(
				'#type' => 'fieldset',
				'#title' => t("Referring field: $fc_referring_field_label"),
				'#collapsible' => TRUE,
				'#collapsed' => false,
			  );
			foreach($fc_referring_field_fields as $fc_referring_field_field => $fc_referring_field_field_name){
				$referring_field_field = field_info_field($fc_referring_field_field);
			
				//drupal_set_message(nhpid_api_dump($referring_field_field['settings']['fields']['node'], 'blue', TRUE));
				$referred_types = isset($referring_field_field['settings']['fields']['node'])? $referring_field_field['settings']['fields']['node'] : array();
		  $form['nhpid_field_reference_referred_fields'][$fc_referring_field][$fc_referring_field_field] = array(
				'#type' => 'fieldset',
				'#title' => t("Referring field: $fc_referring_field_field_name"),
				'#collapsible' => TRUE,
				'#collapsed' => false,
			  );
				$form['nhpid_field_reference_referred_fields'][$fc_referring_field][$fc_referring_field_field]['old_referred_types'] = array(
				'#type' => 'fieldset',
				'#title' => t("Existing referring fields"),
				'#collapsible' => TRUE,
				'#collapsed' => false,
					'#access'=>!empty($referring_field_field['settings']['fields']['node']),
			  );
		  $referred_nhpid_types = array_diff_key($all_nhpid_types,$referred_types);
			foreach($referred_types as $referred_type=>$referred_fields){

			  $form['nhpid_field_reference_referred_fields'][$fc_referring_field][$fc_referring_field_field]['old_referred_types'][$referred_type] = array(
					'#type' => 'fieldset',
					'#title' => t("Referring fields: $referred_type"),
					'#collapsible' => TRUE,
					'#collapsed' => false,
				  );
					$form['nhpid_field_reference_referred_fields'][$fc_referring_field][$fc_referring_field_field]['old_referred_types'][$referred_type]['fields'] = array(
					'#type' => 'checkboxes',
					//'#title' => t("Referred field: $referred_type"),
					'#options' => $all_possible_referred_fields[$referred_type],
					'#default_value' => $referred_fields,
				  );
			  unset($nhpid_types[$referred_type]);
				}

			$form['nhpid_field_reference_referred_fields'][$fc_referring_field][$fc_referring_field_field]['new_referred_types'] = array(
				'#type' => 'fieldset',
				'#title' => t("New referring fields"),
				'#collapsible' => TRUE,
				'#collapsed' => TRUE,
			  );
		  
				foreach($referred_nhpid_types as $possible_referred_type=>$possible_referring_type_name){
				//if(in_array($possible_referred_type, array_keys($referred_types))) continue;
					$form['nhpid_field_reference_referred_fields'][$fc_referring_field][$fc_referring_field_field]['new_referred_types'][$possible_referred_type] = array(
					'#type' => 'fieldset',
					'#title' => t($possible_referring_type_name),
					'#collapsible' => TRUE,
					'#collapsed' => TRUE,
				  );
			  $possible_referred_fields = $all_possible_referred_fields[$possible_referred_type];
			  //$possible_referred_fields = field_info_instances('node', $possible_referred_type);
					$form['nhpid_field_reference_referred_fields'][$fc_referring_field][$fc_referring_field_field]['new_referred_types'][$possible_referred_type]['fields'] = array(
					'#type' => 'checkboxes',
					'#title' => t("Referred field"),
					'#options' => $possible_referred_fields,
				  );
				}
			}
		}
	

	  $form['nhpid_field_reference_referred_fields']['save']=array(
		'#type' => 'submit',
		'#value' => t('Save'),
		'#access' => isset($form_state['clicked_button']) and $form_state['clicked_button']['#id'] == 'edit-nhpid-field-reference-referred-fields-update-referring-type',
		'#name' => "nhpid_field_reference_referred_fields_" . $refering_type . "_save",
		'#limit_validation_errors' => array(array('nhpid_field_reference_referred_fields')),
		'#submit' => array('nhpid_field_dependency_form_submit'),
	  );
	}

	// Workflow states
  $form['nhpid_field_reference_visible_wkf_states'] = array(
    '#type' => 'fieldset',
    '#title' => t('Referred node workflow states visible to referring fields'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
	$workflow_name='NHPID Data Workflow';
	$sql = "select ws.sid, ws.state from {workflow_states} ws, {workflows} w where ws.sid > 1 and ws.wid = w.wid and w.name=:workflow_name order by ws.weight";

  $wfs = array();
  $result = db_query($sql, array(':workflow_name'=>$workflow_name));
  $default_states = array();
  while ($wf = $result->fetchAssoc()) {
    $wfs[$wf['sid']] = $wf['state'];
    if ($wf['state'] == 'Published') $default_states[] = $wf['state'];
    if ($wf['state'] == 'Validated') $default_states[] = $wf['state'];
  }
  $wf_state = !empty($form_state['values']['nhpid_field_reference_visible_wkf_states']['nhpid_visible_wkf_states']) ? $form_state['values']['nhpid_field_reference_visible_wkf_states']['nhpid_visible_wkf_states'] : variable_get('nhpid_visible_wkf_states', $default_states);
  
  $form['nhpid_field_reference_visible_wkf_states']['nhpid_visible_wkf_states'] = array(
    '#type' => 'checkboxes', 
    '#title' => t('Select one or two workflow State(s). If no states selected, all states are in effective.'),
    '#options' => $wfs,
    '#multiple' => TRUE,
    '#default_value' => $wf_state,
    '#description' => t('Depending nodes can only see their depended nodes at selected states.'),
		'#required' => TRUE,
  );

  $form['nhpid_field_reference_visible_wkf_states']['save']=array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#name' => 'nhpid_field_reference_visible_wkf_states_save',
    '#limit_validation_errors' => array(array('nhpid_field_reference_visible_wkf_states'),
																				array('mapped_fields'),),
		'#submit' => array('nhpid_field_dependency_form_submit'),
  );
return $form;
	//unit type mapping
	$mapped_fields = array();
  $form['nhpid_field_reference_unit_unit_type_mapping'] = array(
  '#type' => 'fieldset',
  '#title' => t('Unit fields/unit type mapping'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
  );
  $unit_fields = array();
	$fields = field_info_fields('node');

	foreach($fields as $field){
		if($field['type'] == 'field_reference' and !empty($field['settings']['fields']['node']['code_unit']) ){
      $unit_fields[]=$field['field_name'];
		}
	}
	$mapped_fields = array_merge($mapped_fields, $unit_fields);
  $content_types = array();
	foreach($unit_fields as $unit_field){
    $content_types = array_merge($content_types, nhpid_api_get_content_types_by_field_name($unit_field));
	}
  $unit_type_nodes = node_load_multiple(get_all_nids_by_type('code_unit_type'));
  $nhpid_field_unit_type_mapping = variable_get('nhpid_field_unit_type_mapping', array());

  $unit_types = array();
  foreach ($unit_type_nodes as $unit_type_node) {
		//$unit_types[$unit_type_node->field_code[$unit_type_node->language][0]['value']] = $unit_type_node->field_code[$unit_type_node->language][0]['value'] . ' (' . $unit_type_node->field_description_e[$unit_type_node->language][0]['value'] .')';
    $unit_types[$unit_type_node->nid] = $unit_type_node->field_code[$unit_type_node->language][0]['value'] . ' (' . $unit_type_node->field_description_e[$unit_type_node->language][0]['value'] .')';

	}
  natsort($unit_types);
  $node_types = array();
  $form['nhpid_field_reference_unit_unit_type_mapping']['help']=array(
    '#type' => 'item',
    '#markup' => "This tool sets unit types of the field field_unit. Only units of selected types will be shown in the node edit forms. If no any types selected, all units will be shown.",
  );
  foreach ($content_types as $type => $name) {
     $node_types[] = $type;
    //$type_mapping = "nhpid_" . $type . "_unit_type_mapping";
      $form['nhpid_field_reference_unit_unit_type_mapping'][$type]=array(
      '#type' => 'fieldset',
      '#title' => "$name ($type)",
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    foreach($unit_fields as $unit_field){
      if($field_info = field_info_instance('node', $unit_field, $type)){
        $form['nhpid_field_reference_unit_unit_type_mapping'][$type][$unit_field]=array(
		      '#type' => 'fieldset',
		      '#title' =>$field_info['label'] . ' (' . $unit_field  . ')' ,
		      '#collapsible' => TRUE,
		      '#collapsed' => FALSE,
		    );
        $default =  $nhpid_field_unit_type_mapping[$type][$unit_field]['unit_types'];

		    $form['nhpid_field_reference_unit_unit_type_mapping'][$type][$unit_field]['unit_types']=array(
		      '#type' => 'checkboxes',
		      '#title' => 'Unit types',
		      '#options' => $unit_types,
		      '#default_value' => $default,
		      '#multiple' => TRUE,
		      '#required' => FALSE,
		      '#description' => t('Select unit types. To select all, check all node types or leave all of them unchecked.'),
		    );
			}
		}
  }
  $form['nhpid_field_reference_unit_unit_type_mapping']['node_types']=array(
    '#type' => 'value',
    '#value' => $node_types,
  );
  $form['nhpid_field_reference_unit_unit_type_mapping']['save']=array(
    '#type' => 'submit',
    '#value' => t('Save'),
		'#name' => 'nhpid_field_reference_unit_unit_type_mapping_save',
    '#limit_validation_errors' => array(array('nhpid_field_reference_unit_unit_type_mapping'),
																				array('mapped_fields')),
		'#submit' => array('nhpid_field_dependency_form_submit'),
  );
  	//ingredient category mapping

  $form['nhpid_field_reference_field_ingredient_cat_mapping'] = array(
  '#type' => 'fieldset',
  '#title' => t('field_ingredient_cat mapping'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
  );
  $ingredient_cat_fields = array();
	$fields = field_info_fields('node');

	foreach($fields as $field){
		if($field['type'] == 'field_reference' and !empty($field['settings']['fields']['node']['code_ingredient_category']) ){
      $ingredient_cat_fields[]=$field['field_name'];
		}
	}
	$mapped_fields = array_merge($mapped_fields, $ingredient_cat_fields);
  $content_types = array();
  //drupal_set_message(nhpid_api_dump($unit_fields, 'red', TRUE));

	foreach($ingredient_cat_fields as $ingredient_cat_field){
    $content_types = array_merge($content_types, nhpid_api_get_content_types_by_field_name($ingredient_cat_field));
	}
  //drupal_set_message(nhpid_api_dump($content_types, 'red', TRUE));
  $code_ingredient_category_nodes = node_load_multiple(get_all_nids_by_type('code_ingredient_category'));
  $nhpid_field_ingredient_cat_mapping = variable_get('nhpid_field_ingredient_cat_mapping', array());
  //drupal_set_message(nhpid_api_dump($code_ingredient_category_nodes, 'red', TRUE));
  $ingredient_cats = array();
  foreach ($code_ingredient_category_nodes as $code_ingredient_category_node) {
    //drupal_set_message(nhpid_api_dump($unit_type_node, 'red', TRUE));
		//$unit_types[$unit_type_node->field_code[$unit_type_node->language][0]['value']] = $unit_type_node->field_code[$unit_type_node->language][0]['value'] . ' (' . $unit_type_node->field_description_e[$unit_type_node->language][0]['value'] .')';
    $ingredient_cats[$code_ingredient_category_node->nid] = $code_ingredient_category_node->field_code[$code_ingredient_category_node->language][0]['value'] . ' (' . $code_ingredient_category_node->field_description_e[$code_ingredient_category_node->language][0]['value'] .')';
	}
  //drupal_set_message(nhpid_api_dump($ingredient_cats, 'red', TRUE));
  natsort($ingredient_cats);
  $node_types = array();
  $form['nhpid_field_reference_field_ingredient_cat_mapping']['help']=array(
    '#type' => 'item',
    '#markup' => "This tool sets allowed ingredient categories of the field field_ingredient_cat. Only selected categories will be shown in the node edit forms. If no any category selected, all of them will be shown.",
  );
  foreach ($content_types as $type => $name) {
     $node_types[] = $type;
    //$type_mapping = "nhpid_" . $type . "_unit_type_mapping";
      $form['nhpid_field_reference_field_ingredient_cat_mapping'][$type]=array(
      '#type' => 'fieldset',
      '#title' => "$name ($type)",
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    foreach($ingredient_cat_fields as $ingredient_cat_field){
      if($field_info = field_info_instance('node', $ingredient_cat_field, $type)){
        $form['nhpid_field_reference_field_ingredient_cat_mapping'][$type][$ingredient_cat_field]=array(
		      '#type' => 'fieldset',
		      '#title' =>$field_info['label'] . ' (' . $ingredient_cat_field  . ')' ,
		      '#collapsible' => TRUE,
		      '#collapsed' => FALSE,
		    );
        $default =  $nhpid_field_ingredient_cat_mapping[$type][$ingredient_cat_field]['ingredient_categories'];

		    $form['nhpid_field_reference_field_ingredient_cat_mapping'][$type][$ingredient_cat_field]['ingredient_categories']=array(
		      '#type' => 'checkboxes',
		      '#title' => 'Ingredient Categories',
		      '#options' => $ingredient_cats,
		      '#default_value' => $default,
		      '#multiple' => TRUE,
		      '#required' => FALSE,
		      '#description' => t('Select ingredient categories. To select all, check all categories or leave all of them unchecked.'),
		    );
			}
		}
  }
  $form['nhpid_field_reference_field_ingredient_cat_mapping']['node_types']=array(
    '#type' => 'value',
    '#value' => $node_types,
  );
  $form['nhpid_field_reference_field_ingredient_cat_mapping']['save']=array(
    '#type' => 'submit',
    '#value' => t('Save'),
		'#name' => 'nhpid_field_reference_field_ingredient_cat_mapping_save',
    '#limit_validation_errors' => array(array('nhpid_field_reference_field_ingredient_cat_mapping'),
																				array('mapped_fields')),
		'#submit' => array('nhpid_field_dependency_form_submit'),
  );
  //field_nhpid_approved_name_mapping
  $form['nhpid_field_reference_field_approved_ingredient_name_mapping'] = array(
  '#type' => 'fieldset',
  '#title' => t('field_approved_ingredient_name mapping'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
  );
	$mapped_field = 'field_approved_ingredient_name';
	$mapped_fields[] = $mapped_field;
	$content_types = array();
	$content_types = array_merge($content_types, nhpid_api_get_content_types_by_field_name($mapped_field));
	$field_info = field_info_field($mapped_field);
	$referred_types = array();
	if ($field_info['settings']['handler'] == 'base'){
		foreach($field_info['settings']['handler_settings']['target_bundles'] as $type => $val){
			$node_type_names = node_type_get_names();
			$referred_types[$type] = $node_type_names[$type] . ' (' . $type . ')';
		}
	}
	if ($field_info['settings']['handler'] == 'views'){
		$view_name=$field_info['settings']['handler_settings']['view']['view_name'];
		$display_name=$field_info['settings']['handler_settings']['view']['display_name'];
		$view = views_get_view($view_name);
		$filter_name= 'type';
		$display = $view->display[$display_name];
		foreach($display->display_options['filters'][$filter_name]['value'] as $type => $val){
			$node_type_names = node_type_get_names();
			$referred_types[$type] = $node_type_names[$type] . ' (' . $type . ')';
		}
	}

  //drupal_set_message(nhpid_api_dump($content_types, 'red', TRUE));
  $nhpid_field_approved_ingredient_name_mapping = variable_get('nhpid_field_approved_ingredient_name_mapping', array());

  $form['nhpid_field_reference_field_approved_ingredient_name_mapping']['help']=array(
    '#type' => 'item',
    '#markup' => "This tool sets referred node types by field_approved_ingredient_name. Only selected referred fields of selected node types will be shown in dropdoen list. If no any referred fields are selected, all of them will be shown.",
  );
  foreach ($content_types as $type => $name) {
     $node_types[] = $type;
    //$type_mapping = "nhpid_" . $type . "_unit_type_mapping";
      $form['nhpid_field_reference_field_approved_ingredient_name_mapping'][$type]=array(
      '#type' => 'fieldset',
      '#title' => "$name ($type)",
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $default =  isset($nhpid_field_approved_ingredient_name_mapping[$type])? $nhpid_field_approved_ingredient_name_mapping[$type]['referred_types']: array();

    $form['nhpid_field_reference_field_approved_ingredient_name_mapping'][$type]['referred_types']=array(
      '#type' => 'checkboxes',
      '#title' => 'Node types',
      '#options' => $referred_types,
      '#default_value' => $default,
      '#multiple' => TRUE,
      '#checkall' => TRUE,
      '#required' => FALSE,
      '#description' => t('Select node types. To select all, check all node types or leave all of them unchecked.'),
    );
  }
  $form['nhpid_field_reference_field_approved_ingredient_name_mapping']['all_referred_types']=array(
    '#type' => 'value',
    '#value' => $referred_types,
  );
  $form['nhpid_field_reference_field_approved_ingredient_name_mapping']['node_types']=array(
    '#type' => 'value',
    '#value' => array_keys($content_types),
  );
  $form['nhpid_field_reference_field_approved_ingredient_name_mapping']['save']=array(
    '#type' => 'submit',
    '#value' => t('Save'),
		'#name' => 'nhpid_field_reference_field_approved_ingredient_name_mapping_save',
    '#limit_validation_errors' => array(array('nhpid_field_reference_field_approved_ingredient_name_mapping'),
																				array('mapped_fields'),),
		'#submit' => array('nhpid_field_dependency_form_submit'),
  );
  //field_constituent mapping
  $form['nhpid_field_reference_field_constituent_mapping'] = array(
  '#type' => 'fieldset',
  '#title' => t('field_constituent mapping'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
  );
  $mapped_field = 'field_constituent';
	$mapped_fields[] = $mapped_field;
  $content_types = array();
  $content_types = array_merge($content_types, nhpid_api_get_content_types_by_field_name($mapped_field));
	$field_info = field_info_field($mapped_field);
	$referred_types = array();
	if ($field_info['settings']['handler'] == 'base'){
		foreach($field_info['settings']['handler_settings']['target_bundles'] as $type => $val){
			$node_type_names = node_type_get_names();
			$referred_types[$type] = $node_type_names[$type] . ' (' . $type . ')';
		}
	}
	if ($field_info['settings']['handler'] == 'views'){
		$view_name=$field_info['settings']['handler_settings']['view']['view_name'];
		$display_name=$field_info['settings']['handler_settings']['view']['display_name'];
		$view = views_get_view($view_name);
		$filter_name= 'type';
		$display = $view->display[$display_name];
		foreach($display->display_options['filters'][$filter_name]['value'] as $type => $val){
			$node_type_names = node_type_get_names();
			$referred_types[$type] = $node_type_names[$type] . ' (' . $type . ')';
		}
	}
  //drupal_set_message(nhpid_api_dump($content_types, 'red', TRUE));
  $nhpid_field_constituent_mapping = variable_get('nhpid_field_constituent_mapping', array());

  $form['nhpid_field_reference_field_constituent_mapping']['help']=array(
    '#type' => 'item',
    '#markup' => "This tool sets referred node types by field_constituent. Only selected referred fields of selected node types will be shown in dropdown list. If no any referred fields are selected, all of them will be shown.",
  );
  foreach ($content_types as $type => $name) {
     $node_types[] = $type;
    //$type_mapping = "nhpid_" . $type . "_unit_type_mapping";
      $form['nhpid_field_reference_field_constituent_mapping'][$type]=array(
      '#type' => 'fieldset',
      '#title' => "$name ($type)",
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $default = isset($nhpid_field_constituent_mapping[$type])? $nhpid_field_constituent_mapping[$type]['referred_types']:array();

    $form['nhpid_field_reference_field_constituent_mapping'][$type]['referred_types']=array(
      '#type' => 'checkboxes',
      '#title' => 'Node types',
      '#options' => $referred_types,
      '#default_value' => $default,
      '#multiple' => TRUE,
      '#checkall' => TRUE,
      '#required' => FALSE,
      '#description' => t('Select node types. To select all, check all node types or leave all of them unchecked.'),
    );

  }
  $form['nhpid_field_reference_field_constituent_mapping']['all_referred_types']=array(
    '#type' => 'value',
    '#value' => $referred_types,
  );
  $form['nhpid_field_reference_field_constituent_mapping']['node_types']=array(
    '#type' => 'value',
    '#value' => array_keys($content_types),
  );
  $form['nhpid_field_reference_field_constituent_mapping']['save']=array(
    '#type' => 'submit',
    '#value' => t('Save'),
		'#name' => 'nhpid_field_reference_field_constituent_mapping_save',
    '#limit_validation_errors' => array(array('nhpid_field_reference_field_constituent_mapping'),
																				array('mapped_fields'),),
		'#submit' => array('nhpid_field_dependency_form_submit'),
  );

	//field_sub_ingredient mapping
  $form['nhpid_field_reference_field_subingredient_mapping'] = array(
  '#type' => 'fieldset',
  '#title' => t('field_subingredient mapping'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
  );
  $mapped_field = 'field_subingredient';
	$mapped_fields[] = $mapped_field;
  $content_types = array();
  $content_types = array_merge($content_types, nhpid_api_get_content_types_by_field_name($mapped_field));
	$field_info = field_info_field($mapped_field);
	$referred_types = array();
	if ($field_info['settings']['handler'] == 'base'){
		foreach($field_info['settings']['handler_settings']['target_bundles'] as $type => $val){
			$node_type_names = node_type_get_names();
			$referred_types[$type] = $node_type_names[$type] . ' (' . $type . ')';
		}
	}
	if ($field_info['settings']['handler'] == 'views'){
		$view_name=$field_info['settings']['handler_settings']['view']['view_name'];
		$display_name=$field_info['settings']['handler_settings']['view']['display_name'];
		$view = views_get_view($view_name);
		$filter_name= 'type';
		$display = $view->display[$display_name];
		foreach($display->display_options['filters'][$filter_name]['value'] as $type => $val){
			$node_type_names = node_type_get_names();
			$referred_types[$type] = $node_type_names[$type] . ' (' . $type . ')';
		}
	}
  //drupal_set_message(nhpid_api_dump($content_types, 'red', TRUE));
  $nhpid_field_subingredient_mapping = variable_get('nhpid_field_subingredient_mapping', array());

  $form['nhpid_field_reference_field_subingredient_mapping']['help']=array(
    '#type' => 'item',
    '#markup' => "This tool sets referred node types by field_subingredient. Only selected referred fields of selected node types will be shown in dropdown list. If no any referred fields are selected, all of them will be shown.",
  );
  foreach ($content_types as $type => $name) {
     $node_types[] = $type;
    //$type_mapping = "nhpid_" . $type . "_unit_type_mapping";
      $form['nhpid_field_reference_field_subingredient_mapping'][$type]=array(
      '#type' => 'fieldset',
      '#title' => "$name ($type)",
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $default = isset($nhpid_field_subingredient_mapping[$type])? $nhpid_field_subingredient_mapping[$type]['referred_types']:array();

    $form['nhpid_field_reference_field_subingredient_mapping'][$type]['referred_types']=array(
      '#type' => 'checkboxes',
      '#title' => 'Node types',
      '#options' => $referred_types,
      '#default_value' => $default,
      '#multiple' => TRUE,
      '#checkall' => TRUE,
      '#required' => FALSE,
      '#description' => t('Select node types. To select all, check all node types or leave all of them unchecked.'),
    );

  }
  $form['nhpid_field_reference_field_subingredient_mapping']['all_referred_types']=array(
    '#type' => 'value',
    '#value' => $referred_types,
  );
  $form['nhpid_field_reference_field_subingredient_mapping']['node_types']=array(
    '#type' => 'value',
    '#value' => array_keys($content_types),
  );
  $form['nhpid_field_reference_field_subingredient_mapping']['save']=array(
    '#type' => 'submit',
    '#value' => t('Save'),
		'#name' => 'nhpid_field_reference_field_subingredient_mapping_save',
    '#limit_validation_errors' => array(array('nhpid_field_reference_field_subingredient_mapping'),
																				array('mapped_fields'),),
		'#submit' => array('nhpid_field_dependency_form_submit'),
  );
  $form['mapped_fields']=array(
    '#type' => 'value',
    '#value' => $mapped_fields,
	);
  $form['save_all']=array(
    '#type' => 'submit',
    '#value' => t('Save All Mappings'),
		'#name' => 'save_all',
    '#limit_validation_errors' => array(array('nhpid_field_reference_unit_unit_type_mapping'),
																				array('nhpid_field_reference_field_approved_ingredient_name_mapping'),
																				array('nhpid_field_reference_field_constituent_mapping'),
																				array('nhpid_field_reference_field_subingredient_mapping'),
																				array('mapped_fields'),
																				),
		'#submit' => array('nhpid_field_dependency_form_submit'),
	);
  // dropdown list labels
  /*
	$all_referred_fields = field_reference_get_all_referred_fields();
	$labels = variable_get('nhpid_field_reference_list_labels', array());
  $form['nhpid_field_reference_referred_field_label'] = array(
    '#type' => 'fieldset',
    '#title' => t('Referred fields label'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
	foreach($all_referred_fields as $entity_type => $referred_entities){
    $form['nhpid_field_reference_referred_field_label']['nhpid_field_reference_referred_field_label_data'] = array(
	    '#type' => 'fieldset',
	    //'#title' => "Entity Type: $entity_type",
	    '#collapsible' => TRUE,
	    '#collapsed' => FALSE,
	  );
    $form['nhpid_field_reference_referred_field_label']['nhpid_field_reference_referred_field_label_data'][$entity_type] = array(
	    '#type' => 'fieldset',
	    '#title' => "Entity Type: $entity_type",
	    '#collapsible' => TRUE,
	    '#collapsed' => FALSE,
	  );
    ksort($referred_entities);

		foreach($referred_entities as $bundle => $referred_fields_name){
      $form['nhpid_field_reference_referred_field_label']['nhpid_field_reference_referred_field_label_data'][$entity_type][$bundle] = array(
		    '#type' => 'fieldset',
		    '#title' => "Entity: $bundle",
		    '#collapsible' => TRUE,
		    '#collapsed' => TRUE,
		  );
			$all_possible_label_fields = get_node_type_field_name_title_mapping($bundle);
			foreach($referred_fields_name as $key => $referred_field_name){
        $form['nhpid_field_reference_referred_field_label']['nhpid_field_reference_referred_field_label_data'][$entity_type][$bundle][$key] = array(
			    '#type' => 'fieldset',
			    '#title' => "Field: $key",
			    '#collapsible' => TRUE,
			    '#collapsed' => FALSE,
			  );
				unset($all_possible_label_fields[$key]);
        $all_possible_label_fields = array_merge(array('' => '--none--'), $all_possible_label_fields);
				$label_field = !empty($form_state['values']['nhpid_field_reference_referred_field_label']['nhpid_field_reference_referred_field_label_data'][$entity_type][$bundle][$key]['label_field']) ? $form_state['values']['nhpid_field_reference_referred_field_label'][$entity_type][$bundle][$key]['label_field'] : $labels[$entity_type][$bundle][$key]['label_field'];
        $form['nhpid_field_reference_referred_field_label']['nhpid_field_reference_referred_field_label_data'][$entity_type][$bundle][$key]['label_field'] = array(
          '#type' => 'select',
			    //'#title' => t("Referred field: $referred_type"),
			    '#options' => $all_possible_label_fields,
			    '#default_value' => $label_field,
				);
			}
		}
	}
  $form['nhpid_field_reference_referred_field_label']['save']=array(
  '#type' => 'submit',
    '#value' => t('Save'),
		//'#access' => $form_state['clicked_button']['#id'] == 'edit-nhpid-field-reference-referred-fields-update-referring-type',
    '#name' => "nhpid-field-reference-referred-field-label-save",
    '#limit_validation_errors' => array(array('nhpid_field_reference_referred_field_label')),
		'#submit' => array('nhpid_field_dependency_form_submit'),
  );
  
	//reset field reference option lists
	$referring_fields = field_reference_get_all_referring_fields();
  $form['reset_field_reference_option_lists'] = array(
  '#type' => 'fieldset',
  '#title' => t('Reset field reference option lists'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
  );
  $form['reset_field_reference_option_lists']['help']=array(
    '#type' => 'item',
    '#markup' => "This tool resets all field reference option lists. It takes a prolonged period of time if you select all fields or a large number of fields.",
  );
  foreach ($referring_fields as $referring_field) {
		$table_select_referring_fields[$referring_field]=array('referring_field'=>$referring_field);
  }
  $selected_referring_fields = !empty($form_state['values']['reset_field_reference_option_lists']['referring_fields']) ? $form_state['values']['reset_field_reference_option_lists']['referring_fields'] : array();
	$header=array('referring_field'=>"Referring Fields");
  $form['reset_field_reference_option_lists']['referring_fields'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#js_select' => TRUE,
    '#title' => t('Select Referring Fields'),
    '#options' => $table_select_referring_fields,
    '#default_value' => $selected_referring_fields,
    '#required' => TRUE,
    '#description' => t('Select one or more referring_fields'),
  );
	$form['reset_field_reference_option_lists']['save']=array(
    '#type' => 'submit',
    '#value' => t('Reset field_reference option lists'),
		'#name' => 'reset_field_reference_option_lists_save',
    '#limit_validation_errors' => array(array('reset_field_reference_option_lists'),),
		'#submit' => array('nhpid_field_dependency_form_submit'),
	);
*/	
  return $form;
}

function nhpid_field_dependency_form_validate($form, &$form_state) {

	switch ($form_state['clicked_button']['#id']) {
    
    case "edit-nhpid-field-reference-visible-wkf-states-save":
		/*
    $states = $form_state['values']['nhpid_field_reference_visible_wkf_states']['nhpid_visible_wkf_states'];
    $count = 0;
    foreach ($states as $state) {
      if ($state) $count ++;
    }
    
    if ($count > 2 ) {
      form_set_error('nhpid_field_dependency_visible_wkf_states][nhpid_field_reference_visible_wkf_states][nhpid_visible_wkf_states', 'No more than two states can be selected.');
    }
		*/
    break;
	case "edit-nhpid-entityreference-referred-fields-save":
		//dpm($form_state['values']['nhpid_entityreference_referred_fields']['all_referring_fields']);
		$referring_fields = $form_state['values']['nhpid_entityreference_referred_fields'];
		$all_referring_fields = $form_state['values']['nhpid_entityreference_referred_fields']['all_referring_fields'];
		//dpm($all_referring_fields);
		//dpm($referring_fields);
		foreach($all_referring_fields as $referring_field_name){
			$referring_field=$referring_fields[$referring_field_name];
			foreach($referring_field as $referred_type => $referred_field){
				if (!$referred_field){
					form_set_error(t('nhpid_entityreference_referred_fields][@referring_field][@referred_type', array('@referring_field'=>$referring_field_name, '@referred_type'=> $referred_type)), t('@referring_field: @referred_type has not been set.',  array('@referring_field'=>$referring_field_name, '@referred_type'=> $referred_type)));
					//dpm(t('@referring_field: @referred_type has not been set.',  array('@referring_field'=>$referring_field_name, '@referred_type'=> $referred_type)));
				}
			}

		}	
		break;
	}
	

}

function nhpid_field_dependency_form_submit($form, &$form_state) {
 
  switch ($form_state['clicked_button']['#id']) {
    
    case "edit-nhpid-field-reference-visible-wkf-states-save":
		case "edit-save-all":
      $states = array_values($form_state['values']['nhpid_field_reference_visible_wkf_states']['nhpid_visible_wkf_states']);
      $rtn = array();
      foreach ($states as $sid => $state) {
        if ($state) $rtn[$sid] = $state;
      }
      variable_set('nhpid_visible_wkf_states', $rtn);
      field_reference_update_all_cached_option_lists();
      break;  
		case 'edit-nhpid-field-reference-unit-unit-type-mapping-save':
    case "edit-save-all":
      $unit_type_setting = array();
		  $types = $form_state['values']['nhpid_field_reference_unit_unit_type_mapping']['node_types'];
		  foreach ($types as $type) {
		    $unit_type_setting[$type] = $form_state['values']['nhpid_field_reference_unit_unit_type_mapping'][$type];
		  }
      variable_set('nhpid_field_unit_type_mapping', $unit_type_setting);
      field_reference_update_all_cached_option_lists_by_referred_entity('node', 'code_unit');
			break;
    case 'edit-nhpid-field-reference-field-ingredient-cat-mapping-save':
    case "edit-save-all":
      $ingredient_cat_setting = array();
		  $types = $form_state['values']['nhpid_field_reference_field_ingredient_cat_mapping']['node_types'];
		  foreach ($types as $type) {
		    $ingredient_cat_setting[$type] = $form_state['values']['nhpid_field_reference_field_ingredient_cat_mapping'][$type];
		  }
      variable_set('nhpid_field_ingredient_cat_mapping', $ingredient_cat_setting);
      field_reference_update_all_cached_option_lists_by_referred_entity('node', 'code_ingredient_category');
			break;
		case 'edit-nhpid-field-reference-field-approved-ingredient-name-mapping-save':
    case "edit-save-all":
      $type_setting = array();
		  $types = $form_state['values']['nhpid_field_reference_field_approved_ingredient_name_mapping']['node_types'];
		  foreach ($types as $type) {
		    $type_setting[$type] = $form_state['values']['nhpid_field_reference_field_approved_ingredient_name_mapping'][$type];
		  }
		  variable_set('nhpid_field_approved_ingredient_name_mapping', $type_setting);
      foreach ($types as $type) {
        field_reference_update_all_cached_option_lists('node', $type, array('field_approved_ingredient_name'));
		  }
			break;
		case 'edit-nhpid-field-reference-field-constituent-mapping-save':
    case "edit-save-all":
      $type_setting = array();
		  $types = $form_state['values']['nhpid_field_reference_field_constituent_mapping']['node_types'];
		  foreach ($types as $type) {
		    $type_setting[$type] = $form_state['values']['nhpid_field_reference_field_constituent_mapping'][$type];
		  }
		  variable_set('nhpid_field_constituent_mapping', $type_setting);
      foreach ($types as $type) {
        field_reference_update_all_cached_option_lists('node', $type, array('field_constituent'));
		  }
      break;

  	case 'edit-nhpid-field-reference-field-subingredient-mapping-save':
    case "edit-save-all":
      $type_setting = array();
		  $types = $form_state['values']['nhpid_field_reference_field_subingredient_mapping']['node_types'];
		  foreach ($types as $type) {
		    $type_setting[$type] = $form_state['values']['nhpid_field_reference_field_subingredient_mapping'][$type];
		  }
		  variable_set('nhpid_field_subingredient_mapping', $type_setting);
      foreach ($types as $type) {
        field_reference_update_all_cached_option_lists('node', $type, array('field_subingredient'));
		  }
      break;

    case 'edit-reset-field-reference-option-lists-save':
      $selected_referring_fields = $form_state['values']['reset_field_reference_option_lists']['referring_fields'];
			foreach($selected_referring_fields as $key => $selected_referring_field){
				if (!$selected_referring_field) unset($selected_referring_fields[$key]);
			}
			//drupal_set_message(nhpid_api_dump($selected_referring_fields, 'blue', TRUE));
			field_reference_update_all_cached_option_lists(NULL, NULL, $selected_referring_fields);

			drupal_set_message('Field reference catched option lists have been updated.');
			break;
		case 'edit-nhpid-field-reference-referred-fields-update-referring-type':
			break;
    case 'edit-nhpid-entityreference-referred-fields-save':

		$referring_fields = $form_state['values']['nhpid_entityreference_referred_fields'];
		$referred_fields_settings = array();
		$all_referring_fields = $form_state['values']['nhpid_entityreference_referred_fields']['all_referring_fields'];
		foreach($all_referring_fields as $referring_field_name){
			$referring_field=$referring_fields[$referring_field_name];
			if ($referring_field =='Save'){
				continue;
			}
			foreach ($referring_field as $referred_type => $referred_field){
				$referred_fields_settings[$referring_field_name][$referred_type]=$referred_field;
			}
		}	
		//dpm($referred_fields_settings);
		$variable_name='nhpid_entityreference_fields_settings';
		variable_set($variable_name, $referred_fields_settings);	
		break;
		
	case 'edit-nhpid-field-reference-referred-field-label-save':
    //case "edit-save-all":
			$old_list_labels = variable_get('nhpid_field_reference_list_labels', array());
			$new_list_labels = $form_state['values']['nhpid_field_reference_referred_field_label']['nhpid_field_reference_referred_field_label_data'];
      variable_set('nhpid_field_reference_list_labels', $form_state['values']['nhpid_field_reference_referred_field_label']['nhpid_field_reference_referred_field_label_data']);
			foreach($new_list_labels as $entity_type => $info){
				foreach($info as $bundle => $fields){
					foreach($fields as $field_name => $label_field){
						if (!isset($old_list_labels[$entity_type][$bundle][$field_name]) or $old_list_labels[$entity_type][$bundle][$field_name]['label_field'] != $new_list_labels[$entity_type][$bundle][$field_name]['label_field'] ){
              $rtn = field_reference_update_all_cached_option_lists_by_referred_entity($entity_type, $bundle);
						}
					}
				}
			}
			
      //field_reference_update_all_cached_option_lists();
			break;
    default:

  }
  if (isset($form_state['values']['mapped_fields'])) variable_set('nhpid_field_mapping_mapped_fields', $form_state['values']['mapped_fields']);
  $form_state['storage']['values'] = $form_state['values'];
  $form_state['rebuild'] = TRUE;
}



/***
 * Rule archive and resstore
 */ 
function nhpid_rule_archive_form($form, &$form_state=NULL) {
	$form['#tree'] = TRUE;
	
  $form['#attributes'] = array('enctype' => "multipart/form-data");
  $data = !empty($form_state['values']['data']) ? $form_state['values']['data'] : '';
  $trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
  $form['help']=array(
    '#type' => 'item',
    '#markup' => "This tool lets users to archive all NHPID rules to file and upload archived rule to Drupal. It is suggested that the rules should be archived after any additions and modifications.",
  );
  $form['archive']=array(
    '#type' => 'fieldset',
    '#title' => t('Archive rules'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE, 
  );    
  $form['archive']['archive']=array(
  '#type' => 'submit', 
  '#value' => t('Archive'), 
  );
  $form['upload']=array(
    '#type' => 'fieldset',
    '#title' => t('Restore Archived Rules'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE, 
  );  
  $form['upload']['file']=array(
    '#name' => 'files[file]',
		'#type' => 'file', 
    '#default_value' => $data,
    '#title' => t('Archived rule file'), 
  );
  $form['upload']['upload']=array(
    '#type' => 'submit', 
    '#value' => t('Upload'), 
  );
  return $form;
}

function nhpid_rule_archive_form_submit($form, &$form_state) {
  //drupal_set_message(nhpid_api_dump($form_state, 'red', TRUE));
	switch ($form_state['clicked_button']['#id']) {
    case 'edit-archive-archive':
      $rules = array();
      $rule_variable_id_root = 'nhpid_';
      $sql ="select * from {variable} where name like :name ";
      $result = db_query($sql, array(':name' => $rule_variable_id_root . "%"));
      while ($r = $result->fetchAssoc()) {
        $name = $r['name'];
        $value = variable_get($name, '');
        $rules[] = array('name' => $name, 'value' => $value);
      }

      $data = serialize($rules);
      $data = str_replace("\n", "~TEMP~", $data); // unserialize does not work with string contain '/n'
      $file = "nhpid_rule_archive.txt";
      $uploaded_data_file_path =  "public://rules/";
      //$uploaded_data_file_split_path = $uploaded_data_file_path . '/split';
      $public_file_stream_wrapper = file_stream_wrapper_get_instance_by_scheme('public');
      if (!$public_file_stream_wrapper->dir_opendir($uploaded_data_file_path, null)) file_prepare_directory($uploaded_data_file_path, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
      file_unmanaged_save_data($data, "$uploaded_data_file_path/$file", FILE_EXISTS_REPLACE);

      $path = "$uploaded_data_file_path$file";
      nhpid_api_download($path);
      
      break;
    case 'edit-upload-upload':
      //drupal_set_message(nhpid_api_dump($_FILES, 'red', TRUE));
      $file = file_save_upload('file');
      if ($file) {
        $data = file_get_contents($file -> destination);
        $data = str_replace("~TEMP~", "\n", $data);
        $rules = unserialize($data);
        foreach ($rules as $rule) {
          variable_set($rule['name'], $rule['value']);
        }
        drupal_set_message('The NHPID rules have been restored successfully.');
      }
      else {
        form_set_error('file', 'The NHPID rules have not been restored successfully. Please double check your archived file and try it again.');
      }
      break;
  }
  
  $form_state['storage']['values'] = $form_state['values'];
}

function nhpid_excel_column_title_mapping_form($form, &$form_state=NULL) {
  
  $table_name = NHPID_EXCEL_COLUMN_MAPPING_TABLE;
  //$table_column_names = nhpid_get_table_field_names($table_name);
  $types=get_all_nhpid_data_node_types();
  //$types = array_slice($types, -3, 3);
  $fields_not_checked=array('field_legacy_nid'=>array(),'field_parent_space'=>array(),'field_workflow'=>array());
  //$form['#theme'] = 'nhpid_excel_field_mapping_form';
  $form['#tree']=true;
  $trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
  $form['help']=array(
    '#type' => 'item',
    '#markup' => "To add new mapping, just filled the form and click on 'Save'. To change an existing mapping, click the 'Edit' in the mapping list and change data and save. node_type and drupal_field_name are combined primary key.",
  );
  $form['data_storage'] = array(
    '#type' => 'item',
    '#markup' => t('This settings is stored in the database table <em>!table</em>.', array('!table'=>$table_name)),
   );
  $form['node_types']=array(
		'#type' => 'value',
		'#value' => $types,
	);
  $form['table_name']=array(
		'#type' => 'value',
		'#value' => $table_name,
	);

  foreach ($types as $node_type => $node_name) {
      $drupal_fields = get_all_fields_of_node_type($node_type);
	  $drupal_fields = array_diff_key($drupal_fields,$fields_not_checked);
	  $form[$node_type] = array(
        '#title' => $node_name,
        '#type' => 'fieldset', 
		//'#value' => $node_type,
		'#theme' => 'nhpid_excel_field_mapping_form_wrapper',
        '#collapsible' => TRUE, 
        '#collapsed' => True,
      );
	  
	  $sql = db_select($table_name, 'x')
				->fields('x', array('drupal_field_name', 'excel_field_name','node_type','col_order'))
				->condition('node_type', $node_type)
				->orderBy('col_order')
				->execute();
	  $data = $sql ->fetchAllAssoc('drupal_field_name');
	  $ordered_fields=array_intersect(array_keys($data),array_keys($drupal_fields)) + array_diff( array_keys($drupal_fields),array_keys($data));
	  //dpm($ordered_fields);
	  //dpm(array_keys($drupal_fields));
      foreach($ordered_fields as $drupal_field_name) {
		$excel_field_name=null;
		$excel_field_order=null;
		$field_label=$drupal_fields[$drupal_field_name];
		$excel_field_name=!empty($form_state['values'][$node_type][$drupal_field_name]['excel_field_name'] ) ? $form_state['values'][$node_type][$drupal_field_name]['excel_field_name']  : '';
		$excel_field_order=!empty($form_state['values'][$node_type][$drupal_field_name]['excel_field_order'] ) ? $form_state['values'][$node_type][$drupal_field_name]['excel_field_order']  : count($data) + 1;
		if (isset($data[$drupal_field_name])){
			$excel_field_name = $data[$drupal_field_name]->excel_field_name;
			$excel_field_order=$data[$drupal_field_name]->col_order;
		}
		$element="$drupal_field_name";
		$form[$node_type][$element] = array(
          '#title' => $drupal_field_name,
		  '#type' => 'fieldset', 
          '#collapsible' => TRUE, 
          '#collapsed' => False,
        );
		$form[$node_type][$element]['drupal_field_name'] = array(
		  '#type' => 'item',
		  '#markup' => $drupal_field_name,
        );
		$form[$node_type][$element]['drupal_field_name'] = array(
		  '#type' => 'item', 
          '#markup' => $drupal_field_name,
        );
        $form[$node_type][$element]['excel_field_name'] = array(
		  '#type' => 'textfield', 
          //'#title' => 'Excel Field Name', 
          '#default_value' => $excel_field_name,
		  //'#maxlength' => 60,
		  '#size' => 20,
        );
		
		$form[$node_type][$element]['weight'] = array(
		  '#type' => 'weight', 
          '#title' => 'Weight', 
          '#default_value' => $excel_field_order,
		  '#title_display' => 'invisible',
		  '#delta' => count($ordered_fields) + 1,
        );
		
      }
    }
    
  $form['submit'] = array(
  '#type' => 'submit',
  '#value' => t('Save Required Field Setting')
  );

  return $form;  
  
}

function nhpid_excel_column_title_mapping_form_submit($form, &$form_state) {
   
    $table_name = $form_state['values']['table_name'];
    $node_types = $form_state['values']['node_types'];
	$operations = array();
    foreach ($node_types as $node_type => $node_name) {
	  $drupal_field_names=$form_state['values'][$node_type];
	  foreach($drupal_field_names as $drupal_field_name=>$data){
			$excel_field_name=$data['excel_field_name'];
			$excel_field_order=$data['weight'];
			$item=array(
				  'drupal_field_name' => $drupal_field_name, 
				  'node_type' => $node_type,
				  'excel_field_name' => $excel_field_name,
				  'mapping_field_name' => $drupal_field_name,
				  'col_order' => $excel_field_order,
			);
			$operations[] = array('_nhpid_map_excel_column', array($item, $table_name));
	  }
      
    } 
	$batch = array(
	  'operations' => $operations,
	  'finished' => 'batch_re_gnerate_title_body_finished',
	  // We can define custom messages instead of the default ones.
	  'title' => t('Map excel column with druapl field...'),
	  'init_message' => t('Starting.'),
	  'progress_message' => t('Processed @current out of @total items.'),
	  'error_message' => t('Mapping excel column has encountered an error.'),
	  'file' => drupal_get_path('module', 'nhpid'). '/nhpid_forms.inc',
	);

	batch_set($batch);
	batch_process();

}

function nhpid_lock_system_form($form, &$form_state=NULL) {
	global $user;
	$lock_persistent = variable_get(DATA_EXPORTING_LOCK_VARIABLE, 0);
  $lock_temp = variable_get(DATA_EXPORTING_LOCK_TEMP_VARIABLE, 0);
  $trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
  $form['lock'] = array(
    '#title' => 'Lock system persistently',
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => false,
		);
  $form['lock']['description'] = array(
    '#type' => 'item',
    '#title' => "",
    '#markup' => t('Locking the system persistently will block other users to edit nhpid data. If you would like to lock the system persistently, press "Lock". The lock has to be released manually by clicking "Release". All users except one who locks the system are unable to save data.'),
  );
  $locker_uid = variable_get(SYSTEM_LOCK_VARIABLE, null);
  //dpm($user);
  $email_link = null;
  if ($locker_uid and $user->uid != $locker_uid){
		$locker = user_load($locker_uid);
		$locker_name = $locker -> name;
		if (user_access('access nhpid email') and $locker-> uid != $user -> uid) $email_link = l("Ask info", "nhpid_email/$locker_uid", array('attributes' => array('target' => '_blank')));
  }
	else{
    $locker_name = 'you';
	}

  $form['lock']['persistent_status'] = array(
    '#type' => 'item',
    '#markup' => t("<span style='text-decoration: blink'><em>The system is locked persistently by $locker_name.</em></span> $email_link"),
    '#access' => $lock_persistent,
  );
  $form['lock']['lock-lock'] = array(
    '#type' => 'submit',
    '#value' => t('Lock'),
    '#access' => !$lock_persistent,
  );
  $form['lock']['release-lock'] = array(
    '#type' => 'submit',
    '#value' => t('Release'),
    '#access' => $lock_persistent,
  );
	if ($lock_temp){
    $form['lock_temp'] = array(
	    '#title' => 'Release temporarily system lock for exporting',
	    '#type' => 'fieldset',
	    '#collapsible' => TRUE,
	    '#collapsed' => false,
			);
	  $form['lock_temp']['description'] = array(
	    '#type' => 'item',
	    '#title' => "",
	    '#description' => t('The system is currently temporarily locked. This means a data exporting process is running, or a exporting process was crashed. If there are no active exporting processes in progress, please release the lock.'),
	  );
    $form['lock_temp']['release-lock-temp'] = array(
    '#type' => 'submit',
    '#value' => t('Release'),
    '#access' => $lock_temp,
  );
	}
  return $form;
}
function nhpid_lock_system_form_submit($form, &$form_state) {
   //dpm($form_state);
   switch ($form_state['clicked_button']['#id']) {
   case 'edit-release-lock':
      # relase lock
      variable_set(SYSTEM_LOCK_VARIABLE, NULL);
      break;
  case 'edit-release-lock-temp':
      # relase lock
      variable_set(DATA_EXPORTING_LOCK_TEMP_VARIABLE, 0);
      break;
    
    case 'edit-lock-lock':
      #  lock system from saving data persistently
      global $user;
      variable_set(SYSTEM_LOCK_VARIABLE, $user -> uid);
      break;
	 }
}
function nhpid_enforce_revision_log_form($form, &$form_state=NULL) {

  $enforce_revision_log = !empty($form_state['values']['nhpid_enforce_revision_log']) ? $form_state['values']['nhpid_enforce_revision_log'] : variable_get('nhpid_enforce_revision_log', 0);
  $enforce_revision_log_warning_message = !empty($form_state['values']['nhpid_enforce_revision_log_warning_message']) ? $form_state['values']['nhpid_enforce_revision_log_warning_message'] : variable_get('nhpid_enforce_revision_log_log_warning_message', "Please enter the revision log message and check the 'Create new revision' checkbox.");
	$trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
  $form['help']=array(
    '#type' => 'item',
    '#markup' => "If enabled, users have to be enter revision log message and check 'Create new revision' for any updates of NHPID data nodes",
  );

  $form['nhpid_enforce_revision_log']=array(
    '#type' => 'checkbox',
    '#title' => "Enforce revision log message",
    '#default_value' => $enforce_revision_log,
  );

  $form['nhpid_enforce_revision_log_warning_message']=array(
    '#type' => 'textarea',
    '#title' => "Warning message",
    '#default_value' => $enforce_revision_log_warning_message,
  );
  $form['save']=array(
    '#type' => 'submit',
    '#value' => t('Save Setting'),
  );
  return $form;
}

function nhpid_enforce_revision_log_form_submit($form, &$form_state) {
  //drupal_set_message(nhpid_api_dump($form_state['values'], 'red', TRUE));
  $nhpid_enforce_revision_log = $form_state['values']['nhpid_enforce_revision_log'];
  $nhpid_enforce_revision_log_warning_message = $form_state['values']['nhpid_enforce_revision_log_warning_message'];
  variable_set('nhpid_enforce_revision_log', $nhpid_enforce_revision_log);
  variable_set('nhpid_enforce_revision_log_warning_message', $nhpid_enforce_revision_log_warning_message);
  $form_state['storage']['values'] = $form_state['values'];
	if($nhpid_enforce_revision_log){
		drupal_set_message("Revision log is enforced.");
	}
  else{
		drupal_set_message("Enforcement of revision log is released.");
	}
}
function nhpid_update_caculated_field_values_form($form, &$form_state=NULL){
  $trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
  $form['help']=array(
    '#type' => 'item',
    '#markup' => "To speed up data exporting, all exported data are pre-calucalted and cached. Normally, the cached datasets are kept updated automatically. However, in case the datasets need to be updated maunualy, this is the tool to do so.",
  );

  $form['mode']=array(
    '#type' => 'select',
    '#title' => t('Select all nodes or nodes changed since last update only'),
    '#options' => array(0=> 'All nodes', 1=>'Nodes changed since last update only',),
    '#default_value' => 0,
  );
  $types = get_all_nhpid_data_node_types();
	$table_select_types = array();
  foreach ($types as $type => $value) {
		$table_select_types[$type]=array('type'=>$value);
  }
  $selected_node_types = !empty($form_state['values']['node_types']) ? $form_state['values']['node_types'] : array();
	$ntype_header=array('type'=>"Node Types");
  $form['node_types'] = array(
    '#type' => 'tableselect',
    '#header' => $ntype_header,
    '#js_select' => TRUE,
    '#title' => t('Select Node types'),
    '#options' => $table_select_types,
    '#default_value' => $selected_node_types,
    '#required' => false,
    '#description' => t('Select one or more node types'),
  );

  $form['update']=array(
    '#type' => 'submit',
    '#value' => t('update'),
  );
  return $form;
}
function nhpid_update_caculated_field_values_form_submit($form, &$form_state) {
  $node_types = $form_state['values']['node_types'];
	$mode = $form_state['values']['mode'];
  $operations = array();
  foreach ($node_types as $key=>$node_type) {
    if ($node_type) $operations[] = array('update_calculated_field_values_batch', array($node_type, $mode));
    //break;
  }
  //drupal_set_message(nhpid_api_dump($operations, 'red', TRUE));
  $batch = array(
    'operations' => $operations,
    'finished' => 'batch_re_gnerate_title_body_finished',
    // We can define custom messages instead of the default ones.
    'title' => t('Update calculated field values'),
    'init_message' => t('Starting.'),
    'progress_message' => t('Processed @current out of @total node types.'),
    'error_message' => t('Updating calulated field values has encountered an error.'),
    'file' => drupal_get_path('module', 'nhpid'). '/nhpid_forms.inc',
  );


  batch_set($batch);
  batch_process();

  $form_state['storage']['values'] = $form_state['values'];
}
function update_calculated_field_values_batch($node_type, $mode, &$context) {
  $sql = "SELECT nid FROM {node} WHERE type=:type order by nid desc";
  $result = db_query($sql, array(':type' => $node_type));
  $sql_count = "SELECT count(nid) FROM {node} WHERE type=:type order by nid desc";
  $count = db_query($sql_count, array(':type' => $node_type))->fetchColumn(0);
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = $count;
  }
  nhpid_api_save_all_calculated_field_values(array($node_type), $mode);
  
  $context['message'] = check_plain("$node_type: $count nodes");

   if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    //$context['finished'] = ($context['sandbox']['progress'] >= $context['sandbox']['max']);
  }


}
function theme_nhpid_excel_field_mapping_form_wrapper($variables) {
	//$header = array();
	$header = array('', 'Drupal Field Name', 'Excel Column Name', 'Excel Column Order', );
	$element = $variables['element'];

	//drupal_debug($element);
	$rows=array();
	foreach(element_children($element) as $field_name){
		$node_type = $element[$field_name]['#parents'][0];
		$element[$field_name]['weight']['#attributes']['class'] = array($node_type . '-excel-column-order-weight');
		if (strstr($field_name, 'field_')){
			//drupal_debug($key);
			//drupal_debug($val);
			$excel_field_name=drupal_render($element[$field_name]['excel_field_name']);
			//$excel_field_order=drupal_render($element[$field_name]['excel_field_order']);
			$drupal_field_name=drupal_render($element[$field_name]['drupal_field_name']);
			$weight=drupal_render($element[$field_name]['weight']);				
			$rows[] = array(
				'data'=>array(
					array('class' => array('excel-column-cross')),
					$drupal_field_name, $excel_field_name,$weight,
				),
				'class' => array('draggable'),
			);
		}
	
	}

	//drupal_debug($rows);
	
  $output = theme('table', array('header' => $header, 'rows' => $rows,  'caption' => Null,'colgroups' => Null,'sticky' => True,'empty' => '','attributes' => array('id' => $node_type .'-excel-column-order')));
  //$output .= drupal_render_children($element);
  //drupal_debug($output);
  drupal_add_tabledrag($node_type .'-excel-column-order', 'order', 'sibling', $node_type .'-excel-column-order-weight');
  return $output;
}

function theme_nhpid_field_length_limit_form_wrapper($variables) {
	$header = array('Drupal Field Name', 'Length Limit', );
	$element = $variables['element'];
	//drupal_debug($element);
	$rows=array();
	$output = '';
	
	foreach(element_children($element) as $field_name){
		//drupal_debug($field_name);
		if (strstr($field_name, 'field_')){
			$length_limit=render($element[$field_name]);	
			//drupal_debug($length_limit);
			//drupal_debug($element[$field_name]);
			$rows[] = array(
				'data'=>array(
					$field_name, $length_limit,
				),
			);
		}
	
		
	}
	$output = theme('table', array('header' => $header, 'rows' => $rows,  'caption' => Null,'colgroups' => Null,'sticky' => True,'empty' => '','attributes' => array()));

	return $output;
}

function theme_nhpid_referred_field_form_wrapper($variables) {
	$types = get_all_nhpid_data_node_types();
	$header = array('Referred Type', 'Referred Field', );
	$element = $variables['element'];
	//drupal_debug($element);
	$rows=array();
	foreach(element_children($element) as $node_type){
		//drupal_debug($node_type);
		if (isset($types[$node_type])){
			$node_type_title=$element[$node_type]['#title'];
			unset($element[$node_type]['#title']);
			$referred_field=drupal_render($element[$node_type]);				
			$rows[] = array(
				'data'=>array(
					$node_type_title, $referred_field,
				),
			);
		}
	
	}

	//drupal_debug($rows);
	
  $output = theme('table', array('header' => $header, 'rows' => $rows,  'caption' => Null,'colgroups' => Null,'sticky' => True,'empty' => '','attributes' => array()));
  //$output .= drupal_render_children($element);
  return $output;
}

