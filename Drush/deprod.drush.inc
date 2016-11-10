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
  $alias = drush_get_context('DRUSH_TARGET_SITE_ALIAS');

  if(drush_confirm(dt('Would you like to enable the module Stage File Proxy ?'))) {
    drush_invoke_process($alias,'pm-enable stage_file_proxy');
  }
  if(drush_confirm(dt('Would you like to enable the module Devel ?'))) {
    drush_invoke_process($alias,'pm-enable devel');
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
  $alias = drush_get_context('DRUSH_TARGET_SITE_ALIAS');

  if(drush_confirm(dt('Would you like to disable the module Stage File Proxy ?'))) {
    drush_invoke_process($alias,'pm-disable stage_file_proxy');
  }
  if(drush_confirm(dt('Would you like to disable the module Devel ?'))) {
    drush_invoke_process($alias,'pm-disable devel');
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
