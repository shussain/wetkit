<?php


// Implementation of hook_variable_group_info
function hci_md_export_variable_group_info() {
  $groups['nhpid_web_service'] = array(
    'title' => t('NHPID Web Service'), 
    'description' => t('NHPID web service variables'), 
    'access' => 'administer site configuration', 
    'path' => array('admin/nhpid/web_service/web_service_variables', ),
  );
  $groups['nhpid_web_service_log'] = array(
    'title' => t('NHPID Web Service Log'), 
    'description' => t('NHPID web service log variables'), 
    'access' => 'export hci_md data setting', 
    'path' => array('admin/nhpid/web_service/web_service_log_variables', 'nhpid_web_service/web_service_log_setting'),
  );
  return $groups;
}

// Implementation of hook_variable_info
function hci_md_export_variable_info($options){
	$description  = t('The possible values this field can contain.');
	$variable = array();
	$workflow = workflow_get_workflows_by_type('iid');
	$workflow_states = workflow_get_workflow_state_names($workflow->wid);

	
	$variable['nhpid_web_service_retrieve_ready_states'] = array(
		'type' => 'select',
		'title' => t('Web service retrieve ready states (nhpid_web_service_retrieve_ready_states'),
		'options' => $workflow_states,
		'description' => t('The workflow state of IID which is ready to published to DHPID )' ),
		'group' => 'nhpid_web_service',
	);
	
	
	//export_log
	$variable['hci_md_export_log_max_records'] = array(
		'type' => 'select',
		'title' => t('The max number of records being kept (hci_md_export_log_max_records)'),
		'options' => array(1000=>1000, 2000=>2000, 5000=>5000, 10000=>10000, 50000=>50000, 0=>'unlimited'),
		'default' => 5000,
		'description' => t('The max number of records are kept. If the number of records exceeds the setting, older ones will be deleted automatically.'),
		'group' => 'hc_inspection_export_log',
	);
	
	//dpm($variable);
	return $variable;
}
