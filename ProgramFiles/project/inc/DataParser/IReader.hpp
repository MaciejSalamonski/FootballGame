#pragma once

#include <string>

namespace masalamo
{

class IReader
{
public:
    virtual std::string getContent() const = 0;
    virtual ~IReader() = default;
};

} // masalamo
