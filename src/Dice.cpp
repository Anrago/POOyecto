#include "Dice.h"
#include <random>

Dice::Dice(short int MaxMumber)
{
    this->MaxNumber=MaxMumber;
}

int Dice::DropDice(){
    int c = rand()%(this->MaxNumber - 0 + 1);
    std::cout<< c <<" "<<std::endl;
    return c;
}

// int Dice::Roll()
// {
//     return rand()%MaxNumber+1;
// }
