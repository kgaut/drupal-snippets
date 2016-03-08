#Mettre à jours ses entités customs

```
function MODULE_update_8001() {
  \Drupal::entityTypeManager()->clearCachedDefinitions();
  \Drupal::service('entity.definition_update_manager')->applyUpdates();
}
```