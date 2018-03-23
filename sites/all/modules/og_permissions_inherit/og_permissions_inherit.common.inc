<?php
/**
 * @file
 * Common re-usable functions.
 */

/**
 * Return an array of all the og ancestry from cache when available.
 *
 * @param object $group
 *   The group for which we are loading the ancestry.
 * @param bool $reset
 *   Reset the cache for this group type/id.
 *
 * @return array
 *   An array of group ids from it's og ancestry.
 */
function og_permissions_inherit_ancestors_load($group, $reset = FALSE) {
  $node_type = $group->type;
  $group_cache = &drupal_static(__FUNCTION__, array());
  $cid = $node_type . '__' . $group->nid;
  $ancestor_groups = array();
  if (!isset($group_cache[$cid]) || $reset) {
    $ancestor_groups = og_permissions_inherit_ancestors_load_multiple($group, $reset);
    $group_cache[$cid] = $ancestor_groups;
    cache_set($cid, $group_cache[$cid]);
  }
  return $group_cache[$cid];
}

/**
 * Return an array of all the groups' ids from it's og ancestry.
 *
 * @param object $group
 *   The group for which we are loading the ancestry.
 * @param bool $reset
 *   Reset the cache for this group type/id.
 *
 * @return array
 *   An array of group ids of ancestors.
 */
function og_permissions_inherit_ancestors_load_multiple($group, $reset = FALSE) {
  $inherit_from_groups = array();
  if (isset($group->og_group_ref[LANGUAGE_NONE][0]['target_id'])) {
    $current_group_id = $group->og_group_ref[LANGUAGE_NONE][0]['target_id'];
    while ($current_group_id !== 0) {
      $current_group = entity_load('node', array($current_group_id));
      $current_group_inherit_from = variable_get('og_permissions_inherit_from_' . $current_group[$current_group_id]->type);
      if ($current_group_inherit_from !== '') {
        $inherit_from_groups[] = $current_group_id;
        if (isset($current_group[$current_group_id]->og_group_ref[LANGUAGE_NONE][0]['target_id'])) {
          $current_group_id = $current_group[$current_group_id]->og_group_ref[LANGUAGE_NONE][0]['target_id'];
        }
        else {
          $current_group_id = 0;
        }
      }
    }
  }
  return $inherit_from_groups;
}
