<?php
/**
 * @file assessment_central_migrate_d2d.migrate.inc
 */

/**
 * This is code for AC migration from old D7 to new D7.
 */

/**
 * Implements hook_migrate_api().
 */
function assessment_central_migrate_d2d_migrate_api() {
  /**
   * Declare the api version and migration group.
   */
  $api = array(
    'api' => 2,
    'groups' => array(
      'assessment_central_group' => array(
        'title' => t('Old D7 to new D7 AC migrations.'),
      ),
      'migrations' => array(),
    ),
  );

  /**
   * Each migration being registered takes an array of arguments, some required
   * and some optional. Start with the common arguments required by all - the
   * source_connection (connection key, set up in settings.php, pointing to
   * the Drupal 6 database), source_version (major version of Drupal), and
   * group_name (a.k.a. import job).
   */
  $common_arguments = array(
    'source_connection' => 'legacy',
    'source_version' => 7,
    'group_name' => 'assessment_central_group',
	'source_database' => array(
    'driver' => 'mysql',
    'database' => 'old_ac',
    'username' => 'drupal',
    'password' => 'drupal_pwd',
    'host' => 'localhost',
    'prefix' => '',
	),
  );

  // Register the user migration.
   // Migrate roles
  
  $api['migrations']['Role'] = $common_arguments + array(
    'description' => t('Migration of Roles'),
    'class_name' => 'DrupalRole7Migration',
	'role_mappings' => array(
      'manager' => 'manager',
      'data entry' => 'data entry',
      'observer' => 'observer',
    ),
  );

  // We just use the migrate_d2d D7 migration class as-is.
  $api['migrations']['User'] = $common_arguments + array(
    'description' => t('Migration of users'),
    'class_name' => 'DrupalUser7Migration',
	'role_migration' => 'Role',
  );

  // For vocabulary migrations, source_vocabulary and destination_vocabulary are
  // required arguments. Note that in Drupal 6 vocabularies did not have machine
  // names, so we use the vocabulary ID to uniquely identify them.
  /*
  $vocabulary_arguments = array(
    'Countries' => array(
      'description' => t('Migration of Countries terms from Drupal 6'),
      'source_vocabulary' => '1',  // D6 Vocabulary ID
      'destination_vocabulary' => 'countries',
    ),
    'Topics' => array(
      'description' => t('Migration of Topics terms from Drupal 6'),
      'source_vocabulary' => '2',  // D6 Vocabulary ID
      'destination_vocabulary' => 'topics',
    ),
  );
	*/
  // Again, we're using the migrate_d2d class directly.
  // The soft dependency says that while we don't have to run the user migration
  // first, we want to make sure it's listed first so the vocabularies are
  // listed right ahead of the node migrations.
  /*
  $common_vocabulary_arguments = $common_arguments + array(
    'class_name' => 'DrupalTerm6Migration',
    'soft_dependencies' => array('User'),
  );
  foreach ($vocabulary_arguments as $migration_name => $arguments) {
    $arguments += $common_vocabulary_arguments;
    $api['migrations'][$migration_name] = $arguments;
  }
	*/
  // Node migrations - each has its own class derived from the migrate_d2d class,
  // specifying its particular field mappings and transformations. source_type
  // and destination_type are required arguments.
  $node_arguments = array(
    'LinkType' => array(
      'class_name' => 'ACLinkTypeMigration',
      'description' => t('Migration of Link Type nodes'),
      'source_type' => 'link_type',
      'destination_type' => 'link_type',
    ),
	'NoteType' => array(
      'class_name' => 'ACNoteTypeMigration',
      'description' => t('Migration of Note type nodes'),
      'source_type' => 'note_type',
      'destination_type' => 'note_type',
    ),
	'PCIType' => array(
      'class_name' => 'ACPCITypeMigration',
      'description' => t('Migration of PCI type nodes'),
      'source_type' => 'pci_type',
      'destination_type' => 'pci_type',
    ),
	
	'NHPIDIngredient' => array(
      'class_name' => 'ACNHPIDIngredientMigration',
      'description' => t('Migration of NHPID Ingredient nodes'),
      'source_type' => 'nhpid_ingredient',
      'destination_type' => 'nhpid_ingredient',
    ),
	'Combo' => array(
      'class_name' => 'ACComboMigration',
      'description' => t('Migration of Combo nodes'),
      'source_type' => 'combo',
      'destination_type' => 'combo',
    ),
	'Combo2' => array(
      'class_name' => 'ACComboMigration2',
      'description' => t('Migration of Combo nodes'),
      'source_type' => 'combo',
      'destination_type' => 'combo',
    ),
	'MI' => array(
      'class_name' => 'ACMIMigration',
      'description' => t('Migration of MI nodes'),
      'source_type' => 'mi',
      'destination_type' => 'mi',
    ),
	
  );

  // Tell the node migrations where the users are coming from, so they can
  // set up the dependency and resolve D6->D7 uids.
  $common_node_arguments = $common_arguments + array(
      'user_migration' => 'User'
    );

  foreach ($node_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }
	/*
  // Menu migrations -- same requirements as users
  $menu_arguments = $common_arguments + array(
    'description' => t('Migration of menus from Drupal 6'),
    'class_name' => 'DrupalMenu6Migration',
  );

  // We just use the migrate_d2d D6 migration class as-is.
  $api['migrations']['Menu'] = $menu_arguments;

  // Menu links migrations -- basic requirements, plus must set up menu dependency
  $menu_links_arguments = $common_arguments + array(
    'description' => t('Migration of menu links from Drupal 6'),
    'class_name' => 'DrupalMenuLinks6Migration',
    'menu_migration' => 'Menu',
  );
  $api['migrations']['MenuLinks'] = $menu_links_arguments;
	*/
	// field collection
	
	$api['migrations']['FCNotes'] = $common_arguments + array(
    'description' => t('Migration of field collection field_notes'),
    'class_name' => 'ACNotesMigration',
	);
	$api['migrations']['FCPCI'] = $common_arguments + array(
    'description' => t('Migration of field collection field_pci'),
    'class_name' => 'ACPCIMigration',
	);

  return $api;
}
