// Axel Jarquin Morga
// A0163632
#include "BiciElectrica.h"
#include <iostream>

using namespace std;

BiciElectrica::BiciElectrica(string marca,double velocidad) {
    this ->marca = marca;
    this ->velocidad = velocidad;
}
BiciElectrica::BiciElectrica():Bici("Bici electrica",0.0) {};

void BiciElectrica::acelera() {
    if(velocidad == 0){
        velocidad = 1.0;
        velocidad = velocidad + (velocidad * 0.20);
    }
    else{
        velocidad = velocidad + (velocidad * 0.20);
    };

}

ostream& operator<<(ostream& os, BiciElectrica& b){
    double vkh = b.velocidad * 3.6;
    double mi = vkh / 1.6;
    os << "Bici electrica:"<<b.marca<<",Velocidad:"<<mi<<" mi/hr"<<endl;
    return os;
}
