#include <crow.h>
#include <map>
#include <string>
#include "Artist.h"
#include "Venue.h"
#include "Event.h"
#include "PastEvent.h"
#include "artistFunctions.h"

using namespace std;
using namespace crow;

//map to store Artists
map<string, Artist> artistMap;

template <typename T>
map<string, Venue<T>> venueMap;