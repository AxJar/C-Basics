#include "Arreglo.h"
#include <iostream>

void Arreglo::busqueda(int valABuscar)
{
    int arregloDatos[10] = { 1,2,3,4,5,6,7,8,9,10 };  // O(1)

    for (int i = 0; i < 10; i++)   // O(n)   Siempre se toma la complejidad "mas alta"
    {
        if (arregloDatos[i] == valABuscar)   // O(1)
        {
            std::cout << "encontrado en el indice " << i <<std::endl;  // O(1)
        }
    }

}