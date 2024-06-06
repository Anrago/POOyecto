#pragma once
#include <vector>
#include "Player.h"
#include "Dice.h"
#include "Snake.h"
#include "Ladder.h"

#define COLUMNS 10
#define ROWS 10
#define CELL_SIZE 40
#define PADDING 5

using std::vector;
class Board
{
private:
    int BoardM[COLUMNS][ROWS];
    Snake snakes;
    Ladder ladders;
    Player players;
    Dice dices;
public:
    Board();
    //int GetCells(){return Cells;};
    void DrawBoard(int PosX, int PosY);
    void InitPlayer(short int NumPlayer,Color ColorPlayer);
    void MovePlayer();

};
