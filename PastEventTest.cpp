#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <crow.h>
#include <string>
#include "PastEvent.h"
#include <map>

//map to store Artists
std::map<std::string, Artist> artistMap;
//map to store Venues
std::map<std::string, Venue> venueMap;

TEST_CASE("Testing Past Event class functionality")
{
    Artist art1("Name", "Type", 2.3);
    artistMap.insert({"Name", art1});
    Venue ven1("City", "Address", 2.5);
    venueMap.insert({"City", ven1});

    PastEvent finished("4", art1, ven1, "12/12/2004", "2:32");

    SUBCASE("Testing addReview Method")
    {
        CHECK(finished.addReview("Good") == "Good");
    }

    finished.addReview("Good");

    SUBCASE("Testing getReview Method")
    {
        CHECK(finished.getReview() == "Good");
    }
}