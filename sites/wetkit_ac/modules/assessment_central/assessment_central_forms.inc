<?php


//***  * The admin panel * ***

### style sheets from NHPID
global $nhpid_format_header;
global $nhpid_format_footer;
global $base_url;
$path = drupal_get_path('module', 'assessment_central');

$nhpid_format_header = <<<EOD
	<link href="$base_url/$path/css/nhpid/base.css" media="screen, print" rel="stylesheet" type="text/css" />
	<link href="$base_url/$path/css/nhpid/base-institution.css" media="screen, print" rel="stylesheet" type="text/css" />
	<link href="$base_url/$path/css/nhpid/dhp-mps.css" media="screen, print" rel="stylesheet" type="text/css" />
  <style>
  body{background-color:white;}
  #edit-export-preview a {text-decoration:underline;}
  #edit-assessment-central-html {background-color: rgb(221, 221, 221);}
  #edit-assessment-central-html legend {background:rgba(102, 51, 102, 0.3);}

  </style>
  <div class="page"><div class="core">

	<div class="center">
		<h1>Natural Health Products Ingredients Database</h1> 
EOD;
		
$nhpid_format_footer = <<<EOD
	</div>

	<div class="footer">
		<div class="footerline" ></div>	
 
	</div>
	
	</div>
EOD;




/***
 * NHPID data node  setting
 */ 
function assessment_central_data_node_type_form($form, &$form_state=NULL) {
  $trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
  $form['help'] = array(
    '#type' => 'item',
    '#markup' => t('This setting defines node types storing NHPID data.' ),
  );
  
  $node_types = array();
  $node_objs = node_type_get_types();
  foreach ($node_objs as $type => $obj) {
    $node_types[$type] = $obj -> name . " ($type)";
  }
  //drupal_set_message(assessment_central_api_dump($default_types, 'red', TRUE));
  $components = variable_get('assessment_central_data_node_types', NULL);
  $form['assessment_central_data_node_types'] = array(
    '#type' => 'checkboxes', 
    '#title' => 'NHPID data node types',
    '#options' => $node_types,
    '#default_value' => $components,
    '#required' => FALSE,
    '#description' => t('Check if the node type is a NHPID data node type.'),
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save setting')
  );
  
  //drupal_set_message(nhpid_api_dump($form, 'red', TRUE));
  return $form;
}
function assessment_central_data_node_type_form_submit($form, &$form_state) {
  $value = $form_state['values']['assessment_central_data_node_types'];
  variable_set("assessment_central_data_node_types", $value);
  $form_state['storage']['values'] = $form_state['values'];
}


/***
 * NHPID ITS link url setting
 */ 
function assessment_central_default_url_form($form, &$form_state=NULL) {
	$trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
  $form['help'] = array(
    '#type' => 'item',
    '#markup' => t('This functin sets default urls for links in exported HTML files' ),
  );
  $nhpid_id_url = variable_get('assessment_central_nhpid_id_url', 'http://was-int-01.hc-sc.gc.ca/nhpid-bdipsn-internal/ingredReq.do?id=:nhpid_id&lang=eng');
  $form['nhpid_id_url'] = array(
    '#type' => 'textfield',
    '#title' => t('NHPID ID URL'),
    '#default_value' => $nhpid_id_url,
    '#size' => 120,
    '#required' => TRUE,
    '#description' => t("Enter the NHPID at the NHPID database url in the format of 'http://was-int-01.hc-sc.gc.ca/nhpid-bdipsn-internal/ingredReq.do?id=:nhpid_id&lang=eng. Please replace the ingredient id with ':nhpid_id'. <em>:atid</em> must remain unchanged."),
  );
  
  $assessment_central_url = variable_get('assessment_central_assessment_central_url', 'http://was-int-01.hc-sc.gc.ca/nhpid-bdipsn-internal/ingredReq.do?atid=:atid&lang=eng');
  $form['assessment_central_assessment_central_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Assessment Central URL'),
    '#default_value' => $assessment_central_url,
    '#size' => 120,
    '#required' => TRUE,
    '#description' => t("Enter the Assessment Central url such as http://was-int-01.hc-sc.gc.ca/nhpid-bdipsn-internal/ingredReq.do?atid=:atid&lang=eng. <em>:atid</em> must remain unchanged."),
  );
  $usda_url = variable_get('assessment_central_usda_url', 'http://ndb.nal.usda.gov/ndb/foods/list');
  $form['assessment_central_usda_url'] = array(
    '#type' => 'textfield',
    '#title' => t('USDA URL'),
    '#default_value' => $usda_url,
    '#size' => 120,
    '#required' => TRUE,
    '#description' => t("Enter the USDA url such as http://ndb.nal.usda.gov/ndb/foods/list."),
  );
  $cnf_url = variable_get('assessment_central_cnf_url', 'http://webprod3.hc-sc.gc.ca/cnf-fce/index-eng.jsp');
  $form['assessment_central_cnf_url'] = array(
    '#type' => 'textfield',
    '#title' => t('CNF URL'),
    '#default_value' => $cnf_url,
    '#size' => 120,
    '#required' => TRUE,
    '#description' => t("Enter the CNF url such as http://webprod3.hc-sc.gc.ca/cnf-fce/index-eng.jsp."),
  );
  $cms_url = variable_get('assessment_central_cms_url_file', 'http://was7-int-ihs.hc-sc.gc.ca/nhpols/faces/jsp/browse/browse.jsp/:cms_id');
  $form['assessment_central_cms_url_file'] = array(
    '#type' => 'textfield',
    '#title' => t('CMS File URL'),
    '#default_value' => $cms_url,
    '#size' => 120,
    '#required' => TRUE,
    '#description' => t("Enter the CNF url such as http://was7-int-ihs.hc-sc.gc.ca/nhpols/faces/jsp/browse/browse.jsp/:cms_id"),
  );
  $cms_folder_url = variable_get('assessment_central_cms_url_folder', 'http://was7-int-ihs.hc-sc.gc.ca/nhpols/faces/jsp/browse/browse.jsp?id=:cms_id');
  $form['assessment_central_cms_url_folder'] = array(
    '#type' => 'textfield',
    '#title' => t('CMS Folder URL'),
    '#default_value' => $cms_folder_url,
    '#size' => 120,
    '#required' => TRUE,
    '#description' => t("Enter the CNF url such as http://was7-int-ihs.hc-sc.gc.ca/nhpols/faces/jsp/browse/browse.jsp?id=:cms_id"),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Default URLs'),
    '#weight' => 10,
  );
  return $form;
}
function assessment_central_default_url_form_validate___($form, &$form_state) {
  
  $nhpid_id_url = $form_state['values']['nhpid_id_url'];
  $assessment_central_html_url = $form_state['values']['assessment_central_assessment_central_url'];
  
}
function assessment_central_default_url_form_submit($form, &$form_state) {
  
  $form_state['storage']['values'] = $form_state['values'];
  variable_set("assessment_central_nhpid_id_url", $form_state['values']['nhpid_id_url']);
  variable_set("assessment_central_assessment_central_url", $form_state['values']['assessment_central_assessment_central_url']);
  variable_set("assessment_central_usda_url", $form_state['values']['assessment_central_usda_url']);
  variable_set("assessment_central_cnf_url", $form_state['values']['assessment_central_cnf_url']);
  variable_set("assessment_central_cms_url_file", $form_state['values']['assessment_central_cms_url_file']);
  variable_set("assessment_central_cms_url_folder", $form_state['values']['assessment_central_cms_url_folder']);
  if (variable_get('assessment_central_nhpid_id_url') == $form_state['values']['nhpid_id_url'] 
  and variable_get('assessment_central_assessment_central_url') == $form_state['values']['assessment_central_assessment_central_url'] 
  and variable_get('assessment_central_usda_url') == $form_state['values']['assessment_central_usda_url'] 
  and variable_get('assessment_central_cnf_url') == $form_state['values']['assessment_central_cnf_url']
  and variable_get('assessment_central_cms_url_file') == $form_state['values']['assessment_central_cms_url_file']
	and variable_get('assessment_central_cms_url_folder') == $form_state['values']['assessment_central_cms_url_folder']){
    drupal_set_message('Default urls have been saved.');
  }
  else {
    form_set_error('', 'Saving of default urls failed.');
  }
}

