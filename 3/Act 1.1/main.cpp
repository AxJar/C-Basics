#include <iostream>
#include "Suma.h"

using namespace std;

int main() {
/*    int n;
    cout << "Introduce el numero a sumar: " <<endl;    // O(1)
    cin >> n;  // O(1)
    cout << "Suma alterativa = " << Suma::sumaA(n) << endl;   // O(1)
    cout << "Suma recursiva = " << Suma::sumaR(n) << endl;   // O(1)
    cout << "Suma directa = " << Suma::sumaD(n) << endl;   // O(1)*/

    cout << "Suma alterativa = " << Suma::sumaA(10) << endl;   // O(1)
    cout << "Suma recursiva = " << Suma::sumaR(10) << endl;   // O(1)
    cout << "Suma directa = " << Suma::sumaD(10) << endl;   // O(1)
    cout << endl;

    cout << "Suma alterativa = " << Suma::sumaA(50) << endl;   // O(1)
    cout << "Suma recursiva = " << Suma::sumaR(50) << endl;   // O(1)
    cout << "Suma directa = " << Suma::sumaD(50) << endl;   // O(1)
    cout << endl;

    cout << "Suma alterativa = " << Suma::sumaA(100) << endl;   // O(1)
    cout << "Suma recursiva = " << Suma::sumaR(100) << endl;   // O(1)
    cout << "Suma directa = " << Suma::sumaD(100) << endl;   // O(1)
    cout << endl;

    cout << "Suma alterativa = " << Suma::sumaA(200) << endl;   // O(1)
    cout << "Suma recursiva = " << Suma::sumaR(200) << endl;   // O(1)
    cout << "Suma directa = " << Suma::sumaD(200) << endl;   // O(1)

    return 0;
}
