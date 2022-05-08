#pragma once

#include "IDataManager.hpp"

#include "../ApiCommunicator/ApiCommunicator.hpp"
#include "../DataParser/Reader.hpp"
#include "../DataParser/Parser.hpp"
#include "../Timer/ITimer.hpp"
#include "../Observer/IObserver.hpp"

namespace masalamo
{

class DataManager : public IDataManager, IObserver
{
public:
    DataManager(IParser& parser, ITimer& timer);
    ~DataManager();

    std::vector<Team> getData() const override;
    void update() override;
private:
    std::vector<Team> data_;
    IParser& parser_;
    ITimer& timer_;
};

} // masalamo