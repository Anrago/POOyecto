#include "Board.h"
#include <iostream>
Board::Board()
{
    NumPlayers = 2;
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
        Temp.DefineSkin();
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
        // Ciclo para recorrer columnas
        for (int j = 0; j < 10; j++)
        {
            // Calcula las coordenadas de la celda
            float cellX = PosX + j * (CELL_SIZE + PADDING);
            float cellY = PosY + i * (CELL_SIZE + PADDING);

            // Define el rectángulo de la celda
            Rectangle cellRect = {cellX, cellY, CELL_SIZE, CELL_SIZE};
            DrawRectangle(cellRect.x, cellRect.y, cellRect.width, cellRect.height, BLACK);
        }

        // Dibujado de serpiente y de escalera

        for (int k = 0; k < NumPlayers; k++)
        {
            Rectangle ActColision = players[k].DrawPlayer(PosX, PosY, CELL_SIZE, PADDING); // Variable que almacena el rectangulo del jugador actual
            for (int x = 0; x < 2; x++)
            {
                Rectangle CollisionS = snakes[x].DrawSnake(PosX, PosY, CELL_SIZE, PADDING);
                Rectangle CollisionL = ladders[x].DrawLadder(PosX, PosY, CELL_SIZE, PADDING);
                if (CheckCollisionRecs(ActColision, CollisionS)) // Verifica colision entre jugador y serpiente
                    players[k].Position = snakes[x].Header;
                if (CheckCollisionRecs(ActColision, CollisionL)) // Verifica colision entre jugador y escalera
                    players[k].Position = ladders[x].Destiny;
            }
        }

        // CasePlayers(&players[0], &players[1], &players[2], &players[3], PosX, PosY);
        // std::cout << NumPlayers << std::endl;
    }
}

void Board::MovePlayer()
{
    players[0].Move(2);
    players[1].Move(1);
    players[2].Move(3);
    players[3].Move(4);
}

// --------------------- Textures --------------------- //

void Board::DefineSnakeTexture(){
    this->snakes.DefineSkin();
}

void Board::FreeSnakeTexture(){
    this->snakes.FreeSkin();
}

void Board:: DefinePlayerSkinGhost(){
    
}

//---------------------------TODO MAL PERO NO LO BORRO XD-----------------------

// void Board::CasePlayers(Player *J1, Player *J2, int PosX, int PosY)
// {
//     Rectangle CollisionJ1 = J1->DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);
//     Rectangle CollisionJ2 = J2->DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);

//     if (CheckCollisionRecs(CollisionJ1, CollisionS))
//         J1->Position = snakes.Header;
//     if (CheckCollisionRecs(CollisionJ1, CollisionL))
//         J1->Position = ladders.Destiny;

//     if (CheckCollisionRecs(CollisionJ2, CollisionS))
//         J2->Position = snakes.Header;
//     if (CheckCollisionRecs(CollisionJ2, CollisionL))
//         J2->Position = ladders.Destiny;
// }

// void Board::CasePlayers(Player *J1, Player *J2, Player *J3, int PosX, int PosY)
// {
//     Rectangle CollisionJ1 = J1->DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);
//     Rectangle CollisionJ2 = J2->DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);
//     Rectangle CollisionJ3 = J3->DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);

//     Rectangle CollisionS = snakes.DrawSnake(PosX, PosY, CELL_SIZE, PADDING);
//     Rectangle CollisionL = ladders.DrawLadder(PosX, PosY, CELL_SIZE, PADDING);

//     if (CheckCollisionRecs(CollisionJ1, CollisionS))
//         J1->Position = snakes.Header;
//     if (CheckCollisionRecs(CollisionJ1, CollisionL))
//         J1->Position = ladders.Destiny;

//     if (CheckCollisionRecs(CollisionJ2, CollisionS))
//         J2->Position = snakes.Header;
//     if (CheckCollisionRecs(CollisionJ2, CollisionL))
//         J2->Position = ladders.Destiny;

//     if (CheckCollisionRecs(CollisionJ3, CollisionS))
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

//     Rectangle CollisionS = snakes.DrawSnake(PosX, PosY, CELL_SIZE, PADDING);
//     Rectangle CollisionL = ladders.DrawLadder(PosX, PosY, CELL_SIZE, PADDING);

//     if (CheckCollisionRecs(CollisionJ1, CollisionS))
//         J1->Position = snakes.Header;
//     if (CheckCollisionRecs(CollisionJ1, CollisionL))
//         J1->Position = ladders.Destiny;

//     if (CheckCollisionRecs(CollisionJ2, CollisionS))
//         J2->Position = snakes.Header;
//     if (CheckCollisionRecs(CollisionJ2, CollisionL))
//         J2->Position = ladders.Destiny;

//     if (CheckCollisionRecs(CollisionJ3, CollisionS))
//         J3->Position = snakes.Header;
//     if (CheckCollisionRecs(CollisionJ3, CollisionL))
//         J3->Position = ladders.Destiny;

//     if (CheckCollisionRecs(CollisionJ4, CollisionS))
//         J4->Position = snakes.Header;
//     if (CheckCollisionRecs(CollisionJ4, CollisionL))
//         J4->Position = ladders.Destiny;
// }
