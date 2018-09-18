<?php
function nhpid_web_service_resource() {
  $api = array(
	'nhpid_web_service' => array(
  		'operations' => array(
			'retrieve' => array(
				'help' => 'Retrieves NHPID web service info.',
				'file' => array(
					'type' => 'inc',
					'module' => 'nhpid_web_service',
					'name' => 'nhpid_web_service.services',
					),
				'callback' => 'nhpid_web_service_resource_retrieve',
				'access callback' => 'user_access',
				'access arguments' => array('access nhpid web service'),
				'access arguments append' => FALSE,
				'args' => array(
					array(
						'name' => 'bundle',
						'type' => 'string',
						'description' => 'Content type',
						//'source' => array('param'=>'bundle'),
						'source' => array('path' => 0),
						'optional' => TRUE,
					),
					array(
						'name' => 'data_cutoff',
						'type' => 'string',
						'description' => 'The earliest update or create date of node. Possible values: all, from_last_retrieval, datetime in Unix timestamp format.',
						//'source' => array('param'=>'data_cutoff'),
						'source' => array('path' => 1),
						'optional' => TRUE,
					),
				),
			),
			'index' => array(
				'help' => 'Retrieves NHPID web service info.',
				'file' => array(
					'type' => 'inc',
					'module' => 'nhpid_web_service',
					'name' => 'nhpid_web_service.services',
					),
				'callback' => 'nhpid_web_service_resource_retrieve',
				'access callback' => 'user_access',
				'access arguments' => array('access nhpid web service'),
				'access arguments append' => FALSE,
				'args' => array(
					array(
						'name' => 'bundle',
						'type' => 'string',
						'description' => 'Content type',
						'source' => array('param'=>'bundle'),
						//'source' => array('path' => 0),
						'optional' => TRUE,
					),
					array(
						'name' => 'workflow',
						'type' => 'array',
						'description' => 'workflow',
						'source' => array('param'=>'workflow'),
						//'source' => array('path' => 0),
						'optional' => TRUE,
					),
					array(
						'name' => 'data_cutoff',
						'type' => 'string',
						'description' => 'The earliest update or create date of node. Possible values: all, from_last_retrieval, datetime in Unix timestamp format.',
						'source' => array('param'=>'data_cutoff'),
						//'source' => array('path' => 1),
						'optional' => TRUE,
					),
				),
			),
			'create' => array(
				'help' => 'Create nhpid web service log.',
				'file' => array(
					'type' => 'inc',
					'module' => 'nhpid_web_service',
					'name' => 'nhpid_web_service.services',
					),
				'callback' => 'nhpid_web_service_request_process',
				'access callback' => 'user_access',
				'access arguments' => array('access nhpid web service'),
				'access arguments append' => FALSE,
				'args' => array(
					array(
						'name' => 'data',
						'type' => 'string',
						'description' => 'Log data in json',
						'source' =>'data',
						'optional' => FALSE,
					),
				),
			),
			'update' => array(
				'help' => 'Create nhpid web service log.',
				'file' => array(
					'type' => 'inc',
					'module' => 'nhpid_web_service',
					'name' => 'nhpid_web_service.services',
					),
				'callback' => 'nhpid_web_service_resource_retrieve',
				'access callback' => 'user_access',
				'access arguments' => array('access nhpid web service'),
				'access arguments append' => FALSE,
				'args' => array(
					 array(
					   'name' => 'id',
					   'type' => 'int',
					   'description' => 'The id of the log to update',
					   'source' => array('path' => '0'),
					   'optional' => FALSE,
					 ),
					array(
						'name' => 'data',
						'type' => 'string',
						'description' => 'Log data in json',
						'source' =>'data',
						'optional' => FALSE,
					),
				),
			),
		),
	),
  );

  return $api;
}

/**
 * [nhpid_web_service_resource_retrieve] definition.
 * Returns nhpid web service data
 * @param $bundle
 *   The  nhpid data type bundle.
 * @param $date_cutoff
 *   The earliest update or create date of node. Possible values: all, *   from_last_retrieval, datetime in Unix timestamp format.
 * @return array
 *	The nhpid data.
 */
