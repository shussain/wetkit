<?php
/**
 * @file
 * node_exort_from_legal_opinion.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function node_exort_from_legal_opinion_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'body\' => array(),
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'1\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => \'a:4:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;s:12:"admin_select";s:6:"navbar";s:15:"navbar_language";i:0;}\',
      \'entity_translation_handler_id\' => \'node-format-eid-29\',
      \'field_pick_list_parent\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'28\',
          ),
        ),
      ),
      \'files\' => array(),
      \'language\' => \'en\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'admin\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'Email\',
      \'title_field\' => array(
        \'en\' => array(
          array(
            \'value\' => \'Email\',
            \'format\' => NULL,
            \'safe_value\' => \'Email\',
          ),
        ),
        \'fr\' => array(
          array(
            \'value\' => \'Email\',
            \'format\' => NULL,
            \'safe_value\' => \'Email\',
          ),
        ),
      ),
      \'title_original\' => \'Email\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'translations\' => (object) array(
          \'original\' => \'en\',
          \'data\' => array(
            \'en\' => array(
              \'entity_type\' => \'node\',
              \'entity_id\' => \'29\',
              \'revision_id\' => \'32\',
              \'language\' => \'en\',
              \'source\' => \'\',
              \'uid\' => \'1\',
              \'status\' => \'1\',
              \'translate\' => \'0\',
              \'created\' => \'1490023255\',
              \'changed\' => \'1490023255\',
            ),
            \'fr\' => array(
              \'entity_type\' => \'node\',
              \'entity_id\' => \'29\',
              \'revision_id\' => \'32\',
              \'language\' => \'fr\',
              \'source\' => \'en\',
              \'uid\' => \'1\',
              \'status\' => \'1\',
              \'translate\' => \'0\',
              \'created\' => \'1490023268\',
              \'changed\' => \'1490023268\',
            ),
          ),
        ),
      \'type\' => \'format\',
      \'uid\' => \'1\',
      \'uuid\' => \'0a9faa62-2c44-4648-887f-b0ad471d9291\',
      \'vid\' => NULL,
      \'vuuid\' => \'592cb8eb-3132-40ec-bdf1-a9fe9e6a26d7\',
    ),
  (object) array(
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'2\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => \'a:4:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;s:12:"admin_select";s:6:"navbar";s:15:"navbar_language";i:0;}\',
      \'entity_translation_handler_id\' => \'node-opinion-eid-35\',
      \'field_attachments\' => array(),
      \'field_background\' => array(
        \'und\' => array(
          array(
            \'value\' => \'<p>My background</p>\',
            \'format\' => \'wetkit_wysiwyg_text\',
            \'safe_value\' => \'<p>My background</p>\',
          ),
        ),
      ),
      \'field_bf_date\' => array(
        \'und\' => array(
          array(
            \'value\' => \'2017-03-21 04:00:00\',
            \'timezone\' => \'America/New_York\',
            \'timezone_db\' => \'UTC\',
            \'date_type\' => \'datetime\',
          ),
        ),
      ),
      \'field_date_sent_to_dlsu\' => array(
        \'und\' => array(
          array(
            \'value\' => \'2017-03-21 04:00:00\',
            \'timezone\' => \'America/New_York\',
            \'timezone_db\' => \'UTC\',
            \'date_type\' => \'datetime\',
          ),
        ),
      ),
      \'field_department_approach_taken\' => array(),
      \'field_dlsu_contact\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'33\',
          ),
        ),
      ),
      \'field_format\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'29\',
          ),
        ),
      ),
      \'field_issue\' => array(),
      \'field_legal_opinion\' => array(),
      \'field_legal_opinion_request\' => array(),
      \'field_main_date\' => array(
        \'und\' => array(
          array(
            \'value\' => \'2017-03-21 00:00:00\',
            \'timezone\' => \'America/New_York\',
            \'timezone_db\' => \'America/New_York\',
            \'date_type\' => \'datetime\',
          ),
        ),
      ),
      \'field_nnhpd_bureau_project\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'34\',
          ),
        ),
      ),
      \'field_parent_space\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'22\',
          ),
        ),
      ),
      \'field_priority\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'30\',
          ),
        ),
      ),
      \'field_receive_date\' => array(
        \'und\' => array(
          array(
            \'value\' => \'2017-03-21 04:00:00\',
            \'timezone\' => \'America/New_York\',
            \'timezone_db\' => \'UTC\',
            \'date_type\' => \'datetime\',
          ),
        ),
      ),
      \'field_related_legal_opinion\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'10\',
          ),
        ),
      ),
      \'field_relevant_chronology\' => array(),
      \'field_relevant_legislations\' => array(),
      \'field_requester\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'32\',
          ),
        ),
      ),
      \'field_requesting_unit\' => array(),
      \'field_serial\' => array(
        \'und\' => array(
          array(
            \'value\' => \'1\',
          ),
        ),
      ),
      \'field_status\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'25\',
          ),
        ),
      ),
      \'field_subject_line\' => array(
        \'und\' => array(
          array(
            \'value\' => \'My first legal opinion\',
            \'format\' => NULL,
            \'safe_value\' => \'My first legal opinion\',
          ),
        ),
      ),
      \'field_summary_of_legal_opinion\' => array(),
      \'field_unique_tag\' => array(
        \'und\' => array(
          array(
            \'value\' => \'000001\',
          ),
        ),
      ),
      \'files\' => array(),
      \'group_content_access\' => array(
        \'und\' => array(
          array(
            \'value\' => \'1\',
          ),
        ),
      ),
      \'language\' => \'en\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'admin\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'panelizer\' => array(
        \'default\' => (object) array(
            \'pnid\' => \'5\',
            \'title\' => \'Default\',
            \'panelizer_type\' => \'node\',
            \'panelizer_key\' => \'opinion\',
            \'access\' => array(),
            \'view_mode\' => \'default\',
            \'did\' => NULL,
            \'name\' => \'node:opinion:default:default\',
            \'css_id\' => \'\',
            \'css_class\' => \'\',
            \'css\' => \'\',
            \'no_blocks\' => \'0\',
            \'title_element\' => \'H2\',
            \'link_to_entity\' => \'1\',
            \'extra\' => array(),
            \'pipeline\' => \'standard\',
            \'contexts\' => array(),
            \'relationships\' => array(),
            \'table\' => \'panelizer_defaults\',
            \'type\' => \'Overridden\',
            \'export_type\' => 3,
            \'display\' => panels_display::__set_state(array(
               \'args\' => 
              array (
              ),
               \'content\' => 
              array (
                74 => 
                stdClass::__set_state(array(
                   \'pid\' => \'74\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:title_field\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'hidden\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'0\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'09ec8429-a31c-48ba-bc95-0da867374c2a\',
                )),
                85 => 
                stdClass::__set_state(array(
                   \'pid\' => \'85\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_subject_line\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'1\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'2cc96bf5-49f4-41f3-8f31-19a34be2a8f1\',
                )),
                80 => 
                stdClass::__set_state(array(
                   \'pid\' => \'80\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_serial\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'hidden\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'2\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'d98400c4-4631-4f5c-b0be-6647a83e43b0\',
                )),
                82 => 
                stdClass::__set_state(array(
                   \'pid\' => \'82\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_background\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'3\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'91e096c1-35c9-4fb6-bc7e-17d8b759edbb\',
                )),
                83 => 
                stdClass::__set_state(array(
                   \'pid\' => \'83\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_relevant_chronology\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'4\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'1e5130e6-c051-4199-b88a-ba47d6d3512f\',
                )),
                84 => 
                stdClass::__set_state(array(
                   \'pid\' => \'84\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_issue\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'5\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'88dcc06d-3eb4-425f-a47b-368302542f0a\',
                )),
                86 => 
                stdClass::__set_state(array(
                   \'pid\' => \'86\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_legal_opinion_request\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'6\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'f4c1b3bd-7352-4332-b6dc-fed3cdfa0ccd\',
                )),
                87 => 
                stdClass::__set_state(array(
                   \'pid\' => \'87\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_summary_of_legal_opinion\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'7\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'f3fa34d2-59c0-4c52-8415-11f5656a6f2e\',
                )),
                88 => 
                stdClass::__set_state(array(
                   \'pid\' => \'88\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_legal_opinion\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'8\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'58826700-c4d4-4459-89a4-bced33bd77cf\',
                )),
                89 => 
                stdClass::__set_state(array(
                   \'pid\' => \'89\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_department_approach_taken\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'9\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'210a19c1-4a19-4d02-95cf-32009dfe41dd\',
                )),
                96 => 
                stdClass::__set_state(array(
                   \'pid\' => \'96\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_attachments\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'file_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'10\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'82cee31c-4e18-484b-8783-cc8847eedcb1\',
                )),
                100 => 
                stdClass::__set_state(array(
                   \'pid\' => \'100\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'node_links\',
                   \'subtype\' => \'node_links\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'override_title\' => false,
                    \'override_title_text\' => \'\',
                    \'build_mode\' => \'default\',
                    \'identifier\' => \'\',
                    \'link\' => true,
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                    \'css_class\' => \'link-wrapper\',
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'11\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'84eebc7c-8fc1-451d-be7c-94cd09f8293d\',
                )),
                99 => 
                stdClass::__set_state(array(
                   \'pid\' => \'99\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_parent_space\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'0\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'62659471-cb4f-48ee-932d-db0c89b33028\',
                )),
                81 => 
                stdClass::__set_state(array(
                   \'pid\' => \'81\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_unique_tag\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'computed_field_plain\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'1\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'10326405-a353-4c34-a2f2-8b45262794a6\',
                )),
                97 => 
                stdClass::__set_state(array(
                   \'pid\' => \'97\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_related_legal_opinion\',
                   \'shown\' => \'0\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => 1,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'2\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'e8e4bcee-a0f9-46b3-8d90-9b6256ef3b06\',
                )),
                75 => 
                stdClass::__set_state(array(
                   \'pid\' => \'75\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_priority\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'3\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'cc33106a-b8c6-45e6-9f0f-b43d9d7fe6a6\',
                )),
                76 => 
                stdClass::__set_state(array(
                   \'pid\' => \'76\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_status\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'4\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'b3807e67-c1ea-47ca-8fe4-66487ec9fa9f\',
                )),
                77 => 
                stdClass::__set_state(array(
                   \'pid\' => \'77\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_requester\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => 1,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'5\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'eff7f0c7-3283-4962-bbfa-041fea08edd0\',
                )),
                98 => 
                stdClass::__set_state(array(
                   \'pid\' => \'98\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_requesting_unit\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'6\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'2439d9aa-7250-4e44-83ae-8239dbdf10a2\',
                )),
                78 => 
                stdClass::__set_state(array(
                   \'pid\' => \'78\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_dlsu_contact\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => 1,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'7\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'6a92c262-c514-436a-a4a7-ea758568f3c8\',
                )),
                79 => 
                stdClass::__set_state(array(
                   \'pid\' => \'79\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_nnhpd_bureau_project\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => 1,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'8\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'5dde2e9a-5dbf-4079-837e-5d001ade89c1\',
                )),
                90 => 
                stdClass::__set_state(array(
                   \'pid\' => \'90\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_relevant_legislations\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'9\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'7bb1fecd-b961-42d8-b87b-0caf9450355f\',
                )),
                91 => 
                stdClass::__set_state(array(
                   \'pid\' => \'91\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_main_date\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'date_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'format_type\' => \'short\',
                      \'fromto\' => \'both\',
                      \'multiple_number\' => \'\',
                      \'multiple_from\' => \'\',
                      \'multiple_to\' => \'\',
                      \'show_remaining_days\' => 0,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'10\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'d1a2c431-72ae-49b8-9cba-3cf8b0dc79f3\',
                )),
                92 => 
                stdClass::__set_state(array(
                   \'pid\' => \'92\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_bf_date\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'date_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'format_type\' => \'short\',
                      \'fromto\' => \'both\',
                      \'multiple_number\' => \'\',
                      \'multiple_from\' => \'\',
                      \'multiple_to\' => \'\',
                      \'show_remaining_days\' => 0,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'11\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'7be6343f-2176-4c43-abab-f35d02a72e03\',
                )),
                93 => 
                stdClass::__set_state(array(
                   \'pid\' => \'93\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_receive_date\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'date_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'format_type\' => \'short\',
                      \'fromto\' => \'both\',
                      \'multiple_number\' => \'\',
                      \'multiple_from\' => \'\',
                      \'multiple_to\' => \'\',
                      \'show_remaining_days\' => 0,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'12\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'8c1402ef-1ca9-4fde-be39-15ce2e98bccd\',
                )),
                94 => 
                stdClass::__set_state(array(
                   \'pid\' => \'94\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_date_sent_to_dlsu\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'date_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'format_type\' => \'short\',
                      \'fromto\' => \'both\',
                      \'multiple_number\' => \'\',
                      \'multiple_from\' => \'\',
                      \'multiple_to\' => \'\',
                      \'show_remaining_days\' => 0,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'13\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'ab31a96a-8eff-4be0-9049-f95e6ad4990b\',
                )),
                95 => 
                stdClass::__set_state(array(
                   \'pid\' => \'95\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_format\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'14\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'33e5939f-e5e2-4e14-bdf2-e41c6c9f8146\',
                )),
                106 => 
                stdClass::__set_state(array(
                   \'pid\' => \'106\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'views_panes\',
                   \'subtype\' => \'legal_opinion-panel_pane_related_opinion\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'view_settings\' => \'fields\',
                    \'header_type\' => \'none\',
                    \'view_mode\' => \'teaser\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'15\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'560d7904-91fd-45e2-ab92-44b97d86c15e\',
                )),
              ),
               \'panels\' => 
              array (
                \'center\' => 
                array (
                  0 => \'74\',
                  1 => \'85\',
                  2 => \'80\',
                  3 => \'82\',
                  4 => \'83\',
                  5 => \'84\',
                  6 => \'86\',
                  7 => \'87\',
                  8 => \'88\',
                  9 => \'89\',
                  10 => \'96\',
                  11 => \'100\',
                ),
                \'right_sidebar\' => 
                array (
                  0 => \'99\',
                  1 => \'81\',
                  2 => \'97\',
                  3 => \'75\',
                  4 => \'76\',
                  5 => \'77\',
                  6 => \'98\',
                  7 => \'78\',
                  8 => \'79\',
                  9 => \'90\',
                  10 => \'91\',
                  11 => \'92\',
                  12 => \'93\',
                  13 => \'94\',
                  14 => \'95\',
                  15 => \'106\',
                ),
              ),
               \'incoming_content\' => NULL,
               \'css_id\' => NULL,
               \'context\' => 
              array (
              ),
               \'did\' => \'9\',
               \'renderer\' => \'standard\',
               \'layout\' => \'flexible\',
               \'layout_settings\' => 
              array (
                \'items\' => 
                array (
                  \'canvas\' => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'column\',
                    \'children\' => 
                    array (
                      0 => \'main\',
                      1 => 1,
                    ),
                    \'parent\' => NULL,
                  ),
                  \'main\' => 
                  array (
                    \'type\' => \'column\',
                    \'width\' => \'76.51967705731147\',
                    \'width_type\' => \'%\',
                    \'children\' => 
                    array (
                      0 => \'main-row\',
                    ),
                    \'parent\' => \'canvas\',
                  ),
                  \'main-row\' => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'region\',
                    \'children\' => 
                    array (
                      0 => \'center\',
                    ),
                    \'parent\' => \'main\',
                  ),
                  \'center\' => 
                  array (
                    \'type\' => \'region\',
                    \'title\' => \'Center\',
                    \'width\' => 100,
                    \'width_type\' => \'%\',
                    \'parent\' => \'main-row\',
                  ),
                  1 => 
                  array (
                    \'type\' => \'column\',
                    \'width\' => \'23.480322942688527\',
                    \'width_type\' => \'%\',
                    \'parent\' => \'canvas\',
                    \'children\' => 
                    array (
                      0 => 2,
                    ),
                    \'class\' => \'\',
                    \'hide_empty\' => 1,
                  ),
                  2 => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'region\',
                    \'children\' => 
                    array (
                      0 => \'right_sidebar\',
                    ),
                    \'parent\' => \'1\',
                    \'class\' => \'\',
                    \'hide_empty\' => 1,
                  ),
                  \'right_sidebar\' => 
                  array (
                    \'type\' => \'region\',
                    \'title\' => \'Right Sidebar\',
                    \'width\' => 100,
                    \'width_type\' => \'%\',
                    \'parent\' => \'2\',
                    \'class\' => \'\',
                    \'hide_empty\' => 1,
                  ),
                ),
              ),
               \'panel_settings\' => 
              array (
                \'style_settings\' => 
                array (
                  \'default\' => NULL,
                  \'center\' => NULL,
                  \'right_sidebar\' => 
                  array (
                    \'style\' => \'$\',
                    \'settings\' => 
                    array (
                      \'name\' => \'_temporary\',
                      \'style_base\' => \'region_plain_box\',
                      \'palette\' => 
                      array (
                        \'background\' => \'#e1e1e1\',
                        \'text\' => \'#000000\',
                        \'border\' => \'#5295ef\',
                      ),
                      \'font\' => 
                      array (
                        \'font\' => \'\',
                        \'size\' => \'\',
                        \'letter_spacing\' => \'\',
                        \'word_spacing\' => \'\',
                        \'decoration\' => \'\',
                        \'weight\' => \'\',
                        \'style\' => \'\',
                        \'variant\' => \'\',
                        \'case\' => \'\',
                        \'alignment\' => \'\',
                      ),
                      \'border\' => 
                      array (
                        \'thickness\' => \'1px\',
                        \'style\' => \'solid\',
                      ),
                      \'padding\' => 
                      array (
                        \'top\' => \'\',
                        \'right\' => \'0.05em\',
                        \'bottom\' => \'\',
                        \'left\' => \'0.5em\',
                      ),
                    ),
                  ),
                ),
                \'right_sidebar\' => 
                array (
                  \'style\' => \'stylizer\',
                ),
              ),
               \'cache\' => 
              array (
              ),
               \'title\' => \'%node:title\',
               \'hide_title\' => \'0\',
               \'title_pane\' => \'74\',
               \'uuid\' => \'d5859a33-8e95-47d2-b73d-d6cf60eeb01b\',
               \'storage_type\' => \'panelizer_default\',
               \'storage_id\' => \'node:opinion:default:default\',
            )),
            \'export_module\' => NULL,
            \'entity_id\' => 0,
            \'revision_id\' => 0,
          ),
      ),
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'000001: My first legal opinion\',
      \'title_field\' => array(
        \'en\' => array(
          array(
            \'value\' => \'000001: My first legal opinion\',
            \'format\' => NULL,
            \'safe_value\' => \'000001: My first legal opinion\',
          ),
        ),
        \'fr\' => array(
          array(
            \'value\' => \'000001: My first legal opinion\',
            \'format\' => NULL,
            \'safe_value\' => \'000001: My first legal opinion\',
          ),
        ),
      ),
      \'title_original\' => \'000001: My first legal opinion\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'translations\' => (object) array(
          \'original\' => \'en\',
          \'data\' => array(
            \'en\' => array(
              \'entity_type\' => \'node\',
              \'entity_id\' => \'35\',
              \'revision_id\' => \'38\',
              \'language\' => \'en\',
              \'source\' => \'\',
              \'uid\' => \'1\',
              \'status\' => \'1\',
              \'translate\' => \'0\',
              \'created\' => \'1490108460\',
              \'changed\' => \'1490192888\',
            ),
          ),
        ),
      \'type\' => \'opinion\',
      \'uid\' => \'1\',
      \'uuid\' => \'0aaca99c-c314-43cb-94d5-614325588ceb\',
      \'vid\' => NULL,
      \'vuuid\' => \'7bd517a2-6249-46f0-b85a-f391925fc75a\',
    ),
  (object) array(
      \'body\' => array(),
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'1\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => \'a:4:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;s:12:"admin_select";s:6:"navbar";s:15:"navbar_language";i:0;}\',
      \'entity_translation_handler_id\' => \'node-requesting_unit-eid-31\',
      \'field_pick_list_parent\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'28\',
          ),
        ),
      ),
      \'files\' => array(),
      \'language\' => \'en\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'admin\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'Requesting Unit A\',
      \'title_field\' => array(
        \'en\' => array(
          array(
            \'value\' => \'Requesting Unit A\',
            \'format\' => NULL,
            \'safe_value\' => \'Requesting Unit A\',
          ),
        ),
      ),
      \'title_original\' => \'Requesting Unit A\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'translations\' => (object) array(
          \'original\' => \'en\',
          \'data\' => array(
            \'en\' => array(
              \'entity_type\' => \'node\',
              \'entity_id\' => \'31\',
              \'revision_id\' => \'34\',
              \'language\' => \'en\',
              \'source\' => \'\',
              \'uid\' => \'1\',
              \'status\' => \'1\',
              \'translate\' => \'0\',
              \'created\' => \'1490108067\',
              \'changed\' => \'1490108067\',
            ),
          ),
        ),
      \'type\' => \'requesting_unit\',
      \'uid\' => \'1\',
      \'uuid\' => \'170c91de-9ea0-49c3-9e01-185e432b6665\',
      \'vid\' => NULL,
      \'vuuid\' => \'6fba52cc-b8a3-44cc-9feb-299f38422842\',
    ),
  (object) array(
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'2\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => \'a:4:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;s:12:"admin_select";s:6:"navbar";s:15:"navbar_language";i:0;}\',
      \'entity_translation_handler_id\' => \'node-opinion-eid-10\',
      \'field_attachments\' => array(),
      \'field_background\' => array(
        \'und\' => array(
          array(
            \'value\' => \'<h3>OG User Roles allows group administrators of organic groups to grant additional user roles to individual members of a certain group.</h3>\',
            \'format\' => \'wetkit_wysiwyg_text\',
            \'safe_value\' => \'<h3>OG User Roles allows group administrators of organic groups to grant additional user roles to individual members of a certain group.</h3>\',
          ),
        ),
      ),
      \'field_bf_date\' => array(),
      \'field_date_sent_to_dlsu\' => array(),
      \'field_department_approach_taken\' => array(),
      \'field_dlsu_contact\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'33\',
          ),
        ),
      ),
      \'field_format\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'29\',
          ),
        ),
      ),
      \'field_issue\' => array(
        \'und\' => array(
          array(
            \'value\' => \'<p><span style="color: rgb(34, 34, 34); font-family: &quot;Lucida Grande&quot;, &quot;DejaVu Sans&quot;, &quot;Bitstream Vera Sans&quot;, Verdana, Arial, sans-serif; font-size: 13px; background-color: rgb(255, 255, 255);">Any additional permissions only apply within the context of this group and not globally. This means that the additional user roles to grant are determined and assigned by the requested page; e.g. node/123 belongs to group XYZ for which the user was granted additional roles. If the user goes to another page that does not belong to the same group, the additional user roles are no longer assigned.</span></p>\',
            \'format\' => \'wetkit_wysiwyg_text\',
            \'safe_value\' => \'<p><span style="color: rgb(34, 34, 34); font-family: &quot;Lucida Grande&quot;, &quot;DejaVu Sans&quot;, &quot;Bitstream Vera Sans&quot;, Verdana, Arial, sans-serif; font-size: 13px; background-color: rgb(255, 255, 255);">Any additional permissions only apply within the context of this group and not globally. This means that the additional user roles to grant are determined and assigned by the requested page; e.g. node/123 belongs to group XYZ for which the user was granted additional roles. If the user goes to another page that does not belong to the same group, the additional user roles are no longer assigned.</span></p>\',
          ),
        ),
      ),
      \'field_legal_opinion\' => array(),
      \'field_legal_opinion_request\' => array(),
      \'field_main_date\' => array(
        \'und\' => array(
          array(
            \'value\' => \'2017-03-21 00:00:00\',
            \'timezone\' => \'America/New_York\',
            \'timezone_db\' => \'America/New_York\',
            \'date_type\' => \'datetime\',
          ),
        ),
      ),
      \'field_nnhpd_bureau_project\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'34\',
          ),
        ),
      ),
      \'field_parent_space\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'22\',
          ),
        ),
      ),
      \'field_priority\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'30\',
          ),
        ),
      ),
      \'field_receive_date\' => array(),
      \'field_related_legal_opinion\' => array(),
      \'field_relevant_chronology\' => array(
        \'und\' => array(
          array(
            \'value\' => \'<p>No contents</p>\',
            \'format\' => \'wetkit_wysiwyg_text\',
            \'safe_value\' => \'<p>No contents</p>\',
          ),
        ),
      ),
      \'field_relevant_legislations\' => array(),
      \'field_requester\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'24\',
          ),
        ),
      ),
      \'field_requesting_unit\' => array(),
      \'field_serial\' => array(
        \'und\' => array(
          array(
            \'value\' => \'2\',
          ),
        ),
      ),
      \'field_status\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'25\',
          ),
        ),
      ),
      \'field_subject_line\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Opinion1\',
            \'format\' => NULL,
            \'safe_value\' => \'Opinion1\',
          ),
        ),
      ),
      \'field_summary_of_legal_opinion\' => array(),
      \'field_unique_tag\' => array(
        \'und\' => array(
          array(
            \'value\' => \'000002\',
          ),
        ),
      ),
      \'files\' => array(),
      \'group_content_access\' => array(),
      \'language\' => \'en\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'admin\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'panelizer\' => array(
        \'default\' => (object) array(
            \'pnid\' => \'5\',
            \'title\' => \'Default\',
            \'panelizer_type\' => \'node\',
            \'panelizer_key\' => \'opinion\',
            \'access\' => array(),
            \'view_mode\' => \'default\',
            \'did\' => NULL,
            \'name\' => \'node:opinion:default:default\',
            \'css_id\' => \'\',
            \'css_class\' => \'\',
            \'css\' => \'\',
            \'no_blocks\' => \'0\',
            \'title_element\' => \'H2\',
            \'link_to_entity\' => \'1\',
            \'extra\' => array(),
            \'pipeline\' => \'standard\',
            \'contexts\' => array(),
            \'relationships\' => array(),
            \'table\' => \'panelizer_defaults\',
            \'type\' => \'Overridden\',
            \'export_type\' => 3,
            \'display\' => panels_display::__set_state(array(
               \'args\' => 
              array (
              ),
               \'content\' => 
              array (
                74 => 
                stdClass::__set_state(array(
                   \'pid\' => \'74\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:title_field\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'hidden\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'0\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'09ec8429-a31c-48ba-bc95-0da867374c2a\',
                )),
                85 => 
                stdClass::__set_state(array(
                   \'pid\' => \'85\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_subject_line\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'1\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'2cc96bf5-49f4-41f3-8f31-19a34be2a8f1\',
                )),
                80 => 
                stdClass::__set_state(array(
                   \'pid\' => \'80\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_serial\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'hidden\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'2\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'d98400c4-4631-4f5c-b0be-6647a83e43b0\',
                )),
                82 => 
                stdClass::__set_state(array(
                   \'pid\' => \'82\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_background\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'3\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'91e096c1-35c9-4fb6-bc7e-17d8b759edbb\',
                )),
                83 => 
                stdClass::__set_state(array(
                   \'pid\' => \'83\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_relevant_chronology\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'4\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'1e5130e6-c051-4199-b88a-ba47d6d3512f\',
                )),
                84 => 
                stdClass::__set_state(array(
                   \'pid\' => \'84\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_issue\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'5\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'88dcc06d-3eb4-425f-a47b-368302542f0a\',
                )),
                86 => 
                stdClass::__set_state(array(
                   \'pid\' => \'86\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_legal_opinion_request\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'6\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'f4c1b3bd-7352-4332-b6dc-fed3cdfa0ccd\',
                )),
                87 => 
                stdClass::__set_state(array(
                   \'pid\' => \'87\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_summary_of_legal_opinion\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'7\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'f3fa34d2-59c0-4c52-8415-11f5656a6f2e\',
                )),
                88 => 
                stdClass::__set_state(array(
                   \'pid\' => \'88\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_legal_opinion\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'8\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'58826700-c4d4-4459-89a4-bced33bd77cf\',
                )),
                89 => 
                stdClass::__set_state(array(
                   \'pid\' => \'89\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_department_approach_taken\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'9\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'210a19c1-4a19-4d02-95cf-32009dfe41dd\',
                )),
                96 => 
                stdClass::__set_state(array(
                   \'pid\' => \'96\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_attachments\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'file_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'10\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'82cee31c-4e18-484b-8783-cc8847eedcb1\',
                )),
                100 => 
                stdClass::__set_state(array(
                   \'pid\' => \'100\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'node_links\',
                   \'subtype\' => \'node_links\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'override_title\' => false,
                    \'override_title_text\' => \'\',
                    \'build_mode\' => \'default\',
                    \'identifier\' => \'\',
                    \'link\' => true,
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                    \'css_class\' => \'link-wrapper\',
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'11\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'84eebc7c-8fc1-451d-be7c-94cd09f8293d\',
                )),
                99 => 
                stdClass::__set_state(array(
                   \'pid\' => \'99\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_parent_space\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'0\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'62659471-cb4f-48ee-932d-db0c89b33028\',
                )),
                81 => 
                stdClass::__set_state(array(
                   \'pid\' => \'81\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_unique_tag\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'computed_field_plain\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'1\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'10326405-a353-4c34-a2f2-8b45262794a6\',
                )),
                97 => 
                stdClass::__set_state(array(
                   \'pid\' => \'97\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_related_legal_opinion\',
                   \'shown\' => \'0\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => 1,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'2\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'e8e4bcee-a0f9-46b3-8d90-9b6256ef3b06\',
                )),
                75 => 
                stdClass::__set_state(array(
                   \'pid\' => \'75\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_priority\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'3\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'cc33106a-b8c6-45e6-9f0f-b43d9d7fe6a6\',
                )),
                76 => 
                stdClass::__set_state(array(
                   \'pid\' => \'76\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_status\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'4\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'b3807e67-c1ea-47ca-8fe4-66487ec9fa9f\',
                )),
                77 => 
                stdClass::__set_state(array(
                   \'pid\' => \'77\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_requester\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => 1,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'5\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'eff7f0c7-3283-4962-bbfa-041fea08edd0\',
                )),
                98 => 
                stdClass::__set_state(array(
                   \'pid\' => \'98\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_requesting_unit\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'6\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'2439d9aa-7250-4e44-83ae-8239dbdf10a2\',
                )),
                78 => 
                stdClass::__set_state(array(
                   \'pid\' => \'78\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_dlsu_contact\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => 1,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'7\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'6a92c262-c514-436a-a4a7-ea758568f3c8\',
                )),
                79 => 
                stdClass::__set_state(array(
                   \'pid\' => \'79\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_nnhpd_bureau_project\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => 1,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'8\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'5dde2e9a-5dbf-4079-837e-5d001ade89c1\',
                )),
                90 => 
                stdClass::__set_state(array(
                   \'pid\' => \'90\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_relevant_legislations\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'9\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'7bb1fecd-b961-42d8-b87b-0caf9450355f\',
                )),
                91 => 
                stdClass::__set_state(array(
                   \'pid\' => \'91\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_main_date\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'date_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'format_type\' => \'short\',
                      \'fromto\' => \'both\',
                      \'multiple_number\' => \'\',
                      \'multiple_from\' => \'\',
                      \'multiple_to\' => \'\',
                      \'show_remaining_days\' => 0,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'10\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'d1a2c431-72ae-49b8-9cba-3cf8b0dc79f3\',
                )),
                92 => 
                stdClass::__set_state(array(
                   \'pid\' => \'92\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_bf_date\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'date_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'format_type\' => \'short\',
                      \'fromto\' => \'both\',
                      \'multiple_number\' => \'\',
                      \'multiple_from\' => \'\',
                      \'multiple_to\' => \'\',
                      \'show_remaining_days\' => 0,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'11\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'7be6343f-2176-4c43-abab-f35d02a72e03\',
                )),
                93 => 
                stdClass::__set_state(array(
                   \'pid\' => \'93\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_receive_date\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'date_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'format_type\' => \'short\',
                      \'fromto\' => \'both\',
                      \'multiple_number\' => \'\',
                      \'multiple_from\' => \'\',
                      \'multiple_to\' => \'\',
                      \'show_remaining_days\' => 0,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'12\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'8c1402ef-1ca9-4fde-be39-15ce2e98bccd\',
                )),
                94 => 
                stdClass::__set_state(array(
                   \'pid\' => \'94\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_date_sent_to_dlsu\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'date_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'format_type\' => \'short\',
                      \'fromto\' => \'both\',
                      \'multiple_number\' => \'\',
                      \'multiple_from\' => \'\',
                      \'multiple_to\' => \'\',
                      \'show_remaining_days\' => 0,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'13\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'ab31a96a-8eff-4be0-9049-f95e6ad4990b\',
                )),
                95 => 
                stdClass::__set_state(array(
                   \'pid\' => \'95\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_format\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'14\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'33e5939f-e5e2-4e14-bdf2-e41c6c9f8146\',
                )),
                106 => 
                stdClass::__set_state(array(
                   \'pid\' => \'106\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'views_panes\',
                   \'subtype\' => \'legal_opinion-panel_pane_related_opinion\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'view_settings\' => \'fields\',
                    \'header_type\' => \'none\',
                    \'view_mode\' => \'teaser\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'15\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'560d7904-91fd-45e2-ab92-44b97d86c15e\',
                )),
              ),
               \'panels\' => 
              array (
                \'center\' => 
                array (
                  0 => \'74\',
                  1 => \'85\',
                  2 => \'80\',
                  3 => \'82\',
                  4 => \'83\',
                  5 => \'84\',
                  6 => \'86\',
                  7 => \'87\',
                  8 => \'88\',
                  9 => \'89\',
                  10 => \'96\',
                  11 => \'100\',
                ),
                \'right_sidebar\' => 
                array (
                  0 => \'99\',
                  1 => \'81\',
                  2 => \'97\',
                  3 => \'75\',
                  4 => \'76\',
                  5 => \'77\',
                  6 => \'98\',
                  7 => \'78\',
                  8 => \'79\',
                  9 => \'90\',
                  10 => \'91\',
                  11 => \'92\',
                  12 => \'93\',
                  13 => \'94\',
                  14 => \'95\',
                  15 => \'106\',
                ),
              ),
               \'incoming_content\' => NULL,
               \'css_id\' => NULL,
               \'context\' => 
              array (
              ),
               \'did\' => \'9\',
               \'renderer\' => \'standard\',
               \'layout\' => \'flexible\',
               \'layout_settings\' => 
              array (
                \'items\' => 
                array (
                  \'canvas\' => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'column\',
                    \'children\' => 
                    array (
                      0 => \'main\',
                      1 => 1,
                    ),
                    \'parent\' => NULL,
                  ),
                  \'main\' => 
                  array (
                    \'type\' => \'column\',
                    \'width\' => \'76.51967705731147\',
                    \'width_type\' => \'%\',
                    \'children\' => 
                    array (
                      0 => \'main-row\',
                    ),
                    \'parent\' => \'canvas\',
                  ),
                  \'main-row\' => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'region\',
                    \'children\' => 
                    array (
                      0 => \'center\',
                    ),
                    \'parent\' => \'main\',
                  ),
                  \'center\' => 
                  array (
                    \'type\' => \'region\',
                    \'title\' => \'Center\',
                    \'width\' => 100,
                    \'width_type\' => \'%\',
                    \'parent\' => \'main-row\',
                  ),
                  1 => 
                  array (
                    \'type\' => \'column\',
                    \'width\' => \'23.480322942688527\',
                    \'width_type\' => \'%\',
                    \'parent\' => \'canvas\',
                    \'children\' => 
                    array (
                      0 => 2,
                    ),
                    \'class\' => \'\',
                    \'hide_empty\' => 1,
                  ),
                  2 => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'region\',
                    \'children\' => 
                    array (
                      0 => \'right_sidebar\',
                    ),
                    \'parent\' => \'1\',
                    \'class\' => \'\',
                    \'hide_empty\' => 1,
                  ),
                  \'right_sidebar\' => 
                  array (
                    \'type\' => \'region\',
                    \'title\' => \'Right Sidebar\',
                    \'width\' => 100,
                    \'width_type\' => \'%\',
                    \'parent\' => \'2\',
                    \'class\' => \'\',
                    \'hide_empty\' => 1,
                  ),
                ),
              ),
               \'panel_settings\' => 
              array (
                \'style_settings\' => 
                array (
                  \'default\' => NULL,
                  \'center\' => NULL,
                  \'right_sidebar\' => 
                  array (
                    \'style\' => \'$\',
                    \'settings\' => 
                    array (
                      \'name\' => \'_temporary\',
                      \'style_base\' => \'region_plain_box\',
                      \'palette\' => 
                      array (
                        \'background\' => \'#e1e1e1\',
                        \'text\' => \'#000000\',
                        \'border\' => \'#5295ef\',
                      ),
                      \'font\' => 
                      array (
                        \'font\' => \'\',
                        \'size\' => \'\',
                        \'letter_spacing\' => \'\',
                        \'word_spacing\' => \'\',
                        \'decoration\' => \'\',
                        \'weight\' => \'\',
                        \'style\' => \'\',
                        \'variant\' => \'\',
                        \'case\' => \'\',
                        \'alignment\' => \'\',
                      ),
                      \'border\' => 
                      array (
                        \'thickness\' => \'1px\',
                        \'style\' => \'solid\',
                      ),
                      \'padding\' => 
                      array (
                        \'top\' => \'\',
                        \'right\' => \'0.05em\',
                        \'bottom\' => \'\',
                        \'left\' => \'0.5em\',
                      ),
                    ),
                  ),
                ),
                \'right_sidebar\' => 
                array (
                  \'style\' => \'stylizer\',
                ),
              ),
               \'cache\' => 
              array (
              ),
               \'title\' => \'%node:title\',
               \'hide_title\' => \'0\',
               \'title_pane\' => \'74\',
               \'uuid\' => \'d5859a33-8e95-47d2-b73d-d6cf60eeb01b\',
               \'storage_type\' => \'panelizer_default\',
               \'storage_id\' => \'node:opinion:default:default\',
            )),
            \'export_module\' => NULL,
            \'entity_id\' => 0,
            \'revision_id\' => 0,
          ),
      ),
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'000002: Opinion1\',
      \'title_field\' => array(
        \'en\' => array(
          array(
            \'value\' => \'000002: Opinion1\',
            \'format\' => NULL,
            \'safe_value\' => \'000002: Opinion1\',
          ),
        ),
        \'fr\' => array(
          array(
            \'value\' => \'000002: Opinion1\',
            \'format\' => NULL,
            \'safe_value\' => \'000002: Opinion1\',
          ),
        ),
      ),
      \'title_original\' => \'000002: Opinion1\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'translations\' => (object) array(
          \'original\' => \'en\',
          \'data\' => array(
            \'en\' => array(
              \'entity_type\' => \'node\',
              \'entity_id\' => \'10\',
              \'revision_id\' => \'13\',
              \'language\' => \'en\',
              \'source\' => \'\',
              \'uid\' => \'1\',
              \'status\' => \'1\',
              \'translate\' => \'0\',
              \'created\' => \'1489421400\',
              \'changed\' => \'1490124466\',
            ),
          ),
        ),
      \'type\' => \'opinion\',
      \'uid\' => \'1\',
      \'uuid\' => \'19bdb566-551a-461d-8f34-cdfb73691800\',
      \'vid\' => NULL,
      \'vuuid\' => \'1568ee8b-ce9c-49fc-b206-8d678118a173\',
    ),
  (object) array(
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'2\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => \'a:4:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;s:12:"admin_select";s:6:"navbar";s:15:"navbar_language";i:0;}\',
      \'entity_translation_handler_id\' => \'node-opinion-eid-12\',
      \'field_attachments\' => array(),
      \'field_background\' => array(),
      \'field_bf_date\' => array(),
      \'field_date_sent_to_dlsu\' => array(),
      \'field_department_approach_taken\' => array(),
      \'field_dlsu_contact\' => array(),
      \'field_format\' => array(),
      \'field_issue\' => array(),
      \'field_legal_opinion\' => array(),
      \'field_legal_opinion_request\' => array(),
      \'field_main_date\' => array(),
      \'field_nnhpd_bureau_project\' => array(),
      \'field_parent_space\' => array(),
      \'field_priority\' => array(),
      \'field_receive_date\' => array(),
      \'field_related_legal_opinion\' => array(),
      \'field_relevant_chronology\' => array(),
      \'field_relevant_legislations\' => array(),
      \'field_requester\' => array(),
      \'field_requesting_unit\' => array(),
      \'field_serial\' => array(),
      \'field_status\' => array(),
      \'field_subject_line\' => array(),
      \'field_summary_of_legal_opinion\' => array(),
      \'field_unique_tag\' => array(),
      \'files\' => array(),
      \'group_content_access\' => array(),
      \'language\' => \'en\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'admin\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'panelizer\' => array(
        \'default\' => (object) array(
            \'pnid\' => \'5\',
            \'title\' => \'Default\',
            \'panelizer_type\' => \'node\',
            \'panelizer_key\' => \'opinion\',
            \'access\' => array(),
            \'view_mode\' => \'default\',
            \'did\' => NULL,
            \'name\' => \'node:opinion:default:default\',
            \'css_id\' => \'\',
            \'css_class\' => \'\',
            \'css\' => \'\',
            \'no_blocks\' => \'0\',
            \'title_element\' => \'H2\',
            \'link_to_entity\' => \'1\',
            \'extra\' => array(),
            \'pipeline\' => \'standard\',
            \'contexts\' => array(),
            \'relationships\' => array(),
            \'table\' => \'panelizer_defaults\',
            \'type\' => \'Overridden\',
            \'export_type\' => 3,
            \'display\' => panels_display::__set_state(array(
               \'args\' => 
              array (
              ),
               \'content\' => 
              array (
                74 => 
                stdClass::__set_state(array(
                   \'pid\' => \'74\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:title_field\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'hidden\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'0\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'09ec8429-a31c-48ba-bc95-0da867374c2a\',
                )),
                85 => 
                stdClass::__set_state(array(
                   \'pid\' => \'85\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_subject_line\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'1\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'2cc96bf5-49f4-41f3-8f31-19a34be2a8f1\',
                )),
                80 => 
                stdClass::__set_state(array(
                   \'pid\' => \'80\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_serial\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'hidden\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'2\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'d98400c4-4631-4f5c-b0be-6647a83e43b0\',
                )),
                82 => 
                stdClass::__set_state(array(
                   \'pid\' => \'82\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_background\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'3\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'91e096c1-35c9-4fb6-bc7e-17d8b759edbb\',
                )),
                83 => 
                stdClass::__set_state(array(
                   \'pid\' => \'83\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_relevant_chronology\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'4\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'1e5130e6-c051-4199-b88a-ba47d6d3512f\',
                )),
                84 => 
                stdClass::__set_state(array(
                   \'pid\' => \'84\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_issue\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'5\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'88dcc06d-3eb4-425f-a47b-368302542f0a\',
                )),
                86 => 
                stdClass::__set_state(array(
                   \'pid\' => \'86\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_legal_opinion_request\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'6\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'f4c1b3bd-7352-4332-b6dc-fed3cdfa0ccd\',
                )),
                87 => 
                stdClass::__set_state(array(
                   \'pid\' => \'87\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_summary_of_legal_opinion\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'7\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'f3fa34d2-59c0-4c52-8415-11f5656a6f2e\',
                )),
                88 => 
                stdClass::__set_state(array(
                   \'pid\' => \'88\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_legal_opinion\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'8\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'58826700-c4d4-4459-89a4-bced33bd77cf\',
                )),
                89 => 
                stdClass::__set_state(array(
                   \'pid\' => \'89\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_department_approach_taken\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'9\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'210a19c1-4a19-4d02-95cf-32009dfe41dd\',
                )),
                96 => 
                stdClass::__set_state(array(
                   \'pid\' => \'96\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_attachments\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'file_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'10\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'82cee31c-4e18-484b-8783-cc8847eedcb1\',
                )),
                100 => 
                stdClass::__set_state(array(
                   \'pid\' => \'100\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'node_links\',
                   \'subtype\' => \'node_links\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'override_title\' => false,
                    \'override_title_text\' => \'\',
                    \'build_mode\' => \'default\',
                    \'identifier\' => \'\',
                    \'link\' => true,
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                    \'css_class\' => \'link-wrapper\',
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'11\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'84eebc7c-8fc1-451d-be7c-94cd09f8293d\',
                )),
                99 => 
                stdClass::__set_state(array(
                   \'pid\' => \'99\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_parent_space\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'0\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'62659471-cb4f-48ee-932d-db0c89b33028\',
                )),
                81 => 
                stdClass::__set_state(array(
                   \'pid\' => \'81\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_unique_tag\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'computed_field_plain\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'1\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'10326405-a353-4c34-a2f2-8b45262794a6\',
                )),
                97 => 
                stdClass::__set_state(array(
                   \'pid\' => \'97\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_related_legal_opinion\',
                   \'shown\' => \'0\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => 1,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'2\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'e8e4bcee-a0f9-46b3-8d90-9b6256ef3b06\',
                )),
                75 => 
                stdClass::__set_state(array(
                   \'pid\' => \'75\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_priority\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'3\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'cc33106a-b8c6-45e6-9f0f-b43d9d7fe6a6\',
                )),
                76 => 
                stdClass::__set_state(array(
                   \'pid\' => \'76\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_status\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'4\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'b3807e67-c1ea-47ca-8fe4-66487ec9fa9f\',
                )),
                77 => 
                stdClass::__set_state(array(
                   \'pid\' => \'77\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_requester\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => 1,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'5\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'eff7f0c7-3283-4962-bbfa-041fea08edd0\',
                )),
                98 => 
                stdClass::__set_state(array(
                   \'pid\' => \'98\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_requesting_unit\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'6\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'2439d9aa-7250-4e44-83ae-8239dbdf10a2\',
                )),
                78 => 
                stdClass::__set_state(array(
                   \'pid\' => \'78\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_dlsu_contact\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => 1,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'7\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'6a92c262-c514-436a-a4a7-ea758568f3c8\',
                )),
                79 => 
                stdClass::__set_state(array(
                   \'pid\' => \'79\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_nnhpd_bureau_project\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => 1,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'8\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'5dde2e9a-5dbf-4079-837e-5d001ade89c1\',
                )),
                90 => 
                stdClass::__set_state(array(
                   \'pid\' => \'90\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_relevant_legislations\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'9\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'7bb1fecd-b961-42d8-b87b-0caf9450355f\',
                )),
                91 => 
                stdClass::__set_state(array(
                   \'pid\' => \'91\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_main_date\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'date_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'format_type\' => \'short\',
                      \'fromto\' => \'both\',
                      \'multiple_number\' => \'\',
                      \'multiple_from\' => \'\',
                      \'multiple_to\' => \'\',
                      \'show_remaining_days\' => 0,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'10\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'d1a2c431-72ae-49b8-9cba-3cf8b0dc79f3\',
                )),
                92 => 
                stdClass::__set_state(array(
                   \'pid\' => \'92\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_bf_date\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'date_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'format_type\' => \'short\',
                      \'fromto\' => \'both\',
                      \'multiple_number\' => \'\',
                      \'multiple_from\' => \'\',
                      \'multiple_to\' => \'\',
                      \'show_remaining_days\' => 0,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'11\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'7be6343f-2176-4c43-abab-f35d02a72e03\',
                )),
                93 => 
                stdClass::__set_state(array(
                   \'pid\' => \'93\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_receive_date\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'date_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'format_type\' => \'short\',
                      \'fromto\' => \'both\',
                      \'multiple_number\' => \'\',
                      \'multiple_from\' => \'\',
                      \'multiple_to\' => \'\',
                      \'show_remaining_days\' => 0,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'12\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'8c1402ef-1ca9-4fde-be39-15ce2e98bccd\',
                )),
                94 => 
                stdClass::__set_state(array(
                   \'pid\' => \'94\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_date_sent_to_dlsu\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'date_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'format_type\' => \'short\',
                      \'fromto\' => \'both\',
                      \'multiple_number\' => \'\',
                      \'multiple_from\' => \'\',
                      \'multiple_to\' => \'\',
                      \'show_remaining_days\' => 0,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'13\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'ab31a96a-8eff-4be0-9049-f95e6ad4990b\',
                )),
                95 => 
                stdClass::__set_state(array(
                   \'pid\' => \'95\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_format\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'14\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'33e5939f-e5e2-4e14-bdf2-e41c6c9f8146\',
                )),
                106 => 
                stdClass::__set_state(array(
                   \'pid\' => \'106\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'views_panes\',
                   \'subtype\' => \'legal_opinion-panel_pane_related_opinion\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'view_settings\' => \'fields\',
                    \'header_type\' => \'none\',
                    \'view_mode\' => \'teaser\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'15\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'560d7904-91fd-45e2-ab92-44b97d86c15e\',
                )),
              ),
               \'panels\' => 
              array (
                \'center\' => 
                array (
                  0 => \'74\',
                  1 => \'85\',
                  2 => \'80\',
                  3 => \'82\',
                  4 => \'83\',
                  5 => \'84\',
                  6 => \'86\',
                  7 => \'87\',
                  8 => \'88\',
                  9 => \'89\',
                  10 => \'96\',
                  11 => \'100\',
                ),
                \'right_sidebar\' => 
                array (
                  0 => \'99\',
                  1 => \'81\',
                  2 => \'97\',
                  3 => \'75\',
                  4 => \'76\',
                  5 => \'77\',
                  6 => \'98\',
                  7 => \'78\',
                  8 => \'79\',
                  9 => \'90\',
                  10 => \'91\',
                  11 => \'92\',
                  12 => \'93\',
                  13 => \'94\',
                  14 => \'95\',
                  15 => \'106\',
                ),
              ),
               \'incoming_content\' => NULL,
               \'css_id\' => NULL,
               \'context\' => 
              array (
              ),
               \'did\' => \'9\',
               \'renderer\' => \'standard\',
               \'layout\' => \'flexible\',
               \'layout_settings\' => 
              array (
                \'items\' => 
                array (
                  \'canvas\' => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'column\',
                    \'children\' => 
                    array (
                      0 => \'main\',
                      1 => 1,
                    ),
                    \'parent\' => NULL,
                  ),
                  \'main\' => 
                  array (
                    \'type\' => \'column\',
                    \'width\' => \'76.51967705731147\',
                    \'width_type\' => \'%\',
                    \'children\' => 
                    array (
                      0 => \'main-row\',
                    ),
                    \'parent\' => \'canvas\',
                  ),
                  \'main-row\' => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'region\',
                    \'children\' => 
                    array (
                      0 => \'center\',
                    ),
                    \'parent\' => \'main\',
                  ),
                  \'center\' => 
                  array (
                    \'type\' => \'region\',
                    \'title\' => \'Center\',
                    \'width\' => 100,
                    \'width_type\' => \'%\',
                    \'parent\' => \'main-row\',
                  ),
                  1 => 
                  array (
                    \'type\' => \'column\',
                    \'width\' => \'23.480322942688527\',
                    \'width_type\' => \'%\',
                    \'parent\' => \'canvas\',
                    \'children\' => 
                    array (
                      0 => 2,
                    ),
                    \'class\' => \'\',
                    \'hide_empty\' => 1,
                  ),
                  2 => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'region\',
                    \'children\' => 
                    array (
                      0 => \'right_sidebar\',
                    ),
                    \'parent\' => \'1\',
                    \'class\' => \'\',
                    \'hide_empty\' => 1,
                  ),
                  \'right_sidebar\' => 
                  array (
                    \'type\' => \'region\',
                    \'title\' => \'Right Sidebar\',
                    \'width\' => 100,
                    \'width_type\' => \'%\',
                    \'parent\' => \'2\',
                    \'class\' => \'\',
                    \'hide_empty\' => 1,
                  ),
                ),
              ),
               \'panel_settings\' => 
              array (
                \'style_settings\' => 
                array (
                  \'default\' => NULL,
                  \'center\' => NULL,
                  \'right_sidebar\' => 
                  array (
                    \'style\' => \'$\',
                    \'settings\' => 
                    array (
                      \'name\' => \'_temporary\',
                      \'style_base\' => \'region_plain_box\',
                      \'palette\' => 
                      array (
                        \'background\' => \'#e1e1e1\',
                        \'text\' => \'#000000\',
                        \'border\' => \'#5295ef\',
                      ),
                      \'font\' => 
                      array (
                        \'font\' => \'\',
                        \'size\' => \'\',
                        \'letter_spacing\' => \'\',
                        \'word_spacing\' => \'\',
                        \'decoration\' => \'\',
                        \'weight\' => \'\',
                        \'style\' => \'\',
                        \'variant\' => \'\',
                        \'case\' => \'\',
                        \'alignment\' => \'\',
                      ),
                      \'border\' => 
                      array (
                        \'thickness\' => \'1px\',
                        \'style\' => \'solid\',
                      ),
                      \'padding\' => 
                      array (
                        \'top\' => \'\',
                        \'right\' => \'0.05em\',
                        \'bottom\' => \'\',
                        \'left\' => \'0.5em\',
                      ),
                    ),
                  ),
                ),
                \'right_sidebar\' => 
                array (
                  \'style\' => \'stylizer\',
                ),
              ),
               \'cache\' => 
              array (
              ),
               \'title\' => \'%node:title\',
               \'hide_title\' => \'0\',
               \'title_pane\' => \'74\',
               \'uuid\' => \'d5859a33-8e95-47d2-b73d-d6cf60eeb01b\',
               \'storage_type\' => \'panelizer_default\',
               \'storage_id\' => \'node:opinion:default:default\',
            )),
            \'export_module\' => NULL,
            \'entity_id\' => 0,
            \'revision_id\' => 0,
          ),
      ),
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'Opinion2\',
      \'title_field\' => array(
        \'en\' => array(
          array(
            \'value\' => \'Opinion2\',
            \'format\' => NULL,
            \'safe_value\' => \'Opinion2\',
          ),
        ),
      ),
      \'title_original\' => \'Opinion2\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'translations\' => (object) array(
          \'original\' => \'en\',
          \'data\' => array(
            \'en\' => array(
              \'entity_type\' => \'node\',
              \'entity_id\' => \'12\',
              \'revision_id\' => \'15\',
              \'language\' => \'en\',
              \'source\' => \'\',
              \'uid\' => \'1\',
              \'status\' => \'1\',
              \'translate\' => \'0\',
              \'created\' => \'1489519980\',
              \'changed\' => \'1489757930\',
            ),
          ),
        ),
      \'type\' => \'opinion\',
      \'uid\' => \'1\',
      \'uuid\' => \'2a642739-fad4-4da0-9d74-591e809d4596\',
      \'vid\' => NULL,
      \'vuuid\' => \'f18d486e-a8e1-4aca-b62d-aedcda3eedc5\',
    ),
  (object) array(
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'1\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => \'a:4:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;s:12:"admin_select";s:6:"navbar";s:15:"navbar_language";i:0;}\',
      \'entity_translation_handler_id\' => \'node-requester-eid-24\',
      \'field_email\' => array(),
      \'field_given_name\' => array(
        \'und\' => array(
          array(
            \'value\' => \'test\',
            \'format\' => NULL,
            \'safe_value\' => \'test\',
          ),
        ),
      ),
      \'field_pick_list_parent\' => array(),
      \'field_surname\' => array(
        \'und\' => array(
          array(
            \'value\' => \'test\',
            \'format\' => NULL,
            \'safe_value\' => \'test\',
          ),
        ),
      ),
      \'field_telephone\' => array(),
      \'field_title\' => array(),
      \'files\' => array(),
      \'language\' => \'en\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'15\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'admin\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'test,test\',
      \'title_field\' => array(
        \'en\' => array(
          array(
            \'value\' => \'test,test\',
            \'format\' => NULL,
            \'safe_value\' => \'test,test\',
          ),
        ),
        \'fr\' => array(
          array(
            \'value\' => \'test,test\',
            \'format\' => NULL,
            \'safe_value\' => \'test,test\',
          ),
        ),
      ),
      \'title_original\' => \'test,test\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'translations\' => (object) array(
          \'original\' => NULL,
          \'data\' => array(),
        ),
      \'type\' => \'requester\',
      \'uid\' => \'1\',
      \'uuid\' => \'30dae3be-5b2a-4ae1-b4f6-f59907dde082\',
      \'vid\' => NULL,
      \'vuuid\' => \'79a93846-6894-40ed-bbef-7e38bc3b6f2d\',
    ),
  (object) array(
      \'body\' => array(),
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'1\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => \'a:4:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;s:12:"admin_select";s:6:"navbar";s:15:"navbar_language";i:0;}\',
      \'entity_translation_handler_id\' => \'node-pick_list-eid-28\',
      \'files\' => array(),
      \'group_access\' => array(
        \'und\' => array(
          array(
            \'value\' => \'1\',
          ),
        ),
      ),
      \'group_group\' => array(
        \'und\' => array(
          array(
            \'value\' => \'1\',
          ),
        ),
      ),
      \'language\' => \'en\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'admin\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'og_roles_permissions\' => array(
        \'und\' => array(
          array(
            \'value\' => \'0\',
          ),
        ),
      ),
      \'panelizer\' => array(
        \'default\' => (object) array(
            \'pnid\' => \'4\',
            \'title\' => \'Default\',
            \'panelizer_type\' => \'node\',
            \'panelizer_key\' => \'pick_list\',
            \'access\' => array(),
            \'view_mode\' => \'default\',
            \'did\' => NULL,
            \'name\' => \'node:pick_list:default:default\',
            \'css_id\' => \'\',
            \'css_class\' => \'\',
            \'css\' => \'\',
            \'no_blocks\' => \'0\',
            \'title_element\' => \'H2\',
            \'link_to_entity\' => \'1\',
            \'extra\' => array(),
            \'pipeline\' => \'standard\',
            \'contexts\' => array(),
            \'relationships\' => array(),
            \'table\' => \'panelizer_defaults\',
            \'type\' => \'Overridden\',
            \'export_type\' => 3,
            \'display\' => panels_display::__set_state(array(
               \'args\' => 
              array (
              ),
               \'content\' => 
              array (
                70 => 
                stdClass::__set_state(array(
                   \'pid\' => \'70\',
                   \'did\' => \'8\',
                   \'panel\' => \'add_list\',
                   \'type\' => \'block\',
                   \'subtype\' => \'bean-create-pick-lists\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                    \'plugins\' => 
                    array (
                      0 => 
                      array (
                        \'name\' => \'role\',
                        \'settings\' => 
                        array (
                          \'rids\' => 
                          array (
                            0 => 3,
                            1 => 4,
                          ),
                        ),
                        \'context\' => \'logged-in-user\',
                        \'not\' => false,
                      ),
                    ),
                    \'logic\' => \'and\',
                  ),
                   \'configuration\' => 
                  array (
                    \'override_title\' => 0,
                    \'override_title_text\' => \'\',
                    \'override_title_heading\' => \'h2\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'style\' => \'default\',
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'0\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'90161c67-440e-4feb-8fdc-45ccd393cf81\',
                )),
                56 => 
                stdClass::__set_state(array(
                   \'pid\' => \'56\',
                   \'did\' => \'8\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:group_group\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'og_group_subscribe\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'field_name\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'0\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'3e3cd6a9-0333-426f-b891-dbc452c665c8\',
                )),
                57 => 
                stdClass::__set_state(array(
                   \'pid\' => \'57\',
                   \'did\' => \'8\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:body\',
                   \'shown\' => \'0\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'hidden\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'1\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'ef26cddc-65f7-4ec5-9119-e91375d31da8\',
                )),
                58 => 
                stdClass::__set_state(array(
                   \'pid\' => \'58\',
                   \'did\' => \'8\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_pick_list_parent\',
                   \'shown\' => \'0\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'2\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'ac588207-07ac-4ce1-b5e4-7bce78493ec7\',
                )),
                59 => 
                stdClass::__set_state(array(
                   \'pid\' => \'59\',
                   \'did\' => \'8\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:title_field\',
                   \'shown\' => \'0\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'hidden\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'3\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'85e23666-0b27-4448-89a3-3ce73c584c2a\',
                )),
                60 => 
                stdClass::__set_state(array(
                   \'pid\' => \'60\',
                   \'did\' => \'8\',
                   \'panel\' => \'center\',
                   \'type\' => \'node_links\',
                   \'subtype\' => \'node_links\',
                   \'shown\' => \'0\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'override_title\' => false,
                    \'override_title_text\' => \'\',
                    \'build_mode\' => \'default\',
                    \'identifier\' => \'\',
                    \'link\' => true,
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                    \'css_class\' => \'link-wrapper\',
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'4\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'399863a8-e850-466b-8597-09e19cb27b13\',
                )),
                105 => 
                stdClass::__set_state(array(
                   \'pid\' => \'105\',
                   \'did\' => \'8\',
                   \'panel\' => \'lists\',
                   \'type\' => \'views_panes\',
                   \'subtype\' => \'legal_opinion-panel_pane_pick_lists\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'view_settings\' => \'fields\',
                    \'header_type\' => \'none\',
                    \'view_mode\' => \'teaser\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'0\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'976e00cf-30a4-4e48-9aa5-183ae03c6f65\',
                )),
              ),
               \'panels\' => 
              array (
                \'add_list\' => 
                array (
                  0 => \'70\',
                ),
                \'center\' => 
                array (
                  0 => \'56\',
                  1 => \'57\',
                  2 => \'58\',
                  3 => \'59\',
                  4 => \'60\',
                ),
                \'lists\' => 
                array (
                  0 => \'105\',
                ),
              ),
               \'incoming_content\' => NULL,
               \'css_id\' => NULL,
               \'context\' => 
              array (
              ),
               \'did\' => \'8\',
               \'renderer\' => \'standard\',
               \'layout\' => \'flexible\',
               \'layout_settings\' => 
              array (
                \'items\' => 
                array (
                  \'canvas\' => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'column\',
                    \'children\' => 
                    array (
                      0 => \'main\',
                    ),
                    \'parent\' => NULL,
                  ),
                  \'main\' => 
                  array (
                    \'type\' => \'column\',
                    \'width\' => 100,
                    \'width_type\' => \'%\',
                    \'children\' => 
                    array (
                      0 => \'main-row\',
                      1 => 1,
                      2 => 2,
                    ),
                    \'parent\' => \'canvas\',
                  ),
                  \'main-row\' => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'region\',
                    \'children\' => 
                    array (
                      0 => \'center\',
                    ),
                    \'parent\' => \'main\',
                  ),
                  \'center\' => 
                  array (
                    \'type\' => \'region\',
                    \'title\' => \'Center\',
                    \'width\' => 100,
                    \'width_type\' => \'%\',
                    \'parent\' => \'main-row\',
                  ),
                  1 => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'region\',
                    \'children\' => 
                    array (
                      0 => \'add_list\',
                    ),
                    \'parent\' => \'main\',
                    \'class\' => \'\',
                    \'hide_empty\' => 0,
                  ),
                  \'add_list\' => 
                  array (
                    \'type\' => \'region\',
                    \'title\' => \'Add List\',
                    \'width\' => 100,
                    \'width_type\' => \'%\',
                    \'parent\' => \'1\',
                    \'class\' => \'\',
                    \'hide_empty\' => 0,
                  ),
                  2 => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'region\',
                    \'children\' => 
                    array (
                      0 => \'lists\',
                    ),
                    \'parent\' => \'main\',
                    \'class\' => \'\',
                    \'hide_empty\' => 0,
                  ),
                  \'lists\' => 
                  array (
                    \'type\' => \'region\',
                    \'title\' => \'Lists\',
                    \'width\' => 100,
                    \'width_type\' => \'%\',
                    \'parent\' => \'2\',
                    \'class\' => \'\',
                    \'hide_empty\' => 0,
                  ),
                ),
              ),
               \'panel_settings\' => 
              array (
                \'style_settings\' => 
                array (
                  \'default\' => NULL,
                  \'center\' => NULL,
                  \'lists\' => 
                  array (
                    \'style\' => \'$\',
                    \'settings\' => 
                    array (
                      \'name\' => \'_temporary\',
                      \'style_base\' => \'region_plain_box\',
                      \'palette\' => 
                      array (
                        \'background\' => \'#FFFFFF\',
                        \'text\' => \'#000000\',
                        \'border\' => \'#1c4cc7\',
                      ),
                      \'font\' => 
                      array (
                        \'font\' => \'\',
                        \'size\' => \'\',
                        \'letter_spacing\' => \'\',
                        \'word_spacing\' => \'\',
                        \'decoration\' => \'\',
                        \'weight\' => \'\',
                        \'style\' => \'\',
                        \'variant\' => \'\',
                        \'case\' => \'\',
                        \'alignment\' => \'\',
                      ),
                      \'border\' => 
                      array (
                        \'thickness\' => \'1px\',
                        \'style\' => \'solid\',
                      ),
                      \'padding\' => 
                      array (
                        \'top\' => \'\',
                        \'right\' => \'\',
                        \'bottom\' => \'\',
                        \'left\' => \'\',
                      ),
                    ),
                  ),
                  \'add_list\' => NULL,
                ),
                \'add_list\' => 
                array (
                  \'style\' => \'0\',
                ),
                \'lists\' => 
                array (
                  \'style\' => \'stylizer\',
                ),
              ),
               \'cache\' => 
              array (
              ),
               \'title\' => \'\',
               \'hide_title\' => \'0\',
               \'title_pane\' => \'56\',
               \'uuid\' => \'3be5709d-71fa-4ed4-9aa2-7d822c1be78d\',
               \'storage_type\' => \'panelizer_default\',
               \'storage_id\' => \'node:pick_list:default:default\',
            )),
            \'export_module\' => NULL,
            \'entity_id\' => 0,
            \'revision_id\' => 0,
          ),
      ),
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'Pick Lists\',
      \'title_field\' => array(
        \'en\' => array(
          array(
            \'value\' => \'Pick Lists\',
            \'format\' => NULL,
            \'safe_value\' => \'Pick Lists\',
          ),
        ),
      ),
      \'title_original\' => \'Pick Lists\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'translations\' => (object) array(
          \'original\' => NULL,
          \'data\' => array(),
        ),
      \'type\' => \'pick_list\',
      \'uid\' => \'1\',
      \'uuid\' => \'3c6fac1d-cc28-4747-8676-c1580e720a82\',
      \'vid\' => NULL,
      \'vuuid\' => \'3f42c56c-f997-4ff2-8c67-bd105ba01a0f\',
    ),
  (object) array(
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'2\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => \'a:4:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;s:12:"admin_select";s:6:"navbar";s:15:"navbar_language";i:0;}\',
      \'entity_translation_handler_id\' => \'node-opinion-eid-15\',
      \'field_attachments\' => array(),
      \'field_background\' => array(),
      \'field_bf_date\' => array(),
      \'field_date_sent_to_dlsu\' => array(),
      \'field_department_approach_taken\' => array(),
      \'field_dlsu_contact\' => array(),
      \'field_format\' => array(),
      \'field_issue\' => array(),
      \'field_legal_opinion\' => array(),
      \'field_legal_opinion_request\' => array(),
      \'field_main_date\' => array(),
      \'field_nnhpd_bureau_project\' => array(),
      \'field_parent_space\' => array(),
      \'field_priority\' => array(),
      \'field_receive_date\' => array(),
      \'field_related_legal_opinion\' => array(),
      \'field_relevant_chronology\' => array(),
      \'field_relevant_legislations\' => array(),
      \'field_requester\' => array(),
      \'field_requesting_unit\' => array(),
      \'field_serial\' => array(),
      \'field_status\' => array(),
      \'field_subject_line\' => array(),
      \'field_summary_of_legal_opinion\' => array(),
      \'field_unique_tag\' => array(),
      \'files\' => array(),
      \'group_content_access\' => array(),
      \'language\' => \'en\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'admin\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'panelizer\' => array(
        \'default\' => (object) array(
            \'pnid\' => \'5\',
            \'title\' => \'Default\',
            \'panelizer_type\' => \'node\',
            \'panelizer_key\' => \'opinion\',
            \'access\' => array(),
            \'view_mode\' => \'default\',
            \'did\' => NULL,
            \'name\' => \'node:opinion:default:default\',
            \'css_id\' => \'\',
            \'css_class\' => \'\',
            \'css\' => \'\',
            \'no_blocks\' => \'0\',
            \'title_element\' => \'H2\',
            \'link_to_entity\' => \'1\',
            \'extra\' => array(),
            \'pipeline\' => \'standard\',
            \'contexts\' => array(),
            \'relationships\' => array(),
            \'table\' => \'panelizer_defaults\',
            \'type\' => \'Overridden\',
            \'export_type\' => 3,
            \'display\' => panels_display::__set_state(array(
               \'args\' => 
              array (
              ),
               \'content\' => 
              array (
                74 => 
                stdClass::__set_state(array(
                   \'pid\' => \'74\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:title_field\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'hidden\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'0\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'09ec8429-a31c-48ba-bc95-0da867374c2a\',
                )),
                85 => 
                stdClass::__set_state(array(
                   \'pid\' => \'85\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_subject_line\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'1\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'2cc96bf5-49f4-41f3-8f31-19a34be2a8f1\',
                )),
                80 => 
                stdClass::__set_state(array(
                   \'pid\' => \'80\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_serial\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'hidden\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'2\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'d98400c4-4631-4f5c-b0be-6647a83e43b0\',
                )),
                82 => 
                stdClass::__set_state(array(
                   \'pid\' => \'82\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_background\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'3\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'91e096c1-35c9-4fb6-bc7e-17d8b759edbb\',
                )),
                83 => 
                stdClass::__set_state(array(
                   \'pid\' => \'83\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_relevant_chronology\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'4\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'1e5130e6-c051-4199-b88a-ba47d6d3512f\',
                )),
                84 => 
                stdClass::__set_state(array(
                   \'pid\' => \'84\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_issue\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'5\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'88dcc06d-3eb4-425f-a47b-368302542f0a\',
                )),
                86 => 
                stdClass::__set_state(array(
                   \'pid\' => \'86\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_legal_opinion_request\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'6\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'f4c1b3bd-7352-4332-b6dc-fed3cdfa0ccd\',
                )),
                87 => 
                stdClass::__set_state(array(
                   \'pid\' => \'87\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_summary_of_legal_opinion\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'7\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'f3fa34d2-59c0-4c52-8415-11f5656a6f2e\',
                )),
                88 => 
                stdClass::__set_state(array(
                   \'pid\' => \'88\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_legal_opinion\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'8\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'58826700-c4d4-4459-89a4-bced33bd77cf\',
                )),
                89 => 
                stdClass::__set_state(array(
                   \'pid\' => \'89\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_department_approach_taken\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'9\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'210a19c1-4a19-4d02-95cf-32009dfe41dd\',
                )),
                96 => 
                stdClass::__set_state(array(
                   \'pid\' => \'96\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_attachments\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'file_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'10\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'82cee31c-4e18-484b-8783-cc8847eedcb1\',
                )),
                100 => 
                stdClass::__set_state(array(
                   \'pid\' => \'100\',
                   \'did\' => \'9\',
                   \'panel\' => \'center\',
                   \'type\' => \'node_links\',
                   \'subtype\' => \'node_links\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'override_title\' => false,
                    \'override_title_text\' => \'\',
                    \'build_mode\' => \'default\',
                    \'identifier\' => \'\',
                    \'link\' => true,
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                    \'css_class\' => \'link-wrapper\',
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'11\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'84eebc7c-8fc1-451d-be7c-94cd09f8293d\',
                )),
                99 => 
                stdClass::__set_state(array(
                   \'pid\' => \'99\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_parent_space\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'0\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'62659471-cb4f-48ee-932d-db0c89b33028\',
                )),
                81 => 
                stdClass::__set_state(array(
                   \'pid\' => \'81\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_unique_tag\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'computed_field_plain\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'1\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'10326405-a353-4c34-a2f2-8b45262794a6\',
                )),
                97 => 
                stdClass::__set_state(array(
                   \'pid\' => \'97\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_related_legal_opinion\',
                   \'shown\' => \'0\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => 1,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'2\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'e8e4bcee-a0f9-46b3-8d90-9b6256ef3b06\',
                )),
                75 => 
                stdClass::__set_state(array(
                   \'pid\' => \'75\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_priority\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'3\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'cc33106a-b8c6-45e6-9f0f-b43d9d7fe6a6\',
                )),
                76 => 
                stdClass::__set_state(array(
                   \'pid\' => \'76\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_status\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'4\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'b3807e67-c1ea-47ca-8fe4-66487ec9fa9f\',
                )),
                77 => 
                stdClass::__set_state(array(
                   \'pid\' => \'77\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_requester\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => 1,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'5\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'eff7f0c7-3283-4962-bbfa-041fea08edd0\',
                )),
                98 => 
                stdClass::__set_state(array(
                   \'pid\' => \'98\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_requesting_unit\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'6\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'2439d9aa-7250-4e44-83ae-8239dbdf10a2\',
                )),
                78 => 
                stdClass::__set_state(array(
                   \'pid\' => \'78\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_dlsu_contact\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => 1,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'7\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'6a92c262-c514-436a-a4a7-ea758568f3c8\',
                )),
                79 => 
                stdClass::__set_state(array(
                   \'pid\' => \'79\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_nnhpd_bureau_project\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => 1,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'8\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'5dde2e9a-5dbf-4079-837e-5d001ade89c1\',
                )),
                90 => 
                stdClass::__set_state(array(
                   \'pid\' => \'90\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_relevant_legislations\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'9\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'7bb1fecd-b961-42d8-b87b-0caf9450355f\',
                )),
                91 => 
                stdClass::__set_state(array(
                   \'pid\' => \'91\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_main_date\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'date_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'format_type\' => \'short\',
                      \'fromto\' => \'both\',
                      \'multiple_number\' => \'\',
                      \'multiple_from\' => \'\',
                      \'multiple_to\' => \'\',
                      \'show_remaining_days\' => 0,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'10\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'d1a2c431-72ae-49b8-9cba-3cf8b0dc79f3\',
                )),
                92 => 
                stdClass::__set_state(array(
                   \'pid\' => \'92\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_bf_date\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'date_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'format_type\' => \'short\',
                      \'fromto\' => \'both\',
                      \'multiple_number\' => \'\',
                      \'multiple_from\' => \'\',
                      \'multiple_to\' => \'\',
                      \'show_remaining_days\' => 0,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'11\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'7be6343f-2176-4c43-abab-f35d02a72e03\',
                )),
                93 => 
                stdClass::__set_state(array(
                   \'pid\' => \'93\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_receive_date\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'date_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'format_type\' => \'short\',
                      \'fromto\' => \'both\',
                      \'multiple_number\' => \'\',
                      \'multiple_from\' => \'\',
                      \'multiple_to\' => \'\',
                      \'show_remaining_days\' => 0,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'12\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'8c1402ef-1ca9-4fde-be39-15ce2e98bccd\',
                )),
                94 => 
                stdClass::__set_state(array(
                   \'pid\' => \'94\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_date_sent_to_dlsu\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'date_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'format_type\' => \'short\',
                      \'fromto\' => \'both\',
                      \'multiple_number\' => \'\',
                      \'multiple_from\' => \'\',
                      \'multiple_to\' => \'\',
                      \'show_remaining_days\' => 0,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'13\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'ab31a96a-8eff-4be0-9049-f95e6ad4990b\',
                )),
                95 => 
                stdClass::__set_state(array(
                   \'pid\' => \'95\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:field_format\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'entityreference_label\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'link\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'14\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'33e5939f-e5e2-4e14-bdf2-e41c6c9f8146\',
                )),
                106 => 
                stdClass::__set_state(array(
                   \'pid\' => \'106\',
                   \'did\' => \'9\',
                   \'panel\' => \'right_sidebar\',
                   \'type\' => \'views_panes\',
                   \'subtype\' => \'legal_opinion-panel_pane_related_opinion\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'view_settings\' => \'fields\',
                    \'header_type\' => \'none\',
                    \'view_mode\' => \'teaser\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'15\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'560d7904-91fd-45e2-ab92-44b97d86c15e\',
                )),
              ),
               \'panels\' => 
              array (
                \'center\' => 
                array (
                  0 => \'74\',
                  1 => \'85\',
                  2 => \'80\',
                  3 => \'82\',
                  4 => \'83\',
                  5 => \'84\',
                  6 => \'86\',
                  7 => \'87\',
                  8 => \'88\',
                  9 => \'89\',
                  10 => \'96\',
                  11 => \'100\',
                ),
                \'right_sidebar\' => 
                array (
                  0 => \'99\',
                  1 => \'81\',
                  2 => \'97\',
                  3 => \'75\',
                  4 => \'76\',
                  5 => \'77\',
                  6 => \'98\',
                  7 => \'78\',
                  8 => \'79\',
                  9 => \'90\',
                  10 => \'91\',
                  11 => \'92\',
                  12 => \'93\',
                  13 => \'94\',
                  14 => \'95\',
                  15 => \'106\',
                ),
              ),
               \'incoming_content\' => NULL,
               \'css_id\' => NULL,
               \'context\' => 
              array (
              ),
               \'did\' => \'9\',
               \'renderer\' => \'standard\',
               \'layout\' => \'flexible\',
               \'layout_settings\' => 
              array (
                \'items\' => 
                array (
                  \'canvas\' => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'column\',
                    \'children\' => 
                    array (
                      0 => \'main\',
                      1 => 1,
                    ),
                    \'parent\' => NULL,
                  ),
                  \'main\' => 
                  array (
                    \'type\' => \'column\',
                    \'width\' => \'76.51967705731147\',
                    \'width_type\' => \'%\',
                    \'children\' => 
                    array (
                      0 => \'main-row\',
                    ),
                    \'parent\' => \'canvas\',
                  ),
                  \'main-row\' => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'region\',
                    \'children\' => 
                    array (
                      0 => \'center\',
                    ),
                    \'parent\' => \'main\',
                  ),
                  \'center\' => 
                  array (
                    \'type\' => \'region\',
                    \'title\' => \'Center\',
                    \'width\' => 100,
                    \'width_type\' => \'%\',
                    \'parent\' => \'main-row\',
                  ),
                  1 => 
                  array (
                    \'type\' => \'column\',
                    \'width\' => \'23.480322942688527\',
                    \'width_type\' => \'%\',
                    \'parent\' => \'canvas\',
                    \'children\' => 
                    array (
                      0 => 2,
                    ),
                    \'class\' => \'\',
                    \'hide_empty\' => 1,
                  ),
                  2 => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'region\',
                    \'children\' => 
                    array (
                      0 => \'right_sidebar\',
                    ),
                    \'parent\' => \'1\',
                    \'class\' => \'\',
                    \'hide_empty\' => 1,
                  ),
                  \'right_sidebar\' => 
                  array (
                    \'type\' => \'region\',
                    \'title\' => \'Right Sidebar\',
                    \'width\' => 100,
                    \'width_type\' => \'%\',
                    \'parent\' => \'2\',
                    \'class\' => \'\',
                    \'hide_empty\' => 1,
                  ),
                ),
              ),
               \'panel_settings\' => 
              array (
                \'style_settings\' => 
                array (
                  \'default\' => NULL,
                  \'center\' => NULL,
                  \'right_sidebar\' => 
                  array (
                    \'style\' => \'$\',
                    \'settings\' => 
                    array (
                      \'name\' => \'_temporary\',
                      \'style_base\' => \'region_plain_box\',
                      \'palette\' => 
                      array (
                        \'background\' => \'#e1e1e1\',
                        \'text\' => \'#000000\',
                        \'border\' => \'#5295ef\',
                      ),
                      \'font\' => 
                      array (
                        \'font\' => \'\',
                        \'size\' => \'\',
                        \'letter_spacing\' => \'\',
                        \'word_spacing\' => \'\',
                        \'decoration\' => \'\',
                        \'weight\' => \'\',
                        \'style\' => \'\',
                        \'variant\' => \'\',
                        \'case\' => \'\',
                        \'alignment\' => \'\',
                      ),
                      \'border\' => 
                      array (
                        \'thickness\' => \'1px\',
                        \'style\' => \'solid\',
                      ),
                      \'padding\' => 
                      array (
                        \'top\' => \'\',
                        \'right\' => \'0.05em\',
                        \'bottom\' => \'\',
                        \'left\' => \'0.5em\',
                      ),
                    ),
                  ),
                ),
                \'right_sidebar\' => 
                array (
                  \'style\' => \'stylizer\',
                ),
              ),
               \'cache\' => 
              array (
              ),
               \'title\' => \'%node:title\',
               \'hide_title\' => \'0\',
               \'title_pane\' => \'74\',
               \'uuid\' => \'d5859a33-8e95-47d2-b73d-d6cf60eeb01b\',
               \'storage_type\' => \'panelizer_default\',
               \'storage_id\' => \'node:opinion:default:default\',
            )),
            \'export_module\' => NULL,
            \'entity_id\' => 0,
            \'revision_id\' => 0,
          ),
      ),
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'opinion3\',
      \'title_field\' => array(
        \'en\' => array(
          array(
            \'value\' => \'opinion3\',
            \'format\' => NULL,
            \'safe_value\' => \'opinion3\',
          ),
        ),
      ),
      \'title_original\' => \'opinion3\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'translations\' => (object) array(
          \'original\' => NULL,
          \'data\' => array(),
        ),
      \'type\' => \'opinion\',
      \'uid\' => \'1\',
      \'uuid\' => \'5acc233f-3f03-4e76-baec-61b9e19d503f\',
      \'vid\' => NULL,
      \'vuuid\' => \'f865433b-1e28-4804-ba55-bb4251919c86\',
    ),
  (object) array(
      \'body\' => array(),
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'2\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => \'a:4:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;s:12:"admin_select";s:6:"navbar";s:15:"navbar_language";i:0;}\',
      \'entity_translation_handler_id\' => \'node-space-eid-22\',
      \'field_root_space\' => array(),
      \'files\' => array(),
      \'group_access\' => array(
        \'und\' => array(
          array(
            \'value\' => \'0\',
          ),
        ),
      ),
      \'group_group\' => array(
        \'und\' => array(
          array(
            \'value\' => \'1\',
          ),
        ),
      ),
      \'language\' => \'en\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'15\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'admin\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'og_group_ref\' => array(),
      \'og_user_inheritance\' => array(
        \'und\' => array(
          array(
            \'value\' => \'1\',
          ),
        ),
      ),
      \'og_user_permission_inheritance\' => array(
        \'und\' => array(
          array(
            \'value\' => \'0\',
          ),
        ),
      ),
      \'panelizer\' => array(
        \'default\' => (object) array(
            \'pnid\' => \'1\',
            \'title\' => \'Default\',
            \'panelizer_type\' => \'node\',
            \'panelizer_key\' => \'space\',
            \'access\' => array(),
            \'view_mode\' => \'default\',
            \'did\' => NULL,
            \'name\' => \'node:space:default:default\',
            \'css_id\' => \'\',
            \'css_class\' => \'\',
            \'css\' => \'\',
            \'no_blocks\' => \'0\',
            \'title_element\' => \'H2\',
            \'link_to_entity\' => \'1\',
            \'extra\' => array(),
            \'pipeline\' => \'standard\',
            \'contexts\' => array(),
            \'relationships\' => array(),
            \'table\' => \'panelizer_defaults\',
            \'type\' => \'Overridden\',
            \'export_type\' => 3,
            \'display\' => panels_display::__set_state(array(
               \'args\' => 
              array (
              ),
               \'content\' => 
              array (
                73 => 
                stdClass::__set_state(array(
                   \'pid\' => \'73\',
                   \'did\' => \'2\',
                   \'panel\' => \'bottum\',
                   \'type\' => \'block\',
                   \'subtype\' => \'bean-create-opinion-0\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'override_title\' => 0,
                    \'override_title_text\' => \'\',
                    \'override_title_heading\' => \'h2\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'0\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'16bd7c73-3597-4967-8735-b014925fbd1c\',
                )),
                55 => 
                stdClass::__set_state(array(
                   \'pid\' => \'55\',
                   \'did\' => \'2\',
                   \'panel\' => \'bottum\',
                   \'type\' => \'views_panes\',
                   \'subtype\' => \'space-panel_pane_opinion_list\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'view_settings\' => \'fields\',
                    \'header_type\' => \'none\',
                    \'view_mode\' => \'teaser\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'1\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'1cde5124-e9c7-4def-ac52-b5d322f061b4\',
                )),
                102 => 
                stdClass::__set_state(array(
                   \'pid\' => \'102\',
                   \'did\' => \'2\',
                   \'panel\' => \'bottum\',
                   \'type\' => \'views_panes\',
                   \'subtype\' => \'legal_opinion-panel_pane_opinion_list\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'view_settings\' => \'fields\',
                    \'header_type\' => \'none\',
                    \'view_mode\' => \'teaser\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'2\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'105f40bf-dcb8-44cc-b099-2af718ecf564\',
                )),
                2 => 
                stdClass::__set_state(array(
                   \'pid\' => \'2\',
                   \'did\' => \'2\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:body\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'hidden\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'0\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'31e7853a-4343-43ca-9c12-d79e73be2737\',
                )),
                3 => 
                stdClass::__set_state(array(
                   \'pid\' => \'3\',
                   \'did\' => \'2\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:group_group\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'og_group_subscribe\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'field_name\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'1\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'0fdac150-e3fe-4f20-a555-d4f1f2da8ddc\',
                )),
                5 => 
                stdClass::__set_state(array(
                   \'pid\' => \'5\',
                   \'did\' => \'2\',
                   \'panel\' => \'center\',
                   \'type\' => \'node_links\',
                   \'subtype\' => \'node_links\',
                   \'shown\' => \'0\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'override_title\' => false,
                    \'override_title_text\' => \'\',
                    \'build_mode\' => \'default\',
                    \'identifier\' => \'\',
                    \'link\' => true,
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                    \'css_class\' => \'link-wrapper\',
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'2\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'fafa8510-e693-42f7-b669-f1654f7a0960\',
                )),
              ),
               \'panels\' => 
              array (
                \'bottum\' => 
                array (
                  0 => \'73\',
                  1 => \'55\',
                  2 => \'102\',
                ),
                \'center\' => 
                array (
                  0 => \'2\',
                  1 => \'3\',
                  2 => \'5\',
                ),
              ),
               \'incoming_content\' => NULL,
               \'css_id\' => NULL,
               \'context\' => 
              array (
              ),
               \'did\' => \'2\',
               \'renderer\' => \'standard\',
               \'layout\' => \'flexible\',
               \'layout_settings\' => 
              array (
                \'items\' => 
                array (
                  \'canvas\' => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'column\',
                    \'children\' => 
                    array (
                      0 => \'main\',
                    ),
                    \'parent\' => NULL,
                    \'class\' => \'\',
                    \'column_class\' => \'\',
                    \'row_class\' => \'\',
                    \'region_class\' => \'\',
                    \'no_scale\' => false,
                    \'fixed_width\' => \'\',
                    \'column_separation\' => \'0.5em\',
                    \'region_separation\' => \'0.5em\',
                    \'row_separation\' => \'0.5em\',
                    \'hide_empty\' => 1,
                  ),
                  \'main\' => 
                  array (
                    \'type\' => \'column\',
                    \'width\' => 100.0,
                    \'width_type\' => \'%\',
                    \'children\' => 
                    array (
                      0 => \'main-row\',
                      1 => 5,
                    ),
                    \'parent\' => \'canvas\',
                  ),
                  \'main-row\' => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'region\',
                    \'children\' => 
                    array (
                      0 => \'center\',
                    ),
                    \'parent\' => \'main\',
                  ),
                  \'center\' => 
                  array (
                    \'type\' => \'region\',
                    \'title\' => \'Center\',
                    \'width\' => 100,
                    \'width_type\' => \'%\',
                    \'parent\' => \'main-row\',
                  ),
                  5 => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'region\',
                    \'children\' => 
                    array (
                      0 => \'bottum\',
                    ),
                    \'parent\' => \'main\',
                    \'class\' => \'\',
                    \'hide_empty\' => 1,
                  ),
                  \'bottum\' => 
                  array (
                    \'type\' => \'region\',
                    \'title\' => \'Bottom\',
                    \'width\' => 100,
                    \'width_type\' => \'%\',
                    \'parent\' => \'5\',
                    \'class\' => \'\',
                    \'hide_empty\' => 1,
                  ),
                ),
              ),
               \'panel_settings\' => 
              array (
                \'style_settings\' => 
                array (
                  \'default\' => NULL,
                  \'center\' => 
                  array (
                    \'modifier_class\' => \'\',
                    \'hide_classes\' => 
                    array (
                    ),
                    \'additional_classes\' => 
                    array (
                    ),
                    \'collapsible\' => false,
                    \'collapsed\' => \'\',
                    \'region_title\' => \'\',
                  ),
                  \'sidebar_left\' => NULL,
                  \'sidebar_right\' => 
                  array (
                    \'style\' => \'$\',
                    \'settings\' => 
                    array (
                      \'name\' => \'_temporary\',
                      \'style_base\' => \'region_plain_box\',
                      \'palette\' => 
                      array (
                        \'background\' => \'#ffffff\',
                        \'text\' => \'#000000\',
                        \'border\' => \'#90c6f2\',
                      ),
                      \'font\' => 
                      array (
                        \'font\' => \'\',
                        \'size\' => \'\',
                        \'letter_spacing\' => \'\',
                        \'word_spacing\' => \'\',
                        \'decoration\' => \'\',
                        \'weight\' => \'\',
                        \'style\' => \'\',
                        \'variant\' => \'\',
                        \'case\' => \'\',
                        \'alignment\' => \'\',
                      ),
                      \'border\' => 
                      array (
                        \'thickness\' => \'1px\',
                        \'style\' => \'solid\',
                      ),
                      \'padding\' => 
                      array (
                        \'top\' => \'2.0em\',
                        \'right\' => \'2.0em\',
                        \'bottom\' => \'\',
                        \'left\' => \'2.0em\',
                      ),
                    ),
                  ),
                  \'bottum\' => 
                  array (
                    \'style\' => \'$\',
                    \'settings\' => 
                    array (
                      \'name\' => \'_temporary\',
                      \'style_base\' => \'region_plain_box\',
                      \'palette\' => 
                      array (
                        \'background\' => \'#ffffff\',
                        \'text\' => \'#000000\',
                        \'border\' => \'#3a96a1\',
                      ),
                      \'font\' => 
                      array (
                        \'font\' => \'\',
                        \'size\' => \'\',
                        \'letter_spacing\' => \'\',
                        \'word_spacing\' => \'\',
                        \'decoration\' => \'\',
                        \'weight\' => \'\',
                        \'style\' => \'\',
                        \'variant\' => \'\',
                        \'case\' => \'\',
                        \'alignment\' => \'\',
                      ),
                      \'border\' => 
                      array (
                        \'thickness\' => \'1px\',
                        \'style\' => \'solid\',
                      ),
                      \'padding\' => 
                      array (
                        \'top\' => \'3.0em\',
                        \'right\' => \'2.0em\',
                        \'bottom\' => \'2.0em\',
                        \'left\' => \'3.0em\',
                      ),
                    ),
                  ),
                ),
                \'center\' => 
                array (
                  \'style\' => \'bootstrap_styles:panel\',
                ),
                \'sidebar_right\' => 
                array (
                  \'style\' => \'stylizer\',
                ),
                \'bottum\' => 
                array (
                  \'style\' => \'stylizer\',
                ),
              ),
               \'cache\' => 
              array (
              ),
               \'title\' => \'\',
               \'hide_title\' => \'0\',
               \'title_pane\' => \'2\',
               \'uuid\' => \'ecc372bd-8999-4a0c-87fa-9d5972284800\',
               \'storage_type\' => \'panelizer_default\',
               \'storage_id\' => \'node:space:default:default\',
            )),
            \'export_module\' => NULL,
            \'entity_id\' => 0,
            \'revision_id\' => 0,
          ),
      ),
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'NNHPD_BLSS\',
      \'title_field\' => array(
        \'en\' => array(
          array(
            \'value\' => \'NNHPD_BLSS\',
            \'format\' => NULL,
            \'safe_value\' => \'NNHPD_BLSS\',
          ),
        ),
        \'fr\' => array(
          array(
            \'value\' => \'NNHPD_BLSS_F\',
            \'format\' => NULL,
            \'safe_value\' => \'NNHPD_BLSS_F\',
          ),
        ),
      ),
      \'title_original\' => \'NNHPD_BLSS\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'translations\' => (object) array(
          \'original\' => \'en\',
          \'data\' => array(
            \'en\' => array(
              \'entity_type\' => \'node\',
              \'entity_id\' => \'22\',
              \'revision_id\' => \'25\',
              \'language\' => \'en\',
              \'source\' => \'\',
              \'uid\' => \'15\',
              \'status\' => \'1\',
              \'translate\' => \'0\',
              \'created\' => \'1489672920\',
              \'changed\' => \'1490022322\',
            ),
            \'fr\' => array(
              \'entity_type\' => \'node\',
              \'entity_id\' => \'22\',
              \'revision_id\' => \'25\',
              \'language\' => \'fr\',
              \'source\' => \'en\',
              \'uid\' => \'15\',
              \'status\' => \'1\',
              \'translate\' => \'0\',
              \'created\' => \'1489672961\',
              \'changed\' => \'1490022385\',
            ),
          ),
        ),
      \'type\' => \'space\',
      \'uid\' => \'1\',
      \'uuid\' => \'816d7440-c103-44ab-92fe-e90d9c71661b\',
      \'vid\' => NULL,
      \'vuuid\' => \'458bb469-912c-4959-9afd-89bf5bbd4a5c\',
    ),
  (object) array(
      \'body\' => array(),
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'2\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => \'a:4:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;s:12:"admin_select";s:6:"navbar";s:15:"navbar_language";i:0;}\',
      \'entity_translation_handler_id\' => \'node-space-eid-16\',
      \'field_root_space\' => array(),
      \'files\' => array(),
      \'group_access\' => array(
        \'und\' => array(
          array(
            \'value\' => \'1\',
          ),
        ),
      ),
      \'group_group\' => array(
        \'und\' => array(
          array(
            \'value\' => \'1\',
          ),
        ),
      ),
      \'language\' => \'en\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'15\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'admin\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'og_group_ref\' => array(),
      \'og_user_inheritance\' => array(
        \'und\' => array(
          array(
            \'value\' => \'1\',
          ),
        ),
      ),
      \'og_user_permission_inheritance\' => array(
        \'und\' => array(
          array(
            \'value\' => \'1\',
          ),
        ),
      ),
      \'panelizer\' => array(
        \'default\' => (object) array(
            \'pnid\' => \'1\',
            \'title\' => \'Default\',
            \'panelizer_type\' => \'node\',
            \'panelizer_key\' => \'space\',
            \'access\' => array(),
            \'view_mode\' => \'default\',
            \'did\' => NULL,
            \'name\' => \'node:space:default:default\',
            \'css_id\' => \'\',
            \'css_class\' => \'\',
            \'css\' => \'\',
            \'no_blocks\' => \'0\',
            \'title_element\' => \'H2\',
            \'link_to_entity\' => \'1\',
            \'extra\' => array(),
            \'pipeline\' => \'standard\',
            \'contexts\' => array(),
            \'relationships\' => array(),
            \'table\' => \'panelizer_defaults\',
            \'type\' => \'Overridden\',
            \'export_type\' => 3,
            \'display\' => panels_display::__set_state(array(
               \'args\' => 
              array (
              ),
               \'content\' => 
              array (
                73 => 
                stdClass::__set_state(array(
                   \'pid\' => \'73\',
                   \'did\' => \'2\',
                   \'panel\' => \'bottum\',
                   \'type\' => \'block\',
                   \'subtype\' => \'bean-create-opinion-0\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'override_title\' => 0,
                    \'override_title_text\' => \'\',
                    \'override_title_heading\' => \'h2\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'0\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'16bd7c73-3597-4967-8735-b014925fbd1c\',
                )),
                55 => 
                stdClass::__set_state(array(
                   \'pid\' => \'55\',
                   \'did\' => \'2\',
                   \'panel\' => \'bottum\',
                   \'type\' => \'views_panes\',
                   \'subtype\' => \'space-panel_pane_opinion_list\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'view_settings\' => \'fields\',
                    \'header_type\' => \'none\',
                    \'view_mode\' => \'teaser\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'1\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'1cde5124-e9c7-4def-ac52-b5d322f061b4\',
                )),
                102 => 
                stdClass::__set_state(array(
                   \'pid\' => \'102\',
                   \'did\' => \'2\',
                   \'panel\' => \'bottum\',
                   \'type\' => \'views_panes\',
                   \'subtype\' => \'legal_opinion-panel_pane_opinion_list\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'view_settings\' => \'fields\',
                    \'header_type\' => \'none\',
                    \'view_mode\' => \'teaser\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'2\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'105f40bf-dcb8-44cc-b099-2af718ecf564\',
                )),
                2 => 
                stdClass::__set_state(array(
                   \'pid\' => \'2\',
                   \'did\' => \'2\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:body\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'hidden\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'0\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'31e7853a-4343-43ca-9c12-d79e73be2737\',
                )),
                3 => 
                stdClass::__set_state(array(
                   \'pid\' => \'3\',
                   \'did\' => \'2\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:group_group\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'og_group_subscribe\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'field_name\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'1\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'0fdac150-e3fe-4f20-a555-d4f1f2da8ddc\',
                )),
                5 => 
                stdClass::__set_state(array(
                   \'pid\' => \'5\',
                   \'did\' => \'2\',
                   \'panel\' => \'center\',
                   \'type\' => \'node_links\',
                   \'subtype\' => \'node_links\',
                   \'shown\' => \'0\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'override_title\' => false,
                    \'override_title_text\' => \'\',
                    \'build_mode\' => \'default\',
                    \'identifier\' => \'\',
                    \'link\' => true,
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                    \'css_class\' => \'link-wrapper\',
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'2\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'fafa8510-e693-42f7-b669-f1654f7a0960\',
                )),
              ),
               \'panels\' => 
              array (
                \'bottum\' => 
                array (
                  0 => \'73\',
                  1 => \'55\',
                  2 => \'102\',
                ),
                \'center\' => 
                array (
                  0 => \'2\',
                  1 => \'3\',
                  2 => \'5\',
                ),
              ),
               \'incoming_content\' => NULL,
               \'css_id\' => NULL,
               \'context\' => 
              array (
              ),
               \'did\' => \'2\',
               \'renderer\' => \'standard\',
               \'layout\' => \'flexible\',
               \'layout_settings\' => 
              array (
                \'items\' => 
                array (
                  \'canvas\' => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'column\',
                    \'children\' => 
                    array (
                      0 => \'main\',
                    ),
                    \'parent\' => NULL,
                    \'class\' => \'\',
                    \'column_class\' => \'\',
                    \'row_class\' => \'\',
                    \'region_class\' => \'\',
                    \'no_scale\' => false,
                    \'fixed_width\' => \'\',
                    \'column_separation\' => \'0.5em\',
                    \'region_separation\' => \'0.5em\',
                    \'row_separation\' => \'0.5em\',
                    \'hide_empty\' => 1,
                  ),
                  \'main\' => 
                  array (
                    \'type\' => \'column\',
                    \'width\' => 100.0,
                    \'width_type\' => \'%\',
                    \'children\' => 
                    array (
                      0 => \'main-row\',
                      1 => 5,
                    ),
                    \'parent\' => \'canvas\',
                  ),
                  \'main-row\' => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'region\',
                    \'children\' => 
                    array (
                      0 => \'center\',
                    ),
                    \'parent\' => \'main\',
                  ),
                  \'center\' => 
                  array (
                    \'type\' => \'region\',
                    \'title\' => \'Center\',
                    \'width\' => 100,
                    \'width_type\' => \'%\',
                    \'parent\' => \'main-row\',
                  ),
                  5 => 
                  array (
                    \'type\' => \'row\',
                    \'contains\' => \'region\',
                    \'children\' => 
                    array (
                      0 => \'bottum\',
                    ),
                    \'parent\' => \'main\',
                    \'class\' => \'\',
                    \'hide_empty\' => 1,
                  ),
                  \'bottum\' => 
                  array (
                    \'type\' => \'region\',
                    \'title\' => \'Bottom\',
                    \'width\' => 100,
                    \'width_type\' => \'%\',
                    \'parent\' => \'5\',
                    \'class\' => \'\',
                    \'hide_empty\' => 1,
                  ),
                ),
              ),
               \'panel_settings\' => 
              array (
                \'style_settings\' => 
                array (
                  \'default\' => NULL,
                  \'center\' => 
                  array (
                    \'modifier_class\' => \'\',
                    \'hide_classes\' => 
                    array (
                    ),
                    \'additional_classes\' => 
                    array (
                    ),
                    \'collapsible\' => false,
                    \'collapsed\' => \'\',
                    \'region_title\' => \'\',
                  ),
                  \'sidebar_left\' => NULL,
                  \'sidebar_right\' => 
                  array (
                    \'style\' => \'$\',
                    \'settings\' => 
                    array (
                      \'name\' => \'_temporary\',
                      \'style_base\' => \'region_plain_box\',
                      \'palette\' => 
                      array (
                        \'background\' => \'#ffffff\',
                        \'text\' => \'#000000\',
                        \'border\' => \'#90c6f2\',
                      ),
                      \'font\' => 
                      array (
                        \'font\' => \'\',
                        \'size\' => \'\',
                        \'letter_spacing\' => \'\',
                        \'word_spacing\' => \'\',
                        \'decoration\' => \'\',
                        \'weight\' => \'\',
                        \'style\' => \'\',
                        \'variant\' => \'\',
                        \'case\' => \'\',
                        \'alignment\' => \'\',
                      ),
                      \'border\' => 
                      array (
                        \'thickness\' => \'1px\',
                        \'style\' => \'solid\',
                      ),
                      \'padding\' => 
                      array (
                        \'top\' => \'2.0em\',
                        \'right\' => \'2.0em\',
                        \'bottom\' => \'\',
                        \'left\' => \'2.0em\',
                      ),
                    ),
                  ),
                  \'bottum\' => 
                  array (
                    \'style\' => \'$\',
                    \'settings\' => 
                    array (
                      \'name\' => \'_temporary\',
                      \'style_base\' => \'region_plain_box\',
                      \'palette\' => 
                      array (
                        \'background\' => \'#ffffff\',
                        \'text\' => \'#000000\',
                        \'border\' => \'#3a96a1\',
                      ),
                      \'font\' => 
                      array (
                        \'font\' => \'\',
                        \'size\' => \'\',
                        \'letter_spacing\' => \'\',
                        \'word_spacing\' => \'\',
                        \'decoration\' => \'\',
                        \'weight\' => \'\',
                        \'style\' => \'\',
                        \'variant\' => \'\',
                        \'case\' => \'\',
                        \'alignment\' => \'\',
                      ),
                      \'border\' => 
                      array (
                        \'thickness\' => \'1px\',
                        \'style\' => \'solid\',
                      ),
                      \'padding\' => 
                      array (
                        \'top\' => \'3.0em\',
                        \'right\' => \'2.0em\',
                        \'bottom\' => \'2.0em\',
                        \'left\' => \'3.0em\',
                      ),
                    ),
                  ),
                ),
                \'center\' => 
                array (
                  \'style\' => \'bootstrap_styles:panel\',
                ),
                \'sidebar_right\' => 
                array (
                  \'style\' => \'stylizer\',
                ),
                \'bottum\' => 
                array (
                  \'style\' => \'stylizer\',
                ),
              ),
               \'cache\' => 
              array (
              ),
               \'title\' => \'\',
               \'hide_title\' => \'0\',
               \'title_pane\' => \'2\',
               \'uuid\' => \'ecc372bd-8999-4a0c-87fa-9d5972284800\',
               \'storage_type\' => \'panelizer_default\',
               \'storage_id\' => \'node:space:default:default\',
            )),
            \'export_module\' => NULL,
            \'entity_id\' => 0,
            \'revision_id\' => 0,
          ),
      ),
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'NNHPD_PAD\',
      \'title_field\' => array(
        \'en\' => array(
          array(
            \'value\' => \'NNHPD_PAD\',
            \'format\' => NULL,
            \'safe_value\' => \'NNHPD_PAD\',
          ),
        ),
        \'fr\' => array(
          array(
            \'value\' => \'NNHPD_PAD_F\',
            \'format\' => NULL,
            \'safe_value\' => \'NNHPD_PAD_F\',
          ),
        ),
      ),
      \'title_original\' => \'NNHPD_PAD\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'translations\' => (object) array(
          \'original\' => \'en\',
          \'data\' => array(
            \'en\' => array(
              \'entity_type\' => \'node\',
              \'entity_id\' => \'16\',
              \'revision_id\' => \'19\',
              \'language\' => \'en\',
              \'source\' => \'\',
              \'uid\' => \'15\',
              \'status\' => \'1\',
              \'translate\' => \'0\',
              \'created\' => \'1489600380\',
              \'changed\' => \'1490022343\',
            ),
            \'fr\' => array(
              \'entity_type\' => \'node\',
              \'entity_id\' => \'16\',
              \'revision_id\' => \'19\',
              \'language\' => \'fr\',
              \'source\' => \'en\',
              \'uid\' => \'15\',
              \'status\' => \'1\',
              \'translate\' => \'0\',
              \'created\' => \'1489601592\',
              \'changed\' => \'1490022413\',
            ),
          ),
        ),
      \'type\' => \'space\',
      \'uid\' => \'1\',
      \'uuid\' => \'81ea89d8-11ad-42dd-aa1b-f25d31ea262f\',
      \'vid\' => NULL,
      \'vuuid\' => \'f21ae05b-d04f-4ea7-bb4f-d216e8d59898\',
    ),
  (object) array(
      \'body\' => array(),
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'1\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => \'a:4:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;s:12:"admin_select";s:6:"navbar";s:15:"navbar_language";i:0;}\',
      \'entity_translation_handler_id\' => \'node-priority-eid-30\',
      \'field_pick_list_parent\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'28\',
          ),
        ),
      ),
      \'files\' => array(),
      \'language\' => \'en\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'admin\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'Hight\',
      \'title_field\' => array(
        \'en\' => array(
          array(
            \'value\' => \'Hight\',
            \'format\' => NULL,
            \'safe_value\' => \'Hight\',
          ),
        ),
        \'fr\' => array(
          array(
            \'value\' => \'Haute\',
            \'format\' => NULL,
            \'safe_value\' => \'Haute\',
          ),
        ),
      ),
      \'title_original\' => \'Hight\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'translations\' => (object) array(
          \'original\' => \'en\',
          \'data\' => array(
            \'en\' => array(
              \'entity_type\' => \'node\',
              \'entity_id\' => \'30\',
              \'revision_id\' => \'33\',
              \'language\' => \'en\',
              \'source\' => \'\',
              \'uid\' => \'1\',
              \'status\' => \'1\',
              \'translate\' => \'0\',
              \'created\' => \'1490104422\',
              \'changed\' => \'1490104422\',
            ),
            \'fr\' => array(
              \'entity_type\' => \'node\',
              \'entity_id\' => \'30\',
              \'revision_id\' => \'33\',
              \'language\' => \'fr\',
              \'source\' => \'en\',
              \'uid\' => \'1\',
              \'status\' => \'1\',
              \'translate\' => \'0\',
              \'created\' => \'1490104485\',
              \'changed\' => \'1490104485\',
            ),
          ),
        ),
      \'type\' => \'priority\',
      \'uid\' => \'1\',
      \'uuid\' => \'9cefd721-a365-4a72-a06e-6ec278accb74\',
      \'vid\' => NULL,
      \'vuuid\' => \'92b96109-31b2-483f-8b8f-9fd206751ca4\',
    ),
  (object) array(
      \'body\' => array(),
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'1\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => \'a:4:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;s:12:"admin_select";s:6:"navbar";s:15:"navbar_language";i:0;}\',
      \'entity_translation_handler_id\' => \'node-status-eid-25\',
      \'field_pick_list_parent\' => array(
        \'und\' => array(),
      ),
      \'files\' => array(),
      \'language\' => \'en\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'admin\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'Draft\',
      \'title_field\' => array(
        \'en\' => array(
          array(
            \'value\' => \'Draft\',
            \'format\' => NULL,
            \'safe_value\' => \'Draft\',
          ),
        ),
        \'fr\' => array(
          array(
            \'value\' => \'Brouillon\',
            \'format\' => NULL,
            \'safe_value\' => \'Brouillon\',
          ),
        ),
      ),
      \'title_original\' => \'Draft\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'translations\' => (object) array(
          \'original\' => \'en\',
          \'data\' => array(
            \'en\' => array(
              \'entity_type\' => \'node\',
              \'entity_id\' => \'25\',
              \'revision_id\' => \'28\',
              \'language\' => \'en\',
              \'source\' => \'\',
              \'uid\' => \'1\',
              \'status\' => \'1\',
              \'translate\' => \'0\',
              \'created\' => \'1489777721\',
              \'changed\' => \'1489777721\',
            ),
            \'fr\' => array(
              \'entity_type\' => \'node\',
              \'entity_id\' => \'25\',
              \'revision_id\' => \'28\',
              \'language\' => \'fr\',
              \'source\' => \'en\',
              \'uid\' => \'1\',
              \'status\' => \'1\',
              \'translate\' => \'0\',
              \'created\' => \'1489777761\',
              \'changed\' => \'1489777761\',
            ),
          ),
        ),
      \'type\' => \'status\',
      \'uid\' => \'1\',
      \'uuid\' => \'a69f1aec-6259-4a4a-9f7b-dfe73b80af02\',
      \'vid\' => NULL,
      \'vuuid\' => \'1c0d9037-73d9-4906-ba93-0d8b4cb672b1\',
    ),
  (object) array(
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'1\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => \'a:4:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;s:12:"admin_select";s:6:"navbar";s:15:"navbar_language";i:0;}\',
      \'entity_translation_handler_id\' => \'node-dlsu_contact-eid-33\',
      \'field_email\' => array(),
      \'field_given_name\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Contact 1\',
            \'format\' => NULL,
            \'safe_value\' => \'Contact 1\',
          ),
        ),
      ),
      \'field_pick_list_parent\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'28\',
          ),
        ),
      ),
      \'field_surname\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Contact 1\',
            \'format\' => NULL,
            \'safe_value\' => \'Contact 1\',
          ),
        ),
      ),
      \'field_telephone\' => array(),
      \'field_title\' => array(),
      \'files\' => array(),
      \'language\' => \'en\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'admin\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'Contact 1\',
      \'title_field\' => array(
        \'en\' => array(
          array(
            \'value\' => \'Contact 1\',
            \'format\' => NULL,
            \'safe_value\' => \'Contact 1\',
          ),
        ),
      ),
      \'title_original\' => \'Contact 1\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'translations\' => (object) array(
          \'original\' => NULL,
          \'data\' => array(),
        ),
      \'type\' => \'dlsu_contact\',
      \'uid\' => \'1\',
      \'uuid\' => \'acad2c70-bc67-4e0e-a6a5-772f69190619\',
      \'vid\' => NULL,
      \'vuuid\' => \'f1232f44-9a8d-4220-a71f-37e1f5616aa8\',
    ),
  (object) array(
      \'body\' => array(),
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'1\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => \'a:4:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;s:12:"admin_select";s:6:"navbar";s:15:"navbar_language";i:0;}\',
      \'entity_translation_handler_id\' => \'node-nnhpd_bureau_project-eid-34\',
      \'field_pick_list_parent\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'28\',
          ),
        ),
      ),
      \'files\' => array(),
      \'language\' => \'en\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'admin\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'BLSS\',
      \'title_field\' => array(
        \'en\' => array(
          array(
            \'value\' => \'BLSS\',
            \'format\' => NULL,
            \'safe_value\' => \'BLSS\',
          ),
        ),
      ),
      \'title_original\' => \'BLSS\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'translations\' => (object) array(
          \'original\' => \'en\',
          \'data\' => array(
            \'en\' => array(
              \'entity_type\' => \'node\',
              \'entity_id\' => \'34\',
              \'revision_id\' => \'37\',
              \'language\' => \'en\',
              \'source\' => \'\',
              \'uid\' => \'1\',
              \'status\' => \'1\',
              \'translate\' => \'0\',
              \'created\' => \'1490108494\',
              \'changed\' => \'1490108494\',
            ),
          ),
        ),
      \'type\' => \'nnhpd_bureau_project\',
      \'uid\' => \'1\',
      \'uuid\' => \'adb60715-6c3b-450e-b4cc-93220a74621e\',
      \'vid\' => NULL,
      \'vuuid\' => \'e89e3d7f-453f-4369-95d5-457e4a714180\',
    ),
  (object) array(
      \'body\' => array(),
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'1\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => \'a:4:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;s:12:"admin_select";s:6:"navbar";s:15:"navbar_language";i:0;}\',
      \'entity_translation_handler_id\' => \'node-space_root-eid-27\',
      \'files\' => array(),
      \'group_access\' => array(),
      \'group_content_access\' => array(),
      \'group_group\' => array(
        \'und\' => array(
          array(
            \'value\' => \'1\',
          ),
        ),
      ),
      \'language\' => \'en\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'admin\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'og_group_ref\' => array(),
      \'panelizer\' => array(
        \'default\' => (object) array(
            \'pnid\' => \'3\',
            \'title\' => \'Default\',
            \'panelizer_type\' => \'node\',
            \'panelizer_key\' => \'space_root\',
            \'access\' => array(),
            \'view_mode\' => \'default\',
            \'did\' => NULL,
            \'name\' => \'node:space_root:default:default\',
            \'css_id\' => \'\',
            \'css_class\' => \'\',
            \'css\' => \'\',
            \'no_blocks\' => \'0\',
            \'title_element\' => \'H2\',
            \'link_to_entity\' => \'1\',
            \'extra\' => array(),
            \'pipeline\' => \'standard\',
            \'contexts\' => array(),
            \'relationships\' => array(),
            \'table\' => \'panelizer_defaults\',
            \'type\' => \'Overridden\',
            \'export_type\' => 3,
            \'display\' => panels_display::__set_state(array(
               \'args\' => 
              array (
              ),
               \'content\' => 
              array (
                42 => 
                stdClass::__set_state(array(
                   \'pid\' => \'42\',
                   \'did\' => \'6\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:body\',
                   \'shown\' => \'0\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'hidden\',
                    \'formatter\' => \'text_default\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'0\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'bb1a7bc8-86e8-455b-9cdc-538f415663f6\',
                )),
                43 => 
                stdClass::__set_state(array(
                   \'pid\' => \'43\',
                   \'did\' => \'6\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:title_field\',
                   \'shown\' => \'0\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'hidden\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'1\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'4f6d050c-ea9c-46d6-8962-337f93d9f543\',
                )),
                44 => 
                stdClass::__set_state(array(
                   \'pid\' => \'44\',
                   \'did\' => \'6\',
                   \'panel\' => \'center\',
                   \'type\' => \'entity_field\',
                   \'subtype\' => \'node:group_group\',
                   \'shown\' => \'0\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'label\' => \'above\',
                    \'formatter\' => \'og_group_subscribe\',
                    \'delta_limit\' => 0,
                    \'delta_offset\' => \'0\',
                    \'delta_reversed\' => false,
                    \'formatter_settings\' => 
                    array (
                      \'field_name\' => false,
                    ),
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'2\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'5731e8d4-a49f-43b8-9ffe-7c43c5391eaf\',
                )),
                45 => 
                stdClass::__set_state(array(
                   \'pid\' => \'45\',
                   \'did\' => \'6\',
                   \'panel\' => \'center\',
                   \'type\' => \'node_links\',
                   \'subtype\' => \'node_links\',
                   \'shown\' => \'0\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'override_title\' => false,
                    \'override_title_text\' => \'\',
                    \'build_mode\' => \'default\',
                    \'identifier\' => \'\',
                    \'link\' => true,
                    \'context\' => \'panelizer\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                    \'css_class\' => \'link-wrapper\',
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'3\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'5d1bbc9f-cd85-4786-8ab7-1a50cfca025d\',
                )),
                72 => 
                stdClass::__set_state(array(
                   \'pid\' => \'72\',
                   \'did\' => \'6\',
                   \'panel\' => \'center\',
                   \'type\' => \'block\',
                   \'subtype\' => \'bean-create-space\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'override_title\' => 0,
                    \'override_title_text\' => \'\',
                    \'override_title_heading\' => \'h2\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'4\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'62894f5c-a617-4b9b-b3d4-29d3ec70552e\',
                )),
                101 => 
                stdClass::__set_state(array(
                   \'pid\' => \'101\',
                   \'did\' => \'6\',
                   \'panel\' => \'center\',
                   \'type\' => \'views\',
                   \'subtype\' => \'legal_opinion\',
                   \'shown\' => \'1\',
                   \'access\' => 
                  array (
                  ),
                   \'configuration\' => 
                  array (
                    \'override_pager_settings\' => 0,
                    \'use_pager\' => 1,
                    \'nodes_per_page\' => \'10\',
                    \'pager_id\' => \'0\',
                    \'offset\' => \'0\',
                    \'more_link\' => 0,
                    \'feed_icons\' => 0,
                    \'panel_args\' => 0,
                    \'link_to_view\' => 0,
                    \'args\' => \'\',
                    \'url\' => \'\',
                    \'display\' => \'page_view_tree\',
                    \'override_title\' => 0,
                    \'override_title_text\' => \'\',
                    \'override_title_heading\' => \'h2\',
                  ),
                   \'cache\' => 
                  array (
                  ),
                   \'style\' => 
                  array (
                    \'settings\' => NULL,
                  ),
                   \'css\' => 
                  array (
                  ),
                   \'extras\' => 
                  array (
                  ),
                   \'position\' => \'5\',
                   \'locks\' => 
                  array (
                  ),
                   \'uuid\' => \'3dd4f832-72cc-450a-bc19-e9e28a9fb301\',
                )),
              ),
               \'panels\' => 
              array (
                \'center\' => 
                array (
                  0 => \'42\',
                  1 => \'43\',
                  2 => \'44\',
                  3 => \'45\',
                  4 => \'72\',
                  5 => \'101\',
                ),
              ),
               \'incoming_content\' => NULL,
               \'css_id\' => NULL,
               \'context\' => 
              array (
              ),
               \'did\' => \'6\',
               \'renderer\' => \'standard\',
               \'layout\' => \'flexible\',
               \'layout_settings\' => 
              array (
              ),
               \'panel_settings\' => 
              array (
                \'style_settings\' => 
                array (
                  \'default\' => NULL,
                  \'center\' => 
                  array (
                    \'style\' => \'$\',
                    \'settings\' => 
                    array (
                      \'name\' => \'_temporary\',
                      \'style_base\' => \'region_plain_box\',
                      \'palette\' => 
                      array (
                        \'background\' => \'#FFFFFF\',
                        \'text\' => \'#000000\',
                        \'border\' => \'#303099\',
                      ),
                      \'font\' => 
                      array (
                        \'font\' => \'\',
                        \'size\' => \'\',
                        \'letter_spacing\' => \'\',
                        \'word_spacing\' => \'\',
                        \'decoration\' => \'\',
                        \'weight\' => \'\',
                        \'style\' => \'\',
                        \'variant\' => \'\',
                        \'case\' => \'\',
                        \'alignment\' => \'\',
                      ),
                      \'border\' => 
                      array (
                        \'thickness\' => \'1px\',
                        \'style\' => \'solid\',
                      ),
                      \'padding\' => 
                      array (
                        \'top\' => \'\',
                        \'right\' => \'\',
                        \'bottom\' => \'\',
                        \'left\' => \'\',
                      ),
                    ),
                  ),
                ),
                \'center\' => 
                array (
                  \'style\' => \'stylizer\',
                ),
              ),
               \'cache\' => 
              array (
              ),
               \'title\' => \'\',
               \'hide_title\' => \'0\',
               \'title_pane\' => \'42\',
               \'uuid\' => \'127b0aeb-bfe4-45a1-882c-0d70c44f809d\',
               \'storage_type\' => \'panelizer_default\',
               \'storage_id\' => \'node:space_root:default:default\',
            )),
            \'export_module\' => NULL,
            \'entity_id\' => 0,
            \'revision_id\' => 0,
          ),
      ),
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'All Spaces\',
      \'title_field\' => array(
        \'en\' => array(
          array(
            \'value\' => \'All Spaces\',
            \'format\' => NULL,
            \'safe_value\' => \'All Spaces\',
          ),
        ),
        \'fr\' => array(
          array(
            \'value\' => \'Espace racine\',
            \'format\' => NULL,
            \'safe_value\' => \'Espace racine\',
          ),
        ),
      ),
      \'title_original\' => \'All Spaces\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'translations\' => (object) array(
          \'original\' => \'en\',
          \'data\' => array(
            \'en\' => array(
              \'entity_type\' => \'node\',
              \'entity_id\' => \'27\',
              \'revision_id\' => \'30\',
              \'language\' => \'en\',
              \'source\' => \'\',
              \'uid\' => \'1\',
              \'status\' => \'1\',
              \'translate\' => \'0\',
              \'created\' => \'1490021700\',
              \'changed\' => \'1490022107\',
            ),
            \'fr\' => array(
              \'entity_type\' => \'node\',
              \'entity_id\' => \'27\',
              \'revision_id\' => \'30\',
              \'language\' => \'fr\',
              \'source\' => \'en\',
              \'uid\' => \'1\',
              \'status\' => \'1\',
              \'translate\' => \'0\',
              \'created\' => \'1490021918\',
              \'changed\' => \'1490022145\',
            ),
          ),
        ),
      \'type\' => \'space_root\',
      \'uid\' => \'1\',
      \'uuid\' => \'c786693a-66cb-447c-a5ca-f9864ded5fcc\',
      \'vid\' => NULL,
      \'vuuid\' => \'01295031-0237-4e9d-87e8-35571c4ddaa8\',
    ),
  (object) array(
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'1\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => \'a:4:{s:7:"contact";i:1;s:20:"l10n_client_disabled";b:0;s:12:"admin_select";s:6:"navbar";s:15:"navbar_language";i:0;}\',
      \'entity_translation_handler_id\' => \'node-requester-eid-32\',
      \'field_email\' => array(),
      \'field_given_name\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Requester 1\',
            \'format\' => NULL,
            \'safe_value\' => \'Requester 1\',
          ),
        ),
      ),
      \'field_pick_list_parent\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'28\',
          ),
        ),
      ),
      \'field_surname\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Requester 1\',
            \'format\' => NULL,
            \'safe_value\' => \'Requester 1\',
          ),
        ),
      ),
      \'field_telephone\' => array(),
      \'field_title\' => array(),
      \'files\' => array(),
      \'language\' => \'en\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'admin\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'Requester 1, Requester 1\',
      \'title_field\' => array(
        \'en\' => array(
          array(
            \'value\' => \'Requester 1, Requester 1\',
            \'format\' => NULL,
            \'safe_value\' => \'Requester 1, Requester 1\',
          ),
        ),
        \'fr\' => array(
          array(
            \'value\' => \'Requester 1, Requester 1\',
            \'format\' => NULL,
            \'safe_value\' => \'Requester 1, Requester 1\',
          ),
        ),
      ),
      \'title_original\' => \'Requester 1, Requester 1\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'translations\' => (object) array(
          \'original\' => NULL,
          \'data\' => array(),
        ),
      \'type\' => \'requester\',
      \'uid\' => \'1\',
      \'uuid\' => \'f3e8a7aa-cbfc-4948-876f-c3db5aa9b72c\',
      \'vid\' => NULL,
      \'vuuid\' => \'0e363d47-d539-460a-a46d-0068389e5a19\',
    ),
)',
);
  return $node_export;
}
