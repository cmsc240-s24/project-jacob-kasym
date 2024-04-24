#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <crow.h>
#include <string>
#include "Venue.h"

TEST_CASE("Testing Venue class functionality")
{
    SUBCASE("Blank Parameter Constructor should throw an exception")
    {
        CHECK_THROWS_AS(Venue emptyCity("", "290 Blvd",  1.0), std::invalid_argument);
        CHECK_THROWS_AS(Venue emptyAddress("Toronto ON", "", 1.0), std::invalid_argument);
        CHECK_THROWS_AS(Venue negCost("Toronto ON", "290 Blvd", -1.0), std::invalid_argument);
    }

    SUBCASE("Blank Json Constructor should throw an exception")
    {
        CHECK_THROWS_AS(Venue emptyJCity(crow::json::load(R"({"city":"","address":"Music","cost":1.0})")), std::invalid_argument);
        CHECK_THROWS_AS(Venue emptyJAddress(crow::json::load(R"({"city":"Band","address":"","cost":1.0})")), std::invalid_argument);
        CHECK_THROWS_AS(Venue negJCost(crow::json::load(R"({"city":"Band","address":"Music","cost":-1.0})")), std::invalid_argument);
    }
    
    Venue pVenue("Toronto ON", "290 Blvd", 5.0);
    Venue jVenue(crow::json::load(R"({"city":"Toronto ON","address":"290 Blvd","cost":5.0})"));


    SUBCASE("getCity should return the set city")
    {
        CHECK(pVenue.getCity() == "Toronto ON");
        CHECK(jVenue.getCity() == "Toronto ON");
    }

    SUBCASE("setCity should change the city")
    {
        CHECK(pVenue.setCity("Richmond VA") == "Richmond VA");
        CHECK(pVenue.getCity() == "Richmond VA");
        CHECK(jVenue.setCity("Roanoke VA") == "Roanoke VA");
        CHECK(jVenue.getCity() == "Roanoke VA");
    }

    SUBCASE("setCity to blank should throw an exception")
    {
        CHECK_THROWS_AS(pVenue.setCity(""), std::invalid_argument);
        CHECK_THROWS_AS(jVenue.setCity(""), std::invalid_argument);
    }

    SUBCASE("getAddress should return the set address")
    {
        CHECK(pVenue.getAddress() == "290 Blvd");
        CHECK(jVenue.getAddress() == "290 Blvd");
    }

    SUBCASE("setAddress should change the address")
    {
        CHECK(pVenue.setAddress("1629 Rd") == "1629 Rd");
        CHECK(pVenue.getAddress() == "1629 Rd");
        CHECK(jVenue.setAddress("302 St") == "302 St");
        CHECK(jVenue.getAddress() == "302 St");
    }

    SUBCASE("setAddress to blank should throw an exception")
    {
        CHECK_THROWS_AS(pVenue.setAddress(""), std::invalid_argument);
        CHECK_THROWS_AS(jVenue.setAddress(""), std::invalid_argument);
    }

    SUBCASE("getCost should return the set cost")
    {
        CHECK(pVenue.getCost() == 5.0);
        CHECK(jVenue.getCost() == 5.0);
    }

    SUBCASE("setCost should change the cost")
    {
        CHECK(pVenue.setCost(5.0) == 5.0);
        CHECK(pVenue.getCost() == 5.0);
        CHECK(jVenue.setCost(6.0) == 6.0);
        CHECK(jVenue.getCost() == 6.0);
    }

    SUBCASE("setCost to negative should throw an exception")
    {
        CHECK_THROWS_AS(pVenue.setCost(-1.0), std::invalid_argument);
        CHECK_THROWS_AS(pVenue.setCost(-1.0), std::invalid_argument);
    }

    SUBCASE("Testing the convertToJson Method") 
    {
        crow::json::wvalue jsonOutput = pVenue.convertToJson();
        crow::json::rvalue jsonReadValue = crow::json::load(jsonOutput.dump());

        CHECK(jsonReadValue["city"].s() == "Toronto ON");
        CHECK(jsonReadValue["address"].s() == "290 Blvd");
        CHECK(jsonReadValue["cost"].d() == 5.0);
    }

    SUBCASE("Testing updateFromJson Method") 
    {
        crow::json::rvalue updateJson = crow::json::load(R"({"city":"One","address":"Two","cost":20.0})");
        pVenue.updateFromJson(updateJson);

        CHECK(pVenue.getCity() == "One");
        CHECK(pVenue.getAddress() == "Two");
        CHECK(pVenue.getCost() == 20.0);
    }
}