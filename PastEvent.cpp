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

std::string PastEvent::addReview(string review)
{
    reviews.push_back(review);
    return reviews.back();
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
    return writeValueJson;
    return writeValueJson;
}

void PastEvent::updateFromJson(crow::json::rvalue readValueJson)
{
    setId(readValueJson["id"].s());
    setArtist(artistMap.at(readValueJson["artist"]["name"].s()));
    setWhere(venueMap.at(readValueJson["venue"]["city"].s()));
    setWhen(readValueJson["date"].s(), readValueJson["time"].s());
    reviews.clear();
    
    for(crow::json::rvalue review : readValueJson["reviews"])
    {
        reviews.push_back(review.s());
    }
    return;
}