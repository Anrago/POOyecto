#include "raylib.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "./Clases/Player.h"
#include "./Clases/Snake.h"


int main(){
    srand(time(NULL));

    int screenWidth=1280;
    int screenHeight=700;

    InitWindow(screenWidth,screenHeight,"Pooyecto");
    SetTargetFPS(60);

    Dice dice1,dice2;
    Board map(screenWidth,screenHeight);
    Player p1(screenWidth,screenHeight,map);

    // --------- Serpientes --------- //
    Rectangle s1Start=p1.getCordCasilla(4);
    Rectangle s1Finish=p1.getCordCasilla(12);
    Snake s1(s1Start,s1Finish);

    int filatemp=p1.getFila(10);

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

            DrawRectangleRec(s1.start,GREEN);
            DrawRectangleRec(s1.finall,GREEN);

            if (CheckCollisionRecs(p1.rec,s1.finall)){
                p1=s1.Down(p1);
                
            }
            

            DrawRectangleRec(boton,RED);
            if(CheckCollisionPointRec(Click,boton)){

                cout<<filatemp<<endl;
                dado=dice1.DropDice();
                p1.MovePosition(1);
                Click={0,0};
            }
            

        EndDrawing();
    } 
    CloseWindow();
    return 0;
}

