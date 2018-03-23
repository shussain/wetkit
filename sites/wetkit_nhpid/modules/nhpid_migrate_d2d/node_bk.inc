<?php

/**
 * Common mappings for the TPD node migrations.
 */
abstract class NHPIDNodeMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_legacy_nid', 'nid')
         ->description('We have a common field to save the D6 nid');
	$this->addFieldMapping('field_its_ids', 'field_its_ids');
	$this->addFieldMapping('field_its_ids:title', 'field_its_ids:title');
	$this->addFieldMapping('field_its_ids:attributes', 'field_its_ids:attributes');

	$this->addFieldMapping('field_workflow', 'workflow_node');
	$this->addFieldMapping('field_parent_space', 'parent_space');
	//$this->addFieldMapping('uid', 'uid');
  }
   /**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
   
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$sid = $this->get_sid($row->nid);

	if ($sid){
		$row->workflow_node = array($sid);
	}

    else {
      $this->saveMessage(t('No workflow_node data for node !nid', array('!nid' => $nid)));
    }
	
	// parent space
	$des = $this->getDestination();
	$type = $des->getBundle();
	//$methods = get_class_methods($this);
	
	$field = 'field_parent_space';
	$instance = field_info_instance('node', $field, $type);
	
	if ($instance){
		$default = $instance['default_value'][0]['target_id'];
		$row->parent_space=array($default);
	}
	
	//print_r($row);
	return True;
  }
  public function complete($entity, stdClass $row){
	  //print_r($entity);
	  //print_r($row);
	  // author uid
	if ($row->uid){
		//print_r ('legacy_uid: ' . $entity->uid . "\n");
		$entity->uid=$row->uid;
		//print_r ('new_uid: ' . $entity->uid . "\n");
	}
	print_r($row->title . " is migrated \n");
  }
  public function get_new_user_uid($legacy_uid){
	 $legacy_user_row = Database::getConnection('legacy', $this->sourceConnection)
                 ->select('users', 'u')
                 ->fields('u', array('uid', 'name'))
				 ->condition('uid', $legacy_uid)
                 ->execute()
                 ->fetchObject();
	if ($legacy_user_row ) {
       $user_name = $user_row->name;
	   
	   $user_row = Database::getConnection('default')
                 ->select('users', 'u')
                 ->fields('u', array('uid', 'name'))
				 ->condition('name', $user_name)
                 ->execute()
                 ->fetchObject();
		if($user_row){
			$new_uid = $user_row -> uid;
			return $$new_uid;
		}
    }
	return 1;
  }
  public function get_new_code_entity_id($code, $code_type){
	$entity_row = Database::getConnection('default')
                 ->select('field_data_field_code', 'c')
                 ->fields('c', array('entity_id', 'field_code_value'))
				 ->condition('bundle', $code_type)
				 ->condition('field_code_value', $code)
                 ->execute()
                 ->fetchObject();
	if($entity_row){
		$entity_id = $entity_row -> entity_id;
		return $entity_id;
	}
	return null;	
  }
 
  public function get_new_nid($legacy_nid){
	$entity_row = Database::getConnection('default')
                 ->select('field_data_field_legacy_nid', 'c')
                 ->fields('c', array('entity_id', 'field_legacy_nid_value'))
				 ->condition('field_legacy_nid_value', $legacy_nid)
                 ->execute()
                 ->fetchObject();
	if($entity_row){
		$entity_id = $entity_row -> entity_id;
		return $entity_id;
	}  
	return null;
  }
  public function get_sid($legacy_nid){
	$workflow_row = Database::getConnection('legacy', $this->sourceConnection)
                 ->select('workflow_node', 'wd')
                 ->fields('wd', array('nid', 'sid', 'uid', 'stamp'))
				 ->condition('nid', $legacy_nid)
                 ->execute()
                 ->fetchObject();
	//print_r ($legency_nid);
	//print_r ($workflow_row);
	if ($workflow_row ){
		return $workflow_row->sid;
	}
	
	return null;
  }
  
  public function map_field_reference(&$row, $field_name){
	if (property_exists($row, "$field_name:entity_id")){
		$legacy_nids=$row->{"$field_name:entity_id"};
		$target_ids= array();
		if (!empty($legacy_nids)){
			foreach($legacy_nids as $legacy_nid){
				$target_ids[] = $this->get_new_nid($legacy_nid);
			}
			$row->{$field_name}=$target_ids;
		}
	}
  }
  public function map_mon_dependency_field_reference(&$row, $field_name){
	if (property_exists($row, "$field_name:entity_id")){
		//$old_code=$row->$field_name:entity_id;
		$target_ids= array();
		if (!empty($legacy_nids)){
			foreach($legacy_nids as $legacy_nid){
				$target_ids[] = $this->get_new_nid($legacy_nid);
			}
			$row->{$field_name}=$target_ids;
		}
	}
  }

}



/**
 * all type mappings and handling.
 */
class AllTypes extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->destination_type = $arguments['destination_type'];
    $this->source_type = $arguments['source_type'];
	$field_instances = field_info_instances('node', $arguments['destination_type']);
	$this->dependencies = $arguments['dependencies'];
	$fields = array();
	foreach($field_instances as $field_name => $info){
		if (! in_array($field_name, array('field_legacy_nid'))){
			continue;
		}
		if ($info['widget']['module']=='field_collection'){
			continue;
		}
		$fields[$field_name] = $info['label'];
	}
	
	$this -> destination_fields=$fields;
	

	foreach($this -> destination_fields as $field_name => $label){
		$this->addFieldMapping($field_name, $field_name);
		if ($field_name == 'field_its_ids'){
			$this->addFieldMapping('field_its_ids', 'field_its_ids');
			$this->addFieldMapping('field_its_ids:title', 'field_its_ids:title');
			$this->addFieldMapping('field_its_ids:attributes', 'field_its_ids:attributes');
		}
		elseif ($field_name == 'field_workflow'){
			$this->addFieldMapping('field_workflow', 'workflow_node');
		}
		elseif ($field_name == 'field_parent_space'){
			$this->addFieldMapping('field_parent_space', 'parent_space');
		}
	}
  } 
  public function prepareRow($row) {
    //print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	
	//mapping entity reference fields target id
	foreach($this -> destination_fields as $field_name => $label){
		$field=field_info_field($field_name);
		if ($field['type'] == 'entityreference'){
			$this->map_field_reference($row, $field_name);
		}
		//print_r($field_name);
	}
	//mapping mono dependency fields fields target id
	$dependency_fields = array('field_dose_dependency','field_duration_dependency', 'field_for_use_dependency','field_risk_dependency','field_use_dependency',);
	foreach($this -> destination_fields as $field_name => $label){
		$field=field_info_field($field_name);
		if (in_array($field_name, $dependency_fields){
			//$this->map_field_reference($row, $field_name);
		}
		//print_r($field_name);
	}
	
	print_r($row);
	return True;
  }
}


