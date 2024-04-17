/**
 * @file Artist.h
 * @brief The header for the Artist Class.
*/
#ifndef ARTIST_H
#define ARTIST_H

#include <string>
#include <vector>

/**
 * @class Artist
 * @brief A class that represents a touring Artist.
 * 
 *  description
*/
class Artist
{
private:
    std::string name;
    std::vector<std::string> members;
    std::string type;
public:
    /**
     * @brief Basic constructor with no members.
     * @param initialName The string of the name.
     * @param initialType The string of the description.
     * @exception invalid_argument If the name is blank.
     * @exception invalid_argument If the description is blank.
    */
    Artist(std::string initialName, std::string initialType);

    /**
     * @brief Constructor with one member.
     * @param initialName The string of the name.
     * @param initialType The string of the description.
     * @param firstMember The string name of the member.
     * @exception invalid_argument If the name is blank.
     * @exception invalid_argument If the description is blank.
     * @exception invalid_argument If the member is blank.
    */
    Artist(std::string initialName, std::string initialType, std::string firstMember);

    /**
     * @brief Constructor with multiple members.
     * @param initialName The string of the name.
     * @param initialType The string of the description.
     * @param initialMembers The string vector of the members.
     * @exception invalid_argument If the name is blank.
     * @exception invalid_argument If the description is blank.
     * @exception invlaide_argument If any member is blank.
    */
    Artist(std::string initialName, std::string initialType, std::vector<std::string> initialMembers);
    
    /**
     * @brief Shows the name of the artist.
     * @return The string name.
    */
    std::string getName() { return name; }
    
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
    std::string getDescription() { return type; }

    /**
     * @brief Changes the description of the artist.
     * @param newType The new description.
     * @return The new description.
     * @exception invalid_argument If the new description is blank.
    */
    std::string setDescription(std::string newType);

    /**
     * @brief Shows everyone who is in the Artist group.
     * @return The vector of members.
    */
    std::vector<std::string> getMembers() { return members; }

    /**
     * @brief Adds a new member to the members vector.
     * @param newMember The member string to be added.
     * @return The new member.
     * @exception invalid_argument If the new member is blank.
    */
    std::string addMember(std::string newMember);
};

#endif