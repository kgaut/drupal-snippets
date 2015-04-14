#Form API

##Ajouter une fonction de validate custom
Dans un HOOK_form ou HOOK_form_alter 
```php
$form[“#validate”][] = “nom_de_la_fonction”
```

##Ajouter une fonction de submit custom
Dans un HOOK_form ou HOOK_form_alter 
```php
$form[“#submit”][] = “nom_de_la_fonction”
```