/**
 *Code application type mappings and handling.
 */
class CodeApplicationType extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_app_type_e', 'field_app_type_e');
	$this->addFieldMapping('field_app_type_f', 'field_app_type_f');

  } 
}

/**
 *CodeWithNameComment mappings and handling.
 */
class CodeWithNameComment extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_name_e', 'field_name_e');
	$this->addFieldMapping('field_name_f', 'field_name_f');
	$this->addFieldMapping('field_comment_e', 'field_comment_e');
	$this->addFieldMapping('field_comment_f', 'field_comment_f');

  } 
}

/**
 *CodeWithDescriptionComment mappings and handling.
 */
class CodeWithDescriptionComment extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
	$this->addFieldMapping('field_description', 'field_description');
    $this->addFieldMapping('field_description_e', 'field_description_e');
	$this->addFieldMapping('field_description_f', 'field_description_f');
	$this->addFieldMapping('field_comment_e', 'field_comment_e');
	$this->addFieldMapping('field_comment_f', 'field_comment_f');

  } 
}

/**
 *CodeCommentTerm mappings and handling.
 */
class CodeCommentTerm extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_common_term_e', 'field_common_term_e');
	$this->addFieldMapping('field_common_term_f', 'field_common_term_f');
	$this->addFieldMapping('field_common_term_type', 'field_common_term_type');
	$this->addFieldMapping('field_common_term_type_f', 'field_common_term_type_f');
	
	
  } 
}

/**
 *CodeWithName mappings and handling.
 */
class CodeWithName extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_name_e', 'field_name_e');
	$this->addFieldMapping('field_name_f', 'field_name_f');

  } 
}

/**
 *CodeWithNameDescription mappings and handling.
 */
class CodeWithNameDescription extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_name_e', 'field_name_e');
	$this->addFieldMapping('field_name_f', 'field_name_f');
	$this->addFieldMapping('field_description_e', 'field_description_e');
	$this->addFieldMapping('field_description_f', 'field_description_f');

  } 
}
/**
 *CodeJournal mappings and handling.
 */
class CodeJournal extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_title', 'field_title');
  } 
}
/**
 *CodeOrganismTypeGroup mappings and handling.
 */
class CodeOrganismTypeGroup extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_country_flag', 'field_country_flag');
    $this->addFieldMapping('field_name_e', 'field_name_e');
	$this->addFieldMapping('field_name_f', 'field_name_f');
	$this->addFieldMapping('field_description_e', 'field_description_e');
	$this->addFieldMapping('field_description_f', 'field_description_f');
	$this->addFieldMapping('field_geographical_flag', 'field_geographical_flag');
	
  } 
}
/**
 *CodeOtherJournal mappings and handling.
 */
class CodeOtherJournal extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_comment', 'field_comment');
    $this->addFieldMapping('field_issn', 'field_issn');
	$this->addFieldMapping('field_journal_title', 'field_journal_title');
	
  } 
}
/**
 *CodePreparationGroup mappings and handling.
 */
class CodePreparationGroup extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
	$this->addFieldMapping('field_name_e', 'field_name_e');
	$this->addFieldMapping('field_name_f', 'field_name_f');
    $this->addFieldMapping('field_dec', 'field_dec');
	$this->addFieldMapping('field_decon', 'field_decon');
	$this->addFieldMapping('field_deconst', 'field_deconst');
	$this->addFieldMapping('field_decst', 'field_decst');
	$this->addFieldMapping('field_dist', 'field_dist');
	$this->addFieldMapping('field_distcon', 'field_distcon');
	$this->addFieldMapping('field_dry', 'field_dry');
	$this->addFieldMapping('field_dryda', 'field_dryda');
	$this->addFieldMapping('field_dryst', 'field_dryst');
	$this->addFieldMapping('field_exdry', 'field_exdry');
	$this->addFieldMapping('field_exdryst', 'field_exdryst');
	$this->addFieldMapping('field_exliq', 'field_exliq');
	$this->addFieldMapping('field_exliqst', 'field_exliqst');
	$this->addFieldMapping('field_flext', 'field_flext');
	$this->addFieldMapping('field_flextst', 'field_flextst');
	$this->addFieldMapping('field_fresh', 'field_fresh');
	$this->addFieldMapping('field_infsn', 'field_infsn');
	$this->addFieldMapping('field_infsnst', 'field_infsnst');

	$this->addFieldMapping('field_ju', 'field_ju');
	$this->addFieldMapping('field_jucpw', 'field_jucpw');
	$this->addFieldMapping('field_jucpwst', 'field_jucpwst');
	$this->addFieldMapping('field_just', 'field_just');
	$this->addFieldMapping('field_oiles', 'field_oiles');
	$this->addFieldMapping('field_oilfx', 'field_oilfx');
	$this->addFieldMapping('field_oilfxst', 'field_oilfxst');
	$this->addFieldMapping('field_oilin', 'field_oilin');
	$this->addFieldMapping('field_pow', 'field_pow');
	$this->addFieldMapping('field_powst', 'field_powst');
	$this->addFieldMapping('field_tinct', 'field_tinct');
	$this->addFieldMapping('field_tinct5_10', 'field_tinct5_10');
	$this->addFieldMapping('field_tinct_10', 'field_tinct_10');
	$this->addFieldMapping('field_tinctst', 'field_tinctst');
	$this->addFieldMapping('field_organism_type_group', 'field_organism_type_group');
  }

	public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_name='field_organism_type_group';
	$this->map_field_reference($row, $field_name);
	//print_r($row);
	return True;
  }    
}
/**
 *CodeProvinceState mappings and handling.
 */
