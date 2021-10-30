//
// Created by Axel JM on 05/06/2021.
//

#ifndef SOBRECARGA_DE_OPERADORES_POLAR_H
#define SOBRECARGA_DE_OPERADORES_POLAR_H
#include "Rectangular.h"
#include <iostream>

using namespace std;

class Polar{
    private:
        double r;
        double a;

    public:
        Polar();
        Polar(double,double);
        double getR();
        double getA();
        Rectangular toRectangular();
        Polar operator*(Polar cp);
        Polar operator/(Polar cp);
        friend ostream& operator<<(ostream& os,const Polar& cp);

};
#endif //SOBRECARGA_DE_OPERADORES_POLAR_H
