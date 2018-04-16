<?php

/**
 * Common mappings for the NHPID DMS node migrations.
 */
abstract class NHPIDNodeMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
	$this->row_counter = 0;
	$this->row_counter_cutoff = 100;
	
	$this->destination_type = $arguments['destination_type'];
    $this->source_type = $arguments['source_type'];
	$field_instances = field_info_instances('node', $arguments['destination_type']);
	if (isset($arguments['dependencies'])){
		$this->dependencies = $arguments['dependencies'];
	}

	$fields = array();
	
	foreach($field_instances as $field_name => $info){
		if (in_array($field_name, array('body'))){
			continue;
		}
		if ($info['widget']['module']=='field_collection'){
			continue;
		}
		$fields[$field_name] = $info['label'];
	}
	//print_r($fields);
	$this -> destination_fields=$fields;
	foreach($this -> destination_fields as $field_name => $label){
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
		elseif ($field_name == 'field_legacy_nid'){
			$this->addFieldMapping('field_legacy_nid', 'nid');
		}
		elseif ($field_name == 'field_preparation_code'){
			$this->addFieldMapping('field_preparation_code', 'preparation_code');
		}
		else{
			$this->addFieldMapping($field_name, $field_name);
		}
	}
   
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
	// Run garbage collector to further reduce memory.
	$this->row_counter ++;
	if($this->row_counter>$this->row_counter_cutoff){
		$this->row_counter = 0;
		gc_collect_cycles();
		//print_r('GC run\n');
	}
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
	
	//print_r($row);
	foreach($this -> destination_fields as $field_name => $label){
		$field=field_info_field($field_name);
		//mapping entity reference fields target id
		if ($field['type'] == 'entityreference'){
			$this->map_field_reference($row, $field_name);
		}
		//workflow
		if ($field_name == 'field_workflow'){
			$sid = $this->get_sid($row->nid);
			if ($sid){
				$row->workflow_node = array($sid);
			}
			else {
			  $this->saveMessage(t('No workflow_node data for node !nid', array('!nid' => $nid)));
			}
		}
		// parent space
		if ($field_name == 'field_parent_space'){
			$des = $this->getDestination();
			$type = $des->getBundle();
			$instance = field_info_instance('node', $field_name, $type);
			if ($instance){
				$default = $instance['default_value'][0]['target_id'];
				$row->parent_space=array($default);
			}
		}
		// Its ids. Change the original chili its ids to AO nid.
		if ($field_name == 'field_its_ids'){
			$this->set_ao_its_nid($row);
		}
		// Some legacy vales of field_fema_number is not numeric.
		if ($field_name == 'field_fema_number'){
			if ($row->field_fema_number){
				foreach($row->field_fema_number as &$item){
					if (!is_numeric($item)){
						$item=NULL;
					}
				}
			}
		}
		// move individual preparation field to field_preparation_code
		$preparation_codes=get_all_values_of_a_field_by_node_type('code_organism_preparation', 'field_code');
		$field_name_root = str_replace('field_', '', $field_name);
		if (array_search(strtoupper($field_name_root), $preparation_codes)){
			if ($row->$field_name[0]=='X'){
				$preparation_code_nid=$this->get_new_code_entity_id(strtoupper($field_name_root), 'code_organism_preparation');
				$row->preparation_code[]=$preparation_code_nid;
			}
		}
		
	}

	//$methods = get_class_methods($this);
	//print_r($row);
	return True;
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
  
  public function set_ao_its_nid(&$row){
	$its_url = variable_get('nhpid_its_url', '');
	$chili_its_ids_title = $row->{'field_its_ids:title'};
	$chili_its_ids = $row->field_its_ids;
	$chili_its_ids_attributes = $row->{'field_its_ids:attributes'};
	$chili_its_ids_language = $row->{'field_its_ids:language'};
	//print_r($chili_its_ids_title);
	$oa_its_nids = array();
	$oa_its_nids_title = array();
	$oa_its_nids_attributes = array();
	$oa_its_nids_language = array();
	if ($chili_its_ids_title){
		for($i=0; $i<count($chili_its_ids_title); $i++){
			$chili_its_id_title=$chili_its_ids_title[$i];
			$its_row = Database::getConnection('default', $this->sourceConnection)
						 ->select('field_data_field_chili_id', 'c')
						 ->fields('c')
						 ->condition('field_chili_id_value', $chili_its_id_title)
						 ->execute();
			if($its_row->rowCount()>0){
				while($rc=$its_row->fetchObject())
					
					$entity_id = $rc -> entity_id;
					$oa_its_nids_title[] = $entity_id;
					$url = str_replace('#',$entity_id,$its_url);
					$oa_its_nids[]= $url;
					//print_r($its_url);
					//print_r($entity_id);
					//print_r($url);
					$oa_its_nids_attributes[]=$chili_its_ids_attributes[$i];
					$oa_its_nids_language[]=$chili_its_ids_language[$i];
				}
			else{
				$oa_its_nids_title[] = $chili_its_ids_title[$i];
				$url = str_replace('#',$chili_its_ids_title[$i],$its_url);
				$oa_its_nids[]= $url;
				$oa_its_nids_attributes[]=$chili_its_ids_attributes[$i];
				$oa_its_nids_language[]=$chili_its_ids_language[$i];
			}
		}
		
		$row->{'field_its_ids:title'}=$oa_its_nids_title;
		$row->field_its_ids=$oa_its_nids;
		$row->{'field_its_ids:attributes'}=$oa_its_nids_attributes;
		$row->{'field_its_ids:language'}=$oa_its_nids_language;
	}
  }
  public function getQuery(){
	  return $this -> query();
  }
  public function getSourceIds(){
	  $result=$this->query()->execute();
	  $source_ids= array();
	  while($rc=$result->fetchObject()){
		  $source_ids[]=$rc->nid;
	  }
	  return $source_ids;
  }
  public function getProcessedIds(){
	  $machine_name=$this->getMachineName();
	  $result=Database::getConnection('default')
						 ->select('migrate_map_' . strtolower($machine_name), 'm')
						 ->fields('m')
						 ->execute();
	  $source_ids= array();
	  while($rc=$result->fetchObject()){
		  $source_ids[]=$rc->sourceid1;
	  }
	  return $source_ids;
  }
  public function getUnprocessedIds(){
	  return array_diff($this->getSourceIds(), $this->getProcessedIds());
  }
  public function getNeedsUpdateIds(){
	  $machine_name=$this->getMachineName();
	  $result=Database::getConnection('default')
						 ->select('migrate_map_' . strtolower($machine_name), 'm')
						 ->fields('m')
						 ->condition('needs_update', 1)
						 ->execute();
	  $source_ids= array();
	  while($rc=$result->fetchObject()){
		  $source_ids[]=$rc->sourceid1;
	  }
	  return $source_ids;
  }
  public function getUpdatedIds(){
	  $machine_name=$this->getMachineName();
	  $result=Database::getConnection('default')
						 ->select('migrate_map_' . strtolower($machine_name), 'm')
						 ->fields('m')
						 ->condition('needs_update', 0)
						 ->execute();
	  $source_ids= array();
	  while($rc=$result->fetchObject()){
		  $source_ids[]=$rc->sourceid1;
	  }
	  return $source_ids;
  }
  public function getUnprocessedAndNeedsUpdateIds(){
	  return array_unique(array_merge($this->getUnprocessedIds() + $this->getNeedsUpdateIds()));
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
  }  
}