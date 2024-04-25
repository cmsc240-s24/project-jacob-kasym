/**
 * @file Venue.h
 * @brief The header for the Venue Class.
*/
#ifndef VENUE_H
#define VENUE_H

#include <crow.h>
#include <string>

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
    double cost;
public:
    
    /**
     * @brief The construtor for direct parameters.
     * @param initialCity The string of the city.
     * @param initialAdress The string of the adress.
     * @param initialSize The size.
     * @param initialCost The float for the cost.
     * @exception invalid_argument If the city is blank.
     * @exception invalid_argument If the address is blank.
     * @exception invalid_argument If the cost is negative.
    */
    Venue(std::string initialCity, std::string initialAddress, double initialCost);

    /**
     * @brief The constructor for json.
     * @param readValueJson The json form of the venue
     * @exception invalid_argument If the city is blank.
     * @exception invalid_argument If the address is blank.
     * @exception invalid_argument If the cost is negative.
    */
    Venue(crow::json::rvalue readValueJson);

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
     * @brief Shows the cost of the venue.
     * @return The cost.
    */
    double getCost();

    /**
     * @brief Changes the cost of the venue.
     * @return The new cost.
    */
    double setCost(double newCost);

    /**
     * @brief Coverts the Venue instance into json.
     * @return The json form of the venue.
    */
    crow::json::wvalue convertToJson();

    /**
     * @brief Updates an venue instance from given json.
     * @param readValueJson The json to be read.
     * @exception invalid_argument If the city is blank.
     * @exception invalid_argument If the address is blank.
     * @exception invalid_argument If the cost is negative.
    */
    void updateFromJson(crow::json::rvalue readValueJson);

    std::string getId() {return city;}
};

#endif