#Attribut States

##Exemple sur un élément radio

Dans l'exemple suivant, le champ texte **Content comment ?** ne s'affichera et ne sera visible et obligatoire que si la personne à sélectionné **oui** au champ radio **content ?** 

```php
$form['content'] = array(
  '#type' => 'radios',
  '#title' => t('Je suis content ?'),
  '#options'=>array('NON'=>'Non','OUI'=>'Oui'),
  '#required' => TRUE,
);

$form['content_comment'] = array(
  '#type' => 'textfield',
  '#title' => t('Content comment ???'),
  '#required' => FALSE,
  '#states' => array(
    'required' => array(
      ':input[name="content"]' => array('value' => 'oui'),
    ),
    'visible' => array(
      ':input[name="content"]' => array('value' => 'oui'),
    ),
  )
);
```

