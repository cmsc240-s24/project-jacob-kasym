#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <crow.h>
#include <string>
#include "Event.h"

//map to store Artists
std::map<std::string, Artist> artistMap;
//map to store Venues
std::map<std::string, Venue> venueMap;

TEST_CASE("Testing Event class functionality")
{
    Artist art1("Name", "Type", 2.3);
    artistMap.insert({"Name", art1});
    Venue ven1("City", "Address", 2.5);
    venueMap.insert({"City", ven1});

    Event finished("4", art1, ven1, "12/12/2004", "2:32");

    SUBCASE("Testing convertoJson Method")
    {
        crow::json::wvalue jsonOutput = finished.convertToJson();
        crow::json::rvalue jsonReadValue = crow::json::load(jsonOutput.dump());
        
        CHECK(jsonReadValue["id"].s() == "4");
        CHECK(jsonReadValue["date"].s() == "12/12/2004");
        CHECK(jsonReadValue["time"].s() == "2:32");
        CHECK(jsonReadValue["artist"]["name"].s() == "Name");
        CHECK(jsonReadValue["venue"]["city"].s() == "City");
    }

    SUBCASE("Testing updateFromJson Method")
    {
        crow::json::rvalue updateJson = crow::json::load(R"({"venue":{"city":"City"},"time":"4:00","date":"12/02/2023","id":"2","artist":{"name":"Name"}})");
        finished.updateFromJson(updateJson);

        CHECK(finished.getId() == "2");
        CHECK(finished.getDate() == "12/02/2023");
        CHECK(finished.getTime() == "4:00");
        CHECK(finished.getArtist().getName() == "Name");
        CHECK(finished.getWhere().getCity() == "City");
    }
}