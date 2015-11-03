#Création d'un vocabulaire et de termes
```php
  $voc_name = "Nom du vocabulaire";
  $voc_desc = "Description du vocabulaire";
  $voc_machine_name = "Nom du vocabulaire";

  $vocabulary = new stdClass();
  $vocabulary->name = $voc_name;
  $vocabulary->description = $voc_desc;
  $vocabulary->machine_name = $voc_machine_name;
  taxonomy_vocabulary_save($vocabulary);

  $vocabulary = taxonomy_vocabulary_machine_name_load($voc_machine_name);

  $terms = array(
    'Term 1',
    'Term 2',
    'Term 3',
  );

  foreach($terms as $key => $term) {
    $new_term = new stdClass();
    $new_term->name = $term;
    $new_term->weight = $key;
    $new_term->description = '';
    $new_term->vid = $vocabulary->vid;
    taxonomy_term_save($new_term);
  }
```
