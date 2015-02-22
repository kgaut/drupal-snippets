Plus d'informations sur cette page : https://www.drupal.org/node/110238

```php
function MODULE_update_7001() {
db_query("UPDATE {system} SET weight = $POIDS WHERE type = 'module' AND name = 'MODULE'");
} 
```
