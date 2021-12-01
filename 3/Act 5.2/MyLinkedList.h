
#ifndef ACT_5_2_MYLINKEDLIST_H
#define ACT_5_2_MYLINKEDLIST_H

//Inclusión de las Librerías y Cabeceras correspondientes.
#include <iostream>
#include <string>
#include <utility>
#include "RegisterEntry.h"

//Ajuste a Estándar
using namespace std;

// Estructura del nodo.
struct MyNodoLL {
    string key;
    RegisterEntry reg;
    MyNodoLL *next;

    // Constructor del nodo
    // Complejidad: O(1)
    MyNodoLL(string key, RegisterEntry reg, MyNodoLL *next) {
        this->key = move(key);
        this->reg = move(reg);
        this->next = next;
    }

    // Constructor del nodo que contiene un puntero nulo.
    // Complejidad: O(1)
    MyNodoLL(string key, RegisterEntry reg) : MyNodoLL(move(key), move(reg), nullptr) {}
};

class MyLinkedList {
private:
    // Puntero al nodo to the cabeza
    MyNodoLL *head;

    // Puntero al nodo cola
    MyNodoLL *tail;

    // Numero de elementos en la lista
    int size;

public:
    // Constructor de una lista ligada que inicializa cabeza y cola como punteros nulos y de tamaño 0.
    // Complejidad: O(1)
    MyLinkedList();

    // Destructor de la lista ligada
    // Complejidad: O(n)
    ~MyLinkedList();

    // Método para obtener el número de elementos en la lista ligada.
    // Complejidad: O(1)
    int length() const;

    // Método para checar si la lista ligada esta vacía.
    // Complejidad: O(1)
    bool isEmpty() const;

    // Método para obtener el número de elementos de la lista ligada.
    // Complejidad: O(1)
    MyNodoLL *getAt(int pos);

    // Método para obtener el puntero del RegisterEntry de la llave de una IP.
    // Complejidad: O(1)
    RegisterEntry *getAt(const string &key);

    // Método para comprobar si una llave ya está en la lista ligada.
    // Complejidad: 0(n) en el peor caso y 0(1) en el mejor caso.
    bool isRepeated(const string &key);

    // Método para crear un nodo con la llave ip y su RegisterEntry e insertarlo en el primer lugar de la lista ligada.
    // Complejidad: O(1)
    void insertFirst(string key, RegisterEntry reg);

    // Método para remover el primer nodo de la lista ligada.
    // Complejidad: O(1)
    void removeFirst();

    // Método para remover el ultimo nodo de la lista ligada.
    // Complejidad: O(1)
    void removeLast();

    // Método para remover un nodo en determinada posicion de la lista ligada.
    // Complejidad: O(n)
    void removeAt(int pos);

    // Método para remover un nodo de la lista ligada acorde a la llave IP recibida.
    // Complejidad: O(n)
    void removeAt(const string &key);

    // Método para remover el nodo de la lista ligada que contiene la llave IP recibida.
    // Regresa un ostream con la información de cada nodo de la lista.
    friend ostream &operator<<(ostream &os, const MyLinkedList &ll) {
        MyNodoLL *current = ll.head;
        for (int i = 0; i < ll.size; i++) {
            os << "[" << current->key << ",";
            os << current->reg << "]";
            current = current->next;
        }
        return os;
    }
};

#endif //ACT_5_2_MYLINKEDLIST_H
