#include <crow.h>
#include <map>
#include <string>
#include "Venue.h"

using namespace std;
using namespace crow;

extern map<string, Venue> venueMap;

response createVenue(request req) 
{
    string apiKeyHeader = "Authorization";
    string expectedApiKey = "Key";
    
    // Validate the api key in the request header.
    if (!req.headers.count(apiKeyHeader) || req.headers.find(apiKeyHeader)->second != expectedApiKey) 
    {
        return response(403, "Forbidden");
    }

    // Load the request body string into a JSON read value.
    json::rvalue readValueJson = json::load(req.body);

    // If there was a problem converting the body text to JSON return an error.
    if (!readValueJson) 
        return response(400, "Invalid JSON");
    
    // Create a new venue.
    Venue venue{readValueJson["city"].s(), readValueJson["address"].s(), readValueJson["cost"].d()};

    // Add the new Venue to the map.
    venueMap[venue.getCity()] = venue;

    // Return the created venue as a JSON string.
    return response(201, venue.convertToJson().dump());
}

response readVenue(string city) 
{
    try 
    {
        // Get the venue from the venue map.
        Venue venue = venueMap.at(city);

        // Return the venue as a JSON string.
        return response(venue.convertToJson().dump());
    } 
    catch (out_of_range& exception) 
    {
        // If the venue was not found in the map return a 404 not found error.
        return response(404, "Venue Not Found");
    }
}

response readAllVenues(request req) 
{
    // Create a new JSON write value use to write to the file.
    json::wvalue jsonWriteValue;
    
    // For each venue in the map, convert the venue to JSON and add to the write value.
    int index = 0;
    for (pair<string, Venue> keyValuePair : venueMap)
    {
        // first: gives you access to the first item in the pair.
        // second: gives you access to the second item in the pair.
        jsonWriteValue[index] =keyValuePair.second.convertToJson();
        index++;
    }

    return response(jsonWriteValue.dump());
}

void updateVenue(request req, response& res, string city) 
{
    string apiKeyHeader = "Authorization";
    string expectedApiKey = "Key";
    
    // Validate the api key in the request header.
    if (!req.headers.count(apiKeyHeader) || req.headers.find(apiKeyHeader)->second != expectedApiKey) 
    {
        res.code = 403; // Unauthorized
        res.end("Forbidden");
        return;
    }

    try 
    {
        // Get the venue from the venue map.
        Venue venue = venueMap.at(city);

        // Convert the request body to JSON.
        json::rvalue readValueJson = json::load(req.body);

        // If there was a problem converting the body text to JSON return an error.
        if (!readValueJson) 
        {
            res.code = 400;
            res.end("Invalid JSON");
            return;
        }

        // Update the venue.
        venue.setAddress(readValueJson["address"].s());
        venue.setCost(readValueJson["cost"].d());
        venueMap[city] = venue;

        // Return the updated venue as a JSON string.
        res.code = 200;
        res.set_header("Content-Type", "application/json");
        res.write(venue.convertToJson().dump());
        res.end();
    } 
    catch (out_of_range& exception) 
    {
        // If the venue was not found in the map return a 404 not found error.
        res.code = 404;
        res.end("Venue Not Found");
    }
}

response deleteVenue(request req, string city) 
{
    string apiKeyHeader = "Authorization";
    string expectedApiKey = "Key";
    
    // Validate the api key in the request header.
    if (!req.headers.count(apiKeyHeader) || req.headers.find(apiKeyHeader)->second != expectedApiKey) 
    {
        return response(403, "Forbidden");
    }

    try 
    {
        // Get the venue from the venue map.
        Venue venue = venueMap.at(city);

        // Remove the venue from the venue map.
        venueMap.erase(city);

        // Return a successful code 204 which means success but no content to return.
        return response(204);
    } 
    catch (out_of_range& exception) 
    {
        // If the venue was not found in the map return a 404 not found error.
        return response(404, "Venue not found");
    }
}