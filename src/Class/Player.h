#include "raylib.h"
#include "Dice.h"
class Player
{
private:
    short int NumPlayer;
    Color PlayerColor;
    Vector2 Position=0;
public:
    Player(short int NumPlayer=1,Color PlayerColor = BLUE);
    vectro2 Move(int NumCas);

};