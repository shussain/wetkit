$fc_fields = array();
$all_fields = field_info_field_map();
/*
foreach($all_fields as $field_name=>$info){
	if ((strpos($field_name, 'field_fc_')===0) and $info['type']=='field_collection'){
		$table = 'field_data_' . $field_name;
		db_delete($table)
		->execute();			
	}
}
*/
$result=array();
foreach($all_fields as $field_name=>$info){
	if ((strpos($field_name, 'field_fc_')===0) and $info['type']=='field_collection'){
		$table = 'field_data_' . $field_name;
		$result[$field_name] = db_select($table)->fields(NULL, array('field'))->countQuery()->execute()->fetchField();	
		
	}
}
dpm($result);