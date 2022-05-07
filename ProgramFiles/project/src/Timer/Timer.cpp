#include "../../inc/Timer/Timer.hpp"

#include <chrono>
#include <thread>


namespace masalamo 
{

Timer::Timer()
{
    startTimer();
}

Timer::~Timer()
{
    stopTimer();
}

void Timer::startTimer()
{
    while(isCounting)
    {
        ++seconds_;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (seconds_ > 30)
        {
            
        }
    }
}

void Timer::stopTimer()
{

}

};

} // masalamo