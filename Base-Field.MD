#Définition des champs de base

## Date
```
$fields['game_date'] = BaseFieldDefinition::create('datetime')
  ->setLabel(t('Date'))
  ->setDescription(t('The game\'s date'))
  ->setSettings(array(
    'default_value' => '',
    'max_length' => 50,
    'text_processing' => 0,
  ))
  ->setDefaultValue(array(0 => array(
    'default_date_type' => 'now',
    'default_date' => 'now',
  )))
  ->setDisplayOptions('view', array(
    'label' => 'hidden',
    'type' => 'datetime_default',
    'weight' => 0,
  ))
  ->setDisplayOptions('form', array(
    'type' => 'datetime_default',
    'weight' => 1,
  ))
  ->setDisplayConfigurable('form', TRUE)
  ->setDisplayConfigurable('view', TRUE);
  ```
