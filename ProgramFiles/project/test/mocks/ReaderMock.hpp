#include "../inc/DataParser/IReader.hpp"

#include "gmock/gmock.h" 


namespace masalamo
{

class ReaderMock : public IReader
{
    MOCK_METHOD(nlohmann::json, getContent, (), (const, override));
};

} // masalamo
