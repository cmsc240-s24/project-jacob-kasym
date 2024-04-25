#include <crow.h>
#include <map>
#include <string>
#include "Artist.h"
#include "Venue.h"
#include "Event.h"
//#include "PastEvent.h"
#include "artistFunctions.h"
#include "venueFunctions.h"
#include "eventFunctions.h"
#include "templateSaving.h"


using namespace std;
using namespace crow;

//map to store Artists
map<string, Artist> artistMap = loadFromFile<Artist>("artists.json");
//map to store Venues
map<string, Venue> venueMap = loadFromFile<Venue>("venues.json");
//map to store future Events
map<string, Event> eventMap = loadFromFile<Event>("events.json");
//map to store Past Events
//map<string, PastEvent> pastMap;

int main()
{

    SimpleApp app;

    // Events
    CROW_ROUTE(app, "/api/events").methods("POST"_method)(createEvent);
    CROW_ROUTE(app, "/api/events").methods("GET"_method)(readAllEvents);
    CROW_ROUTE(app, "/api/events/<string>").methods("GET"_method)(readEvent);
    CROW_ROUTE(app, "/api/events/<string>").methods("PUT"_method)(updateEvent);
    CROW_ROUTE(app, "/api/events/<string>").methods("DELETE"_method)(deleteEvent);
    // CROW_ROUTE(app, "api/events?artist=<string>").methods("GET"_method)(searchArtist);
    // CROW_ROUTE(app, "api/events?location=<string>").methods("GET"_method)(searchVenue);


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
    saveToFile<Event>(eventMap, "events.json");

}