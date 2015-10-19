#Comment passer des variables à un formulaire ?

### 1ère étape, lors de l'appel au formulaire :

```php
//On ajoute la ou les variables à la suite de l'identifiant de notre formulaire
$form = drupal_get_form('mon_formulaire',$ma_variable_a_passer);
```

### 2e étape, récupération dans le formulaire :

```php
function mon_formulaire($form,&$form_state) {
  //On récupère les variables dans un tableau d'arguments
  $ma_variable_a_recuperer = $form_state['build_info']['args'][0];
  ...
}
```

# Avec plusieurs variables

### Appel du formulaire :
```php
$form = drupal_get_form('mon_formulaire',$var1,$var2);
```

### Récupération dans le formulaire :

```php
function mon_formulaire($form,&$form_state) {
  $var1 = $form_state['build_info']['args'][0];
  $var2 = $form_state['build_info']['args'][1];
  ...
}
```
