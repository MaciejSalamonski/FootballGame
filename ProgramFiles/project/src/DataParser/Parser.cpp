#include "../../inc/DataParser/Parser.hpp"

#include <map>

#include <iostream>

namespace masalamo
{

static std::map<std::string, EGroup> GROUP_MAP
{
    {"Group A", EGroup::EGroupA},
    {"Group B", EGroup::EGroupB},
    {"Group C", EGroup::EGroupC},
    {"Group D", EGroup::EGroupD},
    {"Group E", EGroup::EGroupE},
    {"Group F", EGroup::EGroupF},
    {"Group G", EGroup::EGroupG},
    {"Group H", EGroup::EGroupH}
};


Parser::Parser(IReader& reader)
    : reader_(reader) 
{
    std::cout << "Parser" << '\n';
}

Parser::~Parser()
{
    std::cout << "~Parser" << '\n';
}


std::vector<Team> Parser::parse()
{
    std::cout << "parse" << '\n';

    const auto readerContnet = reader_.getContent();
    const auto jsonTeamsDataContainer = extractJsonTeamsData(readerContnet);

    return fillTeamsData(jsonTeamsDataContainer);
}


std::vector<nlohmann::json> Parser::extractJsonTeamsData(const nlohmann::json& data)
{
    std::cout << "extractJsonTeamsData" << '\n';

    for (const auto& responseData : data["response"])
    {
        for (const auto& groupData : responseData["league"]["standings"].items())
        {
            for (const auto& teamData : groupData.value())
            {
                jsonTeamsContainer_.emplace_back(teamData);
            }
        }
    }

    return jsonTeamsContainer_;
}


std::vector<Team> Parser::fillTeamsData(const std::vector<nlohmann::json>& jsonTeamsDataContainer)
{
    std::cout << "fillTeamsData" << '\n';

    for (const auto& jsonTeamData : jsonTeamsDataContainer)
    {
        teamsContainer_.emplace_back(fillTeamData(jsonTeamData));
    }

    return teamsContainer_;
}


Team Parser::fillTeamData(const nlohmann::json& jsonTeamData)
{
    Team teamData{};

    const auto jsonGoalsData = jsonTeamData["all"]["goals"];
    teamData.goalsAgainst = jsonGoalsData["against"];
    teamData.goalsFor = jsonGoalsData["for"];

    teamData.played = jsonTeamData["all"]["played"];
    teamData.win = jsonTeamData["all"]["win"];
    teamData.draw = jsonTeamData["all"]["draw"];
    teamData.lose = jsonTeamData["all"]["lose"];

    teamData.goalsDiff = jsonTeamData["goalsDiff"];
    teamData.points = jsonTeamData["points"];
    teamData.rank = jsonTeamData["rank"];
    teamData.form = jsonTeamData["form"];

    teamData.team = jsonTeamData["team"]["name"];
    teamData.group = GROUP_MAP[jsonTeamData["group"]];

    return teamData;
}

} // masalamo
