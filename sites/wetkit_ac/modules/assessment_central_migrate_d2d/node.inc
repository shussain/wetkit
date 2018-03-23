<?php

/**
 * Common mappings for the TPD node migrations.
 */
abstract class ACNodeMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
	$this->row_counter = 0;
	$this->row_counter_cutoff = 100;

    $this->addFieldMapping('field_legacy_nid', 'nid')
         ->description('We have a common field to save the D6 nid');
	//$this->addFieldMapping('uid', 'uid');
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
	print_r($entity->title . " is migrated \n");
	// Run garbage collector to further reduce memory.
	$this->row_counter ++;
	if($this->row_counter>$this->row_counter_cutoff){
		$this->row_counter = 0;
		gc_collect_cycles();
		//print_r('GC run\n');
	}
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
  public function get_new_nhpid_ingredient_entity_id($ingredent_name_e){
	$entity_row = Database::getConnection('default')
                 ->select('field_data_field_authorized_name_e', 'c')
                 ->fields('c', array('entity_id', 'field_authorized_name_e_value'))
				 ->condition('bundle', 'nhpid_ingredient')
				 ->condition('field_authorized_name_e_value', $ingredent_name_e)
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
 * Link type mappings and handling.
 */
class ACLinkTypeMigration extends ACNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    $this->sourceFields['field_code'] = 'Code';
	$this->sourceFields['field_description'] = 'Code Description';
	$this->sourceFields['field_workflow'] = 'Workflow';

    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_description', 'field_description');
	$this->addFieldMapping('field_workflow', 'workflow_node');
	
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

    $workflow_row = Database::getConnection('legacy', $this->sourceConnection)
                 ->select('workflow_node', 'wd')
                 ->fields('wd', array('nid', 'sid', 'uid', 'stamp'))
				 ->condition('nid', $row->nid)
                 ->execute()
                 ->fetchObject();
	//print_r($workflow_row);

    if ($workflow_row ) {
       $row->workflow_node = array($workflow_row->sid);
    }
    else {
      $this->saveMessage(t('No workflow_node data for node !nid', array('!nid' => $nid)));
    }
	$row->title = $row->field_code_name[0];
	//print_r($row);
	return True;
  }
  
}

/**
 * Note type mappings and handling.
 */
class ACNoteTypeMigration extends ACNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    $this->sourceFields['field_code'] = 'Code';
	$this->sourceFields['field_description'] = 'Code Description';
	$this->sourceFields['field_workflow'] = 'Workflow';

    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_description', 'field_description');
	$this->addFieldMapping('field_workflow', 'workflow_node');
  }
   public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $workflow_row = Database::getConnection('legacy', $this->sourceConnection)
                 ->select('workflow_node', 'wd')
                 ->fields('wd', array('nid', 'sid', 'uid', 'stamp'))
				 ->condition('nid', $row->nid)
                 ->execute()
                 ->fetchObject();
	
    if ($workflow_row ) {
       $row->workflow_node = array($workflow_row->sid);
    }
    else {
      $this->saveMessage(t('No workflow_node data for node !nid', array('!nid' => $nid)));
    }
	$row->title = $row->field_code_name[0];

	return True;
  }
}

/**
 * PCI type mappings and handling.
 */
class ACPCITypeMigration extends ACNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    $this->sourceFields['field_code'] = 'Code';
	$this->sourceFields['field_description'] = 'Code Description';
	$this->sourceFields['field_workflow'] = 'Workflow';

    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_description', 'field_description');
	$this->addFieldMapping('field_workflow', 'workflow_node');
  }
   public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $workflow_row = Database::getConnection('legacy', $this->sourceConnection)
                 ->select('workflow_node', 'wd')
                 ->fields('wd', array('nid', 'sid', 'uid', 'stamp'))
				 ->condition('nid', $row->nid)
                 ->execute()
                 ->fetchObject();
	
    if ($workflow_row ) {
       $row->workflow_node = array($workflow_row->sid);
    }
    else {
      $this->saveMessage(t('No workflow_node data for node !nid', array('!nid' => $nid)));
    }
	$row->title = $row->field_code_name[0];

	return True;
  }
}

