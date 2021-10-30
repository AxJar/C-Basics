//
// Created by Axel JM on 30/09/2021.
//
#ifndef PILAS_Y__Y_FILAS_TRIANGULO_H
#define PILAS_Y__Y_FILAS_TRIANGULO_H
#include <string>

using namespace std;

class Triangulo {
private:
    float base;
    float altura;
    float area;
public:
    Triangulo();
    Triangulo(float b, float h) {
        base = b;
        altura = h;
    };

    //sobrecargar el operador <<
    friend ostream& operator << (ostream& os,Triangulo& t){
        os << "(" << t.base << ", "<< t.altura << ")";
        return os;
    }
};



#endif //PILAS_Y__Y_FILAS_TRIANGULO_H
