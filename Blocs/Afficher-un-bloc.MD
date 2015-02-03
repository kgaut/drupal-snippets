```php
$block = block_load('block', 1);
$variables['content']['monblock'] = _block_get_renderable_array(_block_render_blocks(array($block)));
print render($variables['content']['monblock']); 
```