class CodeProvinceState extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
	$this->addFieldMapping('field_country_code', 'field_country_code');
	$this->addFieldMapping('field_province_state_e', 'field_province_state_e');
	$this->addFieldMapping('field_province_state_f', 'field_province_state_f');
	
  } 
}
/**
 *CodeStandardOrGrade mappings and handling.
 */
class CodeStandardOrGrade extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_hm_standard_or_grade', 'field_hm_standard_or_grade');
	$this->addFieldMapping('field_min_dilution_amount', 'field_min_dilution_amount');
	$this->addFieldMapping('field_standard_or_grade', 'field_standard_or_grade');
	
  } 
}
/**
 *CodeChemicalSubclass mappings and handling.
 */
class CodeChemicalSubclass extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_description_e', 'field_description_e');
	$this->addFieldMapping('field_description_f', 'field_description_f');
	$this->addFieldMapping('field_comment_e', 'field_comment_e');
	$this->addFieldMapping('field_comment_f', 'field_comment_f');
	$this->addFieldMapping('field_chemical_class', 'field_chemical_class');
	
  }
	/**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
   
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_name='field_chemical_class';
	$this->map_field_reference($row, $field_name);
	//print_r($row);
	return True;
  }  
}
/**
 *CodeDosageForm mappings and handling.
 */
class CodeDosageForm extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
	$this->addFieldMapping('field_description_e', 'field_description_e');
	$this->addFieldMapping('field_description_f', 'field_description_f');
	$this->addFieldMapping('field_comment_e', 'field_comment_e');
	$this->addFieldMapping('field_comment_f', 'field_comment_f');
	$this->addFieldMapping('field_allowed_ingredient_units', 'field_allowed_ingredient_units');
	$this->addFieldMapping('field_synonyms_e', 'field_synonyms_e');
	$this->addFieldMapping('field_synonyms_f', 'field_synonyms_f');
	$this->addFieldMapping('field_valid_for_compendial', 'field_valid_for_compendial');
	$this->addFieldMapping('field_dosage_form_unit', 'field_dosage_form_unit');
	$this->addFieldMapping('field_new_dosage_form_unit', 'field_new_dosage_form_unit');
	
  }
	/**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
   
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_name='field_dosage_form_unit';
	$this->map_field_reference($row, $field_name);
	$field_name='field_new_dosage_form_unit';
	$this->map_field_reference($row, $field_name);
	return True;
  }  
}
/**
 *CodeIngredientCategory mappings and handling.
 */
class CodeIngredientCategory extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_description_e', 'field_description_e');
	$this->addFieldMapping('field_description_f', 'field_description_f');
	$this->addFieldMapping('field_comment', 'field_comment');
	$this->addFieldMapping('field_ingredient_class', 'field_ingredient_class');
	
  }
	/**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
   
 public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_name='field_ingredient_class';
	$this->map_field_reference($row, $field_name);
	
	return True;
  }  
}

/**
 *CodeNmiPurpose mappings and handling.
 */
class CodeNmiPurpose extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_description_e', 'field_description_e');
	$this->addFieldMapping('field_description_f', 'field_description_f');
	$this->addFieldMapping('field_comment_e', 'field_comment_e');
	$this->addFieldMapping('field_comment_f', 'field_comment_f');
	$this->addFieldMapping('field_artificial_or_natural', 'field_artificial_or_natural');
	$this->addFieldMapping('field_roa_restriction', 'field_roa_restriction');
	
  }
	/**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
   
 public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_name='field_roa_restriction';
	$this->map_field_reference($row, $field_name);
	
	return True;
  }  
}

/**
 *CodeOrganismPreparation and handling.
 */
class CodeOrganismPreparation extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_description_e', 'field_description_e');
	$this->addFieldMapping('field_description_f', 'field_description_f');
	$this->addFieldMapping('field_name_e', 'field_name_e');
	$this->addFieldMapping('field_name_f', 'field_name_f');
	$this->addFieldMapping('field_all_solvents', 'field_all_solvents');
	$this->addFieldMapping('field_extract', 'field_extract');
	$this->addFieldMapping('field_ratio_type', 'field_ratio_type');
	$this->addFieldMapping('field_standardized', 'field_standardized');
	$this->addFieldMapping('field_restricted_solvents', 'field_restricted_solvents');
	
  }
	/**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
   
 public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_name='field_restricted_solvents';
	$this->map_field_reference($row, $field_name);
	
	return True;
  }  
}

/**
 *CodeOrganismType and handling.
 */
class CodeOrganismType extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_description_e', 'field_description_e');
	$this->addFieldMapping('field_description_f', 'field_description_f');
	$this->addFieldMapping('field_comment_e', 'field_comment_e');
	$this->addFieldMapping('field_comment_f', 'field_comment_f');
	$this->addFieldMapping('field_organism_type_group', 'field_organism_type_group');
	
  }
	/**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
   
 public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_name='field_organism_type_group';
	$this->map_field_reference($row, $field_name);
	
	return True;
  }  
}

/**
 *CodeReference and handling.
 */
