/**
 * @file 1
 * @brief 1
*/

#include <stdexcept>

#include "Artist.h"
using namespace std;



/**
 * @brief Changes the description of the artist.
 * @param newType the New Description.
 * @exception invalid_argument If the new description is blank.
*/
void setDescription(string newType)
{
    if (newType == "")
    {
        throw invalid_argument("New Description can not be blank");
    }
    type = newType;
}

/**
 * @brief Adds a new member to the members vector.
 * @param newMember The member string to be added.
 * @exception invalid_argument If the new member is blank.
*/
void Artist::addMember(string newMember)
{
    if (newMember == "")
    {
        throw invalid_argument("New Member can not be blank");
    }
    members.pushback(newMember);
}