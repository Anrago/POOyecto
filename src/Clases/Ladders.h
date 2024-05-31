#pragma once

#include "Player.h"

class Ladders{
public:
    Rectangle start,finall;

    Ladders(Rectangle start, Rectangle finish);
    void Up(Player p1)
};

Ladders::Ladders(Rectangle start, Rectangle finish){
    this->start=start;
    this->finish=finish;
}