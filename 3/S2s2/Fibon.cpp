#include "Fibon.h"
#include <iostream>

int Fibon::fibonacciIter(int val)
{
    int previous = 1;
    int current = 1;
    int next = 1;

    //int contador = 0;

    for (int i = 3; i <= val; ++i)

    {
        next = current + previous;
        previous = current;
        current = next;
        //contador++;
    }
    //std::cout << "veces: " << contador << std::endl;

    return next;
}

int Fibon::fibonacciRecur(int val)
{
    if ((val == 1) || (val == 0)) {
        return val;
    }
    else {
        //cada vez que se abra una rama incrementa en 1
        return(Fibon::fibonacciRecur(val - 1) + Fibon::fibonacciRecur(val - 2));
    }
}

int Fibon::fibonacciRecurV2(int val, int *contador)
{
    if ((val == 1) || (val == 0)) {
        *contador = *contador + 1;
        std::cout << "veces: " << *contador << std::endl;
        return val;
    }
    else {

        //*contador = *contador + 1;
        //std::cout << "veces: " << *contador << std::endl;

        return(Fibon::fibonacciRecurV2(val - 1, contador) + Fibon::fibonacciRecurV2(val - 2, contador));
    }

}
