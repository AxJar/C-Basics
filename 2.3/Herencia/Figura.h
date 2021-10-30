#ifndef FIGURA_H
#define FIGURA_H

class Figura{
    public:
        // virtual permite sobreescribir y que se ejecute
        virtual double perimetro() = 0;
        virtual double area() = 0;
        virtual double volumen() = 0;
        virtual void imprimir() = 0 ;
};

#endif

// Esta es una clase abstracta
