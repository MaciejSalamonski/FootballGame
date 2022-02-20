#include "../../inc/DataParser/Parser.hpp"


namespace masalamo
{

Parser::Parser(std::unique_ptr<IReader>&& reader)
    : reader_(std::move(reader)) 
{}


std::vector<nlohmann::json> Parser::parse()
{
    const auto readerContnet = reader_->getContent();

    return processData(readerContnet);
}


std::vector<nlohmann::json> Parser::processData(const nlohmann::json& data)
{
    for (const auto& responseData : data["response"])
    {
        for (const auto& groupData : responseData["league"]["standings"].items())
        {
            for (const auto& teamData : groupData.value())
            {
                teamsContainer_.emplace_back(teamData);
            }
        }
    }

    return teamsContainer_;
}

} // masalamo
