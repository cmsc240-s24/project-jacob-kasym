#ifndef ARTIST_FUNCTIONS_H
#define ARTIST_FUNCTIONS_H

#include <crow.h>
#include <map>
#include <string>
#include "Artist.h"

//Functions for GET/POST/PUT/DELETE
crow::response createArtist(crow::request req);
crow::response readArtist(std::string name);
crow::response readAllArtists(crow::request req);
void updateArtist(crow::request req, crow::response& res, std::string name);
crow::response deleteArtist(std::string name);

#endif