#include "Player.h"

Player::Player(short int numPlayer, Color playerColor)
{
    this->numPlayer = numPlayer;
    this->playerColor = playerColor;
}

void Player::Move(int numCas)
{
    bool retur = false;
    for (int i = 0; i < numCas; i++)
    {
        if((int)position.y == 0){
            if(position.x == 0 || retur == true){
                retur = true;
                position.x++;
            }
            else
            {
                position.x--;
            }
        }
        else
        {
            if ((int)position.y % 2 == 1)
            {
                position.x++;
            }
            if ((int)position.y % 2 == 0)
            {
                position.x--;
            }
    //--------------------------------
            if ((int)position.x == 10)
            {
                position.y--;
                position.x--;
            }
            if ((int)position.x == -1)
            {
                position.y--;
                position.x++;
            }
        }
    }
}

Vector2 Player::GetPosition(){
    return this->position;
}

Rectangle Player::BoxPlayer(int posX, int posY, int cellSize, int padding)
{
    Vector2 CellV;
    CellV.x = posX + position.x * (cellSize + padding);
    CellV.y = posY + position.y * (cellSize + padding);

    Rectangle cellRect = {CellV.x, CellV.y, float(cellSize), float(cellSize)};
    
    return cellRect;
}

void Player::DrawPlayer(int posX, int posY, int cellSize, int padding)
{
    Vector2 CellV;
    CellV.x = posX + position.x * (cellSize + padding);
    CellV.y = posY + position.y * (cellSize + padding);

    Rectangle cellRect = {CellV.x, CellV.y, float(cellSize), float(cellSize)};

    DrawRectangle(cellRect.x, cellRect.y, cellRect.width, cellRect.height, playerColor);
    
    DrawTextureEx(this->skin,CellV,0.0f,1.0f,WHITE);
}

// ----------------
// Creamos una funcion general para inicializar las 4 skins

void Player::DefineSkins(int index){
    if(index==1){
        this->skin = LoadTexture("../assets/players/Ghost.png");
    }
    else if(index == 2){
        this->skin = LoadTexture("../assets/players/GhostGirl.png");    
    }
    else if(index == 3){
        this->skin = LoadTexture("../assets/players/GhostPesado.png");
    }
    else if(index == 4){
        this->skin = LoadTexture("../assets/players/GhostFrio.png");
    }
}

// void Player::DefineSkin(){
//     this->skin = LoadTexture("../assets/players/Ghost.png");
// }

// void Player::DefineSkin2(){
//     this->skin = LoadTexture("../assets/players/GhostGirl.png");
// }

// void Player::DefineSkin3(){
//     this->skin = LoadTexture("../assets/players/GhostPesado.png");
// }
// void Player::DefineSkin4(){
//     this->skin = LoadTexture("../assets/players/GhostFrio.png");
// }
// ----------------