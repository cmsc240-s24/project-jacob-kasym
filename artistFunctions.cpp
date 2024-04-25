#include <crow.h>
#include <map>
#include <string>
#include "Artist.h"

using namespace std;
using namespace crow;

extern map<string, Artist> artistMap;

response createArtist(request req) 
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
        return response(400, "Bad Request");
    
    // Create a new artist.
    Artist artist{readValueJson["name"].s(), readValueJson["type"].s(), readValueJson["cost"].d()};

    // Add the new Artist to the map.
    artistMap[artist.getName()] = artist;

    // Return the created artist as a JSON string.
    return response(201, artist.convertToJson().dump());
}

response readArtist(string name) 
{
    try 
    {
        // Get the artist from the artist map.
        Artist artist = artistMap.at(name);

        // Return the artist as a JSON string.
        return response(artist.convertToJson().dump());
    } 
    catch (out_of_range& exception) 
    {
        // If the artist was not found in the map return a 404 not found error.
        return response(404, "Artist Not Found");
    }
}

response readAllArtists(request req) 
{
    // Create a new JSON write value use to write to the file.
    json::wvalue jsonWriteValue;
    
    // For each artist in the map, convert the artist to JSON and add to the write value.
    int index = 0;
    for (pair<string, Artist> keyValuePair : artistMap)
    {
        // first: gives you access to the first item in the pair.
        // second: gives you access to the second item in the pair.
        jsonWriteValue[index] =keyValuePair.second.convertToJson();
        index++;
    }

    return response(jsonWriteValue.dump());
}

void updateArtist(request req, response& res, string name) 
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
        // Get the artist from the artist map.
        Artist artist = artistMap.at(name);

        // Convert the request body to JSON.
        json::rvalue readValueJson = json::load(req.body);

        // If there was a problem converting the body text to JSON return an error.
        if (!readValueJson) 
        {
            res.code = 400;
            res.end("Invalid JSON");
            return;
        }

        // Update the artist.
        artist.setDescription(readValueJson["type"].s());
        artist.setCost(readValueJson["cost"].d());
        artistMap[name] = artist;

        // Return the updated artist as a JSON string.
        res.code = 200;
        res.set_header("Content-Type", "application/json");
        res.write(artist.convertToJson().dump());
        res.end();
    } 
    catch (out_of_range& exception) 
    {
        // If the artist was not found in the map return a 404 not found error.
        res.code = 404;
        res.end("Artist Not Found");
    }
}

response deleteArtist(request req, string name) 
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
        // Get the artist from the artist map.
        Artist artist = artistMap.at(name);

        // Remove the artist from the artist map.
        artistMap.erase(name);

        // Return a successful code 204 which means success but no content to return.
        return response(204);
    } 
    catch (out_of_range& exception) 
    {
        // If the artist was not found in the map return a 404 not found error.
        return response(404, "Artist not found");
    }
}