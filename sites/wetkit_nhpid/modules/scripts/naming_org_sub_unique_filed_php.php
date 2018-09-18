$field_ingredient_name = $this->value;
$field_organism_parent = $this->entity->field_organism_parent[$this->langcode][0]['target_id'];
$field_org_group = $this->entity->field_org_group[$this->langcode][0]['target_id'];

$query = new EntityFieldQuery();
$query->entityCondition('entity_type', $this->entity_type)
  ->entityCondition('bundle', $this->entity->type);
if($this->entity->nid){
  $query->propertyCondition('nid', $this->entity->nid, '!=');
}
$query->fieldCondition($this->field['field_name'], 'value', $field_ingredient_name, '=');
if($field_organism_parent){
	$query->fieldCondition('field_organism_parent', 'target_id', $field_organism_parent, '=');
}
if($field_org_group){
	$query->fieldCondition('field_org_group', 'target_id', $field_org_group, '=');
}
$result = $query->execute();
if (isset($result['node'])) {
  $duplicated_nids = array_keys($result['node']);
  $msg = '' ;
  foreach($duplicated_nids as $duplicated_nid){
    $msg = $msg . l($duplicated_nid, 'node/' . $duplicated_nid, array('attributes'=>array('target'=>'_blank'))) . '<br>';
  }
  
  $this->set_error();
  drupal_set_message($msg, 'error');

} 
