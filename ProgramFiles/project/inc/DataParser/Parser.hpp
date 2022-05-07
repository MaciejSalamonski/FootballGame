#pragma once

#include "IParser.hpp"

#include "IReader.hpp"


namespace masalamo 
{

class Parser : public IParser
{
public:
    Parser(IReader& reader);
    std::vector<Team> parse() override;

private:
    std::vector<nlohmann::json> extractJsonTeamsData(const nlohmann::json& data);
    Team fillTeamData(const nlohmann::json& jsonTeamData);
    std::vector<Team> fillTeamsData(const std::vector<nlohmann::json>& jsonTeamsDataContainer);

    std::vector<nlohmann::json> jsonTeamsContainer_;
    std::vector<Team> teamsContainer_;
    IReader& reader_;
};

} // masalamo
