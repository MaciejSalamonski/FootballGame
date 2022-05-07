#pragma once

#include <vector>

#include "../Types/Team.hpp"


namespace masalamo
{

class IDataManager
{
public:
    virtual std::vector<masalamo::Team> getData() const = 0;
    virtual ~IDataManager() = default;
};

} // masalamo