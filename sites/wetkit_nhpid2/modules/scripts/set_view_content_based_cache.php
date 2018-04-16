//This script sets view cache for views with non-exposed content type filter
//Cache is content based using module Views Content cache

// Detecting the module
if (!module_exists('views_content_cache')){
	dpm('Module views_content_cache is required but not installed or enabled. Please install/enable the module');
	exit;
}
/*** parameters need to be set ***/
$view_name='test';
$results_min_lifespan = -1;
$results_max_lifespan = 6; //day
$output_min_lifespan=-1;
$output_max_lifespan=6; //day
$cache_options = NULL;

if ($results_min_lifespan>0){
	$results_min_lifespan = (string)($results_min_lifespan * 60 * 60 * 24);
}
if ($results_max_lifespan>0){
	$results_max_lifespan = (string)($results_max_lifespan * 60 * 60 * 24);
}
if ($output_min_lifespan>0){
	$output_min_lifespan = (string)($output_min_lifespan * 60 * 60 * 24);
}
if ($output_max_lifespan>0){
	$output_max_lifespan = (string)($output_max_lifespan * 60 * 60 * 24);
}

$view=views_get_view($view_name);
if (!$view){
	dpm("View $view_name cannot be found. I gives up.");
	exit;
}
foreach($view->display as $display_name=>&$display){
	$types=array();
	$display_options = $display->display_options;
	//dpm($display_options);
	if(!isset($display_options['filters'])){
		continue;
	}
	foreach($display_options['filters'] as $filter_name=>$filter){
		if((isset($filter['exposed']) and !$filter['exposed']) and $filter['table']=='node' and $filter['field']=='type'){
			$types=$filter['value'];
		}
	}
	if (empty($types)){
		continue;
	}
	$cache=array();
	$cache['type']='views_content_cache';
	$cache['keys']['comment']['changed']=0;
	$cache['keys']['node']=$types;
	$cache['keys']['node_only']['node_changed']='node_changed';
	$cache['results_min_lifespan']=$results_min_lifespan;
	$cache['results_max_lifespan']=$results_max_lifespan;
	$cache['output_min_lifespan']=$output_min_lifespan;
	$cache['output_max_lifespan']=$output_max_lifespan;
	$display_options['cache']=$cache;
	$display_options['cache_options'] = $cache_options;
	$display_options['defaults']['cache_options'] = FALSE;
	$display_options['defaults']['cache'] = FALSE;
	$display->display_options = $display_options;
	
}
dpm($view);

$view->save();
$view->update();