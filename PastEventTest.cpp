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

    SUBCASE("Testing convertoJson Method")
    {
        crow::json::wvalue jsonOutput = finished.convertToJson();
        crow::json::rvalue jsonReadValue = crow::json::load(jsonOutput.dump());
        
        CHECK(jsonReadValue["id"].s() == "4");
        CHECK(jsonReadValue["date"].s() == "12/12/2004");
        CHECK(jsonReadValue["time"].s() == "2:32");
        CHECK(jsonReadValue["artist"]["name"].s() == "Name");
        CHECK(jsonReadValue["venue"]["city"].s() == "City");
        for(crow::json::rvalue review : jsonReadValue["reviews"])
        {
            CHECK(review.s() == "Good");
        }
    }

    SUBCASE("Testing updateFromJson Method")
    {


    }
}