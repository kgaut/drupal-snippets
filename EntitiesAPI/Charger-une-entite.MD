##Chargement d'une entité
```php
$entity_type = 'selection'; //nom du type d'entité
$entity_id = 1; //l'id de l'entité que l'on veut charger

$entite = entity_load('selection',array($entity_id));//la fonction entity_load attends un tableau

$entite = array_pop($entite) //la fonction entity_load retourne un tableau avec comme clé l'id
//OU
$entite = $entite[$entity_id]

```


##Chargement de plusieurs entités
```php
$entity_type = 'selection'; //nom du type d'entité
$entity_id = array(1,5,7);  //les ids des entités que l'on veut charger

$entites = entity_load('selection',$entity_ids);//la fonction entity_load attends un tableau

//$entites est un tableau d'entités dont les clés sont les ids (1,5,7 dans cet exemple)


```
