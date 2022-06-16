#include "../../inc/DataManager/DataManager.hpp"

#include <iostream>


namespace masalamo
{

DataManager::DataManager(IParser& parser, ITimer& timer)
    : parser_(parser), timer_(timer)
{
    std::cout << "DataManager" << '\n';
    timer_.subscribe(this);
    this->update();
}

DataManager::~DataManager()
{
    timer_.unsubscribe(this);
    std::cout << "~DataManager" << '\n';
}

std::vector<Team> DataManager::getData() const
{
    return data_;
}

void DataManager::update()
{
    std::cout << "update" << '\n';

    data_ = parser_.parse();
}

} // masalamo