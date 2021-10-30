#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

using namespace std;

class Tile{
    public:
        char type;
        int position;
        int penalty;
        int reward;
        friend ostream &operator+(ostream &os,Tile *turno);
};

#endif 