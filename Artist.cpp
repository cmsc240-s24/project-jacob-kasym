/**
 * @file Artist.cpp
 * @brief Definitions of certain functions.
*/

#include <stdexcept>

#include "Artist.h"
using namespace std;


Artist::Artist(string initialName, string initialType, float initialCost)
{
    setName(initialName);
    setDescription(initialType);
    setCost(initialCost);
}

string Artist::getName()
{
    return name;
}

string Artist::setName(string newName)
{
    if (newName == "")
    {
        throw invalid_argument("New name can not be blank");
    }
    name = newName;
    return name;
}

string Artist::getDescription()
{
    return type;
}

string Artist::setDescription(string newType)
{
    if (newType == "")
    {
        throw invalid_argument("New description can not be blank");
    }
    type = newType;
    return type;
}

float Artist::getCost()
{
    return cost;
}

float Artist::setCost(float newCost)
{
    if (newCost < 0)
    {
        throw invalid_argument("New cost can not be negative");
    }
    cost = newCost;
    return cost;
}