#include "Player.h"

Player::Player(short int NumPlayer, Color PlayerColor)
{
    this->NumPlayer = NumPlayer;
    this->PlayerColor = PlayerColor;
}

vectro2 Player::Move(int NumCas)
{
    for (int i = 0; i < NumCas; i++)
    {
        if (Position.y%2==1)
        {
            Position.x++;
        }
        else
        {
            
        }
        
    }
    
    return vectro2();
}
