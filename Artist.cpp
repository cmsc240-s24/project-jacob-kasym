/**
 * @file Artist.cpp
 * @brief Definitions of certain functions.
*/

#include <stdexcept>

#include "Artist.h"
using namespace std;

/**
 * @brief Basic constructor with no members.
 * @param initialName The string of the name.
 * @param initialType The string of the description.
 * @exception invalid_argument If the name is blank.
 * @exception invalid_argument If the description is blank.
*/
Artist::Artist(string initialName, string initialType)
{
    if (initialName == "")
    {
        throw invalid_argument("Name can not be blank");
    }
    if (initialType == "")
    {
        throw invalid_argument("Description can not be blank");
    }
    name = initialName;
    type = initialType;
}

/**
 * @brief Constructor with one member.
 * @param initialName The string of the name.
 * @param initialType The string of the description.
 * @param firstMember The string name of the member.
 * @exception invalid_argument If the name is blank.
 * @exception invalid_argument If the description is blank.
 * @exception invalid_argument If the member is blank.
*/
Artist::Artist(string initialName, string initialType, string firstMember)
{
    if (firstMember == "")
    {
        throw invalid_argument("Member can not be blank");
    }
    Artist(initialName, initialType);
    members.push_back(firstMember);
}

/**
 * @brief Constructor with multiple members.
 * @param initialName The string of the name.
 * @param initialType The string of the description.
 * @param initialMembers The string vector of the members.
 * @exception invalid_argument If the name is blank.
 * @exception invalid_argument If the description is blank.
 * @exception invlaide_argument If any member is blank.
*/
Artist::Artist(string initialName, string initialType, vector<string> initialMembers)
{ 
    for (int i = 0; i < initialMembers.size(); i++)
    {
        if (initialMembers.at(i) == "")
        {
            throw invalid_argument("Can not have a blank member");
        }
    }
    Artist(initialName, initialType);
    members = initialMembers;
}

/**
 * @brief Changes the name of the Artist.
 * @param newName The new name.
 * @return The new name.
 * @exception invalid_argument If the new name is blank.
*/
string Artist::setName(std::string newName)
{
    if (newName == "")
    {
        throw invalid_argument("New name can not be blank");
    }
    name = newName;
    return name;
}

/**
 * @brief Changes the description of the artist.
 * @param newType The new description.
 * @return The new description.
 * @exception invalid_argument If the new description is blank.
*/
string Artist::setDescription(string newType)
{
    if (newType == "")
    {
        throw invalid_argument("New description can not be blank");
    }
    type = newType;
    return type;
}

/**
 * @brief Adds a new member to the members vector.
 * @param newMember The member string to be added.
 * @return The new member.
 * @exception invalid_argument If the new member is blank.
*/
string Artist::addMember(string newMember)
{
    if (newMember == "")
    {
        throw invalid_argument("New member can not be blank");
    }
    members.push_back(newMember);
    return members.back();
}