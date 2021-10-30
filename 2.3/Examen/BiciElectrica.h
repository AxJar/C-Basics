// Axel Jarquin Morga
// A0163632

#ifndef EXAMEN_BICIELECTRICA_H
#define EXAMEN_BICIELECTRICA_H
#include "Bici.h"
#include "BiciMecanica.h"
#include <iostream>


class BiciElectrica: public Bici{
public:
    BiciElectrica();
    BiciElectrica(string,double);
    void acelera();
    friend ostream& operator<<(ostream& os, BiciElectrica& b);


};


#endif //EXAMEN_BICIELECTRICA_H
