#pragma once

#include "../Observer/IObserver.hpp"

#include <memory>


namespace masalamo 
{

class ITimer
{
public:
    virtual ~ITimer() = default;

    virtual void startTimer() = 0;
    virtual void stopTimer() = 0;
    virtual void subscribe(IObserver* observer) = 0;
    virtual void unsubscribe(IObserver* observer) = 0;
    virtual void notify() = 0;
};

} // masalamo