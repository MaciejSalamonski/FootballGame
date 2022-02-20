#pragma once

#include "IParser.hpp"

#include "IReader.hpp"


namespace masalamo 
{

class Parser : public IParser
{
public:
    Parser(std::unique_ptr<IReader>&& reader);
    std::vector<nlohmann::json> parse() override;

private:
    std::vector<nlohmann::json> processData(const nlohmann::json& data);

    std::vector<nlohmann::json> teamsContainer_;
    std::unique_ptr<IReader> reader_;
};

} // masalamo
