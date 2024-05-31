#include "raylib.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "./Clases/Player.h"


int main(){
    srand(time(NULL));

    int screenWidth=1280;
    int screenHeight=700;

    InitWindow(screenWidth,screenHeight,"Pooyecto");
    SetTargetFPS(60);

    Dice dice1,dice2;
    Board map(screenWidth,screenHeight);
    Player p1(screenWidth,screenHeight,map);

    int dado;

    int GridCont=0;
    int margen= 50;

    Rectangle boton;
    boton.x=0;
    boton.y=500;
    boton.width=100;
    boton.height=100;

    Vector2 Mouse;
    Vector2 Click;

    while (!WindowShouldClose())
    {
        BeginDrawing();
            
            Mouse=GetMousePosition();

            ClearBackground(BLACK);
            
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                Click=Mouse;
            }
            
            GridCont = 0;
            for (int x = map.startGrid.x; GridCont <= map.Gridx; x += map.GridSize, GridCont ++) 
            {
                /*Dibujar las lineas verticales
                en x no dibuja lineas, solo hara saltos de gridsize
                en y dibujara desde 0 hasta screenHeight*/
                DrawLine(x, margen, x, (map.GridSize * 10) + margen, LIGHTGRAY);
            }
            GridCont = 0;
            for (int y = map.startGrid.y; GridCont <= map.Gridx; y += map.GridSize, GridCont ++) 
            {
                /*Dibujar las lineas verticales
                en y no dibuja lineas, solo hara saltos de gridsize
                en x dibujara desde 0 hasta screenHeight
                practicamente, y sirve para hacer saltos del tamanio del gridsize y la parte de
                0 y screenheight es la que dibujara las lineas desde el inicio hasta el fin
                */
                DrawLine(map.startGrid.x, y, (map.GridSize * 10) + map.startGrid.x, y, LIGHTGRAY);
            }
            DrawRectangleRec(p1.rec,RED);

            DrawRectangleRec(boton,RED);
            if(CheckCollisionPointRec(Click,boton)){
                dado=dice1.DropDice();
                cout<<dado<<endl;
                p1.MovePosition(dado);
                Click.x=0;
                Click.y=0;
            }
            

        EndDrawing();
    } 
    CloseWindow();
    return 0;
}

