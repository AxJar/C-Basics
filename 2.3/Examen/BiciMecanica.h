// Axel Jarquin Morga
// A01636324

#ifndef EXAMEN_BICIMECANICA_H
#define EXAMEN_BICIMECANICA_H
#include "Bici.h"
#include <iostream>

using namespace std;

class BiciMecanica:public Bici{
public:
    BiciMecanica();
    BiciMecanica(string,double);
    void acelera();
    friend ostream& operator<<(ostream& os, BiciMecanica& b);
};


#endif //EXAMEN_BICIMECANICA_H
