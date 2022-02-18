#include "../../inc/ApiCommunicator/ApiCommunicator.hpp"


namespace masalamo
{

ApiCommunicator::ApiCommunicator(const std::string& filePath) 
    : filePath_(filePath)
{}

void ApiCommunicator::downloadData()
{
    command_.append(filePath_);
    system(command_.c_str());
}

} // masalamo