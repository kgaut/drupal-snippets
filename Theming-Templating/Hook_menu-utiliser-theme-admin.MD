```php

function HOOK_menu() {
  if (!module_exists('workflownode')) {
    return array();
  }

  $items['ma_route'] = array(
    ...
    'theme callback' => 'variable_get',
    'theme arguments' => array('admin_theme'),
    ...
  );
  return $items;
}

```