function regenerate_nodes_title($content_types){
	$operations = array();
    foreach ($content_types as $node_type) {
      if ($node_type) $operations[] = array('re_generate_title', array($node_type));
      //break;
    }
    //drupal_set_message(nhpid_api_dump($operations, 'red', TRUE));
    $batch = array(
      'operations' => $operations,
      'finished' => 'batch_re_gnerate_title_body_finished',
      // We can define custom messages instead of the default ones.
      'title' => t('Re-generating node title and body...'),
      'init_message' => t('Starting.'),
      'progress_message' => t('Processed @current out of @total node types.'),
      'error_message' => t('Title and body re-generation has encountered an error.'),
      'file' => drupal_get_path('module', 'assessment_central'). '/assessment_central_forms.inc',
    );

    
    batch_set($batch);
    batch_process();
}
function re_generate_title($node_type, &$context) {
  $sql = "SELECT nid FROM {node} WHERE type=:type order by nid desc";
  $result = db_query($sql, array(':type' => $node_type));
  $sql_count = "SELECT count(nid) FROM {node} WHERE type=:type order by nid desc";
  $count = db_query($sql_count, array(':type' => $node_type))->fetchCol();
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = $count;
  }
  foreach ($result as $row) {
    $node = node_load($row->nid);
    node_save($node);
   
    $context['results'][] = $node->nid . ' : ' . check_plain($node->title);
    $context['sandbox']['progress']++;
    $context['sandbox']['current_node'] = $node->nid;
    $context['message'] = check_plain("$node_type: $count nodes");
    
  }
   if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    //$context['finished'] = ($context['sandbox']['progress'] >= $context['sandbox']['max']);
  }

}

function batch_re_gnerate_title_body_finished($success, $results, $operations) {
  if ($success) {
    // Here we could do something meaningful with the results.
    // We just display the number of nodes we processed...
    $message = count($results) . ' processed.';
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = 'An error occurred while processing ' . $error_operation[0] . ' with arguments :' . print_r($error_operation[0], TRUE);
  }
  drupal_set_message($message);
}

/***
 * Rule archive and resstore
 */ 
