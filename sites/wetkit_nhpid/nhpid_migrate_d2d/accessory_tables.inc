<?php

/**
 * @file
 * Make a copy of the role table. To use this you must create a table named
 * role_copy with the same structure as role.
 */

class NHPIDExcelFieldMappingMigration extends DrupalMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
	//print_r($arguments);
    $this->description = 'Copy the nhpid_excel_drupal_field_mapping table.';
    $destination_key = array(
      'node_type' => array(
        'type' => 'varchar',
        'not null' => TRUE,
		'length' => 100,
      ),
	  'drupal_field_name' => array(
        'type' => 'varchar',
        'not null' => TRUE,
		'length' => 150,
      ),
    );
    //$query = db_select('old_nhpid.nhpid_excel_drupal_field_mapping', 'm')->fields('m');
	
	
    $this->source = new MigrateSourceSQL($this->query());
    $this->destination = new MigrateDestinationTableCopy('nhpid_excel_drupal_field_mapping', $destination_key);

    $this->map = new MigrateSQLMap($this->machineName,
    array('node_type' => array(
        'type' => 'varchar',
        'not null' => TRUE,
		'length' => 100,
		'alias' => 'm',
      ),
	  'drupal_field_name' => array(
        'type' => 'varchar',
        'not null' => TRUE,
		'length' => 150,
		'alias' => 'm',
      ),
	  ),

    $destination_key
    );
  }
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)->select('nhpid_excel_drupal_field_mapping', 'm');
	
	$query->fields('m');
		
    return $query;
  }
  public function getQuery(){
	  return $this -> query();
  }
  public function getSourceIds(){
	  $result=$this->query()->execute();
	  $source_ids= array();
	  while($rc=$result->fetchObject()){
		  $source_ids[$rc->node_type . ':' . $rc->drupal_field_name]=$rc->node_type . ':' . $rc->drupal_field_name;
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
		  $source_ids[$rc->sourceid1 . ':' . $rc->sourceid2]=$rc->sourceid1 . ':' . $rc->sourceid2;
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
		  $source_ids[$rc->sourceid1 . ':' . $rc->sourceid2]=$rc->sourceid1 . ':' . $rc->sourceid2;
	  }
	  return $source_ids;
  }
  public function getUnprocessedIds(){
	  return array_diff_key($this->getSourceIds(), $this->getProcessedIds());
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
		  $source_ids[$rc->sourceid1 . ':' . $rc->sourceid2]=$rc->sourceid1 . ':' . $rc->sourceid2;
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
		  $source_ids[$rc->sourceid1 . ':' . $rc->sourceid2]=$rc->sourceid1 . ':' . $rc->sourceid2;
	  }
	  return $source_ids;
  }
  public function getUnprocessedAndNeedsUpdateIds(){
	  return array_unique(array_merge($this->getUnprocessedIds() + $this->getNeedsUpdateIds()));
  }
}