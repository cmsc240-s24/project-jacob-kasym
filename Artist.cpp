/**
 * @file Artist.cpp
 * @brief Definitions of certain functions.
*/

#include <stdexcept>

#include "Artist.h"
using namespace std;

template <typename T>
Artist<T>::Artist(string initialName, string initialType, T initialCost)
{
    setName(initialName);
    setDescription(initialType);
    setCost(initialCost);
}

template <typename T>
string Artist<T>::getName()
{
    return name;
}

template <typename T>
string Artist<T>::setName(string newName)
{
    if (newName == "")
    {
        throw invalid_argument("New name can not be blank");
    }
    name = newName;
    return name;
}

template <typename T>
string Artist<T>::getDescription()
{
    return type;
}

template <typename T>
string Artist<T>::setDescription(string newType)
{
    if (newType == "")
    {
        throw invalid_argument("New description can not be blank");
    }
    type = newType;
    return type;
}

template <typename T>
T Artist<T>::getCost()
{
    return cost;
}

template <typename T>
T Artist<T>::setCost(T newCost)
{
    cost = newCost;
    return cost;
}