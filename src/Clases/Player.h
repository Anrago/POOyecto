#pragma once

#include "raylib.h"
#include <iostream>
#include <string.h>
#include <string>

#include <stdlib.h>
#include <time.h>


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
    // la fila para saber a que residuo dividirlo para las esquinas
    int fila;
    
    // Resudio por el que dividimos
    int res;

    int casilla;

    // ------------- Functions-------------- //
    Player();
    Player(int screenWidth, int screenHeight,Board map);
    void MovePosition(int x);
    Rectangle getCordCasilla(int x);
    int getFila(int x);
};

Player::Player(){
    this->back=false;
}

Player::Player(int screenWidth, int screenHeight,Board map){
    this->position={0,0};
    this->map=map;
    
    this->rec.x=map.startGrid.x;
    this->rec.y=map.startGrid.y;
    
    this->rec.width=map.GridSize;
    this->rec.height=map.GridSize;

    this->fila=1;
    this->res=10;
    this->casilla=1;
    
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
                this->fila++;
                this->back=true;
            }
            else{
                this->rec.y+= map.GridSize;
                this->fila++;
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

Rectangle Player::getCordCasilla(int x){
    Rectangle temp;
    temp.width=this->rec.width;
    temp.height=this->rec.height;
    temp.x=this->map.startGrid.x;
    temp.y=this->map.startGrid.y;

    int res=10;
    int casilla=1;
    int fila = 0;
    
    bool back=false;
    
    for(int i = 0 ; i < x ; i++){
        // Posicion en X
        // Posicion en Y
        if(int(casilla) % res == 0){
            // position.y+1;
            if(back==false){
                temp.y+= this->map.GridSize;
                fila++;
                back=true;
            }
            else{
                temp.y+= this->map.GridSize;
                fila++;
                back=false;
            }
        }
        else{
            if(back == false){
                temp.x += this->map.GridSize;
            }
            else{
                temp.x -= this->map.GridSize;   
            }

        }
        casilla++;
    }
    
    return temp;
}

int Player::getFila(int x){
    Rectangle temp;
    temp.width=this->rec.width;
    temp.height=this->rec.height;
    temp.x=this->map.startGrid.x;
    temp.y=this->map.startGrid.y;

    int res=10;
    int casilla=1;
    int fila = 1;
    
    bool back=false;
    
    for(int i = 1 ; i < x ; i++){
        // Posicion en X
        // Posicion en Y
        if(int(casilla) % res == 0){
            // position.y+1;
            if(back==false){
                temp.y+= this->map.GridSize;
                fila++;
                back=true;
            }
            else{
                temp.y+= this->map.GridSize;
                fila++;
                back=false;
            }
        }
        else{
            if(back == false){
                temp.x += this->map.GridSize;
            }
            else{
                temp.x -= this->map.GridSize;   
            }

        }
        casilla++;
    }
    
    return fila;
}
