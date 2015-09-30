##Pour un élément de menu nouveau
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
##Pour un élément de menu déjà existant
```php
function HOOK_menu_alter(&$items) {
  $items['atom/%scald_atom/edit/%ctools_js']['theme callback'] = 'variable_get';
  $items['atom/%scald_atom/edit/%ctools_js']['theme arguments'] = array('admin_theme');
}
```
