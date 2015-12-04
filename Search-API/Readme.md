# Search API

## Config différente en preprod

```php
<?php
/**
 * Implements hook_default_search_api_server_alter().
 */
function module_name_default_search_api_server_alter(array &$defaults) {
  if ($_SERVER['SERVER_NAME'] !== 'live.example.com' && isset($defaults['solr'])) {
    $defaults['solr']->options['host'] = 'devsolr.example.com';
    $defaults['solr']->options['port'] = '8080';
    $defaults['solr']->options['path'] = '/solr/drupal';
  }
}
?>
```
