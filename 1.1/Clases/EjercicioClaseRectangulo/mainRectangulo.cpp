#include <iostream>
#include "Rectangulo.h" // Todas las clases van entre comillas
using namespace std;

int main(){
    Rectangulo r1;
    Rectangulo r2(3.5, 2.8);
    cout << r1.perimetro() << "Es el area del rectangulo 1" << endl;
    return 0;
}