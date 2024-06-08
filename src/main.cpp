#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    
    int PlayerPlaying=2;

    Board Tablero(PlayerPlaying);
    // we define the texture of the snake
    Tablero.DefineSnakeTexture();
    
    Dice dado;
    int playerTurn=0;
    int playerMove=0;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);
        Tablero.DrawBoard(320, 80);
        
        
        if (IsKeyPressed(KEY_D))
        {
            playerMove = dado.DropDice();
            
            Tablero.MovePlayer(playerTurn,playerMove);
            
            playerTurn++;
            
            if(playerTurn >= PlayerPlaying){
                playerTurn=0;
            }
        }
        EndDrawing();
    }
    CloseWindow();

    Tablero.FreeSnakeTexture();
    return 0;
}
