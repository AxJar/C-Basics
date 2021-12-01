//Inclusión de Librerías y Cabeceras
#include "MyHashTable.h"
#include <cmath>

//Ajuste a estándar
using namespace std;

// Constructor default de la tabla hash con un tamaño de arreglo de 15000.
// Complejidad: O(1)
MyHashTable::MyHashTable() {
    this->size = 0;
    this->sizeA = 15000;
    this->tabla = new MyLinkedList[this->sizeA];
}

// Destructor de la tabla hash
// Complejidad: O(n)
MyHashTable::~MyHashTable() {
    delete[] this->tabla;
}

// Método para checar si la tabla hash está vacía.
// Complejidad O(1)
bool MyHashTable::isEmpty() const {
    return this->size == 0;
}

// Método para rehacer la tabla si el factor de carga supera 0.75.
// Complejidad: O(n)
void MyHashTable::rehashing() {
    MyLinkedList *tempTabla = this->tabla;
    this->sizeA = ((this->sizeA * 2) + 1);
    this->size = 0;
    this->tabla = new MyLinkedList[this->sizeA];
    for (int i = 0; i < (this->sizeA - 1) / 2; i++) {
        while (!tempTabla[i].isEmpty()) {
            auto head = tempTabla[i].getAt(0);
            put(head->key, head->reg);
            tempTabla[i].removeFirst();
        }
    }
    delete[] tempTabla;
}


// Método para calcular la posicion de una llave en la tabla.
// Complejidad: O(1)
int MyHashTable::getPos(const string &key) const {
    size_t hashT = hash<string>{}(key);
    int hashCode = static_cast<int>(hashT);
    return abs(hashCode) % this->sizeA;
}

// Método para añadir un objeto de tipo RegisterEntry a la tabla hash si la ip ya existe, se añade junto con la fecha y la cantidad de veces que se repite.
// Complejidad Peor caso O(n), con factor de load mayor a .75, si no se vuelve O(1).
void MyHashTable::put(const string &key, RegisterEntry &reg) {
    double cargaFactor = size * 1.0 / sizeA;
    if (cargaFactor > 0.75) {
        rehashing();
        put(key, reg);
    } else {
        int pos = getPos(key);
        if (!this->tabla[pos].isRepeated(key)) {
            this->tabla[pos].insertFirst(key, reg);
            this->size++;
        } else {
            this->tabla[pos].getAt(key)->addRegister(reg.getDateString(), reg.getDateInt());
        }
    }
}

// Método para obtener el RegisterEntry de una IP.
// Complejidad: O(1)
RegisterEntry MyHashTable::get(const string &key) {
    int pos = getPos(key);
    MyLinkedList *lista = &this->tabla[pos];
    return *lista->getAt(key);
}

// Método para remover una ip y su RegisterEntry.
// Complejidad O(n)
void MyHashTable::remove(const string &key) {
    int pos = getPos(key);
    this->tabla[pos].removeAt(key);
}