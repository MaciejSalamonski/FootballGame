#pragma once

#include <vector>

#include "../../inc/DataParser/nlohmann/json.hpp"
#include "../Types/Team.hpp"


namespace masalamo
{

class IParser
{
public:
    virtual ~IParser() = default;
    virtual std::vector<Team> parse() = 0;
};

} // masalamo
