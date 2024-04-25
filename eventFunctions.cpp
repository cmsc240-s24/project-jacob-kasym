#include <crow.h>
#include <map>
#include <string>
#include "Event.h"

using namespace std;
using namespace crow;

extern map<string, Event> eventMap;

response createEvent(request req)
{
    // Load the request body string into a JSON read value.
    json::rvalue readValueJson = json::load(req.body);

    // If there was a problem converting the body text to JSON return an error.
    if(!readValueJson)
        return response(400, "Invalid JSON");

    // Create a new event.
    Event event{readValueJson["id"]}

}