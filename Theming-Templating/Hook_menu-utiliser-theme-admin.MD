```php

function HOOK_menu() {

  $items['ma_route'] = array(
    ...
    'theme callback' => 'variable_get',
    'theme arguments' => array('admin_theme'),
    ...
  );
  
  return $items;
}

```
