#include "raylib.h"
class Ladder
{
public:
    Vector2 destiny;
    Vector2 base;

    Ladder();
    Ladder(Vector2 destiny,Vector2 base);
    Rectangle DrawLadder(int PosX, int PosY,int CELL_SIZE, int PADDING);
};

