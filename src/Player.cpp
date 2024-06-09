#include "Player.h"

Player::Player(short int NumPlayer, Color PlayerColor)
{
    this->NumPlayer = NumPlayer;
    this->PlayerColor = PlayerColor;
}

void Player::Move(int NumCas)
{
    bool retur = false;
    for (int i = 0; i < NumCas; i++)
    {
        if((int)Position.y == 0){
            if(Position.x == 0 || retur == true){
                retur = true;
                Position.x++;
            }
            else
            {
                Position.x--;
            }
        }
        else
        {
            if ((int)Position.y % 2 == 1)
            {
                Position.x++;
            }
            if ((int)Position.y % 2 == 0)
            {
                Position.x--;
            }
    //--------------------------------
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
}

Vector2 Player::GetPosition(){
    return this->Position;
}

Rectangle Player::BoxPlayer(int PosX, int PosY, int CELL_SIZE, int PADDING)
{
    Vector2 CellV;
    CellV.x = PosX + Position.x * (CELL_SIZE + PADDING);
    CellV.y = PosY + Position.y * (CELL_SIZE + PADDING);

    Rectangle cellRect = {CellV.x, CellV.y, float(CELL_SIZE), float(CELL_SIZE)};

    // DrawRectangle(cellRect.x, cellRect.y, cellRect.width, cellRect.height, PlayerColor);    
    // DrawTextureEx(this->skin,CellV,0.0f,1.0f,WHITE);
    
    return cellRect;
}

void Player::DrawPlayer(int PosX, int PosY, int CELL_SIZE, int PADDING)
{
    Vector2 CellV;
    CellV.x = PosX + Position.x * (CELL_SIZE + PADDING);
    CellV.y = PosY + Position.y * (CELL_SIZE + PADDING);

    Rectangle cellRect = {CellV.x, CellV.y, float(CELL_SIZE), float(CELL_SIZE)};

    DrawRectangle(cellRect.x, cellRect.y, cellRect.width, cellRect.height, PlayerColor);
    
    DrawTextureEx(this->skin,CellV,0.0f,1.0f,WHITE);
}

void Player::DefineSkin(){
    this->skin = LoadTexture("../assets/players/Ghost.png");
}

void Player::DefineSkin2(){
    this->skin = LoadTexture("../assets/players/GhostGirl.png");
}

void Player::DefineSkin3(){
    this->skin = LoadTexture("../assets/players/GhostPesado.png");
}
void Player::DefineSkin4(){
    this->skin = LoadTexture("../assets/players/GhostFrio.png");
}

// Player::Roll()
// {
//     return Dice::Roll();
// }
