#ifndef VENUE_FUNCTIONS_H
#define VENUE_FUNCTIONS_H

#include <crow.h>
#include <map>
#include <string>
#include "Venue.h"

//Functions for GET/POST/PUT/DELETE
crow::response createVenue(crow::request req);
crow::response readVenue(std::string name);
crow::response readAllVenues(crow::request req);
void updateVenue(crow::request req, crow::response& res, std::string name);
crow::response deleteVenue(crow::request req, std::string name);

#endif