#pragma once

#include "Player.h"

class Snake{
public:
    Rectangle start,finall;

    Snake(Rectangle start, Rectangle finall);
    Player Down(Player p1);
};

Snake::Snake(Rectangle start, Rectangle finall){
    this->start=start;
    this->finall=finall;
}

Player Snake::Down(Player p1){
    Player temp;
    temp=p1;
    int x =0;
    
    while( x < 4){
        cout<< "Bajo"<<endl;
        if(int(temp.casilla) % temp.res == 0){
            if(temp.back==false){
                temp.rec.y-= p1.map.GridSize;
                temp.fila--;
                temp.back=true;
                
            }
            else{
                temp.rec.y-= p1.map.GridSize;
                temp.fila--;
                temp.back=false;

            }
            
            
        }
        else{
            if(temp.back == false){
                temp.rec.x -= p1.map.GridSize;
            }
            else{
                temp.rec.x += p1.map.GridSize;   
            }

        }
        temp.casilla--;
        x++;
    }
    cout<<temp.casilla<<endl;
    
    return temp;
}


