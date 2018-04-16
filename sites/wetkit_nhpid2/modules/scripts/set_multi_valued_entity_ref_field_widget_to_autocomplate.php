
$types = get_all_nhpid_data_node_types();
foeach($types as $type){
	$instances=field_info_field_instances('node', $type);
	foreach($instances as $field_name => $settings){
		$field=field_info_field($field_name);
		if($field->type=='entityreference' and $field->cardinality==-1){
			$setting['widget']['module']='entityreference';
			$setting['widget']['type']='entityreference_autocomplete';
			$setting['widget']['settings']['match_operator']='CONTAINS';
			$setting['widget']['settings']['size']=60;
			$setting['widget']['settings']['path']='';
			dpm($setting);
			//field_update_instance($setting);
		}
	}
}