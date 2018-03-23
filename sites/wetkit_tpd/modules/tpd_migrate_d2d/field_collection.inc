<?php
/**
 * @file
 * Base class for migrating field collection into Drupal.
 */

/**
 
 */
abstract class FCMigration extends DrupalMigration {
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
			//print_r('GC run');
		}
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

class TPDPrimaryUserMigration extends FCMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('field_primary_user migration from old D7.');
    $this->dependencies = array('TradingPartner_4');
	$this->destination_type='field_primary_user';

    $this->sourceFields += array(
      'item_id' => t('Item Id'),
      //'revision_id' => t('Revision ID'),  
      'field_name' => t('Host field name'),
      'archived' => t('Archived'),
	  'host_entity_id' => 'Host entity ID',
	  'field_contact' => "Contact",
	  'field_salute' => 'Salute',
	  'field_title' => 'Title',
	  'field_language' => 'Language',
	  'field_phone_number' => 'Phone number country codes',
	  //'field_phone_number:number' => 'Phone number',
	  //'field_phone_number:extension' => 'Extension',
	  //'field_fax:number' => 'Fax number',
	  //'field_fax:extension' => 'Fax Extension',
	  'field_fax' => 'Fax country codes',
	  'field_email' => 'Email',
  
    );
	//$this->sourceFields += parent::getSourceFields('field_collection_item', 'field_primary_user');
	/*				 
	$query = Database::getConnection('legancy', $this->sourceConnection)
		->select('field_collection_item', 'c')
		->fields('c', array('item_id',  'field_name', 'archived'))
		->condition('field_name', 'field_primary_user');
    $this->source = new  MigrateSourceSQL($query, $columns);
    */
	$this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL,
      $this->sourceOptions);
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
	$this->addFieldMapping('field_contact', 'field_contact');
	$this->addFieldMapping('field_salute', 'field_salute');
	$this->addFieldMapping('field_title', 'field_title');
	$this->addFieldMapping('field_language', 'field_language');
	
	$this->addFieldMapping('field_phone_number', 'field_phone_number');
	$this->addFieldMapping('field_fax', 'field_fax');
	$this->addFieldMapping('field_phone_number:number', 'field_phone_number_number');
	$this->addFieldMapping('field_phone_number:extension', 'field_phone_number_extension');
	$this->addFieldMapping('field_fax:number', 'field_fax_number');
	$this->addFieldMapping('field_fax:extension', 'field_fax_extension');
	$this->addFieldMapping('field_email', 'field_email');
    
  }
  /**
   * Query for basic node fields from Drupal 7.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    $query = Database::getConnection('legancy', $this->sourceConnection)
		->select('field_collection_item', 'c')
		->condition('field_name', $this->destination_type);
	
	$query->leftJoin('field_data_field_contact', 'fc', 'fc.entity_id = c.item_id');
	$query->leftJoin('field_data_field_salute', 'fs', 'fs.entity_id = c.item_id');
	$query->leftJoin('field_data_field_title', 'ft', 'ft.entity_id = c.item_id');
	$query->leftJoin('field_data_field_language', 'fl', 'fl.entity_id = c.item_id');
	$query->leftJoin('field_data_field_email', 'fe', 'fe.entity_id = c.item_id');
	$query->leftJoin('field_data_field_phone_number', 'fp', 'fp.entity_id = c.item_id');
	$query->leftJoin('field_data_field_fax', 'ff', 'ff.entity_id = c.item_id');
	$query->fields('c', array('item_id', 'revision_id', 'field_name', 'archived'));
	$query->addField('fc', 'field_contact_value', 'field_contact');
	$query->addField('fs', 'field_salute_value', 'field_salute');
	$query->addField('ft', 'field_title_value', 'field_title');
	$query->addField('fl', 'field_language_value', 'field_language');
	$query->addField('fe', 'field_email_value', 'field_email');
	$query->addField('fp', 'field_phone_number_number', 'field_phone_number_number');
	$query->addField('fp', 'field_phone_number_extension', 'field_phone_number_extension');
	$query->addField('fp', 'field_phone_number_country_codes', 'field_phone_number');
	$query->addField('ff', 'field_fax_number', 'field_fax_number');
	$query->addField('ff', 'field_fax_extension', 'field_fax_extension');
	$query->addField('ff', 'field_fax_country_codes', 'field_fax');
	
	
    return $query;
  }
  
  public function prepareRow($row) {
    
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	//print_r($row);
	$legacy_host_entity_row = Database::getConnection('legancy', $this->sourceConnection)
                 ->select('field_data_field_primary_user', 'c')
                 ->fields('c', array('entity_id', 'field_primary_user_value'))
				 ->condition('bundle', 'trading_partner')
				 ->condition('field_primary_user_value', $row->item_id)
                 ->execute()
                 ->fetchObject();
		if($legacy_host_entity_row){
			$legacy_entity_id = $legacy_host_entity_row -> entity_id;
			$new_host_entity_row = Database::getConnection('default')
                 ->select('field_data_field_legacy_nid', 'c')
                 ->fields('c', array('entity_id', 'field_legacy_nid_value'))
				 ->condition('bundle', 'trading_partner')
				 ->condition('field_legacy_nid_value', $legacy_entity_id)
                 ->execute()
                 ->fetchObject();
			$row->host_entity_id = $new_host_entity_row->entity_id;
		}
		else{
			print_r ('No host entity id is found for'  . $row->item_id . "\n");
		}
	//print_r($row);
	print_r($row->item_id . " is migrated \n");
  }

}
class TPDDelegatedUsersMigration extends FCMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('field_delegated_users migration from old D7.');
    $this->dependencies = array('TradingPartner_4');
	$this->destination_type='field_delegated_users';
    $this->sourceFields += array(
      'item_id' => t('Item Id'),
      //'revision_id' => t('Revision ID'),  
      'field_name' => t('Host field name'),
      'archived' => t('Archived'),
	  'host_entity_id' => 'Host entity ID',
	  'field_contact' => "Contact",
	  'field_salute' => 'Salute',
	  'field_title' => 'Title',
	  'field_language' => 'Language',
	  'field_phone_number' => 'Phone number country codes',
	  //'field_phone_number:number' => 'Phone number',
	  //'field_phone_number:extension' => 'Extension',
	  //'field_fax:number' => 'Fax number',
	  //'field_fax:extension' => 'Fax Extension',
	  'field_fax' => 'Fax country codes',
	  'field_email' => 'Email',
  
    );
	//$this->sourceFields += parent::getSourceFields('field_collection_item', 'field_primary_user');
	/*				 
	$query = Database::getConnection('legancy', $this->sourceConnection)
		->select('field_collection_item', 'c')
		->fields('c', array('item_id',  'field_name', 'archived'))
		->condition('field_name', 'field_primary_user');
    $this->source = new  MigrateSourceSQL($query, $columns);
    */
	$this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL,
      $this->sourceOptions);
    $this->destination = new MigrateDestinationFieldCollection(
      'field_delegated_users',
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
	$this->addFieldMapping('field_contact', 'field_contact');
	$this->addFieldMapping('field_salute', 'field_salute');
	$this->addFieldMapping('field_title', 'field_title');
	$this->addFieldMapping('field_language', 'field_language');
	
	$this->addFieldMapping('field_phone_number', 'field_phone_number');
	$this->addFieldMapping('field_fax', 'field_fax');
	$this->addFieldMapping('field_phone_number:number', 'field_phone_number_number');
	$this->addFieldMapping('field_phone_number:extension', 'field_phone_number_extension');
	$this->addFieldMapping('field_fax:number', 'field_fax_number');
	$this->addFieldMapping('field_fax:extension', 'field_fax_extension');
	$this->addFieldMapping('field_email', 'field_email');
    
  }
  /**
   * Query for basic node fields from Drupal 7.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    $query = Database::getConnection('legancy', $this->sourceConnection)
		->select('field_collection_item', 'c')
		->condition('field_name', 'field_delegated_user');
	$query->join('field_data_field_delegated_user', 'du', 'du.field_delegated_user_value=c.item_id');
	$query->leftJoin('field_data_field_contact', 'fc', 'fc.entity_id = c.item_id');
	$query->leftJoin('field_data_field_salute', 'fs', 'fs.entity_id = c.item_id');
	$query->leftJoin('field_data_field_title', 'ft', 'ft.entity_id = c.item_id');
	$query->leftJoin('field_data_field_language', 'fl', 'fl.entity_id = c.item_id');
	$query->leftJoin('field_data_field_email', 'fe', 'fe.entity_id = c.item_id');
	$query->leftJoin('field_data_field_phone_number', 'fp', 'fp.entity_id = c.item_id');
	$query->leftJoin('field_data_field_fax', 'ff', 'ff.entity_id = c.item_id');
	$query->fields('c', array('item_id', 'revision_id', 'field_name', 'archived'));
	$query->addField('fc', 'field_contact_value', 'field_contact');
	$query->addField('fs', 'field_salute_value', 'field_salute');
	$query->addField('ft', 'field_title_value', 'field_title');
	$query->addField('fl', 'field_language_value', 'field_language');
	$query->addField('fe', 'field_email_value', 'field_email');
	$query->addField('fp', 'field_phone_number_number', 'field_phone_number_number');
	$query->addField('fp', 'field_phone_number_extension', 'field_phone_number_extension');
	$query->addField('fp', 'field_phone_number_country_codes', 'field_phone_number');
	$query->addField('ff', 'field_fax_number', 'field_fax_number');
	$query->addField('ff', 'field_fax_extension', 'field_fax_extension');
	$query->addField('ff', 'field_fax_country_codes', 'field_fax');
	
	
    return $query;
  }
  
  public function prepareRow($row) {
    
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	//print_r($row);
	$legacy_host_entity_row = Database::getConnection('legancy', $this->sourceConnection)
                 ->select('field_data_field_delegated_user', 'c')
                 ->fields('c', array('entity_id', 'field_delegated_user_value'))
				 ->condition('bundle', 'trading_partner')
				 ->condition('field_delegated_user_value', $row->item_id)
                 ->execute()
                 ->fetchObject();
		if($legacy_host_entity_row){
			$legacy_entity_id = $legacy_host_entity_row -> entity_id;
			$new_host_entity_row = Database::getConnection('default')
                 ->select('field_data_field_legacy_nid', 'c')
                 ->fields('c', array('entity_id', 'field_legacy_nid_value'))
				 ->condition('bundle', 'trading_partner')
				 ->condition('field_legacy_nid_value', $legacy_entity_id)
                 ->execute()
                 ->fetchObject();
			$row->host_entity_id = $new_host_entity_row->entity_id;
		}
		else{
			print_r ('No host entity id is found for'  . $row->item_id . "\n");
		}
	print_r($row->item_id . " is migrated \n");
  }
  
}
class TPDOtherUsersMigration extends FCMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('field_other_users migration from old D7.');
    $this->dependencies = array('TradingPartner_4');
	$this->destination_type='field_delegated_users';
    $this->sourceFields += array(
      'item_id' => t('Item Id'),
      //'revision_id' => t('Revision ID'),  
      'field_name' => t('Host field name'),
      'archived' => t('Archived'),
	  'host_entity_id' => 'Host entity ID',
	  'field_contact' => "Contact",
	  'field_salute' => 'Salute',
	  'field_title' => 'Title',
	  'field_language' => 'Language',
	  'field_phone_number' => 'Phone number country codes',
	  //'field_phone_number:number' => 'Phone number',
	  //'field_phone_number:extension' => 'Extension',
	  //'field_fax:number' => 'Fax number',
	  //'field_fax:extension' => 'Fax Extension',
	  'field_fax' => 'Fax country codes',
	  'field_email' => 'Email',
  
    );
	//$this->sourceFields += parent::getSourceFields('field_collection_item', 'field_primary_user');
	/*				 
	$query = Database::getConnection('legancy', $this->sourceConnection)
		->select('field_collection_item', 'c')
		->fields('c', array('item_id',  'field_name', 'archived'))
		->condition('field_name', 'field_primary_user');
    $this->source = new  MigrateSourceSQL($query, $columns);
    */
	$this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL,
      $this->sourceOptions);
    $this->destination = new MigrateDestinationFieldCollection(
      'field_delegated_users',
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

    
	$this->addFieldMapping('host_entity_id', 'host_entity_id'); //->sourceMigration('TradingPartner');
	$this->addFieldMapping('field_contact', 'field_contact');
	$this->addFieldMapping('field_salute', 'field_salute');
	$this->addFieldMapping('field_title', 'field_title');
	$this->addFieldMapping('field_language', 'field_language');
	
	$this->addFieldMapping('field_phone_number', 'field_phone_number');
	$this->addFieldMapping('field_fax', 'field_fax');
	$this->addFieldMapping('field_phone_number:number', 'field_phone_number_number');
	$this->addFieldMapping('field_phone_number:extension', 'field_phone_number_extension');
	$this->addFieldMapping('field_fax:number', 'field_fax_number');
	$this->addFieldMapping('field_fax:extension', 'field_fax_extension');
	$this->addFieldMapping('field_email', 'field_email');
    
  }
  /**
   * Query for basic node fields from Drupal 7.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    $query = Database::getConnection('legancy', $this->sourceConnection)
		->select('field_collection_item', 'c')
		->condition('field_name', 'field_other_user');
	
	$query->leftJoin('field_data_field_contact', 'fc', 'fc.entity_id = c.item_id');
	$query->leftJoin('field_data_field_salute', 'fs', 'fs.entity_id = c.item_id');
	$query->leftJoin('field_data_field_title', 'ft', 'ft.entity_id = c.item_id');
	$query->leftJoin('field_data_field_language', 'fl', 'fl.entity_id = c.item_id');
	$query->leftJoin('field_data_field_email', 'fe', 'fe.entity_id = c.item_id');
	$query->leftJoin('field_data_field_phone_number', 'fp', 'fp.entity_id = c.item_id');
	$query->leftJoin('field_data_field_fax', 'ff', 'ff.entity_id = c.item_id');
	$query->fields('c', array('item_id', 'revision_id', 'field_name', 'archived'));
	$query->addField('fc', 'field_contact_value', 'field_contact');
	$query->addField('fs', 'field_salute_value', 'field_salute');
	$query->addField('ft', 'field_title_value', 'field_title');
	$query->addField('fl', 'field_language_value', 'field_language');
	$query->addField('fe', 'field_email_value', 'field_email');
	$query->addField('fp', 'field_phone_number_number', 'field_phone_number_number');
	$query->addField('fp', 'field_phone_number_extension', 'field_phone_number_extension');
	$query->addField('fp', 'field_phone_number_country_codes', 'field_phone_number');
	$query->addField('ff', 'field_fax_number', 'field_fax_number');
	$query->addField('ff', 'field_fax_extension', 'field_fax_extension');
	$query->addField('ff', 'field_fax_country_codes', 'field_fax');
	
	
    return $query;
  }
  
  public function prepareRow($row) {
    
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	//print_r($row);
	$legacy_host_entity_row = Database::getConnection('legancy', $this->sourceConnection)
                 ->select('field_data_field_other_user', 'c')
                 ->fields('c', array('entity_id', 'field_other_user_value'))
				 ->condition('bundle', 'trading_partner')
				 ->condition('field_other_user_value', $row->item_id)
                 ->execute()
                 ->fetchObject();
		if($legacy_host_entity_row){
			$legacy_entity_id = $legacy_host_entity_row -> entity_id;
			$new_host_entity_row = Database::getConnection('default')
                 ->select('field_data_field_legacy_nid', 'c')
                 ->fields('c', array('entity_id', 'field_legacy_nid_value'))
				 ->condition('bundle', 'trading_partner')
				 ->condition('field_legacy_nid_value', $legacy_entity_id)
                 ->execute()
                 ->fetchObject();
			$row->host_entity_id = $new_host_entity_row->entity_id;
		}
		else{
			print_r ('No host entity id is found for'  . $row->item_id . "\n");
		}
	//print_r($row);
	print_r($row->item_id . " is migrated \n");
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
	
 
}