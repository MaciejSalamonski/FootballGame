#include "../inc/DataParser/Reader.hpp"

#include "../inc/ApiCommunicator/ApiCommunicator.hpp"
#include "../inc/DataParser/Parser.hpp"

#include <string>
#include <iostream>
#include <memory>


const auto CREATE_JSON_FILE_PATH = std::string{"../../scripts/create_json_files_with_data.py"};
const auto GROUP_STAGE_FILE_PATH = std::string{"../../data/GroupStageData.json"};

int main()
{
    auto apiCommunicator = std::make_unique<masalamo::ApiCommunicator>(CREATE_JSON_FILE_PATH);
    auto reader = std::make_unique<masalamo::Reader>(std::move(apiCommunicator), GROUP_STAGE_FILE_PATH);
    auto parser = std::make_unique<masalamo::Parser>(std::move(reader));

    std::vector<masalamo::Team> vec = parser->parse();

    return 0;
}