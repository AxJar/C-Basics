#include <iostream>
#include "Rectangulo.h"
using namespace std;

Rectangulo::Rectangulo(double largo,double ancho){
    this -> largo = largo;
    this -> ancho = ancho;
};
Rectangulo::Rectangulo():Rectangulo(10.0,5.0){    // Constructor por default de la clase rectangulo , manda a llamar al constructor con parametros , pasandole los valores siguientes
    
};

double Rectangulo::perimetro(){
    return this -> largo * 2.0 + this -> ancho * 2.0;
};

double Rectangulo::area(){
    return this -> largo * this -> ancho;
};

double Rectangulo::volumen(){
    return 0.0;
};


void Rectangulo::imprimir(){
    cout << "Rectangulo de largo "<< this ->largo << " y de ancho "<<this -> ancho << endl;
};