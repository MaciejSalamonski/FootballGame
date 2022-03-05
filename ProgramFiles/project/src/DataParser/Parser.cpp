#include "../../inc/DataParser/Parser.hpp"

#include <map>


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

Parser::Parser(std::unique_ptr<IReader>&& reader)
    : reader_(std::move(reader)) 
{}


std::vector<Team> Parser::parse()
{
    const auto readerContnet = reader_->getContent();
    const auto jsonTeamsDataContainer = extractJsonTeamsData(readerContnet);

    return fillTeamsData(jsonTeamsDataContainer);
}


std::vector<nlohmann::json> Parser::extractJsonTeamsData(const nlohmann::json& data)
{
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


Team Parser::fillTeamData(const nlohmann::json& jsonTeamData)
{
    Team teamData{};

    const auto jsonGoalsData = jsonTeamData["all"]["goals"];
    teamData.goalsAgainst_ = jsonGoalsData["against"];
    teamData.goalsFor_ = jsonGoalsData["for"];

    teamData.played_ = jsonTeamData["all"]["played"];
    teamData.win_ = jsonTeamData["all"]["win"];
    teamData.draw_ = jsonTeamData["all"]["draw"];
    teamData.lose_ = jsonTeamData["all"]["lose"];

    teamData.goalsDiff_ = jsonTeamData["goalsDiff"];
    teamData.points_ = jsonTeamData["points"];
    teamData.rank_ = jsonTeamData["rank"];
    teamData.form_ = jsonTeamData["form"];

    teamData.team_ = jsonTeamData["team"]["name"];
    teamData.group_ = GROUP_MAP[jsonTeamData["group"]];

    return teamData;
}


std::vector<Team> Parser::fillTeamsData(const std::vector<nlohmann::json>& jsonTeamsDataContainer)
{
    for (const auto& jsonTeamData : jsonTeamsDataContainer)
    {
        teamsContainer_.emplace_back(fillTeamData(jsonTeamData));
    }

    return teamsContainer_;
}

} // masalamo
