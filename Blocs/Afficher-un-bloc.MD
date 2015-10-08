##Afficher un block créé via l'administration
```php
$identifiant = 1; //c'est l'identifiant du bloc visible dans l'url lors de sa modification
$block = block_load('block', $identifiant);
$monBlock = _block_get_renderable_array(_block_render_blocks(array($block)));
//Code pour afficher le block
//Peut aussi être passé à un template via theme()
print render($monBlock); 
```

##Afficher un block créé dans un module
```php
$module = 'mon_module' //Le nom du module définissant le bloc
$identifiant = 'mon_bloc'; //le nom "machine" du bloc, défini dans HOOK_block_info()

$block = block_load($module, $identifiant);
$monBlock = _block_get_renderable_array(_block_render_blocks(array($block)));

//Code pour afficher le block
//Peut aussi être passé à un template via theme()
print render($monBlock); 
```

##Afficher un block créé dans views
```php
$nom_vue = 'mon_bloc'; //le nom "machine" de la vue
$nom_affichage = 'block1' //le nom "machine" de l'affichage ("Display")
$block = block_load('views', $nom_vue.'-'.$nom_affichage);
$monBlock = _block_get_renderable_array(_block_render_blocks(array($block)));

//Code pour afficher le block
//Peut aussi être passé à un template via theme()
print render($monBlock); 

```
