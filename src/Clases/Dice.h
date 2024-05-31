#pragma once

#include "Player.h"

class Dice{
public:
    int result;
    Dice();
    int DropDice();
};

Dice::Dice(){
    this->result=0;
}

int Dice::DropDice(){
    int n = (rand() % 6)+1;
    return n;
}


