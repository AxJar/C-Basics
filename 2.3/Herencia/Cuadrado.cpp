#include <iostream>
#include "Cuadrado.h"

using namespace std;

Cuadrado::Cuadrado(double lado):Rectangulo(lado,lado){};

Cuadrado::Cuadrado():Cuadrado(5.0){};

void Cuadrado::imprimir(){
    cout << "Cuadrado de lado "<< this ->largo << endl;
};

void Cuadrado::saludar(){
    cout << "Buenas tardes" << endl;
};