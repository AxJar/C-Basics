//
// Created by Axel JM on 07/06/2021.
//

#include "Turn.h"

Turn::Turn(int turn,int player,int pTile, int p, string tile) {
    this->turn =turn;
    this->player =player;
    this->pTile =pTile;
    this->p =p;
    this->tile =tile;
}

ostream &operator<<(ostream &os,Turn t){
    os <<t.turn<<" "<<t.player<<" "<<t.p<<" "<<t.tile<<" "<<endl;
    return os;
}