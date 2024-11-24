#pragma once
#include <iostream>
#include <ctime>
class Dice
{
private:
    short int maxNumber;
    int result;
public:
    Dice(short int maxNumber=6);
    int DropDice ();
};
