//Inclusión de las Librerías y Cabeceras correspondientes.
#include "MyLinkedList.h"
#include <string>
#include <utility>

//Ajuste a Estándar.
using namespace std;

// Constructor de una lista ligada que inicializa cabeza y cola como punteros nulos y de tamaño 0.
// Complejidad: O(1)
MyLinkedList::MyLinkedList() {
    this->head = this->tail = nullptr;
    this->size = 0;
}

// Destructor de la lista ligada.
// Complejidad: O(n)
MyLinkedList::~MyLinkedList() {
    MyNodoLL *next;
    while (head != nullptr) {
        next = head->next;
        delete head;
        head = next;
    }
}

// Método para obtener el número de elementos en la lista ligada.
// Complejidad: O(1)
int MyLinkedList::length() const {
    return this->size;
}

// Método para checar si la lista ligada esta vacía.
// Complejidad: O(1)
bool MyLinkedList::isEmpty() const {
    return this->size == 0;
}

// Método para obtener el puntero del RegisterEntry de la llave de una IP.
// Complejidad: O(1)
RegisterEntry *MyLinkedList::getAt(const string &key) {
    MyNodoLL *current = this->head;
    for (int i = 0; i < this->size; i++) {
        if (current->key == key) {
            return &current->reg;
        }
        current = current->next;
    }
    throw invalid_argument("No se encontró " + key + " en la lista");
}

// Método para comprobar si una llave ya esta en la lista ligada.
// Complejidad: 0(n) en el peor caso y 0(1) en el mejor caso.
bool MyLinkedList::isRepeated(const string &key) {
    MyNodoLL *current = this->head;
    for (int i = 0; i < this->size; i++) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Método para obtener el número de elementos de la lista ligada con los a
// Complejidad: O(1)
MyNodoLL *MyLinkedList::getAt(int pos) {
    if (pos >= 0) {
        MyNodoLL *current = this->head;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        return current;
    } else {
        throw invalid_argument("No se puede insertar en la posición " + to_string(pos) + " en una lista de tamaño " + to_string(this->size));
    }
}

// Método para crear un nodo con la llave ip y su RegisterEntry e insertarlo en el primer lugar de la lista ligada.
// Complejidad: O(1)
void MyLinkedList::insertFirst(string key, RegisterEntry reg) {
    this->head = new MyNodoLL(move(key), move(reg), this->head);
    if (this->tail == nullptr) {
        this->tail = this->head;
    }
    this->size++;
}

// Método para remover el primer nodo de la lista ligada.
// Complejidad: O(1)
void MyLinkedList::removeFirst() {
    if (this->size > 0) {
        MyNodoLL *tmp = this->head;
        this->head = this->head->next;
        this->size--;
        if (this->size == 0) {
            this->tail = nullptr;
        }
        delete tmp;
    } else {
        throw invalid_argument("No se puede borrar el inicio de una lista vacía");
    }
}

// Método para remover el ultimo nodo de la lista ligada.
// Complejidad: O(1)
void MyLinkedList::removeLast() {
    if (this->size <= 1) {
        removeFirst();
    } else {
        MyNodoLL *current = this->head;
        for (int i = 0; i < this->size - 2; i++) {
            current = current->next;
        }
        this->tail = current;
        delete current->next;
        this->tail->next = nullptr;
        this->size--;
    }
}

// Método para remover un nodo en determinada posicion de la lista ligada.
// Complejidad: O(n)
void MyLinkedList::removeAt(int pos) {
    if (pos == 0) {
        removeFirst();
    } else {
        MyNodoLL *current = this->head;
        for (int i = 0; i < pos - 1; i++) {
            current = current->next;
        }
        MyNodoLL *tmp = current->next;
        current->next = current->next->next;
        if (pos == this->size - 1) {
            this->tail = current;
        }
        this->size--;
        delete tmp;
    }
}

// Método para remover un nodo de la lista ligada acorde a la llave IP recibida.
// Complejidad: O(n)
void MyLinkedList::removeAt(const string &key) {
    MyNodoLL *current = this->head;
    for (int i = 0; i < this->size; i++) {
        if (current->key == key) {
            removeAt(i);
        }
        current = current->next;
    }
}
