#include <ITimer.hpp>


namespace masalamo 
{

class Timer : public ITimer
{
public:
    Timer();
    ~Timer();

    void startTimer() override;
    void stopTimer() override;
private:
    void resetTimer();

    bool isCounting = true;
    int seconds_;
};

} // masalamo