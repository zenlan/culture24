<?php

/**
 * @package Culture24
 *
 */
defined('C24_API_DEBUG') or define('C24_API_DEBUG', false);
defined('C24_API_EVENTS') or define('C24_API_EVENTS', 'events');
defined('C24_API_VENUES') or define('C24_API_VENUES', 'venues');
defined('C24_API_MAX_TRIES') or define('C24_API_MAX_TRIES', 3);
define('C24_API_DATE_FORMAT_INPUT', 'd-m-Y');
define('C24_API_DATE_FORMAT_OUTPUT', 'd/m/Y');
define('C24_API_DATE_END_DEFAULT', date(C24_API_DATE_FORMAT_INPUT, time() + (7 * (24 * 3600))));

/**
 * Class that handles Culture24 requests and responses
 */
class Culture24API {

  /**
   *
   * @var string
   */
  protected $_url = '';

  /**
   *
   * @var string
   */
  protected $_key = '';

  /**
   *
   * @var string
   */
  protected $_api_version = '1';

  /**
   * @var string
   */
  protected $_message = '';

  /**
   * @var integer
   */
  protected $_attempt = 0;

  /**
   * @var boolean
   */
  protected $_error = false;

  /**
   * @var string
   */
  protected $_response = '';

  /**
   * @var integer
   */
  protected $_offset = 0;

  /**
   * @var integer
   */
  protected $_limit = 2;

  /**
   * @var string
   */
  protected $_date_start = false;

  /**
   * @var string
   */
  protected $_date_end = false;

  /**
   * @var string
   */
  protected $_date_end_default = C24_API_DATE_END_DEFAULT;

  /**
   * @var string
   */
  protected $_region = '';
  
  /**
   * @var string
   */
  protected $_country = '';

  /**
   * @var string
   */
  protected $_audience = '';

  /**
   * @var string
   */
  protected $_type = '';

  /**
   * @var string
   */
  protected $_keywords = '';

  /**
   * @var string
   */
  protected $_keyfield = '';

  /**
   * @var string
   */
  protected $_name = '';

  /**
   * @var string
   */
  protected $_venueID = '';

  /**
   * @var string
   */
  protected $_sort = '';

  /**
   * @var string
   */
  protected $_tag = '';

  /**
   * @var string
   */
  protected $_last_request = '';

  /**
   * @var string
   */
  protected $_request = '';

  /**
   * @var string
   */
  protected $_query_type = C24_API_EVENTS;

  /**
   * @var  array
   */
  protected $_data_parsed = array();

  /**
   * @var integer
   */
//  protected $_found = 0;

  /**
   * @var string
   */
  protected $_records = array();

  /**
   * @var array of Culture24Event
   */
//  protected $_objects = array();

  /**
   *
   * @var array
   */
  protected $_validation_errors = array();

  /**
   * Constructor
   * Query type defaults to events but can be overriden by options
   * @param type options
   */
  function __construct($options = array()) {
    $settings = culture24_get_api_settings();
    $this->_url = $settings['url'];
    $this->_key = $settings['key'];
    $this->_api_version = $settings['ver'];
    $this->set_elements($options['elements']);
    unset($options['elements']);
    foreach ($options as $key => $val) {
      $this->{'_' . $key} = trim($val);
    }
  }

  /**
   * Return API search request query string with data format and key
   * @return string
   */
  protected function _get_base_search_query() {
    return $this->_url . $this->_api_version . '/' . $this->_query_type . '/?format=json&key=' . $this->_key;
  }

  /**
   * Return API single record request query string with data format and key
   * @param string $id
   * @return string
   */
  protected function _get_base_id_query($id) {
    return $this->_url . $this->_api_version . '/' . $this->_query_type . '/' . $id . '/?format=json&key=' . $this->_key;
  }

  /**
   * Set important properties to empty defaults
   */
  protected function _reset() {
    $this->_message = '';
    $this->_error = FALSE;
    $this->_request = '';
    $this->_response = '';
    $this->_data_parsed = NULL;
    $this->_found = 0;
    $this->_records = array();
    $this->_objects = array();
  }

  /**
   * Fetch a single event or venue by it's uniqueID
   * @param string $id
   * @return boolean
   */
  public function fetchOneByID($id) {
    $this->_reset();
    $this->_request = $this->_get_base_id_query($id);
    $this->_request .= $this->_get_request_arg('elements');
    if ($this->_sendRequest()) {
      return $this->_data_parsed->result;
    }
    return array();
  } 

