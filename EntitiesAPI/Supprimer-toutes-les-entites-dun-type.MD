#Supprimer toutes les entités d'un certain type

Créer un fichier php à la racine de votre site drupal avec le contenu suivant, puis l'appeler depuis votre navigateur.
```php
<?php
define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);


$entity_type = "node"; //Nom du type de l'entité
$bundle = "article"; //Bundle de l'entité ('article', 'page'...)

$query = new EntityFieldQuery();
$result = $query
  ->entityCondition('entity_type',$entity_type)
  ->entityCondition('bundle', $bundle)
  ->execute();

$deleted_count = 0;
foreach ($result[$entity_type] as $key => $record) {
  entity_delete($entity_type,$key);
  $deleted_count++;
}

print("$deleted_count entites de type $entity_type ont été supprimées.");
```
