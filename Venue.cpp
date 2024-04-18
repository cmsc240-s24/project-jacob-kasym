/**
 * @file Venue.cpp
 * @brief Definitions of certain functions.
*/

#include <stdexcept>

#include "Venue.h"
using namespace std;

template <typename T>
Venue<T>::Venue(string initialCity, string initialAddress, T initialCapacity, double initialCost)
{
    setCity(initialCity);
    setAddress(initialAddress);
    setCapacity(initialCapacity);
    setCost(initialCost);
}

template <typename T>
string Venue<T>::getCity()
{
    return city;
}

template <typename T>
string Venue<T>::setCity(string newCity)
{
    if (newCity == "")
    {
        throw invalid_argument("New city can not be blank");
    }
    city = newCity;
    return city;
}

template <typename T>
string Venue<T>::getAddress()
{
    return address;
}

template <typename T>
string Venue<T>::setAddress(string newAddress)
{
    if (newAddress == "")
    {
        throw invalid_argument("New address can not be blank");
    }
    address = newAddress;
    return address;
}

template <typename T>
T Venue<T>::getCapacity()
{
    return size;
}

template <typename T>
T Venue<T>::setCapacity(T newCapacity)
{
    size = newCapacity;
    return size;
}

template <typename T>
double Venue<T>::getCost()
{
    return cost;
}

template <typename T>
double Venue<T>::setCost(double newCost)
{
    if (newCost < 0)
    {
        throw invalid_argument("New cost can not be negative");
    }
    cost = newCost;
    return cost;
}