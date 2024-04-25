#include <crow.h>
#include <map>
#include <string>
#include "Event.h"

using namespace std;
using namespace crow;

extern map<string, Event> eventMap;
extern map<string, Artist> artistMap;
extern map<string, Venue> venueMap;

response createEvent(request req)
{
    // Load the request body string into a JSON read value.
    json::rvalue readValueJson = json::load(req.body);

    // If there was a problem converting the body text to JSON return an error.
    if(!readValueJson)
        return response(400, "Invalid JSON");

    // Create a new event.
    Event event{readValueJson["id"].s(), artistMap[readValueJson["artist"]["name"].s()], venueMap[readValueJson["venue"]["city"].s()], readValueJson["date"].s(), readValueJson["time"].s()};

    eventMap[event.getId()] = event;

    return response(201, event.convertToJson().dump());
}

response readEvent(string id)
{
    try
    {
        //Get the event id from the event map
        Event event = eventMap.at(id);

        //return the event as a JSON string
        return response(event.convertToJson().dump());
    }
    catch(out_of_range& exception)
    {
        return response(404, "Event Not Found");
    }
}

response readAllEvents(request req)
{
    // Create a new JSON write value use to write to the file
    json::wvalue jsonWriteValue;

    //For each event in the map, convert the event to JSON and add to the write value
    int index = 0;
    for(pair<string,Event> keyValuePair : eventMap)
    {
        // first: gives you access to the first item in the pair
        // second: gives you access to the second item in the pair
        jsonWriteValue[index] = keyValuePair.second.convertToJson();
        index++;
    }

    return response(jsonWriteValue.dump());
}

void updateEvent(request req, response& res, string id)
{
    try
    {
        // Get the event from the event map
        Event event = eventMap.at(id);

        //Convert the request  body to json
        json::rvalue readValueJson = json::load(req.body);

        if(!readValueJson)
        {
            res.code = 400;
            res.end("Invalid Json");
            return;
        }

        //update the event
        event.setArtist(artistMap.at(readValueJson["artist"]["name"].s()));
        event.setWhere(venueMap.at(readValueJson["venue"]["city"].s()));
        event.setWhen(readValueJson["date"].s(), readValueJson["time"].s());
        eventMap[id] = event;

        //return the updated event as a JSON string
        res.code = 200;
        res.set_header("Content-Type", "application/json");
        res.write(event.convertToJson().dump());
    }
    catch(out_of_range& exception)
    {
        res.code = 404;
        res.end("Event Not Found");
    }
    
}