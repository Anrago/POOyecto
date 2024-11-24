#include "Snake.h"

Snake::Snake()
{
    header = {8, 3};
    tail = {2, 2};
}

Snake::Snake(Vector2 Header, Vector2 Tail)
{
    this->header = Header;
    this->tail = Tail;
}

Rectangle Snake::DrawSnake(int PosX, int PosY, int CELL_SIZE, int PADDING)
{
    
    Vector2 CellTailV;
    CellTailV.x=PosX + tail.x * (float(CELL_SIZE) + PADDING);
    CellTailV.y=PosY + tail.y * (float(CELL_SIZE) + PADDING);
    
    Rectangle CellTailR = {CellTailV.x, CellTailV.y, float(CELL_SIZE), float(CELL_SIZE)};

    return CellTailR;
}

void Snake::DefineSkin(){
    this->skin = LoadTexture("../assets/snake/SnakeHead.png");
}
void Snake::FreeSkin(){
    UnloadTexture(this->skin);
}