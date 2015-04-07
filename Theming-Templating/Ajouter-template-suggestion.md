# Comment ajouter une suggestion de template ?

Par exemple on veux ajouter une suggestion de template pour les nodes selon leur view_mode et selon leur type


```php
function MODULE_preprocess_node(&$variables) {
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $variables['view_mode'];
}
```

exemple de template pour un contenu de type **article** en view_mode **full** : 

*node--article--full.tpl.php*

