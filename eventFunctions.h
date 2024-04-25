#ifndef EVENT_FUNCTIONS_H
#define EVENT_FUNCTIONS_H

#include <crow.h>
#include <map>
#include <string>
#include "Event.h"

//Functions for GET/POST/PUT/DELETE
crow::response createEvent(crow::request req);
crow::response readEvent(std::string name);
crow::response readAllEvents(crow::request req);
void updateEvent(crow::request req, crow::response& res, std::string name);
crow::response deleteEvent(std::string name);

#endif