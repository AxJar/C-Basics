#include <iostream>
using namespace std;

int main(){
    float n1,n2;
    float suma,resta,mult,div;
    cout << "Dame el primer numero: ";
    cin >> n1;
    cout << "Dame el segundo numero: ";
    cin >> n2;
    suma = n1 + n2;
    resta = n1 - n2;
    mult = n1 * n2;
    div = n1 / n2;
    cout << "El resultado de sumar " << n1 << " + " << n2 << " es " << suma << endl;
    cout << "El resultado de restar " << n1 << " - " << n2 << " es " << resta << endl;
    cout << "El resultado de multiplicar " << n1 << " * " << n2 << " es " << mult << endl;
    cout << "El resultado de dividir " << n1 << " / " << n2 << " es " << div << endl;
}