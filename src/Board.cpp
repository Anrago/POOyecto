#include "Board.h"

Board::Board()
{
    NumPlayers = 2;
}

Board::Board(short int NumPlayers)
{
    Color colorsP[4] = {BLUE, RED, GREEN, YELLOW};
    for (int i = 0; i < NumPlayers; i++)
    {
        Player Temp = {NumPlayers, colorsP[i]};
        players.push_back(Temp);
    }
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
            int cellX = PosX + j * (CELL_SIZE + PADDING);
            int cellY = PosY + i * (CELL_SIZE + PADDING);

            // Define el rectángulo de la celda
            Rectangle cellRect = {cellX, cellY, CELL_SIZE, CELL_SIZE};
            DrawRectangle(cellRect.x, cellRect.y, cellRect.width, cellRect.height, BLACK);
        }

        Rectangle CollisionS = snakes.DrawSnake(PosX, PosY, CELL_SIZE, PADDING);
        Rectangle CollisionL = ladders.DrawLadder(PosX, PosY, CELL_SIZE, PADDING);

        Rectangle CollisionP = players[1].DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);
        players[0].DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);
        players[2].DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);
        players[3].DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);
        // Rectangle CollisionP =

        if (CheckCollisionRecs(CollisionP, CollisionS))
            players[1].Position = snakes.Header;
        if (CheckCollisionRecs(CollisionP, CollisionL))
            players[1].Position = ladders.Destiny;
    }
}

void Board::MovePlayer()
{
    players[0].Move(2);
    players[1].Move(1);
    players[2].Move(3);
    players[3].Move(0);
}
