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
    bool isNotReadyToUdpate();

    std::list<IObserver*> subscribers_;
    bool expiration_ = false;
    int seconds_;
    std::thread timerThread_;
};

} // masalamo