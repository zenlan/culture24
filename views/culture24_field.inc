<?php
/**
 * @file
 */

class culture24_views_handler_field extends views_handler_field {

  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->field_alias = $this->field;
  }

  function option_definition() {
    return parent::option_definition();
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function get_value($values) {

    if (isset($values->{$this->field_alias})) {

      return $values->{$this->field_alias};
    }
    return '';
  }

  function query() {
    if (!isset($this->field_alias)) {
      $this->field_alias = $this->real_field;
    }
  }
}
