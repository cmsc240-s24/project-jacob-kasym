# Project Design Document

## Introduction

This API will allow for an easy line of communication between a touring artist and their fanbase about details of the shows on an upcoming/partially completed tour.

## Background/Context

When an performing artist decides to go on a tour, it can be hard to keep track of show dates/locations/times.  This is especially the case if they are a smaller group dealing with smaller venues, which are often liable to change/cancel.  New and longtime fans alike are often left scrambling at the last minute, scouring all of (if any) of bands and venues social media looking for last-minute changes.  The music

## Stakeholders

Artists: people who need events, will be able to schedule, organize tours, social gatherings and events. They are interested in attendance tracking, and overall event planning.

Fans: they are interested in tracking the cities where the events of their favourite artists will be held. They rely on API to get the newest information about their artists and their tours and events.

## Functional Requirements

1. **Resource Creation**
   - The service shall allow music retailers to create new resource entries for genres, artists, records, and compact discs via POST requests.
   - The service shall validate all incoming data against predefined schemas before creating a new resource.
   - The service shall return a `201 Created` status code and the created resource in the response body upon successful creation.

2. **Resource Retrieval**
   - The service shall provide endpoints for customers and music retailers to retrieve lists of genres, artists, records, and compact discs via GET requests.
   - The service shall allow retrieval of detailed information for a single resource by its unique identifier.
   - The service shall return a `200 OK` status code and the requested resources in the response body upon successful retrieval.

3. **Resource Update**
   - The service shall permit music retailers to update existing resource entries for genres, artists, records, and compact discs via PUT requests.
   - The service shall validate all incoming data for updates against predefined schemas.
   - The service shall return a `200 OK` status code and the updated resource in the response body upon successful update.

4. **Resource Deletion**
   - The service shall enable music retailers to delete resource entries for genres, artists, records, and compact discs via DELETE requests.
   - The service shall return a `204 No Content` status code upon successful deletion.
   - The service shall return a `403 Forbidden` status code if an unauthorized user attempts to delete a resource.

5. **Data Validation**
   - The service shall enforce data validation rules to ensure that all resource data conforms to the expected formats, types, and constraints.
   - The service shall return a `400 Bad Request` status code along with error details if validation fails.

6. **Authentication and Authorization**
   - The service shall require authentication for users attempting to create, update, or delete resources.
   - The service shall authorize users based on their roles, permitting only authorized music retailers to modify or delete resource entries.

7. **Error Handling**
   - The service shall implement comprehensive error handling to provide meaningful error messages and appropriate HTTP status codes to the client for all failed operations.
   - The service shall return a `404 Not Found` status code when a requested resource cannot be located.
   - The service shall return a `500 Internal Server Error` status code in the event of unexpected server-side errors.

## Use Case Description


## List Of Resources


## List of End Points


## UML Diagrams

