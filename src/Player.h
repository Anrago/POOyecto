#include "raylib.h"
#include "Dice.h"
class Player
{
public:
    short int NumPlayer;
    Color PlayerColor;
    Vector2 Position = {0,9};
    Player(short int NumPlayer=1,Color PlayerColor = BLUE);
    void Move(int NumCas);
    //virtual int Roll();


};