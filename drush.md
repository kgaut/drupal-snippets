#Drush

##Installation de drupal

|Commande|Résultat|
|--------|--------|
|`drush dl drupal-8.x --select --drupal-project-rename=www`|Propose les différentes versions de D8 disponibles, puis télécharge la version choisie et la place dans un dossier **www**|

##Search API
|Commande|Résultat|
|--------|--------|
|`drush @alias sapi-s`|Affiche le statut des index de recherche|
|`drush @alias sapi-c`|Vide les indexes de recherche|
|`drush @alias sapi-i`|Lance une réindexation pour l'ensemble des indexes|
|`drush @alias sapi-r`|Marque les indexes pour réindexation|
