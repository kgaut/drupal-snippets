```php
function MODULE_user_element_info_alter (&$type) {
if (isset($type['password_confirm']['#process'])) {
$func = '_MODULE_user_process_password_confirm';
$type['password_confirm']['#process'][] = $func;
}
return $type;
}
function _MODULE_user_process_password_confirm($element) {
$element['pass1']['#attributes']['placeholder'] = t('Mot de passe'). ' *';
$element['pass2']['#attributes']['placeholder'] = t('Confirmation mot de passe'). ' *';
return $element;
} 
```
