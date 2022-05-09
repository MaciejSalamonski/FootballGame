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
    while(isTimerNotExpired())
    {
        if (isReadyToUdpate())
        {
            notify();
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
        ++seconds_;
    }
}

void Timer::stopTimer()
{
    std::cout << "stopTimer" << '\n';

    setTimerExpiration(true);
    resetCounter();
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

bool Timer::isReadyToUdpate() const
{
    std::cout << "isReadyToUpdate" << '\n';

    return isCounterNotInResetedState() && hasMinutePassed();
}

bool Timer::isTimerNotExpired() const
{
    std::cout << "isTimerNotExpired" << '\n';

    return !expiration_;
}

bool Timer::isCounterNotInResetedState() const
{
    return seconds_ != 0;
}

bool Timer::hasMinutePassed() const
{
    return !(seconds_ % 60);
}

void Timer::setTimerExpiration(const bool expiration)
{
    std::cout << "setTimerExpiration" << '\n';

    expiration_ = expiration;
}

void Timer::resetCounter()
{
    std::cout << "resetCounter" << '\n';

    seconds_ = 0;
}

} // masalamo