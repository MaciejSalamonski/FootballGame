#pragma once

#include "../../inc/DataParser/nlohmann/json.hpp"


namespace masalamo
{

class IReader
{
public:
    virtual nlohmann::json getContent() const = 0;
    virtual ~IReader() = default;
};

} // masalamo
