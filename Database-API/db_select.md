#db_select

```
  $q = db_select('fd_contact','c')
    ->fields('c')
    ->condition('cid',$cid)
    ->execute();
  $r = $q->fetchAssoc();
  ```

```
  $q = db_select('fd_contact','c')
    ->fields('c')
    ->execute()
    ->fetchAllAssoc('cid');
```
