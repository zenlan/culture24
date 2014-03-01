<?php

/**
 * @file
 */

/**
 * Views query class using Culture24 API as the data source.
 */
class culture24_views_plugin_query extends views_plugin_query {

  /**
   * @var type array
   */
  var $args;

  /**
   * @var type array
   */
  var $filters;

  /**
   * Create the basic query object and fill with default values.
   */
  function init($base_table, $base_field, $options) {
    try {
      parent::init($base_table, $base_field, $options);
      $this->where = array();
    } catch (Exception $e) {
      watchdog('Culture24ViewsQuery::init' . $e->getMessage());
    }
  }

  /**
   * Generate a query and a countquery from all of the information supplied
   * to the object.
   *
   * @param $get_count
   *   Provide a countquery if this is true, otherwise provide a normal query.
   */
  function query($get_count = FALSE) {
    return;
  }

  /**
   * Let modules modify the query just prior to finalizing it.
   *
   * @param view $view
   *   The view which is executed.
   */
  function alter(&$view) {
    
  }

  function add_where($field, $value = NULL) {
    if (!isset($this->filters[$field])) {
      $this->filters[$field] = $value;
    } else {
      $this->filters[$field] .= $value;
    }
  }

  /**
   * Builds the necessary info to execute the query.
   *
   * @param view $view
   *   The view which is executed.
   */
  function build(&$view) {
    //$this->args = array();
    foreach ($view->argument as $field => $info) {
      $this->args[$field] = $info->argument;
    }
    return;
  }

  /**
   * Executes the query and fills the associated view object with according
   * values.
   *
   * Values to set: $view->result, $view->total_rows, $view->execute_time,
   * $view->pager['current_page'].
   *
   * $view->result should contain an array of objects. The array must use a
   * numeric index starting at 0.
   *
   * @param view $view
   *   The view which is executed.
   */
  function execute($view) {
    try {
      $start = microtime(TRUE);
      $tmp = $this->args;
      if (isset($this->args['uniqueID'])) {
        $entities = entity_load($this->base_table, array($this->args['uniqueID']));
        $view->result = $entities; 
      } else {
        $options = array(
            'query_type' => str_replace('c24_', '', $this->base_table) . 's',
            'limit' => 20,
        );
        $options += $this->filters;
        $c24 = new Culture24API($options);
        $rows = $c24->search();
        $view->result = entity_load($this->base_table, $rows);
        $view->total_rows = 20;
        $view->pager['current_page'] = 1;
      }
      $view->execute_time = microtime(TRUE) - $start;
    } catch (Exception $e) {
      watchdog('Culture24ViewsQuery::execute' . $e->getMessage());
      $view->result[] = $e->getMessage();
    }
  }

}
