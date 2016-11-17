<?php
/**
 * Allow to quickly enable / disable drupal production settings such as cache,
 * Devel module...
 * Save this file within your .drush folder, usually ~/.drush/
 **/


function deprod_drush_command() {
  $items = array();

  $items['deprod'] = array(
    'description' => "Set options to Development",
    'arguments' => array(),
    'arguments' => array(),
    'examples' => array(
      'drush deprod' => 'Drush will ask you question for each setting',
      'drush deprod -y' => 'Drush set everything to dev',
    ),
    'aliases' => array('dep'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );

  $items['reprod'] = array(
    'description' => "Set options to Production",
    'arguments' => array(),
    'arguments' => array(),
    'examples' => array(
      'drush reprod' => 'Drush will ask you question for each setting',
      'drush reprod -y' => 'Drush set everything to production value',
    ),
    'aliases' => array('rep'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );

  return $items;
}

function deprod_drush_help($section) {
  switch ($section) {
    case 'drush:deprod':
      return dt("Set options to Development");
    case 'drush:reprod':
      return dt("Set options to Production");
  }
}

function drush_deprod() {
  if (!drush_bootstrap_to_phase(DRUSH_BOOTSTRAP_DRUPAL_DATABASE)) {
    return drush_set_error('DRUPAL_SITE_NOT_FOUND', dt('You need to specify an alias or run this command within a drupal site.'));
  }
  $alias = drush_get_context('DRUSH_TARGET_SITE_ALIAS');

  if(is_module_installed('stage_file_proxy') && !is_module_enabled('stage_file_proxy') && drush_confirm(dt('Would you like to enable the module Stage File Proxy ?'))) {
    drush_invoke_process($alias,'pm-enable stage_file_proxy');
  }
  if(is_module_installed('devel') && !is_module_enabled('devel')) {
    if(drush_confirm(dt('Would you like to enable the module Devel ?'))) {
      drush_invoke_process($alias,'pm-enable devel');
      if(drush_confirm(dt('Would you like all user to access developer information  ?'))) {
        drush_invoke_process($alias,'role-add-perm 1 "access devel information"'); //Anonymous
        drush_invoke_process($alias,'role-add-perm 2 "access devel information"'); //Authenticated user
      }
    }
  }
  if(is_module_enabled('googleanalytics') && drush_confirm(dt('Would you like to disable the module google analytics ?'))) {
    drush_invoke_process($alias,'pm-disable googleanalytics');
  }
  if(is_module_enabled('piwik') && drush_confirm(dt('Would you like to disable the module piwik ?'))) {
    drush_invoke_process($alias,'pm-disable piwik');
  }
  if(drush_confirm(dt('Would you like display error and messages ?'))) {
    drush_invoke_process($alias,'variable-set error_level 2');
  }
  if(drush_confirm(dt('Would you like to disable "Cache pages for anonymous users" ?'))) {
    drush_invoke_process($alias,'variable-set cache 0');
  }
  if(drush_confirm(dt('Would you like to disable block cache ?'))) {
    drush_invoke_process($alias,'variable-set block_cache 0');
  }
  if(drush_confirm(dt('Would you like to disable CSS aggregation ?'))) {
    drush_invoke_process($alias,'variable-set preprocess_css 0');
  }
  if(drush_confirm(dt('Would you like to disable js aggregation ?'))) {
    drush_invoke_process($alias,'variable-set preprocess_js 0');
  }
  if(drush_confirm(dt('Would you like to disable cached pages compression ?'))) {
    drush_invoke_process($alias,'variable-set page_compression 0');
  }
}

function drush_deprod_reprod() {
  if (!drush_bootstrap_to_phase(DRUSH_BOOTSTRAP_DRUPAL_DATABASE)) {
    return drush_set_error('DRUPAL_SITE_NOT_FOUND', dt('You need to specify an alias or run this command within a drupal site.'));
  }
  $alias = drush_get_context('DRUSH_TARGET_SITE_ALIAS');

  if(is_module_enabled('stage_file_proxy') && drush_confirm(dt('Would you like to disable the module Stage File Proxy ?'))) {
    drush_invoke_process($alias,'pm-disable stage_file_proxy');
  }
  if(is_module_enabled('devel')) {
    if(drush_confirm(dt('Would you like to prevent all user to access developer information  ?'))) {
      drush_invoke_process($alias,'role-remove-perm 1 "access devel information"'); //Anonymous
      drush_invoke_process($alias,'role-remove-perm 2 "access devel information"'); //Authenticated user
    }
    if(drush_confirm(dt('Would you like to disable the module Devel ?'))) {
      drush_invoke_process($alias, 'pm-disable devel');
    }
  }
  if(is_module_installed('googleanalytics') && !is_module_enabled('google_analytics') && drush_confirm(dt('Would you like to enable the module google analytics ?'))) {
    drush_invoke_process($alias,'pm-enable googleanalytics');
  }
  if(is_module_installed('piwik') && !is_module_enabled('piwik') && drush_confirm(dt('Would you like to enable the module piwik ?'))) {
    drush_invoke_process($alias,'pm-enable piwik');
  }
  if(drush_confirm(dt('Would you like hide error and messages ?'))) {
    drush_invoke_process($alias,'variable-set error_level 0');
  }
  if(drush_confirm(dt('Would you like to enable "Cache pages for anonymous users" ?'))) {
    drush_invoke_process($alias,'variable-set cache 1');
  }
  if(drush_confirm(dt('Would you like to enable block cache ?'))) {
    drush_invoke_process($alias,'variable-set block_cache 1');
  }
  if(drush_confirm(dt('Would you like to enable CSS aggregation ?'))) {
    drush_invoke_process($alias,'variable-set preprocess_css 1');
  }
  if(drush_confirm(dt('Would you like to enable js aggregation ?'))) {
    drush_invoke_process($alias,'variable-set preprocess_js 1');
  }
  if(drush_confirm(dt('Would you like to enable cached pages compression ?'))) {
    drush_invoke_process($alias,'variable-set page_compression 1');
  }
}

function is_module_enabled($module_name) {
  $result = db_query('SELECT name, status  FROM {system} WHERE type = :type and name = :name', array(
    ':type' => 'module',
    ':name' => $module_name,
  ));
  if($result = $result->fetchObject()) {
    return (bool) $result->status;
  }
}

function is_module_installed($module_name) {
  $result = db_query('SELECT name, status  FROM {system} WHERE type = :type and name = :name', array(
    ':type' => 'module',
    ':name' => $module_name,
  ));
  if($result->fetchObject()) {
    return true;
  }
  return false;
}
