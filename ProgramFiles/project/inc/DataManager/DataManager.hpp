#pragma once

#include "IDataManager.hpp"

#include "../ApiCommunicator/ApiCommunicator.hpp"
#include "../DataParser/Reader.hpp"
#include "../DataParser/Parser.hpp"

namespace masalamo
{

class DataManager : public IDataManager
{
public:
    DataManager(IParser& parser);

    std::vector<Team> getData() const override;
private:
    std::vector<Team> data_;
    IParser& parser_;
};

} // masalamo