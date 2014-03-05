<?php

/**
 * @file
 */

/**
 * Implements hook_views_default_views().
 */
function culture24_views_default_views() {
  $view = new view();
  $view->name = 'culture24_event';
  $view->description = '';
  $view->tag = 'Culture24';
  $view->base_table = 'c24_event';
  $view->human_name = 'Culture24 Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Culture24 Event';
  $handler->display->display_options['css_class'] = 'culture24 culture24-event';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
      'place' => 'place',
      'addressStreet' => 'addressStreet',
      'addressTown' => 'addressTown',
      'addressCounty' => 'addressCounty',
      'addressPostcode' => 'addressPostcode',
      'addressCountry' => 'addressCountry',
      'contentTag' => 'contentTag',
  );
  $handler->display->display_options['row_options']['separator'] = ', ';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Culture24: uniqueID */
  $handler->display->display_options['fields']['uniqueID_1']['id'] = 'uniqueID_1';
  $handler->display->display_options['fields']['uniqueID_1']['table'] = 'c24_event';
  $handler->display->display_options['fields']['uniqueID_1']['field'] = 'uniqueID';
  /* Contextual filter: Culture24: uniqueID */
  $handler->display->display_options['arguments']['uniqueID']['id'] = 'uniqueID';
  $handler->display->display_options['arguments']['uniqueID']['table'] = 'c24_event';
  $handler->display->display_options['arguments']['uniqueID']['field'] = 'uniqueID';
  $handler->display->display_options['arguments']['uniqueID']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uniqueID']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uniqueID']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uniqueID']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uniqueID']['summary_options']['items_per_page'] = '25';

  /* Display: Event Page */
  $handler = $view->new_display('page', 'Event Page', 'c24_page_event_detail');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Culture24 Event';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
      'place' => 'place',
      'addressStreet' => 'addressStreet',
      'addressTown' => 'addressTown',
      'addressCounty' => 'addressCounty',
      'addressPostcode' => 'addressPostcode',
      'addressCountry' => 'addressCountry',
  );
  $handler->display->display_options['row_options']['separator'] = ', ';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Culture24: uniqueID */
  $handler->display->display_options['fields']['uniqueID_1']['id'] = 'uniqueID_1';
  $handler->display->display_options['fields']['uniqueID_1']['table'] = 'c24_event';
  $handler->display->display_options['fields']['uniqueID_1']['field'] = 'uniqueID';
  /* Field: Culture24: name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'c24_event';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Culture24: place */
  $handler->display->display_options['fields']['place']['id'] = 'place';
  $handler->display->display_options['fields']['place']['table'] = 'c24_event';
  $handler->display->display_options['fields']['place']['field'] = 'place';
  $handler->display->display_options['fields']['place']['label'] = '';
  $handler->display->display_options['fields']['place']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressStreet */
  $handler->display->display_options['fields']['addressStreet']['id'] = 'addressStreet';
  $handler->display->display_options['fields']['addressStreet']['table'] = 'c24_event';
  $handler->display->display_options['fields']['addressStreet']['field'] = 'addressStreet';
  $handler->display->display_options['fields']['addressStreet']['label'] = '';
  $handler->display->display_options['fields']['addressStreet']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressTown */
  $handler->display->display_options['fields']['addressTown']['id'] = 'addressTown';
  $handler->display->display_options['fields']['addressTown']['table'] = 'c24_event';
  $handler->display->display_options['fields']['addressTown']['field'] = 'addressTown';
  $handler->display->display_options['fields']['addressTown']['label'] = '';
  $handler->display->display_options['fields']['addressTown']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressCounty */
  $handler->display->display_options['fields']['addressCounty']['id'] = 'addressCounty';
  $handler->display->display_options['fields']['addressCounty']['table'] = 'c24_event';
  $handler->display->display_options['fields']['addressCounty']['field'] = 'addressCounty';
  $handler->display->display_options['fields']['addressCounty']['label'] = '';
  $handler->display->display_options['fields']['addressCounty']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressPostcode */
  $handler->display->display_options['fields']['addressPostcode']['id'] = 'addressPostcode';
  $handler->display->display_options['fields']['addressPostcode']['table'] = 'c24_event';
  $handler->display->display_options['fields']['addressPostcode']['field'] = 'addressPostcode';
  $handler->display->display_options['fields']['addressPostcode']['label'] = '';
  $handler->display->display_options['fields']['addressPostcode']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressCountry */
  $handler->display->display_options['fields']['addressCountry']['id'] = 'addressCountry';
  $handler->display->display_options['fields']['addressCountry']['table'] = 'c24_event';
  $handler->display->display_options['fields']['addressCountry']['field'] = 'addressCountry';
  $handler->display->display_options['fields']['addressCountry']['label'] = '';
  $handler->display->display_options['fields']['addressCountry']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'culture24/event/%';

  /* Display: Search Page */
  $handler = $view->new_display('page', 'Search Page', 'c24_page_event_search');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Culture24 Event Search';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
      'place' => 'place',
      'addressStreet' => 'addressStreet',
      'addressTown' => 'addressTown',
      'addressCounty' => 'addressCounty',
      'addressPostcode' => 'addressPostcode',
      'addressCountry' => 'addressCountry',
  );
  $handler->display->display_options['row_options']['separator'] = ', ';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Culture24: uniqueID */
  $handler->display->display_options['fields']['uniqueID']['id'] = 'uniqueID';
  $handler->display->display_options['fields']['uniqueID']['table'] = 'c24_event';
  $handler->display->display_options['fields']['uniqueID']['field'] = 'uniqueID';
  $handler->display->display_options['fields']['uniqueID']['label'] = '';
  $handler->display->display_options['fields']['uniqueID']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uniqueID']['element_label_colon'] = FALSE;
  /* Field: Culture24: name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'c24_event';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'culture24/event/[uniqueID]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Culture24: place */
  $handler->display->display_options['fields']['place']['id'] = 'place';
  $handler->display->display_options['fields']['place']['table'] = 'c24_event';
  $handler->display->display_options['fields']['place']['field'] = 'place';
  $handler->display->display_options['fields']['place']['label'] = '';
  $handler->display->display_options['fields']['place']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressStreet */
  $handler->display->display_options['fields']['addressStreet']['id'] = 'addressStreet';
  $handler->display->display_options['fields']['addressStreet']['table'] = 'c24_event';
  $handler->display->display_options['fields']['addressStreet']['field'] = 'addressStreet';
  $handler->display->display_options['fields']['addressStreet']['label'] = '';
  $handler->display->display_options['fields']['addressStreet']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressTown */
  $handler->display->display_options['fields']['addressTown']['id'] = 'addressTown';
  $handler->display->display_options['fields']['addressTown']['table'] = 'c24_event';
  $handler->display->display_options['fields']['addressTown']['field'] = 'addressTown';
  $handler->display->display_options['fields']['addressTown']['label'] = '';
  $handler->display->display_options['fields']['addressTown']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressCounty */
  $handler->display->display_options['fields']['addressCounty']['id'] = 'addressCounty';
  $handler->display->display_options['fields']['addressCounty']['table'] = 'c24_event';
  $handler->display->display_options['fields']['addressCounty']['field'] = 'addressCounty';
  $handler->display->display_options['fields']['addressCounty']['label'] = '';
  $handler->display->display_options['fields']['addressCounty']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressPostcode */
  $handler->display->display_options['fields']['addressPostcode']['id'] = 'addressPostcode';
  $handler->display->display_options['fields']['addressPostcode']['table'] = 'c24_event';
  $handler->display->display_options['fields']['addressPostcode']['field'] = 'addressPostcode';
  $handler->display->display_options['fields']['addressPostcode']['label'] = '';
  $handler->display->display_options['fields']['addressPostcode']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressCountry */
  $handler->display->display_options['fields']['addressCountry']['id'] = 'addressCountry';
  $handler->display->display_options['fields']['addressCountry']['table'] = 'c24_event';
  $handler->display->display_options['fields']['addressCountry']['field'] = 'addressCountry';
  $handler->display->display_options['fields']['addressCountry']['label'] = '';
  $handler->display->display_options['fields']['addressCountry']['element_label_colon'] = FALSE;
  /* Field: Culture24: contentTag */
  $handler->display->display_options['fields']['contentTag']['id'] = 'contentTag';
  $handler->display->display_options['fields']['contentTag']['table'] = 'c24_event';
  $handler->display->display_options['fields']['contentTag']['field'] = 'contentTag';
  $handler->display->display_options['fields']['contentTag']['label'] = 'Tags';
  $handler->display->display_options['fields']['contentTag']['type'] = 'ol';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Culture24: country */
  $handler->display->display_options['filters']['country']['id'] = 'country';
  $handler->display->display_options['filters']['country']['table'] = 'c24_event';
  $handler->display->display_options['filters']['country']['field'] = 'country';
  $handler->display->display_options['filters']['country']['value'] = '0';
  $handler->display->display_options['filters']['country']['exposed'] = TRUE;
  $handler->display->display_options['filters']['country']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['country']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['country']['expose']['operator'] = 'country_op';
  $handler->display->display_options['filters']['country']['expose']['identifier'] = 'country';
  $handler->display->display_options['filters']['country']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      10 => 0,
      11 => 0,
      13 => 0,
      12 => 0,
  );
  /* Filter criterion: Culture24: region */
  $handler->display->display_options['filters']['region']['id'] = 'region';
  $handler->display->display_options['filters']['region']['table'] = 'c24_event';
  $handler->display->display_options['filters']['region']['field'] = 'region';
  $handler->display->display_options['filters']['region']['value'] = '0';
  $handler->display->display_options['filters']['region']['exposed'] = TRUE;
  $handler->display->display_options['filters']['region']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['region']['expose']['label'] = 'Region';
  $handler->display->display_options['filters']['region']['expose']['operator'] = 'region_op';
  $handler->display->display_options['filters']['region']['expose']['identifier'] = 'region';
  $handler->display->display_options['filters']['region']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      10 => 0,
      11 => 0,
      13 => 0,
      12 => 0,
  );
  /* Filter criterion: Culture24: audience */
  $handler->display->display_options['filters']['audience']['id'] = 'audience';
  $handler->display->display_options['filters']['audience']['table'] = 'c24_event';
  $handler->display->display_options['filters']['audience']['field'] = 'audience';
  $handler->display->display_options['filters']['audience']['value'] = '0';
  $handler->display->display_options['filters']['audience']['exposed'] = TRUE;
  $handler->display->display_options['filters']['audience']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['audience']['expose']['label'] = 'Audience';
  $handler->display->display_options['filters']['audience']['expose']['operator'] = 'audience_op';
  $handler->display->display_options['filters']['audience']['expose']['identifier'] = 'audience';
  $handler->display->display_options['filters']['audience']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      10 => 0,
      11 => 0,
      13 => 0,
      12 => 0,
  );
  /* Filter criterion: Culture24: type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'c24_event';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = '0';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      10 => 0,
      11 => 0,
      13 => 0,
      12 => 0,
  );
  /* Filter criterion: Culture24: contentTag */
  $handler->display->display_options['filters']['contentTag']['id'] = 'contentTag';
  $handler->display->display_options['filters']['contentTag']['table'] = 'c24_event';
  $handler->display->display_options['filters']['contentTag']['field'] = 'contentTag';
  $handler->display->display_options['filters']['contentTag']['exposed'] = TRUE;
  $handler->display->display_options['filters']['contentTag']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['contentTag']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['contentTag']['expose']['description'] = 'comma delimited tags';
  $handler->display->display_options['filters']['contentTag']['expose']['operator'] = 'contentTag_op';
  $handler->display->display_options['filters']['contentTag']['expose']['identifier'] = 'contentTag';
  $handler->display->display_options['filters']['contentTag']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      10 => 0,
      11 => 0,
      13 => 0,
      12 => 0,
  );
  /* Filter criterion: Culture24: name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'c24_event';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      10 => 0,
      11 => 0,
      13 => 0,
      12 => 0,
  );
  /* Filter criterion: Culture24: venueID */
  $handler->display->display_options['filters']['venueID']['id'] = 'venueID';
  $handler->display->display_options['filters']['venueID']['table'] = 'c24_event';
  $handler->display->display_options['filters']['venueID']['field'] = 'venueID';
  $handler->display->display_options['filters']['venueID']['exposed'] = TRUE;
  $handler->display->display_options['filters']['venueID']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['venueID']['expose']['label'] = 'Venue ID';
  $handler->display->display_options['filters']['venueID']['expose']['operator'] = 'venueID_op';
  $handler->display->display_options['filters']['venueID']['expose']['identifier'] = 'venueID';
  $handler->display->display_options['filters']['venueID']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      10 => 0,
      11 => 0,
      13 => 0,
      12 => 0,
  );
  $handler->display->display_options['path'] = 'culture24/events';
  $translatables['culture24_event'] = array(
      t('Master'),
      t('Culture24 Event'),
      t('more'),
      t('Apply'),
      t('Reset'),
      t('Sort by'),
      t('Asc'),
      t('Desc'),
      t('uniqueID'),
      t('All'),
      t('Event Page'),
      t('Search Page'),
      t('Culture24 Event Search'),
      t('Select any filter and click on Apply to see results'),
      t('Items per page'),
      t('- All -'),
      t('Offset'),
      t('« first'),
      t('‹ previous'),
      t('next ›'),
      t('last »'),
      t('Tags'),
      t('Country'),
      t('Region'),
      t('Audience'),
      t('Type'),
      t('comma delimited tags'),
      t('Name'),
      t('Venue ID'),
  );

  $views[$view->name] = $view;


  $view = new view();
  $view->name = 'culture24_venue';
  $view->description = '';
  $view->tag = 'Culture24';
  $view->base_table = 'c24_venue';
  $view->human_name = 'Culture24 Venues';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Culture24 Venue';
  $handler->display->display_options['css_class'] = 'culture24 culture24-venue';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['separator'] = ', ';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Culture24: uniqueID */
  $handler->display->display_options['fields']['uniqueID_1']['id'] = 'uniqueID_1';
  $handler->display->display_options['fields']['uniqueID_1']['table'] = 'c24_venue';
  $handler->display->display_options['fields']['uniqueID_1']['field'] = 'uniqueID';
  /* Contextual filter: Culture24: uniqueID */
  $handler->display->display_options['arguments']['uniqueID']['id'] = 'uniqueID';
  $handler->display->display_options['arguments']['uniqueID']['table'] = 'c24_venue';
  $handler->display->display_options['arguments']['uniqueID']['field'] = 'uniqueID';
  $handler->display->display_options['arguments']['uniqueID']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uniqueID']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uniqueID']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uniqueID']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uniqueID']['summary_options']['items_per_page'] = '25';

  /* Display: Venue Page */
  $handler = $view->new_display('page', 'Venue Page', 'c24_page_venue_detail');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Culture24 Venue';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Culture24: uniqueID */
  $handler->display->display_options['fields']['uniqueID']['id'] = 'uniqueID';
  $handler->display->display_options['fields']['uniqueID']['table'] = 'c24_venue';
  $handler->display->display_options['fields']['uniqueID']['field'] = 'uniqueID';
  $handler->display->display_options['fields']['uniqueID']['label'] = '';
  $handler->display->display_options['fields']['uniqueID']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uniqueID']['element_label_colon'] = FALSE;
  /* Field: Culture24: name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'c24_venue';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressStreet */
  $handler->display->display_options['fields']['addressStreet']['id'] = 'addressStreet';
  $handler->display->display_options['fields']['addressStreet']['table'] = 'c24_venue';
  $handler->display->display_options['fields']['addressStreet']['field'] = 'addressStreet';
  $handler->display->display_options['fields']['addressStreet']['label'] = '';
  $handler->display->display_options['fields']['addressStreet']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressTown */
  $handler->display->display_options['fields']['addressTown']['id'] = 'addressTown';
  $handler->display->display_options['fields']['addressTown']['table'] = 'c24_venue';
  $handler->display->display_options['fields']['addressTown']['field'] = 'addressTown';
  $handler->display->display_options['fields']['addressTown']['label'] = '';
  $handler->display->display_options['fields']['addressTown']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressCounty */
  $handler->display->display_options['fields']['addressCounty']['id'] = 'addressCounty';
  $handler->display->display_options['fields']['addressCounty']['table'] = 'c24_venue';
  $handler->display->display_options['fields']['addressCounty']['field'] = 'addressCounty';
  $handler->display->display_options['fields']['addressCounty']['label'] = '';
  $handler->display->display_options['fields']['addressCounty']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressPostcode */
  $handler->display->display_options['fields']['addressPostcode']['id'] = 'addressPostcode';
  $handler->display->display_options['fields']['addressPostcode']['table'] = 'c24_venue';
  $handler->display->display_options['fields']['addressPostcode']['field'] = 'addressPostcode';
  $handler->display->display_options['fields']['addressPostcode']['label'] = '';
  $handler->display->display_options['fields']['addressPostcode']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressCountry */
  $handler->display->display_options['fields']['addressCountry']['id'] = 'addressCountry';
  $handler->display->display_options['fields']['addressCountry']['table'] = 'c24_venue';
  $handler->display->display_options['fields']['addressCountry']['field'] = 'addressCountry';
  $handler->display->display_options['fields']['addressCountry']['label'] = '';
  $handler->display->display_options['fields']['addressCountry']['element_label_colon'] = FALSE;
  /* Field: Culture24: type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'c24_venue';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Culture24: contentTag */
  $handler->display->display_options['fields']['contentTag']['id'] = 'contentTag';
  $handler->display->display_options['fields']['contentTag']['table'] = 'c24_venue';
  $handler->display->display_options['fields']['contentTag']['field'] = 'contentTag';
  $handler->display->display_options['fields']['contentTag']['label'] = '';
  $handler->display->display_options['fields']['contentTag']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'culture24/venue/%';

  /* Display: Search Page */
  $handler = $view->new_display('page', 'Search Page', 'c24_page_venue_search');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Culture24 Venue Search';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Culture24: uniqueID */
  $handler->display->display_options['fields']['uniqueID']['id'] = 'uniqueID';
  $handler->display->display_options['fields']['uniqueID']['table'] = 'c24_venue';
  $handler->display->display_options['fields']['uniqueID']['field'] = 'uniqueID';
  $handler->display->display_options['fields']['uniqueID']['label'] = '';
  $handler->display->display_options['fields']['uniqueID']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uniqueID']['element_label_colon'] = FALSE;
  /* Field: Culture24: name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'c24_venue';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'culture24/event/[uniqueID]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressStreet */
  $handler->display->display_options['fields']['addressStreet']['id'] = 'addressStreet';
  $handler->display->display_options['fields']['addressStreet']['table'] = 'c24_venue';
  $handler->display->display_options['fields']['addressStreet']['field'] = 'addressStreet';
  $handler->display->display_options['fields']['addressStreet']['label'] = '';
  $handler->display->display_options['fields']['addressStreet']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressTown */
  $handler->display->display_options['fields']['addressTown']['id'] = 'addressTown';
  $handler->display->display_options['fields']['addressTown']['table'] = 'c24_venue';
  $handler->display->display_options['fields']['addressTown']['field'] = 'addressTown';
  $handler->display->display_options['fields']['addressTown']['label'] = '';
  $handler->display->display_options['fields']['addressTown']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressCounty */
  $handler->display->display_options['fields']['addressCounty']['id'] = 'addressCounty';
  $handler->display->display_options['fields']['addressCounty']['table'] = 'c24_venue';
  $handler->display->display_options['fields']['addressCounty']['field'] = 'addressCounty';
  $handler->display->display_options['fields']['addressCounty']['label'] = '';
  $handler->display->display_options['fields']['addressCounty']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressPostcode */
  $handler->display->display_options['fields']['addressPostcode']['id'] = 'addressPostcode';
  $handler->display->display_options['fields']['addressPostcode']['table'] = 'c24_venue';
  $handler->display->display_options['fields']['addressPostcode']['field'] = 'addressPostcode';
  $handler->display->display_options['fields']['addressPostcode']['label'] = '';
  $handler->display->display_options['fields']['addressPostcode']['element_label_colon'] = FALSE;
  /* Field: Culture24: addressCountry */
  $handler->display->display_options['fields']['addressCountry']['id'] = 'addressCountry';
  $handler->display->display_options['fields']['addressCountry']['table'] = 'c24_venue';
  $handler->display->display_options['fields']['addressCountry']['field'] = 'addressCountry';
  $handler->display->display_options['fields']['addressCountry']['label'] = '';
  $handler->display->display_options['fields']['addressCountry']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'culture24/venues';
  $translatables['culture24_venue'] = array(
      t('Master'),
      t('Culture24 Venue'),
      t('more'),
      t('Apply'),
      t('Reset'),
      t('Sort by'),
      t('Asc'),
      t('Desc'),
      t('uniqueID'),
      t('All'),
      t('Venue Page'),
      t('Search Page'),
      t('Culture24 Venue Search'),
      t('Select any filter and click on Apply to see results'),
      t('Items per page'),
      t('- All -'),
      t('Offset'),
      t('« first'),
      t('‹ previous'),
      t('next ›'),
      t('last »'),
      t('Tags'),
      t('comma delimited tags'),
      t('Name'),
  );

  $views[$view->name] = $view;

  return $views;
}
