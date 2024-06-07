#include "raylib.h"
#include "Dice.h"
class Player
{
public:
    short int NumPlayer;
    Color PlayerColor;
    Vector2 Position = {0,9};
    
    Player(short int NumPlayer=1,Color PlayerColor = BLUE);
    Rectangle DrawPlayer(int PosX, int PosY,int CELL_SIZE, int PADDING);
    void Move(int NumCas);
    //virtual int Roll();


};