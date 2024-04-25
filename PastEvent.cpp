#include "PastEvent.h"
#include <stdlib.h>
#include <time.h>
using namespace std;
extern map<string, Artist> artistMap;
extern map<string, Venue> venueMap;

PastEvent::PastEvent(std::string id, Artist artist, Venue location, std::string date, std::string time) : Event(id, artist, location, date, time){
    
}

PastEvent::PastEvent(crow::json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
}

std::string PastEvent::getReview()
{
    return reviews.at(rand()%reviews.size());
}

void PastEvent::addReview(string review)
{
    reviews.push_back(review);
}

crow::json::wvalue PastEvent::convertToJson()
{
    crow::json::wvalue writeValueJson;
    writeValueJson["id"] = id;
    writeValueJson["artist"]["name"] = artist.getName();
    writeValueJson["venue"]["city"]= location.getCity();
    writeValueJson["date"] = date;
    writeValueJson["time"] = time;
    int index = 0;
    for(string review : reviews)
    {
        writeValueJson["reviews"][index] = review;
        index++;
    }
}

void PastEvent::updateFromJson(crow::json::rvalue readValueJson)
{
    setId(readValueJson["id"].s());
    setArtist(artistMap.at(readValueJson["artist"]["name"].s()));
    setWhere(venueMap.at(readValueJson["venue"]["city"].s()));
    setWhen(readValueJson["date"].s(), readValueJson["time"].s());
    reviews.clear();
    reviews = readValueJson["reviews"].lo();
    int index = 0;
    for(crow::json::rvalue keyValue : readValueJson["reviews"].lo())
    {
        reviews.push_back(keyValue[index].s());
        index++;
    }
}