#pragma once

#include "IApiCommunicator.hpp"

#include <string>


namespace masalamo
{

class ApiCommunicator : public IApiCommunicator
{
public:
    ApiCommunicator();
    ApiCommunicator(const std::string& filePath);
    void downloadData() override;

private:

    std::string filePath_{"../../scripts/create_json_files_with_data.py"};
    std::string command_{"python3 "}; 
};

} // masalamo