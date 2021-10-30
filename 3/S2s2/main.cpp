#include <iostream>
#include "Fibon.h"
#include "Prob1.h"

int main()
{
    int valor = 17;
    int guardador = 0;
    int* intptr = &guardador;
    //std::cout << "Valor a buscar\n";
    // std::cin >> valor;

    //std::cout << "Resultado Iterativo: " << Fibon::fibonacciIter(valor) << std::endl;
    //std::cout << "Resultado Recursivo: " << Fibon::fibonacciRecur(valor) << std::endl;

    std::cout << "Resultado Recursivo: " << Fibon::fibonacciRecurV2(valor,intptr) << std::endl;


    //std::cout << "Resultado prob: " << Prob1::proba(5,intptr) << std::endl;

    //std::cout << "Resultado prob: " << Prob1::probc(5, intptr) << std::endl;



}

