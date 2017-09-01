# Entity Field Query
```php
$query = new EntityFieldQuery();
$result = $query
  ->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'article')
  ->fieldCondition('field_categories', 'tid', array('12','13'), 'IN')
  ->propertyCondition('status', NODE_PUBLISHED)
  ->range(0,5)
  ->execute();
```

## Debuguer une EFQ
1 - Ajouter un tag à la query
```php
$query->addTag('efq_debug');
```

2 - utiliser un hook_query_alter
```php
function CUSTOMMODULE_query_alter($query) {
  if ($query->hasTag('efq_debug')) {
    dpm((string) $query);
    dpm($query->arguments());
  }
}
```
