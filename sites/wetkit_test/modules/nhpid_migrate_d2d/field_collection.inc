<?php
/**
 * @file
 * Base class for migrating field collection into Drupal.
 */
 abstract class FCMigration extends DrupalMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
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
  public function map_field_reference(&$row, $field_name){
	if (property_exists($row, "$field_name")){
		$legacy_nids=$row->{"$field_name"};
		if (!empty($legacy_nids)){
			if(is_array($legacy_nids)){
				$target_ids= array();
				foreach($legacy_nids as $legacy_nid){
					$target_ids[] = $this->get_new_nid($legacy_nid);
				}
			}
			else{
				$target_ids = $this->get_new_nid($legacy_nids);
			}
			$row->{$field_name}=$target_ids;
		}
	}
  }
	public function map_mono_dependency_field_reference(&$row, $field_name){
	//print_r($row);
	if (property_exists($row, $field_name)){
		$old_codes=$row->$field_name;
		$target_ids= array();
		if (!empty($old_codes)){
			if(is_array($old_codes)){
				foreach($old_codes as $old_code){
					$code_parts=preg_split('/-/',$old_code);
					$text=$code_parts[0];
					$legacy_nid=$code_parts[1];
					$target_ids[] = $text . '-' . $this->get_new_nid($legacy_nid);
				}
			}
			else{
				$code_parts=preg_split('/-/',$old_codes);
				$text=$code_parts[0];
				$legacy_nid=$code_parts[1];
				$new_nid=$this->get_new_nid(trim($legacy_nid));
				$target_ids = $text . '-' . $new_nid;
			}
			$row->{$field_name}=$target_ids;
		}
	}
	//print_r($row);
  }
  public function getQuery(){
	  return $this -> query();
  }
  public function getSourceIds(){
	  $result=$this->query()->execute();
	  $source_ids= array();
	  while($rc=$result->fetchObject()){
		  $source_ids[]=$rc->item_id;
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
  public function getFailedIds(){
	  $machine_name=$this->getMachineName();
	  $result=Database::getConnection('default')
						 ->select('migrate_map_' . strtolower($machine_name), 'm')
						 ->fields('m')
						 ->isNull('destid1')
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
 
 */

class NHPIDFCMigration extends FCMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
	//print_r($arguments);
    $this->description = t('field_notes migration from old D7.');
	$this->destination_type = $arguments['destination_type'];
    $this->source_type = $arguments['source_type'];
	$field_instances = field_info_instances('field_collection_item', $arguments['destination_type']);
	$this->dependencies = $arguments['dependencies'];
	$fields = array();
	foreach($field_instances as $field_name => $info){
		if (! in_array($field_name, array('field_legacy_nid', 'field_legacy_item_id'))){
			$fields[$field_name] = $info['label'];
		}
	}
	
	$this -> destination_fields=$fields;
	//print_r($fields);
    $this->sourceFields += array(
      'item_id' => t('Item Id'),
      'revision_id' => t('Revision ID'),  
      'field_name' => t('Host field name'),
      'archived' => t('Archived'),
	  'host_entity_id' => 'Host entity ID',
    );

	foreach($this -> destination_fields as $field_name => $label){
		$this->sourceFields += array($field_name =>$label);
		$this->addFieldMapping($field_name, $field_name);
	}
	
	$this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL,
      $this->sourceOptions);
    $this->destination = new MigrateDestinationFieldCollection(
      $arguments['destination_type'],
      array('host_entity_type' => 'node')
    );

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'item_id' => array(
        'type' => 'int',
        'not null' => true,
        ),
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );

    
	$this->addFieldMapping('host_entity_id', 'host_entity_id');
	//$this->addFieldMapping('field_legacy_nid', 'nid') ->description('We have a common field to save the D6 nid');
	$this->addFieldMapping('field_legacy_item_id', 'item_id') ->description('We have a common field to save the D6 nid');
	    
  }
  /**
   * Query for basic node fields from Drupal 7.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
		->select('field_collection_item', 'c')
		->condition('field_name', $this->source_type);
	
	$query->fields('c', array('item_id', 'revision_id', 'field_name', 'archived'));
	//print_r($query->execute()->rowCount());
	//print_r($query->__toString());
    return $query;
  }
  
  public function prepareRow($row) {
    //print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	// field values
	foreach($this -> destination_fields as $field_name => $label){
		$legacy_field_config = Database::getConnection('legacy', $this->sourceConnection)
                 ->select('field_config', 'c')
                 ->fields('c', array('field_name', 'data', 'module'))
				 ->condition('field_name', $field_name)
                 ->execute()
                 ->fetchObject();
		$module = $legacy_field_config->module;
		$data = unserialize($legacy_field_config->data);
		if($module == 'entityreference') {
			$storage_field=$field_name . '_entity_id';
		}
		elseif($module == 'field_reference') {
			$storage_field=$data['storage']['details']['sql']['FIELD_LOAD_CURRENT']['field_data_' . $field_name]['entity_id'];
		}
		else{
			$storage_field=$data['storage']['details']['sql']['FIELD_LOAD_CURRENT']['field_data_' . $field_name]['value'];
		}
		
		$result=Database::getConnection('default', $this->sourceConnection)
		->select('field_data_' . $field_name, $field_name)
		->fields($field_name, array($storage_field, 'entity_id'))
		->condition('entity_id', $row->item_id)
		->execute();
		while($record = $result->fetchObject()) {
       		$row->$field_name[]=$record->$storage_field;
		}
		
	}
	
	// Mapping field collection item id
	$old_field_collection_field_table = 'field_data_' . $this->source_type;
	$legacy_host_entity_row = Database::getConnection('default', $this->sourceConnection)
                 ->select($old_field_collection_field_table, 'c')
                 ->fields('c', array('entity_id', 'delta', $this->source_type .'_value'))
				 ->condition($this->source_type .'_value', $row->item_id)
                 ->execute()
                 ->fetchObject();
	if($legacy_host_entity_row){
		$legacy_entity_id = $legacy_host_entity_row -> entity_id;
		//print_r($legacy_entity_id );
		$new_host_entity_row = Database::getConnection('default')
			 ->select('field_data_field_legacy_nid', 'c')
			 ->fields('c', array('entity_id', 'field_legacy_nid_value'))
			 ->condition('field_legacy_nid_value', $legacy_entity_id)
			 ->execute()
			 ->fetchObject();
		//print_r($new_host_entity_row );
		$row->host_entity_id = $new_host_entity_row->entity_id;
	}
	else{
		print_r ('No host entity id is found for'  . $row->item_id . "\n");
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
		if (in_array($field_name, $dependency_fields)){
			$this->map_mono_dependency_field_reference($row, $field_name);
		}
	}
	
	//print_r($row);
	print_r($row->host_entity_id . ':'. $row->item_id . " is migrated \n");
	return True;
  }
  public function completeRollback($entity_ids) {
    //parent::completeRollback();
    // Code to execute after an entity has been rolled back.
	//print_r($entity_ids);
	$table = 'field_data_' . $this->destination_type;
	db_delete($table)
	->condition($this->destination_type . '_value', $entity_ids, '=')
	->execute();
  }
 
  public function complete_($entity, stdClass $row){
	  //print_r($entity);
	  //print_r($row);
	  // author uid
	if ($entity->item_id){
		// change item_id in host node
			$wrapper = entity_metadata_wrapper('node', node_load($row->host_entity_id));
			if (get_class($wrapper -> {$this->destination_type}) =='EntityDrupalWrapper') {
				$wrapper -> {$this->destination_type}=$entity->item_id;
			}
			else{
				$wrapper -> {$this->destination_type}[]=$entity->item_id;
			}
			//$wrapper->save();
	}
  }
}
