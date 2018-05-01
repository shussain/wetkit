<?php

/**
 * Implements hook_drush_command().
 */
function tpd_migrate_d2d_drush_command() {
  
  $items['tpd-migrate'] = array(
    'description' => 'Migrate TPD from D7 to another D7',
    'aliases' => array('tpdm'),
    
    'options' => array(
	  'operation' => 'clear-only, import-only, clear-and-import. Default:import-only',
	  'update'=>'Process updating all imported items. Effective only for imports.',
	  'batch_size'=>'Integer, the number of records to be processed in one batch. Default: 1000',
    ),
    'examples' => array(
      'drush tpdm --operation=clear-only' => 'Clear NHPID Data nodes only.',
      'drush tpdm --operation=--clear-and-import' => 'Clear all the NHPID data nodes first, them migrate them again.',
    ),
  );
  
  return $items;
}

/**
 * Callback for the command
 */
function drush_tpd_migrate_d2d_tpd_migrate(){
    
    
  // Option
  $operation = drush_get_option('operation', 'import-only');
  // 
  $migrates=array(
      'Role_1' => 1,
	  'User_2' => 2,
	  'CodeAmendmentStatus_3' => 3,
	  'CodeTPStatus_3' => 4,
	  'TradingPartner_4' => 5,
	  'DelegatedUsers_5' => 7,
	  'OtherUsers_5' => 8,
	  'PrimaryUser_5' => 9,
      );
  $batch_size = drush_get_option('batch_size', '1000');
  $types = array('mi','combo','link_type','nhpid_ingredient','note_type','pci_type');
  $migrations = migrate_migrations();
  //print_r($migrations);
  drush_set_option('strict', FALSE);
  switch($operation){
	  case 'clear-only':
	  case 'clear-and-import':
		arsort($migrates);
		foreach($migrates as $migrate=>$order){
			
			//User and Role are better not rolled back
			if($migrate == 'User_2' or $migrate=='Role_1'){
				continue;
			}
			$migration=$migrations[$migrate];
			while ($migration->importedCount() > 0){
				drush_invoke_process('@self', 'migrate-reset-status', array($migrate));
				drush_invoke_process('@self', 'migrate-rollback', array($migrate), array('feedback'=>'100 seconds'));
			}
		}
		//delete other nodes which are not migrated
		
		foreach($types as $type => $info){
			drush_invoke_process('@self', 'migrate-wipe', array($type), array('feedback'=>'100 seconds'));
		}
		if($operation=='clear-only'){
			break;
		}
	  case 'clear-and-import':
	  case 'import-only':
		asort($migrates);
		//rollback
		foreach($migrates as $migrate => $order){
			$migration=$migrations[$migrate];
			drush_invoke_process('@self', 'migrate-reset-status', array($migrate));
			if (drush_get_option('update')){
				/*
				drush_invoke_process('@self', 'migrate-import', array($migrate), array('update'=>True, 'feedback'=>'100 seconds'));
				if (method_exists($migration, 'getUnprocessedAndNeedsUpdateIds')){
					while ($migration->getUnprocessedAndNeedsUpdateIds()){
						$idlist=implode(',', $migration->getNeedsUpdateIds());
						drush_invoke_process('@self', 'migrate-import', array($migrate), array('update'=>True, 'idlist' =>$idlist, 'feedback'=>'100 seconds'));
					}
				}
				*/
				if (method_exists($migration, 'getSourceIds')){
							$unprocessed_ids = $migration->getSourceIds();
							$unprocessed = count($unprocessed_ids);
							$processed = 0;
							$ids_chunks=array_chunk($unprocessed_ids, $batch_size);
							foreach ($ids_chunks as $ids_chunk){
								$idlist=implode(',', $ids_chunk);
								drush_invoke_process('@self', 'migrate-import', array($migrate), array('update'=>True, 'idlist' =>$idlist, 'feedback'=>'100 seconds'));
								$processed = $processed + count($ids_chunk);
								$remaining = $unprocessed_ids - $processed;
								print_r("Total: $unprocessed. Processed: $processed. Remaining: $remaining\n");
							}
							
						}
			}
			else{
				/*
				drush_invoke_process('@self', 'migrate-import', array($migrate), array('feedback'=>'100 seconds'));
				if (method_exists($migration, 'getUnprocessedIds')){
					while ($migration->getUnprocessedIds()){
						$idlist=implode(',', $migration->getUnprocessedIds());
						//print_r($idlist);
						drush_invoke_process('@self', 'migrate-import', array($migrate), array('update'=>True, 'idlist' =>$idlist, 'feedback'=>'100 seconds'));
					}
				}
				*/
				if (method_exists($migration, 'getSourceIds')){
							$unprocessed_ids = $migration->getSourceIds();
							$unprocessed = count($unprocessed_ids);
							$ids_chunks=array_chunk($unprocessed_ids, $batch_size);
							$processed = 0;
							//print_r($batch_size);
							foreach ($ids_chunks as $ids_chunk){
								$idlist=implode(',', $ids_chunk);
								//print_r($idlist);
								drush_invoke_process('@self', 'migrate-import', array($migrate), array('update'=>True,'idlist' =>$idlist, 'feedback'=>'100 seconds'));
								$processed = $processed + count($ids_chunk);
								$remaining = $unprocessed - $processed;
								print_r("Total: $unprocessed. Processed: $processed. Remaining: $remaining\n");
							}
						}
			}
			print_r(t("Migrating @migrate is processed once.\n", array('@migrate'=>$migrate)));
			
		}

		
	  break;
	  
	  default:
	  drush_set_error(t('I cannot understand the operation "@operation". Please use "clear-only, import-only, or clear-and-import"', array('@operation'=>$operation)));
	 
	  
  }
  
}
