<?php

/**
 * Implements hook_drush_command().
 */
function nhpid_migrate_d2d_drush_command() {
  
  $items['nhpid-dms-migrate'] = array(
    'description' => 'Migrate NHPID DMS from D7 to another D7',
    'aliases' => array('ndm'),
    
    'options' => array(
	  'operation' => 'clear-only, import-only, clear-and-import. Default:import-only',
	  'update' =>'Process updating all imported items. Effective only for imports.',
	  'groups' =>'Comma delimited group names',
    ),
    'examples' => array(
      'drush ndm --operation=clear-only' => 'Clear NHPID Data nodes only.',
      'drush ndm --operation=--clear-and-import --update --groups=migrate_group1, migrate_group3'  => 'Clear all the NHPID data nodes first, them migrate them again.',
    ),
  );
  
  return $items;
}

/**
 * Callback for the drush-demo-command command
 */
function drush_nhpid_migrate_d2d_nhpid_dms_migrate(){
    
    
  // Option
  $operation = drush_get_option('operation', 'import-only');
  //print_r($operation);
  $groups=array(
      'nhpid_group_1' => 1,
	  'nhpid_group_code_node_group1' => 2,
	  'nhpid_group_code_node_group2' => 3,
	  'nhpid_group_code_node_group3' => 4,
	  'nhpid_group_code_node_group4' => 5,
	  'nhpid_group_data_node_group1' => 7,
	  'nhpid_group_data_node_group2' => 8,
	  'nhpid_group_data_node_group3' => 9,
	  'nhpid_group_mono_node_group1' => 10,
	  'nhpid_group_mono_node_group2' => 11,
	  'nhpid_group_mono_node_group3' => 12,
	  'nhpid_group_mono_node_group4' => 13,
	  'nhpid_group_mono_node_group5' => 14,
	  'nhpid_group_mono_node_group6' => 15,
	  'nhpid_group_field_collection_group1' => 16,
	  'nhpid_group_accessory_tables' => 17,
      );
  if(drush_get_option('groups', '')){
	  $groups=select_groups($groups);
  }
  //print_r($groups);
  $migrates=nhpid_migrate_d2d_get_migrates();
  $migrations = migrate_migrations();
  drush_set_option('strict', FALSE);
  switch($operation){
	  case 'clear-only':
	  case 'clear-and-import':
		print_r($operation);
		arsort($groups);
		foreach($groups as $group=>$weight){
			if(isset($migrates[$group])){
				foreach($migrates[$group] as $migrate){
					//User and Role are better not rolled back
					if($migrate == 'User' or $migrate=='Role'){
						continue;
					}
					$migration=$migrations[$migrate];
					while ($migration->importedCount() > 0){
						drush_invoke_process('@self', 'migrate-reset-status', array($migrate));
						drush_invoke_process('@self', 'migrate-rollback', array($migrate), array('feedback'=>'100 seconds'));
					}
				}
			}
		}
		//delete other nodes which are not migrated
		$types = get_all_nhpid_data_node_types();
		foreach($types as $type => $info){
			drush_invoke_process('@self', 'migrate-wipe', array($type),  array('feedback'=>'100 seconds'));
		}
		if($operation=='clear-only'){
			break;
		}
	  //case 'clear-and-import':
	  case 'import-only':
		print_r($operation);
		asort($groups);
		foreach($groups as $group=>$weight){
			print_r(t("Migrating @group...\n", array('@group'=>$group)));
			if(isset($migrates[$group])){
				foreach($migrates[$group] as $migrate){
					$migration=$migrations[$migrate];
					drush_invoke_process('@self', 'migrate-reset-status', array($migrate));
					if (drush_get_option('update')){
						drush_invoke_process('@self', 'migrate-import', array($migrate), array('update'=>True, 'feedback'=>'100 seconds'));
						if (method_exists($migration, 'getUnprocessedAndNeedsUpdateIds')){
							while ($migration->getUnprocessedAndNeedsUpdateIds()){
								$idlist=implode(',', $migration->getNeedsUpdateIds());
								drush_invoke_process('@self', 'migrate-import', array($migrate), array('update'=>True, 'idlist' =>$idlist, 'feedback'=>'100 seconds'));
							}
						}
					}
					else{
						drush_invoke_process('@self', 'migrate-import', array($migrate), array('feedback'=>'100 seconds'));
						if (method_exists($migration, 'getUnprocessedIds')){
							while ($migration->getUnprocessedIds()){
								$idlist=implode(',', $migration->getUnprocessedIds());
								//print_r($idlist);
								drush_invoke_process('@self', 'migrate-import', array($migrate), array('update'=>True, 'idlist' =>$idlist, 'feedback'=>'100 seconds'));
							}
						}
					}
					

					print_r(t("Migrating @migrate is processed once.\n", array('@migrate'=>$migrate)));
					
				}
			}
		}
		
	  break;
	  
	  default:
	  drush_set_error(t('I cannot understand the operation "@operation". Please use "clear-only, import-only, or clear-and-import"', array('@operation'=>$operation)));
	 
	  
  }
  
}

function nhpid_migrate_d2d_get_migrates($group=null){
	$query=db_select('migrate_status', 'm')
		->fields('m', array('machine_name', 'group_name'));

	if ($group){
		$query->condition('group_name', $group);
	}
	else{
		$query->condition('group_name', 'nhpid_group%', 'LIKE');
	}

	$result=$query->execute();
	$rtn=array();
	while($rc=$result->fetchObject()){
		$rtn[$rc->group_name][]=$rc->machine_name;
	}
	return $rtn;
}

function select_groups($groups){
	$selected_groups = array();
	foreach (explode(',', drush_get_option('groups', '')) as $group){
		$selected_groups[$group]=0;
	}
	return array_intersect_key($groups, $selected_groups);
}
