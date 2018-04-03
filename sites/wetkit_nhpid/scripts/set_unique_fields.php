<?php

/* sets unique rules for some unique fields within content type */
/*** fields which are set to unique within a bundle ***/
//nhpid dms
$unique_fields=array('field_code'=>'code', 'field_ingredient_name'=>'ingname_e', 'field_ingredient_name_f'=>'ingname_f', 'field_title'=>'f_title', 'field_name_e'=>'name_e','field_name_f'=>'name_f','field_org_group_name_e'=>'orggname_e','field_org_group_name_f'=>'orggname_f');

//assessment centtral
//$unique_fields=array('field_code'=>'code', 'field_ingredient_name'=>'ingname', 'field_authorized_name_e'=>'authname_e', 'field_authorized_name_f'=>'authname_f','field_ingred_id' => 'ingredid', 'field_mi_nhpid_name' =>'miingname');

//tpd
//$unique_fields=array('field_code'=>'code', 'field_code_name'=>'codename','field_id'=>'id', 'field_company_name'=>'companyname', );

//legal opinion
//$unique_fields=array('field_name_picklist'=>'name', 'field_code_name'=>'codename','field_id'=>'id', 'field_company_name'=>'companyname', );

/*** detecting if module field_validation enabled  ***/

if (!module_exists('field_validation')){
	dpm('Not processed. Please enable module field_validation');
	return;
}
// delet all existing field_unique_rules
field_validation_ui_delete_all_unique_rules();

$template=(object)array(
   'ruleid' => '1',
   'rulename' => 'Code Unit Code Unique',
   'name' => 'code_unit_code_unique',
   'field_name' => 'field_code',
   'col' => 'value',
   'entity_type' => 'node',
   'bundle' => 'code_unit',
   'validator' => 'field_validation_unique_validator',
   'settings' => 
  array (
    'data' => 'bundle',
    'per_user' => 0,
    'bypass' => 0,
    'roles' => 
    array (
      1 => 0,
      2 => 0,
      19 => 0,
      20 => 0,
      4 => 0,
      21 => 0,
      22 => 0,
      23 => 0,
      24 => 0,
      25 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => 
    array (
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  ),
   'error_message' => '[field-name] has to be unique within [bundle]. The value [value] is used by [existing-entity-link].',
);
//user roles
$user_roles = array_fill_keys (array_keys(user_roles()), 0);
$template->settings['roles']=$user_roles;

foreach($unique_fields as $unique_field=>$short_cut){
	$field = field_info_field($unique_field);
	//col
	$field=field_info_field($unique_field);
	$col = '';
	switch($field['type']){
		case 'entityreference':
		$col='target_id';
		break;
		case 'text':
		case 'number_integer':
		case 'datestamp':
		case 'text_lomg':
		case 'text_with_summary':
		$col='value';
		break;
		case 'taxonomy_term_reference':
		$col='tid';
		break;
		case 'link_field':
		$col='url';
		break;
		default:
		dpm($unique_field . ' cannot be set to unuiqe.');
		continue;
	}
	foreach($field['bundles'] as $entity_type => $type_bundles){
		foreach($type_bundles as $bundle){
			$name=substr($bundle .'_' . $short_cut  . 'u', -32);
			
			$setting=field_validation_ui_get_rule_by_name($name);
			//dpm($setting);
			if(!$setting){
				$setting = clone($template);
				$setting->ruleid=NULL;
			}
			$setting->rulename=$bundle .'_' . $unique_field  .'_' . 'unique';
			$setting->name=$name;
			$setting->entity_type=$entity_type;
			$setting->field_name=$unique_field;
			$setting->bundle=$bundle;
			$setting->settings=serialize($template->settings);
			$setting->error_message=$template->error_message;
			$setting->validator=$template->validator;
			
			$setting->col=$col;
			dpm($setting);
			dpm(strlen($setting->name));
			db_merge('field_validation_rule')
			->key(array('ruleid'=>$setting->ruleid))
			->fields((array)$setting)
			->execute();
		}
	}
	
}


function field_validation_ui_get_rule($ruleid) {
  $result = db_query("SELECT * FROM {field_validation_rule} WHERE ruleid = :ruleid", array(':ruleid' => $ruleid), array('fetch' => PDO::FETCH_OBJ));
  $rule = $result->fetchObject();
  if($rule){
	$rule->settings = unserialize($rule->settings);
  }
  return $rule;
}

function field_validation_ui_get_rule_by_name($name) {
  $result = db_query("SELECT * FROM {field_validation_rule} WHERE name = :name", array(':name' => $name), array('fetch' => PDO::FETCH_OBJ));
  $rule = $result->fetchObject();
  if($rule){
	$rule->settings = unserialize($rule->settings);
  }
  return $rule;
}

function field_validation_ui_delete_all_unique_rules() {
  $num_deleted = db_delete('field_validation_rule')
  ->condition('validator', 'field_validation_unique_validator')
  ->execute();
  dpm("$num_deleted rules have been deleted.");
}