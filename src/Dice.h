#pragma once
#include <iostream>
#include <ctime>
class Dice
{
private:
    short int MaxNumber;
    int result;
public:
    Dice(short int MaxMumbre=6);
    int DropDice ();
    //int Roll() override ;
    
};
