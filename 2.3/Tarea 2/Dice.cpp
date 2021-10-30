#include "Dice.h"

Dice::Dice(){
    srand(time(0));
}


int Dice::GetDice(){
    return  (rand() % 6) + 1;
}