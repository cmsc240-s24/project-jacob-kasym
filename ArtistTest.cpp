#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Artist.h"

TEST_CASE("Testing Artist class functionality")
{
    SUBCASE("Blank Constructor should throw an exception")
    {
        CHECK_THROWS_AS(Artist emptyName("", "Music", 1.0), std::invalid_argument);
        CHECK_THROWS_AS(Artist emptyType("Band", "", 1.0), std::invalid_argument);
        CHECK_THROWS_AS(Artist negCost("Band", "Music", -1.0), std::invalid_argument);
    }
    
    Artist artist("Band", "Music", 10.0);



    SUBCASE("getName should return the set name")
    {
        CHECK(artist.getName() == "Band");
    }

    SUBCASE("setName should change the name")
    {
        CHECK(artist.setName("Group") == "Group");
        CHECK(artist.getName() == "Group");
        CHECK(artist.setName("People") == "People");
        CHECK(artist.getName() == "People");
    }

    SUBCASE("setName to blank should throw an exception")
    {
        CHECK_THROWS_AS(artist.setName(""), std::invalid_argument);
    }

    SUBCASE("getDescription should return the set type")
    {
        CHECK(artist.getDescription() == "Music");
    }

    SUBCASE("setDescription should change the description")
    {
        CHECK(artist.setDescription("Perform") == "Perform");
        CHECK(artist.getDescription() == "Perform");
        CHECK(artist.setDescription("Improv") == "Improv");
        CHECK(artist.getDescription() == "Improv");
    }

    SUBCASE("setDescription to blank should throw an exception")
    {
        CHECK_THROWS_AS(artist.setDescription(""), std::invalid_argument);
    }

    SUBCASE("getCost should return the set cost")
    {
        CHECK(artist.getCost() == 10.0);
    }

    SUBCASE("setCost should change the cost")
    {
        CHECK(artist.setCost(5.0) == 5.0);
        CHECK(artist.getCost() == 5.0);
        CHECK(artist.setCost(6.0) == 6.0);
        CHECK(artist.getCost() == 6.0);
    }

    SUBCASE("setCost to negative should throw an exception")
    {
        CHECK_THROWS_AS(artist.setCost(-1.0), std::invalid_argument);
    }
}