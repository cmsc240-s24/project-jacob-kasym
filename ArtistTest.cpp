#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Artist.h"

TEST_CASE("Testing Artist class functionality")
{
    SUBCASE("Blank Constructor should throw an exception")
    {
        CHECK_THROWS_AS(Artist emptyName("", "Music"), std::invalid_argument);
        CHECK_THROWS_AS(Artist emptyType("Band", ""), std::invalid_argument);
        CHECK_THROWS_AS(Artist emptyName2("", "Music", "John Doe"), std::invalid_argument);
        CHECK_THROWS_AS(Artist emptyType2("Band", "", "John Doe"), std::invalid_argument);
        CHECK_THROWS_AS(Artist emptyMember("Band", "Music", ""), std::invalid_argument);
    }
    
    Artist artist("Band", "Music");

    SUBCASE("getName should return the set name")
    {
        CHECK(artist.getName() == "Band");
    }

    SUBCASE("setName should change the name")
    {
        CHECK(artist.setName("Group") == "Group");
        CHECK(artist.setName("People") == "People");
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
        CHECK(artist.setDescription("Theatre") == "Theatre");
        CHECK(artist.setDescription("Improv") == "Improv");
    }

    SUBCASE("setDescription to blank should throw an exception")
    {
        CHECK_THROWS_AS(artist.setDescription(""), std::invalid_argument);
    }

//    SUBCASE("getMembers should return the set type")
//    {
//        CHECK(artist.getMembers() == "Music");
//    }

//    SUBCASE("addMember should add the description")
//    {
//        CHECK(artist.setDescription("Theatre") == "Theatre");
//        CHECK(artist.setDescription("Improv") == "Improv");
//    }

    SUBCASE("addMember to blank should throw an exception")
    {
        CHECK_THROWS_AS(artist.addMember(""), std::invalid_argument);
    }

}