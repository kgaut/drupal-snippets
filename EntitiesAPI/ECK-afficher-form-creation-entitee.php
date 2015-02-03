```php
$entity_machine_name = "lorem"; //Nom machine de votre entitée
$bundle_machine_name = "ipsum"; //Nom machine de votre ipsum
 
$form = eck__entity__add($entity_machine_name, $bundle_machine_name);
 
$content = drupal_render($form); 
```
