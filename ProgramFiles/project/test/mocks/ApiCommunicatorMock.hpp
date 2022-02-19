#include "../../inc/ApiCommunicator/IApiCommunicator.hpp"

#include "gmock/gmock.h"


namespace masalamo
{

class ApiCommunicatorMock : public IApiCommunicator
{
public:
    MOCK_METHOD(void, downloadData, (), (override));
};

} // masalamo
