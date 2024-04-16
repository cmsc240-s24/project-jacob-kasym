/**
 * @file Artist.h
 * @brief The header for the Artist Class
*/
#ifndef ARTIST_H
#define ARTIST_H

#include <string>

/**
 * @class Artist
 * @brief A class that represents a touring Artist
 * 
 * 
 *  description
*/
class Artist
{
public:
    Artist() {}
    Artist(std::string initialName, std::string initialType)
        : name(initialName), type(initialType) {}
    Artist(std::string initialName, std::string initialType, std::string firstMember)
        : name(initialName), type(initialType) {}
    std::string getName();
    void setName(std::string newName);
    std::string getDescription();
    void setDescription(std::string newType);
    std::string getMembers();
    void addMember(std::string newMember);
private:
    std::string name;
    std::string members;
    std::string type;
};

#endif