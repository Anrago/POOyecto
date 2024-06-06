#include "raylib.h"
#include "Dice.h"
class Player
{
public:
    short int NumPlayer;
    Color PlayerColor;
    Vector2 Position = {2,7};
    Player(short int NumPlayer=1,Color PlayerColor = BLUE);
    void Move(int NumCas);
    Rectangle DrawPlayer(int PosX, int PosY,int CELL_SIZE, int PADDING);
    //virtual int Roll();


};