<?php

/**
 * @file
 * Utilities for the Culture24 module.
 *
 * @ingroup Culture24
 */
function culture24_get_api_settings() {
  return variable_get('c24_api', array(
      'url' => 'http://www.culture24.org.uk/api/rest/v',
      'ver' => '1',
      'key' => '')
  );
}

function culture24_http_request($request) {
  return drupal_http_request($request);
}

/**
 * display raw Culture24 record
 *
 * @param string $machine_name
 *   Machine Name
 * @param string $id
 *   Unique identifier
 */
function culture24_debug($type = '', $id = '') {

  $list = array();
  $errors = array();
  if (empty($type)) {
    $errors[] = 'missing arg1 "$type"';
  }
  if (empty($id)) {
    $errors[] = 'missing arg2 "id"';
  }
  $info = entity_get_info($type);
  if (!$info) {
    $errors = 'unkown entity type: ' . $type;
  } else {
    try {
      $entity = culture24_load($id, $type);
      if (!is_a($entity, 'c24_entity')) {
        $errors[] = 'failed to load Culture24 entity type: ' . $type;
      } elseif (isset($entity->error)) {
        $errors[] = $entity->error;
      } else {
        $list = entity_view($type, array($entity), 'debug');
      }
    } catch (Exception $e) {
      $errors[] = $e->getMessage();
    }
  }
  $result['culture24_debug'] = array(
      '#theme' => 'item_list',
      '#items' => empty($errors) ? $list : $errors,
      '#title' => t('Culture24 Item Debug Page: @name @error', array(
          '@name' => $type,
          '@error' => (empty($errors) ? '' : ' !ERROR'),
      )),
  );
  return $result;
}

/**
 * Server ping
 *
 * @param string $url
 *   URL to ping
 * @param string $database
 *   Database name
 */
function culture24_ping_server($url) {

  $request = 'http://' . $url . (strpos($url, '?') ? '&' : '?')
          . 'q=1&limit=1&fields=uniqueID';
  if ($data = culture24_http_request_data($request)) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Log data to a file, useful for debugging
 *
 * @param various $data
 *   Data
 * @param string $prefix
 *   Prefix string
 */
function culture24_logfile($data, $prefix = 'log') {

  file_put_contents(
          variable_get('file_public_path')
          . '/tmp/culture24_' . $prefix . '_' . date('Ymd_His') . '.txt', print_r($data, TRUE)
  );
}
