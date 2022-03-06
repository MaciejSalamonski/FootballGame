#include "../../inc/DataParser/Reader.hpp"

#include "../mocks/ApiCommunicatorMock.hpp"

#include "gtest/gtest.h"


namespace masalamo
{

using TestPair = std::pair<nlohmann::json, std::string>;

const std::string READER_TEST_FILE_PATH = {"../test/constants/TestFile.json"};
const nlohmann::json EXPECTED_RESULT = {
    {
        {"name", "Molecule Man"},
        {"age", 29},
        {"secretIdentity", "Dan Jukes"},
        {"powers", {
            "Radiation resistance",
            "Turning tiny",
            "Radiation blast"
        }},
    },
    {
        {"name", "Madame Uppercut"},
        {"age", 39},
        {"secretIdentity", "Jane Wilson"},
        {"powers", {
            "Million tonne punch",
            "Damage resistance",
            "Superhuman reflexes"
        }},
    }
};


class ReaderFixture : public ::testing::Test
{
protected:

    std::unique_ptr<ApiCommunicatorMock> apiCommunicatorMockPtr_ = std::make_unique<ApiCommunicatorMock>();
};


TEST_F(ReaderFixture, ShouldReturnJsonObject)
{
    EXPECT_CALL(*apiCommunicatorMockPtr_, downloadData()).Times(1);

    const auto readerPtr = std::make_unique<Reader>(std::move(apiCommunicatorMockPtr_), READER_TEST_FILE_PATH);
    const nlohmann::json result = readerPtr->getContent();

    EXPECT_EQ(result, EXPECTED_RESULT);
}

} // masalamo