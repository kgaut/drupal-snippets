# Form API

## Définition d'un formulaire simple

```php

function menu_callback() {
  drupal_get_form(‘mon_form_custom’); // appel du formulaire
}

function mon_form_custom($form, &$form_state) {
  //Définition du formulaire
}

function mon_form_custom_validate($form, &$form_state) {
  //fonction de validation du formulaire globale
}

function mon_form_custom_submit($form, &$form_state) {
  //fonction de validation
}

```

## Ajouter une fonction de validate custom
Dans un HOOK_form ou HOOK_form_alter 

```php
$form[“#validate”][] = “nom_de_la_fonction”
```

## Ajouter une fonction de submit custom
Dans un HOOK_form ou HOOK_form_alter 

```php
$form[“#submit”][] = “nom_de_la_fonction”
```
