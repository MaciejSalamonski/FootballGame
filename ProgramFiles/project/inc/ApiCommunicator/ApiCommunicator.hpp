#pragma once

#include "IApiCommunicator.hpp"

#include <string>


namespace masalamo
{

class ApiCommunicator : public IApiCommunicator
{
public:
    ApiCommunicator(const std::string& filePath);
    void downloadData() override;

private:
    std::string filePath_;
    std::string command_{"python3 "}; 
};

} // masalamo