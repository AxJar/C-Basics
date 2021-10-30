//
// Created by Axel JM on 18/08/2021.
//

#include "NGauss.h"

int NGauss::sumaI(int var){

    int resultado = 0;
    for (int i = 1; i <=var ; ++i) {
        resultado += i;
    }
    return resultado;
}

int NGauss::sumaR(int val) {
    if (val == 1)
        return 0;
    else
        return val + NGauss::sumaR(val - 1);
}

int NGauss::sumaG(int val) {

    return  (val + 1) * (val / 2.0f);   // asi se convierte a flotante
}
