#include "Snake.h"

Snake::Snake()
{
    Header = {8, 3};
    Tail = {2, 2};
}

Snake::Snake(Vector2 Header, Vector2 Tail)
{
    this->Header = Header;
    this->Tail = Tail;
}

Rectangle Snake::DrawSnake(int PosX, int PosY, int CELL_SIZE, int PADDING)
{
    // Vector2 CellHeaderV;
    // CellHeaderV.x=PosX + Header.x * (float(CELL_SIZE) + PADDING);
    // CellHeaderV.y=PosY + Header.y * (float(CELL_SIZE) + PADDING);
    
    Vector2 CellTailV;
    CellTailV.x=PosX + Tail.x * (float(CELL_SIZE) + PADDING);
    CellTailV.y=PosY + Tail.y * (float(CELL_SIZE) + PADDING);
    
    // Inutlizada
    // Rectangle CellHeaderR = {CellHeaderV.x, CellHeaderV.y, float(CELL_SIZE), float(CELL_SIZE)};
    
    Rectangle CellTailR = {CellTailV.x, CellTailV.y, float(CELL_SIZE), float(CELL_SIZE)};
    
    // // Head
    // DrawTextureEx(this->skin,CellHeaderV,0.0f,1.0f,WHITE);
    // // Tail
    // DrawTextureEx(this->skin,CellTailV,0.0f,1.0f,WHITE);

    // DrawRectangle(CellHeaderR.x, CellHeaderR.y, CellHeaderR.width, CellHeaderR.height, DARKGREEN);
    // DrawRectangle(CellTailR.x, CellTailR.y, CellTailR.width, CellTailR.height, GREEN);
    return CellTailR;
}

void Snake::DefineSkin(){
    this->skin = LoadTexture("../assets/snake/SnakeHead.png");
}
void Snake::FreeSkin(){
    UnloadTexture(this->skin);
}