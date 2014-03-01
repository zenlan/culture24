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

//    parent::exposed_form_alter($form, $form_state);
//
//    if ($form['#id'] == 'views-exposed-form-search-collections-search-page-collections-adv') {
//
//      $this->_compile_adv_form($form);
//      //watchdog('exposed_form_alter', $form_state['input']);
//      if (isset($form_state['input']['mediaReference'])) {
//        $form['mediaReference']['#value'] = (isset($form_state['input']['webCategory']) ? $form_state['input']['mediaReference'] : 0);
//      }
//      if (isset($form['webCategory'])) {
//        $form['webCategory']['#value'] = (isset($form_state['input']['webCategory']) ? $form_state['input']['webCategory'] : 0);
//      }
//      if (isset($form['periodString'])) {
//        $form['periodString']['#value'] = (isset($form_state['input']['periodString']) ? $form_state['input']['periodString'] : 0);
//      }
//    }
  }

  function exposed_filter_applied() {
//    if (!isset($this->view->exposed_data)) {
//      $this->view->exposed_data = array();
//    }
    return parent::exposed_filter_applied();
  }

  protected function _compile_adv_form(&$form) {

//    global $_iwm_collections_filters;
//    $form[IWM_SEARCH_API_MULTI_KEYS_TOKEN]['#weight'] = 10;
//    $form['items_per_page']['#weight'] = 20;
//    $form['description']['#weight'] = 30;
//    $form['submit']['#weight'] = 40;
//    $form['reset']['#weight']  = 50;
//    $form['#limit_validation_errors'] = array();
//
//    foreach ($form['#info'] as $viewfilter => $viewvals) {
//
//      $field = str_replace('filter-', '', $viewfilter);
//      if (!isset($form[$field])) {
//
//        continue;
//      }
//      if (isset($_iwm_collections_filters[$field])) {
//
//        $varvals = $_iwm_collections_filters[$field];
//        if (isset($varvals['widget'])) {
//
//          $form[$field]['#id'] = 'iwm_collections_widget_' . $field;
//
//          switch ($varvals['widget']) {
//
//            case 'checkbox':
//
//              $form[$field]['#type'] = 'checkbox';
//              $form[$field]['#title'] = check_plain($varvals['label']);
//              break;
//
//            case 'date':
//
//              $form['#info'][$viewfilter]['label'] = check_plain($varvals['label']);
//              $form[$field]['#size'] = 10;
//              break;
//
//            case 'select':
//
//              $form['#info'][$viewfilter]['label'] = check_plain($varvals['label']);
//              $facets = iwm_collections_get_filter_arrays($field);
//              $disabled = isset($facets['error']);
//              $list = array();
//              if (count($facets[$field])) {
//
//                $list = array_combine(array_keys($facets[$field]), array_keys($facets[$field]));
//                array_unshift($list, 'any');
//              }
//              $form[$field]['#type'] = 'select';
//              unset($form[$field]['#size']);
//              $form[$field]['#options'] = ($list ? $list : array('Failed to retrieve filter keys'));
//              break;
//
//            case 'textfield':
//
//              $form['#info'][$viewfilter]['label'] = check_plain($varvals['label']);
//              if (isset($varvals['autocomplete']) && $varvals['autocomplete']) {
//
//                $form[$field]['#autocomplete_path'] = 'iwm_collections/autocomplete/' . $field;
//              }
//              break;
//          }
//        }
//      }
//    }
  }
}