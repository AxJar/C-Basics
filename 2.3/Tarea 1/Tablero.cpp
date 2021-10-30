#include "Tablero.h"

Tablero::Tablero(){
    turn = 0;
};

char Tablero::getTile(int nTile){
    return board[nTile];
};

void Tablero::setTurn(int t){
    turn = t;
};

void Tablero::Logic(){
    int snakes = 0;
    int ladders = 0;
    int n;
    char s;
    board[0] = 'N';
    for(int i = 1; i < 29; i++){
        n = rand() % 3;
        if(n == 1 && snakes <= 2){
            board[i] = 'S';
            snakes++;
        };
        else{
            if (n == 1 && ladders <= 2){
                board[i] = 'L';
                ladders++;
            };
            else{
                board[i] = 'N';
            };
        };
    };
    board[29] = 'N';
    return;
};
