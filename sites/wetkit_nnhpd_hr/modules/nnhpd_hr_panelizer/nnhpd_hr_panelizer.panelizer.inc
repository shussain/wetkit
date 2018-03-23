<?php
/**
 * @file
 * nnhpd_hr_panelizer.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nnhpd_hr_panelizer_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Code list position lan  profile  section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'section';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:section:clone_of_code_list_position_lan_profile_section';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '84.94541373329251',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '15.054586266707483',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar_left',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 1,
      ),
      'sidebar_left' => array(
        'type' => 'region',
        'title' => 'Sidebar left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar_left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '791fb5ff-54b7-4a95-9d89-1b0c0c603087';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b1ee46c6-5505-4bba-9f99-bb6d1ba8f19e';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'create_position_lan_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b1ee46c6-5505-4bba-9f99-bb6d1ba8f19e';
  $display->content['new-b1ee46c6-5505-4bba-9f99-bb6d1ba8f19e'] = $pane;
  $display->panels['center'][0] = 'new-b1ee46c6-5505-4bba-9f99-bb6d1ba8f19e';
  $pane = new stdClass();
  $pane->pid = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'nnhpd_hr-panel_pane_code_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c9a2174e-7658-4149-9848-46159e8a24e9';
  $display->content['new-c9a2174e-7658-4149-9848-46159e8a24e9'] = $pane;
  $display->panels['center'][1] = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:section:clone_of_code_list_position_lan_profile_section'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Code list bureau section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'section';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:section:code_list_bureau_section';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '84.94541373329251',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '15.054586266707483',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar_left',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 1,
      ),
      'sidebar_left' => array(
        'type' => 'region',
        'title' => 'Sidebar left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar_left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '791fb5ff-54b7-4a95-9d89-1b0c0c603087';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a20f3b78-0e34-4347-9704-3b5b45964927';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'create_bureau';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a20f3b78-0e34-4347-9704-3b5b45964927';
  $display->content['new-a20f3b78-0e34-4347-9704-3b5b45964927'] = $pane;
  $display->panels['center'][0] = 'new-a20f3b78-0e34-4347-9704-3b5b45964927';
  $pane = new stdClass();
  $pane->pid = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'nnhpd_hr-panel_pane_code_list';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c9a2174e-7658-4149-9848-46159e8a24e9';
  $display->content['new-c9a2174e-7658-4149-9848-46159e8a24e9'] = $pane;
  $display->panels['center'][1] = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $pane = new stdClass();
  $pane->pid = 'new-fb39321b-5004-4ef3-a32c-3a02ea44d689';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'nnhpd_hr-panel_pane_code_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'fb39321b-5004-4ef3-a32c-3a02ea44d689';
  $display->content['new-fb39321b-5004-4ef3-a32c-3a02ea44d689'] = $pane;
  $display->panels['center'][2] = 'new-fb39321b-5004-4ef3-a32c-3a02ea44d689';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:section:code_list_bureau_section'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Code list classification section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'section';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:section:code_list_classification_section';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '84.94541373329251',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '15.054586266707483',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar_left',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 1,
      ),
      'sidebar_left' => array(
        'type' => 'region',
        'title' => 'Sidebar left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar_left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '791fb5ff-54b7-4a95-9d89-1b0c0c603087';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b0b4d4a8-ed7e-47f4-a3a1-40a02e5c132a';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'create_classification';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b0b4d4a8-ed7e-47f4-a3a1-40a02e5c132a';
  $display->content['new-b0b4d4a8-ed7e-47f4-a3a1-40a02e5c132a'] = $pane;
  $display->panels['center'][0] = 'new-b0b4d4a8-ed7e-47f4-a3a1-40a02e5c132a';
  $pane = new stdClass();
  $pane->pid = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'nnhpd_hr-panel_pane_code_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c9a2174e-7658-4149-9848-46159e8a24e9';
  $display->content['new-c9a2174e-7658-4149-9848-46159e8a24e9'] = $pane;
  $display->panels['center'][1] = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:section:code_list_classification_section'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Code list directorate section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'section';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:section:code_list_directorate_section';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '84.94541373329251',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '15.054586266707483',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar_left',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 1,
      ),
      'sidebar_left' => array(
        'type' => 'region',
        'title' => 'Sidebar left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar_left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '791fb5ff-54b7-4a95-9d89-1b0c0c603087';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-16859168-eb4b-4738-bdb5-475af660e03b';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'create_directorate';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '16859168-eb4b-4738-bdb5-475af660e03b';
  $display->content['new-16859168-eb4b-4738-bdb5-475af660e03b'] = $pane;
  $display->panels['center'][0] = 'new-16859168-eb4b-4738-bdb5-475af660e03b';
  $pane = new stdClass();
  $pane->pid = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'nnhpd_hr-panel_pane_code_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c9a2174e-7658-4149-9848-46159e8a24e9';
  $display->content['new-c9a2174e-7658-4149-9848-46159e8a24e9'] = $pane;
  $display->panels['center'][1] = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:section:code_list_directorate_section'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Code list employment type section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'section';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:section:code_list_employment_type_section';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '84.94541373329251',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '15.054586266707483',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar_left',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 1,
      ),
      'sidebar_left' => array(
        'type' => 'region',
        'title' => 'Sidebar left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar_left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '791fb5ff-54b7-4a95-9d89-1b0c0c603087';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-99664f16-7fec-44ba-a74b-6484fe2f6912';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'create_employment_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '99664f16-7fec-44ba-a74b-6484fe2f6912';
  $display->content['new-99664f16-7fec-44ba-a74b-6484fe2f6912'] = $pane;
  $display->panels['center'][0] = 'new-99664f16-7fec-44ba-a74b-6484fe2f6912';
  $pane = new stdClass();
  $pane->pid = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'nnhpd_hr-panel_pane_code_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c9a2174e-7658-4149-9848-46159e8a24e9';
  $display->content['new-c9a2174e-7658-4149-9848-46159e8a24e9'] = $pane;
  $display->panels['center'][1] = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:section:code_list_employment_type_section'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Code list position section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'section';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:section:code_list_position_section';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '84.94541373329251',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '15.054586266707483',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar_left',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 1,
      ),
      'sidebar_left' => array(
        'type' => 'region',
        'title' => 'Sidebar left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar_left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '791fb5ff-54b7-4a95-9d89-1b0c0c603087';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-837c3b34-4065-4876-9c17-f27141c36599';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'create_postion';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '837c3b34-4065-4876-9c17-f27141c36599';
  $display->content['new-837c3b34-4065-4876-9c17-f27141c36599'] = $pane;
  $display->panels['center'][0] = 'new-837c3b34-4065-4876-9c17-f27141c36599';
  $pane = new stdClass();
  $pane->pid = 'new-2bbab235-8c81-4f94-9ace-54e70c05f4dc';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'nnhpd_hr-panel_pane_position_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2bbab235-8c81-4f94-9ace-54e70c05f4dc';
  $display->content['new-2bbab235-8c81-4f94-9ace-54e70c05f4dc'] = $pane;
  $display->panels['center'][1] = 'new-2bbab235-8c81-4f94-9ace-54e70c05f4dc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:section:code_list_position_section'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Code list security type section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'section';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:section:code_list_security_type_section';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '84.94541373329251',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '15.054586266707483',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar_left',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 1,
      ),
      'sidebar_left' => array(
        'type' => 'region',
        'title' => 'Sidebar left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar_left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '791fb5ff-54b7-4a95-9d89-1b0c0c603087';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7699fc45-5431-4fff-bb19-b02820948723';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'create_security_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7699fc45-5431-4fff-bb19-b02820948723';
  $display->content['new-7699fc45-5431-4fff-bb19-b02820948723'] = $pane;
  $display->panels['center'][0] = 'new-7699fc45-5431-4fff-bb19-b02820948723';
  $pane = new stdClass();
  $pane->pid = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'nnhpd_hr-panel_pane_code_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c9a2174e-7658-4149-9848-46159e8a24e9';
  $display->content['new-c9a2174e-7658-4149-9848-46159e8a24e9'] = $pane;
  $display->panels['center'][1] = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:section:code_list_security_type_section'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Code list SLE_E section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'section';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:section:code_list_sle_e_section';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '84.94541373329251',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '15.054586266707483',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar_left',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 1,
      ),
      'sidebar_left' => array(
        'type' => 'region',
        'title' => 'Sidebar left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar_left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '791fb5ff-54b7-4a95-9d89-1b0c0c603087';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a20f3b78-0e34-4347-9704-3b5b45964927';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'create_bureau';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a20f3b78-0e34-4347-9704-3b5b45964927';
  $display->content['new-a20f3b78-0e34-4347-9704-3b5b45964927'] = $pane;
  $display->panels['center'][0] = 'new-a20f3b78-0e34-4347-9704-3b5b45964927';
  $pane = new stdClass();
  $pane->pid = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'nnhpd_hr-panel_pane_code_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c9a2174e-7658-4149-9848-46159e8a24e9';
  $display->content['new-c9a2174e-7658-4149-9848-46159e8a24e9'] = $pane;
  $display->panels['center'][1] = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:section:code_list_sle_e_section'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Code list SLE_F section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'section';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:section:code_list_sle_f_section';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '84.94541373329251',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '15.054586266707483',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar_left',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 1,
      ),
      'sidebar_left' => array(
        'type' => 'region',
        'title' => 'Sidebar left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar_left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '791fb5ff-54b7-4a95-9d89-1b0c0c603087';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b0dc2a60-8578-48c3-833b-42b98bb6cffd';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'create_sle_f';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b0dc2a60-8578-48c3-833b-42b98bb6cffd';
  $display->content['new-b0dc2a60-8578-48c3-833b-42b98bb6cffd'] = $pane;
  $display->panels['center'][0] = 'new-b0dc2a60-8578-48c3-833b-42b98bb6cffd';
  $pane = new stdClass();
  $pane->pid = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'nnhpd_hr-panel_pane_code_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c9a2174e-7658-4149-9848-46159e8a24e9';
  $display->content['new-c9a2174e-7658-4149-9848-46159e8a24e9'] = $pane;
  $display->panels['center'][1] = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:section:code_list_sle_f_section'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Code list work status section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'section';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:section:code_list_work_status_section';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '84.94541373329251',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '15.054586266707483',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar_left',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 1,
      ),
      'sidebar_left' => array(
        'type' => 'region',
        'title' => 'Sidebar left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar_left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '791fb5ff-54b7-4a95-9d89-1b0c0c603087';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4d3b8523-d0bc-4f54-8972-661b17d93da2';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'create_work_status';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4d3b8523-d0bc-4f54-8972-661b17d93da2';
  $display->content['new-4d3b8523-d0bc-4f54-8972-661b17d93da2'] = $pane;
  $display->panels['center'][0] = 'new-4d3b8523-d0bc-4f54-8972-661b17d93da2';
  $pane = new stdClass();
  $pane->pid = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'nnhpd_hr-panel_pane_code_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c9a2174e-7658-4149-9848-46159e8a24e9';
  $display->content['new-c9a2174e-7658-4149-9848-46159e8a24e9'] = $pane;
  $display->panels['center'][1] = 'new-c9a2174e-7658-4149-9848-46159e8a24e9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:section:code_list_work_status_section'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Code list section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'section';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:section:default';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '84.94541373329251',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '15.054586266707483',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar_left',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 1,
      ),
      'sidebar_left' => array(
        'type' => 'region',
        'title' => 'Sidebar left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar_left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '791fb5ff-54b7-4a95-9d89-1b0c0c603087';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4f6f87cb-23b2-431d-b3f9-cbfd2abc60bf';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<a href=\'add/position\'> Add Position</a>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4f6f87cb-23b2-431d-b3f9-cbfd2abc60bf';
  $display->content['new-4f6f87cb-23b2-431d-b3f9-cbfd2abc60bf'] = $pane;
  $display->panels['center'][0] = 'new-4f6f87cb-23b2-431d-b3f9-cbfd2abc60bf';
  $pane = new stdClass();
  $pane->pid = 'new-2bbab235-8c81-4f94-9ace-54e70c05f4dc';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'nnhpd_hr-panel_pane_position_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2bbab235-8c81-4f94-9ace-54e70c05f4dc';
  $display->content['new-2bbab235-8c81-4f94-9ace-54e70c05f4dc'] = $pane;
  $display->panels['center'][1] = 'new-2bbab235-8c81-4f94-9ace-54e70c05f4dc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:section:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Section list section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'section';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:section:section_list_section';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '84.94541373329251',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '15.054586266707483',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar_left',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 1,
      ),
      'sidebar_left' => array(
        'type' => 'region',
        'title' => 'Sidebar left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar_left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '791fb5ff-54b7-4a95-9d89-1b0c0c603087';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f242455b-42b8-4a1a-b083-1a25fb4f3fe8';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'nnhpd_hr-panel_pane_section_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f242455b-42b8-4a1a-b083-1a25fb4f3fe8';
  $display->content['new-f242455b-42b8-4a1a-b083-1a25fb4f3fe8'] = $pane;
  $display->panels['center'][0] = 'new-f242455b-42b8-4a1a-b083-1a25fb4f3fe8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:section:section_list_section'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Staff List section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'section';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:section:staff_list_section';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '84.94541373329251',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '15.054586266707483',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar_left',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 1,
      ),
      'sidebar_left' => array(
        'type' => 'region',
        'title' => 'Sidebar left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar_left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '791fb5ff-54b7-4a95-9d89-1b0c0c603087';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0a3ec829-b864-4058-9e02-5cf6a9be6f0a';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'create_staff_member';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0a3ec829-b864-4058-9e02-5cf6a9be6f0a';
  $display->content['new-0a3ec829-b864-4058-9e02-5cf6a9be6f0a'] = $pane;
  $display->panels['center'][0] = 'new-0a3ec829-b864-4058-9e02-5cf6a9be6f0a';
  $pane = new stdClass();
  $pane->pid = 'new-3460604b-4641-4765-b31d-da42cd9c2d3e';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'nnhpd_hr-panel_pane_staff_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3460604b-4641-4765-b31d-da42cd9c2d3e';
  $display->content['new-3460604b-4641-4765-b31d-da42cd9c2d3e'] = $pane;
  $display->panels['center'][1] = 'new-3460604b-4641-4765-b31d-da42cd9c2d3e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:section:staff_list_section'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'staff_member';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:staff_member:default';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array(
    0 => array(
      'identifier' => 'Assigned From field collection (field_assigned_from) from node (staff_member)',
      'keyword' => 'Assigned From Field collection',
      'name' => 'field_collection_from_field:node:staff_member:field_assigned_from',
      'delta' => '0',
      'context' => 'panelizer',
      'id' => 1,
    ),
    1 => array(
      'identifier' => 'Assigned To field collection (field_assigned_to) from node (staff_member)',
      'keyword' => 'Assigned To Field collection',
      'name' => 'field_collection_from_field:node:staff_member:field_assigned_to',
      'delta' => '0',
      'context' => 'panelizer',
      'id' => 1,
    ),
    2 => array(
      'identifier' => 'Assets field collection (field_assets) from node (staff_member)',
      'keyword' => 'Assets Field collection',
      'name' => 'field_collection_from_field:node:staff_member:field_assets',
      'delta' => '0',
      'context' => 'panelizer',
      'id' => 1,
    ),
    3 => array(
      'identifier' => 'Reporting To field collection (field_reporting_to) from node (staff_member)',
      'keyword' => 'Reporting To Field collection',
      'name' => 'field_collection_from_field:node:staff_member:field_reporting_to',
      'delta' => '0',
      'context' => 'panelizer',
      'id' => 1,
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 6,
          1 => 24,
          2 => 35,
        ),
        'parent' => 'canvas',
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 7,
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      7 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'children' => array(
          0 => 8,
          1 => 9,
          2 => 10,
          3 => 11,
          4 => 12,
          5 => 13,
          6 => 14,
          7 => 21,
          8 => 22,
          9 => 23,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      8 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'active_inactive',
          1 => 'last_name',
          2 => 'first_name_',
          3 => 'initial_',
        ),
        'parent' => '7',
        'class' => '',
        'hide_empty' => 0,
      ),
      'active_inactive' => array(
        'type' => 'region',
        'title' => 'Active/Inactive',
        'width' => '24.96594200982175',
        'width_type' => '%',
        'parent' => '8',
        'class' => '',
        'hide_empty' => 0,
      ),
      'last_name' => array(
        'type' => 'region',
        'title' => 'Last name',
        'width' => '25.041598557084225',
        'width_type' => '%',
        'parent' => '8',
        'class' => '',
        'hide_empty' => 0,
      ),
      'first_name_' => array(
        'type' => 'region',
        'title' => 'First Name',
        'width' => '25.080822344209167',
        'width_type' => '%',
        'parent' => '8',
        'class' => '',
        'hide_empty' => 0,
      ),
      'initial_' => array(
        'type' => 'region',
        'title' => 'Initial',
        'width' => '24.91163708888486',
        'width_type' => '%',
        'parent' => '8',
        'class' => '',
        'hide_empty' => 0,
      ),
      9 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'work_status_',
        ),
        'parent' => '7',
        'class' => '',
        'hide_empty' => 0,
      ),
      'work_status_' => array(
        'type' => 'region',
        'title' => 'Employment Status',
        'width' => 100,
        'width_type' => '%',
        'parent' => '9',
        'class' => '',
        'hide_empty' => 0,
      ),
      10 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 15,
        ),
        'parent' => '7',
        'class' => '',
        'hide_empty' => 0,
      ),
      11 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 18,
        ),
        'parent' => '7',
        'class' => '',
        'hide_empty' => 0,
      ),
      12 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'position___',
          1 => 'pri_',
          2 => 'po_pl',
        ),
        'parent' => '7',
        'class' => '',
        'hide_empty' => 0,
      ),
      'position___' => array(
        'type' => 'region',
        'title' => 'Position #:',
        'width' => '24.97451747593496',
        'width_type' => '%',
        'parent' => '12',
        'class' => '',
        'hide_empty' => 0,
      ),
      'pri_' => array(
        'type' => 'region',
        'title' => 'PO/PL',
        'width' => '25.038978014007437',
        'width_type' => '%',
        'parent' => '12',
        'class' => '',
        'hide_empty' => 0,
      ),
      13 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'classification_',
          1 => 'level_',
        ),
        'parent' => '7',
        'class' => '',
        'hide_empty' => 0,
      ),
      'classification_' => array(
        'type' => 'region',
        'title' => 'Classification',
        'width' => 50,
        'width_type' => '%',
        'parent' => '13',
        'class' => '',
        'hide_empty' => 0,
      ),
      'level_' => array(
        'type' => 'region',
        'title' => 'Level',
        'width' => 50,
        'width_type' => '%',
        'parent' => '13',
        'class' => '',
        'hide_empty' => 0,
      ),
      14 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'security_level_',
          1 => 'security_expiry_date_',
        ),
        'parent' => '7',
        'class' => '',
        'hide_empty' => 0,
      ),
      'security_level_' => array(
        'type' => 'region',
        'title' => 'Security Level',
        'width' => 50,
        'width_type' => '%',
        'parent' => '14',
        'class' => '',
        'hide_empty' => 0,
      ),
      'security_expiry_date_' => array(
        'type' => 'region',
        'title' => 'Security Expiry Date',
        'width' => 50,
        'width_type' => '%',
        'parent' => '14',
        'class' => '',
        'hide_empty' => 0,
      ),
      15 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '10',
        'children' => array(
          0 => 16,
          1 => 17,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      16 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'start_date_',
          1 => 'end_date_',
        ),
        'parent' => '15',
        'class' => '',
        'hide_empty' => 0,
      ),
      'start_date_' => array(
        'type' => 'region',
        'title' => 'Start Date',
        'width' => '50',
        'width_type' => '%',
        'parent' => '16',
        'class' => '',
        'hide_empty' => 0,
      ),
      'end_date_' => array(
        'type' => 'region',
        'title' => 'End Date',
        'width' => '50',
        'width_type' => '%',
        'parent' => '16',
        'class' => '',
        'hide_empty' => 0,
      ),
      17 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'work_status',
        ),
        'parent' => '15',
        'class' => '',
        'hide_empty' => 0,
      ),
      'work_status' => array(
        'type' => 'region',
        'title' => 'Work Status',
        'width' => 100,
        'width_type' => '%',
        'parent' => '17',
        'class' => '',
        'hide_empty' => 0,
      ),
      18 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '11',
        'children' => array(
          0 => 43,
          1 => 19,
          2 => 20,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      19 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'assigned_to',
          1 => 'start_date__',
          2 => 'end_date__',
        ),
        'parent' => '18',
        'class' => '',
        'hide_empty' => 0,
      ),
      20 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'assigned_from',
          1 => 'start_date',
          2 => 'end_date',
        ),
        'parent' => '18',
        'class' => '',
        'hide_empty' => 0,
      ),
      'start_date' => array(
        'type' => 'region',
        'title' => 'Start Date',
        'width' => '25.043982634326795',
        'width_type' => '%',
        'parent' => '20',
        'class' => '',
        'hide_empty' => 0,
      ),
      'end_date' => array(
        'type' => 'region',
        'title' => 'End Date',
        'width' => '24.9717205245786',
        'width_type' => '%',
        'parent' => '20',
        'class' => '',
        'hide_empty' => 0,
      ),
      21 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'position_language_profile',
          1 => 'meets_',
          2 => 'sle_e',
          3 => 'sle_f',
        ),
        'parent' => '7',
        'class' => '',
        'hide_empty' => 0,
      ),
      22 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'reading_expiry',
          1 => 'writing_expiry',
          2 => 'oral_expiry',
        ),
        'parent' => '7',
        'class' => '',
        'hide_empty' => 0,
      ),
      'position_language_profile' => array(
        'type' => 'region',
        'title' => 'Position Language Profile',
        'width' => '24.960223698309726',
        'width_type' => '%',
        'parent' => '21',
        'class' => '',
        'hide_empty' => 0,
      ),
      'meets_' => array(
        'type' => 'region',
        'title' => 'Meets?',
        'width' => '25.026289768356616',
        'width_type' => '%',
        'parent' => '21',
        'class' => '',
        'hide_empty' => 0,
      ),
      'sle_e' => array(
        'type' => 'region',
        'title' => 'SLE_E',
        'width' => '25.070301012698472',
        'width_type' => '%',
        'parent' => '21',
        'class' => '',
        'hide_empty' => 0,
      ),
      'sle_f' => array(
        'type' => 'region',
        'title' => 'SLE_F',
        'width' => '24.943185520635183',
        'width_type' => '%',
        'parent' => '21',
        'class' => '',
        'hide_empty' => 0,
      ),
      'reading_expiry' => array(
        'type' => 'region',
        'title' => 'Reading Expiry',
        'width' => '24.958770729044137',
        'width_type' => '%',
        'parent' => '22',
        'class' => '',
        'hide_empty' => 0,
      ),
      'writing_expiry' => array(
        'type' => 'region',
        'title' => 'Writing Expiry',
        'width' => '24.9978011334045',
        'width_type' => '%',
        'parent' => '22',
        'class' => '',
        'hide_empty' => 0,
      ),
      'oral_expiry' => array(
        'type' => 'region',
        'title' => 'Oral Expiry',
        'width' => '50.043428137551366',
        'width_type' => '%',
        'parent' => '22',
        'class' => '',
        'hide_empty' => 0,
      ),
      23 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'notes',
        ),
        'parent' => '7',
        'class' => '',
        'hide_empty' => 0,
      ),
      'notes' => array(
        'type' => 'region',
        'title' => 'Notes',
        'width' => 100,
        'width_type' => '%',
        'parent' => '23',
        'class' => '',
        'hide_empty' => 0,
      ),
      24 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 25,
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      25 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '24',
        'children' => array(
          0 => 46,
          1 => 26,
          2 => 27,
          3 => 28,
          4 => 29,
          5 => 30,
          6 => 31,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      26 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'position____',
          1 => 'position_title',
        ),
        'parent' => '25',
        'class' => '',
        'hide_empty' => 0,
      ),
      27 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 32,
        ),
        'parent' => '25',
        'class' => '',
        'hide_empty' => 0,
      ),
      28 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'supervisor___s_security_clearance',
        ),
        'parent' => '25',
        'class' => '',
        'hide_empty' => 0,
      ),
      29 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'assigned_cube',
          1 => 'moving_to',
          2 => 'moving_date',
        ),
        'parent' => '25',
        'class' => '',
        'hide_empty' => 0,
      ),
      30 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'notes_',
        ),
        'parent' => '25',
        'class' => '',
        'hide_empty' => 0,
      ),
      31 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(),
        'parent' => '25',
        'class' => '',
        'hide_empty' => 0,
      ),
      'position____' => array(
        'type' => 'region',
        'title' => 'Position #',
        'width' => '50.068527883996',
        'width_type' => '%',
        'parent' => '26',
        'class' => '',
        'hide_empty' => 0,
      ),
      'position_title' => array(
        'type' => 'region',
        'title' => 'Position Title',
        'width' => '49.931472116004',
        'width_type' => '%',
        'parent' => '26',
        'class' => '',
        'hide_empty' => 0,
      ),
      'supervisor___s_security_clearance' => array(
        'type' => 'region',
        'title' => 'Supervisor’s Security clearance',
        'width' => 100,
        'width_type' => '%',
        'parent' => '28',
        'class' => '',
        'hide_empty' => 0,
      ),
      'assigned_cube' => array(
        'type' => 'region',
        'title' => 'Assigned Cube',
        'width' => '24.99645306316972',
        'width_type' => '%',
        'parent' => '29',
        'class' => '',
        'hide_empty' => 0,
      ),
      'moving_to' => array(
        'type' => 'region',
        'title' => 'Moving to',
        'width' => '25.011001538983347',
        'width_type' => '%',
        'parent' => '29',
        'class' => '',
        'hide_empty' => 0,
      ),
      'moving_date' => array(
        'type' => 'region',
        'title' => 'Moving Date',
        'width' => '49.99254539784693',
        'width_type' => '%',
        'parent' => '29',
        'class' => '',
        'hide_empty' => 0,
      ),
      32 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '27',
        'children' => array(
          0 => 44,
          1 => 33,
          2 => 34,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      33 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'bureau',
          1 => 'director',
          2 => 'manager',
        ),
        'parent' => '32',
        'class' => '',
        'hide_empty' => 0,
      ),
      34 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'unit',
          1 => 'unit_head',
        ),
        'parent' => '32',
        'class' => '',
        'hide_empty' => 0,
      ),
      'bureau' => array(
        'type' => 'region',
        'title' => 'Bureau',
        'width' => '24.919847609820536',
        'width_type' => '%',
        'parent' => '33',
        'class' => '',
        'hide_empty' => 0,
      ),
      'director' => array(
        'type' => 'region',
        'title' => 'Director',
        'width' => '24.919083868697783',
        'width_type' => '%',
        'parent' => '33',
        'class' => '',
        'hide_empty' => 0,
      ),
      'manager' => array(
        'type' => 'region',
        'title' => 'Manager',
        'width' => '50.16106852148166',
        'width_type' => '%',
        'parent' => '33',
        'class' => '',
        'hide_empty' => 0,
      ),
      'unit' => array(
        'type' => 'region',
        'title' => 'Unit',
        'width' => 50,
        'width_type' => '%',
        'parent' => '34',
        'class' => '',
        'hide_empty' => 0,
      ),
      'unit_head' => array(
        'type' => 'region',
        'title' => 'Unit Head',
        'width' => 50,
        'width_type' => '%',
        'parent' => '34',
        'class' => '',
        'hide_empty' => 0,
      ),
      'notes_' => array(
        'type' => 'region',
        'title' => 'Notes',
        'width' => 100,
        'width_type' => '%',
        'parent' => '30',
        'class' => '',
        'hide_empty' => 0,
      ),
      35 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 36,
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      36 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '35',
        'children' => array(
          0 => 45,
          1 => 37,
          2 => 38,
          3 => 39,
          4 => 40,
          5 => 41,
          6 => 42,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      37 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'ergonomic_assessment_on_file_',
          1 => 'equipment_associated_with_ea',
        ),
        'parent' => '36',
        'class' => '',
        'hide_empty' => 0,
      ),
      'ergonomic_assessment_on_file_' => array(
        'type' => 'region',
        'title' => 'Ergonomic Assessment on file ',
        'width' => 50,
        'width_type' => '%',
        'parent' => '37',
        'class' => '',
        'hide_empty' => 0,
      ),
      'equipment_associated_with_ea' => array(
        'type' => 'region',
        'title' => 'Equipment Associated with EA',
        'width' => 50,
        'width_type' => '%',
        'parent' => '37',
        'class' => '',
        'hide_empty' => 0,
      ),
      38 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'notes__',
        ),
        'parent' => '36',
        'class' => '',
        'hide_empty' => 0,
      ),
      39 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'computer',
          1 => 'asset_number',
        ),
        'parent' => '36',
        'class' => '',
        'hide_empty' => 0,
      ),
      40 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'notes___',
        ),
        'parent' => '36',
        'class' => '',
        'hide_empty' => 0,
      ),
      41 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'software_requested',
        ),
        'parent' => '36',
        'class' => '',
        'hide_empty' => 0,
      ),
      42 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'notes____',
        ),
        'parent' => '36',
        'class' => '',
        'hide_empty' => 0,
      ),
      'notes__' => array(
        'type' => 'region',
        'title' => 'Notes',
        'width' => 100,
        'width_type' => '%',
        'parent' => '38',
        'class' => '',
        'hide_empty' => 0,
      ),
      'computer' => array(
        'type' => 'region',
        'title' => 'Computer',
        'width' => 50,
        'width_type' => '%',
        'parent' => '39',
        'class' => '',
        'hide_empty' => 0,
      ),
      'asset_number' => array(
        'type' => 'region',
        'title' => 'Asset Number',
        'width' => 50,
        'width_type' => '%',
        'parent' => '39',
        'class' => '',
        'hide_empty' => 0,
      ),
      'notes___' => array(
        'type' => 'region',
        'title' => 'Notes',
        'width' => 100,
        'width_type' => '%',
        'parent' => '40',
        'class' => '',
        'hide_empty' => 0,
      ),
      'software_requested' => array(
        'type' => 'region',
        'title' => 'Software requested',
        'width' => 100,
        'width_type' => '%',
        'parent' => '41',
        'class' => '',
        'hide_empty' => 0,
      ),
      'notes____' => array(
        'type' => 'region',
        'title' => 'Notes',
        'width' => 100,
        'width_type' => '%',
        'parent' => '42',
        'class' => '',
        'hide_empty' => 0,
      ),
      43 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'assignment',
        ),
        'parent' => '18',
        'class' => '',
        'hide_empty' => 0,
      ),
      'assignment' => array(
        'type' => 'region',
        'title' => 'Assignment',
        'width' => 100,
        'width_type' => '%',
        'parent' => '43',
        'class' => '',
        'hide_empty' => 0,
      ),
      'assigned_to' => array(
        'type' => 'region',
        'title' => 'Assigned To',
        'width' => '50',
        'width_type' => '%',
        'parent' => '19',
        'class' => '',
        'hide_empty' => 0,
      ),
      'start_date__' => array(
        'type' => 'region',
        'title' => 'Start Date',
        'width' => '25',
        'width_type' => '%',
        'parent' => '19',
        'class' => '',
        'hide_empty' => 0,
      ),
      'end_date__' => array(
        'type' => 'region',
        'title' => 'End Date',
        'width' => '25',
        'width_type' => '%',
        'parent' => '19',
        'class' => '',
        'hide_empty' => 0,
      ),
      'assigned_from' => array(
        'type' => 'region',
        'title' => 'Assigned From',
        'width' => '49.98429684109461',
        'width_type' => '%',
        'parent' => '20',
        'class' => '',
        'hide_empty' => 0,
      ),
      44 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'report_to',
        ),
        'parent' => '32',
        'class' => '',
        'hide_empty' => 0,
      ),
      'report_to' => array(
        'type' => 'region',
        'title' => 'Report To',
        'width' => 100,
        'width_type' => '%',
        'parent' => '44',
        'class' => '',
        'hide_empty' => 0,
      ),
      45 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'assets',
        ),
        'parent' => '36',
        'class' => '',
        'hide_empty' => 0,
      ),
      'assets' => array(
        'type' => 'region',
        'title' => 'Assets',
        'width' => 100,
        'width_type' => '%',
        'parent' => '45',
        'class' => '',
        'hide_empty' => 0,
      ),
      46 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'report_to_',
        ),
        'parent' => '25',
        'class' => '',
        'hide_empty' => 0,
      ),
      'report_to_' => array(
        'type' => 'region',
        'title' => 'Report To',
        'width' => 100,
        'width_type' => '%',
        'parent' => '46',
        'class' => '',
        'hide_empty' => 0,
      ),
      'po_pl' => array(
        'type' => 'region',
        'title' => 'PRI',
        'width' => '49.986504510057614',
        'width_type' => '%',
        'parent' => '12',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'active' => NULL,
      'first_name' => NULL,
      'initial' => NULL,
      'active_inactive' => NULL,
      'last_name' => NULL,
      'first_name_' => NULL,
      'initial_' => NULL,
      'work_status_' => NULL,
      'assigned_to_' => NULL,
      'assigned_from_' => NULL,
      'start_date' => NULL,
      'end_date' => NULL,
      'position___' => NULL,
      'pri_' => NULL,
      'classification_' => NULL,
      'level_' => NULL,
      'security_level_' => NULL,
      'security_expiry_date_' => NULL,
      'start_date_' => NULL,
      'end_date_' => NULL,
      'work_status' => NULL,
      'assigned_to' => NULL,
      'assigned_from' => NULL,
      'position_language_profile' => NULL,
      'meets_' => NULL,
      'sle_e' => NULL,
      'sle_f' => NULL,
      'reading_expiry' => NULL,
      'writing_expiry' => NULL,
      'oral_expiry' => NULL,
      'notes' => NULL,
      'position____' => NULL,
      'position_title' => NULL,
      'supervisor___s_security_clearance' => NULL,
      'assigned_cube' => NULL,
      'moving_to' => NULL,
      'moving_date' => NULL,
      'bureau' => NULL,
      'director' => NULL,
      'manager' => NULL,
      'unit' => NULL,
      'unit_head' => NULL,
      'notes_' => NULL,
      'ergonomic_assessment_on_file_' => NULL,
      'equipment_associated_with_ea' => NULL,
      'notes__' => NULL,
      'computer' => NULL,
      'asset_number' => NULL,
      'notes___' => NULL,
      'software_requested' => NULL,
      'notes____' => NULL,
      'assignment' => NULL,
      'start_date__' => NULL,
      'end_date__' => NULL,
      'report_to' => NULL,
      'assets' => NULL,
      'report_to_' => NULL,
      'po_pl' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'dcf42fa9-c69d-4ec9-bf4b-76dba7ff65b6';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-cf672d18-e1e8-4cac-9e09-0ac26e32c5dd';
  $pane->panel = 'active_inactive';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_active';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'list_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'title' => array(
        'element' => 'span',
        'attributes' => array(
          'id' => '',
          'class' => '',
        ),
      ),
      'content' => array(
        'element' => 'span',
        'attributes' => array(
          'id' => '',
          'class' => '',
        ),
      ),
      'theme' => 0,
    ),
    'style' => 'wrapper_element',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'cf672d18-e1e8-4cac-9e09-0ac26e32c5dd';
  $display->content['new-cf672d18-e1e8-4cac-9e09-0ac26e32c5dd'] = $pane;
  $display->panels['active_inactive'][0] = 'new-cf672d18-e1e8-4cac-9e09-0ac26e32c5dd';
  $pane = new stdClass();
  $pane->pid = 'new-8939fe92-7a65-424e-b55f-0e02ca1d3d73';
  $pane->panel = 'assets';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Assets',
    'title' => '',
    'body' => '<h2>Assets</h2>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8939fe92-7a65-424e-b55f-0e02ca1d3d73';
  $display->content['new-8939fe92-7a65-424e-b55f-0e02ca1d3d73'] = $pane;
  $display->panels['assets'][0] = 'new-8939fe92-7a65-424e-b55f-0e02ca1d3d73';
  $pane = new stdClass();
  $pane->pid = 'new-f789e29d-9429-404b-88f7-2affd934ef02';
  $pane->panel = 'asset_number';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_asset_number';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_assets_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f789e29d-9429-404b-88f7-2affd934ef02';
  $display->content['new-f789e29d-9429-404b-88f7-2affd934ef02'] = $pane;
  $display->panels['asset_number'][0] = 'new-f789e29d-9429-404b-88f7-2affd934ef02';
  $pane = new stdClass();
  $pane->pid = 'new-55080c64-18cb-4c90-b1e6-f20153c9aea7';
  $pane->panel = 'assigned_cube';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_assigned_cube';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_reporting_to_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '55080c64-18cb-4c90-b1e6-f20153c9aea7';
  $display->content['new-55080c64-18cb-4c90-b1e6-f20153c9aea7'] = $pane;
  $display->panels['assigned_cube'][0] = 'new-55080c64-18cb-4c90-b1e6-f20153c9aea7';
  $pane = new stdClass();
  $pane->pid = 'new-ea27d7bc-c2fa-48e6-ad7e-f5385bed86e8';
  $pane->panel = 'assigned_from';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_assigned_from_directorate';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 0,
    ),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_assigned_from_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ea27d7bc-c2fa-48e6-ad7e-f5385bed86e8';
  $display->content['new-ea27d7bc-c2fa-48e6-ad7e-f5385bed86e8'] = $pane;
  $display->panels['assigned_from'][0] = 'new-ea27d7bc-c2fa-48e6-ad7e-f5385bed86e8';
  $pane = new stdClass();
  $pane->pid = 'new-22b05365-5bb4-4998-911b-e7c8ce2d8dc0';
  $pane->panel = 'assigned_to';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_assigned_to_directorate';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 0,
    ),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_assigned_to_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '22b05365-5bb4-4998-911b-e7c8ce2d8dc0';
  $display->content['new-22b05365-5bb4-4998-911b-e7c8ce2d8dc0'] = $pane;
  $display->panels['assigned_to'][0] = 'new-22b05365-5bb4-4998-911b-e7c8ce2d8dc0';
  $pane = new stdClass();
  $pane->pid = 'new-342a772b-5acb-4ba1-ad5e-8cd52c7089c6';
  $pane->panel = 'assignment';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Assignment',
    'title' => '',
    'body' => '<h2>Assignment</h2>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '342a772b-5acb-4ba1-ad5e-8cd52c7089c6';
  $display->content['new-342a772b-5acb-4ba1-ad5e-8cd52c7089c6'] = $pane;
  $display->panels['assignment'][0] = 'new-342a772b-5acb-4ba1-ad5e-8cd52c7089c6';
  $pane = new stdClass();
  $pane->pid = 'new-017c9810-d58e-44c6-b040-044732edcce0';
  $pane->panel = 'bureau';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_bureau';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 0,
    ),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_reporting_to_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '017c9810-d58e-44c6-b040-044732edcce0';
  $display->content['new-017c9810-d58e-44c6-b040-044732edcce0'] = $pane;
  $display->panels['bureau'][0] = 'new-017c9810-d58e-44c6-b040-044732edcce0';
  $pane = new stdClass();
  $pane->pid = 'new-6400c35d-afdb-4f02-87c6-77cdc761c50d';
  $pane->panel = 'classification_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_classification';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 0,
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '6400c35d-afdb-4f02-87c6-77cdc761c50d';
  $display->content['new-6400c35d-afdb-4f02-87c6-77cdc761c50d'] = $pane;
  $display->panels['classification_'][0] = 'new-6400c35d-afdb-4f02-87c6-77cdc761c50d';
  $pane = new stdClass();
  $pane->pid = 'new-ea44cdbd-2c22-416e-9db6-6d59bae536c5';
  $pane->panel = 'computer';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_computer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'list_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_assets_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ea44cdbd-2c22-416e-9db6-6d59bae536c5';
  $display->content['new-ea44cdbd-2c22-416e-9db6-6d59bae536c5'] = $pane;
  $display->panels['computer'][0] = 'new-ea44cdbd-2c22-416e-9db6-6d59bae536c5';
  $pane = new stdClass();
  $pane->pid = 'new-72fbf87d-ae82-48b5-be2d-51650cc0f788';
  $pane->panel = 'director';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_director';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 0,
    ),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_reporting_to_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '72fbf87d-ae82-48b5-be2d-51650cc0f788';
  $display->content['new-72fbf87d-ae82-48b5-be2d-51650cc0f788'] = $pane;
  $display->panels['director'][0] = 'new-72fbf87d-ae82-48b5-be2d-51650cc0f788';
  $pane = new stdClass();
  $pane->pid = 'new-f5247660-a7f0-425b-8350-6ef47c08eca2';
  $pane->panel = 'end_date';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_end_date_assigned_from';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'dd_mth_yy',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
    ),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_assigned_from_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f5247660-a7f0-425b-8350-6ef47c08eca2';
  $display->content['new-f5247660-a7f0-425b-8350-6ef47c08eca2'] = $pane;
  $display->panels['end_date'][0] = 'new-f5247660-a7f0-425b-8350-6ef47c08eca2';
  $pane = new stdClass();
  $pane->pid = 'new-ea0f246d-c40b-4efc-80a7-7d3ee1768bf6';
  $pane->panel = 'end_date_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_end_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'dd_mth_yy',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ea0f246d-c40b-4efc-80a7-7d3ee1768bf6';
  $display->content['new-ea0f246d-c40b-4efc-80a7-7d3ee1768bf6'] = $pane;
  $display->panels['end_date_'][0] = 'new-ea0f246d-c40b-4efc-80a7-7d3ee1768bf6';
  $pane = new stdClass();
  $pane->pid = 'new-452e15e9-e45b-413b-92e9-5a715591ec0f';
  $pane->panel = 'end_date__';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_end_date_assigned_to';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'dd_mth_yy',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
    ),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_assigned_to_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '452e15e9-e45b-413b-92e9-5a715591ec0f';
  $display->content['new-452e15e9-e45b-413b-92e9-5a715591ec0f'] = $pane;
  $display->panels['end_date__'][0] = 'new-452e15e9-e45b-413b-92e9-5a715591ec0f';
  $pane = new stdClass();
  $pane->pid = 'new-ea9184b9-dfcb-414a-ae61-585ef37c11e3';
  $pane->panel = 'equipment_associated_with_ea';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_equipment_associated_w_ea';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_assets_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ea9184b9-dfcb-414a-ae61-585ef37c11e3';
  $display->content['new-ea9184b9-dfcb-414a-ae61-585ef37c11e3'] = $pane;
  $display->panels['equipment_associated_with_ea'][0] = 'new-ea9184b9-dfcb-414a-ae61-585ef37c11e3';
  $pane = new stdClass();
  $pane->pid = 'new-e4268404-c0e4-4c89-8fd8-d2c5ca0f1dd7';
  $pane->panel = 'ergonomic_assessment_on_file_';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_ergonomic_assess_on_file';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'list_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_assets_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e4268404-c0e4-4c89-8fd8-d2c5ca0f1dd7';
  $display->content['new-e4268404-c0e4-4c89-8fd8-d2c5ca0f1dd7'] = $pane;
  $display->panels['ergonomic_assessment_on_file_'][0] = 'new-e4268404-c0e4-4c89-8fd8-d2c5ca0f1dd7';
  $pane = new stdClass();
  $pane->pid = 'new-e7472c43-ec57-4bff-a276-79e73fac3d9e';
  $pane->panel = 'first_name_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_last_name';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e7472c43-ec57-4bff-a276-79e73fac3d9e';
  $display->content['new-e7472c43-ec57-4bff-a276-79e73fac3d9e'] = $pane;
  $display->panels['first_name_'][0] = 'new-e7472c43-ec57-4bff-a276-79e73fac3d9e';
  $pane = new stdClass();
  $pane->pid = 'new-608b01a3-07ae-4fac-8437-37622a68ac2d';
  $pane->panel = 'initial_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_initial';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '608b01a3-07ae-4fac-8437-37622a68ac2d';
  $display->content['new-608b01a3-07ae-4fac-8437-37622a68ac2d'] = $pane;
  $display->panels['initial_'][0] = 'new-608b01a3-07ae-4fac-8437-37622a68ac2d';
  $pane = new stdClass();
  $pane->pid = 'new-b3a3407d-0d36-4180-857a-d87e571f4cbd';
  $pane->panel = 'last_name';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_first_name';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b3a3407d-0d36-4180-857a-d87e571f4cbd';
  $display->content['new-b3a3407d-0d36-4180-857a-d87e571f4cbd'] = $pane;
  $display->panels['last_name'][0] = 'new-b3a3407d-0d36-4180-857a-d87e571f4cbd';
  $pane = new stdClass();
  $pane->pid = 'new-60b9c85c-5b20-4a53-81dd-b42f6eefe3da';
  $pane->panel = 'level_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_level';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'list_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '60b9c85c-5b20-4a53-81dd-b42f6eefe3da';
  $display->content['new-60b9c85c-5b20-4a53-81dd-b42f6eefe3da'] = $pane;
  $display->panels['level_'][0] = 'new-60b9c85c-5b20-4a53-81dd-b42f6eefe3da';
  $pane = new stdClass();
  $pane->pid = 'new-b4a27f1c-f505-4b3c-8f97-f5edfca7a7c4';
  $pane->panel = 'manager';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_manager';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 0,
    ),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_reporting_to_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b4a27f1c-f505-4b3c-8f97-f5edfca7a7c4';
  $display->content['new-b4a27f1c-f505-4b3c-8f97-f5edfca7a7c4'] = $pane;
  $display->panels['manager'][0] = 'new-b4a27f1c-f505-4b3c-8f97-f5edfca7a7c4';
  $pane = new stdClass();
  $pane->pid = 'new-71c0a312-d0ba-4fd0-a99c-8be179b997a7';
  $pane->panel = 'meets_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_meets';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'list_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '71c0a312-d0ba-4fd0-a99c-8be179b997a7';
  $display->content['new-71c0a312-d0ba-4fd0-a99c-8be179b997a7'] = $pane;
  $display->panels['meets_'][0] = 'new-71c0a312-d0ba-4fd0-a99c-8be179b997a7';
  $pane = new stdClass();
  $pane->pid = 'new-279cb4af-e9f5-4db3-ab32-78c235b9c5b1';
  $pane->panel = 'moving_date';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_moving_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'dd_mth_yy',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
    ),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_reporting_to_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '279cb4af-e9f5-4db3-ab32-78c235b9c5b1';
  $display->content['new-279cb4af-e9f5-4db3-ab32-78c235b9c5b1'] = $pane;
  $display->panels['moving_date'][0] = 'new-279cb4af-e9f5-4db3-ab32-78c235b9c5b1';
  $pane = new stdClass();
  $pane->pid = 'new-3d3d04a4-50f5-4354-83c3-3d5882f15654';
  $pane->panel = 'moving_to';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_moving_to';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_reporting_to_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3d3d04a4-50f5-4354-83c3-3d5882f15654';
  $display->content['new-3d3d04a4-50f5-4354-83c3-3d5882f15654'] = $pane;
  $display->panels['moving_to'][0] = 'new-3d3d04a4-50f5-4354-83c3-3d5882f15654';
  $pane = new stdClass();
  $pane->pid = 'new-e2288be2-a1a2-43d0-96c5-d553dc89a6c3';
  $pane->panel = 'notes';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_notes';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e2288be2-a1a2-43d0-96c5-d553dc89a6c3';
  $display->content['new-e2288be2-a1a2-43d0-96c5-d553dc89a6c3'] = $pane;
  $display->panels['notes'][0] = 'new-e2288be2-a1a2-43d0-96c5-d553dc89a6c3';
  $pane = new stdClass();
  $pane->pid = 'new-f31bd9cf-6bae-464e-a718-82a324ceb828';
  $pane->panel = 'notes_';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_note';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_reporting_to_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f31bd9cf-6bae-464e-a718-82a324ceb828';
  $display->content['new-f31bd9cf-6bae-464e-a718-82a324ceb828'] = $pane;
  $display->panels['notes_'][0] = 'new-f31bd9cf-6bae-464e-a718-82a324ceb828';
  $pane = new stdClass();
  $pane->pid = 'new-d02a9046-db66-445c-9bac-13c20251671e';
  $pane->panel = 'notes__';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_assets_notes_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_assets_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd02a9046-db66-445c-9bac-13c20251671e';
  $display->content['new-d02a9046-db66-445c-9bac-13c20251671e'] = $pane;
  $display->panels['notes__'][0] = 'new-d02a9046-db66-445c-9bac-13c20251671e';
  $pane = new stdClass();
  $pane->pid = 'new-97436083-fb53-414a-83c5-e9ecfc9c2b63';
  $pane->panel = 'notes___';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_assets_notes_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_assets_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '97436083-fb53-414a-83c5-e9ecfc9c2b63';
  $display->content['new-97436083-fb53-414a-83c5-e9ecfc9c2b63'] = $pane;
  $display->panels['notes___'][0] = 'new-97436083-fb53-414a-83c5-e9ecfc9c2b63';
  $pane = new stdClass();
  $pane->pid = 'new-104db010-dd07-437d-b1b0-d33fed56f777';
  $pane->panel = 'notes____';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_assets_notes_3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_assets_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '104db010-dd07-437d-b1b0-d33fed56f777';
  $display->content['new-104db010-dd07-437d-b1b0-d33fed56f777'] = $pane;
  $display->panels['notes____'][0] = 'new-104db010-dd07-437d-b1b0-d33fed56f777';
  $pane = new stdClass();
  $pane->pid = 'new-17f8ab1b-4068-4b90-805b-e7fda2b2e263';
  $pane->panel = 'oral_expiry';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_oral_expiry';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'dd_mth_yy',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '17f8ab1b-4068-4b90-805b-e7fda2b2e263';
  $display->content['new-17f8ab1b-4068-4b90-805b-e7fda2b2e263'] = $pane;
  $display->panels['oral_expiry'][0] = 'new-17f8ab1b-4068-4b90-805b-e7fda2b2e263';
  $pane = new stdClass();
  $pane->pid = 'new-0a5e67f7-4154-46de-962a-c8ad4b721c75';
  $pane->panel = 'position_language_profile';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_position_language_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 0,
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0a5e67f7-4154-46de-962a-c8ad4b721c75';
  $display->content['new-0a5e67f7-4154-46de-962a-c8ad4b721c75'] = $pane;
  $display->panels['position_language_profile'][0] = 'new-0a5e67f7-4154-46de-962a-c8ad4b721c75';
  $pane = new stdClass();
  $pane->pid = 'new-d0aa7559-e913-4932-bbc4-7f06c25d82a1';
  $pane->panel = 'position_title';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_position_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_reporting_to_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd0aa7559-e913-4932-bbc4-7f06c25d82a1';
  $display->content['new-d0aa7559-e913-4932-bbc4-7f06c25d82a1'] = $pane;
  $display->panels['position_title'][0] = 'new-d0aa7559-e913-4932-bbc4-7f06c25d82a1';
  $pane = new stdClass();
  $pane->pid = 'new-9fbef837-12ac-4754-8699-fdec8485b5a2';
  $pane->panel = 'position___';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_position_number';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9fbef837-12ac-4754-8699-fdec8485b5a2';
  $display->content['new-9fbef837-12ac-4754-8699-fdec8485b5a2'] = $pane;
  $display->panels['position___'][0] = 'new-9fbef837-12ac-4754-8699-fdec8485b5a2';
  $pane = new stdClass();
  $pane->pid = 'new-d4f3dadd-a3a2-4efc-bd65-39120968d0fb';
  $pane->panel = 'position____';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_position_number';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_reporting_to_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd4f3dadd-a3a2-4efc-bd65-39120968d0fb';
  $display->content['new-d4f3dadd-a3a2-4efc-bd65-39120968d0fb'] = $pane;
  $display->panels['position____'][0] = 'new-d4f3dadd-a3a2-4efc-bd65-39120968d0fb';
  $pane = new stdClass();
  $pane->pid = 'new-ad926cd1-088c-4b98-8be2-161b7b18cedb';
  $pane->panel = 'po_pl';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_pri';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ad926cd1-088c-4b98-8be2-161b7b18cedb';
  $display->content['new-ad926cd1-088c-4b98-8be2-161b7b18cedb'] = $pane;
  $display->panels['po_pl'][0] = 'new-ad926cd1-088c-4b98-8be2-161b7b18cedb';
  $pane = new stdClass();
  $pane->pid = 'new-745d0200-8f61-44bd-9195-aa9057164d3c';
  $pane->panel = 'pri_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_po_pl';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '745d0200-8f61-44bd-9195-aa9057164d3c';
  $display->content['new-745d0200-8f61-44bd-9195-aa9057164d3c'] = $pane;
  $display->panels['pri_'][0] = 'new-745d0200-8f61-44bd-9195-aa9057164d3c';
  $pane = new stdClass();
  $pane->pid = 'new-f7f443e7-c9ac-47e1-96a6-50fb724fc138';
  $pane->panel = 'reading_expiry';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_reading_expiry';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'dd_mth_yy',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f7f443e7-c9ac-47e1-96a6-50fb724fc138';
  $display->content['new-f7f443e7-c9ac-47e1-96a6-50fb724fc138'] = $pane;
  $display->panels['reading_expiry'][0] = 'new-f7f443e7-c9ac-47e1-96a6-50fb724fc138';
  $pane = new stdClass();
  $pane->pid = 'new-6adb30eb-a45c-4798-8ee3-ab6955cf1990';
  $pane->panel = 'report_to_';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'report to',
    'title' => '',
    'body' => '<h2>Report To</h2>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '6adb30eb-a45c-4798-8ee3-ab6955cf1990';
  $display->content['new-6adb30eb-a45c-4798-8ee3-ab6955cf1990'] = $pane;
  $display->panels['report_to_'][0] = 'new-6adb30eb-a45c-4798-8ee3-ab6955cf1990';
  $pane = new stdClass();
  $pane->pid = 'new-78f6e917-9f3d-4a2c-b327-5ee86b254f61';
  $pane->panel = 'security_expiry_date_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_security_expiry_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'dd_mth_yy',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '78f6e917-9f3d-4a2c-b327-5ee86b254f61';
  $display->content['new-78f6e917-9f3d-4a2c-b327-5ee86b254f61'] = $pane;
  $display->panels['security_expiry_date_'][0] = 'new-78f6e917-9f3d-4a2c-b327-5ee86b254f61';
  $pane = new stdClass();
  $pane->pid = 'new-c04dd7b6-3bcf-4e0a-a564-b598a0f1c166';
  $pane->panel = 'security_level_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_security_level';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 0,
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c04dd7b6-3bcf-4e0a-a564-b598a0f1c166';
  $display->content['new-c04dd7b6-3bcf-4e0a-a564-b598a0f1c166'] = $pane;
  $display->panels['security_level_'][0] = 'new-c04dd7b6-3bcf-4e0a-a564-b598a0f1c166';
  $pane = new stdClass();
  $pane->pid = 'new-b67654f3-56e0-4166-ac1a-b47763351b8f';
  $pane->panel = 'sle_e';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_sle_e';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 0,
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b67654f3-56e0-4166-ac1a-b47763351b8f';
  $display->content['new-b67654f3-56e0-4166-ac1a-b47763351b8f'] = $pane;
  $display->panels['sle_e'][0] = 'new-b67654f3-56e0-4166-ac1a-b47763351b8f';
  $pane = new stdClass();
  $pane->pid = 'new-3ccc3c46-b0a2-4c91-af66-e0f6716f617f';
  $pane->panel = 'sle_f';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_sle_f';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 0,
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3ccc3c46-b0a2-4c91-af66-e0f6716f617f';
  $display->content['new-3ccc3c46-b0a2-4c91-af66-e0f6716f617f'] = $pane;
  $display->panels['sle_f'][0] = 'new-3ccc3c46-b0a2-4c91-af66-e0f6716f617f';
  $pane = new stdClass();
  $pane->pid = 'new-e35efb72-0711-47c8-91ed-538a5e4e1ea6';
  $pane->panel = 'software_requested';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_software_requested';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_default',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_assets_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e35efb72-0711-47c8-91ed-538a5e4e1ea6';
  $display->content['new-e35efb72-0711-47c8-91ed-538a5e4e1ea6'] = $pane;
  $display->panels['software_requested'][0] = 'new-e35efb72-0711-47c8-91ed-538a5e4e1ea6';
  $pane = new stdClass();
  $pane->pid = 'new-dd01a1f3-61eb-4860-8b7a-49738678b335';
  $pane->panel = 'start_date';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_start_date_assigned_from';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'dd_mth_yy',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
    ),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_assigned_from_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'dd01a1f3-61eb-4860-8b7a-49738678b335';
  $display->content['new-dd01a1f3-61eb-4860-8b7a-49738678b335'] = $pane;
  $display->panels['start_date'][0] = 'new-dd01a1f3-61eb-4860-8b7a-49738678b335';
  $pane = new stdClass();
  $pane->pid = 'new-613eb24d-25a9-4b63-8f97-eceb105c54a9';
  $pane->panel = 'start_date_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_start_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'dd_mth_yy',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '613eb24d-25a9-4b63-8f97-eceb105c54a9';
  $display->content['new-613eb24d-25a9-4b63-8f97-eceb105c54a9'] = $pane;
  $display->panels['start_date_'][0] = 'new-613eb24d-25a9-4b63-8f97-eceb105c54a9';
  $pane = new stdClass();
  $pane->pid = 'new-2dab1935-74bc-4fdb-95dd-be962b46b586';
  $pane->panel = 'start_date__';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_start_date_assigned_to';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'dd_mth_yy',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
    ),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_assigned_to_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2dab1935-74bc-4fdb-95dd-be962b46b586';
  $display->content['new-2dab1935-74bc-4fdb-95dd-be962b46b586'] = $pane;
  $display->panels['start_date__'][0] = 'new-2dab1935-74bc-4fdb-95dd-be962b46b586';
  $pane = new stdClass();
  $pane->pid = 'new-01c23160-f24d-456c-b124-26cba6f76fe6';
  $pane->panel = 'supervisor___s_security_clearance';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_supervisor_security_clear';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_assigned_from_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '01c23160-f24d-456c-b124-26cba6f76fe6';
  $display->content['new-01c23160-f24d-456c-b124-26cba6f76fe6'] = $pane;
  $display->panels['supervisor___s_security_clearance'][0] = 'new-01c23160-f24d-456c-b124-26cba6f76fe6';
  $pane = new stdClass();
  $pane->pid = 'new-b3c8cfb1-8a79-4c5b-bb3f-abc6e92ea1b6';
  $pane->panel = 'unit';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_unit';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_reporting_to_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b3c8cfb1-8a79-4c5b-bb3f-abc6e92ea1b6';
  $display->content['new-b3c8cfb1-8a79-4c5b-bb3f-abc6e92ea1b6'] = $pane;
  $display->panels['unit'][0] = 'new-b3c8cfb1-8a79-4c5b-bb3f-abc6e92ea1b6';
  $pane = new stdClass();
  $pane->pid = 'new-af7fa52d-6ab9-48f8-91ec-4b18585fefaa';
  $pane->panel = 'unit_head';
  $pane->type = 'entity_field';
  $pane->subtype = 'field_collection_item:field_unit_head';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 0,
    ),
    'context' => 'relationship_field_collection_from_field:node:staff_member:field_reporting_to_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'af7fa52d-6ab9-48f8-91ec-4b18585fefaa';
  $display->content['new-af7fa52d-6ab9-48f8-91ec-4b18585fefaa'] = $pane;
  $display->panels['unit_head'][0] = 'new-af7fa52d-6ab9-48f8-91ec-4b18585fefaa';
  $pane = new stdClass();
  $pane->pid = 'new-6de56d28-5b4b-4b9d-92c8-9284ed03ec3f';
  $pane->panel = 'work_status';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_work_status';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 0,
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '6de56d28-5b4b-4b9d-92c8-9284ed03ec3f';
  $display->content['new-6de56d28-5b4b-4b9d-92c8-9284ed03ec3f'] = $pane;
  $display->panels['work_status'][0] = 'new-6de56d28-5b4b-4b9d-92c8-9284ed03ec3f';
  $pane = new stdClass();
  $pane->pid = 'new-46c32bf0-81f2-4864-89e0-654915790d47';
  $pane->panel = 'work_status_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_employment_status';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 0,
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '46c32bf0-81f2-4864-89e0-654915790d47';
  $display->content['new-46c32bf0-81f2-4864-89e0-654915790d47'] = $pane;
  $display->panels['work_status_'][0] = 'new-46c32bf0-81f2-4864-89e0-654915790d47';
  $pane = new stdClass();
  $pane->pid = 'new-5f4a79c1-359a-4af3-b11c-8966017b4fbe';
  $pane->panel = 'writing_expiry';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_writing_expiry';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'dd_mth_yy',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5f4a79c1-359a-4af3-b11c-8966017b4fbe';
  $display->content['new-5f4a79c1-359a-4af3-b11c-8966017b4fbe'] = $pane;
  $display->panels['writing_expiry'][0] = 'new-5f4a79c1-359a-4af3-b11c-8966017b4fbe';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:staff_member:default'] = $panelizer;

  return $export;
}
