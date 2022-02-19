#include "../inc/DataParser/IReader.hpp"

#include "gmock/gmock.h" 

namespace masalamo
{

class ReaderMock : public IReader
{
    MOCK_METHOD(std::string, getContent, (), (const, override));
};

} // masalamo
