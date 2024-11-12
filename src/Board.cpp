#include "Board.h"
#include <iostream>
Board::Board()
{
    NumPlayers = 1;
    Color colorsP[4] = {BLUE, RED, GREEN, YELLOW};
    for (int i = 0; i < NumPlayers; i++)
    {
        Player Temp = {NumPlayers, colorsP[i]}; // Inicializa jugador
        players.push_back(Temp);                // Almacena jugador en vector
    }

    InitSnakes();
    InitLadders();
}

Board::Board(short int NumPlayers)
{
    Color colorsP[4] = {BLUE, RED, GREEN, YELLOW}; // Colores de jugadores
    this->NumPlayers = NumPlayers;

    for (int i = 0; i < NumPlayers; i++)
    {
        Player Temp = {NumPlayers, colorsP[i]}; // Inicializa jugador
        
        // Esto luego lo muevo es solo para calar diferentes skins, o capas y lo dejo juasjuas
        if(i == 0){
            Temp.DefineSkin();
        }else if(i==1){
            Temp.DefineSkin2();
        }else if(i==2){
            Temp.DefineSkin3();
        }else if(i == 3){
            Temp.DefineSkin4();
        }

        players.push_back(Temp);                // Almacena jugador en vector
    }

    InitSnakes();
    InitLadders();
}

void Board::DefinePlayersPlaying(short int NumPlayers){
    Color colorsP[4] = {BLUE, RED, GREEN, YELLOW}; // Colores de jugadores
    this->NumPlayers = NumPlayers;

    for (int i = 0; i < NumPlayers; i++)
    {
        Player Temp = {NumPlayers, colorsP[i]}; // Inicializa jugador
        
        // Esto luego lo muevo es solo para calar diferentes skins, o capas y lo dejo juasjuas
        if(i == 0){
            Temp.DefineSkin();
        }else if(i==1){
            Temp.DefineSkin2();
        }else if(i==2){
            Temp.DefineSkin3();
        }else if(i == 3){
            Temp.DefineSkin4();
        }

        players.push_back(Temp);                // Almacena jugador en vector
    }

    InitSnakes();
    InitLadders();
}

void Board::DrawBoard(int PosX, int PosY)
{
    // Ciclo para recorrer filas
    for (int i = 0; i < 10; i++)
    {
        // Dibujado de serpiente y de escalera

        // Dibujamos los jugadores
        for (int k = 0; k < NumPlayers; k++)
        {
             // Variable que almacena el rectangulo del jugador actual
            Rectangle ActColision = players[k].BoxPlayer(PosX, PosY, CELL_SIZE, PADDING);

            // Serpientes
            // El limite sera el numero maximo de serpientes y escaleras, pero no sumadas
            for (int x = 0; x < 4; x++) 
            {
                Rectangle Tail = snakes[x].DrawSnake(PosX, PosY, CELL_SIZE, PADDING);

                if (CheckCollisionRecs(ActColision, Tail)) // Verifica colision entre jugador y serpiente
                    players[k].Position = snakes[x].Header;
            }
            
            // Escaleras
            for (int x = 0; x < 5; x++) 
            {
                Rectangle Base = ladders[x].DrawLadder(PosX, PosY, CELL_SIZE, PADDING);

                if (CheckCollisionRecs(ActColision, Base)) // Verifica colision entre jugador y escalera
                    players[k].Position = ladders[x].Destiny;
            }
            players[k].DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);
        }
        /*
            Podria separar los draw, osea del snake y ladder, un ciclo para dibujar estas primero, luego otra para obtener
            su posicion actual para las colisiones, asi evitaria que se sobrepongan encima de los jugadores, PERO
            si se supone que usaremos el mapa con las serpientes pues mejor que la funcion drawnsake solo
            retorne la posicion actual
        */
    }
}

void Board::MovePlayer()
{
    players[0].Move(2);
    players[1].Move(1);
    players[2].Move(3);
    players[3].Move(4);
}

void Board::MovePlayer(int NumPlayer, int boxes)
{
    players[NumPlayer].Move(boxes);
}

Vector2 Board:: GetActualPlayerPosition(int NumPlayer){
    return players[NumPlayer].Position;
}

// --------------------- Textures --------------------- //

Texture2D Board::GetPlayerSkin(int NumPlayer){
    return this->players[NumPlayer].skin;
}

void Board::DefineSnakeTexture()
{
    for (int i = 0; i < 4; i++)
        this->snakes[i].DefineSkin();
}

void Board::FreeSnakeTexture()
{
    for (int i = 0; i < 2; i++)
        this->snakes[i].FreeSkin();
}