  /**
   * Fetch a set of records filtered by arguments
   * @return boolean
   */
  public function search() {
    $this->_reset();
    $this->_buildSearchQuery();
    if ($this->_sendRequest()) {
      return $this->_data_parsed->result->items;
    }
    return array();
  }

  protected function _buildSearchQuery() {
    $this->_request = $this->_get_base_search_query();
    $this->_request .= $this->_get_request_arg('limit');
    $this->_request .= $this->_get_request_arg('offset');
    $this->_request .= $this->_get_request_arg('contentTag');
    $this->_request .= $this->_get_request_arg('type');
    $this->_request .= $this->_get_request_arg('name');
    $this->_request .= $this->_get_request_arg('elements');
    $this->_request .= $this->_get_request_arg('dates');
    $this->_request .= $this->_get_request_arg('keywords');
    $this->_request .= $this->_get_request_arg('audience');
    $this->_request .= $this->_get_request_arg('venueID');
    $this->_request .= $this->_get_request_arg('sort');
  }

  /**
   * Execute a Culture24 API http request with optional re-attempts on failure
   *
   * @return boolean
   */
  protected function _sendRequest() {
    try {
      $this->_error = FALSE;
      $this->_attempt++;
      if ($this->_http_request()) {
        $this->_set_message('response', $this->_response);
        return TRUE;
      } else if ($this->_attempt === C24_API_MAX_TRIES) {
        $this->_sendRequest();
      }
    } catch (Exception $e) {
      $this->_set_error_message('exception', $e);
    }
    return FALSE;
  }

  protected function _http_request() {
    if (C24_LOG_QUERIES) {
      watchdog('Culture24', urldecode($this->_request));
    }
    $this->_last_request = $this->_request;
    $this->_response = culture24_http_request($this->_request);
    if ($this->_response->code != 200) {
      watchdog('Culture24', 'The Culture24 server responded to !$request with status code !status: !msg.', array(
          '!$request' => $this->_request,
          '!status' => $this->_response->code,
          '!msg' => $this->_response->error,
              )
      );
      $this->_set_error_message('response', $this->_response);
      return FALSE;
    }
    return $this->_parse_json();
  }

  /**
   * JSON_ERROR handling only works with PHP >= 5.4.0
   *
   * @return string
   */
  protected function _parse_json() {
    try {
      $this->_data_parsed = json_decode($this->_response->data);
//      switch (json_last_error()) {
//        case JSON_ERROR_DEPTH:
//          $this->_set_error_message('json', JSON_ERROR_DEPTH . ': Maximum stack depth exceeded');
//          break;
//        case JSON_ERROR_CTRL_CHAR:
//          $this->_set_error_message('json', JSON_ERROR_CTRL_CHAR . ': Unexpected control character found');
//          break;
//        case JSON_ERROR_SYNTAX:
//          $this->_set_error_message('json', JSON_ERROR_SYNTAX . ': Syntax error, malformed JSON');
//          break;
//        case JSON_ERROR_STATE_MISMATCH:
//          $this->_set_error_message('json', JSON_ERROR_STATE_MISMATCH . ': Invalid or malformed JSON');
//          break;
//        case JSON_ERROR_UTF8:
//          $this->_set_error_message('json', JSON_ERROR_UTF8 . ': Malformed UTF-8 characters, possibly incorrectly encoded');
//          break;
//        case JSON_ERROR_NONE:
//        default:
//          break;
//      }
    } catch (Exception $e) {
      $this->_set_error_message('exception', $e);
      return FALSE;
    }
    return TRUE;
  }

