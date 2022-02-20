#pragma once

#include <vector>

#include "../../inc/DataParser/nlohmann/json.hpp"


namespace masalamo
{

class IParser
{
public:
    virtual ~IParser() = default;
    virtual std::vector<nlohmann::json> parse() = 0;
};

} // masalamo
