#pragma once
#include <vector>
#include "Player.h"
#include "Dice.h"
#include "Snake.h"
#include "Ladder.h"

using std::vector;
class Board
{
private:
    int Cells;
    vector<Snake> snakes;
    vector<Ladder> ladders;
    Player players[];
    Dice dices[];
public:
    Board();

};
