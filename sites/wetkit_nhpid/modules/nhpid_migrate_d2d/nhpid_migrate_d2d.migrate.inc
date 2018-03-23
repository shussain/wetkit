<?php
/**
 * @file nhpid_migrate_d2d.migrate.inc
 */

/**
 * This is code for NHPID DMS migration from old D7 to new D7.
 */

/**
 * Implements hook_migrate_api().
 */
function nhpid_migrate_d2d_migrate_api() {
  /**
   * Declare the api version and migration group.
   */
  $code_node_group_1 = array(
  'code_application_type'=>'CodeApplicationType',
  'code_cat_iv_product'=>'CodeWithNameComment',
  'code_chemical_class'=>'CodeWithDescriptionComment',
  'code_common_term' => 'CodeCommentTerm',
  'code_dosage_unit'=>'CodeWithName',
  'code_dose_type'=>'CodeWithNameDescription',
  'code_evidence_type'=>'CodeWithNameDescription',
  'code_geo_distribution'=>'CodeWithDescriptionComment',
  'code_indication_type'=>'CodeWithNameDescription',
  'code_ingredient_class' => 'CodeWithDescriptionComment',
  'code_journal' => 'CodeJournal',
  'code_mono_type' =>'CodeWithName',
  'code_nhpd_classification'=>'CodeWithDescriptionComment',
  'code_organism_type_group'=>'CodeOrganismTypeGroup',
  'code_other_journal'=>'CodeOtherJournal',
  'code_province_state'=>'CodeProvinceState',
  'code_rationale_ref'=>'CodeWithDescriptionComment',
  'code_reference_type'=>'CodeWithDescriptionComment',
  'code_risk_type'=>'CodeWithNameDescription',
  'code_standard_or_grade'=>'CodeStandardOrGrade',
  'code_unit_type'=>'CodeWithNameDescription',
  'code_use_type'=>'CodeWithNameDescription',
  'homeopathic_dilution'=>'HomoDilution',
  'homeopathic_preparation'=>'CodeWithDescriptionComment',
  );
  $code_node_group_2 = array(
  'code_chemical_subclass'=>'CodeChemicalSubclass',
  'code_ingredient_category'=>'CodeIngredientCategory',
  'code_nmi_purpose' => 'CodeNmiPurpose',
  'code_organism_preparation' => 'CodeOrganismPreparation',
  'code_organism_part' => 'CodeOrganismPreparation',
  'code_organism_type'=>'CodeOrganismType',
  'code_reference'=>'CodeReference',
  'code_solvent'=>'CodeSolvent',
  'code_unit'=>'CodeUnit',
  
  );
  $code_node_group_3 = array(
  'code_roa'=>'CodeROA',
  'code_subpopulation'=>'CodeSubpopulation',
  'code_preparation_group'=>'CodePreparationGroup',
  'code_ich_classes'=>'CodeICHClasses',
  'code_dosage_form' => 'CodeDosageForm',
  );
  
  $code_node_group_4 = array(
  'code_dosage_form_group'=>'CodeDosageFormGroup',
  );
  $data_node_group_1 = array(
  'herbal_hcn'=>'HerbalHCNAndNaming',
  'naming_org_group_taxon'=>'NamingOrganismTaxon',
  'naming_organism'=>'HerbalHCNAndNaming',
  'naming_org_group'=>'NamingOrganismGroup',
  'homeopathic_mi'=>'HomoMI',
  'test_method_quality'=>'TestMethodQuality',
  
  );
  $data_node_group_2 = array(
  'naming_chemical'=>'HerbalHCNAndNaming',
  'naming_org_substance'=>'HerbalHCNAndNaming',
  'naming_protein'=>'HerbalHCNAndNaming',
  'nonnhp_organism'=>'HerbalHCNAndNaming',
  'nonnhp_chemical'=>'HerbalHCNAndNaming',
  );
  $data_node_group_3 = array(
  'mi_chemical'=>'MiNmiSubing',
  'mi_organism'=>'MiNmiSubing',
  'mi_org_substance'=>'MiNmiSubing',
  'nmi_chemical'=>'MiNmiSubing',
  'nmi_org_substance'=>'MiNmiSubing',
  'subing_chemical'=>'MiNmiSubing',
  'subing_protein'=>'MiNmiSubing',
  'subing_org_part'=>'MiNmiSubing',
 
  );
  $data_mono_data_group_1 = array(
  'mono_citation'=>'CodeReference',
  
  'mono_direction_for_use'=>'MonoDirectionForUse',
  'mono_dosage_form_group'=>'MonoDosageFormGroup',
  'mono_dosage_form_note'=>'MonoNote',
  'mono_dose_note'=>'MonoNote',
  'mono_duration'=>'MonoDuration',
  'mono_monograph_list'=>'MonoMonographList',
  'mono_preparation'=>'MonoPreparation',
  'mono_rda_value'=>'MonoRDAValue',
  'mono_risk'=>'MonoRisk',
  'mono_subing_combo'=>'MonoSubingCombo',
 
  );
  $data_mono_data_group_2 = array(
  'mono_roa'=>'MonoROA',
  'mono_subing_dose'=>'MonoSubingDose',
  'mono_use'=>'MonoUse',
  'mono_phase'=>'MonoPhase',
  'mono_monograph'=>'MonoMonograph'
  
 
  );
  $data_mono_data_group_3 = array(
  'mono_subing_dose_combo'=>'MonoSubingDoseCombo',
  
 
  );
  $data_mono_data_group_4 = array(
  'mono_dose'=>'MonoDose',

 
  );
  $data_mono_data_group_5 = array(
  'mono_dose_combination'=>'MonoDoseCombination',

 
  );
  $data_mono_data_group_6 = array(
  'mono_entry'=>'MonoEntry',

 
  );
  $api = array(
    'api' => 2,
    'groups' => array(
      'nhpid_group_1' => array(
        'title' => t('Basic Data'),
      ),
	  'nhpid_group_code_node_group1' => array(
        'title' => t('Code node group 1'),
      ),
	  'nhpid_group_code_node_group2' => array(
        'title' => t('Code node group 2'),
      ),
	  'nhpid_group_code_node_group3' => array(
        'title' => t('Code node group 3'),
      ),
	  'nhpid_group_code_node_group4' => array(
        'title' => t('Code node group 4'),
      ),
	  'nhpid_group_data_node_group1' => array(
        'title' => t('Data node group 1'),
      ),
	  'nhpid_group_data_node_group2' => array(
        'title' => t('Data node group 2'),
      ),
	  'nhpid_group_data_node_group3' => array(
        'title' => t('Data node group 3'),
      ),
	  'nhpid_group_mono_node_group1' => array(
        'title' => t('Mono node group 1'),
      ),
	  'nhpid_group_mono_node_group2' => array(
        'title' => t('Mono node group 2'),
      ),
	  'nhpid_group_mono_node_group3' => array(
        'title' => t('Mono node group 3'),
      ),
	  'nhpid_group_mono_node_group4' => array(
        'title' => t('Mono node group 4'),
      ),
	  'nhpid_group_mono_node_group5' => array(
        'title' => t('Mono node group 5'),
      ),
	  'nhpid_group_mono_node_group6' => array(
        'title' => t('Mono node group 6'),
      ),
	  'nhpid_group_field_collection_group1' => array(
        'title' => t('Field collection group 1'),
      ),
	  'nhpid_group_accessory_tales' => array(
        'title' => t('Accessory Tables'),
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
	'source_database' => array(
    'driver' => 'mysql',
    'database' => 'old_nhpid',
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
	'group_name' => 'nhpid_group_1',
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
	'group_name' => 'nhpid_group_1',
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
  
  // node data
  // Tell the node migrations where the users are coming from, so they can
  // set up the dependency and resolve D6->D7 uids.
  $common_node_arguments = $common_arguments + array(
      'user_migration' => 'User'
    );
  $code_node_group1_arguments = array();
  foreach ($code_node_group_1 as $type => $class){
	 $code_node_group1_arguments[$type] = array(
      'class_name' => $class,
      'description' => t("Migration of code $type"),
      'source_type' => $type,
      'destination_type' => $type,
	  'group_name' => 'nhpid_group_code_node_group1',
    );
  }
  
  foreach ($code_node_group1_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }
  $code_node_group2_arguments = array();
  foreach ($code_node_group_2 as $type => $class){
	 $code_node_group2_arguments[$type] = array(
      'class_name' => $class,
      'description' => t("Migration of code $type"),
      'source_type' => $type,
      'destination_type' => $type,
	  'group_name' => 'nhpid_group_code_node_group2',
    );
  }
  foreach ($code_node_group2_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }

  $code_node_group3_arguments = array();
  foreach ($code_node_group_3 as $type => $class){
	 $code_node_group3_arguments[$type] = array(
      'class_name' => $class,
      'description' => t("Migration of code $type"),
      'source_type' => $type,
      'destination_type' => $type,
	  'group_name' => 'nhpid_group_code_node_group3',
    );
  }
  foreach ($code_node_group3_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }
  
  $code_node_group4_arguments = array();
  foreach ($code_node_group_4 as $type => $class){
	 $code_node_group4_arguments[$type] = array(
      'class_name' => $class,
      'description' => t("Migration of code $type"),
      'source_type' => $type,
      'destination_type' => $type,
	  'group_name' => 'nhpid_group_code_node_group4',
    );
  }
  foreach ($code_node_group4_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }
  
  $data_node_group1_arguments = array();
  foreach ($data_node_group_1 as $type => $class){
	 $data_node_group1_arguments[$type] = array(
      'class_name' => $class,
      'description' => t("Migration of code $type"),
      'source_type' => $type,
      'destination_type' => $type,
	  'group_name' => 'nhpid_group_data_node_group1',
    );
  }
  foreach ($data_node_group1_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }
  
  $data_node_group2_arguments = array();
  foreach ($data_node_group_2 as $type => $class){
	 $data_node_group2_arguments[$type] = array(
      'class_name' => $class,
      'description' => t("Migration of code $type"),
      'source_type' => $type,
      'destination_type' => $type,
	  'group_name' => 'nhpid_group_data_node_group2',
    );
  }
  foreach ($data_node_group2_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }
  
  $data_node_group3_arguments = array();
  foreach ($data_node_group_3 as $type => $class){
	 $data_node_group3_arguments[$type] = array(
      'class_name' => $class,
      'description' => t("Migration of code $type"),
      'source_type' => $type,
      'destination_type' => $type,
	  'group_name' => 'nhpid_group_data_node_group3',
    );
  }
  foreach ($data_node_group3_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }
  
  $mono_node_group1_arguments = array();
  foreach ($data_mono_data_group_1 as $type => $class){
	 $mono_node_group1_arguments[$type] = array(
      'class_name' => $class,
      'description' => t("Migration of code $type"),
      'source_type' => $type,
      'destination_type' => $type,
	  'group_name' => 'nhpid_group_mono_node_group1',
    );
  }
  foreach ($mono_node_group1_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }
  $mono_node_group2_arguments = array();
  foreach ($data_mono_data_group_2 as $type => $class){
	 $mono_node_group2_arguments[$type] = array(
      'class_name' => $class,
      'description' => t("Migration of code $type"),
      'source_type' => $type,
      'destination_type' => $type,
	  'group_name' => 'nhpid_group_mono_node_group2',
    );
  }
  foreach ($mono_node_group2_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }
  $mono_node_group3_arguments = array();
  foreach ($data_mono_data_group_3 as $type => $class){
	 $mono_node_group3_arguments[$type] = array(
      'class_name' => $class,
      'description' => t("Migration of code $type"),
      'source_type' => $type,
      'destination_type' => $type,
	  'group_name' => 'nhpid_group_mono_node_group3',
    );
  }
  foreach ($mono_node_group3_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }
  $mono_node_group4_arguments = array();
  foreach ($data_mono_data_group_4 as $type => $class){
	 $mono_node_group4_arguments[$type] = array(
      'class_name' => $class,
      'description' => t("Migration of code $type"),
      'source_type' => $type,
      'destination_type' => $type,
	  'group_name' => 'nhpid_group_mono_node_group4',
    );
  }
  foreach ($mono_node_group4_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }
  $mono_node_group5_arguments = array();
  foreach ($data_mono_data_group_5 as $type => $class){
	 $mono_node_group5_arguments[$type] = array(
      'class_name' => $class,
      'description' => t("Migration of code $type"),
      'source_type' => $type,
      'destination_type' => $type,
	  'group_name' => 'nhpid_group_mono_node_group5',
    );
  }
  foreach ($mono_node_group5_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }
  $mono_node_group6_arguments = array();
  foreach ($data_mono_data_group_6 as $type => $class){
	 $mono_node_group6_arguments[$type] = array(
      'class_name' => $class,
      'description' => t("Migration of code $type"),
      'source_type' => $type,
      'destination_type' => $type,
	  'group_name' => 'nhpid_group_mono_node_group6',
    );
  }
  foreach ($mono_node_group6_arguments as $migration_name => $arguments) {
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
	$field_collection_fields= array(
		'field_fc_use_dependency' => array('mono_use'),
		'field_fc_cas_number' => array('herbal_hcn', 'naming_chemical','naming_protein', 'nonnhp_chemical'),
		'field_fc_chem_mn_sc_org_part'=>array('mono_entry'),
		'field_fc_chem_mon_src_ad_sc_e'=>array('mono_entry'),
		'field_fc_chem_mon_src_ad_sc_f'=>array('mono_entry'),
		'field_fc_chem_mon_src_adt_ing'=>array('mono_entry'),
		'field_fc_chem_mon_src_ing'=>array('mono_entry'),
		'field_fc_common_name_e'=>array('mono_entry'),
		'field_fc_common_name_f'=>array('mono_entry'),
		'field_fc_org_mon_src_part'=>array('mono_entry'),
		'field_fc_proper_name_e'=>array('mono_entry'),
		'field_fc_proper_name_f'=>array('mono_entry'),
		'field_fc_subingredient_source'=>array('mono_entry'),
		'field_fc_common_name'=>array('nonnhp_organism', 'naming_chemical','naming_protein', 'nonnhp_chemical'),
		'field_fc_dose_dependency'=>array('mono_dose', 'mono_dose_combination'),
		'field_fc_duration_dependency'=>array('mono_duration'),
		'field_fc_excluded_item'=>array('naming_org_group'),
		'field_fc_for_use_dependency'=>array('mono_direction_for_use'),
		'field_fc_included_item'=>array('naming_org_group'),
		'field_fc_proper_name'=>array('nonnhp_organism', 'naming_chemical','naming_protein', 'nonnhp_chemical'),
		'field_fc_risk_dependency'=>array('mono_risk'),
		'field_fc_synonym_e'=>array('nonnhp_organism', 'naming_chemical','naming_protein', 'nonnhp_chemical','herbal_hcn','naming_organism', 'naming_org_substance'),
		'field_fc_synonym_f'=>array('nonnhp_organism', 'naming_chemical','naming_protein', 'nonnhp_chemical','herbal_hcn','naming_organism', 'naming_org_substance'),
		'field_fc_taxon'=>array('naming_organism','nonnhp_organism'),
	);
	foreach($field_collection_fields as $type=>$dependencies){
		$api['migrations'][$type] = $common_arguments + array(
		'description' => t('Migration of field collection field_notes'),
		'class_name' => 'NHPIDFCMigration',
		'source_type' => $type,
		'destination_type' => $type,
		'group_name' => 'nhpid_group_field_collection_group1',
		'dependencies'=>$dependencies,
		);
	}
	/*
	$api['migrations_6']['FCPCI'] = $common_arguments + array(
    'description' => t('Migration of field collection field_pci'),
    'class_name' => 'ACPCIMigration',
	);
	*/
	
	 // table nhpid_excel_drupal_field_mapping
	$api['migrations']['excel_field_mapping'] = $common_arguments + array(
    'description' => t('Migrate nhpid_excel_drupal_field_mapping'),
	'group_name' => 'nhpid_group_accessory_talbes',
	'excel_field_mapping' => 'Excel field mapping',
	'class_name' => 'NHPIDExcelFieldMappingMigration',
  );

  return $api;
}
