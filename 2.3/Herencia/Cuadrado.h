#ifndef CUADRADO_H
#define CUADRADO_H
#include "Rectangulo.h"

class Cuadrado:public Rectangulo{
    public:
        Cuadrado();
        Cuadrado(double lado);
        void imprimir();
        void saludar();
};


#endif
