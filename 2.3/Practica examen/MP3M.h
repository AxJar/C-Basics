//
// Created by Axel JM on 08/06/2021.
//

#ifndef EXAMEN_MP3M_H
#define EXAMEN_MP3M_H
#include "Multimedio.h"
#include <iostream>

using namespace std;

class MP3M: public Multimedio{
public:
    MP3M();
    MP3M(string, int);
    int getSize();
    friend ostream& operator<<(ostream& os,const MP3M& m);
};


#endif //EXAMEN_MP3M_H
