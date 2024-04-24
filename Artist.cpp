/**
 * @file Artist.cpp
 * @brief Definitions of certain functions.
*/

#include <stdexcept>

#include "Artist.h"
using namespace std;
using namespace crow;

Artist::Artist(string initialName, string initialType, double initialCost)
{
    setName(initialName);
    setDescription(initialType);
    setCost(initialCost);
}

Artist::Artist(crow::json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
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

double Artist::getCost()
{
    return cost;
}

double Artist::setCost(double newCost)
{
    if (newCost < 0)
    {
        throw invalid_argument("New cost can not be negative");
    }
    cost = newCost;
    return cost;
}

json::wvalue Artist::convertToJson()
{
    json::wvalue writeValueJson;
    writeValueJson["name"] = name;
    writeValueJson["type"] = type;
    writeValueJson["cost"] = cost;
    return writeValueJson;
}

void Artist::updateFromJson(crow::json::rvalue readValueJson)
{
    setName(readValueJson["name"].s());
    setDescription(readValueJson["type"].s());
    setCost(readValueJson["cost"].d());
}