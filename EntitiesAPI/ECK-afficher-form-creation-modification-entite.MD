#Créer & Modifier une entité définie par ECK

## Formulaire de création
```php
$entity_machine_name = "lorem"; //Nom machine de votre entité
$bundle_machine_name = "ipsum"; //Nom machine de votre ipsum
 
$form = eck__entity__add($entity_machine_name, $bundle_machine_name);
 
$content = drupal_render($form); 
```

## Formulaire de modification

```php
$entity_machine_name = "lorem"; //Nom machine de votre entité
$bundle_machine_name = "ipsum"; //Nom machine de votre ipsum
$id = 5; // identifiant de l'entite à modifier
 
$form = eck__entity__edit($entity_machine_name,$bundle_machine_name,$id);
 
$content = drupal_render($form); 
```