class CodeReference extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_book_chapter_edition', 'field_book_chapter_edition');
    $this->addFieldMapping('field_book_chapter_editor', 'field_book_chapter_editor');
	$this->addFieldMapping('field_book_chapter_page_numbe', 'field_book_chapter_page_numbe');
	$this->addFieldMapping('field_book_chapter_place', 'field_book_chapter_place');
	$this->addFieldMapping('field_book_chapter_publisher_e', 'field_book_chapter_publisher_e');
	$this->addFieldMapping('field_book_chapter_publisher_f', 'field_book_chapter_publisher_f');
	$this->addFieldMapping('field_book_chapter_volume', 'field_book_chapter_volume');
	$this->addFieldMapping('field_book_title_e', 'field_book_title_e');
	$this->addFieldMapping('field_book_title_f', 'field_book_title_f');
	$this->addFieldMapping('field_citation_format_e', 'field_citation_format_e');
	$this->addFieldMapping('field_citation_format_f', 'field_citation_format_f');
	$this->addFieldMapping('field_citation_full_text_e', 'field_citation_full_text_e');
	$this->addFieldMapping('field_citation_full_text_f', 'field_citation_full_text_f');
	$this->addFieldMapping('field_code', 'field_code');
	$this->addFieldMapping('field_comment', 'field_comment');
	$this->addFieldMapping('field_journal_article_page_num ', 'field_journal_article_page_num ');
	$this->addFieldMapping('field_journal_article_part ', 'field_journal_article_part ');
	$this->addFieldMapping('field_journal_article_volume ', 'field_journal_article_volume ');
	$this->addFieldMapping('field_journal_f', 'field_journal_f');
	$this->addFieldMapping('field_report_number', 'field_report_number');
	$this->addFieldMapping('field_report_place', 'field_report_place');
	$this->addFieldMapping('field_report_publisher_e ', 'field_report_publisher_e ');
	$this->addFieldMapping('field_report_publisher_f', 'field_report_publisher_f');
	$this->addFieldMapping('field_url_e', 'field_url_e');
	$this->addFieldMapping('field_url_f', 'field_url_f');
	$this->addFieldMapping('field_website_title_e ', 'field_website_title_e ');
	$this->addFieldMapping('field_website_title_f', 'field_website_title_f');
	$this->addFieldMapping('field_work_author_e', 'field_work_author_e');
	$this->addFieldMapping('field_work_author_f', 'field_work_author_f');
	$this->addFieldMapping('field_work_title_e', 'field_work_title_e');
	$this->addFieldMapping('field_work_title_f', 'field_work_title_f');
	$this->addFieldMapping('field_work_year', 'field_work_year');
	$this->addFieldMapping('field_website_access_date', 'field_website_access_date');
	$this->addFieldMapping('field_work_date', 'field_work_date');
	$this->addFieldMapping('field_citation_type', 'field_citation_type');
	$this->addFieldMapping('field_journal_e', 'field_journal_e');
	
  }
	/**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
   
 public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_name='field_citation_type';
	$this->map_field_reference($row, $field_name);
	$field_name='field_journal_e';
	$this->map_field_reference($row, $field_name);
	
	return True;
  }  
}
/**
 *CodeSolvent and handling.
 */
class CodeSolvent extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_name_e', 'field_name_e');
	$this->addFieldMapping('field_name_f', 'field_name_f');
	$this->addFieldMapping('field_ich_class', 'field_ich_class');
	
  }
	/**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
   
 public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_name='field_ich_class';
	$this->map_field_reference($row, $field_name);
	
	return True;
  }  
}

/**
 *CodeUnit and handling.
 */
class CodeUnit extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_description_e', 'field_description_e');
	$this->addFieldMapping('field_description_f', 'field_description_f');
	$this->addFieldMapping('field_comment', 'field_comment');
	$this->addFieldMapping('field_equivalent', 'field_equivalent');
	$this->addFieldMapping('field_preferred', 'field_preferred');
	$this->addFieldMapping('field_ratio_to_base', 'field_ratio_to_base');
	$this->addFieldMapping('field_unit_type_code', 'field_unit_type_code');
	
  }
	/**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
   
 public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_name='field_unit_type_code';
	$this->map_field_reference($row, $field_name);
	
	return True;
  }  
}

/**
 *CodeICHClasses and handling.
 */
class CodeICHClasses extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_description_e', 'field_description_e');
	$this->addFieldMapping('field_description_f', 'field_description_f');
	$this->addFieldMapping('field_allowable_test_method', 'field_allowable_test_method');
	$this->addFieldMapping('field_residual_limit', 'field_residual_limit');
	$this->addFieldMapping('field_name_e', 'field_name_e');
	$this->addFieldMapping('field_name_f', 'field_name_f');
	$this->addFieldMapping('field_unit', 'field_unit');
	
  }
	/**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
   
 public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_name='field_unit';
	$this->map_field_reference($row, $field_name);
	
	return True;
  }  
}

/**
 *CodeROA and handling.
 */
class CodeROA extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_description_e', 'field_description_e');
	$this->addFieldMapping('field_description_f', 'field_description_f');
	$this->addFieldMapping('field_comment_e', 'field_comment_e');
	$this->addFieldMapping('field_comment_f', 'field_comment_f');
	$this->addFieldMapping('field_no_fixed_limits', 'field_no_fixed_limits');
	$this->addFieldMapping('field_sterile', 'field_sterile');
	$this->addFieldMapping('field_dosage_forms', 'field_dosage_forms');
  }
	/**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
   
 public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_name='field_dosage_forms';
	$this->map_field_reference($row, $field_name);
	
	return True;
  }  
}

/**
 *CodeSubpopulation and handling.
 */
class CodeSubpopulation extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_description_e', 'field_description_e');
	$this->addFieldMapping('field_description_f', 'field_description_f');
	$this->addFieldMapping('field_comment_e', 'field_comment_e');
	$this->addFieldMapping('field_comment_f', 'field_comment_f');
	$this->addFieldMapping('field_name_e', 'field_name_e');
	$this->addFieldMapping('field_name_f', 'field_name_f');
	$this->addFieldMapping('field_exclusion_e', 'field_exclusion_e');
	$this->addFieldMapping('field_exclusion_f', 'field_exclusion_f');
	$this->addFieldMapping('field_inclusion_e', 'field_inclusion_e');
	$this->addFieldMapping('field_inclusion_f', 'field_inclusion_f');
	$this->addFieldMapping('field_max_age', 'field_max_age');
	$this->addFieldMapping('field_min_age', 'field_min_age');
	$this->addFieldMapping('field_preferred', 'field_preferred');
	$this->addFieldMapping('field_age_unit', 'field_age_unit');
  }
	/**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
   
 public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_name='field_age_unit';
	$this->map_field_reference($row, $field_name);
	
	return True;
  }  
}

/**
 *CodeDosageFormGroup and handling.
 */
class CodeDosageFormGroup extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_name_e', 'field_name_e');
	$this->addFieldMapping('field_name_f', 'field_name_f');
	$this->addFieldMapping('field_dosage_form_codes', 'field_dosage_form_codes');
  }
	/**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
   
 public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_name='field_dosage_form_codes';
	$this->map_field_reference($row, $field_name);
	
	return True;
  }  
}

/**
 *HerbalHCNAndNaming and handling, Including herbal_hcn,naming_chemical,naming_organism, naming_org_substance,naming_protein,nonnhp_chemical,nonnhp_organism
 */
