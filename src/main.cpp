#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

/*      POOYECTO-SNAKE AND LADDERS

El pooyecto sera un serpientes y escaleras


COMANDOS
cd buidl
mingw32-make
./name.exe

*/


int main()
{
    //Ventana
    int screenWidth = 1280;
    int screenHeight = 720;
    InitWindow(screenWidth, screenHeight,"SerpientesyEscaleras");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Hola mundo",screenWidth/2,screenHeight/2,24,BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}