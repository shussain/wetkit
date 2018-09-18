/**
* Reset its_ids. The new its_ids (its task nids) are mapped in table [its_database].nid_legacy_nid_chili_id_mapping
**/
$its_database='oa_nnhpd_its';
$nhpid_database='wetkit_nhpid';
$table_name='field_data_field_its_ids'; // db_merge does not take database prefix, such as db_name.table_name

$query=<<<QUERY
select entity_type, deleted, language, entity_id, delta, field_its_ids_title, nid, legacy_nid, chili_issue_id 
from $nhpid_database.field_data_field_its_ids 
join $its_database.nid_legacy_nid_chili_id_mapping on field_data_field_its_ids.field_its_ids_title=nid_legacy_nid_chili_id_mapping.legacy_nid
or field_data_field_its_ids.field_its_ids_title=nid_legacy_nid_chili_id_mapping.chili_issue_id
QUERY;
dpm($query);

$result=db_query($query);
$nhpid_its_url=variable_get("nhpid_its_url", '');
while($record = $result->fetchObject()) {
    print_r($record);
	$nid=$record->nid;
	$legacy_nid=$record->legacy_nid;
	$chili_issue_id=$record->chili_issue_id;
	$entity_type=$record->entity_type;
	$deleted=$record->deleted;
	$language=$record->language;
	$entity_id=$record->entity_id;
	$delta=$record->delta;
	$field_its_ids_title=$record->field_its_ids_title;
	$new_field_its_ids_title=$nid;
	
	$new_nhpid_its_url='';
	if($nhpid_its_url){
		$new_field_its_ids_url=str_replace('#', $new_field_its_ids_title,$nhpid_its_url);
	}
	
	db_merge($table_name)
	->key(array('entity_type'=>$entity_type,'deleted'=>$deleted, 'entity_id'=>$entity_id,'language'=>$language, 'delta'=>$delta))
	->updateFields(array('field_its_ids_title'=>$new_field_its_ids_title,'field_its_ids_url'=>$new_field_its_ids_url))
	->execute();
	
	
	//break;
}

