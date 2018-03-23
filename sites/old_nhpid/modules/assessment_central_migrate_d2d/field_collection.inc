<?php
/**
 * @file
 * Base class for migrating field collection into Drupal.
 */
 abstract class ACFCMigration extends DrupalMigration {
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

}

/**
 
 */

class ACNotesMigration extends ACFCMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('field_notes migration from old D7.');
    $this->dependencies = array('Combo', 'MI');

    $this->sourceFields += array(
      'item_id' => t('Item Id'),
      'revision_id' => t('Revision ID'),  
      'field_name' => t('Host field name'),
      'archived' => t('Archived'),
	  'host_entity_id' => 'Host entity ID',
	  'field_note_type' => "Node type",
	  'field_link_type' => 'Link type',
	  'field_address' => 'Address',
	  'field_note' => 'Note',
	  'field_warning' => 'Warning',
	    
    );
	//$this->sourceFields += parent::getSourceFields('field_collection_item', 'field_primary_user');
	/*				 
	$query = Database::getConnection('legancy', $this->sourceConnection)
		->select('field_collection_item', 'c')
		->fields('c', array('item_id', 'revision_id', 'field_name', 'archived'))
		->condition('field_name', 'field_primary_user');
    $this->source = new  MigrateSourceSQL($query, $columns);
    */
	$this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL,
      $this->sourceOptions);
    $this->destination = new MigrateDestinationFieldCollection(
      'field_notes',
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
    $query = Database::getConnection('legancy', $this->sourceConnection)
		->select('field_collection_item', 'c')
		->condition('field_name', 'field_notes');
	
	$query->leftJoin('field_data_field_note_type', 'fnt', 'fnt.entity_id = c.item_id');
	$query->leftJoin('field_data_field_link_type', 'fln', 'fln.entity_id = c.item_id');
	$query->leftJoin('field_data_field_address', 'fa', 'fa.entity_id = c.item_id');
	$query->leftJoin('field_data_field_note', 'fn', 'fn.entity_id = c.item_id');
	$query->leftJoin('field_data_field_warning', 'fw', 'fw.entity_id = c.item_id');
	$query->fields('c', array('item_id', 'revision_id', 'field_name', 'archived'));
	$query->addField('fnt', 'field_note_type_value', 'field_note_type');
	$query->addField('fln', 'field_link_type_value', 'field_link_type');
	$query->addField('fa', 'field_address_value', 'field_address');
	$query->addField('fn', 'field_note_value', 'field_note');
	$query->addField('fw', 'field_warning_value', 'field_warning');
		
    return $query;
  }
  
  public function prepareRow($row) {
    
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	print_r($row);
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
	$code = $row -> field_note_type;
	$code_type = 'note_type';
	print_r($codes);
	if ($code){
		$target_id = $this->get_new_code_entity_id($code, $code_type);
		if ($target_id ){
			$row->field_note_type = $target_id;
		}
		else{
			$this->saveMessage(t('No target id found for code !name', array('!name' => $code)));
		}
	}
	
	// field_link_type
	$codes = $row -> field_link_type;
	$code_type = 'link_type';
	if ($code){
		$target_id = $this->get_new_code_entity_id($code, $code_type);
		if ($target_id ){
			$row->field_link_type = $target_id;
		}
		else{
			$this->saveMessage(t('No target id found for code !name', array('!name' => $code)));
		}
	}
	
	
	print_r($row);
	print_r($row->item_id . " is migrated \n");
	return True;
  }
}
class ACPCIMigration extends ACFCMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('field_notes migration from old D7.');
    $this->dependencies = array('Combo', 'MI');

    $this->sourceFields += array(
      'item_id' => t('Item Id'),
      'revision_id' => t('Revision ID'),  
      'field_name' => t('Host field name'),
      'archived' => t('Archived'),
	  'host_entity_id' => 'Host entity ID',
	  'field_pci_type' => "PCI type",
	  'field_link_type' => 'Link type',
	  'field_address' => 'Address',
	  'field_note' => 'Note',
	    
    );
	//$this->sourceFields += parent::getSourceFields('field_collection_item', 'field_primary_user');
	/*				 
	$query = Database::getConnection('legancy', $this->sourceConnection)
		->select('field_collection_item', 'c')
		->fields('c', array('item_id', 'revision_id', 'field_name', 'archived'))
		->condition('field_name', 'field_primary_user');
    $this->source = new  MigrateSourceSQL($query, $columns);
    */
	$this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL,
      $this->sourceOptions);
    $this->destination = new MigrateDestinationFieldCollection(
      'field_pci',
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
	
	$query->leftJoin('field_data_field_pci_type', 'fpt', 'fpt.entity_id = c.item_id');
	$query->leftJoin('field_data_field_link_type', 'fln', 'fln.entity_id = c.item_id');
	$query->leftJoin('field_data_field_address', 'fa', 'fa.entity_id = c.item_id');
	$query->leftJoin('field_data_field_note', 'fn', 'fn.entity_id = c.item_id');
	$query->fields('c', array('item_id', 'revision_id', 'field_name', 'archived'));
	$query->addField('fpt', 'field_pci_type_value', 'field_pci_type');
	$query->addField('fln', 'field_link_type_value', 'field_link_type');
	$query->addField('fa', 'field_address_value', 'field_address');
	$query->addField('fn', 'field_note_value', 'field_note');
		
    return $query;
  }
  
  public function prepareRow($row) {
    
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	print_r($row);
	// Mapping field collection item id
	$legacy_host_entity_row = Database::getConnection('legancy', $this->sourceConnection)
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
	$code = $row -> field_pci_type;
	$code_type = 'pci_type';
	if ($code){
		$target_id = $this->get_new_code_entity_id($code, $code_type);
		if ($target_id ){
			$row->field_pci_type = $target_id;
		}
		else{
			$this->saveMessage(t('No target id found for code !name', array('!name' => $code)));
		}
	}
	/*
	if ($codes){
		foreach($codes as $code){
			$target_id = $this->get_new_code_entity_id($code, $code_type);
			if ($target_id ){
				$target_ids[]=$target_id;
			}
			else{
				$this->saveMessage(t('No target id found for code !name', array('!name' => $code)));
			}
		}
		$row->field_pci_type = $target_ids;
	}
	*/
	// field_link_type
	$codes = $row -> field_link_type;
	$code_type = 'link_type';
	if ($code){
		$target_id = $this->get_new_code_entity_id($code, $code_type);
		if ($target_id ){
			$row->field_link_type = $target_id;
		}
		else{
			$this->saveMessage(t('No target id found for code !name', array('!name' => $code)));
		}
	}
	
	print_r($row);
	print_r($row->item_id . " is migrated \n");
	return True;
  }
}