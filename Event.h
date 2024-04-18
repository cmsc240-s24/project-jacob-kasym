/**
 * @file Event.h
 * @brief The header for the Event Class.
*/

#ifndef EVENT_H
#define EVENT_H
#include <string>
#include "Artist.h"
#include "Venue.h"

/**
 * @class Event
 * @brief A class that represents an Event.
 * 
 *  Has basic functionality to get and set artist, date and time, costs for an event.
*/
class Event
{
private: 
    std::string id;
    Artist artist;
    template <typename T>
    Venue<T> location;
    std::string date;
    std::string time;


public:
    /**
     * @brief Constructor for the Event class.
     * @param string id : Initial id of the event
     * @param Artist artist : artist of the event
     * @param Venue location : location where the event is going to be held
     * @param string date : date of the event
     * @param string time : time of the event
    */
    Event(std::string id, Artist artist, Venue location, std::string date, std::string time);

    /**
     * @brief Getting id of the event
     * @return string id of the event
    */
    std::string getId();

    /**
     * @brief Update id of the event
     * @param string id : new id of the event
    */
    void setId(string id);

    /**
     * @brief Getting artist of the event
     * @return Artist artist of the event
    */
    Artist getArtist();

    /**
     * @brief Update artist of the event
     * @param Artist artist : new artist for the event
    */
    void setArtist(Artist artist);

    /**
     * @brief Getting cost of the event ticket
     * @return T cost of the event
    */
    float getCost();

    /**
     * @brief Getting date and time of the event
     * @return string representation of date and time
    */
    std::string getWhen();

    /**
     * @brief Update date and time of the event
     * @param string date : new date of the event
     * @param string time : new time of the event
    */
    void setWhen(std::string date, std::string time);

    /**
     * @brief Getting location of the event in string form
     * @return string representation of location of the event
    */
    std::string getWhere();

    /**
     * @brief Update location of the event
     * @param Venue location : new location of the event
    */
    void setWhere(Venue location);
};

#endif