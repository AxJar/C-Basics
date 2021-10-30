#ifndef CAJA_H
#define CAJA_H
#include "Rectangulo.h"

class Caja:public Rectangulo{
    private:
        double alto;
    public:
        Caja();
        Caja(double largo,double ancho, double alto);
        double volumen();
        double perimetro();
        double area();
        void imprimir();
        

};



#endif