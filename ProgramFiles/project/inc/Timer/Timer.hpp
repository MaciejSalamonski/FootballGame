#include "ITimer.hpp"

#include <list>
#include <thread>


namespace masalamo 
{

class Timer : public ITimer
{
public:
    Timer();
    ~Timer() override;

    void startTimer() override;
    void stopTimer() override;
    void subscribe(IObserver* observer) override;
    void unsubscribe(IObserver* observer) override;
    void notify() override;
private:
    bool isReadyToUdpate() const;
    bool isTimerNotExpired() const;
    bool isCounterNotInResetedState() const;
    bool hasMinutePassed() const;
    void setTimerExpiration(const bool expiration);
    void resetCounter();

    std::list<IObserver*> subscribers_;
    bool expiration_ = false;
    int seconds_;
    std::thread timerThread_;
};

} // masalamo