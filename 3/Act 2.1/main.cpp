/*
PROGRAMA: Programa que implementa una Simple Linked List
CREADORES: León Emiliano García Pérez (A00573074), Axel Jarquin Morga (A01636324), Leonardo Luna Flores (A01633305)
FECHA DE ENTREGA: Lunes 27 de Septiembre de 2021
*/

#include <iostream>
#include "FLinked.h"

using namespace std;

void espacio(){
    cout<<endl;
}

int main() {
    FLinked<int> list;

    list.create(1); //crea 1 en pos 0 ////Complejidad computacional O(1);
    list.create(23); // crea 23 en pos 1 ////Complejidad computacional O(1);
    list.create(3); //crea 3 en pos 2 ////Complejidad computacional O(1);

    cout << list.read(1) << std::endl; //imprimir 23 en pos 1 ////Complejidad computacional O(n);
    cout << list[1] << std::endl; //imprimir 23 en pos 1 ////Complejidad computacional O(n);

    list.del(1); // borra 23 en pos 1 ////Complejidad computacional O(n);

    //3 de pos 2 pasa a pos 1

    cout << list.read(1) << std::endl; //imprimir 3 pos 1  ////Complejidad computacional O(n);

    list.create(2); // se crea 2 pos 2 ////Complejidad computacional O(1);
    list.create(3); // se crea 3 pos 3  ////Complejidad computacional O(1);

    espacio();

    cout << list.read(0) << std::endl; // imprimir 1 en pos 0  ////Complejidad computacional O(n);
    cout << list.read(1) << std::endl; // imprimir 3 en pos 1  ////Complejidad computacional O(n);
    cout << list.read(2) << std::endl; // imprimir 2 en pos 2  ////Complejidad computacional O(n);
    cout << list.read(3) << std::endl; // imprimir 3 en pos 3  ////Complejidad computacional O(n);

    list.del(1); // borra 3 en pos 1  ////Complejidad computacional O(n);

    // 2 pasa pos 2 a pos 1
    // 3 pasa pos 3 a pos 2

    espacio();

    cout << list.read(0) << std::endl; // imprimir 1 en pos 0  ////Complejidad computacional O(n);
    cout << list.read(1) << std::endl; // imprimir 2 en pos 1  ////Complejidad computacional O(n);
    cout << list.read(2) << std::endl; // imprimir 3 en pos 2  ////Complejidad computacional O(n);

    list.update(2, 4); // El 2 se hace 4 en pos 1  ////Complejidad computacional O(n);

    espacio();

    cout << list.read(0) << std::endl; // imprimir 1 en pos 0  ////Complejidad computacional O(n);
    cout << list.read(1) << std::endl; // imprimir 2 en pos 1  ////Complejidad computacional O(n);
    cout << list.read(2) << std::endl; // imprimir 4 en pos 2  ////Complejidad computacional O(n);

    return 0;
}