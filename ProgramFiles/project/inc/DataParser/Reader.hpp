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
    Reader(std::unique_ptr<IApiCommunicator>&& apiCommunicator, const std::string& filePath);
    ~Reader();
    
    nlohmann::json getContent() const override;
private:
    void read();

    std::ifstream dataFile_;
    nlohmann::json json_;
    std::unique_ptr<IApiCommunicator> apiCommunicator_;
};

} // masalamo