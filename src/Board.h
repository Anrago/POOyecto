#pragma once
#include <vector>
#include "Player.h"
#include "Dice.h"
#include "Snake.h"
#include "Ladder.h"

#define COLUMNS 10
#define ROWS 10
#define CELL_SIZE 50
#define PADDING 10

using std::vector;
class Board
{
private:
    Snake snakes;
    Ladder ladders;
    vector <Player> players;
    Dice dices;
    short int NumPlayers;
public:
    Board();
    Board(short int NumPlayers);
    void DrawBoard(int PosX, int PosY);
    void MovePlayer();

};
