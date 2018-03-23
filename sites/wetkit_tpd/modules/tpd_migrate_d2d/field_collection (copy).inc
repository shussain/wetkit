<?php
/**
 * @file
 * Base class for migrating field collection into Drupal.
 */

/**
 * Base class for D7 field collection migrations - handles commonalities across all
 * supported source Drupal versions.
 *
 * In addition to the arguments supported by DrupalMigration, the following
 * must be passed in the $arguments array:
 *
 * source_type - Drupal 6 content type machine name.
 * destination_type - Drupal 7 content type machine name (bundle).
 *
 * The following optional arguments may be passed:
 *
 * user_migration - Machine name of a user migration, used to establish
 *   dependencies and a sourceMigration for the uid mapping.
 * default_uid - Drupal 7 (destination) uid of the user account to use as
 *   the default.
 * default_language - Default language for the node and node body. Defaults
 *   to LANGUAGE_NONE.
 */
abstract class DrupalFieldCollectionMigration extends DrupalMigration {
  /**
   * The source and destination content types (bundles) we're dealing with.
   */
  protected $destinationType;

  /**
   * Default language to apply to the node and it's body field.
   *
   * @var string
   */
  protected $defaultLanguage = LANGUAGE_NONE;

  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $this->destinationType = $arguments['destination_type'];
    $this->sourceType = $arguments['source_type'];
    if (!empty($arguments['user_migration'])) {
      $user_migration = $arguments['user_migration'];
      $this->dependencies[] = $user_migration;
    }
    if (!empty($arguments['default_language'])) {
      $this->defaultLanguage = $arguments['default_language'];
    }
    parent::__construct($arguments);

    // Document known core fields
    $this->sourceFields += array(
      'item_id' => t('Item Id'),
      'revision_id' => t('Revision ID'),  // @todo Depends on has_title, and label may be customized
      'field_name' => t('Host field name'),
      'archived' => t('Archived'),
    );

    $this->sourceFields += $this->version->getSourceFields('field_collection_item', $this->sourceType);
    if ($this->moduleExists('path')) {
      $this->sourceFields['path'] = t('Path alias');
    }

    $this->destination = new MigrateDestinationNode($this->destinationType);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'item_id' => array('type' => 'int',
                       'unsigned' => TRUE,
                       'not null' => TRUE,
                       'description' => 'Source node ID',
                       'alias' => 'n',
                      ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    if (!$this->newOnly) {
      $this->highwaterField = array(
        'name' => 'changed',
        'alias' => 'n',
        'type' => 'int',
      );
    }

    // Setup common mappings
    $this->addSimpleMappings(array('item_id', 'revision_id', 'field_name', 'archived',));
  
  }

  /**
   * Called after the query data is fetched - we'll use this to populate the
   * source row with the CCK fields.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

  
  }

  /**
   * Implementation of Migration::createStub().
   *
   * @param $migration
   * @return array|bool
   */
  protected function createStub($migration) {
    migrate_instrument_start('DrupalNodeMigration::createStub');
    $node = new stdClass;
    $node->title = t('Stub');
    $node->body = array(LANGUAGE_NONE => array(array("value" => t('Stub body'))));
    $node->type = $this->destination->getBundle();
    $node->uid = 1;
    node_save($node);
    migrate_instrument_stop('DrupalNodeMigration::createStub');
    if (isset($node->nid)) {
      return array($node->nid);
    }
    else {
      return FALSE;
    }
  }
}

