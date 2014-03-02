<?php

/**
 * @file
 */

/**
 *
 * implements hook_views_plugin
 */
function culture24_views_plugins() {
  $module_path = drupal_get_path('module', 'culture24');
  $views_path = drupal_get_path('module', 'views');
  return array(
      'module' => 'culture24',
      'exposed_form' => array(
          'parent' => array(
              'no ui' => TRUE,
              'handler' => 'views_plugin_exposed_form_input_required',
              'parent' => '',
          ),
          'c24_search_event' => array(
              'module' => 'culture24',
              'title' => t('Culture24 Event Search'),
              'help' => t('Culture24 Event Search'),
              'handler' => 'culture24_views_plugin_exposed_form',
              'uses options' => TRUE,
              'help topic' => '',
              'path' => $module_path . '/views',
              'file' => 'culture24_form.inc',
              'theme path' => $module_path . '/theme',
              'theme file' => 'culture24.theme.inc',
          ),
          'c24_search_venue' => array(
              'module' => 'culture24',
              'title' => t('Culture24 Venue Search'),
              'help' => t('Culture24 Venue Search'),
              'handler' => 'culture24_views_plugin_exposed_form',
              'uses options' => TRUE,
              'help topic' => '',
              'path' => $module_path . '/views',
              'file' => 'culture24_form.inc',
              'theme path' => $module_path . '/theme',
              'theme file' => 'culture24.theme.inc',
          ),
      ),
      'query' => array(
          'c24_query' => array(
              'title' => t('Culture24 Query'),
              'help' => t('Query will be generated and run using the Culture24 API.'),
              'handler' => 'culture24_views_plugin_query',
              'path' => $module_path . '/views',
              'file' => 'culture24_query.inc',
          ),
      ),
  );
}

/**
 * implements hook_views_data
 */
function culture24_views_data() {

  $data['c24_event']['table']['group'] = t('Culture24');
  $data['c24_event']['table']['base'] = array(
      'field' => 'uniqueID',
      'title' => t('Culture24 Event'),
      'help' => t("Culture24 Help"),
      'query class' => 'c24_query',
  );
  $propsE = entity_get_all_property_info('c24_event');
  foreach ($propsE as $k => $v) {
    $data['c24_event'][$k] = array(
        'title' => t($k),
        'help' => t($k),
        'field' => array(
            'handler' => 'culture24_views_handler_field',
            'click sortable' => FALSE,
            'cardinality' => $v['cardinality'], 
        )
    );
  }
  $data['c24_event']['uniqueID']['filter'] = array(
      'handler' => 'culture24_views_handler_filter',
      'label' => 'uniqueID',
  );
  $data['c24_event']['uniqueID']['argument'] = array(
      'handler' => 'culture24_views_handler_argument',
  );

  $data['c24_event']['name']['filter'] = array(
      'handler' => 'culture24_views_handler_filter',
      'label' => t('Name'),
  );
  $data['c24_event']['audience']['filter'] = array(
      'handler' => 'culture24_views_handler_filter',
      'label' => t('Audience'),
  );
  $data['c24_event']['type']['filter'] = array(
      'handler' => 'culture24_views_handler_filter',
      'label' => t('Type'),
  );
  $data['c24_event']['contentTag']['filter'] = array(
      'handler' => 'culture24_views_handler_filter',
      'label' => t('Tags'),
  );
  $data['c24_event']['venueID']['filter'] = array(
      'handler' => 'culture24_views_handler_filter',
      'label' => t('Venue'),
  );

  /**
   * contentTag alias 'region'
   */
  $data['c24_event']['region']['filter'] = array(
      'handler' => 'culture24_views_handler_filter',
      'label' => t('Region'),
      'title' => t('region'),
      'help' => t('region'),
      'real field' => 'contentTag',
  );
  /**
   * contentTag alias 'country'
   */
  $data['c24_event']['country']['filter'] = array(
      'handler' => 'culture24_views_handler_filter',
      'label' => t('Country'),
      'title' => t('country'),
      'help' => t('country'),
      'real field' => 'contentTag',
  );

  $data['c24_venue']['table']['group'] = t('Culture24');
  $data['c24_venue']['table']['base'] = array(
      'field' => 'uniqueID',
      'title' => t('Culture24 Venue'),
      'help' => t("Culture24 Help"),
      'query class' => 'c24_query',
  );
  $propsV = entity_get_all_property_info('c24_venue');
  foreach ($propsV as $k => $v) {

    $data['c24_venue'][$k] = array(
        'title' => t($k),
        'help' => t($k),
        'field' => array(
            'handler' => 'culture24_views_handler_field',
            'click sortable' => FALSE,
        )
    );
  }
  $data['c24_venue']['uniqueID']['filter'] = array(
      'handler' => 'culture24_views_handler_filter',
      'label' => 'uniqueID',
  );
  $data['c24_venue']['uniqueID']['argument'] = array(
      'handler' => 'culture24_views_handler_argument',
  );

  $data['c24_venue']['name']['filter'] = array(
      'handler' => 'culture24_views_handler_filter',
      'label' => 'Name',
  );

  return $data;
}

function culture24_field_cardinality($field) {

  $multi = array(
      'type',
      'contentTag',
      'link',
      'url',
      'charges',
      'instance',
      'audience',
      'otherNames',
      'type',
      'openingHours',
      'discounts',
      'travelDirections',
      'facilitiesInformation',
      'facility',
      'service',
      'collections',
  );
  if (in_array($field, $multi)) {
    return TRUE;
  }
  return FALSE;
}
