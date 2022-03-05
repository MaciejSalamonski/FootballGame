#pragma once

#include "EGroup.hpp"

#include <cstdint>
#include <string>


namespace masalamo
{

class Team
{
public:

    bool operator==(const Team& otherTeam) const
    {
        return isEqual(otherTeam) ? true : false;
    }

    bool operator!=(const Team& otherTeam) const
    {
        return isEqual(otherTeam) ? false : true;
    }

    EGroup group;
    int goalsDiff;
    uint16_t draw;
    uint16_t goalsAgainst;
    uint16_t goalsFor;
    uint16_t lose;
    uint16_t played;
    uint16_t points;
    uint16_t rank;
    uint16_t win;
    std::string form;
    std::string team;

private:
    bool isEqual(const Team& otherTeam) const
    {
        return group == otherTeam.group && goalsDiff == otherTeam.goalsDiff &&
            draw == otherTeam.draw && goalsAgainst == otherTeam.goalsAgainst &&
            goalsFor == otherTeam.goalsFor && lose == otherTeam.lose &&
            played == otherTeam.played && points == otherTeam.points &&
            rank == otherTeam.rank && win == otherTeam.win &&
            form == otherTeam.form && team == otherTeam.team;
    }
};

}