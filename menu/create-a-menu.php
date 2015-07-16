<?php

$menu = array (
  'menu_name' => 'menu_test_one',
  'title' => 'My Menu One',
  'description' => 'Lorem Ipsum',
),

$exists = db_query("SELECT title FROM {menu_custom} WHERE menu_name=:menu_name", array(':menu_name' => $menu['menu_name']))->fetchField();
if (!$exists) {
  menu_save($menu);
}
