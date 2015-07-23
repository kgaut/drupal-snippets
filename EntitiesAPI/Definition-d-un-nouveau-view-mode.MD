```php
function HOOK_entity_info_alter(&$entity_info) {
$entity_info['node']['view modes']['front'] = array(
'label' => t('Homepage'),
'custom settings' => TRUE,
);
} 
```
