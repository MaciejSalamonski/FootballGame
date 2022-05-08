#include "../../inc/Timer/Timer.hpp"

#include <chrono>
#include <iostream>


namespace masalamo 
{

Timer::Timer()
{
    std::cout << "Timer" << '\n';
    timerThread_ = std::thread(&Timer::startTimer, this);
}

Timer::~Timer()
{
    std::cout << "~Timer" << '\n';
    this->stopTimer();
}

void Timer::startTimer()
{
    std::cout << "startTimer" << '\n';
    while(true)
    {
        ++seconds_;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (isNotReadyToUdpate())
        {
            continue;
        }
        
        notify();
    }
}

void Timer::stopTimer()
{
    std::cout << "stopTimer" << '\n';

    expiration_ = true;
    timerThread_.join();
}

void Timer::subscribe(IObserver* observer)
{
    std::cout << "subscribe" << '\n';

    subscribers_.emplace_back(observer);
}

void Timer::unsubscribe(IObserver* observer)
{
    std::cout << "unsubscribe" << '\n';

    subscribers_.remove(observer);
}

void Timer::notify()
{
    std::cout << "notify" << '\n';

    for (const auto& subscriber : subscribers_)
    {
        if (subscriber)
        {
            subscriber->update();
        }
    }
}

bool Timer::isNotReadyToUdpate()
{
    std::cout << "isNotReadyToUpdate" << '\n';

    return seconds_ % 20;
}

} // masalamo