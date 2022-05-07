#include "../../inc/DataParser/Reader.hpp"


namespace masalamo
{

Reader::Reader(IApiCommunicator& apiCommunicator)
    : apiCommunicator_{apiCommunicator}
{
    apiCommunicator_.downloadData();

    if (dataFile_.is_open())
    {
        this->read();
    }
}


Reader::Reader(IApiCommunicator& apiCommunicator, const std::string& filePath)
    : apiCommunicator_{apiCommunicator}, dataFile_(filePath)
{
    apiCommunicator_.downloadData();

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


nlohmann::json Reader::getContent() const
{
    return json_;
}

} // masalamo