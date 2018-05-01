$types = get_all_nhpid_data_node_types();
foreach($types as $type=>$label){
	$variable_name='menu_options_' . $type;
	variable_set($variable_name, array());
}