/**
 * Field collection field_primary_user mappings and handling.
 */
 /*
class TPDPrimaryUserMigration extends DrupalFieldCollectionMigration{
	public function __construct($arguments) {
		$this->dependencies = array('TradingPartner');
 
		parent::__construct($arguments);
		$this->addFieldMapping('field_contact', 'field_contact')->sourceMigration('TradingPartner');
		$this->addFieldMapping('field_salute', 'field_salute')->sourceMigration('TradingPartner');
		$this->addFieldMapping('field_title', 'field_title')->sourceMigration('TradingPartner');
		$this->addFieldMapping('field_language', 'field_language')->sourceMigration('TradingPartner');
		$this->addFieldMapping('field_email', 'field_email')->sourceMigration('TradingPartner');
		$this->addFieldMapping('field_phone_number', 'field_phone_number')->sourceMigration('TradingPartner');
		$this->addFieldMapping('field_fax', 'field_fax')->sourceMigration('TradingPartner');
 
	}

  /**
   * Query for basic node fields from Drupal 7.
   *
   * @return QueryConditionInterface
   */
   /*
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('field_collection_item', 'n')
             ->fields('n', array('item_id', 'revision_id', 'field_name', 'archived'))
             ->condition('n.field_name', $this->sourceType);
			 

    return $query;
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // The property 'tnid' cannot be handled via sourceMigration() method
    // because it might be 0 or the main node of translation set. We don't want
    // to create a stub for such cases.
    if (!empty($row->tnid)) {
      $destination_ids = $this->getMap()->lookupDestinationID(array($row->tnid));
      // There's no destination yet. Create a stub.
      if (empty($destination_ids)) {
        // Don't create stub for itself.
        if ($row->tnid != $row->nid) {
          // Check if 'tnid' is a node in the source set to prevent not
          // updatable stubs.
          $query = clone $this->query();
          $query->condition('n.nid', $row->tnid);
          $nid = $query->execute()->fetchField();
          unset($query);
          if ($nid) {
            if ($tnids = $this->createStub(NULL)) {
              // Save the mapping.
              $this->map->saveIDMapping((object) array('nid' => $row->tnid), $tnids, MigrateMap::STATUS_NEEDS_UPDATE, $this->defaultRollbackAction);
              $row->tnid = reset($tnids);
            }
          }
        }
        else {
          $row->tnid = 0;
          $row->_is_translation_source = TRUE;
        }
      }
      else {
        $row->tnid = $destination_ids['destid1'];
      }
    }
  }

  public function complete($node, stdClass $row) {
    if (empty($row->_is_translation_source)) {
      return;
    }

    db_update('node')
      ->fields(array('tnid' => $node->nid))
      ->condition('nid', $node->nid)
      ->execute();
  }
  
}
*/
class TPDPrimaryUserMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('field_primary_user migration from CSV source.');
    $this->dependencies = array('TradingPartner');

    $columns = array(
      'item_id' => t('Item Id'),
      'revision_id' => t('Revision ID'),  
      'field_name' => t('Host field name'),
      'archived' => t('Archived'),
    );
	$query = db_select('old_tpd.field_collection_item', 'c')
                 ->fields('c', array('item_id', 'revision_id', 'field_name', 'archived'))
				 ->condition('field_name', 'field_primary_user');
				 
	$query = Database::getConnection('legancy')
		->select('old_tpd.field_collection_item', 'c')
        ->fields('c', array('item_id', 'revision_id', 'field_name', 'archived'))
		->condition('field_name', 'field_primary_user');
    $this->source = new  MigrateSourceSQL($query, $columns);
   

    $this->destination = new MigrateDestinationFieldCollection(
      'field_primary_user',
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

    $this->addFieldMapping('field_contact', 'field_contact')->sourceMigration('TradingPartner');
    
  }
  public function import(stdClass $collection, stdClass $row) {
    $updating = FALSE;
    if (isset($row->migrate_map_destid1)) {
      // We're updated an existing entity - start from the previous data.
      // entity_load() returns an array, so we get the field collection entity
      // with array_shift().
      if ($entity = array_shift(entity_load('field_collection_item', array($row->migrate_map_destid1), array(), TRUE))) {
        $entity_old = clone $entity;
        $updating = TRUE;
      }
    }

    if (!$updating) {
      // Skip the collection if it has no host.
      if (empty($collection->host_entity_id)) {
        throw new MigrateException('Could not find host entity of the field collection to import.');
      }
      $entity = entity_create('field_collection_item', array('field_name' => $this->bundle));
      $updating = FALSE;
      $host_entity = entity_load_single($this->hostEntityType, $collection->host_entity_id);
      entity_get_controller($this->hostEntityType)->resetCache();

      if (isset($row->language)) {
        $entity->setHostEntity($this->hostEntityType, $host_entity, $row->language, TRUE);
      }
      else {
        $entity->setHostEntity($this->hostEntityType, $host_entity);
      }
    }

    unset($collection->host_entity_id);

    foreach ((array) $collection as $field => $value) {
      $entity->{$field} = $value;
    }

    $this->prepare($entity, $row);

    // Restore fields from original field_collection_item if updating
    if ($updating) {
      foreach ($entity as $field => $value) {
        if ('field_' != substr($field, 0, 6)) {
          continue;
        }
        elseif (property_exists($entity_old, $field) && !property_exists($collection, $field)) {
          $entity->$field = $entity_old->$field;
        }
      }
    }

    migrate_instrument_start('field_collection_save');
    $status = entity_save('field_collection_item', $entity);
    migrate_instrument_stop('field_collection_save');

    if (in_array($this->hostEntityType, array('node', 'field_collection_item')) || ($status !== FALSE)) {
      $this->complete($entity, $row);
      if ($updating) {
        $this->numUpdated++;
      }
      else {
        $this->numCreated++;
      }
      return array($entity->item_id);
    }
    else {
      return FALSE;
    }
  }
}