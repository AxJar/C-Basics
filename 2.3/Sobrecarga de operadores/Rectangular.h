//
// Created by Axel JM on 05/06/2021.
//

#ifndef SOBRECARGA_DE_OPERADORES_RECTANGULAR_H
#define SOBRECARGA_DE_OPERADORES_RECTANGULAR_H
#include <iostream>
using namespace std;

class Polar;
class Rectangular{
    private:
        double x,y;
    public:
        Rectangular();
        Rectangular(double,double);
        double getX();
        double getY();
        Polar toPolar();
        //Rectangular suma(Rectangular cr);
        Rectangular operator+(Rectangular cr);//Es lo mismo que la funcion suma de arriba pero se utiliza ahora el operador suma mediante la sobrecarga
        Rectangular operator+(Rectangular cp);
        Rectangular operator-(Rectangular cr);
        Rectangular operator*(Rectangular cr);
        Rectangular operator/(Rectangular cr);

        friend ostream& operator<<(ostream& os,const Rectangular& cr);

};
#endif //SOBRECARGA_DE_OPERADORES_RECTANGULAR_H