/**
 * NHPID Ingredient mappings and handling.
 */
class ACNHPIDIngredientMigration extends ACNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
   
    parent::__construct($arguments);

    $this->addFieldMapping('field_ingred_id', 'field_ingred_id');
    $this->addFieldMapping('field_authorized_name_e', 'field_authorized_name_e');
	$this->addFieldMapping('field_authorized_name_f', 'field_authorized_name_f');
	$this->addFieldMapping('field_ingredspec_class_name', 'field_ingredspec_class_name');
	$this->addFieldMapping('field_workflow', 'workflow_node');
  }
   public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $workflow_row = Database::getConnection('legacy', $this->sourceConnection)
                 ->select('workflow_node', 'wd')
                 ->fields('wd', array('nid', 'sid', 'uid', 'stamp'))
				 ->condition('nid', $row->nid)
                 ->execute()
                 ->fetchObject();
	
    if ($workflow_row ) {
       $row->workflow_node = array($workflow_row->sid);
    }
    else {
      $this->saveMessage(t('No workflow_node data for node !nid', array('!nid' => $nid)));
    }
	$row->title = $row->field_code_name[0];

	return True;
  }
}
/**
 * Combo mappings and handling.
 */
class ACComboMigration extends ACNodeMigration {
  public function __construct(array $arguments) {
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_combo_name', 'field_combo_name');
    $this->addFieldMapping('field_combo_nhpid_name', 'field_combo_nhpid_name');
    $this->addFieldMapping('field_linked_combos', 'field_linked_combos');
	//$this->addFieldMapping('field_pci', 'field_pci');
	//$this->addFieldMapping('field_notes', 'field_notes');
	$this->addFieldMapping('field_export_history', 'field_export_history');
	$this->addFieldMapping('field_workflow', 'workflow_node');
  }
   public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	//print_r($row->field_combo_nhpid_name);
	// workflow node to workflow field
    $workflow_row = Database::getConnection('legacy', $this->sourceConnection)
                 ->select('workflow_node', 'wd')
                 ->fields('wd', array('nid', 'sid', 'uid', 'stamp'))
				 ->condition('nid', $row->nid)
                 ->execute()
                 ->fetchObject();
	
    if ($workflow_row ) {
       $row->workflow_node = array($workflow_row->sid);
    }
    else {
      $this->saveMessage(t('No workflow_node data for node !nid', array('!nid' => $nid)));
    }
	
	// entity reference target_ids. In legacy setting, this field values are the english authorized names. We should map it to entity id of type NHPID Ingredient
	// field_combo_nhpid_name
	$ingredient_name_e = $row -> field_combo_nhpid_name;
	$target_ids = array();
	foreach($ingredient_name_e as $ingredient_name){
		$target_id = $this->get_new_nhpid_ingredient_entity_id($ingredient_name);
		if ($target_id ){
			$target_ids[]=$target_id;
		}
		else{
			$this->saveMessage(t('No target id found for NHPID name !name', array('!name' => $ingredient_name)));
		}
	}
	$row->field_combo_nhpid_name = $target_ids;
	//print_r($row->field_combo_nhpid_name);
	//print_r($row->{'field_current_tp_status:entity_id'});
			
	return True;
  }
}

/**
 * Combo mappings and handling. Handleing the field field_linked_combos
 */