class HerbalHCNAndNaming extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);
	$this->addFieldMapping('field_additional_detail_e', 'field_additional_detail_e');
	$this->addFieldMapping('field_additional_detail_f', 'field_additional_detail_f');
	$this->addFieldMapping('field_chem_single_group', 'field_chem_single_group');
    $this->addFieldMapping('field_comment', 'field_comment');
	$this->addFieldMapping('field_fc_cas_number', 'field_fc_cas_number');
    $this->addFieldMapping('field_country', 'field_country');
	$this->addFieldMapping('field_family', 'field_family');
	$this->addFieldMapping('field_fc_common_name', 'field_fc_common_name');
	$this->addFieldMapping('field_fc_proper_name', 'field_fc_proper_name');
	$this->addFieldMapping('field_fc_synonym_e', 'field_fc_synonym_e');
	$this->addFieldMapping('field_fc_synonym_', 'field_fc_synonym_');
	$this->addFieldMapping('field_fc_taxon', 'field_fc_taxon');
	$this->addFieldMapping('field_genus', 'field_genus');
	$this->addFieldMapping('field_formula', 'field_formula');
	$this->addFieldMapping('field_ingredient_name', 'field_ingredient_name');
	$this->addFieldMapping('field_ingredient_name_f', 'field_ingredient_name_f');
	$this->addFieldMapping('field_ingredient_role', 'field_ingredient_role');
	$this->addFieldMapping('field_lower_limit', 'field_lower_limit');
	$this->addFieldMapping('field_non_nhp_rationale_e', 'field_non_nhp_rationale_e');
	$this->addFieldMapping('field_non_nhp_rationale_', 'field_non_nhp_rationale_');
	$this->addFieldMapping('field_old_rationale', 'field_old_rationale');
	$this->addFieldMapping('field_quantity_restriction_on', 'field_quantity_restriction_on');
	$this->addFieldMapping('field_restriction_desc_e', 'field_restriction_desc_e');
	$this->addFieldMapping('field_restriction_desc_f', 'field_restriction_desc_f');
	$this->addFieldMapping('field_species', 'field_species');
	$this->addFieldMapping('field_subspecies', 'field_subspecies');
	$this->addFieldMapping('field_fema_number', 'field_fema_number');
	//refrence fields
	$this->addFieldMapping('field_approved_ingredient_name', 'field_approved_ingredient_name');
	$this->addFieldMapping('field_organism_part', 'field_organism_part');
	$this->addFieldMapping('field_organism_preparation', 'field_organism_preparation');
	$this->addFieldMapping('field_route_of_admin', 'field_route_of_admin');
	$this->addFieldMapping('field_unit', 'field_unit');
	$this->addFieldMapping('field_limitation_ref', 'field_limitation_ref');
	$this->addFieldMapping('field_organism_parent', 'field_organism_parent');
	$this->addFieldMapping('field_name_reference', 'field_name_reference');
	$this->addFieldMapping('field_organism_origin', 'field_organism_origin');
	$this->addFieldMapping('field_ingredient_cat', 'field_ingredient_cat');
	$this->addFieldMapping('field_nhpd_classification', 'field_nhpd_classification');
	$this->addFieldMapping('field_geo_distribution', 'field_geo_distribution');
	$this->addFieldMapping('field_chemical_class', 'field_chemical_class');
	$this->addFieldMapping('field_chem_subclass', 'field_chem_subclass');
	$this->addFieldMapping('field_org_group', 'field_org_group');
	$this->addFieldMapping('field_ref', 'field_ref');
  }
	/**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
   
 public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_approved_ingredient_name','field_route_of_admin','field_unit','field_limitation_ref','field_organism_parent','field_name_reference','field_organism_origin','field_ingredient_cat','field_nhpd_classification','field_geo_distribution','field_organism_part','field_organism_preparation','field_org_group','field_chem_subclass','field_chemical_class','field_ref',);
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	
	return True;
  }  
}
/**
 *NamingOrganismTaxon and handling.
 */
class NamingOrganismTaxon extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_family', 'field_family');
    $this->addFieldMapping('field_genus', 'field_genus');
	$this->addFieldMapping('field_species', 'field_species');
	$this->addFieldMapping('field_subspecies', 'field_subspecies');
  }
  
}
/**
 *NamingOrganismGroup and handling.
 */
class NamingOrganismGroup extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_fc_excluded_item', 'field_fc_excluded_item');
    $this->addFieldMapping('field_fc_included_item', 'field_fc_included_item');
	$this->addFieldMapping('field_org_group_name_e', 'field_org_group_name_e');
	$this->addFieldMapping('field_org_group_name_f', 'field_org_group_name_f');
	$this->addFieldMapping('field_date', 'field_date');
	$this->addFieldMapping('field_name_reference', 'field_name_reference');
  }
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_name_reference',);
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	
	return True;
  }  
}

/**
 *MiNmiSubing, Including mi_chemical, mi_org_substance, mi_protein, nmi_chimical, nmi_org_substance, subing_chemical, subing_org_part, subing_protein
 */
