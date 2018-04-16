//modify node form and display

$types = get_all_nhpid_data_node_types();
foreach($types as $type=>$name){
	//create a field group called Hidden Fields
	$group = null;
	$group_name='group_hidden_fields';
	$group_label='Hidden Fields';
	$children=array('metatags','path');
	$legacy_field_instance = field_info_instance('node', 'field_legacy_nid', $type);
	if ($legacy_field_instance){
		$legacy_field_instance['widget']['type']='field_extrawidgets_hidden';
		$legacy_field_instance['display']['default']['type']='hidden';
		$legacy_field_instance['display']['teaser']['type']='hidden';
		$legacy_field_instance['display']['featured']['type']='hidden';
		field_update_instance($legacy_field_instance);
		$children[]='field_legacy_nid';
	}
	$parent_space_field_instance = field_info_instance('node', 'field_parent_space', $type);
	if ($parent_space_field_instance){
		$parent_space_field_instance['widget']['type']='field_extrawidgets_read_only';
		$parent_space_field_instance['display']['default']['type']='hidden';
		$parent_space_field_instance['display']['teaser']['type']='hidden';
		$parent_space_field_instance['display']['featured']['type']='hidden';
		field_update_instance($parent_space_field_instance);
		$children[]='field_parent_space';
	}
	$body_field_instance = field_info_instance('node', 'body', $type);
	if ($body_field_instance){
		$body_field_instance['widget']['type']='field_extrawidgets_hidden';
		$body_field_instance['display']['default']['type']='hidden';
		$body_field_instance['display']['teaser']['type']='hidden';
		$body_field_instance['display']['featured']['type']='hidden';
		field_update_instance($body_field_instance);
		$children[]='body';
	}
	if (field_group_exists($group_name, 'node', $type, 'form')){
		$group = field_group_load_field_group($group_name, 'node', $type, 'form');
		$group->format_type='tab';
		$group->children=$children;
	}
	else{
		$identifier="$group_name|node|$type|form";
		$group=(object)array(
			'identifier' => $identifier,
			'group_name' => $group_name,
			'entity_type' => 'node',
			'bundle' => $type,
			'mode' => 'form',
			'label' => $group_label,
			'children' => $children,
			'weight' => '100',
			'format_type' => 'tab',
			'format_settings' => array(
			  'formatter' => 'closed',
			  'instance_settings' => array(
				'description' => '',
				'classes' => 'group-hidden-fields field-group-fieldset',
				'required_fields' => 1,
			  ),
			),
		);
	}
	field_group_group_save($group);
}

//field_legacy_nid and field_legacy_item_id
foreach(array('field_legacy_nid',  'field_legacy_item_id') as $field){

	$legacy_field=field_info_field($field);
	foreach($legacy_field['bundles'] as $entity_type=> $bundles){
		foreach($bundles as $bundle){
			$field_instance = field_info_instance($entity_type, $field, $bundle);
			$field_instance['widget']['type']='field_extrawidgets_hidden';
			$field_instance['display']['default']['type']='hidden';
			$field_instance['display']['teaser']['type']='hidden';
			$field_instance['display']['featured']['type']='hidden';
			field_update_instance($field_instance);
		}
	}
}
//field_collection field display

foreach($types as $type=>$name){
	$instances=field_info_instances('node', $type);
	foreach($instances as $field_name => $instance){
		if ($instance['widget']['module']=='field_collection'){
			$instance['display']['default']['type']='field_collection_table_view';
			$instance['display']['default']['module']='field_collection_table_view';
			field_update_instance($instance);
		}
	}
}