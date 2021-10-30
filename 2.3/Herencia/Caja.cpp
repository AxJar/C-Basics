#include <iostream>
#include "Caja.h"

using namespace std;


Caja::Caja(double largo,double ancho, double alto):Rectangulo(largo, ancho){
    this-> alto = alto;
};

Caja::Caja():Caja(5.0,7.0,10.0){};

double Caja::perimetro(){
    return 8.0 * this->alto + 2.0 * this->ancho + 4.0 * this-> largo;
};

double Caja::area(){
    return 2.0 * (Rectangulo::area() + this-> ancho * this-> alto + this-> largo * this-> alto);
};

double Caja::volumen(){
    return Rectangulo::area() * this->alto;
};

void Caja::imprimir(){
    cout << "Caja de largo "<< this ->largo << " , de ancho "<<this -> ancho << " y de largo " << this -> alto << endl;
};