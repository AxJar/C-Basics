#ifndef TABLERO_H
#define TABLERO_H

#include "Dice.h"

class Tablero{
    private:
            char board[30];
            int turn;
    public:
        Tablero();
        char getTile(int nTile);
        void setTurn(int t);
        void Logic();
};

#endif