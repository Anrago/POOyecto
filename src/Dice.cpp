#include "Dice.h"
#include <random>

Dice::Dice(short int MaxMumber)
{
    this->MaxNumber=MaxMumber;
}

int Dice::DropDice(){
    int c = rand()%MaxNumber + 1;
    return c;
}

// int Dice::Roll()
// {
//     return rand()%MaxNumber+1;
// }
