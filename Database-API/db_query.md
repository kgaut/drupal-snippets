# DB Query

## Select simple avec itération
```php
$uid = 1;
$result = db_query('SELECT n.nid, n.title, n.created
FROM {node} n WHERE n.uid = :uid', array(':uid' => $uid));
foreach ($result as $record) {
  // Faire des trucs
} 
```

## Select simple
```php
$last_update = db_query('select MAX(changed) from {node} where status = 1 LIMIT 1')->fetchField();
```

## Insertion simple
```php
$result = db_query("INSERT INTO {node} (title, uid, created) VALUES (%s, %d, %d)", 'Example', 1, time());
```

## Connaitre le nombre de résultats d'une requète
```php
$num_of_nodes = db_query('SELECT nid FROM {node}')->rowCount(); 
```
