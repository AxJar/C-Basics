// Implementación de una tabla hash con un string que contiene la ip como llave y un registerEntry el cual es el resumen conteniendo la fecha hora y razon de fallo. Esta tabla utiliza listas ligadas para guardar dichos valores.
// La colisión se maneja por chaining

#ifndef ACT_5_2_MYHASHTABLE_H
#define ACT_5_2_MYHASHTABLE_H

//Inclusión de las Librerías y Cabeceras correspondientes.
#include <string>
#include "MyLinkedList.h"
#include "RegisterEntry.h"

class MyHashTable {
private:
    int size;//El número de elementos que tiene almacenado
    int sizeA; //El tamaño del arreglo
    MyLinkedList *tabla;

    // Método para rehacer la tabla si el factor de carga supera 0.75. No
    // Complejidad: O(n)
    //No recibe parámetros, no tiene valor de retorno.
    void rehashing();

    // Método para calcular la posicion de una llave en la tabla.
    // Complejidad: O(1)
    //Recibe como parámetros una constante string referenciada y retorna un valor entero.
    int getPos(const string &key) const;

public:
    // Constructor default con un tamaño de arreglo de 15000.
    // Complejidad: O(1)
    //No recibe parámetros.
    MyHashTable();

    // Destructor.
    // Complejidad: O(n)
    //No recibe parámetros.
    ~MyHashTable();

    // Método para checar si la tabla hash está vacía.
    // Complejidad O(1)
    //No recibe parámetros, retorna un valor booleano.
    bool isEmpty() const;

    // Método para añadir un objeto de tipo RegisterEntry a la tabla hash si la ip ya existe, se añade junto con la fecha y la cantidad de veces que se repite
    // Complejidad Peor caso O(n), con factor de load mayor a .75, si no se vuelve O(1).
    //Recibe como parámetros una string cosntante referenciada, y un RegisterEntry referenciado, no tiene valor de retorno.
    void put(const string &key, RegisterEntry &reg);

    // Método para obtener el RegisterEntry de una IP.
    // Complejidad: O(1)
    //Recibe como parámetr un string cosntante referenciado y retorna un RegisterEntry.
    RegisterEntry get(const string &key);

    // Método para remover una ip y su RegisterEntry.
    // Complejidad O(n)
    //Recibe como parámetro una constante string referenciada y no tiene valor de retorno.
    void remove(const string &key);
};

#endif //ACT_5_2_MYHASHTABLE_H
