<?php
/**
 * Disable, uninstall and then reinstall a drupal module
 * Save this file within your .drush folder, usually ~/.drush/
 **/

function reinstall_drush_command() {
  $items = array();

  $items['reinstall'] = array(
    'description' => "Disable, uninstall and then reinstall a drupal module",
    'arguments' => array(
      'module' => 'module\'s name',
    ),
    'options' => array(),
    'examples' => array(
      'drush reinstall devel',
    ),
    'aliases' => array('rei'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap at all.
  );

  return $items;
}

function reinstall_drush_help($section) {
  switch ($section) {
    case 'drush:reinstall':
     return dt("disable, uninstall and then reinstall a drupal module");
  }
}

function drush_reinstall($module_name) {
  $alias = drush_get_context('DRUSH_TARGET_SITE_ALIAS');
  drush_invoke_process($alias,'pm-disable '.$module_name);
  drush_invoke_process($alias,'pm-uninstall '.$module_name);
  drush_invoke_process($alias,'pm-enable '.$module_name);
}

