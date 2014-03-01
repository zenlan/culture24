<?php

/**
 * @file
 * Admin page callbacks for the Culture24 module.
 *
 * @ingroup Culture24
 */

/**
 * Culture24 settings management form
 * 
 * @param type $form
 * @param type $form_state
 * @return string
 */
function culture24_settings_form($form, &$form_state) {

//  $info = entity_get_info('c24_event');
//  $props = entity_get_all_property_info('c24_event');
//  $result = entity_create('c24_event', array());    
//  $result = entity_load('c24_event', array('EVENT467774'));  
  
  $settings = culture24_get_api_settings();
  $form['#tree'] = TRUE;
  $form['#title'] = t('Settings');
  $form['c24_api']['url'] = array(
      '#type' => 'textfield',
      '#title' => t('API URL'),
      '#required' => TRUE,
      '#default_value' => $settings['url'],
  );
  $form['c24_api']['ver'] = array(
      '#type' => 'textfield',
      '#title' => t('Version'),
      '#required' => TRUE,
      '#default_value' => $settings['ver'],
  );
  $form['c24_api']['key'] = array(
      '#type' => 'textfield',
      '#title' => t('Key'),
      '#required' => TRUE,
      '#default_value' => $settings['key'],
  );
  return system_settings_form($form);
}

/**
 * form submit
 */
function culture24_settings_form_submit(array $form, array &$form_state) {
  variable_set('c24_url', $form_state['input']['api']['url']);
  variable_set('c24_ver', $form_state['input']['api']['ver']);
  variable_set('c24_key', $form_state['input']['api']['key']);
}
