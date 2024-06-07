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
    Vector2 a;
    a.x = -1;
    int b = a.x;
    Board Tablero = {4};
    // Tablero.InitPlayer(1,GREEN);
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
    return 0;
}
