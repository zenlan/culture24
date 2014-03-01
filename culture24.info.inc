<?php

// $Id$

/**
 * @file
 * Provides info about Culture24 entities.
 */

/**
 *
 * Implements hook_entity_property_info().
 * @see entity_entity_property_info()
 *
 */
function culture24_entity_property_info() {
  $info = array();
  
  $base = array(); 
  $base['uniqueID'] = array('type' => 'text', 'label' => 'uniqueID', 'description' => 'uniqueID');
  $base['name'] = array('type' => 'text', 'label' => 'name', 'description' => 'name');
  $base['description'] = array('type' => 'text', 'label' => 'description', 'description' => 'description');
  $base['type'] = array('type' => 'text', 'label' => 'type', 'description' => 'type');
  $base['contentTag'] = array('type' => 'text', 'label' => 'contentTag', 'description' => 'contentTag');
  $base['addressStreet'] = array('type' => 'text', 'label' => 'addressStreet', 'description' => 'addressStreet');
  $base['addressTown'] = array('type' => 'text', 'label' => 'addressTown', 'description' => 'addressTown');
  $base['addressCounty'] = array('type' => 'text', 'label' => 'addressCounty', 'description' => 'addressCounty');
  $base['addressCountry'] = array('type' => 'text', 'label' => 'addressCountry', 'description' => 'addressCountry');
  $base['addressPostcode'] = array('type' => 'integer', 'label' => 'addressPostcode', 'description' => 'addressPostcode');
  $base['link'] = array('type' => 'text', 'label' => 'link', 'description' => 'link');
  $base['url'] = array('type' => 'text', 'label' => 'url', 'description' => 'url');
  $base['graphicUrl'] = array('type' => 'text', 'label' => 'graphicUrl', 'description' => 'graphicUrl');
  $base['charges'] = array('type' => 'text', 'label' => 'charges', 'description' => 'charges');

  $info['c24_event']['properties'] = $base;
  $event = &$info['c24_event']['properties'];
  $event['venueID'] = array('type' => 'text', 'label' => 'venueID', 'description' => 'venueID');
  $event['venue.name'] = array('type' => 'text', 'label' => 'venue.name', 'description' => 'venue.name');
  $event['venue.url'] = array('type' => 'text', 'label' => 'venue.url', 'description' => 'venue.url');
  $event['venue.addressStreet'] = array('type' => 'text', 'label' => 'venue.addressStreet', 'description' => 'venue.addressStreet');
  $event['venue.addressTown'] = array('type' => 'text', 'label' => 'venue.addressTown', 'description' => 'venue.addressTown');
  $event['venue.addressCounty'] = array('type' => 'text', 'label' => 'venue.addressCounty', 'description' => 'venue.addressCounty');
  $event['venue.addressPostcode'] = array('type' => 'text', 'label' => 'venue.addressPostcode', 'description' => 'venue.addressPostcode');
  $event['venue.addressCountry'] = array('type' => 'text', 'label' => 'venue.addressCountry', 'description' => 'venue.addressCountry');
  $event['venue.latitude'] = array('type' => 'text', 'label' => 'venue.latitude', 'description' => 'venue.latitude');
  $event['venue.longitude'] = array('type' => 'text', 'label' => 'venue.longitude', 'description' => 'venue.longitude');
  $event['instance'] = array('type' => 'text', 'label' => 'instance', 'description' => 'instance');
  $event['audience'] = array('type' => 'text', 'label' => 'audience', 'description' => 'audience');
  $event['status'] = array('type' => 'text', 'label' => 'status', 'description' => 'status');
  $event['shortDescription'] = array('type' => 'text', 'label' => 'shortDescription', 'description' => 'shortDescription');
  $event['freeOfCharge'] = array('type' => 'text', 'label' => 'freeOfCharge', 'description' => 'freeOfCharge');
  $event['concessionsAvailable'] = array('type' => 'text', 'label' => 'concessionsAvailable', 'description' => 'concessionsAvailable');
  $event['registrationRequired'] = array('type' => 'text', 'label' => 'registrationRequired', 'description' => 'registrationRequired');
  $event['place'] = array('type' => 'text', 'label' => 'place', 'description' => 'place');
  $event['nationalCurriculumTag'] = array('type' => 'text', 'label' => 'nationalCurriculumTag', 'description' => 'nationalCurriculumTag');
  $event['publicationDate'] = array('type' => 'text', 'label' => 'publicationDate', 'description' => 'publicationDate');
  
  $info['c24_venue']['properties'] = $base;
  $venue = &$info['c24_venue']['properties'];
  $venue['otherNames'] = array('type' => 'text', 'label' => 'otherNames', 'description' => 'otherNames');
  $venue['type'] = array('type' => 'text', 'label' => 'type', 'description' => 'type');
  $venue['contentTag'] = array('type' => 'text', 'label' => 'contentTag', 'description' => 'contentTag');
  $venue['legalStatus'] = array('type' => 'text', 'label' => 'legalStatus', 'description' => 'legalStatus');
  $venue['email'] = array('type' => 'text', 'label' => 'email', 'description' => 'email');
  $venue['telephone'] = array('type' => 'text', 'label' => 'telephone', 'description' => 'telephone');
  $venue['fax'] = array('type' => 'text', 'label' => 'fax', 'description' => 'fax');
  $venue['latitude'] = array('type' => 'text', 'label' => 'latitude', 'description' => 'latitude');
  $venue['longitude'] = array('type' => 'text', 'label' => 'longitude', 'description' => 'longitude');
  $venue['openingHours'] = array('type' => 'text', 'label' => 'openingHours', 'description' => 'openingHours');
  $venue['discounts'] = array('type' => 'text', 'label' => 'discounts', 'description' => 'discounts');
  $venue['travelDirections'] = array('type' => 'text', 'label' => 'travelDirections', 'description' => 'travelDirections');
  $venue['facilitiesInformation'] = array('type' => 'text', 'label' => 'facilitiesInformation', 'description' => 'facilitiesInformation');
  $venue['facility'] = array('type' => 'text', 'label' => 'facility', 'description' => 'facility');
  $venue['service'] = array('type' => 'text', 'label' => 'service', 'description' => 'service');
  $venue['keyArtistOrExhibit'] = array('type' => 'text', 'label' => 'keyArtistOrExhibit', 'description' => 'keyArtistOrExhibit');
  $venue['collections'] = array('type' => 'text', 'label' => 'collections', 'description' => 'collections');
  $venue['collectionsDescription'] = array('type' => 'text', 'label' => 'collectionsDescription', 'description' => 'collectionsDescription');
  $venue['collectionsDescriptionGraphic'] = array('type' => 'text', 'label' => 'collectionsDescriptionGraphic', 'description' => 'collectionsDescriptionGraphic');
  $venue['constituentInstitution'] = array('type' => 'text', 'label' => 'constituentInstitution', 'description' => 'constituentInstitution');
  $venue['lea'] = array('type' => 'text', 'label' => 'lea', 'description' => 'lea');
  $venue['regionalAgency'] = array('type' => 'text', 'label' => 'regionalAgency', 'description' => 'regionalAgency');

  return $info;
}
