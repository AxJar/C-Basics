#pragma once
#include <iostream>
using namespace std;

template<class T> // Clase reutilizable que crea los vagones
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
                        last = NULL;
                    }

                    //Función que añade un nuevo elemento a la lista, recibe como parámetro el Dato, y no tiene valor de retorno.
                    void create(T data) { // Compljeidad computacional O(1)
                        if (!first) {
                            // List vacía
                            first = new node<T>;
                            first->data = data;
                            first->next = NULL;
                            last = first;
                        }
                        else {
                            // Lista no vacía
                            if (last == first) {
                                // Lista con un elemento
                                last = new node<T>;
                                last->data = data;
                                last->next = NULL;
                                first->next = last;
                            }
                            else {
                                // Lista con más de un elemento
                                node<T>* insdata = new node<T>;
                                insdata->data = data;
                                insdata->next = NULL;
                                last->next = insdata;
                                last = insdata;
                            }
                        }
                    }

                    // Función que ecibe como parametro el indice en donde se encuentra el elemento, tiene como salida el elemento que se encuentra en dicho indice.
                    T read(int index) { // Compljeidad computacional 0(n)
                        if (index == 0) {
                            // Toma el elemento del primer
                            return this->first->data;
                        }
                        else {
                            // Toma el índice del elemento
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
                            // Cambia el primer elemento
                            this->first->data=dato;
                        }
                        else {
                            // Cambia el elemento del índice
                            node<T>* curr = this->first;
                            for (int i = 0; i < index; ++i) {
                                curr = curr->next;
                            }
                            curr->data=dato;
                        }
                    }

                    //Función que elimina un elemento de la lista, ajustando los indices de todos los elementos, recibe el indice a eliminar, sin retorno.
                    //Referencia: https://youtu.be/Y0n86K43GO4 "Linked List in C/C++ - Delete a node at nth position"
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


