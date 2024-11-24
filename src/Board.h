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
    vector <Snake> snakes;
    vector <Ladder> ladders;
    Dice dices;
    short int numPlayers;

public:
    vector <Player> players;
    Board();
    Board(short int numPlayers);
    void DrawBoard(int PosX, int PosY);
    // NumPlayer= Numero de jugador , boxes = numero de casillas que avanzara
    
    void DefinePlayersPlaying(short int numPlayers);
    
    void MovePlayer(int NumPlayer,int boxes);
    // --------- Textures --------- //
    // Players
    void DefinePlayerSkinGhost();
    Texture2D GetPlayerSkin(int NumPlayer);
    Vector2 GetActualPlayerPosition(int NumPlayer);
    
    // Snake
    void DefineSnakeTexture();
    void FreeSnakeTexture();
    void InitSnakes();
    void InitLadders();
};