function nhpid_web_service_resource_retrieve($bundle=null, $workflow_states=array('Published'), $date_cutoff='from_last_retrieval') {
	//ddl($bundle, '$bundle');
	//ddl($date_cutoff, '$date_cutoff');
	//ddl($workflow_states, '$workflow_states');
	$return_val = array();
	//$query = new EntityFieldQuery;
	$types=array($bundle=>$bundle);
	if(!$bundle){
		$types = get_all_nhpid_data_node_types();
		$types = array_slice($types, 60, 17);
	}

	foreach ($types as $type => $value) {
		$query=db_select('node', 'n')
		->fields('n', array('nid'));
		$query->leftJoin('field_data_field_workflow', 'wfn', 'n.nid = wfn.entity_id');
		$query->condition('n.type', $type);
		
		if ($workflow_states){
			$states=workflow_get_workflows_by_type($type)->states;
			$sids=array();
			foreach($states as $sid=>$state){
				foreach($workflow_states as $workflow_state){
					if ($state->state==$workflow_state){
						$sids[]=$state->sid;
					}
				}
			}
			$query->condition('wfn.field_workflow_value', $sids, 'IN');
		}
		
		if($date_cutoff){
			if ($date_cutoff=='from_last_retrieval'){
				$subquery = Clone($query);
				$query->leftJoin('nhpid_web_service_export_time', 'et', 'n.nid=et.nid');
				$query->isNull('et.nid');
				$subquery->innerJoin('nhpid_web_service_export_time', 'et', 'n.nid=et.nid and n.changed > et.export_date');
				$query->union($subquery);
				
			}
			elseif(is_timestamp($date_cutoff)){
				$query->condition('n.changed', $date_cutoff, '>=');
			}
		}
		
	
		$result=$query->execute();
		$nids=array();
		while($rc=$result->fetchObject()){
			$nids[]=$rc->nid;	
		}
		if(!empty($nids)){
			$sql='select nid from {node} where nid in (:nids)';
			$args=array(':nids' => $nids);
			$data = $data = get_all_node_by_type(NULL, $sql, $args, array('date_type' => 'nhpid_short_dash'));
			//ddl($data, '$data');

			//remove pseudo reference 'NA' from mono_citation and code_reference
			if ($type == 'mono_citation' or $type == 'code_reference'){
				$pseudo_node = nhpid_api_get_node_by_title_type('NA_NA', $type);
				unset($data[$pseudo_node->nid]);
			}
			$return_val[$type]=$data;
		}
		
	}

	//ddl($return_val);
  return $return_val;
}
/**
 * [nhpid_web_service_request_process] definition.
 * 
 * Returns nhpid web service data
 * @ param $data
 * Associative array with values in json format.
 * Keys:
 * 'op': required
 *   The  operation of consumer. Possible values: 
 *		feed_logs: feed back logs from consumer to server; 
 *		retrieve_content_types: retrieve all data content types from server; 
 *		retrieve_data: retrieves selected data from server.
 * 'params':
 * 	 Parameters used to retrieve nhpid data in json object format. Sub-keys:
 * 		'bundle': Required. 
 *					The nhpid data type. Effective only to op retrieve_data.
 *					
 *		'workflow_states': Optional. In json array format.
 *						Default: "Published, Validated"
 *			
 * 		'date_cutoff': The earliest update or create date of node. 
 *			Possible values: 
 *				'All': All nodes
 *				'from_last_retrival': Nodes which changed is greater than its *			   last retrieval time. 
 *				[datetime] in Unix timestamp format: Nodes which changed is *				greater than this time.
 * 'logs':
 * 		Error log generated in populating nhpid. In format:
 *		{"[nid]":[],"[nid]":["error 1","error2", "..."], ...} 
 *		
 * @return array
 *	The nhpid data or other data.
 */
