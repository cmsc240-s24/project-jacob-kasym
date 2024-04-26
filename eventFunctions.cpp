#include <crow.h>
#include <map>
#include <string>
#include "eventFunctions.h"
#include "Event.h"
#include "PastEvent.h"

using namespace std;
using namespace crow;

extern map<string, Event> eventMap;
extern map<string, Artist> artistMap;
extern map<string, Venue> venueMap;
extern map<string, PastEvent> pastMap;


response readRandomReview(string searchString){
    json::wvalue jsonWriteValue;

    try
    {
        PastEvent pastevent = pastMap.at(searchString);
        json::wvalue jsonWriteValue;
        jsonWriteValue["random review"] = pastevent.getReview();
        return response(200, jsonWriteValue.dump());
    }
    catch(out_of_range& exception)
    {
        return response(404, "Event Not Found");
    }
}

response readPastEvent(string id)
{

    try
    {
        //Get the event id from the event map
        PastEvent event = pastMap.at(id);

        //return the event as a JSON string
        return response(event.convertToJson().dump());
    }
    catch(out_of_range& exception)
    {
        return response(404, "Event Not Found");
    }
}
//printing out all past events
response readPastEvents()
{
    json::wvalue jsonWriteValue;

    //For each past event in the map, convert the event to JSON and add to the write value
    int index = 0;
    for(pair<string,PastEvent> keyValuePair : pastMap)
    {
        // first: gives you access to the first item in the pair
        // second: gives you access to the second item in the pair
        jsonWriteValue[index] = keyValuePair.second.convertToJson();
        index++;
    }

    return response(jsonWriteValue.dump());

}

response searchArtist(string searchString)
{
    vector<Event> found;
    //For each string/Event pair in the event map
    for(pair<string, Event> eventPair : eventMap)
    {
        if(eventPair.second.getArtist().getName().find(searchString) != string::npos)
            found.push_back(eventPair.second);
    }

    json::wvalue jsonWriteValue;

    int index = 0;
    for(Event event : found)
    {
        jsonWriteValue[index] = event.convertToJson();
        index++;
    }

    return response(200,jsonWriteValue.dump());
}

response searchVenue(string searchString)
{
    vector<Event> found;
    //For each string/Event pair in the event map
    for(pair<string, Event> eventPair : eventMap)
    {
        if(eventPair.second.getWhere().getCity().find(searchString) != string::npos)
            found.push_back(eventPair.second);
    }

    json::wvalue jsonWriteValue;

    int index = 0;
    for(Event event : found)
    {
        jsonWriteValue[index] = event.convertToJson();
        index++;
    }

    return response(200,jsonWriteValue.dump());
}

struct
{
    bool operator()(pair<string, Event>& a, pair<string,Event>& b)
    {
        //substring of certain indices of the format MM/DD/YYYY
        string year_a = a.second.getDate().substr(6,4);
        string year_b = b.second.getDate().substr(6,4);
        string month_a = a.second.getDate().substr(0,2);
        string month_b = b.second.getDate().substr(0,2);
        string day_a = a.second.getDate().substr(3,2);
        string day_b = b.second.getDate().substr(3,2);

        if(year_a < year_b)
            return true;
        if(year_a == year_b && month_a < month_b)
            return true;
        if(year_a == year_b && month_a == month_b && day_a < day_b)
            return true;

        return false;
    }
} comparatorDate;

response sortDates()
{
    vector<pair<string, Event>> eventsToSort;

    for (pair<string, Event> eventPair : eventMap)
    {
        eventsToSort.push_back(eventPair);
    }

    
    
    sort(eventsToSort.begin(), eventsToSort.end(), comparatorDate);

    json::wvalue jsonWriteValue;

    int index = 0;
    for(pair<string, Event> eventPair : eventsToSort)
    {
        jsonWriteValue[index] = eventPair.second.convertToJson();
        index++;
    }

    return response(200, jsonWriteValue.dump());
}

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
    //If there is a sort parameter on the request, then sort the sizes
    if(req.url_params.get("sort"))
    {
        return sortDates();
    }

    if(req.url_params.get("artist"))
    {
        return searchArtist(req.url_params.get("artist"));
    }

    if(req.url_params.get("location"))
    {
        return searchVenue(req.url_params.get("location"));
    }

    if(req.url_params.get("past"))
    {
        return readPastEvents();
    }

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
    if(req.url_params.get("finished"))
    {
        try
        {
            // Get the event from the event map
            Event event = eventMap.at(id);

            PastEvent finishedEvent(event.getId(), event.getArtist(), event.getWhere(), event.getDate(), event.getTime());

            //adds it to pastMap
            pastMap[id] = finishedEvent;
            //update the event
            eventMap.erase(id);

            //return the updated event as a JSON string
            res.code = 200;
            res.set_header("Content-Type", "application/json");
            res.write(event.convertToJson().dump());
            res.end();
        }
        catch(out_of_range& exception)
        {
            res.code = 404;
            res.end("Event Not Found");
        }
    }

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
        res.end();
    }
    catch(out_of_range& exception)
    {
        res.code = 404;
        res.end("Event Not Found");
    }
}

response deleteEvent(string id)
{
    try
    {
        Event event = eventMap.at(id);

        eventMap.erase(id);

        return response(204);
    }
    catch(out_of_range& exception)
    {
        return response(404, "Event not found");
    }
}

void addReview(request req, response& res, string id)
{
    try
    {
        // Get the event from the event map
        PastEvent event = pastMap.at(id);

        //Convert the request  body to json
        json::rvalue readValueJson = json::load(req.body);

        if(!readValueJson)
        {
            res.code = 400;
            res.end("Invalid Json");
            return;
        }

        //update the event
        event.addReview(readValueJson["new review"].s());
        pastMap[id] = event;

        //return the updated event as a JSON string
        res.code = 200;
        res.set_header("Content-Type", "application/json");
        res.write(event.convertToJson().dump());
        res.end();
    }
    catch(out_of_range& exception)
    {
        res.code = 404;
        res.end("Event Not Found");
    }
}

