#db_select

##Exemples basiques
```php
$q = db_select('fd_contact','c')
  ->fields('c')
  ->condition('cid',$cid)
  ->execute();
$r = $q->fetchAssoc();
  ```

```php
$q = db_select('fd_contact','c')
  ->fields('c')
  ->execute()
  ->fetchAllAssoc('cid');
```

##Jointure
```php
$q = db_select('node','n');
$q->join('field_data_field_logo','l','l.entity_id = n.nid AND l.entity_type = :node AND l.deleted= :deleted',array(
  ':node'=>'node',
  ':deleted'=>0,
));

$nodes = $q->fields('n',array('nid','title'))
  ->fields('l',array('field_logo_fid'))
  ->condition('n.status',1)
  ->execute()
  ->fetchAllAssoc('nid');
```