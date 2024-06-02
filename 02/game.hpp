#pragma once

#include <iostream>
#include <vector>
#include "gamers.hpp"

#define MAX_MATCHSTICK 3

class MachstickGame {
public:
    MachstickGame(uint32_t numGamers, uint32_t numMatchsticks);

    ~MachstickGame();

    void gameStart();

private:
    uint32_t matchsticks;
    std::vector<Gamer*> gamers;
    Gamer *loser;

    void makeMove(Gamer *gamer);
    void gameEnd();
};