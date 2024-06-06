#include "Ladder.h"

Ladder::Ladder()
{
    Base = {4, 7};
    Destiny = {3, 3};
}

Ladder::Ladder(Vector2 Destiny, Vector2 Base)
{
    this->Destiny = Destiny;
    this->Base = Base;
}

Rectangle Ladder::DrawLadder(int PosX, int PosY, int CELL_SIZE, int PADDING)
{
    int cellXBase = PosX + Base.x * (CELL_SIZE + PADDING);
    int cellYBase = PosY + Base.y * (CELL_SIZE + PADDING);
    int cellXDestiny = PosX + Destiny.x * (CELL_SIZE + PADDING);
    int cellYDestiny = PosY + Destiny.y * (CELL_SIZE + PADDING);

    Rectangle CellBase = {cellXBase, cellYBase, CELL_SIZE, CELL_SIZE};
    Rectangle CellDestiny = {cellXDestiny, cellYDestiny, CELL_SIZE, CELL_SIZE};

    DrawRectangle(CellBase.x, CellBase.y, CellBase.width, CellBase.height, BROWN);
    DrawRectangle(CellDestiny.x, CellDestiny.y, CellDestiny.width, CellDestiny.height, BROWN);
    return CellBase;
}
