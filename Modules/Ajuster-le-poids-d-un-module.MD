```php
function MODULE_update_7001() {
db_query("UPDATE {system} SET weight = $POIDS WHERE type = 'module' AND name = 'MODULE'");
} 
```
