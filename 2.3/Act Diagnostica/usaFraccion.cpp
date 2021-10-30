# include <iostream>
# include <string>
using namespace std;

#include "Fraccion.h"


// Constructor por default
Fraccion::Fraccion(){
    numerador = 0;
    denominador = 0;
}

// Constructor
Fraccion::Fraccion(int num, int den){
    numerador = num;
    denominador = den;
}

int Fraccion::getNum(){
    return numerador;
}

int Fraccion::getDen(){
    return denominador;
}

void Fraccion::setNum(int num){
    numerador = num;
}

void Fraccion::setDen(int den){
    denominador = den;
}

int reducirFraacciones(){
    
}

int Fraccion::sumaFracciones(){

}

int Fraccion::multiplicaFraciones(){
    
}


void Fraccion::imprime(){
    cout << numerador << "/" << denominador <<endl;
}


int main(){
    

    return 0;
}
