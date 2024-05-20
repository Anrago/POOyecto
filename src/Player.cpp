#include "Player.h"

Player::Player(short int NumPlayer, Color PlayerColor)
{
    this->NumPlayer = NumPlayer;
    this->PlayerColor = PlayerColor;
}

Vector2 Player::Move(int NumCas)
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

        if (Position.x == 10 || Position.x == 1)
        {
            Position.y++;
        }
    }
    return Position;

   
}

// Player::Roll()
// {
//     return Dice::Roll();
// }
