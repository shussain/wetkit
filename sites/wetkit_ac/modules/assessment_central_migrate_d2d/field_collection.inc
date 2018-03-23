<?php
/**
 * @file
 * Base class for migrating field collection into Drupal.
 */
 abstract class ACFCMigration extends DrupalMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
	$this->row_counter = 0;
	$this->row_counter_cutoff = 100;
	
  }
	public function complete($entity, $row) {
		//print_r($entity);
		//print_r($row);
		//print_r('complete');
		$field_name = $entity->field_name;
		$item_id = $entity->item_id;
		$revision_id = $entity->revision_id;
		$host_entity_id = $row->host_entity_id;
		//print_r ("field_name:  $field_name, item_id: , $item_id, revision_id:  $revision_id, host_entity_id:  $host_entity_id\n");
		
		Database::getConnection('default')
		->update("field_data_$field_name")
		->fields(array($field_name . '_value' => $item_id, $field_name . '_revision_id' => $revision_id))
		->condition('entity_id', $host_entity_id, '=')
		->condition($field_name . '_value', $item_id, '=')
		->execute();
		print_r ("finished itemid $item_id of host entity $host_entity_id\n");
		// Run garbage collector to further reduce memory.
		$this->row_counter ++;
		if($this->row_counter>$this->row_counter_cutoff){
			$this->row_counter = 0;
			gc_collect_cycles();
			//print_r('GC run\n');
		}
  
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

class ACNotesMigration extends ACFCMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('field_notes migration from old D7.');
    $this->dependencies = array('Combo_4', 'MI_4');

    $this->sourceFields += array(
      'item_id' => t('Item Id'),
      //'revision_id' => t('Revision ID'),  
      'field_name' => t('Host field name'),
      'archived' => t('Archived'),
	  'host_entity_id' => 'Host entity ID',
	  'field_note_type' => "Node type",
	  'field_link_type' => 'Link type',
	  'field_address' => 'Address',
	  'field_note' => 'Note',
	  'field_warning' => 'Warning',
	    
    );
	
	$this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL,
      $this->sourceOptions);
	$this->destination_type='field_notes';
    $this->destination = new MigrateDestinationFieldCollection(
      $this->destination_type,
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

    
	$this->addFieldMapping('host_entity_id', 'host_entity_id');//->sourceMigration('TradingPartner');
	$this->addFieldMapping('field_note_type', 'field_note_type');
	$this->addFieldMapping('field_link_type', 'field_link_type');
	$this->addFieldMapping('field_address', 'field_address');
	$this->addFieldMapping('field_note', 'field_note');
	$this->addFieldMapping('field_warning', 'field_warning');
	    
  }
  /**
   * Query for basic node fields from Drupal 7.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
		->select('field_collection_item', 'c')
		->condition('field_name', 'field_notes');
	
	//$query->fields('c', array('item_id', 'revision_id', 'field_name', 'archived'));
	$query->fields('c', array('item_id', 'field_name', 'archived'));
		
    return $query;
  }
  
  public function prepareRow($row) {
    
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	//print_r($row);
	// field values
	$fields = array('field_note_type', 'field_link_type','field_address','field_note', 'field_warning' );
	foreach($fields as $field_name){
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
	$legacy_host_entity_row = Database::getConnection('legancy', $this->sourceConnection)
                 ->select('field_data_field_notes', 'c')
                 ->fields('c', array('entity_id', 'field_notes_value'))
				 ->condition('bundle', array('combo', 'mi'), 'IN')
				 ->condition('field_notes_value', $row->item_id)
                 ->execute()
                 ->fetchObject();
		if($legacy_host_entity_row){
			$legacy_entity_id = $legacy_host_entity_row -> entity_id;
			$new_host_entity_row = Database::getConnection('default')
                 ->select('field_data_field_legacy_nid', 'c')
                 ->fields('c', array('entity_id', 'field_legacy_nid_value'))
				 ->condition('bundle', array('combo', 'mi'), 'IN')
				 ->condition('field_legacy_nid_value', $legacy_entity_id)
                 ->execute()
                 ->fetchObject();
			$row->host_entity_id = $new_host_entity_row->entity_id;
		}
		else{
			print_r ('No host entity id is found for'  . $row->item_id . "\n");
		}
	//mapping entity reference field_note_type target id
	// entity reference target_ids. In legacy setting, this field values are the english authorized names. We should map it to entity id of type NHPID Ingredient
	// field_note_type
	$codes = $row -> field_note_type ? $row -> field_note_type:array();
	$code_type = 'note_type';
	//print_r($codes);
	foreach ($codes as $index =>$code){
		$target_id = $this->get_new_code_entity_id($code, $code_type);
		if ($target_id ){
			$row->field_note_type[$index] = $target_id;
		}
		else{
			$this->saveMessage(t('No target id found for code !name', array('!name' => $code)));
		}
	}
	
	// field_link_type
	$codes = $row -> field_link_type ? $row -> field_link_type:array();
	$code_type = 'link_type';
	foreach ($codes as $index =>$code){
		$target_id = $this->get_new_code_entity_id($code, $code_type);
		if ($target_id ){
			$row->field_link_type[$index] = $target_id;
		}
		else{
			$this->saveMessage(t('No target id found for code !name', array('!name' => $code)));
		}
	}
	
	
	//print_r($row);
	print_r($row->item_id . " is migrated \n");
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
	// Run garbage collector to further reduce memory.
	gc_collect_cycles();
  }
}
class ACPCIMigration extends ACFCMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('field_notes migration from old D7.');
    $this->dependencies = array('Combo_4', 'MI_4');

    $this->sourceFields += array(
      'item_id' => t('Item Id'),
      //'revision_id' => t('Revision ID'),  
      'field_name' => t('Host field name'),
      'archived' => t('Archived'),
	  'host_entity_id' => 'Host entity ID',
	  'field_pci_type' => "PCI type",
	  'field_link_type' => 'Link type',
	  'field_address' => 'Address',
	  'field_note' => 'Note',
	    
    );
	
	$this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL,
      $this->sourceOptions);
	$this->destination_type='field_pci';
    $this->destination = new MigrateDestinationFieldCollection(
      $this->destination_type,
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

    
	$this->addFieldMapping('host_entity_id', 'host_entity_id');//->sourceMigration('TradingPartner');
	$this->addFieldMapping('field_pci_type', 'field_pci_type');
	$this->addFieldMapping('field_link_type', 'field_link_type');
	$this->addFieldMapping('field_address', 'field_address');
	$this->addFieldMapping('field_note', 'field_note');
	    
  }
  /**
   * Query for basic node fields from Drupal 7.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    $query = Database::getConnection('legancy', $this->sourceConnection)
		->select('field_collection_item', 'c')
		->condition('field_name', 'field_pci');
		
	//$query->fields('c', array('item_id', 'revision_id', 'field_name', 'archived'));
	$query->fields('c', array('item_id', 'field_name', 'archived'));
	return $query;
  }
  
  public function prepareRow($row) {
    
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	//print_r($row);
	// field values
	$fields = array('field_pci_type', 'field_link_type','field_address','field_note');
	foreach($fields as $field_name){
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
	$legacy_host_entity_row = Database::getConnection('legacy', $this->sourceConnection)
                 ->select('field_data_field_pci', 'c')
                 ->fields('c', array('entity_id', 'field_pci_value'))
				 ->condition('bundle', array('combo', 'mi'), 'IN')
				 ->condition('field_pci_value', $row->item_id)
                 ->execute()
                 ->fetchObject();
		if($legacy_host_entity_row){
			$legacy_entity_id = $legacy_host_entity_row -> entity_id;
			$new_host_entity_row = Database::getConnection('default')
                 ->select('field_data_field_legacy_nid', 'c')
                 ->fields('c', array('entity_id', 'field_legacy_nid_value'))
				 ->condition('bundle', array('combo', 'mi'), 'IN')
				 ->condition('field_legacy_nid_value', $legacy_entity_id)
                 ->execute()
                 ->fetchObject();
			$row->host_entity_id = $new_host_entity_row->entity_id;
		}
		else{
			print_r ('No host entity id is found for'  . $row->item_id . "\n");
		}
	//mapping entity reference field_note_type target id
	// entity reference target_ids. In legacy setting, this field values are the english authorized names. We should map it to entity id of type NHPID Ingredient
	// field_pci_type
	$codes = $row -> field_pci_type ? $row -> field_pci_type:array();
	//print_r($code);
	$code_type = 'pci_type';
	foreach ($codes as $index =>$code){
		$target_id = $this->get_new_code_entity_id($code, $code_type);
		if ($target_id ){
			$row->field_pci_type[$index] = $target_id;
			//print_r($target_id);
		}
		else{
			$this->saveMessage(t('No target id found for code !name', array('!name' => $code)));
		}
	}
	
	// field_link_type
	$codes = $row -> field_link_type ? $row -> field_link_type:array();
	//print_r($codes);
	$code_type = 'link_type';
	foreach ($codes as $index =>$code){
		$target_id = $this->get_new_code_entity_id($code, $code_type);
		if ($target_id ){
			$row->field_link_type[$index] = $target_id;
			//print_r($target_id);
		}
		else{
			$this->saveMessage(t('No target id found for code !name', array('!name' => $code)));
		}
	}
	
	//print_r($row);
	print_r($row->item_id . " is migrated \n");
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
	//Run garbage collector to further reduce memory.
	gc_collect_cycles();
  }
}

