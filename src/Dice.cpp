#include "Dice.h"
#include <random>

Dice::Dice(short int maxNumber)
{
    this->maxNumber=maxNumber;
}

int Dice::DropDice(){
    int c = rand()%maxNumber + 1;
    return c;
}
