#include <crow.h>
#include <map>
#include <string>
#include "Artist.h"

using namespace std;
using namespace crow;

extern map<string, Artist> artistMap;

json::wvalue convertArtistToJson(Artist artist)
{
    json::wvalue writeValueJson;
    writeValueJson["name"] = artist.getName();
    writeValueJson["type"] = artist.getDescription();
    writeValueJson["cost"] = artist.getCost();
    return writeValueJson;
}

response createArtist(request req) 
{
    // Load the request body string into a JSON read value.
    json::rvalue readValueJson = json::load(req.body);

    // If there was a problem converting the body text to JSON return an error.
    if (!readValueJson) 
        return response(400, "Invalid JSON");
    
    // Create a new artist.
    Artist artist{readValueJson["name"].s(), readValueJson["type"].s(), readValueJson["cost"].d()};

    // Add the new Artist to the map.
    artistMap[artist.getName()] = artist;

    // Return the created artist as a JSON string.
    return response(201, convertArtistToJson(artist).dump());
}

response readArtist(string name) 
{
    try 
    {
        // Get the artist from the artist map.
        Artist artist = artistMap.at(name);

        // Return the artist as a JSON string.
        return response(convertArtistToJson(artist).dump());
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
        jsonWriteValue[index] = convertArtistToJson(keyValuePair.second);
        index++;
    }

    return response(jsonWriteValue.dump());
}

void updateArtist(request req, response& res, string name) 
{
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
        res.write(convertArtistToJson(artist).dump());
        res.end();
    } 
    catch (out_of_range& exception) 
    {
        // If the artist was not found in the map return a 404 not found error.
        res.code = 404;
        res.end("Artist Not Found");
    }
}

response deleteArtist(string name) 
{
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

void saveToFile(map<string, Artist> data, string filename)  
{
    // Open the file for writing
    ofstream file(filename);

    if (file.is_open()) 
    {
        // Create a new JSON write value use to write to the file.
        json::wvalue jsonWriteValue;
        
        // For each object in the map, convert the object to JSON and add to the write value.
        int index = 0;
        for (pair<string, Artist> keyValuePair : data)
        {
            // first: gives you access to the first item in the pair.
            // second: gives you access to the second item in the pair.
            jsonWriteValue[index] = convertArtistToJson(keyValuePair.second);
            index++;
        }

        // Write the JSON to the file.
        file << jsonWriteValue.dump();
        file.close();
    }
}


map<string, Artist> loadFromFile(string filename) 
{
    map<string, Artist> data;
    
    // Open the file for reading.
    ifstream file(filename);

    // If the file is open. 
    if (file.is_open()) 
    {      
        // Create a stream for reading in the file.
        ostringstream stringStreamJson;

        // Read the entire JSON string.
        stringStreamJson << file.rdbuf();

        // Load the string into a JSON read value object.
        json::rvalue jsonReadValue = json::load(stringStreamJson.str());

        // Close the file.
        file.close();

        // For each item in the JSON convert it to an object, 
        // and add it to the data map.
        for (json::rvalue item : jsonReadValue) 
        {
            Artist artist{item["name"].s(), item["type"].s(), item["cost"].d()};
            data[artist.getName()] = artist;
        }
    }
    
    return data;
}