#ifndef MYGAME_H
#define MYGAME_H

#include "Tablero.h"
using namespace std;

class MyGame{
    private:
        int turn = 0;
        int points;
        Dice rDice;
        char s;
        char tileValue;
        int t1 = 1;
        int t2 = 1;
        Tablero go;
    public:
        void start();

#endif

