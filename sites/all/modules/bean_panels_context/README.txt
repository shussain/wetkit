Bean Panels Context
===================

This module provides panels context aware beans, and a ctools content type for displaying them.

Panel content options
---------------------

The following are descriptions of each the options exposed to panels by the content type plugin.


### Derive title ###

If the bean plugin's render array has a title, it will be used as the block title.  This is useful if the bean's internals need to generate the bean title.

The bean's title needs to be here in the bean render array: $content['title']['#markup'];

Not here: $content['bean'][$bean->delta]['title']['#markup'];


### Contexts ###

Select which of the available contexts are actually passed to the bean.  Selecting none will pass all available contexts to the bean.

### Delta ###

Which bean to render.

