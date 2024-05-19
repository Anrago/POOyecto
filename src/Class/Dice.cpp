#include "Dice.h"

Dice::Dice(short int MaxMumber)
{
    this->MaxNumber=MaxMumber;
}

int Dice::Roll()
{
    srand(time(NULL));
    return rand()%100+1;
}
