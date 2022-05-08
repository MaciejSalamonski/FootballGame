#include "../../inc/DataParser/Reader.hpp"

#include <iostream>

namespace masalamo
{

Reader::Reader(IApiCommunicator& apiCommunicator)
    : apiCommunicator_{apiCommunicator}
{
    std::cout << "Reader" << '\n';
}


Reader::Reader(IApiCommunicator& apiCommunicator, const std::string& filePath)
    : apiCommunicator_{apiCommunicator}, dataFile_(filePath)
{
    std::cout << "Reader" << '\n';
}


Reader::~Reader()
{
    std::cout << "~Reader" << '\n';

    dataFile_.close();
}


nlohmann::json Reader::getContent()
{
    std::cout << "getContent" << '\n';

    readDataFromJson();

    return json_;
}


void Reader::readDataFromJson()
{
    std::cout << "readDataFromJson" << '\n';

    apiCommunicator_.downloadData();

    if (dataFile_.is_open())
    {
        this->read();
        dataFile_.close();
    }
}


void Reader::read()
{
    std::cout << "read" << '\n';

    json_ = nlohmann::json::parse(dataFile_);
}

} // masalamo