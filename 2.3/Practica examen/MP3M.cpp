//
// Created by Axel JM on 08/06/2021.
//

#include <iostream>
#include "MP3M.h"

using namespace std;

MP3M ::MP3M(string nombre, int duracion) {
    this-> nombre = nombre;
    this->duracion = duracion;
};

MP3M::MP3M():Multimedio("Sin nombre",0){

};

int MP3M::getSize(){
    return this->duracion * 5;
}

ostream& operator<<(ostream& os,const MP3M& m) {
    int minutos = m.duracion / 60;
    int rest_seg = m.duracion - (minutos * 60);
    os << "Song:" << m.nombre<< ",Duration:" << minutos << " min,"<<rest_seg << " seg" ;
    return os;
}
