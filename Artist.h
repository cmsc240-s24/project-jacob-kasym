/**
 * @file Artist.h
 * @brief The header for the Artist Class.
*/
#ifndef ARTIST_H
#define ARTIST_H

#include <crow.h>
#include <string>

/**
 * @class Artist
 * @brief A class that represents a touring Artist.
 * 
 *  Has basic functionality to get and set member variables.
*/
class Artist
{
private:
    std::string name;
    std::string type;
    double cost;
public:
    Artist() { }    
    /**
     * @brief The constructor for direct parameters.
     * @param initialName The string of the name.
     * @param initialType The string of the description.
     * @param initialCost The float of the cost.
     * @exception invalid_argument If the name is blank.
     * @exception invalid_argument If the description is blank.
     * @exception invalid_argument If the cost is negative.
    */
    Artist(std::string initialName, std::string initialType, double initialCost);
    
    /**
     * @brief The constructor for json.
     * @param readValueJson The json form of the artist
     * @exception invalid_argument If the name is blank.
     * @exception invalid_argument If the description is blank.
     * @exception invalid_argument If the cost is negative.
    */
    Artist(crow::json::rvalue readValueJson);

    /**
     * @brief Shows the name of the artist.
     * @return The string name.
    */
    std::string getName();
    
    /**
     * @brief Changes the name of the Artist.
     * @param newName The new name.
     * @return The new name.
     * @exception invalid_argument If the new name is blank.
    */
    std::string setName(std::string newName);
    
    /**
     * @brief Shows the description of the artist.
     * @return The string description.
    */
    std::string getDescription();

    /**
     * @brief Changes the description of the artist.
     * @param newType The new description.
     * @return The new description.
     * @exception invalid_argument If the new description is blank.
    */
    std::string setDescription(std::string newType);

    /**
     * @brief Shows the cost of the artist.
     * @return The cost.
    */
    double getCost();

    /**
     * @brief Changes the cost of the artist.
     * @param newCost The float cost.
     * @return The new cost.
     * @exception invalid_argument If the cost is negative.
    */
    double setCost(double newCost);

    /**
     * @brief Coverts the Artist instance into json.
     * @return The json form of the artist.
    */
    crow::json::wvalue convertToJson();

    /**
     * @brief Updates an artist instance from given json.
     * @param readValueJson The json to be read.
     * @exception invalid_argument If the name is blank.
     * @exception invalid_argument If the description is blank.
     * @exception invalid_argument If the cost is negative.
    */
    void updateFromJson(crow::json::rvalue readValueJson);

    std::string getId() {return name;}
};

#endif