class MiNmiSubing extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);
	
	$this->addFieldMapping('field_monograph_source', 'field_monograph_source');
	$this->addFieldMapping('field_ingredient_role', 'field_ingredient_role');
	$this->addFieldMapping('field_lower_limit', 'field_lower_limit');
	$this->addFieldMapping('field_non_nhp_rationale_e', 'field_non_nhp_rationale_e');
	$this->addFieldMapping('field_non_nhp_rationale_', 'field_non_nhp_rationale_');
	$this->addFieldMapping('field_old_rationale', 'field_old_rationale');
	$this->addFieldMapping('field_quantity_restriction_on', 'field_quantity_restriction_on');
	$this->addFieldMapping('field_restriction_desc_e', 'field_restriction_desc_e');
	$this->addFieldMapping('field_restriction_desc_f', 'field_restriction_desc_f');
	$this->addFieldMapping('field_safety_concern', 'field_safety_concern');
	$this->addFieldMapping('field_upper_limit', 'field_upper_limit');
	$this->addFieldMapping('field_com_functional_cat', 'field_com_functional_cat');
	$this->addFieldMapping('field_date', 'field_date');
	
	//refrence fields
	$this->addFieldMapping('field_approved_ingredient_name', 'field_approved_ingredient_name');
	$this->addFieldMapping('field_organism_part', 'field_organism_part');
	$this->addFieldMapping('field_route_of_admin', 'field_route_of_admin');
	$this->addFieldMapping('field_product_code', 'field_product_code');
	$this->addFieldMapping('field_unit', 'field_unit');
	$this->addFieldMapping('field_limitation_ref', 'field_limitation_ref');
	$this->addFieldMapping('field_nmi_purpose_restriction', 'field_nmi_purpose_restriction');
	$this->addFieldMapping('field_ingredient_cat', 'field_ingredient_cat');
	$this->addFieldMapping('field_nhpd_classification', 'field_nhpd_classification');
	$this->addFieldMapping('field_ref', 'field_ref');
	$this->addFieldMapping('field_other_ref', 'field_other_ref');
	$this->addFieldMapping('field_nmi_purposes', 'field_nmi_purposes');
	$this->addFieldMapping('field_subingredient', 'field_subingredient');
	$this->addFieldMapping('field_chemical_name', 'field_chemical_name');
	$this->addFieldMapping('field_organism_name', 'field_organism_name');
	$this->addFieldMapping('field_dosage_form', 'field_dosage_form');
	$this->addFieldMapping('field_constituent', 'field_constituent');
  }
	/**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
   
 public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_approved_ingredient_name','field_route_of_admin','field_unit','field_limitation_ref','field_ingredient_cat','field_nhpd_classification','field_organism_part','field_ref','field_product_code','field_other_ref','field_nmi_purposes','field_subingredient','field_chemical_name','field_organism_name','field_dosage_form','field_constituent','field_route_of_admin');
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	//print_r($row);
	return True;
  }  
}

/**
 *HomoDilution mappings and handling.
 */
class HomoDilution extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_name_e', 'field_name_e');
	$this->addFieldMapping('field_name_f', 'field_name_f');
	$this->addFieldMapping('field_description_e', 'field_description_e');
	$this->addFieldMapping('field_description_f', 'field_description_f');
	$this->addFieldMapping('field_comment_e', 'field_comment_e');
	$this->addFieldMapping('field_comment_f', 'field_comment_f');
	$this->addFieldMapping('field_diluted', 'field_diluted');
	$this->addFieldMapping('field_ratio_to_base', 'field_ratio_to_base');

  } 
}
/**
 *HomoMI mappings and handling.
 */
class HomoMI extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_aft_required_in_proc_mi', 'field_aft_required_in_proc_mi');
    $this->addFieldMapping('field_atf_required', 'field_atf_required');
	$this->addFieldMapping('field_name_f', 'field_name_f');
	$this->addFieldMapping('field_common_names', 'field_common_names');
	$this->addFieldMapping('field_is_synthetic', 'field_is_synthetic');
	$this->addFieldMapping('field_note', 'field_note');
	$this->addFieldMapping('field_note_e', 'field_note_e');
	$this->addFieldMapping('field_note_f', 'field_note_f');
	$this->addFieldMapping('field_pharm', 'field_pharm');
	$this->addFieldMapping('field_proper_names', 'field_proper_names');
	$this->addFieldMapping('field_quantity', 'field_quantity');
	$this->addFieldMapping('field_simple_common_name_e', 'field_simple_common_name_e');
	$this->addFieldMapping('field_simple_common_name_f', 'field_simple_common_name_f');
	$this->addFieldMapping('field_simple_proper_name_e', 'field_simple_proper_name_e');
	$this->addFieldMapping('field_simple_proper_name_f', 'field_simple_proper_name_f');
	$this->addFieldMapping('field_simple_source_material_e', 'field_simple_source_material_e');
	$this->addFieldMapping('field_simple_source_material_f', 'field_simple_source_material_f');
	$this->addFieldMapping('field_source_material_part', 'field_source_material_part');
	$this->addFieldMapping('field_toxic', 'field_toxic');
	$this->addFieldMapping('field_homo_preparations', 'field_homo_preparations');


  } 
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_homo_preparations');
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	
	return True;
  }  
}

/**
 *TestMethodQuality mappings and handling.
 */
class TestMethodQuality extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_name_e', 'field_name_e');
	$this->addFieldMapping('field_name_f', 'field_name_f');
	$this->addFieldMapping('field_description_e', 'field_description_e');
	$this->addFieldMapping('field_description_f', 'field_description_f');
	$this->addFieldMapping('field_restriction_desc_e', 'field_restriction_desc_e');
	$this->addFieldMapping('field_restriction_desc_f', 'field_restriction_desc_f');
	$this->addFieldMapping('field_subtype_e', 'field_subtype_e');
	$this->addFieldMapping('field_subtype_f', 'field_subtype_f');
	$this->addFieldMapping('field_type_e', 'field_type_e');
	$this->addFieldMapping('field_type_f', 'field_type_f');

  } 
}
/**
 *MonoDirectionForUse mappings and handling.
 */
class MonoDirectionForUse extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_direction_e', 'field_direction_e');
	$this->addFieldMapping('field_direction_f', 'field_direction_f');
	$this->addFieldMapping('field_fc_for_use_dependency', 'field_fc_for_use_dependency');
  } 
}
/**
 *MonoNote mappings and handling.
 */
class MonoNote extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_note_e', 'field_note_e');
	$this->addFieldMapping('field_note_f', 'field_note_f');
  } 
}
/**
 *MonoDuration mappings and handling.
 */
class MonoDuration extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_max_duration', 'field_max_duration');
	$this->addFieldMapping('field_min_duration', 'field_min_duration');
	$this->addFieldMapping('field_statement_e', 'field_statement_e');
	$this->addFieldMapping('field_statement_f', 'field_statement_f');
	$this->addFieldMapping('field_fc_duration_dependency', 'field_fc_duration_dependency');
  } 
}
/**
 *MonoMonographList mappings and handling.
 */
class MonoMonographList extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_new_code', 'field_new_code');
    $this->addFieldMapping('field_new_name', 'field_new_name');
	$this->addFieldMapping('field_note', 'field_note');
	$this->addFieldMapping('field_old_code ', 'field_old_code ');
	$this->addFieldMapping('field_old_name', 'field_old_name');
  } 
}
/**
 *MonoPreparation mappings and handling.
 */
