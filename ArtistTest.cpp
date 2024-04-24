#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <crow.h>
#include <string>
#include "Artist.h"

TEST_CASE("Testing Artist class functionality")
{
    SUBCASE("Blank Parameter Constructor should throw an exception")
    {
        CHECK_THROWS_AS(Artist emptyName("", "Music", 1.0), std::invalid_argument);
        CHECK_THROWS_AS(Artist emptyType("Band", "", 1.0), std::invalid_argument);
        CHECK_THROWS_AS(Artist negCost("Band", "Music", -1.0), std::invalid_argument);
    }

    SUBCASE("Blank Json Constructor should throw an exception")
    {
        CHECK_THROWS_AS(Artist emptyJName(crow::json::load(R"({"name":"","type":"Music","cost":1.0})")), std::invalid_argument);
        CHECK_THROWS_AS(Artist emptyJType(crow::json::load(R"({"name":"Band","type":"","cost":1.0})")), std::invalid_argument);
        CHECK_THROWS_AS(Artist negJCost(crow::json::load(R"({"name":"Band","type":"Music","cost":-1.0})")), std::invalid_argument);
    }
    
    Artist pArtist("Band", "Music", 10.0);
    Artist jArtist(crow::json::load(R"({"name":"Band","type":"Music","cost":10.0})"));


    SUBCASE("getName should return the set name")
    {
        CHECK(pArtist.getName() == "Band");
        CHECK(jArtist.getName() == "Band");
    }

    SUBCASE("setName should change the name")
    {
        CHECK(pArtist.setName("Group") == "Group");
        CHECK(pArtist.getName() == "Group");
        CHECK(jArtist.setName("People") == "People");
        CHECK(jArtist.getName() == "People");
    }

    SUBCASE("setName to blank should throw an exception")
    {
        CHECK_THROWS_AS(pArtist.setName(""), std::invalid_argument);
        CHECK_THROWS_AS(jArtist.setName(""), std::invalid_argument);
    }

    SUBCASE("getDescription should return the set type")
    {
        CHECK(pArtist.getDescription() == "Music");
        CHECK(jArtist.getDescription() == "Music");
    }

    SUBCASE("setDescription should change the description")
    {
        CHECK(pArtist.setDescription("Perform") == "Perform");
        CHECK(pArtist.getDescription() == "Perform");
        CHECK(jArtist.setDescription("Improv") == "Improv");
        CHECK(jArtist.getDescription() == "Improv");
    }

    SUBCASE("setDescription to blank should throw an exception")
    {
        CHECK_THROWS_AS(pArtist.setDescription(""), std::invalid_argument);
        CHECK_THROWS_AS(jArtist.setDescription(""), std::invalid_argument);
    }

    SUBCASE("getCost should return the set cost")
    {
        CHECK(pArtist.getCost() == 10.0);
        CHECK(jArtist.getCost() == 10.0);
    }

    SUBCASE("setCost should change the cost")
    {
        CHECK(pArtist.setCost(5.0) == 5.0);
        CHECK(pArtist.getCost() == 5.0);
        CHECK(jArtist.setCost(6.0) == 6.0);
        CHECK(jArtist.getCost() == 6.0);
    }

    SUBCASE("setCost to negative should throw an exception")
    {
        CHECK_THROWS_AS(pArtist.setCost(-1.0), std::invalid_argument);
        CHECK_THROWS_AS(jArtist.setCost(-1.0), std::invalid_argument);
    }

    SUBCASE("Testing the convertToJson Method") 
    {
        crow::json::wvalue jsonOutput = pArtist.convertToJson();
        crow::json::rvalue jsonReadValue = crow::json::load(jsonOutput.dump());

        CHECK(jsonReadValue["name"].s() == "Band");
        CHECK(jsonReadValue["type"].s() == "Music");
        CHECK(jsonReadValue["cost"].d() == 10.0);
    }

    SUBCASE("Testing updateFromJson Method") 
    {
        crow::json::rvalue updateJson = crow::json::load(R"({"name":"One","type":"Two","cost":20.0})");
        pArtist.updateFromJson(updateJson);

        CHECK(pArtist.getName() == "One");
        CHECK(pArtist.getDescription() == "Two");
        CHECK(pArtist.getCost() == 20.0);
    }
}