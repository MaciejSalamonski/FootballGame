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

    void SetUp() override
    {
        apiCommunicatorMockPtr_ = std::make_unique<ApiCommunicatorMock>();
        EXPECT_CALL(*apiCommunicatorMockPtr_, downloadData()).Times(1);

        readerPtr_ = std::make_unique<Reader>(*apiCommunicatorMockPtr_, READER_TEST_FILE_PATH);
    }

    std::unique_ptr<ApiCommunicatorMock> apiCommunicatorMockPtr_;
    std::unique_ptr<Reader> readerPtr_;
};


TEST_F(ReaderFixture, ShouldReturnJsonObject)
{
    const nlohmann::json result = readerPtr_->getContent();

    EXPECT_EQ(result, EXPECTED_RESULT);
}

} // masalamo