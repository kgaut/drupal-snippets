```php
  if (!in_array('slide_document', node_type_get_names())) {
    //get abstract content type
    $type = slides_content_type_get_type();   
    $type["type"] = 'nom_machine'; 
    $type["name"] = st('Nom du type de contenu');
    $type["disabled"] = 0; //si inactif

    $type = node_type_set_defaults($type);
    node_type_save($type);
    node_add_body_field($type, $label = 'Nom du champs Body');
    //desactivation des commentaires
    variable_set('comment_slide_document', 0);
  }  
  ```
