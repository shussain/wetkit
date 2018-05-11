# delete empty field_collection_field_items
$fields=field_info_field_map();
foreach($fields as $field_name => $field_info){
	if ($field_info['type'] != 'field_collection'){
		continue;
	}
	//$field_name='field_fc_cas_number';
	$value_field=$field_name . '_value';
	$table = 'field_data_'. $field_name;
	$query = "select count(1) as item_count from $table";
	$results =db_query($query);
	if ($results->rowCount()>0){
		$rc=$results->fetchObject();
		dpm("$table has " . $rc->item_count . " records in total");
	}
	$query = "select count(1) as item_count from $table where $value_field not in(select item_id from field_collection_item)";
	$results =db_query($query);
	if ($results->rowCount()>0){
		$rc=$results->fetchObject();
		dpm("$table has " . $rc->item_count . " records witch are not referred by field_collection_items");
	}
	/*
	$query = "select entity_type, entity_id, deleted,language,delta,$value_field from $table where $value_field not in(select item_id from field_collection_item)";
	$results =db_query($query);
	if ($results->rowCount()>0){
		while($rc=$results->fetchObject()){
			
			$delete_query = "delete from $table where $value_field=".$rc->$value_field;
			//dpm ($delete_query);
			db_query($delete_query);
			//break;
		}
		//break;
	}
	*/
}