class MonoPreparation extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_max_extraction_ratio', 'field_max_extraction_ratio');
	$this->addFieldMapping('field_min_extraction_ratio', 'field_min_extraction_ratio');
	$this->addFieldMapping('field_mono_preparation', 'field_mono_preparation');
  } 
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_mono_preparation');
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	
	return True;
  }  
}
/**
 *MonoRDAValue mappings and handling.
 */
class MonoRDAValue extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_threshold', 'field_threshold');
	$this->addFieldMapping('field_approved_ingredient_name', 'field_approved_ingredient_name');
	$this->addFieldMapping('field_subpopulation', 'field_subpopulation');
	$this->addFieldMapping('field_unit', 'field_unit');
  } 
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_unit','field_approved_ingredient_name','field_subpopulation');
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	
	return True;
  }  
}
/**
 *MonoRisk mappings and handling.
 */
class MonoRisk extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
	$this->addFieldMapping('field_statement_e', 'field_statement_e');
	$this->addFieldMapping('field_statement_f', 'field_statement_f');
	$this->addFieldMapping('field_fc_risk_dependency', 'field_fc_risk_dependency');
	$this->addFieldMapping('field_risk_type', 'field_risk_type');
  } 
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_risk_type');
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	
	return True;
  }  
}
/**
 *MonoSubingCombo mappings and handling.
 */
class MonoSubingCombo extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
	$this->addFieldMapping('field_max_ratio', 'field_max_ratio');
	$this->addFieldMapping('field_min_ratio', 'field_min_ratio');
	$this->addFieldMapping('field_subingredients', 'field_subingredients');
  } 
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_subingredients');
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	
	return True;
  }  
}
/**
 *MonoDosageFormGroup mappings and handling.
 */
class MonoDosageFormGroup extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_name_e', 'field_name_e');
	$this->addFieldMapping('field_name_f', 'field_name_f');
	$this->addFieldMapping('field_dosage_forms', 'field_dosage_forms');
  } 
  public function prepareRow($row) {
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_dosage_forms');
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	
	return True;
  }  
}
/**
 *MonoROA mappings and handling.
 */
class MonoROA extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
	// reference fields
    $this->addFieldMapping('field_additional_df_citation', 'field_additional_df_citation');
	$this->addFieldMapping('field_additional_dosage_form', 'field_additional_dosage_form');
	$this->addFieldMapping('field_roa', 'field_roa');
	$this->addFieldMapping('field_df_note_code', 'field_df_note_code');
	$this->addFieldMapping('field_mono_citation', 'field_mono_citation');
  } 
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_additional_df_citation','field_additional_dosage_form','field_roa','field_df_note_code','field_mono_citation');
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	
	return True;
  }  
}
/**
 *MonoSubingDose mappings and handling.
 */
class MonoSubingDose extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
	$this->addFieldMapping('field_max_dose', 'field_max_dose');
	$this->addFieldMapping('field_max_frequency', 'field_max_frequency');
	$this->addFieldMapping('field_min_dose', 'field_min_dose');
	$this->addFieldMapping('field_min_frequency', 'field_min_frequency');
	// reference fields
    $this->addFieldMapping('field_dose_type', 'field_dose_type');
	$this->addFieldMapping('field_subingredient', 'field_subingredient');
	$this->addFieldMapping('field_subingredient_comb', 'field_subingredient_comb');
	$this->addFieldMapping('field_dose_unit', 'field_dose_unit');
	$this->addFieldMapping('field_frequency_unit', 'field_frequency_unit');
  } 
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_dose_type','field_subingredient','field_subingredient_comb','field_dose_unit','field_frequency_unit', );
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	
	return True;
  }  
}

/**
 *MonoUse mappings and handling.
 */
class MonoUse extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
	$this->addFieldMapping('field_fc_use_dependency', 'field_fc_use_dependency');
	$this->addFieldMapping('field_long_statement_e', 'ffield_long_statement_e');
	$this->addFieldMapping('field_long_statement_f', 'field_long_statement_f');
	$this->addFieldMapping('field_short_statement_e', 'field_short_statement_e');
	$this->addFieldMapping('field_short_statement_f', 'field_short_statement_f');
	// reference fields
    $this->addFieldMapping('field_use_type', 'field_use_type');
	$this->addFieldMapping('field_mono_citation', 'field_mono_citation');
	$this->addFieldMapping('field_subingredient_comb', 'field_subingredient_comb');
	$this->addFieldMapping('field_rda_code', 'field_rda_code');
  } 
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_use_type','field_mono_citation','field_subingredient_comb','field_rda_code', );
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	
	return True;
  }  
}

/**
 *MonoPhase mappings and handling.
 */
class MonoPhase extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
	$this->addFieldMapping('field_name_e', 'field_name_e');
	$this->addFieldMapping('field_name_f', 'field_name_f');
	$this->addFieldMapping('field_order', 'field_order');
	
	// reference fields
    $this->addFieldMapping('field_mono_doses', 'field_mono_doses');
	$this->addFieldMapping('field_mono_duration', 'field_mono_duration');
	$this->addFieldMapping('field_subingredient_comb', 'field_subingredient_comb');
	$this->addFieldMapping('field_rda_code', 'field_rda_code');
  } 
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_mono_doses','field_mono_duration', 'field_subingredient_comb','field_rda_code', );
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	
	return True;
  }  
}

/**
 *MonoMonograph mappings and handling.
 */