void Board::InitSnakes()
{
    Snake temp = {{4, 4}, {1, 0}}; // Primero cola luego cabeza
    snakes.push_back(temp);
    
    temp = {{8, 3}, {7, 2}};
    snakes.push_back(temp);
    
    temp = {{1, 8}, {1, 7}};
    snakes.push_back(temp);
    
    temp = {{8, 9}, {5, 6}};
    snakes.push_back(temp);
}

void Board::InitLadders()
{
    Ladder temp = {{7, 0},{8, 1}}; // Primero base luego destino
    ladders.push_back(temp);
    
    temp = {{5, 2},{6, 4}}; 
    ladders.push_back(temp);
    
    temp = {{2, 4},{1, 5}}; 
    ladders.push_back(temp);
    
    temp = {{4, 6},{3, 8}}; 
    ladders.push_back(temp);
     
    temp = {{8, 5}, {9, 8}}; 
    ladders.push_back(temp);
    
}

void Board::DefinePlayerSkinGhost()
{
}

//---------------------------TODO MAL PERO NO LO BORRO XD-----------------------

// void Board::CasePlayers(Player *J1, Player *J2, int PosX, int PosY)
// {
//     Rectangle CollisionJ1 = J1->DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);
//     Rectangle CollisionJ2 = J2->DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);

//     if (CheckCollisionRecs(CollisionJ1, Tail))
//         J1->Position = snakes.Header;
//     if (CheckCollisionRecs(CollisionJ1, CollisionL))
//         J1->Position = ladders.Destiny;

//     if (CheckCollisionRecs(CollisionJ2, Tail))
//         J2->Position = snakes.Header;
//     if (CheckCollisionRecs(CollisionJ2, CollisionL))
//         J2->Position = ladders.Destiny;
// }

// void Board::CasePlayers(Player *J1, Player *J2, Player *J3, int PosX, int PosY)
// {
//     Rectangle CollisionJ1 = J1->DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);
//     Rectangle CollisionJ2 = J2->DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);
//     Rectangle CollisionJ3 = J3->DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);

//     Rectangle Tail = snakes.DrawSnake(PosX, PosY, CELL_SIZE, PADDING);
//     Rectangle CollisionL = ladders.DrawLadder(PosX, PosY, CELL_SIZE, PADDING);

//     if (CheckCollisionRecs(CollisionJ1, Tail))
//         J1->Position = snakes.Header;
//     if (CheckCollisionRecs(CollisionJ1, CollisionL))
//         J1->Position = ladders.Destiny;

//     if (CheckCollisionRecs(CollisionJ2, Tail))
//         J2->Position = snakes.Header;
//     if (CheckCollisionRecs(CollisionJ2, CollisionL))
//         J2->Position = ladders.Destiny;

//     if (CheckCollisionRecs(CollisionJ3, Tail))
//         J3->Position = snakes.Header;
//     if (CheckCollisionRecs(CollisionJ3, CollisionL))
//         J3->Position = ladders.Destiny;
// }

// void Board::CasePlayers(Player *J1, Player *J2, Player *J3, Player *J4, int PosX, int PosY)
// {
//     Rectangle CollisionJ1 = J1->DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);
//     Rectangle CollisionJ2 = J2->DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);
//     Rectangle CollisionJ3 = J3->DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);
//     Rectangle CollisionJ4 = J4->DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);

//     Rectangle Tail = snakes.DrawSnake(PosX, PosY, CELL_SIZE, PADDING);
//     Rectangle CollisionL = ladders.DrawLadder(PosX, PosY, CELL_SIZE, PADDING);

//     if (CheckCollisionRecs(CollisionJ1, Tail))
//         J1->Position = snakes.Header;
//     if (CheckCollisionRecs(CollisionJ1, CollisionL))
//         J1->Position = ladders.Destiny;

//     if (CheckCollisionRecs(CollisionJ2, Tail))
//         J2->Position = snakes.Header;
//     if (CheckCollisionRecs(CollisionJ2, CollisionL))
//         J2->Position = ladders.Destiny;

//     if (CheckCollisionRecs(CollisionJ3, Tail))
//         J3->Position = snakes.Header;
//     if (CheckCollisionRecs(CollisionJ3, CollisionL))
//         J3->Position = ladders.Destiny;

//     if (CheckCollisionRecs(CollisionJ4, Tail))
//         J4->Position = snakes.Header;
//     if (CheckCollisionRecs(CollisionJ4, CollisionL))
//         J4->Position = ladders.Destiny;
// }
