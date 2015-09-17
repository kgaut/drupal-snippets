##Modification d'un champ "liste texte" : ajout d'une valeur.
```php
  $info = field_info_field('field_type_contenu');

  $values = &$info['settings']['allowed_values'];

  if(!isset($values['question_technique'])) {
    $values['question_technique'] = 'Question technique';
    field_update_field($info);
  }
```
