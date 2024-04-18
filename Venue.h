/**
 * @file Venue.h
 * @brief The header for the Venue Class.
*/
#ifndef VENUE_H
#define VENUE_H

#include <string>
#include <vector>

template <typename T>
/**
 * @class Venue
 * @brief A class that represents a Venue.
 * 
 *  Has basic functionality to get and set member variables.
*/
class Venue
{
private:
    std::string city;
    std::string address;
    int capacity;
    T cost;
public:
    /**
     * @brief The construtor.
     * @param initialCity The string of the city.
     * @param initialAdress The string of the adress.
     * @param initialCapacity The int for the capacity.
     * @param initialCost The cost.
     * @exception invalid_argument If the city is blank.
     * @exception invalid_argument If the address is blank.
     * @exception invalid_argument If the capacity is non-positive.
    */
    Venue(std::string initialCity, std::string initialAddress, int initialCapacity, T initialCost);
    
    /**
     * @brief Shows the city of the venue.
     * @return The string city.
    */
    std::string getCity();
    
    /**
     * @brief Changes the city of the Venue.
     * @param newCity The new city.
     * @return The new city.
     * @exception invalid_argument If the new city is blank.
    */
    std::string setCity(std::string newCity);
    
    /**
     * @brief Shows the address of the venue.
     * @return The string address.
    */
    std::string getAddress();

    /**
     * @brief Changes the address of the venue.
     * @param newAddress The new address.
     * @return The new address.
     * @exception invalid_argument If the new address is blank.
    */
    std::string setAddress(std::string newAddress);

    /**
     * @brief Shows the capacity of the venue.
     * @return The int capacity.
    */
    int getCapacity();

    /**
     * @brief Changes the capacity of the venue.
     * @return The new capacity.
     * @exception invalid_argument If the capcity is non-postive.
    */
    int setCapacity(int newCapacity);

    /**
     * @brief Shows the cost of the venue.
     * @return The cost.
    */
    T getCost();

    /**
     * @brief Changes the cost of the venue.
     * @return The new cost.
    */
    T setCost(T newCost);
};

#include "Venue.cpp"

#endif