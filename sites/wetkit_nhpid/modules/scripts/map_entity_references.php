
$types = get_all_nhpid_data_node_types();
$data = variable_get('nhpid_entityreference_fields_settings', array());
$out = array();
foreach($types as $type=>$type_name){
	foreach($data as $field=>$referred_types){
		if (isset($referred_types[$type])){
			$field_info_field = field_info_field($field);
			if (isset($field_info_field['bundles']['node'])){
				$bundle_nodes=$field_info_field['bundles']['node'];
				$bundle_nodes_name='';
				foreach($bundle_nodes as $bundle_node){
					$instance=field_info_instance('node', $field, $bundle_node);
					if(isset($types[$bundle_node])){
						$bundle_nodes_name[]=$types[$bundle_node] . '(field:' . $instance['label'] . "($field))";
					}
				}
				$out[$type_name]=theme_item_list(array('items' =>$bundle_nodes_name, 'title'=>'', 'type'=>'ul',  'attributes'=>array()));
			}
		
		}
	}
}
$header=array('Content Type', 'Used by Content Type(Field)');
$rows = array();
foreach($out as $content_type=>$used){
	$rows[]=array($content_type,$used);
}
$table = theme('table', array('header' => $header, 'rows' => $rows,'attributes' => array('width' => '100%')));

dpm($table);