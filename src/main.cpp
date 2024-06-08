#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "Board.h"

/*      POOYECTO-SNAKE AND LADDERS

El pooyecto sera un serpientes y escaleras


COMANDOS
cd build
mingw32-make
./name.exe

*/

int main()
{
    // Ventana
    int screenWidth = 1280;
    int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "SerpientesyEscaleras");
    SetTargetFPS(60);
    srand(time(NULL));
    // Variable inutilizada
    // Vector2 a;
    // a.x = -1;
    // int b = a.x;
    Board Tablero;
    // we define the texture of the snake
    Tablero.DefineSnakeTexture();
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);
        Tablero.DrawBoard(320, 80);
        if (IsKeyPressed(KEY_D))
        {
            Tablero.MovePlayer();
        }
        EndDrawing();
    }
    CloseWindow();

    Tablero.FreeSnakeTexture();
    return 0;
}
