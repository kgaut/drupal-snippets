# DB Insert

[https://www.drupal.org/node/310079](db_insert sur drupal)

## Requète simple d'insertion dans la table node
```php
$nid = db_insert('node') ->fields(array(
  'title' => 'Example',
  'uid' => 1,
  'created' => REQUEST_TIME,
))->execute();
```
