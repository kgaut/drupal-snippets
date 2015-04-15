#Exemple mini formulaire de contact
 
```php
function fd_contact($form, &$form_state) {
  $form['sexe'] = array(
    '#type' => 'radios',
    '#options' => array(
      'F' => t('Une Femme'),
      'H' => t('Un Homme'),
    ),
    '#title' => t('Vous êtes'),
    '#ajax' => array(
      'callback' => 'fd_contact_sexe_ajax_callback',
      'wrapper' => 'lastname-wrapper',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['lastname'] = array(
    '#prefix' => '<div id="lastname-wrapper">',
    '#suffix' => '</div>',
    '#type' => 'textfield',
    '#title' => t('Votre nom'),
    '#required' => TRUE,
  );

  if(isset($form_state['values']['sexe']) && $form_state['values']['sexe'] === 'F') {
    $form['lastname']['#title'] = t('Votre nom marital');
  }


  $form['birthname'] = array(
    '#type' => 'textfield',
    '#title' => t('Votre nom de jeune fille'),
    '#states' => array(
      'required' => array(
        ':input[name="sexe"]' => array('value'=>'F')
      ),
      'visible' => array(
        ':input[name="sexe"]' => array('value'=>'F')
      ),
    ),
  );
  $form['firstname'] = array(
    '#type' => 'textfield',
    '#title' => t('Votre prenom'),
  );
  $form['cle_secrete'] = array(
    '#type' => 'value',
    '#value' => rand(),
  );
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Votre email'),
    '#required' => TRUE,
    '#element_validate' => array('fd_contact_email_validate'),
  );
  $form['message'] = array(
    '#type' => 'textarea',
    '#title' => t('Votre message'),
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Zoou'),
  );

  return $form;
}

function fd_contact_sexe_ajax_callback($form,&$form_state) {
  return  $form['lastname'];
}

function fd_contact_email_validate($element, &$form_state) {
  if(!valid_email_address($element["#value"])) {
    form_error($element, t('@email ne semble pas être une addresse de courriel valide', array('@email' => t($element['#value']))));
  }
}

function fd_contact_validate($form,&$form_state) {
  if(strlen($form_state['values']['message']) < 20) {
    form_set_error('message','Votre message doit faire au minimum 20 caractères');
  }
}

function fd_contact_submit($form,&$form_state) {
  dpm($form_state);
}
```