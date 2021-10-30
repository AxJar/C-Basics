// Axel Jarquin Morga
// A01636324
#include "BiciMecanica.h"
#include <iostream>

using namespace std;

BiciMecanica::BiciMecanica(string marca,double velocidad) {
    this ->marca = marca;
    this ->velocidad = velocidad;
};

BiciMecanica::BiciMecanica():Bici("Bici mecanica",0.0) {};

void BiciMecanica::acelera() {
    velocidad = velocidad + 1.0;

}

ostream& operator<<(ostream& os, BiciMecanica& b){
    double vkh = b.velocidad * 3.6;
    os << "Bici mecanica:"<<b.marca<<",Velocidad:"<<vkh<<" kms/hr"<<endl;
    return os;
}