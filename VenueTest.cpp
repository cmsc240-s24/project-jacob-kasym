#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Venue.h"

TEST_CASE("Testing Venue class functionality")
{
    SUBCASE("Blank Constructor should throw an exception")
    {
        CHECK_THROWS_AS(Venue emptyCity("", "290 Blvd",  1.0), std::invalid_argument);
        CHECK_THROWS_AS(Venue emptyAddress("Toronto ON", "", 1.0), std::invalid_argument);
        CHECK_THROWS_AS(Venue negCost("Toronto ON", "290 Blvd", -1.0), std::invalid_argument);
    }
    
    Venue venue("Toronto ON", "290 Blvd", 5.0);

    SUBCASE("getCity should return the set city")
    {
        CHECK(venue.getCity() == "Toronto ON");
    }

    SUBCASE("setCity should change the city")
    {
        CHECK(venue.setCity("Richmond VA") == "Richmond VA");
        CHECK(venue.getCity() == "Richmond VA");
        CHECK(venue.setCity("Roanoke VA") == "Roanoke VA");
        CHECK(venue.getCity() == "Roanoke VA");
    }

    SUBCASE("setCity to blank should throw an exception")
    {
        CHECK_THROWS_AS(venue.setCity(""), std::invalid_argument);
    }

    SUBCASE("getAddress should return the set address")
    {
        CHECK(venue.getAddress() == "290 Blvd");
    }

    SUBCASE("setAddress should change the address")
    {
        CHECK(venue.setAddress("1629 Rd") == "1629 Rd");
        CHECK(venue.getAddress() == "1629 Rd");
        CHECK(venue.setAddress("302 St") == "302 St");
        CHECK(venue.getAddress() == "302 St");
    }

    SUBCASE("setAddress to blank should throw an exception")
    {
        CHECK_THROWS_AS(venue.setAddress(""), std::invalid_argument);
    }

    SUBCASE("getCost should return the set cost")
    {
        CHECK(venue.getCost() == 5.0);
    }

    SUBCASE("setCost should change the cost")
    {
        CHECK(venue.setCost(5.0) == 5.0);
        CHECK(venue.getCost() == 5.0);
        CHECK(venue.setCost(6.0) == 6.0);
        CHECK(venue.getCost() == 6.0);
    }

    SUBCASE("setCost to negative should throw an exception")
    {
        CHECK_THROWS_AS(venue.setCost(-1.0), std::invalid_argument);
    }
}