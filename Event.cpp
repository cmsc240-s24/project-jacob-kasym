/**
 * @file Event.cpp
 * @brief Definitions of certain functions.
*/
#include "Event.h"
using namespace std;

Event::Event(std::string iid, Artist iartist, Venue ilocation, std::string idate, std::string itime)
{
    id = iid;
    artist = iartist;
    location = ilocation;
    date = idate;
    time = itime;
}

string Event::getId()
{
    return id;
}

Artist Event::getArtist()
{
    return artist;
}

void Event::setArtist(Artist iartist)
{
    artist = iartist;
}

float Event::getCost()
{
    return location.getCost() + artist.getCost();
}

string Event::getWhen()
{
    return "Date: "+date+" at "+time;
}

void Event::setWhen(string idate, string itime)
{
    date = idate;
    time = itime;
}

string Event::getWhere()
{
    return "City: "+location.getCity() + " at "+location.getAddress();
}

void Event::setWhere(Venue ilocation)
{
    location = ilocation;
}

crow::json::wvalue Event::convertToJson()
{
    crow::json::wvalue writeValueJson;
    writeValueJson["id"] = id;
    writeValueJson["artist"]["name"] = artist.getName();
    writeValueJson["venue"]["city"] = location.getCity();
    writeValueJson["date"] = date;
    writeValueJson["time"] = time;
    return writeValueJson;
}





