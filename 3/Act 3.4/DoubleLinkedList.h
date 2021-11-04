
#ifndef ACT_3_4_DOUBLELINKEDLIST_H
#define ACT_3_4_DOUBLELINKEDLIST_H


//Inclusión de las Librerías y Clases
#include <iostream>
#include "RegisterEntry.h"
#include <utility>
#include <fstream>

//Ajuste a Estandar
using namespace std;

//Definición de Estrcutura para los Nodos.
struct MyNodoLL {
    RegisterEntry reg;
    MyNodoLL *next;
    MyNodoLL *prev;

    MyNodoLL(const string &regString, MyNodoLL *next, MyNodoLL *prev) : reg(regString) {
        this->next = next;
        this->prev = prev;
    }

    explicit MyNodoLL(const string &regString) : MyNodoLL(regString, nullptr, nullptr) {}
};

class DoubleLinkedList {
private:
    MyNodoLL *head;
    MyNodoLL *tail;
    int size;

    //Función auxiliar para ordenamiento por Merge en dos Listas Ligadas, recibe como parámetros dos nodos apuntados y retorna un nodo apuntado.
    MyNodoLL *merge(MyNodoLL *first, MyNodoLL *second); //Complejidad Computacional O(nlogn).

    //Función que realiza el split de una Lista Ligada en Dos, recibe como parámetro un nodo apuntado y retorna un nodo apuntado.
    MyNodoLL *split(MyNodoLL *head); //Complejidad Computacional O(nlogn).

    //Función que implementa el ordenamiento por Merge, recibe como parámetro	un nodo apuntado y retorna un nodo apuntado.
    MyNodoLL *mergeSort(MyNodoLL *head); //Complejidad Computacional O(nlogn).

public:

    //Constructor de la Clase que define a la cabeza y a la cola como apuntadores nulos y establece el tamaño en 0.
    DoubleLinkedList(); //Complejidad Computacional O(1).

    //Función que inserta un nodo al principio, recibe como parámetro un string constante referenciado y no tiene valor de retorno.
    void insertFirst(const string &regString); //Complejidad Computacional O(1).

    //Función que inserta un nodo al final, recibe como parámetro un string constante referenciado y no tiene valor de retorno.
    void insertLast(const string &regString); //Complejidad Computacional O(1).

    // Operador de salida de para mostrar todos los elementos de la lista en el terminal
    friend ostream &operator<<(ostream &os, const DoubleLinkedList &list) { //Complejidad Computacional O(n)
        MyNodoLL *current = list.head;

        while (current->next != nullptr) {
            os << current->reg << endl;
            current = current->next;
        }
        os << endl;
        return os;
    }

    //Función Getter que retorna la cabeza, no tiene paránetros y retorno el nodo cabeza apuntado.
    MyNodoLL *getHead() const; //Complejidad Computacional O(1).

    //Función Destructor de la Clase.
    virtual ~DoubleLinkedList(); //Complejidad Computacional O(n).

    //Función que calcula la Cabeza cuando se modifica por Ordenamiento Merge, no recibe parámetros y no tiene valor de retorno.
    void calculateHead(); //Complejidad Computacional O(n).

    //Función que implementa en una ssimple función al ordenamiento por Merge, no recibe parámetros y no tiene valor de retorno.
    void mergeSort(); //Complejidad Computacional O(nlogn).

    //Función que almacena en un Archivo las IPs Ordenadas, recibe como parámetro una Lista Doblemente Ligada referenciadda y constante y no tiene valor de retorno.
    void bitacoraOrdenada(const DoubleLinkedList &list); //Complejidad Computacional O(n).
};

#endif //ACT_3_4_DOUBLELINKEDLIST_H
