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
    Vector2 CellBaseV;
    CellBaseV.x = PosX + Base.x * (float(CELL_SIZE) + PADDING);
    CellBaseV.y = PosY + Base.y * (float(CELL_SIZE) + PADDING);

    Vector2 CellDestinyV;
    CellDestinyV.x = PosX + Destiny.x * (float(CELL_SIZE) + PADDING);
    CellDestinyV.y = PosY + Destiny.y * (float(CELL_SIZE) + PADDING);

    Rectangle CellBase = {CellBaseV.x, CellBaseV.y, float(CELL_SIZE), float(CELL_SIZE)};
    Rectangle CellDestiny = {CellDestinyV.x, CellDestinyV.y, float(CELL_SIZE), float(CELL_SIZE)}; 

    DrawRectangle(CellBase.x, CellBase.y, CellBase.width, CellBase.height, DARKBROWN);
    DrawRectangle(CellDestiny.x, CellDestiny.y, CellDestiny.width, CellDestiny.height, BROWN);
    return CellBase;
}