function nhpid_web_service_request_process($data){
	ddl($data, '$data');
	$op_message=<<<EOT
		Param op is missing. One of the following values must be selected:
			feed_logs: feed back logs from consumer to server; 
			retrieve_content_types: retrieve all data content types from server; 
			retrieve_data: retrieves selected data from server.
EOT;
	if (!$data['op']){
		return services_error($op_message);
	}

	$op_php = json_decoding($data['op']);
	if (!$op_php){
		return services_error("Param op is invalid JSON format");
	}
	if(!in_array($op_php, array('feed_logs', 'retrieve_content_types', 'retrieve_data'))){
		return services_error("op value cannot be understood.\n" . $op_message);
	}
	switch($op_php){
		case 'retrieve_content_types':
			return get_all_nhpid_data_node_types();
			break;
		
		case 'retrieve_data':

			$params = json_decoding($data['params']);
			if (!$params){
				return services_error("Param params is invalid JSON format");
			}
			//ddl($params);
			$bundle=isset($params->bundle)? $params->bundle : null;
			$date_cutoff=isset($params->date_cutoff)?$params->date_cutoff : null;
			$workflow_states=isset($params->workflow_states)?$params->workflow_states : array('Published', 'Validated');
			return nhpid_web_service_resource_retrieve($bundle, $workflow_states, $date_cutoff);
			break;
		case 'feed_logs':
			return nhpid_web_service_resource_create_log($data);
			break;
	}
}

/**
 * [nhpid_web_service_resource_create_log] definition.
 * @param $logs
 *   The  nhpid data type bundle.
 * @return array
 *	The nhpid data.
 */
function nhpid_web_service_resource_create_log($data) {
	//ddl($data, '$data');
	$logs_json=$data['logs'];
	//ddl($logs_json, '$logs_json');
	$post_errors=array();
	$date = time();
	$logs_php = json_decoding($logs_json);
	if (!$logs_php){
		$post_errors[]= services_error("Invalid JSON format");
	}
	//ddl($logs_php);
	else{
		foreach($logs_php as $nid=>$errors){
			try{
				//export status
				$status=empty($errors)? 1:0;
				$post_err = _save_nhpid_web_service_export_status($nid,$date, $status);
				if($post_err){
					$post_errors[]=$post_err;
				}
				// error log
				if($status==0)
				{
					$node = node_load($nid);
					if ($node) {
						$type = $node -> type;
						$post_err = _nhpid_web_service_export_log($nid, $date, $type, implode($errors, '<br>'), 'error');
						if($post_err){
							$post_errors[]=$post_err;
						}
					}
					else{
						$post_errors[]="Node for nid $nid could not be found.";
					}
				}
			}
			catch(Exception $e){
				$post_errors[]=$e->getMessage();
			}
		}
	}
	
	//ddl($return_val);
	if ($post_errors){
		return services_error(drupal_json_encode($post_errors));
	}
	
  
}

function _nhpid_web_service_export_log($nid, $date, $type, $log, $error_type='error'){

	$table = 'nhpid_web_service_log';
	$record = array(
		'nid' => $nid,
		'export_date' => $date,
		'content_type' => $type,
		'log' => $log,
		'error_type' =>$error_type,
		);
	//$rtn = drupal_write_record($table, $record);
	$rtn=db_insert($table)
  	//->key(array('uid' => $user->uid, 'mid' => $mid))
  	->fields($record)
  	->execute();
	if (!$rtn){
		return "Log for nid $nid failed to be posted.";
	}
	return null;
	
}

function _save_nhpid_web_service_export_status($nid, $date, $status){
	//ddl($status);
	$table = 'nhpid_web_service_export_time';
	$rtn=db_merge($table)
	->key(array('nid'=>$nid))
	->fields(array(
	'nid'=>$nid,
	'status'=>$status,
	'export_date'=>$date))
	->execute();
	if (!$rtn){
		return "Export status for nid $nid failed to be posted.";
	}
	return null;
}
/**
 * Checks if a string is a valid timestamp.
 *
 * @param  string $timestamp Timestamp to validate.
 * 
 * @return bool
 */
function is_timestamp($timestamp)
{
	$check = (is_int($timestamp) OR is_float($timestamp))
		? $timestamp
		: (string) (int) $timestamp;
	return  ($check === $timestamp)
        	AND ( (int) $timestamp <=  PHP_INT_MAX)
        	AND ( (int) $timestamp >= ~PHP_INT_MAX);
}
/**
 * Decodes json
 *
 * @param  string $json. Json to validate.
 * 
 * @return decoded data or false is decoding fails.
 */
function json_decoding($json){
	$decoded=json_decode($json);
	if (json_last_error()!=JSON_ERROR_NONE){
		return False;
	}
	return $decoded;
}
