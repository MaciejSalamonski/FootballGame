#pragma once

#include "IReader.hpp"

#include <fstream>
#include <memory>

#include "../ApiCommunicator/ApiCommunicator.hpp"

#include "nlohmann/json.hpp"


namespace masalamo
{

class Reader : public IReader
{
public:
    Reader(std::unique_ptr<ApiCommunicator>&& apiCommunicator, const std::string& filePath);
    ~Reader();
    
    std::string getContent() const override;
private:
    void read();

    std::ifstream dataFile_;
    nlohmann::json json_;
    std::unique_ptr<ApiCommunicator> apiCommunicator_;
};

} // masalamo