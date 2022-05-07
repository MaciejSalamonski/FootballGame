#pragma once


namespace masalamo 
{

class ITimer
{
public:
    virtual ~ITimer() = default;

    virtual void startTimer() = 0;
    virtual void stopTimer() = 0;
};

} // masalamo