#include <iostream>
using namespace std;

// Programa que convierte de pulgadas a centímetros
// 1 pulgada = 2.54 cm

int main(){
    double distPulg,distCm;
    cout << "Cantidad de pulgadas: " << endl;
    cin >> distPulg;
    distCm = distPulg * 2.54;
    cout << "La distancia en centimetros es " << distCm << endl;
    return 0;
}