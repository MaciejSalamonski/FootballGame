#pragma once

#include "IReader.hpp"

#include <fstream>
#include <memory>

#include "../ApiCommunicator/ApiCommunicator.hpp"


namespace masalamo
{

class Reader : public IReader
{
public:
    Reader(IApiCommunicator& apiCommunicator);
    Reader(IApiCommunicator& apiCommunicator, const std::string& filePath);
    ~Reader();
    
    nlohmann::json getContent() override;
private:
    void read();
    void readDataFromJson();

    std::ifstream dataFile_{"../../data/GroupStageData.json"};
    nlohmann::json json_;
    IApiCommunicator& apiCommunicator_;
};

} // masalamo