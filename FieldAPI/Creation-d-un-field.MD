```php
<?php
 
 
function MYMODULE_fields_field_info() {
$data = array();
$data['picto_bloc'] = array(
'label' => t('Picto de bloc'),
'description' => 'Ensemble picto + titre + texte',
'default_widget' => '_picto_widget',
'default_formatter' => '_picto_formatter',
);
return $data;
}
 
 
function MYMODULE_fields_field_widget_info() {
$widget_list = array();
$widget_list['_picto_widget'] = array(
'label' => t('Default'),
'description' => t(''),
'field types' => array('picto_bloc'),
'behaviors' => array(
'multiple values' => FIELD_BEHAVIOR_DEFAULT,
'default value' => FIELD_BEHAVIOR_DEFAULT,
),
);
return $widget_list;
}
 
function MYMODULE_fields_field_formatter_info() {
$formatter_list = array();
$formatter_list['_picto_formatter'] = array(
'label' => t('Default'),
'field types' => array('picto_bloc'),
'settings' => array(),
);
return $formatter_list;
}
 
function MYMODULE_fields_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
return $items;
}
 
 
function MYMODULE_fields_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
$base = $element;
module_load_include('module','MYMODULE_block');
$picto_options = _MYMODULE_block_get_picto_options();
if ($instance['widget']['type'] === '_picto_widget') {
$element['titre'] = array(
'#type' => 'textfield',
'#title' => t('Titre'),
'#default_value' => isset($items[$delta]['titre']) ? $items[$delta]['titre'] : NULL,
);
$element['texte'] = array(
'#type' => 'text_format',
'#title' => t('Texte'),
'#default_value' => isset($items[$delta]['texte']) ? is_array($items[$delta]['texte']) ? $items[$delta]['texte']['value'] : $items[$delta]['texte'] : NULL,
'#format' => 'full_html',
'#maxlength' => 5000,
);
$element['picto'] = array(
'#type' => 'select',
'#empty_option' => 'Aucun',
'#title' => t('Picto'),
'#default_value' => isset($items[$delta]['picto']) ? $items[$delta]['picto'] : NULL,
'#options' => $picto_options,
'#maxlength' => 5000,
);
return $element;
}
}
 
function MYMODULE_fields_field_is_empty($item, $field) {
if ($field['type'] == 'picto_bloc') {
return empty($item['titre']);
}
return TRUE;
} 
```
