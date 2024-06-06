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
    int cellXHeader = PosX + Header.x * (CELL_SIZE + PADDING);
    int cellYHeader = PosY + Header.y * (CELL_SIZE + PADDING);
    int cellXTail = PosX + Tail.x * (CELL_SIZE + PADDING);
    int cellYTail = PosY + Tail.y * (CELL_SIZE + PADDING);

    Rectangle CellHeader = {cellXHeader, cellYHeader, CELL_SIZE, CELL_SIZE};
    Rectangle CellTail = {cellXTail, cellYTail, CELL_SIZE, CELL_SIZE};

    DrawRectangle(CellHeader.x, CellHeader.y, CellHeader.width, CellHeader.height, GREEN);
    DrawRectangle(CellTail.x, CellTail.y, CellTail.width, CellTail.height, GREEN);
    return CellTail;
}
