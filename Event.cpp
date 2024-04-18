/**
 * @file Event.cpp
 * @brief Definitions of certain functions.
*/
#include "Event.h"
using namespace std;

Event::Event(std::string id, Artist artist, Venue location, std::string date, std::string time)
{
    this.id = id;
    this.artist = artist;
    this.location = location;
    this.date = date
    this.time = time;
}

string Event::getId()
{
    return id;
}

Artist Event::getArtist()
{
    return artist;
}

void Event::setArtist(Artist artist)
{
    this.artist = artist;
}

float Event::getCost()
{
    return location.getCost() + artist.getCost();
}

string Event::getWhen()
{
    return "Date: "+date+" at "+time;
}

void Event::setWhen(string date, string time);
{
    this.date = date;
    this.time = time;
}

string Event::getWhere()
{
    return "City: "+location.getCity() + " at "+location.getAddress();
}

void Event::setWhere(Venue location)
{
    this.location = location;
}

