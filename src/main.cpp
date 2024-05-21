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
    //Ventana
    int screenWidth = 1280;
    int screenHeight = 720;
    InitWindow(screenWidth, screenHeight,"SerpientesyEscaleras");
    SetTargetFPS(60);
    srand(time(NULL));
    
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Hola mundo",(screenWidth/2 ) - 50,(screenHeight/2) - 20,24,BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}