function assessment_central_rule_archive_form($form, &$form_state=NULL) {
  $trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
  $form['#attributes'] = array('enctype' => "multipart/form-data");
  $data = !empty($form_state['values']['data']) ? $form_state['values']['data'] : '';
  $form['help']=array(
    '#type' => 'item',
    '#markup' => "This tool lets users to archive all rules to file and upload archived rule to Drupal. It is suggested that the rules should be archived after any additions and modifications.",
  );
  $form['archive']=array(
    '#type' => 'fieldset',
    '#title' => t('Archive rules'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE, 
  );    
  $form['archive']['archive']=array(
  '#type' => 'submit', 
  '#value' => t('Archive'), 
  );
  $form['upload']=array(
    '#type' => 'fieldset',
    '#title' => t('Restore Archived Rules'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE, 
  );  
  $form['upload']['file']=array(
    '#name' => 'files[file]',
		'#type' => 'file', 
    '#default_value' => $data,
    '#title' => t('Archived rule file'), 
  );
  $form['upload']['upload']=array(
    '#type' => 'submit', 
    '#value' => t('Upload'), 
  );
  return $form;
}

function assessment_central_rule_archive_form_submit($form, &$form_state) {
  //drupal_set_message(nhpid_api_dump($form_state, 'red', TRUE));
  switch ($form_state['clicked_button']['#value']) {
    case $form_state['values']['archive']:
      $rules = array();
      $rule_variable_id_root = 'assessment_central_';
      $sql ="select * from {variable} where name like :name ";
      $result = db_query($sql, array(':name' => $rule_variable_id_root . "%"));
      foreach ($result as $r) {
        $name = $r -> name;
        $value = variable_get($name, '');
        $rules[] = array('name' => $name, 'value' => $value);
      }
      $data = serialize($rules);
      //drupal_set_message(nhpid_api_dump($data, 'red', TRUE));
      $data = str_replace("\n", "~TEMP~", $data); // unserialize does not work with string contain '/n'
      $file = "assessment_central_rule_archive.txt";
      $uploaded_data_file_path =  "public://rules/";
      //$uploaded_data_file_split_path = $uploaded_data_file_path . '/split';
      $public_file_stream_wrapper = file_stream_wrapper_get_instance_by_scheme('public');
      if (!$public_file_stream_wrapper->dir_opendir($uploaded_data_file_path, null)) file_prepare_directory($uploaded_data_file_path, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
      file_unmanaged_save_data($data, "$uploaded_data_file_path/$file", FILE_EXISTS_REPLACE);

      $path = "$uploaded_data_file_path$file";
      assessment_central_download($path);
      

      break;
    case $form_state['values']['upload']:
      //drupal_set_message(nhpid_api_dump($form_state, 'red', TRUE));
      $file = file_save_upload('file');
      //drupal_set_message(nhpid_api_dump($file, 'red', TRUE));
      if ($file) {
        $data = file_get_contents($file -> destination);
        $data = str_replace("~TEMP~", "\n", $data);
        $rules = unserialize($data);
        foreach ($rules as $rule) {
          variable_set($rule['name'], $rule['value']);
        }
        drupal_set_message('The rules have been restored successfully.');
      }
      else {
        form_set_error('file', 'The rules have not been restored successfully. Please double check your archived file and try it again.');
      }
      break;
  }
  
  $form_state['storage']['values'] = $form_state['values'];
}


function assessment_central_update_nhpid_ingredients_form($form, &$form_state=NULL) {
	$trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
  $form['help']=array(
    '#type' => 'item', 
    '#markup' => "This tool updates NHPID ingredient list from an excel file. The name of the data sheet must be the first sheet or named as 'NHPID Ingredients', which containing 4 columns in the order of: <br>
            <ol>
            <li>INGRED_ID</li>
            <li>IINGRED_AUTHORIZED_NAME_ENG</li>
            <li>INGRED_AUTHORIZED_NAME_FR</li>
            <li>INGREDSPEC_CLASS_NAME</li>
            </ol>
            <p>
            This tool also reports retired ingredients (not available in the NHPID DB anymore). Please check the retired ingredient list and take proper measures.",
  );
  $form['#attributes'] = array('enctype' => "multipart/form-data");
  $form['upload_data_file'] = array (
    '#type' => 'file', 
    '#title' => t('Upload NHPID ingredients data file'),
    '#size' => 100,
    //'#required' => TRUE,
  );
  $batch_size = !empty($form_state['values']['batch_size']) ? $form_state['values']['batch_size'] : 50;
  $form['batch_size'] = array(
    '#type' => 'select', 
    '#default_value' => $batch_size,
    '#title' => "Batch size",
    '#description' => "Larger batch sizes may make the loading faster but use more mamory. If you have memory overflowing error, reduce batch size.",
    '#options' => array(1 => 1, 5 => 5, 10 => 10, 50 => 50, 100 => 100, 200 =>200),
    '#multiple' => false,
  );
  $re_indexing = !empty($form_state['values']['do_reindexing']) ? $form_state['values']['do_reindexing'] : 0;
  $form['do_reindexing'] = array(
    '#type' => 'checkbox', 
    '#default_value' => $re_indexing,
    '#title' => "Update Search Index?"
  );
  
  $form['upload-data-file-submit']=array(
    '#type' => 'submit', 
    '#value' => t('Upload'), 
    
    '#attributes' => array('onclick' => 'return confirm("You are going to update all NHPID Ingredient data. If the exsiting ingredients are not found in your data sheet, the workflow state of those ingredients wiil be changed to Obsolete. Are you sure you wish to continue?");'),
  ); 
  return $form;

}
function assessment_central_update_nhpid_ingredients_form_submit($form, &$form_state) {
    drupal_set_message('uploading file...');
    //drupal_set_message(nhpid_api_dump($form_state, 'red', TRUE));
    $limits = array ('extensions' => 'xls', 'file_size' => file_upload_max_size()) ;
    
    $validators = array(
      'assessment_central_upload_nhpid_ingrediets_file_validate' => array($limits['extensions'], $limits['file_size'],),
    );
    $uploaded_data_file = 'upload_data_file';
    //$uploaded_data_file_path = file_directory_temp() . "/uploaded_data_file";
    $uploaded_data_file_path =  "public://uploaded_data_file/";
    if (!is_dir($uploaded_data_file_path)) drupal_mkdir($uploaded_data_file_path);
    //$uploaded_data_file_split_path = $uploaded_data_file_path . '/split';
    $public_file_stream_wrapper = file_stream_wrapper_get_instance_by_scheme('public');
    if (!$public_file_stream_wrapper->dir_opendir($uploaded_data_file_path, null)) file_prepare_directory($uploaded_data_file_path, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
    if (user_access('administer assessment central') && $file = file_save_upload($uploaded_data_file, $validators, "$uploaded_data_file_path", FILE_EXISTS_REPLACE)) {
      $file_path = $file -> uri;
      //drupal_set_message(nhpid_api_dump($file, 'red', TRUE));
      //$lines_limit = $form_state['values']['lines_limit'];
      
      $re_indexing = $form_state['values']['do_reindexing'];
      $batch_size = $form_state['values']['batch_size'];
      aseessment_central_update_load_ingredient_data_batch($file_path, $re_indexing, $batch_size);
      //drupal_set_message(nhpid_api_dump("$file, $uploaded_data_file, $uploaded_data_file_path, $file_path", 'red', TRUE));
    }
    
    else {
      $msg = "File $uploaded_data_file cannot be uploaded.";
      form_set_error ('', $msg);
    }
    $form_state['storage']['values'] = $form_state['values'];
}
function assessment_central_upload_nhpid_ingrediets_file_validate($file, $extensions, $file_size){
  drupal_set_message('validating file...');
  $errors = array();
  $ext = pathinfo($file ->filename, PATHINFO_EXTENSION);
  //drupal_set_message("$ext, $extensions, $file_size");
  if ($ext != $extensions ) $errors[] = 'Only MS Excel 5 format (.xls) is allowed.';
  if ($file -> filesize > $file_size) $errors[] = "File is too large (" . $file -> filesize . "). Max limit is $file_size.";
  return $errors;
}

function aseessment_central_update_load_ingredient_data_batch($file_path, $re_indexing = false, $batch_size = 50) {
  ini_set('memory_limit', "2000M");
  $drupal_field_excel_mapping = array('field_ingred_id' => 'ingred_id', 'field_authorized_name_e' => 'ingred_authorized_name_eng', 'field_authorized_name_f' => 'ingred_authorized_name_fr', 'field_ingredspec_class_name'=> 'ingredspec_class_name');
  //Load PHPExcel
  module_load_include('inc', 'phpexcel');
  $library = libraries_load('PHPExcel');
  if (empty($library['loaded'])) {
    watchdog('phpexcel', "Couldn't find the PHPExcel library. Excel export aborted.", array(), WATCHDOG_ERROR);
	drupal_set_message("Couldn't find the PHPExcel library. Excel export aborted.");

    return;
  }
  
  //$cacheMethod = PHPExcel_CachedObjectStorageFactory::cache_in_memory_gzip;
  $cacheMethod = PHPExcel_CachedObjectStorageFactory::cache_to_phpTemp;
  
  $cacheSettings = array( 'memoryCacheSize' => '2GB', 'cacheTime' => 6000);
  PHPExcel_Settings::setCacheStorageMethod($cacheMethod, $cacheSettings);

  PHPExcel_Cell::setValueBinder(new PHPExcel_Cell_AdvancedValueBinder());
  
  
  $objReader =PHPExcel_IOFactory::createReader('Excel5');
  $objReader->setReadDataOnly(TRUE);
  $objPHPExcel = $objReader->load($file_path);
  $sheetname = 'NHPID INgredients';
  $sheet = $objPHPExcel -> getSheetByName($sheetname);
  if (!$sheet) $sheet = $objPHPExcel -> getSheet(0);
  $col1_title = strtolower($sheet -> getCell('A1') -> getValue());
  $col2_title = strtolower($sheet -> getCell('B1') -> getValue());
  $col3_title = strtolower($sheet -> getCell('C1') -> getValue());
  $col4_title = strtolower($sheet -> getCell('D1') -> getValue());
  $col_indexes = array($col1_title => 0, $col2_title => 1, $col3_title => 2, $col4_title => 3);
  //drupal_set_message(nhpid_api_dump($col_indexes , 'red', TRUE));
  foreach ($drupal_field_excel_mapping as $drupla_field => $excel_col_title){
    if (!in_array($excel_col_title, array_keys($col_indexes))){
      form_set_error('', t('The column titles of data sheet are not correct. The column titles must be: <em>@_titles</em>',  array(@_titles => implode(', ', array_values($drupal_field_excel_mapping)))));
      drupal_goto($_SERVER['HTTP_REFERER']);
    }
    else{
      $drupal_field_excel_mapping[$drupla_field] = $col_indexes[$excel_col_title];
    }
  }
  $highest_row = $sheet -> getHighestRow();
  $operations = array();
  $message = '';
  ## make existing nodes which are not in the nhpid ingredients list to unpublished
  $ingred_ids = array();
  for ($i = 2; $i <= $highest_row; $i ++){
    $excel_col_index=$drupal_field_excel_mapping['field_ingred_id'];
	$ingred_ids[]=trim($sheet -> getCellByColumnAndRow($excel_col_index, $i) -> getCalculatedValue());
  }
  //dpm($ingred_ids);
  if ($ingred_ids){
	  //$ingred_ids_str = implode(", ", $ingred_ids);
	  $node_type ='nhpid_ingredient';
	  $sql = "SELECT entity_id FROM {field_data_field_ingred_id} WHERE bundle=:type and field_ingred_id_value not in (:ingred_ids)";

	  $result = db_query($sql, array(':type' => $node_type, ':ingred_ids'=>$ingred_ids));
	  $count = $result->rowCount();
	  $batch_count = 0;
	  $nids_all = $result->fetchCol();
	  
	  $nids = array();
	  
	  foreach ($nids_all as $nid) {
		$batch_count ++;
		$nids[] = $nid;
		if ($batch_count != $count and $batch_count % $batch_size){
		  continue;
		}
		$operations[] = array('assessment_central_unpublish_nhpid_ingredient_nodes', array($nids, $batch_count, $count));
		$nids = array();
	  }
	  
  }
  $data = array();
  for ($i = 2; $i <= $highest_row; $i ++){
    $item = array();
    foreach($drupal_field_excel_mapping as $drupla_field => $excel_col_index){
      $item[$drupla_field] = trim($sheet -> getCellByColumnAndRow($excel_col_index, $i) -> getCalculatedValue());
    }
    $data[] = $item;
    if ($i != $highest_row and ($i -1) % $batch_size){
      continue;
    }
    $operations[] = array('assessment_central_create_nhpid_ingredient_node', array($data, $i, $highest_row - 1, $re_indexing));
    $data = array();
  }
 //dpm($operations);
  $batch = array(
    'operations' => $operations,
    'finished' => 'assessment_central_batch_finished',
    // We can define custom messages instead of the default ones.
    'title' => t('Processing uploading NHPID ingredients data'),
    'init_message' => t('Processing old data is starting.'),
    'progress_message' => t('Processed @current out of @total steps.'),
    'error_message' => t('Data loading has encountered an error.'),
    'file' => drupal_get_path('module', 'assessment_central'). '/assessment_central_forms.inc',
  );
  
  
  batch_set($batch);
  //batch_process();
  $objPHPExcel->disconnectWorksheets();
  unset($objPHPExcel);


}

function assessment_central_create_nhpid_ingredient_node($data, $done, $remaining, $re_indexing = false, &$context){
  //drupal_set_message(nhpid_api_dump($data , 'red', TRUE));
  if (!isset($context['results'])) {
    $context['results'] = array('attempted' => 0, 'success' => 0);
    
  }
  $context['sandbox']['max'] = 1;
  $context['results']['attempted'] ++;
  foreach($data as $item){
    if (empty($item)) continue;
	$type='nhpid_ingredient';
	$name_e=$item['field_authorized_name_e'];
	$name_f=$item['field_authorized_name_f'];
	$title="$name_e" .'_' . $name_f;
	$node=reset(node_load_multiple(array(),array('title' => $title, 'type' => $type)));
	if (!$node){
		$node = new stdClass();
		$node->type = $type;
		$node->title = $title;
		$node->language = LANGUAGE_NONE;
		$node->uid = null;
		node_object_prepare($node);
		$node -> is_new = TRUE;
	}
	$node->status = 1;
	$node->promote = 0;
    $wid = workflow_get_workflows_by_type($node->type) -> wid;
	$sid=workflow_state_load_by_name('published', $wid)->sid;
   
    $wrapper = entity_metadata_wrapper('node', $node);
	$wrapper->field_workflow->set($sid);
    foreach($item as $drupal_field => $value){
      $wrapper -> {$drupal_field}->set($value);
    }
    $wrapper->save();
    //workflow_execute_transition($node, $sid, $comment = "Initial data load", $force = TRUE);
    
    if ($re_indexing) nhpid_api_index_node($node);
    //drupal_set_message(nhpid_api_dump($node, 'red', TRUE));
    ## update the ingred_id field of MI nodes
    assessment_central_set_mi_ingred_id($node);
    unset($node);
  }
  unset($data);
  $context['results']['success'] ++;
  // Optional message displayed under the progressbar.
  $context['message'] = t('Created %done nhpid_ingredient nodes of %remaining.', array('%done' => $done, '%remaining' => $remaining));
  if ($context['results']['attempted'] != $context['sandbox']['max']) {
    $context['finished'] = ($context['results']['attempted'] >= $context['sandbox']['max']);
  }
  
}

function assessment_central_unpublish_nhpid_ingredient_nodes($nids, $done, $remaining, &$context){
  if (!isset($context['results'])) {
    $context['results'] = array('attempted' => 0, 'success' => 0);

  }
  $context['sandbox']['max'] = 1;
  $context['results']['attempted'] ++;
  // Change workflow state to Obsolete
  foreach($nids as $nid){
		$node = node_load($nid);
		$wid = workflow_get_workflows_by_type($node->type) -> wid;
		$sid=workflow_state_load_by_name('obsolete', $wid)->sid;
   		$wrapper = entity_metadata_wrapper('node', $node);
		$wrapper->field_workflow->set($sid);
		$wrapper->save();
  }
  $context['results']['success'] ++;

  unset($nids);
  // Optional message displayed under the progressbar.
  $context['message'] = t('Unpublished @done nhpid_ingredient nodes of @remaining.', array('@done' => $done, '@remaining' => $remaining));
  $context['results']['remaining']=$remaining;
  if ($context['results']['attempted'] != $context['sandbox']['max']) {
    $context['finished'] = ($context['results']['attempted'] >= $context['sandbox']['max']);
  }
}

function assessment_central_batch_finished($success, $results, $operations) {
  if ($success) {
    if ($results['success'] == $results['attempted']) {
      $message = t('Finished @success steps of updating NHPID ingredients successfully.', array('@success' => $results['success']));
    }
    else {
      $message = t('Finished @success of @attempted of updating NHPID ingredients successfully. @remaining to be deleted', array('@success' => $results['success'], '@attempt' => $results['attempted'], '@remaining' => $results['remaining']));
    }
    // reset retured nhpid names (names not available in the nhpid db anymore)
    $retired_nhpid_names = assessment_central_fetch_retired_nhpid_names();
    if ($retired_nhpid_names){
      $links = array();
      foreach($retired_nhpid_names as $nid => $nhpid_name){
        $links[] = l($nhpid_name, "node/$nid", array('attributes' => array('target' => '_blank')));
		// change workflow state to Obsolete
		$node = node_load($nid);
		$wid = workflow_get_workflows_by_type($node->type) -> wid;
		$sid=workflow_state_load_by_name('obsolete', $wid)->sid;
   		$wrapper = entity_metadata_wrapper('node', $node);
		$wrapper->field_workflow->set($sid);
		$wrapper->save();
      }
      $list = theme_item_list(array('items' => $links, 'title' => '', 'type' => 'ul', 'attributes' => array()));
      $message = $message . "<br> However, the following nhpid names have been retired in current NHPID database. Those MI nodes have been changed to Obsolete.";
      $message = $message . $list;
	  
    }
    $retired_combo_names = assessment_central_fetch_combos_containing_retired_nhpid_names();
    if ($retired_combo_names){
      $links = array();
      foreach($retired_combo_names as $nid => $combo){
        foreach($combo as $item){
          $links[] = l($item['nhpid_name'] . ' in ' . $item['combo_name'], "node/$nid", array('attributes' => array('target' => '_blank')));
        }
		// change workflow state to Obsolete
		$node = node_load($nid);
		$wid = workflow_get_workflows_by_type($node->type) -> wid;
		$sid=workflow_state_load_by_name('obsolete', $wid)->sid;
   		$wrapper = entity_metadata_wrapper('node', $node);
		$wrapper->field_workflow->set($sid);
		$wrapper->save();
      }
      $list = theme_item_list(array('items' => $links, 'title' => '', 'type' => 'ul', 'attributes' => array()));
      $message = $message . "<br> And, the following combinations containing those retired NHPID names. The state of those Combinations are changed to Obsolete.";
      
      $message = $message . $list;
    }
    if ($retired_nhpid_names or $retired_combo_names){
      $message = $message ."Please have a look at those nodes and correct them as soon as possible.<br>";
    }
    
    // set all nhpid ingredient authorized_name_e in variable assessment_central_nhpid_authorized_names_e
    assessment_central_set_variable_nhpid_authorized_names_e_values();
  }
  else {
    $message = t('Updating NHPID ingredients encounters an error.');
  }
  drupal_set_message($message);
}
function assessment_central_export_page($node = NULL){
  $from=drupal_get_form('assessment_central_export_tab_form', $node);
  return drupal_render($from);
}

function assessment_central_export_tab_form($form_id, &$form_state, $node = NULL){
  global $nhpid_format_header;
  global $nhpid_format_footer;
  $trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
  $current_state = get_node_current_state_state($node);
  if ($current_state != 'Published'){
    form_set_error('', t('The state of this node is :current_state. It must be </em>Published</em>.', array(':current_state' => $current_state)));
    drupal_goto($_SERVER['HTTP_REFERER']);
  }
  $assessment_central_html_info = assessment_central_fetch_info_for_export($node);
  $assessment_central_html_e = assessment_central_format_export_info($node, null, true, $assessment_central_html_info, 'e');
  $assessment_central_html_f = assessment_central_format_export_info($node, null, true, $assessment_central_html_info, 'f');
  $export_history = !empty($form_state['values']['assessment_central_export_history'])? $assessment_central_html = $form_state['values']['assessment_central_export_history'] : NULL;
  
  
  if ($assessment_central_html_info){
    ## save file for downloading
    $file_names = assessment_central_export_file_name($node);
    $uploaded_data_file_e = $file_names['e'];
    $uploaded_data_file_f = $file_names['f'];   
    $uploaded_data_file_path =  "public://download_html_file/";
    if (!is_dir($uploaded_data_file_path)) drupal_mkdir($uploaded_data_file_path);
    //$uploaded_data_file_split_path = $uploaded_data_file_path . '/split';
    $public_file_stream_wrapper = file_stream_wrapper_get_instance_by_scheme('public');
    if (!$public_file_stream_wrapper->dir_opendir($uploaded_data_file_path, null)) file_prepare_directory($uploaded_data_file_path, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
    $destination_e = file_destination("$uploaded_data_file_path/$uploaded_data_file_e", FILE_EXISTS_RENAME);
    $destination_f = file_destination("$uploaded_data_file_path/$uploaded_data_file_f", FILE_EXISTS_RENAME);    
    file_unmanaged_save_data($assessment_central_html_e, $destination_e, FILE_EXISTS_REPLACE);
    file_unmanaged_save_data($assessment_central_html_f, $destination_f, FILE_EXISTS_REPLACE);
    /*$form['assessment_central'] = array(
      '#weight' => 50,
      '#type' =>'fieldset',
      '#title' => 'Preview of exported HTML',
      '#collapsible' => TRUE, 
      '#collapsed' => FALSE,
      
    );*/
    $form['assessment_central_html'] = array(
      '#type' => 'fieldset',
      '#title' => 'HTML file preview',
      '#collapsible' => true, 
      '#collapsed' => FALSE,
    );
    
    $form['assessment_central_html']['export-preview'] = array(
      '#type' => 'item',
      '#title' => '',
      '#markup' => $nhpid_format_header . $assessment_central_html_e . $nhpid_format_footer,
    );
    
    $form['assessment_central_html_download_path_e'] = array(
      '#type' => 'hidden',
      '#title' => '',
      '#value' => "$destination_e",
    );
    $form['assessment_central_html_download_file_e'] = array(
      '#type' => 'hidden',
      '#title' => '',
      '#value' => "$uploaded_data_file_e",
    );
    $download_path_e = l($uploaded_data_file_e, "rule_management/node_export_download/$uploaded_data_file_path/$uploaded_data_file_e", array('attributes' => array('target' => '_blank')));
    /*
    $form['assessment_central_syntaxhighlighter'] = array(
      '#type' => 'text_format',
      '#title' => t('Description'),
      '#default_value' => $assessment_central_html,
      '#format' => 'syntex_highlighter',
      
    );*/
    $form['file_name_warning'] = array(
      '#type' => 'item',
      '#title' => '',
      '#markup' => "<em>You must use the pre-defined file names. For some browsers such as Chrome, file names may be changed when saving them. Please use the original file names. </em>",
    );
    $form['assessment_central_html_download_e_2'] = array(
      '#type' => 'submit',
      '#value' => 'Download English version',
      '#name' => 'e',
      '#executes_submit_callback' => true,
    );
    $form['assessment_central_html_download_f_2'] = array(
      '#type' => 'submit',
      '#value' => 'Download French version',
      '#name' => 'f',
      '#executes_submit_callback' => true,
    );
    $form['e'] = array(
      '#type' => 'fieldset',
      '#title' => 'English version',
      '#collapsible' => false, 
      '#collapsed' => FALSE,
    );
    $form['e']['assessment_central_html_box'] = array(
      '#type' => 'textarea',
      '#value' =>  $assessment_central_html_e,
      '#title' => 'HTML code ' . "(file name: $uploaded_data_file_e)",
      '#description' => "To save the code, right click the box and click 'Select All' and then 'Copy'. Please use <em>$uploaded_data_file_e</em> as file name.<br>
                          Or, click following button to download.",
    );
    $form['e']['assessment_central_html_download_e'] = array(
      '#type' => 'submit',
      '#value' => 'Download',
      '#name' => 'e',
      '#executes_submit_callback' => true,
    );
    $form['f'] = array(
      '#type' => 'fieldset',
      '#title' => 'French version',
      '#collapsible' => false, 
      '#collapsed' => FALSE,
    );
    $form['assessment_central_html_download_path_f'] = array(
      '#type' => 'hidden',
      '#title' => '',
      '#value' => "$destination_f",
    );
    $form['assessment_central_html_download_file_f'] = array(
      '#type' => 'hidden',
      '#title' => '',
      '#value' => "$uploaded_data_file_f",
    );
    $download_path_f = l($uploaded_data_file_f, "rule_management/node_export_download/$uploaded_data_file_path/$uploaded_data_file_f", array('attributes' => array('target' => '_blank')));
    /*
    $form['assessment_central_syntaxhighlighter'] = array(
      '#type' => 'text_format',
      '#title' => t('Description'),
      '#default_value' => $assessment_central_html,
      '#format' => 'syntex_highlighter',
      
    );*/
    
    
    $form['f']['assessment_central_html_box'] = array(
      '#type' => 'textarea',
      '#value' =>  $assessment_central_html_f,
      '#title' => 'HTML code ' . "(file name: $uploaded_data_file_f)",
      '#description' => "To save the code, right click the box and click 'Select All' and then 'Copy'. Please use <em>$uploaded_data_file_f</em> as file name.<br>
                          Or, click following button to download.",
    );
    $form['f']['assessment_central_html_download_f'] = array(
      '#type' => 'submit',
      '#value' => 'Download',
      '#name' => 'f',
      '#executes_submit_callback' => true,
    );
    $form['#submit'] = array('assessment_central_html_download_submit');
    
    assessment_central_add_export_history($node);
  }
  
  else {
    $form['assessment_central_error'] = array(
      '#type' => 'item',
      '#markup' => 'No data available',
      '#title' => 'HTML Code',
      
    );
  }
  return $form;
}

function assessment_central_html_download_submit($form, &$form_state){
  $path = '';
  $file = '';
  switch ($form_state['clicked_button']['#id']) {
    case "edit-assessment-central-html-download-f" :
    case "edit-assessment-central-html-download-f-2" :
    $path = $form_state['values']['assessment_central_html_download_path_f'];
    $file = $form_state['values']['assessment_central_html_download_file_f'];
    assessment_central_download($path, $file);
    break;

    case "edit-assessment-central-html-download-e" :
    case "edit-assessment-central-html-download-e-2" :
    $path = $form_state['values']['assessment_central_html_download_path_e'];
    $file = $form_state['values']['assessment_central_html_download_file_e'];
    assessment_central_download($path, $file);
    break;
    default:
  //drupal_set_message(nhpid_api_dump($path , 'brown', TRUE));
  }
  //assessment_central_download($path, $file);
}
function assessment_central_export_history_page($node, $vid= null){
  return drupal_render(drupal_get_form('assessment_central_export_history_tab_form', $node));
}
function assessment_central_export_history_tab_form($form_id, &$form_state, $node = NULL){
  global $nhpid_format_header;
  global $nhpid_format_footer;
  //$vid = isset($_GET['vid'])? $_GET['vid'] : NULL;
  $export_history =isset($_GET['export_history'])? $_GET['export_history'] : NULL;
  //drupal_set_message(nhpid_api_dump($vid, 'red', TRUE));
  $form = array();
  
  //$export_history = !empty($form_state['values']['assessment_central_export_history'])? $assessment_central_html = $form_state['values']['assessment_central_export_history'] : NULL;
  $history_all = assessment_central_get_export_history($node);
  $form['assessment_central_export_history'] = array(
    '#type' => 'select',
    '#title' => 'Export History',
    '#default_value' => $export_history,
    '#description' => "Select one history date",
    '#options' => $history_all,
    '#multiple' => false,
  );
  $form['assessment_central_export_history_changed'] = array(
      '#type' => 'submit',
      '#value' => 'Submit',
      '#executes_submit_callback' => true,
  );
  $form['assessment_central_export_node_nid'] = array(
      '#type' => 'hidden',
      '#value' => $node -> nid,
  );
  $form['#submit'] = array('assessment_central_export_history_submit');
  $vid = null;
  $assessment_central_html = null;
  if ($export_history ) $vid = nhpid_get_closest_revision_id_by_datestamp($node, $export_history);
  $assessment_central_html_info = assessment_central_fetch_info_for_export($node, $vid, true);
  $assessment_central_html_e = assessment_central_format_export_info($node, null, true, $assessment_central_html_info, 'e');
  $assessment_central_html_f = assessment_central_format_export_info($node, null, true, $assessment_central_html_info, 'f');

  //drupal_set_message(nhpid_api_dump($vid, 'red', TRUE));
  //$assessment_central_html = !empty($form_state['values']['assessment_central_html'])? $assessment_central_html = $form_state['values']['assessment_central_html'] : NULL;

  if ($assessment_central_html_info){
    ## save file for downloading
    $file_names = assessment_central_export_file_name($node);
    $uploaded_data_file_e = $file_names['e'];
    $uploaded_data_file_f = $file_names['f'];   
    $uploaded_data_file_path =  "public://download_html_file/";
    if (!is_dir($uploaded_data_file_path)) drupal_mkdir($uploaded_data_file_path);
    //$uploaded_data_file_split_path = $uploaded_data_file_path . '/split';
    $public_file_stream_wrapper = file_stream_wrapper_get_instance_by_scheme('public');
    if (!$public_file_stream_wrapper->dir_opendir($uploaded_data_file_path, null)) file_prepare_directory($uploaded_data_file_path, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
    $destination_e = file_destination("$uploaded_data_file_path/$uploaded_data_file_e", FILE_EXISTS_RENAME);
    $destination_f = file_destination("$uploaded_data_file_path/$uploaded_data_file_f", FILE_EXISTS_RENAME);    
    file_unmanaged_save_data($assessment_central_html_e, $destination_e, FILE_EXISTS_REPLACE);
    file_unmanaged_save_data($assessment_central_html_f, $destination_f, FILE_EXISTS_REPLACE);
    /*$form['assessment_central'] = array(
      '#weight' => 50,
      '#type' =>'fieldset',
      '#title' => 'Preview of exported HTML',
      '#collapsible' => TRUE, 
      '#collapsed' => FALSE,
      
    );*/
    
    
	  $form['assessment_central_html'] = array(
      '#type' => 'fieldset',
      '#title' => 'HTML file preview',
      '#collapsible' => true, 
      '#collapsed' => FALSE,
    );
    
    $form['assessment_central_html']['export-preview'] = array(
      '#type' => 'item',
      '#title' => '',
      '#markup' => $nhpid_format_header . $assessment_central_html_e . $nhpid_format_footer,
    );
    $form['file_name_warning'] = array(
      '#type' => 'item',
      '#title' => '',
      '#markup' => "<em>You must use the pre-defined file names. For some browsers such as Chrome, file names may be changed when saving them. Please use the original file names. </em>",
    );
    $form['assessment_central_html_download_path_e'] = array(
      '#type' => 'hidden',
      '#title' => '',
      '#value' => "$destination_e",
    );
    $form['assessment_central_html_download_file_e'] = array(
      '#type' => 'hidden',
      '#title' => '',
      '#value' => "$uploaded_data_file_e",
    );
    $download_path_e = l($uploaded_data_file_e, "rule_management/node_export_download/$uploaded_data_file_path/$uploaded_data_file_e", array('attributes' => array('target' => '_blank')));
    /*
    $form['assessment_central_syntaxhighlighter'] = array(
      '#type' => 'text_format',
      '#title' => t('Description'),
      '#default_value' => $assessment_central_html,
      '#format' => 'syntex_highlighter',
      
    );*/
    $form['assessment_central_html_download_e_2'] = array(
      '#type' => 'submit',
      '#value' => 'Download English version',
      '#name' => 'e',
      '#executes_submit_callback' => true,
    );
    $form['assessment_central_html_download_f_2'] = array(
      '#type' => 'submit',
      '#value' => 'Download French version',
      '#name' => 'f',
      '#executes_submit_callback' => true,
    );
    $form['e'] = array(
      '#type' => 'fieldset',
      '#title' => 'English version',
      '#collapsible' => false, 
      '#collapsed' => FALSE,
    );
    
    $form['e']['assessment_central_html_box'] = array(
      '#type' => 'textarea',
      '#value' =>  $assessment_central_html_e,
      '#title' => 'HTML code ' . "(file name: $uploaded_data_file_e)",
      '#description' => "To save the code, right click the box and click 'Select All' and then 'Copy'. Please use <em>$uploaded_data_file_e</em> as file name.<br>
                          Or, click following button to download.",
    );
    $form['e']['assessment_central_html_download_e'] = array(
      '#type' => 'submit',
      '#value' => 'Download',
      '#name' => 'e',
      '#executes_submit_callback' => true,
    );
    $form['f'] = array(
      '#type' => 'fieldset',
      '#title' => 'French version',
      '#collapsible' => false, 
      '#collapsed' => FALSE,
    );
    $form['assessment_central_html_download_path_f'] = array(
      '#type' => 'hidden',
      '#title' => '',
      '#value' => "$destination_f",
    );
    $form['assessment_central_html_download_file_f'] = array(
      '#type' => 'hidden',
      '#title' => '',
      '#value' => "$uploaded_data_file_f",
    );
    $download_path_f = l($uploaded_data_file_f, "rule_management/node_export_download/$uploaded_data_file_path/$uploaded_data_file_f", array('attributes' => array('target' => '_blank')));
    /*
    $form['assessment_central_syntaxhighlighter'] = array(
      '#type' => 'text_format',
      '#title' => t('Description'),
      '#default_value' => $assessment_central_html,
      '#format' => 'syntex_highlighter',
      
    );*/
    
    
    $form['f']['assessment_central_html_box'] = array(
      '#type' => 'textarea',
      '#value' =>  $assessment_central_html_f,
      '#title' => 'HTML code ' . "(file name: $uploaded_data_file_f)",
      '#description' => "To save the code, right click the box and click 'Select All' and then 'Copy'. Please use <em>$uploaded_data_file_f</em> as file name.<br>
                          Or, click following button to download.",
    );
    $form['f']['assessment_central_html_download_f'] = array(
      '#type' => 'submit',
      '#value' => 'Download',
      '#name' => 'f',
      '#executes_submit_callback' => true,
    );
    $form['#submit'] = array('assessment_central_export_history_submit');

  }
  
  else {
    $form['assessment_central_error'] = array(
      '#type' => 'item',
      '#markup' => 'No data available',
      '#title' => 'HTML Code',
      
    );
  }
  return $form;
}
function assessment_central_export_history_submit($form, &$form_state){
  //drupal_set_message(nhpid_api_dump($form_state['clicked_button']['#id'], 'blue', TRUE));
  switch ($form_state['clicked_button']['#id']) {
    case "edit-assessment-central-html-download-f" :
    case "edit-assessment-central-html-download-f-2" :
    $path = $form_state['values']['assessment_central_html_download_path_f'];
    $file = $form_state['values']['assessment_central_html_download_file_f'];
    assessment_central_download($path, $file);
    break;

    case "edit-assessment-central-html-download-e" :
    case "edit-assessment-central-html-download-e-2" :
    $path = $form_state['values']['assessment_central_html_download_path_e'];
    $file = $form_state['values']['assessment_central_html_download_file_e'];
    assessment_central_download($path, $file);
    break;
    default:
    $export_history = $form_state['values']['assessment_central_export_history'];
    $nid = $form_state['values']['assessment_central_export_node_nid'];
    //drupal_set_message(nhpid_api_dump($export_history, 'blue', TRUE));
    //drupal_set_message(nhpid_api_dump($nid, 'blue', TRUE));
    //if($vid) $form_state['values']['assessment_central_html'] = assessment_central_format_export_info($node, $vid);
    if ($export_history) drupal_goto("node/$nid/export_history", array('query' => array( 'export_history'=>$export_history)));
  }
  $form_state['storage']['values'] = $form_state['values'];
}

function assessment_central_export_all_form($form, &$form_state=NULL){
  //include_once 'ZipArchive.php';
  //$zip = new ZipArchive();
  $referer = $_SERVER['HTTP_REFERER'];
  $query_string = urldecode(parse_url($referer, PHP_URL_QUERY));
  
  $query_array = array();
  $date_format = 'Y-m-d';
  parse_str($query_string,$query_array);
  $order = null;
  $sort = null;
  if (isset($query_array['order'])){
    $order = $query_array['order'];
    unset($query_array['order']);
    $sort = $query_array['sort'];
    unset($query_array['sort']);
  }
 
  $display_id = 'default';
  $view = views_get_view('assessment_central_export', true);
  // master list
  $wid=workflow_get_workflows_by_type('mi')->wid;
  $sid=workflow_state_load_by_name('published', $wid)->sid;
  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'type'));
  $query->join('field_data_field_workflow', 'w', 'n.nid = w.entity_id');
  $query->condition('w.field_workflow_value', $sid, '=');
  $result=$query->execute();
  $master_list = "Combo/MI name\tType\tNID\n";
   while($rc = $result->fetchObject()) {
    $nid = $rc->nid;
	$type=$rc->type;
	$node = node_load($nid);
	$wrapper=entity_metadata_wrapper('node', $node);
    $node_name = '';
    if ($type == 'mi'){
      $node_name = $wrapper -> field_mi_nhpid_name->raw();
    }
    else if ($type == 'combo'){
      $node_name = $wrapper -> field_combo_name->raw();
    }
    $master_list = $master_list . "$node_name\t$type\t$nid\n";
  }
  $master_list_file =  "master_nid_list.tsv";
  $master_list_file_path =  "public://download_html_file";
  if (!is_dir($master_list_file_path)) drupal_mkdir($master_list_file_path);
  $destination = file_destination("$master_list_file_path/$master_list_file", FILE_EXISTS_RENAME);
  $url = file_create_url($destination);
  file_unmanaged_save_data($master_list,$destination, FILE_EXISTS_REPLACE);
  $link = l("Download master nid list", $url);
  $form['master_list']=array(
    '#type'=>'item',
    '#markup' =>$link,
  );
  
  
  $vars = $view -> display[$display_id];
   // change sort
  
  if ($order){
    if (!isset($vars->display_options['sorts'][$order])){
      $vars->display_options['sorts'][$order]=array();
      $vars->display_options['sorts'][$order]['id']=$vars->display_options['fields'][$order]['id'];
      $vars->display_options['sorts'][$order]['field']=$vars->display_options['fields'][$order]['field'];
      $vars->display_options['sorts'][$order]['table']=$vars->display_options['fields'][$order]['table'];
    }
    foreach($vars->display_options['sorts'] as $key => $value){
      //drupal_set_message(nhpid_api_dump($key, 'blue', TRUE));
      //drupal_set_message(nhpid_api_dump($order, 'blue', TRUE));
      if ($key == $order){
        
        $vars->display_options['sorts'][$key]['order']=$sort;
      }
      else{
        unset($vars->display_options['sorts'][$key]);
      }
    }
    
  }
  //drupal_set_message(nhpid_api_dump($vars->display_options['sorts'], 'blue', TRUE));
  $new_view = views_new_view();
  //return $vars['filter'];
  $new_filter = array();
  
 
  
  $new_filter = (array)$vars->display_options['filters'];
  foreach ($query_array as $filter => $value){
    if (strpos($filter, '_op')){
      $new_filter[strstr($filter, '_op', true)]['operator'] = $value;
      unset($new_filter[$filter]);
    }
    else {
      $new_filter[$filter]['value'] = $value;
    }
    
  }
  $handler = $new_view->new_display('default', 'Defaults', 'default');
 
  foreach ($new_filter as $filter => $value){
    //drupal_set_message(nhpid_api_dump($value, 'purple', TRUE));
    if (isset($value['field']) and $value['field'] == 'date_filter' and $value['operator'] !='between' and (!isset($value['value']['value']['date']) or !$value['value']['value']['date'])){
      //drupal_set_message(nhpid_api_dump('continue', 'purple', TRUE));
      continue;
    }
    foreach($value as $key => $item){
      $handler->display->display_options['filters'][$filter][$key] = $new_filter[$filter][$key];
    }
    unset($handler->display->display_options['filters'][$filter]['exposed']);
    unset($handler->display->display_options['filters'][$filter]['expose']);
    
  }
  
  $handler->override_option('fields',$vars->display_options['fields']);
  $handler->override_option('sorts',$vars->display_options['sorts']);
  //$handler->override_option('filters',$new_filter);
  $handler->override_option('access', array( 
  'type' => 'none', 
  )); 
  $handler->override_option('cache', array( 
  'type' => 'none', 
  )); 
  $handler->override_option('row_options', array( 
  'inline' => array(), 
  'separator' =>'', 
  )); 
  $handler->override_option('pager',array('type' => 'none'));
  $new_view->build('default');
  $new_view->execute_display('default');
  $result = $new_view->result;
  $nids = array();
  $combo_ing_nids = array();
  $combo_ing_titles = array();
  foreach ($result as $hit){
    $nids[$hit -> nid] = $hit -> nid;
    if ($hit -> node_type =='combo'){
		$node = node_load($hit->nid);
		$wrapper = entity_metadata_wrapper('node', $node);
		if (!empty($node -> field_combo_nhpid_name)){
			foreach($wrapper -> field_combo_nhpid_name as $ing_item) {
				$combo_ing_nids[$ing_item -> nid->raw()] = $ing_item -> nid->raw();
				$combo_ing_titles[$ing_item -> nid->raw()] = $ing_item -> title->raw();
			}
		}
    }
  }
  $combo_ing_nids = array_diff($combo_ing_nids, $nids);
  if ($combo_ing_nids){
    $links = array();
    foreach($combo_ing_nids as $nid){
        $links[] = l("$nid (" . $combo_ing_titles[$nid] . ")" , "node/$nid", array('attributes' => array('target' => '_blank')));
    }
    $list = theme_item_list(array('items' => $links, 'title' => '', 'type' => 'ul', 'attributes' => array()));
    $message = "Your NID list contains combo nodes. The following MI nodes are used by those combo nodes. However, they are not in your node list. You may need to export them, too. ";
    
    $message = $message . $list;
    $form['warning_message']=array(
      '#type' => 'item',
      '#markup' =>  $message,
    );
  }
  
  $nid_list = !empty($form_state['values']['nid_list'])? $form_state['values']['nid_list'] : implode("\n", $nids);
  $form['nid_list']=array(
    '#type' => 'textarea',
    '#default_value' =>  $nid_list,
    '#title' => 'NID list',
    '#cols' => 40,
    '#rows' => 10,
    '#description' => "Yan can paste a new NID list here: node nids delimited by a space, tab, comma, semicolon, or new line feed.",
  );
  $form['lock'] = array(
	  '#type' => 'fieldset',
	  '#title' => 'Lock the systme to prevent data from being changed',
	  '#collapsible' => TRUE,
	  '#collapsed' => FALSE,

	  );
  $lock_tmp = variable_get(DATA_EXPORTING_LOCK_TEMP_VARIABLE, 0);
  $lock_persistent = variable_get(SYSTEM_LOCK_VARIABLE, 0);

  $exporting_data_lock = $lock_persistent or $lock_tmp;
  $info ='The system is locked temporarily.';
  $form['lock']['status'] = array(
    '#type' => 'item',
    '#description' => t("<em>$info</em>"),
    '#access' => $lock_tmp,
  );
  $lock = !empty($form_state['values']['lock_choice']) ? $form_state['values']['lock_choice'] : TRUE;
  $form['lock']['lock_choice'] = array(
    '#type' => 'checkbox',
    '#title' => t('Lock the system temporarily when exporting is in progress'),
    '#default_value' => $lock,
  );
  $form['lock']['release-lock-tmp'] = array(
    '#type' => 'submit',
    '#value' => t('Release Tmp Lock'),
    '#access' => $lock_tmp,
  );
  $form['lock']['description'] = array(
    '#type' => 'item',
    '#description' => t('If the system is locked temporarily, all users are unable to edit data.'),
  );
  $form['batch_download'] = array(
    '#type' => 'submit',
    '#value' => 'Download',
  );
  return $form;
}
function assessment_central_export_all_form_submit($form, &$form_state){

 
	  $form_state['storage']['values'] = $form_state['values'];
	  if ($form_state['values']['lock_choice']) {
		variable_set(DATA_EXPORTING_LOCK_TEMP_VARIABLE, 1);
	  }
	  $nid_list = $form_state['values']['nid_list'];
	  $nids = preg_split('/\D+/', $nid_list);
	  $html_file =  "batch_exported_html_files.zip";
	  $html_file_path =  "public://download_html_file";
	  if (!is_dir($html_file_path)) drupal_mkdir($html_file_path);
	  $destination = file_destination("$html_file_path/$html_file", FILE_EXISTS_RENAME);
	  $operations = array();
	  foreach ($nids as $nid) {
		$operations[] = array('assessment_central_export_all_batch_op', array($nid, null, true, $html_file, $destination));
	  }
	  //drupal_set_message(nhpid_api_dump($public_file_stream_wrapper -> getDirectoryPath(), 'red', TRUE));
	  $batch = array(
		'operations' => $operations,
		'finished' => 'assessment_central_export_all_batch_finished',
		// We can define custom messages instead of the default ones.
		'title' => t('Batch export'),
		'init_message' => t('Exporting...'),
		'progress_message' => t('Processed @current out of @total nodes.'),
		'error_message' => t('Batch export has encountered an error.'),
		'file' => drupal_get_path('module', 'assessment_central'). '/assessment_central_forms.inc',
	  );

	  //dpm($batch);
	  batch_set($batch);
	  batch_process();

}

function assessment_central_export_all_batch_op($nid, $vid, $export, $html_file, $destination, &$context){

  if (!isset($context['results']['attempted'])) {
	$context['results'] = array('attempted' => 0, 'success' => 0);
  }
  
  $context['results']['destination'] = $destination;
  $context['results']['file_name'] = $html_file;
  $context['sandbox']['max'] = 1;
  $context['results']['attempted'] ++;
  
  $node = node_load($nid);
  
  if ($node){
		$zip = new ZipArchive();
		$zip->open(drupal_realpath($destination), ZipArchive::CREATE);
		$context['results']['zip'] = $zip;
		if (!isset($context['results']['log_file'])) {
		  $context['results']['log_file'] = "Title\tType\tNid\tHTML file ID\n";
		}
		if ($node->type =='mi' and !isset($context['results']['log_file_mi'])) {
		  $context['results']['log_file_mi'] = "Ingredient name\tHTML file ID\n";
		}
		$html_info = assessment_central_fetch_info_for_export($node, $vid);
		$file_names = assessment_central_export_file_name($node);
		//drupal_set_message(nhpid_api_dump($html_info , 'red', TRUE));
		if ($file_names){
		  $html_info_e = assessment_central_format_export_info($node, $vid, $export, $html_info, 'e');
		  $zip -> addFromString("batch_exported_html/english/" . $file_names['e'], $html_info_e);
		  $html_info_f = assessment_central_format_export_info($node, $vid, $export, $html_info, 'f');
		  $zip -> addFromString("batch_exported_html/french/" . $file_names['f'], $html_info_f);
		  assessment_central_add_export_history($node);
		  //drupal_set_message(nhpid_api_dump($html_info_e , 'blue', TRUE));
		  //drupal_set_message(nhpid_api_dump($html_info_f , 'red', TRUE));
		  $title = $node -> title;
		  $type = $node -> type;
		  $html_file_id = $file_names['b'];
		  $context['results']['log_file'] = $context['results']['log_file'] . "$title\t$type\t$nid\t$html_file_id\n";
		  if ($type == 'mi'){
			$ing_name = $node -> field_mi_nhpid_name[$node -> language][0]['value'];
			$context['results']['log_file_mi'] = $context['results']['log_file_mi'] . "$ing_name\t$html_file_id\n";
		  }
		}
		$zip -> close();

  
  }
  $context['results']['success'] ++;
  // Optional message displayed under the progressbar.
  $context['message'] = t('Exported node @title', array('@title' => $node->title));
  if ($context['results']['attempted'] != $context['sandbox']['max']) {
    $context['finished'] = ($context['results']['attempted'] >= $context['sandbox']['max']);
  }
  
}
function assessment_central_export_all_batch_finished($success, $results, $operations) {
  if ($success) {
    if ($results['success'] == $results['attempted']) {
      $message = t('Finished @success steps of exporting html files successfully.', array('@success' => $results['success']));
    }
    else {
      $message = t('Finished @success of @attempted of exporting html files successfully. @remaining to be deleted', array('@success' => $results['success'], '@attempt' => $results['attempted'], '@remaining' => $remaining));
    }
    //drupal_set_message(nhpid_api_dump($results , 'red', TRUE));
   
  }
  else {
    $message = t('Updating NHPID ingredients encounters an error.');
  }
  variable_set(DATA_EXPORTING_LOCK_TEMP_VARIABLE, 0);
  //drupal_set_message(nhpid_api_dump($results , 'red', TRUE));
  //drupal_set_message(nhpid_api_dump(drupal_realpath($results['destination']) , 'red', TRUE));
  drupal_set_message($message);
  $today = date('Y-n-j');
  $zip = new ZipArchive();
  $zip->open(drupal_realpath($results['destination']), ZipArchive::CREATE);
  $zip -> addFromString("batch_exported_html/log/" . "log_$today.tsv", $results['log_file']);
  $zip -> addFromString("batch_exported_html/log/" . "log_mi_$today.tsv", $results['log_file_mi']);
  $zip -> close();
  assessment_central_download($results['destination'], $results['file_name']);
  
}
function assessment_central_enforce_revision_log_form($form, $form_state=NULL) {
  
  $enforce_revision_log = !empty($form_state['values']['assessment_central_enforce_revision_log']) ? $form_state['values']['assessment_central_enforce_revision_log'] : variable_get('assessment_central_enforce_revision_log', 0);
  $enforce_revision_log_warning_message = !empty($form_state['values']['assessment_central_enforce_revision_log_warning_message']) ? $form_state['values']['assessment_central_enforce_revision_log_warning_message'] : variable_get('assessment_central_enforce_revision_log_log_warning_message', "Please enter the revision log message and check the 'Create new revision' checkbox.");
	$trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
  $form['help']=array(
    '#type' => 'item',
    '#value' => "If enabled, users have to be enter revision log message and check 'Create new revision' for any updates of NHPID data nodes",
  );

  $form['assessment_central_enforce_revision_log']=array(
    '#type' => 'checkbox',
    '#title' => "Enforce revision log message",
    '#default_value' => $enforce_revision_log,
  );

  $form['assessment_central_enforce_revision_log_warning_message']=array(
    '#type' => 'textarea',
    '#title' => "Warning message",
    '#default_value' => $enforce_revision_log_warning_message,
  );
  $form['save']=array(
    '#type' => 'submit',
    '#value' => t('Save Setting'),
  );
  return $form;
}

function assessment_central_enforce_revision_log_form_submit($form, &$form_state) {
  $nhpid_enforce_revision_log = $form_state['values']['assessment_central_enforce_revision_log'];
  $nhpid_enforce_revision_log_warning_message = $form_state['values']['assessment_central_enforce_revision_log_warning_message'];

  variable_set('assessment_central_enforce_revision_log', $nhpid_enforce_revision_log);
  variable_set('assessment_central_enforce_revision_log_warning_message', $nhpid_enforce_revision_log_warning_message);
  $form_state['rebuild'] = TRUE;
  $form_state['storage']['values'] = $form_state['values'];
}

function assessment_central_lock_system_form($form, &$form_state=NULL) {
	global $user;
	$trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
	$lock_persistent = variable_get(SYSTEM_LOCK_VARIABLE, 0);
  $lock_temp = variable_get(DATA_EXPORTING_LOCK_TEMP_VARIABLE, 0);
  $trail=menu_get_active_trail();
	$form['form_title'] = array(
	'#type' => 'item',
	'#markup' => '<h2>' . end($trail)['title'] .'</h2>',
	);
  $form['lock'] = array(
    '#title' => 'Lock system persistently',
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => false,
		);
  $form['lock']['description'] = array(
    '#type' => 'item',
    '#title' => "",
    '#description' => t('Locking the system persistently will block other users to edit nhpid data. If you would like to lock the system persistently, press "Lock". The lock has to be released manually by clicking "Release". All users except one who locks the system are unable to save data.'),
  );
  $locker_uid = variable_get(SYSTEM_LOCK_VARIABLE, null);
  $email_link = null;
  if ($locker_uid and $user->uid != $locker_uid){
		$locker = user_load($locker_uid);
		$locker_name = $locker -> name;
		if (user_access('access nhpid email') and $locker-> uid != $user -> uid) $email_link = l("Ask info", "nhpid_email/$locker_uid", array('attributes' => array('target' => '_blank')));
  }
  else{
    $locker_name = 'you';
  }

  $form['lock']['persistent_status'] = array(
    '#type' => 'item',
    '#description' => t("<span style='text-decoration: blink'><em>The system is locked persistently by $locker_name.</em></span> $email_link"),
    '#access' => $lock_persistent,
  );
  $form['lock']['lock-lock'] = array(
    '#type' => 'submit',
    '#value' => t('Lock'),
    '#access' => !$lock_persistent,
  );
  $form['lock']['release-lock'] = array(
    '#type' => 'submit',
    '#value' => t('Release'),
    '#access' => $lock_persistent,
  );
	if ($lock_temp){
    $form['lock_temp'] = array(
	    '#title' => 'Release temporarily system lock for exporting',
	    '#type' => 'fieldset',
	    '#collapsible' => TRUE,
	    '#collapsed' => false,
			);
	  $form['lock_temp']['description'] = array(
	    '#type' => 'item',
	    '#title' => "",
	    '#description' => t('The system is currently temporarily locked. This means a data exporting process is running, or a exporting process was crashed. If there are no active exporting processes in progress, please release the lock.'),
	  );
    $form['lock_temp']['release-lock-temp'] = array(
    '#type' => 'submit',
    '#value' => t('Release'),
    '#access' => $lock_temp,
  );
	}
  return $form;
}
function assessment_central_lock_system_form_submit($form, &$form_state) {
   switch ($form_state['clicked_button']['#id']) {
   case 'edit-release-lock':
      # relase lock
      variable_set(SYSTEM_LOCK_VARIABLE, NULL);
      break;
  case 'edit-release-lock-temp':
      # relase lock
      variable_set(DATA_EXPORTING_LOCK_TEMP_VARIABLE, 0);
      break;

    case 'edit-lock-lock':
      #  lock system from saving data persistently
      global $user;
      variable_set(SYSTEM_LOCK_VARIABLE, $user -> uid);
      break;
	 }
}