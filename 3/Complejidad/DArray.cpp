#include "DArray.h"
#include <array>
#include <iostream>
#include <algorithm>

void DArray::buscar(int val)
{

    //O(1)
    //O(n)
    //<tipo de data,numero de elementos>     asi se declara el arreglo
    std::array<int, 5> myArray = { 3, 4, 5, 6, 7 }; // O(1)
    //std::array myArray{ 9, 7, 5, 3, 1 };  //como nota, se pude ya hacer esto en versiones decompiladores de C++ 17
    std::array<int,5>::iterator iterador; // O(1)
	

    for (int i = 0; i < 5; i++) // O(n)
        {
        if (myArray[i] == val) // O(1)
            {
            std::cout << "encontrado en el indice " << i << std::endl; // O(1)
            }
        }


    iterador = std::find(std::begin(myArray), std::end(myArray), val); // O(n)

    {
        std::cout << val << " encontrado ";
		
    }

    // O(n)

}