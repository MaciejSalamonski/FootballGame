#include "../../inc/DataParser/Parser.hpp"

#include "../../inc/DataParser/Reader.hpp"

#include "../mocks/ApiCommunicatorMock.hpp"

#include "gtest/gtest.h"

namespace masalamo
{

class ParserFixture : public ::testing::Test
{
protected:
    const std::string PARSER_TEST_FILE_PATH = {"../test/constants/ParserTestFile.json"};
    const size_t EXPECTED_RESULT_CONTAINER_SIZE = 3;
    const std::vector<Team> EXPECTED_TEAM_CONTAINER
    {
        {EGroup::EGroupA, 5, 0, 0, 5, 0, 3, 9, 1, 3, "WWW", "Uruguay"},
        {EGroup::EGroupA, 4, 0, 4, 8, 1, 3, 6, 2, 2, "LWW", "Russia"},
        {EGroup::EGroupH, -3, 0, 5, 2, 2, 3, 3, 4, 1, "LLL", "Poland"}
    };

    std::unique_ptr<ApiCommunicatorMock> apiCommunicatorMockPtr_ = std::make_unique<ApiCommunicatorMock>();
    std::unique_ptr<Reader> readerPtr_ = std::make_unique<Reader>(std::move(apiCommunicatorMockPtr_), PARSER_TEST_FILE_PATH);
};


TEST_F(ParserFixture, parserShouldReturnContainerWithProperFilledObjectsOfTypeTeam)
{
    //EXPECT_CALL(*apiCommunicatorMockPtr_, downloadData()).Times(1);

    std::unique_ptr<Parser> parserPtr = std::make_unique<Parser>(std::move(readerPtr_));
    const std::vector<Team> resultTeamsContainer = parserPtr->parse();

    EXPECT_EQ(resultTeamsContainer[0], EXPECTED_TEAM_CONTAINER[0]);
    EXPECT_EQ(resultTeamsContainer[1], EXPECTED_TEAM_CONTAINER[1]);
    EXPECT_EQ(resultTeamsContainer[2], EXPECTED_TEAM_CONTAINER[2]);
    EXPECT_NE(resultTeamsContainer[1], EXPECTED_TEAM_CONTAINER[2]);
    EXPECT_NE(resultTeamsContainer[2], EXPECTED_TEAM_CONTAINER[3]);
    EXPECT_NE(resultTeamsContainer[1], EXPECTED_TEAM_CONTAINER[3]);

    EXPECT_EQ(resultTeamsContainer.size(), EXPECTED_RESULT_CONTAINER_SIZE);
}

} // masalamo