  /**
   * Return a formatted query argument string for a given key
   * @param string $name
   * @return string
   */
  protected function _get_request_arg($name) {
    $result = '';
    switch ($name) {
      case 'dates':
        $dates = $this->get_dates();
        $result = (empty($dates) ? '' : '&q.date.range=' . $dates);
        break;
      case 'limit':
        $result = '&limit=' . $this->_limit;
        break;
      case 'offset':
        $result = '&offset=' . $this->_offset;
        break;
      case 'contentTag':
        if (!empty($this->_contentTag)) {
          $tags = $this->_contentTag . ',';
        }
        $tags = str_replace(' ', '+', trim($tags, ','));
        $result = '&q.contentTag=' . $tags;
        break;
      case 'type':
        if (!empty($this->_type)) {
          $result = '&q.type=' . str_replace(' ', '+', $this->_type);
        }
        break;
      case 'name':
        if (!empty($this->_name)) {
          $result = '&q.name=' . $this->_name;
        }
        break;
      case 'venueID':
        if (!empty($this->_venueID)) {
          $result = '&q.venueID=' . $this->_venueID;
        }
        break;
      case 'audience':
        if (!empty($this->_audience)) {
          $result = '&q.audience=' . str_replace(' ', '+', $this->_audience);
        }
        break;
      case 'sort':
        $result = '&sort=' . $this->_sort;
        break;
      case 'keywords':
        if (!empty($this->_keywords)) {
          $keywords = str_replace(' ', '+', $this->_keywords);
          if (empty($this->_keyfield)) {
            $key = 'q';
          } else {
            $key = 'q.' . $this->_keyfield;
          }
          $result = '&' . $key . '=' . $keywords;
        }
        break;
//      case 'elements':
//        $elems = $this->_get_elements();
//        $result = (empty($elems) ? '' : '&elements=' . $elems);
//        break;
      default:
        $result = '';
        break;
    }
    return $result;
  }

  /**
   * Format date range arguments for query string
   * Empty date-start defaults to today
   * Empty date-end defaults to C24_API_DATE_END_DEFAULT, override in constructor
   *
   * @return string
   */
  public function get_dates() {
    if ($this->_date_start && $this->_date_end) {
      $date_start = date(C24_API_DATE_FORMAT_OUTPUT, strtotime($this->_date_start));
      $date_end = date(C24_API_DATE_FORMAT_OUTPUT, strtotime($this->_date_end));
      return $date_start . ',' . $date_end;
    } else if ($this->_date_start) {
      //$date = strtotime($this->_date_start);
      $this->_date_end = $this->_date_end_default;
      return $this->get_dates();
    } else if ($this->_date_end) {
      $this->_date_start = date(C24_API_DATE_FORMAT_INPUT);
      return $this->get_dates();
    } else {
      return '';
    }
  }

  /**
   * Return default data elements if not overriden by options/setter
   * @return string
   */
//  protected function _get_elements() {
//    if (!empty($this->_elements)) {
//      return $this->_elements;
//    }
//    if ($this->_query_type == C24_API_EVENTS) {
//      return Culture24Event::get_default_data_elements();
//    } else if ($this->_query_type == C24_API_VENUES) {
//      return Culture24Venue::get_default_data_elements();
//    }
//  }

  /**
   * Return an array of class-specific objects
   * @return array
   */
//  protected function _build_record_objects() {
//    $result = array();
//    if ($this->_query_type == C24_API_EVENTS) {
//      $result = $this->_build_event_objects();
//      //$this->_store_event_validation_errors();
//    } else if ($this->_query_type == C24_API_VENUES) {
//      $result = $this->_build_venue_objects();
//    }
//    return $result;
//  }

  /**
   * Build an array of event objects
   * @return array
   */
//  protected function _build_event_objects() {
//    $result = array();
//    foreach ($this->_records as $k => $v) {
//      $event = new Culture24Event($v);
////      $errors = $event->get_validation_errors();
////      if (!empty($errors)) {
////        $this->_validation_errors[$event->get_property('eventID')] = $errors;
////      }
//      $result[] = $event;
//    }
//    return $result;
//  }

  /**
   * Build an array of venue objects
   * @return array
   */
//  protected function _build_venue_objects() {
//    $result = array();
//    foreach ($this->_records as $v) {
//      $result[$v->uniqueID] = new Culture24Venue($v);
//    }
//    return $result;
//  }

  /**
   *
   * @param string $val
   * @param string $field
   */
  public function set_keywords($val, $field = '') {
    $this->_keywords = trim($val);
    $this->_keyfield = $field;
  }

  /**
   *
   * @param string $val
   */
  public function set_date_start($val) {
    $this->_date_start = trim($val);
  }

  /**
   *
   * @param string $val
   */
  public function set_date_end($val) {
    $this->_date_end = trim($val);
  }

