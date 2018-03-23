TRANSLATION OWN NODES
=============================
Translation own nodes extends Drupal support for translating content based on content author. 
This permission will be in core in D8, but has not been backported yet for Drupal 7.
As there was already a module for Drupal 6, it has been ported to D7 and further expanded with Entity Translation support.

Install
=============================
1) Simply drop this module's directory into your modules directory 
2) Enable the module
3) configure the permissions

Recommended
=============================
- Soft dependencies set on the core translation module and/or entity translation module. Module will do nothing without at least one ofthese modules.
- Chain menu access api is recommended: https://www.drupal.org/project/chain_menu_access

Author
=============================
D6: Juan Vizcarrondo (jvizcarrondo - http://drupal.org/user/352652) 
D7: Wim Vanheste (rv0 - http://drupal.org/user/655596)