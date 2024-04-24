/**
 * @file Venue.cpp
 * @brief Definitions of certain functions.
*/

#include <stdexcept>

#include "Venue.h"
using namespace std;


Venue::Venue(string initialCity, string initialAddress, double initialCost)
{
    setCity(initialCity);
    setAddress(initialAddress);
    setCost(initialCost);
}

string Venue::getCity()
{
    return city;
}

string Venue::setCity(string newCity)
{
    if (newCity == "")
    {
        throw invalid_argument("New city can not be blank");
    }
    city = newCity;
    return city;
}

string Venue::getAddress()
{
    return address;
}

string Venue::setAddress(string newAddress)
{
    if (newAddress == "")
    {
        throw invalid_argument("New address can not be blank");
    }
    address = newAddress;
    return address;
}

double Venue::getCost()
{
    return cost;
}

double Venue::setCost(double newCost)
{
    if (newCost < 0)
    {
        throw invalid_argument("New cost can not be negative");
    }
    cost = newCost;
    return cost;
}