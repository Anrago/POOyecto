#include "raylib.h"
#include "Dice.h"
class Player
{
private:
    short int NumPlayer;
    Color PlayerColor;
    Vector2 Position;
public:
    Player(short int NumPlayer=1,Color PlayerColor = BLUE);
    Vector2 Move(int NumCas);
    //virtual int Roll();

};