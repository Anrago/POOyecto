#include "Player.h"

Player::Player(short int NumPlayer, Color PlayerColor)
{
    this->NumPlayer = NumPlayer;
    this->PlayerColor = PlayerColor;
}

void Player::Move(int NumCas)
{
    for (int i = 0; i < NumCas; i++)
    {
        if ((int)Position.y % 2 == 1)
        {
            Position.x++;
        }
        if ((int)Position.y % 2 == 0)
        {
            Position.x--;
        }

        if ((int)Position.x == 10)
        {
            Position.y--;
            Position.x--;
        }
        if ((int)Position.x == -1)
        {
            Position.y--;
            Position.x++;
        }
    }
}

Rectangle Player::DrawPlayer(int PosX, int PosY, int CELL_SIZE, int PADDING)
{
    Vector2 CellV;
    CellV.x = PosX + Position.x * (CELL_SIZE + PADDING);
    CellV.y = PosY + Position.y * (CELL_SIZE + PADDING);

    Rectangle cellRect = {CellV.x, CellV.y, float(CELL_SIZE), float(CELL_SIZE)};
    DrawRectangle(cellRect.x, cellRect.y, cellRect.width, cellRect.height, PlayerColor);
    return cellRect;
}


// Player::Roll()
// {
//     return Dice::Roll();
// }
