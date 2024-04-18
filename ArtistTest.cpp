#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Artist.h"

TEST_CASE("Testing Artist class functionality")
{
    SUBCASE("Blank Constructor should throw an exception")
    {
        CHECK_THROWS_AS(Artist<int> emptyName("", "Music", 1), std::invalid_argument);
        CHECK_THROWS_AS(Artist<int> emptyType("Band", "", 1), std::invalid_argument);
        CHECK_THROWS_AS(Artist<int> emptyType("", "", 1), std::invalid_argument);
    }
    
    Artist<int> artist("Band", "Music", 10);
    Artist<float> artist2("Comedian", "Comedy", 4.5);
    Artist<std::string> artist3("Troupe", "Theatre", "Free");


    SUBCASE("getName should return the set name")
    {
        CHECK(artist.getName() == "Band");
        CHECK(artist2.getName() == "Comedian");
        CHECK(artist3.getName() == "Troupe");
    }

    SUBCASE("setName should change the name")
    {
        CHECK(artist.setName("Group") == "Group");
        CHECK(artist.setName("People") == "People");
        CHECK(artist2.setName("Something") == "Something");
        CHECK(artist3.setName("Something") == "Something");
    }

    SUBCASE("setName to blank should throw an exception")
    {
        CHECK_THROWS_AS(artist.setName(""), std::invalid_argument);
        CHECK_THROWS_AS(artist2.setName(""), std::invalid_argument);
        CHECK_THROWS_AS(artist3.setName(""), std::invalid_argument);
    }

    SUBCASE("getDescription should return the set type")
    {
        CHECK(artist.getDescription() == "Music");
        CHECK(artist2.getDescription() == "Comedy");
        CHECK(artist3.getDescription() == "Theatre");
    }

    SUBCASE("setDescription should change the description")
    {
        CHECK(artist.setDescription("Perform") == "Perform");
        CHECK(artist.setDescription("Improv") == "Improv");
        CHECK(artist2.setDescription("Something") == "Something");
        CHECK(artist3.setDescription("Something") == "Something");
    }

    SUBCASE("setDescription to blank should throw an exception")
    {
        CHECK_THROWS_AS(artist.setDescription(""), std::invalid_argument);
        CHECK_THROWS_AS(artist2.setDescription(""), std::invalid_argument);
        CHECK_THROWS_AS(artist3.setDescription(""), std::invalid_argument);
    }

    SUBCASE("getCost should return the set cost")
    {
        CHECK(artist.getCost() == 10);
        CHECK(artist2.getCost() == 4.5);
        CHECK(artist3.getCost() == "Free");
    }

    SUBCASE("setCost should change the cost")
    {
        CHECK(artist.setCost(5) == 5);
        CHECK(artist.setCost(6) == 6);
        CHECK(artist2.setCost(5.5) == 5.5);
        CHECK(artist3.setCost("Something") == "Something");
    }
}