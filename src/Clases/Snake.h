#pragma once

#include "Player.h"

class Snake{
public:
    Vector2 start,final;

    Snake(Vector2 start, Vector2 final);
};

Snake::Snake(Vector2 start, Vector2 final){
    this->start=start;
    this->final=final;
}




