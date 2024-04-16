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
public:
    Artist() { }
    Artist(std::string initialName, std::string initialType)
        : name(initialName), type(initialType) { }
    Artist(std::string initialName, std::string initialType, std::string firstMember)
        : name(initialName), type(initialType) { members.pushback(firstmember); }
    Artist(std::string initialName, std::string initialType, vector<std::string> initialMembers)
        : name(initialName), type(initialType), members(initialMembers) { }
    std::string getName() { return name; }
    void setName(std::string newName); { name = newName; }
    std::string getDescription(); { return type; }

    /**
     * @brief Changes the description of the artist.
     * @param newType the New Description.
     * @exception invalid_argument If the new description is blank.
    */
    void setDescription(std::string newType) { type = newType; }

    /**
     * @brief Shows everyone who is in the Artist group.
     * @return The vector of members.
    */
    vector<std::string> getMembers() { return members; }

    /**
     * @brief Adds a new member to the members vector.
     * @param newMember The member string to be added.
     * @exception invalid_argument If the new member is blank.
    */
    void addMember(std::string newMember);
private:
    std::string name;
    vector<std::string> members;
    std::string type;
};

#endif