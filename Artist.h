/**
 * @file Artist.h
 * @brief The header for the Artist Class.
*/
#ifndef ARTIST_H
#define ARTIST_H

#include <string>
#include <vector>

template <typename T>
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
    T cost;
public:
    /**
     * @brief The constructor.
     * @param initialName The string of the name.
     * @param initialType The string of the description.
     * @param initialCost The cost.
     * @exception invalid_argument If the name is blank.
     * @exception invalid_argument If the description is blank.
    */
    Artist(std::string initialName, std::string initialType, T initialCost);
    
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
    T getCost();

    /**
     * @brief Changes the cost of the artist.
     * @return The new cost.
    */
    T setCost(T newCost);   
};

#include "Artist.cpp"

#endif