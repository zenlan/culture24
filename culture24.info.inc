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
  $base['uniqueID'] = array('type' => 'text', 'label' => 'uniqueID', 'description' => 'uniqueID', 'cardinality' => 1);
  $base['name'] = array('type' => 'text', 'label' => 'name', 'description' => 'name', 'cardinality' => 1);
  $base['description'] = array('type' => 'text', 'label' => 'description', 'description' => 'description', 'cardinality' => 1);
  $base['type'] = array('type' => 'text', 'label' => 'type', 'description' => 'type', 'cardinality' => FIELD_CARDINALITY_UNLIMITED);
  $base['contentTag'] = array('type' => 'text', 'label' => 'contentTag', 'description' => 'contentTag', 'cardinality' => FIELD_CARDINALITY_UNLIMITED);
  $base['addressStreet'] = array('type' => 'text', 'label' => 'addressStreet', 'description' => 'addressStreet', 'cardinality' => 1);
  $base['addressTown'] = array('type' => 'text', 'label' => 'addressTown', 'description' => 'addressTown', 'cardinality' => 1);
  $base['addressCounty'] = array('type' => 'text', 'label' => 'addressCounty', 'description' => 'addressCounty', 'cardinality' => 1);
  $base['addressCountry'] = array('type' => 'text', 'label' => 'addressCountry', 'description' => 'addressCountry', 'cardinality' => 1);
  $base['addressPostcode'] = array('type' => 'integer', 'label' => 'addressPostcode', 'description' => 'addressPostcode', 'cardinality' => 1);
  $base['link'] = array('type' => 'text', 'label' => 'link', 'description' => 'link', 'cardinality' => 1);
  $base['url'] = array('type' => 'text', 'label' => 'url', 'description' => 'url', 'cardinality' => 1);
  $base['graphicUrl'] = array('type' => 'text', 'label' => 'graphicUrl', 'description' => 'graphicUrl', 'cardinality' => 1);
  $base['charges'] = array('type' => 'text', 'label' => 'charges', 'description' => 'charges', 'cardinality' => 1);

  $info['c24_event']['properties'] = $base;
  $event = &$info['c24_event']['properties'];
  $event['venueID'] = array('type' => 'text', 'label' => 'venueID', 'description' => 'venueID', 'cardinality' => 1);
  $event['venue.name'] = array('type' => 'text', 'label' => 'venue.name', 'description' => 'venue.name', 'cardinality' => 1);
  $event['venue.url'] = array('type' => 'text', 'label' => 'venue.url', 'description' => 'venue.url', 'cardinality' => 1);
  $event['venue.addressStreet'] = array('type' => 'text', 'label' => 'venue.addressStreet', 'description' => 'venue.addressStreet', 'cardinality' => 1);
  $event['venue.addressTown'] = array('type' => 'text', 'label' => 'venue.addressTown', 'description' => 'venue.addressTown', 'cardinality' => 1);
  $event['venue.addressCounty'] = array('type' => 'text', 'label' => 'venue.addressCounty', 'description' => 'venue.addressCounty', 'cardinality' => 1);
  $event['venue.addressPostcode'] = array('type' => 'text', 'label' => 'venue.addressPostcode', 'description' => 'venue.addressPostcode', 'cardinality' => 1);
  $event['venue.addressCountry'] = array('type' => 'text', 'label' => 'venue.addressCountry', 'description' => 'venue.addressCountry', 'cardinality' => 1);
  $event['venue.latitude'] = array('type' => 'text', 'label' => 'venue.latitude', 'description' => 'venue.latitude', 'cardinality' => 1);
  $event['venue.longitude'] = array('type' => 'text', 'label' => 'venue.longitude', 'description' => 'venue.longitude', 'cardinality' => 1);
  $event['instance'] = array('type' => 'text', 'label' => 'instance', 'description' => 'instance', 'cardinality' => 1);
  $event['audience'] = array('type' => 'text', 'label' => 'audience', 'description' => 'audience', 'cardinality' => FIELD_CARDINALITY_UNLIMITED);
  $event['status'] = array('type' => 'text', 'label' => 'status', 'description' => 'status', 'cardinality' => 1);
  $event['shortDescription'] = array('type' => 'text', 'label' => 'shortDescription', 'description' => 'shortDescription', 'cardinality' => 1);
  $event['freeOfCharge'] = array('type' => 'text', 'label' => 'freeOfCharge', 'description' => 'freeOfCharge', 'cardinality' => 1);
  $event['concessionsAvailable'] = array('type' => 'text', 'label' => 'concessionsAvailable', 'description' => 'concessionsAvailable', 'cardinality' => 1);
  $event['registrationRequired'] = array('type' => 'text', 'label' => 'registrationRequired', 'description' => 'registrationRequired', 'cardinality' => 1);
  $event['place'] = array('type' => 'text', 'label' => 'place', 'description' => 'place', 'cardinality' => 1);
  $event['nationalCurriculumTag'] = array('type' => 'text', 'label' => 'nationalCurriculumTag', 'description' => 'nationalCurriculumTag', 'cardinality' => 1);
  $event['publicationDate'] = array('type' => 'text', 'label' => 'publicationDate', 'description' => 'publicationDate', 'cardinality' => 1);
  
  $info['c24_venue']['properties'] = $base;
  $venue = &$info['c24_venue']['properties'];
  $venue['otherNames'] = array('type' => 'text', 'label' => 'otherNames', 'description' => 'otherNames', 'cardinality' => 1);
  $venue['type'] = array('type' => 'text', 'label' => 'type', 'description' => 'type', 'cardinality' => 1);
  $venue['legalStatus'] = array('type' => 'text', 'label' => 'legalStatus', 'description' => 'legalStatus', 'cardinality' => 1);
  $venue['email'] = array('type' => 'text', 'label' => 'email', 'description' => 'email', 'cardinality' => 1);
  $venue['telephone'] = array('type' => 'text', 'label' => 'telephone', 'description' => 'telephone', 'cardinality' => 1);
  $venue['fax'] = array('type' => 'text', 'label' => 'fax', 'description' => 'fax', 'cardinality' => 1);
  $venue['latitude'] = array('type' => 'text', 'label' => 'latitude', 'description' => 'latitude', 'cardinality' => 1);
  $venue['longitude'] = array('type' => 'text', 'label' => 'longitude', 'description' => 'longitude', 'cardinality' => 1);
  $venue['openingHours'] = array('type' => 'text', 'label' => 'openingHours', 'description' => 'openingHours', 'cardinality' => 1);
  $venue['discounts'] = array('type' => 'text', 'label' => 'discounts', 'description' => 'discounts', 'cardinality' => 1);
  $venue['travelDirections'] = array('type' => 'text', 'label' => 'travelDirections', 'description' => 'travelDirections', 'cardinality' => 1);
  $venue['facilitiesInformation'] = array('type' => 'text', 'label' => 'facilitiesInformation', 'description' => 'facilitiesInformation', 'cardinality' => 1);
  $venue['facility'] = array('type' => 'text', 'label' => 'facility', 'description' => 'facility', 'cardinality' => 1);
  $venue['service'] = array('type' => 'text', 'label' => 'service', 'description' => 'service', 'cardinality' => 1);
  $venue['keyArtistOrExhibit'] = array('type' => 'text', 'label' => 'keyArtistOrExhibit', 'description' => 'keyArtistOrExhibit', 'cardinality' => 1);
  $venue['collections'] = array('type' => 'text', 'label' => 'collections', 'description' => 'collections', 'cardinality' => 1);
  $venue['collectionsDescription'] = array('type' => 'text', 'label' => 'collectionsDescription', 'description' => 'collectionsDescription', 'cardinality' => 1);
  $venue['collectionsDescriptionGraphic'] = array('type' => 'text', 'label' => 'collectionsDescriptionGraphic', 'description' => 'collectionsDescriptionGraphic', 'cardinality' => 1);
  $venue['constituentInstitution'] = array('type' => 'text', 'label' => 'constituentInstitution', 'description' => 'constituentInstitution', 'cardinality' => 1);
  $venue['lea'] = array('type' => 'text', 'label' => 'lea', 'description' => 'lea', 'cardinality' => 1);
  $venue['regionalAgency'] = array('type' => 'text', 'label' => 'regionalAgency', 'description' => 'regionalAgency', 'cardinality' => 1);

  return $info;
}
