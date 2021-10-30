#pragma once
#include <iostream>
using namespace std;

template<class T>
struct node {
    node<T>* next;
    T data;
};

template<class T>
class FLinked
{
public:
    node<T>* first;
    node<T>* last;
    FLinked<T>() {
        first = NULL;
    }
    //Función que añade un nuevo elemento a la lista, recibe como parámetro el Dato, y no tiene valor de retorno.
    void create(T data){ //Complejidad O(1)
        node<T>* nuevoNodo = new node<T>;
        nuevoNodo->data = data;
        nuevoNodo->next = NULL;
        if (first == NULL){
            first = nuevoNodo;
        }
        else{
            node<T>* temp = first;
            while(temp->next !=NULL){
                temp = temp->next;
            }
            temp->next= nuevoNodo;
        }
    }

    // Función que recibe como parametro el indice en donde se encuentra el elemento, tiene como salida el elemento que se encuentra en dicho indice
    T read(int index) { // Compljeidad computacional 0(n)
        if (index == 0) {
            // Get the first element
            return this->first->data;
        }
        else {
            // Get the index'th element
            node<T>* curr = this->first;
            for (int i = 0; i < index; ++i) {
                curr = curr->next;
            }
            return curr->data;
        }
    }

    //Sobrecarga de operador que implementa la función read.
    T operator[](int index) {
        return read(index);
    }

    // Funcion que actualiza el valor de un elemento en la lista, recibe como parametros el indice y el nuevo dato. No contiene retorno.
    void update(int index, T dato){ // Compljeidad computacional O(n)
        if (index == 0) {
            // Change the first element
            this->first->data=dato;
        }
        else {
            // Get the index'th element
            node<T>* curr = this->first;
            for (int i = 0; i < index; ++i) {
                curr = curr->next;
            }
            curr->data=dato;
        }
    }
    //Esta funcion inserta cualquier dato en cualquier posicion
    void insert(int index, T data){
        node<T>* temp1 = new node<T>;
        temp1->data = data;
        temp1->next = NULL;
        if (index == 1){
            temp1->next=first;
            first = temp1;
            return;
        }
        node<T>* temp2 = first;
        for (int i=0; i<index-2; i++){
            temp2=temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
    }

    //Función que elimina un elemento de la lista, ajustando los indices de todos los elementos, recibe el indice a eliminar, sin retorno.
    void del(int index){ // Compljeidad computacional O(n)
        node<T>* curr1 = this->first;

        if(index==0){
            first = curr1->next;
            curr1=NULL;
            return;
        }

        for(int i=0;i<index-1;i++)
            curr1= curr1->next;

        node<T>* curr2 = curr1->next;
        curr1->next=curr2->next;
        curr2=NULL;
    }
};