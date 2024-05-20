#include "Player.h"

Player::Player(short int NumPlayer, Color PlayerColor)
{
    this->NumPlayer = NumPlayer;
    this->PlayerColor = PlayerColor;
}

vector2 Player::Move(int NumCas)
{
    for (int i = 0; i < NumCas; i++)
    {
        if (Position.y % 2 == 1)
        {
            Position.x++;
        }
        if (Position.y % 2 == 0)
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
