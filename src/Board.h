#pragma once
#include <vector>
#include <iostream>
#include "Player.h"
#include "Dice.h"
#include "Snake.h"
#include "Ladder.h"

#define COLUMNS 10
#define ROWS 10
#define CELL_SIZE 50
#define PADDING 10

using std::vector;

// Patron singelton para el board
class Board
{
private:
    static Board* instance;
    vector <Snake> snakes;
    vector <Ladder> ladders;
    Dice dices;
    short int numPlayers;
    Board();

public:
    vector <Player> players;

    // ---------- Singelton ----------
    static Board* getInstance(){
        if(instance == nullptr){
            instance = new Board();
        }
        return instance;
    }

    // prohibir copia y asignacion
    Board(const Board&)= delete;
    Board& operator=(const Board&) = delete;
    // ---------- ---------- ----------

    void DrawBoard(int PosX, int PosY);
    void DefinePlayersPlaying(short int numPlayers);
    
    // NumPlayer= Numero de jugador , boxes = numero de casillas que avanzara
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

