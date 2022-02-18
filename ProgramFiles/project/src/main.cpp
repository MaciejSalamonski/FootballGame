#include <string>
#include <iostream>
#include <memory>

#include "../inc/DataParser/Reader.hpp"
#include "../inc/ApiCommunicator/ApiCommunicator.hpp"

const auto CREATE_JSON_FILE_PATH = std::string{"../../scripts/create_json_files_with_data.py"};
const auto GROUP_STAGE_FILE_PATH = std::string{"../../data/GroupStageData.json"};

int main()
{
    auto apiCommunicator = std::make_unique<masalamo::ApiCommunicator>(CREATE_JSON_FILE_PATH);
    masalamo::Reader reader(std::move(apiCommunicator), GROUP_STAGE_FILE_PATH);
    std::string s = reader.getContent();
    std::cout << s;

    return 0;
}