#include <crow.h>
#include <map>
#include <string>
#include "Artist.h"
#include "Venue.h"
//#include "Event.h"
//#include "PastEvent.h"
#include "artistFunctions.h"
#include "venueFunctions.h"
#include "templateSaving.h"

using namespace std;
using namespace crow;

//map to store Artists
map<string, Artist> artistMap = loadFromFile<Artist>("artists.json");
//map to store Venues
map<string, Venue> venueMap = loadFromFile<Venue>("venues.json");
//map to store future Events
//map<string, Event> eventMap = loadFromFile<Event>("events.json");
//map to store Past Events
//map<string, PastEvent> pastMap;

int main()
{

    SimpleApp app;


    // Artists
    CROW_ROUTE(app, "/api/artists").methods("POST"_method)(createArtist);
    CROW_ROUTE(app, "/api/artists").methods("GET"_method)(readAllArtists);
    CROW_ROUTE(app, "/api/artists/<string>").methods("GET"_method)(readArtist);
    CROW_ROUTE(app, "/api/artists/<string>").methods("PUT"_method)(updateArtist);
    CROW_ROUTE(app, "/api/artists/<string>").methods("DELETE"_method)(deleteArtist);

    // Venues
    CROW_ROUTE(app, "/api/venues").methods("POST"_method)(createVenue);
    CROW_ROUTE(app, "/api/venues").methods("GET"_method)(readAllVenues);
    CROW_ROUTE(app, "/api/venues/<string>").methods("GET"_method)(readVenue);
    CROW_ROUTE(app, "/api/venues/<string>").methods("PUT"_method)(updateVenue);
    CROW_ROUTE(app, "/api/venues/<string>").methods("DELETE"_method)(deleteVenue);


    app.port(19455).run();

    saveToFile<Artist>(artistMap, "artists.json");
    saveToFile<Venue>(venueMap, "venues.json");
    //saveToFile<Event>(futureMap, "events.json");

}