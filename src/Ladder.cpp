#include "Ladder.h"

Ladder::Ladder()
{
    base = {4, 7};
    destiny = {3, 3};
}

Ladder::Ladder(Vector2 destiny, Vector2 base)
{
    this->destiny = destiny;
    this->base = base;
}

Rectangle Ladder::DrawLadder(int PosX, int PosY, int CELL_SIZE, int PADDING)
{
    Vector2 CellBaseV;
    CellBaseV.x = PosX + base.x * (float(CELL_SIZE) + PADDING);
    CellBaseV.y = PosY + base.y * (float(CELL_SIZE) + PADDING);

    Rectangle CellBase = {CellBaseV.x, CellBaseV.y, float(CELL_SIZE), float(CELL_SIZE)};

    return CellBase;
}
