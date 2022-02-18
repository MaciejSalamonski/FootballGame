#include "../../inc/DataParser/Reader.hpp"

namespace masalamo
{

Reader::Reader(std::unique_ptr<ApiCommunicator>&& apiCommunicator, const std::string& filePath)
    : apiCommunicator_(std::move(apiCommunicator)), dataFile_(filePath)
{
    apiCommunicator_->downloadData();

    if (dataFile_.is_open())
    {
        this->read();
    }
}


Reader::~Reader()
{
    dataFile_.close();
}


void Reader::read()
{
    json_ = nlohmann::json::parse(dataFile_);
}


std::string Reader::getContent() const
{
    return json_.dump();
}

} // masalamo