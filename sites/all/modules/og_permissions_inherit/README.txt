OG Permissions inherit
======================

## SUMMARY

Inherit OG permissions by enabling the setting up of a hierarchical relationship 
between organic group node types.  

For example, Lets say we have a series of og courses managed by og course admin 
members and each og course had a series of og tutorials run by og tutor 
members and that we wanted the og course admins to be able to administer 
the og tutorials.  This module negates the need of adding the og course admin 
members as og tutor admin members.  Instead they will inherit the permissions, 
enabling them to have the same privileges lower down the tree.

* With this module you do not need to keep adding users at each level of the 
tree and then giving them new roles and permissions at that level.  

## USAGE

* One or more organic group is required to be set as the "HEAD". 
* Other organic groups now may reference this organic group so to be able to
inherit its' permissions.
* There are no defined limits to the depth of the inheritance allowed.


## REQUIREMENTS

* Drupal version: 7.x-2.x.


## INSTALLATION --

Install as usual, see http://drupal.org/node/70151 for further information.


## HOW TO USE

### Create Inherit permission rules.
* Edit a node type that has already been setup as an OG.  Goto the Organic 
group settings tab under the heading, 
"Inherit permissions from another OG node type".
* Select an OG node type from which you would like to inherit OG permissions 
from
* Set to "HEAD" if it is the top level of the tree.
* At least one og must be set to be at the "HEAD".

### TODO
* Error reporting
* API to allow other modules to check for permission


## TROUBLESHOOTING

See online issue at http://drupal.org/project/issues/og_permissions_inherit.