class ACComboMigration2 extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    
    parent::__construct($arguments);

    $this->addFieldMapping('nid', 'nid')->sourceMigration('Combo_4');
	$this->addFieldMapping('field_linked_combos', 'field_linked_combos');
	//$this->addFieldMapping('field_combo_name', 'field_combo_name');
	$this->systemOfRecord = Migration::DESTINATION;
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
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	//print_r($row->nid);
	//print_r($row->field_linked_combos);
	$legacy_target_ids = $row->field_linked_combos;
	$new_target_ids = array();
	if ($legacy_target_ids){
		foreach($legacy_target_ids as $legacy_target_id){
			$new_target_id = $this->get_new_nid($legacy_target_id);
			if ($new_target_id){
				$new_target_ids[]=$new_target_id;
			}
			else{
				$message = t('Node :nid updated failed: linked combo for :legacy_target_id cannot be found', array(':nid'=> $row->nid, ':legacy_target_id'=>$legacy_target_id));
				$this->saveMessage($message);
			}
		}
		$row->field_linked_combos = $new_target_ids;
	}
		
	//print_r($row->nid);
	return True;
  }
}

/**
 * Mi mappings and handling.
 */
class ACMIMigration extends ACNodeMigration {
  public function __construct(array $arguments) {
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_mi_nhpid_name', 'field_mi_nhpid_name');
    $this->addFieldMapping('field_nhpid_synonyms', 'field_nhpid_synonyms');
    $this->addFieldMapping('field_cnf_usda', 'field_cnf_usda');
	$this->addFieldMapping('field_cnf_canada_id', 'cnf_canada_id');
	$this->addFieldMapping('field_nhpid_url', 'field_nhpid_url');
	$this->addFieldMapping('field_nhpid_id', 'field_linked_combos');
	$this->addFieldMapping('field_tag', 'field_tag');
	$this->addFieldMapping('field_mi_folder', 'field_mi_folder');
	//$this->addFieldMapping('field_pci', 'field_pci');
	//$this->addFieldMapping('field_notes', 'field_notes');
	$this->addFieldMapping('field_export_history', 'field_export_history');
	$this->addFieldMapping('field_workflow', 'workflow_node');
  }
   public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	//print_r($row->field_mi_nhpid_name);
	// workflow node to workflow field
    $workflow_row = Database::getConnection('legacy', $this->sourceConnection)
                 ->select('workflow_node', 'wd')
                 ->fields('wd', array('nid', 'sid', 'uid', 'stamp'))
				 ->condition('nid', $row->nid)
                 ->execute()
                 ->fetchObject();
	
    if ($workflow_row ) {
       $row->workflow_node = array($workflow_row->sid);
    }
    else {
      $this->saveMessage(t('No workflow_node data for node !nid', array('!nid' => $nid)));
    }
	
	// entity reference target_ids. In legacy setting, this field values are the english authorized names. We should map it to entity id of type NHPID Ingredient
	// field_mi_nhpid_name
	$ingredient_name_e = $row -> field_mi_nhpid_name;
	$target_ids = array();
	foreach($ingredient_name_e as $ingredient_name){
		$target_id = $this->get_new_nhpid_ingredient_entity_id($ingredient_name);
		if ($target_id ){
			$target_ids[]=$target_id;
		}
		else{
			$this->saveMessage(t('No target id found for NHPID name !name', array('!name' => $ingredient_name)));
		}
	}
	$row->field_mi_nhpid_name = $target_ids;
	//print_r($row->field_mi_nhpid_name);
	//print_r($row->{'field_current_tp_status:entity_id'});
	
	/**
	* field_cnf_canada_id, this field is added to the vew version of MI content types. Since the data in old ac databses are saved in field field_cnf_usda as 'Code: 170', 'Food codes: 2441, 2516', 'Food code: 6661 (juice), 1667 (fruit)', the ids have to extracted. 
	**/
	$field_cnf_usda=$row->field_cnf_usda;
	if($field_cnf_usda){
		foreach($field_cnf_usda as $item){
			if(!valid_url($item,true)){
				preg_match_all('!\d+!', $item, $matches);
				foreach($matches[0] as $id){
					$row->cnf_canada_id[]=$id;
				}
				unset($row->field_cnf_usda);
				unset($row->{'field_cnf_usda:language'});
			}
		}
	}
	//print_r($row);
			
	return True;
  }
}