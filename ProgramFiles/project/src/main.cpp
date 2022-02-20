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
    masalamo::Parser parser(std::move(reader));

    std::vector<nlohmann::json> vec = parser.parse();

    for (const auto& el : vec)
    {
        std::cout << el << '\n';
    }

    return 0;
}