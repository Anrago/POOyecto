#include "raylib.h"
class Snake
{
public:
    Vector2 Header;
    Vector2 Tail;
    
    Snake();
    Snake(Vector2 Header,Vector2 Tail);
    Rectangle DrawSnake(int PosX, int PosY,int CELL_SIZE, int PADDING);
};


