<?php
/***
* This script imports nodes using drush ne-export 
*/
$base_path='legal_opinion_demo';


if (!module_exists('node_export')){
	drush_print_r("This script requires the module node export to be installed and enabled. Please install and enable the module.");
	exit;
}
$base_folder='/home/pzhang/db_dumps/node_export';
if (!file_exists($base_folder)){
	drush_mkdir($base_folder);
}
$types = array();
// legal_opinion_demo
if($base_path=='legal_opinion_demo'){
	$types = array('format', 'priority','status','bureau_project', 'product_type','requester','legislation','dlsu_contact');
	
}
$folder=$base_folder . '/' . $base_path;
if (!file_exists($folder)){
	drush_mkdir($folder);
}


foreach($types as $type){
	if (!node_type_load($type)){
		drush_print_r("Content type $type does not exist.");
		continue;
	}
	drush_invoke_process('@self','delete-all', array($type), array('reset'=>TRUE));
	$file_name="$folder/$type.txt";
	drush_invoke_process('@self','ne-import', null,array('file'=>$file_name));
	
}
