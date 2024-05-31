#pragma once

#include "Player.h"

class Ladders{
public:
    Vector2 start,finish;

    Ladders(Vector2 start, Vector2 finish);
};

Ladders::Ladders(Vector2 start, Vector2 finish){
    this->start=start;
    this->finish=finish;
}