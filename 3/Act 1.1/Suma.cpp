//
// Created by Axel JM on 18/08/2021.
//

#include "Suma.h"

int Suma::sumaA(int val) {

    int resultado = 0; // O(1)
    for (int i = 1; i <=val ; ++i) {  // O(n)
        resultado += i;  // O(n)
    }
    return resultado;
}

int Suma::sumaR(int val) {
    if (val == 0)  // O(1)
        return 0;
    else
        return val + Suma::sumaR(val - 1); // O(n)
}

int Suma::sumaD(int val) {

    return  (val*(val + 1)) / 2;   // O(n)
}
