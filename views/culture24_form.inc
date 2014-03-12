<?php
// $Id$

/**
 * @file
 */

/**
 * Exposed form plugin
 */
class culture24_views_plugin_exposed_form extends views_plugin_exposed_form_input_required {

  function exposed_form_validate(&$form, &$form_state) {
    return TRUE;
  }

  function exposed_form_alter(&$form, &$form_state) {

  }

  function exposed_filter_applied() {
//    if (!isset($this->view->exposed_data)) {
//      $this->view->exposed_data = array();
//    }
    return parent::exposed_filter_applied();
  }

  protected function _compile_adv_form(&$form) {

  }
}