#ifndef RECTANGULO_H
#define RECTANGULO_H
#include "Figura.h"

//para decir que hereda son los 2 puntos y el public
class Rectangulo:public Figura{
    protected:
        double largo;
        double ancho;
    public:
        Rectangulo();
        Rectangulo(double largo, double ancho);
        double perimetro();
        double area();
        double volumen();
        void imprimir();
};

#endif