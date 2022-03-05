#pragma once

#include "EGroup.hpp"

#include <cstdint>
#include <string>


namespace masalamo
{

class Team
{
public:
    EGroup group_;

    int goalsDiff_;

    uint16_t draw_;
    uint16_t goalsAgainst_;
    uint16_t goalsFor_;
    uint16_t lose_;
    uint16_t played_;
    uint16_t points_;
    uint16_t rank_;
    uint16_t win_;

    std::string form_;
    std::string team_;
};

}