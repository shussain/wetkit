<?php
/**
 * @file
 * API documentation for the FATE module.
 */

/**
 * Deine the path to a specific entity.
 *
 * Many entities are loaded from the path '[entityname]/%[entityname], e.g.
 * 'node/%node' for nodes, however some entities use a different path structure,
 * e.g. 'taxonomy/term/%taxonomy_term' for taxonomy terms.
 *
 * @param string $path
 *   The standard path to an entity of this type,
 * @param int $pos
 *   The position within the $path where the entity is found, as identified by
 *   a percentage sign (%), and starting from zero. For example, in the node
 *   path 'node/%node' the entity is the 2nd item in the path, thus the $pos is
 *   equal to 1; taxonomy terms have a $pos of 2 because the entity is the
 *   third part of the path.
 * @param string $entity_type
 *   The type of entity being processed by a specific field.
 *
 * @see fieldable_panels_panes_fate_entity_path_alter()
 * @see taxonomy_fate_entity_path_alter()
 */
function hook_fate_entity_path_alter(&$path, &$pos, $entity_type) {
  if ($field['entity_type'] == 'customentity') {
    $path = 'my/entity/%myentity';
    $pos = 2;
  }
}

/**
 * Controls whether the revision fields will be displayed for fields on a given
 * entity bundle.
 *
 * @param array $retval
 *   An array where the first item is whether revisions are supported by this
 *   entity bundle, the second item is whether the current user has permission
 *   to control whether or not revisions are created, the third whether a new
 *   revision is created by default.
 * @param string $entity_type
 * @param string $bundle
 */
function hook_fate_entity_allow_revisions(&$retval, $entity_type, $bundle) {
  if ($entity_type == 'myentity') {
    // Support revisions.
    $retval[0] = TRUE;
    // This user can control whether they see the revisions options.
    $retval[1] = user_access('myentity manage revisions');
    // A new revision is created by default.
    $retval[2] = TRUE;
  }
}
