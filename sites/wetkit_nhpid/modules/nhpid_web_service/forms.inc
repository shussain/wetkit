<?php


function nhpid_web_service_setting_form($form, &$form_state){
	$setting = variable_get('nhpid_web_service_setting', array('cron_is_on' => 1, 'rest_url_get' => null, 'rest_url_post' => null,'error_log_age'=>182, 'nhpid_web_service_retrieve_ready_states'=>array()));
	$form['rest_url'] = array(
		'#type' => 'fieldset',
		'#title' => t('REST URL'),
		'#description'=>'RESTful web service endpoints',
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
	);
	$form['rest_url']['rest_url_get'] = array(
		'#type' => 'textfield',
		'#title' => t('NHPID web service get URL'),
		'#default_value' => $setting['rest_url_get'],
	);
	$form['rest_url']['rest_url_post'] = array(
		'#type' => 'textfield',
		'#title' => t('NHPID web service post URL'),
		'#default_value' => $setting['rest_url_post'],
	);
	$form['cron'] = array(
		'#type' => 'fieldset',
		'#title' => t('Cron Setting'),
		'#description'=>'Cron settings for manage web service logs',
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
	);
	$form['cron']['cron_is_on'] = array(
		'#type' => 'radios',
		'#title' => t('Turn on cron'),
		'#options' => array(0 => t('Off'), 1 => t('On')),
		'#default_value' => $setting['cron_is_on'],
	);
	$form['cron']['error_log_age'] = array(
		'#title' => t('Remove records older than'),
		'#type' => 'select',
		'#options' => array(7=>'A week', 31=>'A month', 182=>'6 Months', 365 => 'A year', 372 => 'Two years', 0=>'All'),
		'#default_value' => $setting['error_log_age'],
	);
	//$workflow = workflow_get_workflows_by_type('iid');
	//$workflow_states = workflow_get_workflow_state_names($workflow->wid);
	$workflow_states =array();

	
	$form['nhpid_web_service_retrieve_ready_states'] = array(
		'#type' => 'select',
		'#title' => t('Web service retrieve ready states'),
		'#options' => $workflow_states,
		'#description' => t('The workflow states of nodes which is ready to be exported to NHPID through RESTful web service'),
		'#default_value' => $setting['nhpid_web_service_retrieve_ready_states'],
	);
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Submit'),
		'#name' => 'query',
		'#submit' => array('nhpid_web_service_setting_form_submit'),
	);
	return $form;
}
function nhpid_web_service_log_clear_form($form, &$form_state){

	$older_than = 365;
	
	$form['older_than']=array(
		'#title' => t('Remove records older than'),
		'#type' => 'select',
		'#options' => array(1=>'1 day', 2=>'2 days', 7=>'A week', 31=>'A month', 182=>'6 Months', 365 => 'A year', 0=>'All'),
		'#default_value' => $older_than,
	);
	$form['clear_log'] = array(
		'#type' => 'submit',
		'#value' => t('Clear log'),
		'#name' => 'clear_log',
		'#submit' => array('nhpid_web_service_log_clear_log'),
		'#attributes' => array('onclick' => "return confirm('You are going to remove data migration logs. Continue?');"),
	);
	return $form;
}