class MonoMonograph extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
	$this->addFieldMapping('field_group_name_e', 'field_group_name_e');
	$this->addFieldMapping('field_group_name_f', 'field_group_name_f');
	$this->addFieldMapping('field_monograph_name_e', 'field_monograph_name_e');
	$this->addFieldMapping('field_monograph_name_f', 'field_monograph_name_f');
	$this->addFieldMapping('field_monograph_status', 'field_monograph_status');
	$this->addFieldMapping('field_monograph_type', 'field_monograph_type');
	$this->addFieldMapping('field_monograph_url_e', 'field_monograph_url_e');
	$this->addFieldMapping('field_monograph_url_f', 'field_monograph_url_f');
	$this->addFieldMapping('field_nmi_note_e', 'field_nmi_note_e');
	$this->addFieldMapping('field_nmi_note_f', 'field_nmi_note_f');
	$this->addFieldMapping('field_note_e', 'field_note_e');
	$this->addFieldMapping('field_note_f', 'field_note_f');
	$this->addFieldMapping('field_risk_note_e', 'field_risk_note_e');
	$this->addFieldMapping('field_risk_note_f', 'field_risk_note_f');
	$this->addFieldMapping('field_specification_e', 'field_specification_e');
	$this->addFieldMapping('field_specification_f', 'field_specification_f');
	$this->addFieldMapping('field_storage_condition_e', 'field_storage_condition_e');
	$this->addFieldMapping('field_storage_condition_f', 'field_storage_condition_f');
	$this->addFieldMapping('field_date', 'field_date');
	
	
	// reference fields
    $this->addFieldMapping('field_mono_roa', 'field_mono_roa');
	$this->addFieldMapping('field_mono_use', 'field_mono_use');
	$this->addFieldMapping('field_subpopulation', 'field_subpopulation');
	$this->addFieldMapping('field_dose_note', 'field_dose_note');
	$this->addFieldMapping('field_mono_duration', 'field_mono_duration');
	$this->addFieldMapping('field_mono_risk', 'field_mono_risk');
	$this->addFieldMapping('field_mono_citation_e', 'field_mono_citation_e');
	$this->addFieldMapping('field_mono_citation_f', 'field_mono_citation_f');
	$this->addFieldMapping('field_reference_reviewed_e', 'field_reference_reviewed_e');
	$this->addFieldMapping('field_reference_reviewed_f', 'field_reference_reviewed_f');
	$this->addFieldMapping('field_monograph_phase', 'field_monograph_phase');

  } 
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_mono_roa','field_mono_use', 'field_subpopulation','field_dose_note','field_mono_duration','field_mono_risk','field_mono_citation_e','field_mono_citation_f','field_reference_reviewed_e','field_reference_reviewed_f','field_monograph_phase',);
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	
	return True;
  }  
}
/**
 *MonoSubingDoseCombo mappings and handling.
 */
class MonoSubingDoseCombo extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
	$this->addFieldMapping('field_subingredient_dose', 'field_subingredient_dose');
  } 
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_subingredient_dose');
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	
	return True;
  }  
}
/**
 *MonoDose mappings and handling.
 */
class MonoDose extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
	$this->addFieldMapping('field_additional_detail_e', 'field_additional_detail_e');
	$this->addFieldMapping('field_additional_detail_f', 'field_additional_detail_f');
	$this->addFieldMapping('field_fc_dose_dependency', 'field_fc_dose_dependency');
	$this->addFieldMapping('field_max_dose', 'field_max_dose');
	$this->addFieldMapping('field_max_frequency', 'field_max_frequency');
	$this->addFieldMapping('field_min_dose', 'field_min_dose');
	$this->addFieldMapping('field_min_frequency', 'field_min_frequency');
	$this->addFieldMapping('field_visible', 'field_visible');
	//reference fields
	$this->addFieldMapping('field_dose_unit', 'field_dose_unit');
	$this->addFieldMapping('field_frequency_unit', 'field_frequency_unit');
	$this->addFieldMapping('field_mono_direction_for_use', 'field_mono_direction_for_use');
	$this->addFieldMapping('field_dose_type', 'field_dose_type');
	$this->addFieldMapping('field_subpopulation', 'field_subpopulation');
	$this->addFieldMapping('field_mono_citation', 'field_mono_citation');
	$this->addFieldMapping('field_mono_subingredient_dose', 'field_mono_subingredient_dose');
  } 
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_dose_unit','field_frequency_unit', 'field_mono_direction_for_use','field_dose_type','field_subpopulation', 'field_mono_subingredient_dose',);
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	
	return True;
  }  
}
/**
 *MonoEntry mappings and handling.
 */
class MonoEntry extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_fc_chem_mn_sc_org_part', 'field_fc_chem_mn_sc_org_part');
	$this->addFieldMapping('field_fc_chem_mon_src_ad_sc_e', 'field_fc_chem_mon_src_ad_sc_e');
	$this->addFieldMapping('field_fc_chem_mon_src_ad_sc_f', 'field_fc_chem_mon_src_ad_sc_f');
	//$this->addFieldMapping('field_fc_chem_mon_src_adt_ing', 'field_fc_chem_mon_src_adt_ing');
	$this->addFieldMapping('field_fc_chem_mon_src_ing', 'field_fc_chem_mon_src_ing');
	$this->addFieldMapping('field_fc_common_name_e', 'field_fc_common_name_e');
	$this->addFieldMapping('field_fc_common_name_f', 'field_fc_common_name_f');
	$this->addFieldMapping('field_fc_org_mon_src_part ', 'field_fc_org_mon_src_part ');
	$this->addFieldMapping('field_fc_proper_name_e', 'field_fc_proper_name_e');
	$this->addFieldMapping('field_fc_proper_name_f', 'field_fc_proper_name_f');
	$this->addFieldMapping('field_fc_subingredient_source', 'field_fc_subingredient_source');
	$this->addFieldMapping('field_source_note_e', 'field_source_note_e');
	$this->addFieldMapping('field_source_note_f', 'field_source_note_f');
	//reference fields
	$this->addFieldMapping('field_approved_ingredient_name', 'field_approved_ingredient_name');
	$this->addFieldMapping('field_mono_code', 'field_mono_code');
	$this->addFieldMapping('field_mono_doses', 'field_mono_doses');
	$this->addFieldMapping('field_preparation_mtd', 'field_preparation_mtd');
  } 
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_approved_ingredient_name', 'field_mono_doses','field_preparation_mtd','field_mono_code');
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	
	return True;
  }  
}
/**
 *MonoDoseCombination mappings and handling.
 */
class MonoDoseCombination extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
	$this->addFieldMapping('field_fc_dose_dependency', 'field_fc_dose_dependency');
	$this->addFieldMapping('field_visible', 'field_visible');
	$this->addFieldMapping('field_mono_combination_dose', 'field_mono_combination_dose');
  } 
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$field_names=array('field_mono_combination_dose');
	foreach($field_names as $field_name){
		$this->map_field_reference($row, $field_name);
	}
	
	return True;
  }  
}