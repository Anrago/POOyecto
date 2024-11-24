#include "Board.h"
#include <iostream>

Board::Board()
{
    numPlayers = 1;
    Color colorsP[4] = {BLUE, RED, GREEN, YELLOW};
    for (int i = 0; i < numPlayers; i++)
    {
        Player temp = {numPlayers, colorsP[i]}; 
        players.push_back(temp);                
    }

    InitSnakes();
    InitLadders();
}
// ---------------------------
// Este constructor hace lo mismo que el DefinePLayerPlaying, pero solo es requerida esa funcion
// ---------------------------

Board::Board(short int numPlayers)
{
    // Color colorsP[4] = {BLUE, RED, GREEN, YELLOW};
    // this->numPlayers = numPlayers;

    // for (int i = 0; i < numPlayers; i++)
    // {
    //     Player temp = {numPlayers, colorsP[i]};
        

    //     // ---------------------
    //     // En vez de definir las skins por if, creamos una funcion en la cual dependiendo el indice le asigna una
    //     // skin
    //     temp.DefineSkins(i+1);

    //     // if(i == 0){
    //     //     temp.DefineSkin();
    //     // }else if(i==1){
    //     //     temp.DefineSkin2();
    //     // }else if(i==2){
    //     //     temp.DefineSkin3();
    //     // }else if(i == 3){
    //     //     temp.DefineSkin4();
    //     // }
    //     // ---------------------

    //     players.push_back(temp);
    // }

    // InitSnakes();
    // InitLadders();
}

void Board::DefinePlayersPlaying(short int numPlayers){
    Color colorsP[4] = {BLUE, RED, GREEN, YELLOW}; // Colores de jugadores
    this->numPlayers = numPlayers;

    for (int i = 0; i < numPlayers; i++)
    {
        Player temp = {numPlayers, colorsP[i]}; // Inicializa jugador
        
        // ---------------------
        // En vez de definir las skins por if, creamos una funcion en la cual dependiendo el indice le asigna una
        //  skin

        temp.DefineSkins(i+1);
        // if(i == 0){
        //     temp.DefineSkin();
        // }else if(i==1){
        //     temp.DefineSkin2();
        // }else if(i==2){
        //     temp.DefineSkin3();
        // }else if(i == 3){
        //     temp.DefineSkin4();
        // }

        players.push_back(temp);
    }

    InitSnakes();
    InitLadders();
}

void Board::DrawBoard(int PosX, int PosY)
{
    // Ciclo para recorrer filas
    for (int i = 0; i < 10; i++)
    {
        // Dibujamos los jugadores
        for (int k = 0; k < numPlayers; k++)
        {
             // Variable que almacena el rectangulo del jugador actual
            Rectangle ActColision = players[k].BoxPlayer(PosX, PosY, CELL_SIZE, PADDING);

            // Serpientes
            // El limite sera el numero maximo de serpientes y escaleras, pero no sumadas
            for (int x = 0; x < 4; x++) 
            {
                Rectangle Tail = snakes[x].DrawSnake(PosX, PosY, CELL_SIZE, PADDING);

                if (CheckCollisionRecs(ActColision, Tail)) // Verifica colision entre jugador y serpiente
                    players[k].position = snakes[x].header;
            }
            
            // Escaleras
            for (int x = 0; x < 5; x++) 
            {
                Rectangle Base = ladders[x].DrawLadder(PosX, PosY, CELL_SIZE, PADDING);

                if (CheckCollisionRecs(ActColision, Base)) // Verifica colision entre jugador y escalera
                    players[k].position = ladders[x].destiny;
            }
            players[k].DrawPlayer(PosX, PosY, CELL_SIZE, PADDING);
        }
        /*
            Podria separar los draw, osea del snake y ladder, un ciclo para dibujar estas primero, luego otra para obtener
            su posicion actual para las colisiones, asi evitaria que se sobrepongan encima de los jugadores, PERO
            si se supone que usaremos el mapa con las serpientes pues mejor que la funcion drawnsake solo
            retorne la posicion actual
        */
    }
}

// ---------------------------
// Esta funcion ya no es necesaria
// ---------------------------

// void Board::MovePlayer()
// {
//     players[0].Move(2);
//     players[1].Move(1);
//     players[2].Move(3);
//     players[3].Move(4);
// }

void Board::MovePlayer(int NumPlayer, int boxes)
{
    players[NumPlayer].Move(boxes);
}

Vector2 Board:: GetActualPlayerPosition(int NumPlayer){
    return players[NumPlayer].position;
}

// --------------------- Textures --------------------- //

Texture2D Board::GetPlayerSkin(int NumPlayer){
    return this->players[NumPlayer].skin;
}

void Board::DefineSnakeTexture()
{
    for (int i = 0; i < 4; i++)
        this->snakes[i].DefineSkin();
}

void Board::FreeSnakeTexture()
{
    for (int i = 0; i < 2; i++)
        this->snakes[i].FreeSkin();
}

void Board::InitSnakes()
{
    Snake temp = {{4, 4}, {1, 0}}; // Primero cola luego cabeza
    snakes.push_back(temp);
    
    temp = {{8, 3}, {7, 2}};
    snakes.push_back(temp);
    
    temp = {{1, 8}, {1, 7}};
    snakes.push_back(temp);
    
    temp = {{8, 9}, {5, 6}};
    snakes.push_back(temp);
}

void Board::InitLadders()
{
    Ladder temp = {{7, 0},{8, 1}}; // Primero base luego destino
    ladders.push_back(temp);
    
    temp = {{5, 2},{6, 4}}; 
    ladders.push_back(temp);
    
    temp = {{2, 4},{1, 5}}; 
    ladders.push_back(temp);
    
    temp = {{4, 6},{3, 8}}; 
    ladders.push_back(temp);
     
    temp = {{8, 5}, {9, 8}}; 
    ladders.push_back(temp);
    
}

