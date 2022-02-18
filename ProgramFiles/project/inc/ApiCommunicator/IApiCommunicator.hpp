#pragma once

namespace masalamo
{

class IApiCommunicator
{
public:
    virtual void downloadData() = 0;
    virtual ~IApiCommunicator() = default;
};

} // masalamo