```php
$entity_type = 'selection'; //Type de l'entité voulue
$entity_bundle = 'selection'; //Bundle de l'entité voulue

$entity = entity_create($entity_type, array('type' => $entity_bundle));
$wrapper = entity_metadata_wrapper($entity_type, $entity);

//Modification de propriétés
$wrapper->uid = $user_id;

//Modification de champs
$wrapper->field_selection_country->set($country_id);

//Sauvegarde de l'entitée et de ses champs
$wrapper->save();
```
