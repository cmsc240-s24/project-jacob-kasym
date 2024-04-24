#ifndef TEMPLATESAVING_H
#define TEMPLATESAVING_H

#include <map>
#include <string>

template <typename T>
void saveToFile(std::map<std::string, T> data, std::string filename);

template <typename T>
std::map<std::string, T> loadFromFile(std::string filename);

#include "templateSaving.cpp"

#endif