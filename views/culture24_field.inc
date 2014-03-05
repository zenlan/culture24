<?php

/**
 * @file
 */
class culture24_views_handler_field extends views_handler_field {

  /**
   * Does the field supports multiple field values.
   *
   * @var bool
   */
  public $multiple;

  /**
   * Store the field information.
   *
   * @var array
   */
  public $field_info = array();

  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->field_alias = $this->field;
//    $this->options['alter']['make_list'] = FALSE;
//    if ($this->definition['cardinality'] == FIELD_CARDINALITY_UNLIMITED) {
//      $this->multiple = TRUE;
//      // If "Display all values in the same row" is FALSE, then we always limit
//      // in order to show a single unique value per row.
//      if (!isset($this->options['group_rows']) || $this->options['group_rows']) {
//        $this->limit_values = TRUE;
//      }
//      $this->options['alter']['make_list'] = TRUE;
//      $this->options['multi_type'] = 'ol';//'separator';
//      $this->options['separator'] = ', ';
//      $this->options['group_rows'] = TRUE;
//    }
  }

  /**
   * Determine if this field can allow advanced rendering.
   *
   * Fields can set this to FALSE if they do not wish to allow
   * token based rewriting or link-making.
   */
//  function allow_advanced_render() {
//    return TRUE;
//  }
//  function option_definition() {
//    return parent::option_definition();
//  }
//  function options_form(&$form, &$form_state) {
//    parent::options_form($form, $form_state);
//    if ($this->multiple) {
//      $this->multiple_options_form($form, $form_state);
//    }
//  }

  /**
   * Provide options for multiple value fields.
   */
//  function multiple_options_form(&$form, &$form_state) {
//
//    $tmp = 1;
//    $form['multiple_field_settings'] = array(
//        '#type' => 'fieldset',
//        '#title' => t('Multiple field settings'),
//        '#collapsible' => TRUE,
//        '#collapsed' => TRUE,
//        '#weight' => 5,
//    );
//
//    $form['group_rows'] = array(
//        '#title' => t('Display all values in the same row'),
//        '#type' => 'checkbox',
//        '#default_value' => $this->options['group_rows'],
//        '#description' => t('If checked, multiple values for this field will be shown in the same row. If not checked, each value in this field will create a new row. If using group by, please make sure to group by "Entity ID" for this setting to have any effect.'),
//        '#fieldset' => 'multiple_field_settings',
//    );
//
//    // Make the string translatable by keeping it as a whole rather than
//    // translating prefix and suffix separately.
//    list($prefix, $suffix) = explode('@count', t('Display @count value(s)'));
//
//    if ($this->definition['cardinality'] == FIELD_CARDINALITY_UNLIMITED) {
//      $type = 'textfield';
//      $options = NULL;
//      $size = 5;
//    } else {
//      $type = 'select';
//      $options = drupal_map_assoc(range(1, $this->definition['cardinality']));
//      $size = 1;
//    }
//    $form['multi_type'] = array(
//        '#type' => 'radios',
//        '#title' => t('Display type'),
//        '#options' => array(
//            'ul' => t('Unordered list'),
//            'ol' => t('Ordered list'),
//            'separator' => t('Simple separator'),
//        ),
//        '#dependency' => array('edit-options-group-rows' => array(TRUE)),
//        '#default_value' => $this->options['multi_type'],
//        '#fieldset' => 'multiple_field_settings',
//    );
//
//    $form['separator'] = array(
//        '#type' => 'textfield',
//        '#title' => t('Separator'),
//        '#default_value' => $this->options['separator'],
//        '#dependency' => array(
//            'radio:options[multi_type]' => array('separator'),
//            'edit-options-group-rows' => array(TRUE),
//        ),
//        '#dependency_count' => 2,
//        '#fieldset' => 'multiple_field_settings',
//    );
//  }
//
//  function options_submit(&$form, &$form_state) {
//    parent::options_submit($form, $form_state);
//  }

//  function get_value($values, $field = NULL) {
//
//    if (isset($values->{$this->field_alias})) {
//      return $values->{$this->field_alias};
//    }
//    return '';
//  }

  function query() {
    if (!isset($this->field_alias)) {
      $this->field_alias = $this->real_field;
    }
  }

//  function get_items($values) {
//    $field = parent::get_value($values);
//    return (is_array($field) ? $field : array($field));
//  }

//  function render_item($count, $item) {
//    return render($item);
//  }

//  function render_items($items) {
//    if (!$this->options['group_rows']) {
//      return implode('', $items);
//    }
//  }

//  function render_items($items) {
//    if (!empty($items)) {
//      if (!$this->options['group_rows']) {
//        return implode('', $items);
//      }
//      else if ($this->options['multi_type'] == 'separator') {
//        return implode(filter_xss_admin($this->options['separator']), $items);
//      } 
//      else if ($this->options['multi_type'] == 'ol' || $this->options['multi_type'] == 'ul') {
//        return theme('item_list', array(
//            'items' => $items,
//            'title' => NULL,
//            'type' => $this->options['multi_type']
//        ));
//      }
//      else {
//        return implode(', ', $items);
//      }
//    }
//  }
}
