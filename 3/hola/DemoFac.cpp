//
// Created by Axel JM on 12/08/2021.
//

#include "DemoFac.h"

int DemoFac::factIt(int val) {
    // aqui pondre un error

    int resultado = 1;

    for (int i = val; i >= 2 ; i--) {
        resultado *= i;
    }
    return resultado;
}

int DemoFac::factRec(int val) {

    // debe existir un caso base , el cual me permita terminar // si no existe esta condicion de terminacion
    if (val = 0)
        return 1;
    else
        return val * factRec(val - 1);
}