# Comment afficher un champ personnalisé dans les résultats d'une vue

## Etape 1 : 
```php
function MON_MODULE_views_data() {
  $data['acaps_user']['table']['group'] = t('User'); // groupement de field dans lequel sera placé notre champ custom dans views
  $data['acaps_user']['table']['join'] = array(
    '#global' => array(),
  );

  $data['acaps_user']['countries_followed'] = array(
    'title' => t('Mon nom de champ'),
    'help' => t('Ma description de champ'),
    'field' => array(
      'handler' => 'views_handler_mon_champ_custom', //doit correspondre au nom de la classe definie plus bas
    ),
  );

  return $data;
}
```

## Etape 2
```php
<?php
class views_handler_mon_champ_custom extends views_handler_field {
  function render($values) {
    return t("C'est ici que l'on peut faire les traitement et que l'on doit retourner le contenu du champ");
  }
}
```
