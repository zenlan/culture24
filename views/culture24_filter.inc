<?php

/**
 * @file
 */
class culture24_views_handler_filter extends views_handler_filter {

  var $lufunc;

  function init(&$view, &$options) {
    parent::init($view, $options);
    switch ($this->field) {
      case 'region':
      case 'audience':
      case 'type':
      case 'country':
        $this->lufunc = 'culture24_' . $this->field;
    }
  }

  function can_expose() {
    return TRUE;
  }

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * Options form subform for setting options.
   *
   * This should be overridden by all child classes and it must
   * define $form['value']
   *
   * @see options_form()
   */
  function value_form(&$form, &$form_state) {
    $form['value'] = array();
    switch ($this->field) {
      case 'region':
      case 'country':
      case 'audience':
      case 'type':
        $form['value'] = array(
            '#type' => 'select',
            '#title' => t($this->definition['label']),
            '#default_value' => '',
            '#options' => call_user_func($this->lufunc),
        );
        break;
    }
    return;
  }

  /**
   * Validate the options form.
   */
  function value_validate($form, &$form_state) {
    return TRUE;
  }

  /**
   * Perform any necessary changes to the form values prior to storage.
   * There is no need for this function to actually store the data.
   */
  function value_submit($form, &$form_state) {
    return;
  }

  function query() {

    $values = '';
    foreach ($this->value as $val) {
      switch ($this->field) {
        case 'region':
        case 'audience':
        case 'type':
        case 'country':
          $values .= call_user_func_array($this->lufunc, array($val));
      }
    }
    $values = rtrim($values, ',');
    $this->query->add_where($this->real_field, rtrim($values, ','));
    return;
  }

}
