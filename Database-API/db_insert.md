#DB Insert

##Requète simple d'insertion dans la table node
```php
$nid = db_insert('node') ->fields(array(
  'title' => 'Example',
  'uid' => 1,
  'created' => REQUEST_TIME,
))->execute();
```