#include "../../inc/DataManager/DataManager.hpp"


namespace masalamo
{

DataManager::DataManager(IParser& parser)
    : parser_(parser)
{
    data_ = parser_.parse();
}

std::vector<Team> DataManager::getData() const
{
    return data_;
}

} // masalamo