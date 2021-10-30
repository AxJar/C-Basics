//
// Created by Axel JM on 07/06/2021.
//

#ifndef TAREA_2_TURN_H
#define TAREA_2_TURN_H
#include <iostream>

using namespace std;

class Turn {
public:
    string tile;
    int turn,player,pTile,p;
    Turn( int turn,int player,int pTile, int p, string tile);
    friend ostream &operator<<(ostream &os,Turn *t);

};


#endif //TAREA_2_TURN_H
