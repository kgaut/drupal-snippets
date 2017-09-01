# Attribut States

## Exemple sur un élément radio

Dans l'exemple suivant, le champ texte **Content comment ?** ne s'affichera et ne sera visible et obligatoire que si la personne à sélectionné **oui** au champ radio **content ?** 

```php
$form['content'] = array(
  '#type' => 'radios',
  '#title' => t('Je suis content ?'),
  '#options'=>array('N'=>'Non','O'=>'Oui'),
  '#required' => TRUE,
);

$form['content_comment'] = array(
  '#type' => 'textfield',
  '#title' => t('Content comment ???'),
  '#required' => FALSE,
  '#states' => array(
    'required' => array(
      ':input[name="content"]' => array('value' => 'O'),
    ),
    'visible' => array(
      ':input[name="content"]' => array('value' => 'O'),
    ),
  )
);
```


## States sur une checkbox unique

Ici, le champ field_user_name ne sera obligatoire que si le champ **field_name_enable** de type checkbox  est coché.

```php
$form['field_user_name']['#states'] = array(
  'required' => array(
    ':input[name="field_name_enable"]' => array('checked' => TRUE),
  ),
);
```

Autre exemple :

```php
  $form['twitter_post_add_tracking_code'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add tracking code'),
    '#default_value' => variable_get('twitter_post_add_tracking_code', 0),
  );
  //Le champ qui suit ne sera visible que si le champs précédant est coché
  //cela grâce à l'option #states
  $form['twitter_post_add_tracking_code_utm_medium'] = array(
    '#type' => 'textfield',
    '#title' => t('Campaign Medium  (utm_medium)'),
    '#maxlength' => 140,
    '#default_value' => variable_get('twitter_post_add_tracking_code_utm_medium', ''),
    '#states' => array(
      //À noter, le required ne fera qu'ajouter une asterisque rouge, aucun test ne sera
      //effectué côté serveur. (merci @DuaelFr)
      'required' => array(
        ':input[name="twitter_post_add_tracking_code"]' => array('checked'=>true)
      ),
      'visible' => array(
        ':input[name="twitter_post_add_tracking_code"]' => array('checked'=>true)
      ),
    ),
  );
```
