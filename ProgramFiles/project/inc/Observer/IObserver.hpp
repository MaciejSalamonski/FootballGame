#pragma once

namespace masalamo
{

class IObserver
{
public:
    virtual ~IObserver() = default;
    virtual void update() = 0;
};

} // masalamo