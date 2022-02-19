#include "../../inc/DataParser/Reader.hpp"

#include "gtest/gtest.h"

#include "../mocks/ApiCommunicatorMock.hpp"


namespace masalamo
{

using TestPair = std::pair<nlohmann::json, std::string>;

class ReaderFixture : public ::testing::Test
{
public:
    std::string readerTestFilePath = {"../test/constants/TestFile.json"};
    std::string expectedResult = {"{\"errors\":[],\"get\":\"standings\",\"paging\":{\"current\":1,\"total\":1}}"};

    std::unique_ptr<ApiCommunicatorMock> apiCommunicatorMockPtr_ = std::make_unique<ApiCommunicatorMock>();
};

TEST_F(ReaderFixture, ShouldParseJsonToStringWithoutBlankSpaces)
{
    EXPECT_CALL(*apiCommunicatorMockPtr_, downloadData()).Times(1);

    auto readerPtr = std::make_unique<Reader>(std::move(apiCommunicatorMockPtr_), readerTestFilePath);
    std::string result = readerPtr->getContent();

    EXPECT_EQ(result, expectedResult);
}

} // masalamo