function nhpid_web_service_log_form($form, &$form_state){
	//$form['#method'] = 'get';
	
	$lines_per_page = isset($_GET['lines_per_page']) ? $_GET['lines_per_page'] : (isset($form_state['values']['lines_per_page']) ? $form_state['values']['lines_per_page'] : 20);
	//dpm($lines_per_page);
	$form['lines_per_page']=array(
		'#title' => t('Records per page'),
		'#type' => 'select',
		'#options' => array(10=>10, 20=>20, 50=>50, 100=>100, 500=>500),
		'#default_value' => $lines_per_page,
	);
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Refresh'),
		'#name' => 'query',
		'#submit' => array('nhpid_web_service_log_form_submit'),
	);
	$summary_header = array(
		'export_date' =>  t('Date'), 'failed_nodes' => t('Failed Nodes'),
	);
	//dpm($summary_header);
	
	$summary_query = db_select('nhpid_web_service_log', 'l')
			-> fields('l')
			->orderBy('l.export_date', 'DESC');
	$summary_result = $summary_query->execute();
	$summary_rows = array();
	if ($summary_result){
		while($rc =$summary_result -> fetchObject()){
			$summary_date = format_date($rc -> export_date, 'custom', 'Y-m-d H:i:s');
			if (!array_key_exists($rc -> export_date, $summary_rows)){
				$summary_rows[$rc -> export_date]['export_date']=$summary_date;
				$summary_rows[$rc -> export_date]['failed_nodes']=0;
				
			}
			//$summary_rows[$summary_date]['export_date']['data']=$summary_date;

			$error_type = $rc -> error_type;
			if ($error_type=='error'){
				$summary_rows[$rc -> export_date]['failed_nodes']++;
			}

			
		}
		
	}
	
	//dpm(array_values($summary_rows));
	$header = array(
		'export_date' => array('data' => t('Date'), 'field' => 'l.export_date', 'sort' =>'desc'), 'nid' => array('data' =>t('NID'), 'field' => 'l.nid'), 'content_type' => array('data' =>t('Type'), 'field' => 'l.content_type'), 'error_type' => array('data' => t('Error Type'), 'field' => 'error_type'),
		'log' => array('data' => t('Log'), 'field' => 'log'),
	);
	$query = db_select('nhpid_web_service_log', 'l')
			-> fields('l');
	
	$selected_dates=array_values($form_state['values']['summary_table']);
	//dpm($selected_dates);
	if($selected_dates){
		$query -> condition('export_date', $selected_dates, 'IN');
	}
	
	$query = $query->extend('TableSort')->orderByHeader($header)->extend('PagerDefault')->limit($lines_per_page);
	$result = $query->execute();
	$rows = array();
	
	if ($result){
		while($rc =$result -> fetchObject()){
			$date = format_date($rc -> export_date, 'custom', 'Y-m-d H:i:s');
			$error_type = $rc -> error_type;
			$log = $rc -> log;
			$nid = $rc -> nid;
			$content_type = $rc -> content_type;
			$row = array(
				'export_date' => array('data' => $date),
				'nid' => array('data' => l($nid, "node/$nid")),
				'content_type' => array('data' => $content_type),
				'log' => array('data' => $log, 'style'=>$error_type=='error'? 'color:red;':'color:green',),
				'error_type' => array('data' => $error_type),
			);
			$rows[] = $row;
		}
	}
	//dpm($rows);
	
	$form['summary_table'] = array(
      '#type' => 'tableselect',
      '#header' => $summary_header,
      '#options' => $summary_rows,
      '#empty' => t('No Result.'),
	  '#caption' => t('Summary'),
	  '#js_select' => TRUE,
	  '#sticky' => TRUE,
    );
	
	$form['view-detail']=array(
    '#type' => 'submit',
    '#value' => t('View Detail'),
	'#submit' => array('nhpid_web_service_log_form_submit'),

	);

	$form['table'] = array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,
      '#empty' => t('Please select a date or dates from the summary table above'),
	  '#caption' => t('Log'),
	  '#sticky' => TRUE,
    );

    // ADD PAGER
	
    $form['pager'] = array('#markup' => theme('pager',  array( 'parameters'=>array( 'lines_per_page' => $lines_per_page, ))));
	return $form;
}
function nhpid_web_service_log_form_submit($form, &$form_state){
	//dpm($form_state);
	$form_state['lines_per_page'] = $form_state['values']['lines_per_page'];
	//$form_state['days_ago'] = $form_state['values']['days_ago'];
	//$form_state['error_only'] = $form_state['values']['error_only'];
	//$form_state['cache'] = FALSE;
	$form_state['rebuild'] = TRUE;
}

function nhpid_web_service_log_clear_log($form, &$form_state){
	$older_than = isset($_GET['older_than']) ? $_GET['older_than'] : (isset($form_state['values']['older_than']) ? $form_state['values']['older_than'] : 365);
	$time = time() - $older_than * 24 * 365;
	$num = db_delete('nhpid_web_service_log')->condition('export_date', $time, '<')->execute();
	$form_state['cache'] = FALSE;
	$form_state['rebuild'] = TRUE;
	drupal_set_message(t('!num records have been removed', array('!num'=> $num)));
}
function nhpid_web_service_setting_form_submit($form, &$form_state){
	//drupal_set_message(hci_md_dump($form_state, 'red', TRUE));
	$cron_on = $form_state['values']['cron_is_on'];
	$rest_url_get = $form_state['values']['rest_url_get'];
	$rest_url_post = $form_state['values']['rest_url_post'];
	$error_log_age = $form_state['values']['error_log_age'];
	$nhpid_web_service_retrieve_ready_states=$form_state['values']['nhpid_web_service_retrieve_ready_states'];
	variable_set('nhpid_web_service_setting', array('cron_is_on' => $cron_on, 'rest_url_get' => $rest_url_get, 'rest_url_post'=>$rest_url_post, 'error_log_age'=>$error_log_age, 'nhpid_web_service_retrieve_ready_states'=>$nhpid_web_service_retrieve_ready_states));
	$form_state['rebuild'] = TRUE;
}
