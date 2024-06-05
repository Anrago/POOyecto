#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "Board.h"

#define COLUMNS 10
#define RWOS 10
#define CELL_SIZE 40
#define PADDING 5

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
    Vector2 a;
    a.x= -1;
    int b = a.x;
    
    int matrix[10][10]={0};
    Board Tablero;
    Tablero.InitPlayer(1,GREEN);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);
        Tablero.DrawBoard(40,80);
        if(IsKeyPressed(KEY_D))
        {
            Tablero.MovePlayer();
            printf("%d",b);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