  /**
   *
   * @param string $val
   */
  public function set_limit($val) {
    $this->_limit = trim($val);
  }

  /**
   *
   * @param string $val
   */
  public function set_tag($val) {
    $this->_tag = trim($val);
  }

  /**
   *
   * @param string $val
   */
  public function set_type($val) {
    $this->_type = trim($val);
  }

  /**
   *
   * @param string $val
   */
  public function set_sort($val) {
    $this->_sort = trim($val);
  }

  /**
   *
   * @param string $val
   */
  public function set_region($val) {
    $this->_region = trim($val);
  }

  /**
   *
   * @param string $val
   */
  public function set_audience($val) {
    $this->_audience = trim($val);
  }

  /**
   *
   * @param string $val
   */
  public function set_name($val) {
    $this->_name = trim($val);
  }

  /**
   *
   * @param string $val
   */
  public function set_offset($val = 0) {
    $this->_offset = intval($val);
  }

  /**
   * Sets data elements argument
   * Adds uniqueID if not found in list
   * @param string $val
   */
  public function set_elements($val) {
    $val = trim($val);
    if (!empty($val) && strpos($val, 'uniqueID') === FALSE) {
      $val = 'uniqueID,' . $val;
    }
    $this->_elements = $val;
  }

  /**
   * Total number of query results (not records fetched)
   * @return boolean
   */
//  public function get_found() {
//    return $this->_found;
//  }

  /**
   * Array of parsed records
   * @return array
   */
//  public function get_records() {
//    return $this->_records;
//  }

  /**
   * Assigns an array of records
   * Uses offset and limit to reduce objects built
   * @param type $records
   * @param type $offset
   * @param type $limit
   */
//  public function set_records($records, $offset = 0, $limit = 0) {
//    if ($offset || $limit) {
//      $this->_records = array_slice($records, $offset, $limit);
//    } else {
//      $this->_records = $records;
//    }
//    $this->_objects = $this->_build_record_objects();
//  }

  /**
   * Return array of class objects
   * @return array
   */
//  public function get_objects() {
//    return $this->_objects;
//  }

  /**
   * Returns last executed API request query string
   * @return string
   */
  public function get_last_request() {
    return $this->_last_request;
  }

  /**
   * Returns the last message set by a request
   * @return string
   */
  public function get_message() {
    return $this->_message;
  }

  /**
   * Returns the last error status set by a request
   * @return string
   */
  public function get_error() {
    return $this->_error;
  }

  /**
   * Sets the current message using data arg according to type
   * @param string $type
   * @param object $data
   */
  protected function _set_message($type, $data) {
    switch ($type) {
      case 'response':
//        if ($code = wp_remote_retrieve_response_code($data)) {
//          $this->_message = wp_remote_retrieve_response_code($data)
//                  . ': ' . wp_remote_retrieve_response_message($data);
//        } else if (isset($data->errors)) {
//          if (isset($data->errors['http_request_failed'])) {
//            $this->_message = 'Despite ' . $this->_attempt . ' attempts, Culture24 was unable to fulfill the request, please try again later.';
//          } else {
//            $this->_message = print_r($data->errors, 1);
//          }
//        }
        break;
      default:
        $this->_message = '';
        break;
    }
  }

  /**
   * Sets the current error message using data arg according to type
   * @param string $type
   * @param object $data
   */
  protected function _set_error_message($type, $data) {
    switch ($type) {
      case 'result':
        $this->_message = $data->errorCode . ': ' . $data->errorMessage;
        break;
      case 'exception':
        $this->_message = $data->getCode() . ': ' . $data->getMessage();
        break;
      case 'json':
      default:
        $this->_message = $data;
        break;
    }
    $this->_error = TRUE;
  }

  /**
   *
   * Validation was useful in the early days of the API
   *
   * @return array
   */
  public function get_validation_errors() {
    return $this->_validation_errors;
  }

//  protected function _store_event_validation_errors() {
    //delete_transient('c24_event_validation_errors');
//    if ($transient = get_transient('c24_event_validation_errors')) {
//      $cache = array_merge($transient, $this->_validation_errors);
//    } else {
//      $cache = $this->_validation_errors;
//    }
//    return set_transient('c24_event_validation_errors', $cache, 7 * (60 * 60 * 24));
//  }

}
