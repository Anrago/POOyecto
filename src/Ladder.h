#include "raylib.h"
class Ladder
{
public:
    Vector2 Destiny;
    Vector2 Base;

    Ladder();
    Ladder(Vector2 Destiny,Vector2 Base);
    Rectangle DrawLadder(int PosX, int PosY,int CELL_SIZE, int PADDING);
};

