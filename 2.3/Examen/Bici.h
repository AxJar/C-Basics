// Axel Jarquin Morga
// A01636324

#ifndef EXAMEN_BICI_H
#define EXAMEN_BICI_H
#include <string>
#include <iostream>

using namespace std;

class Bici {
protected:
    string marca;
    double velocidad;

public:
    Bici(string marca, double velocidad){
        this -> marca = marca;
        this-> velocidad = velocidad;
    }
    Bici():Bici("BICI POO",0.0){};
    virtual void acelera() = 0;

};


#endif //EXAMEN_BICI_H
