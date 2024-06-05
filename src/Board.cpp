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
        DrawPlayer(PosX, PosY);
        DrawSnake(PosX, PosY);
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

void Board::DrawPlayer(int PosX, int PosY)
{
    int cellX = PosX + players.Position.x * (CELL_SIZE + PADDING);
    int cellY = PosY + players.Position.y * (CELL_SIZE + PADDING);

    Rectangle cellRect = {cellX, cellY, CELL_SIZE, CELL_SIZE};
    DrawRectangle(cellRect.x, cellRect.y, cellRect.width, cellRect.height, BLUE);
}

void Board::DrawSnake(int PosX, int PosY)
{
    int cellXHeader = PosX + snakes.Header.x * (CELL_SIZE + PADDING);
    int cellYHeader = PosY + snakes.Header.x * (CELL_SIZE + PADDING);
    int cellXTail = PosX + snakes.Tail.x * (CELL_SIZE + PADDING);
    int cellYTail = PosY + snakes.Tail.x * (CELL_SIZE + PADDING);

    Rectangle CellHeader = {cellXHeader, cellYHeader, CELL_SIZE, CELL_SIZE};
    Rectangle CellTail = {cellXTail, cellYTail, CELL_SIZE, CELL_SIZE};

    DrawRectangle(CellHeader.x, CellHeader.y, CellHeader.width, CellHeader.height, GREEN);
    DrawRectangle(CellTail.x, CellTail.y, CellTail.width, CellTail.height, GREEN);
}
