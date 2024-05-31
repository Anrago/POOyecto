#pragma once

#include "raylib.h"
#include <iostream>
#include <string.h>
#include <string>

#include <stdlib.h>
#include <time.h>

#include "Snake.h"
#include "Ladders.h"
#include "Dice.h"
#include "Board.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

class Player{
public:
    // Posiocion inical,aunque la podemos eliminar
    Vector2 position;
    // Rectangulo o hitbox
    Rectangle rec;
    /*
    saber si tiene que regresar o avanzar
        false = hacia la derehca
        true = hacia la izquierda
    */
    bool back;
    Board map;
    // casilla en la que se encuentra actualmente
    int casilla;
    // la fila para saber a que residuo dividirlo para las esquinas
    int fila;
    int res;

    // ------------- Functions-------------- //
    Player(int screenWidth, int screenHeight,Board map);
    void MovePosition(int x);
};

Player::Player(int screenWidth, int screenHeight,Board map){
    this->position={0,0};
    this->map=map;
    
    this->rec.x=map.startGrid.x;
    this->rec.y=map.startGrid.y;
    
    this->rec.width=map.GridSize;
    this->rec.height=map.GridSize;

    this->casilla=1;
    this->res=10;
    
    this->back=false;
}

void Player::MovePosition(int x){

    for(int i = 0 ; i < x ; i++){
        // Posicion en X
        // Posicion en Y
        if(int(this->casilla) % this->res == 0){
            // position.y+1;
            if(this->back==false){
                this->rec.y+= map.GridSize;
                
                this->back=true;
            }
            else{
                this->rec.y+= map.GridSize;
                
                this->back=false;

            }
        }
        else{
            if(this->back == false){
                this->rec.x += map.GridSize;
            }
            else{
                this->rec.x -= map.GridSize;   
            }

        }

        this->casilla++;
        
    }
}
