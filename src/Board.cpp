#include "Board.h"

Board::Board()
{
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
        Rectangle CollisionP = players.DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);
        Rectangle CollisionS = snakes.DrawSnake(PosX, PosY, CELL_SIZE, PADDING);
        Rectangle CollisionL = ladders.DrawLadder(PosX, PosY, CELL_SIZE, PADDING);

        if (CheckCollisionRecs(CollisionP, CollisionS))
            players.Position = snakes.Header;
        if (CheckCollisionRecs(CollisionP, CollisionL))
            players.Position = ladders.Destiny;
    }
}

void Board::InitPlayer(short int NumPlayer, Color ColorPlayer)
{
    players = {NumPlayer, ColorPlayer};
}

void Board::MovePlayer()
{
    players.Move(1);
}
