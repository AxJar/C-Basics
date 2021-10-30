//Inclusión de las Librerías y Clases
#include "DoubleLinkedList.h"
#include <utility>
#include <fstream>

using namespace std;

//Constructor de la Clase que define a la cabeza y a la cola como apuntadores nulos y establece el tamaño en 0.
DoubleLinkedList::DoubleLinkedList() { //Complejidad Computacional O(1)
  this->head = this->tail = nullptr;
  this->size = 0;
}

//Función que inserta un nodo al principio, recibe como parámetro un string constante referenciado y no tiene valor de retorno.
void DoubleLinkedList::insertFirst(const string &regString) { //Complejidad Computacional O(1)
  this->head = new MyNodoLL(regString, this->head, nullptr);

  if (this->size == 0) {
    this->tail = this->head;
  } else {
    this->head->next->prev = this->head;
  }

  this->size++;
}

//Función que inserta un nodo al final, recibe como parámetro un string constante referenciado y no tiene valor de retorno.
void DoubleLinkedList::insertLast(const string &regString) { //Complejidad Computacional O(1)
  if (size == 0) {
    insertFirst(regString);
  }
  
  auto *nvo = new MyNodoLL(regString, nullptr, this->tail);
  this->tail->next = nvo;
  this->tail = nvo;
  this->size++;
}

//Función Getter que retorna la cabeza, no tiene paránetros y retorno el nodo cabeza apuntado.
MyNodoLL *DoubleLinkedList::getHead() const { //Complejidad Computacional O(1)
  return head;
}

//Función Destructor de la Clase.
DoubleLinkedList::~DoubleLinkedList() { //Complejidad Computacional O(n)
    MyNodoLL *next;
    while (head != nullptr) {
        next = head->next;
        delete head;
        head = next;
    }
}

//Función que calcula la Cabeza cuando se modifica por Ordenamiento Merge, no recibe parámetros y no tiene valor de retorno.
void DoubleLinkedList::calculateHead() { //Complejidad Computacional O(n)
    while (this->head->prev != nullptr) {
        head = head->prev;
    }
}

//Función auxiliar para ordenamiento por Merge en dos Listas Ligadas, recibe como parámetros dos nodos apuntados y retorna un nodo apuntado.
MyNodoLL *DoubleLinkedList::merge(MyNodoLL *first, MyNodoLL *second) { //Complejidad Computacional O(nlogn)

    if (!first)
        return second;

    if (!second)
        return first;

    if (first->reg.getIp() < second->reg.getIp()) {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = nullptr;
        return first;
    } else {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}

//Función que realiza el split de una Lista Ligada en Dos, recibe como parámetro un nodo apuntado y retorna un nodo apuntado. 
MyNodoLL *DoubleLinkedList::split(MyNodoLL *head) { //Complejidad Computacional O(nlogn)
  MyNodoLL *fast = head, *slow = head;

  while (fast->next && fast->next->next) {
    fast = fast->next->next;
    slow = slow->next;
  }

  MyNodoLL *temp = slow->next;
  slow->next = nullptr;
  return temp;
}

//Función que implementa el ordenamiento por Merge, recibe como parámetro	un nodo apuntado y retorna un nodo apuntado.
MyNodoLL *DoubleLinkedList::mergeSort(MyNodoLL *head) { //Complejidad Computacional O(nlogn)
  if (!head || !head->next)
    return head;

  MyNodoLL *second = split(head);

  head = mergeSort(head);
  second = mergeSort(second);

  return merge(head, second);
}

//Función que implementa en una ssimple función al ordenamiento por Merge, no recibe parámetros y no tiene valor de retorno.
void DoubleLinkedList::mergeSort() { //Complejidad Computacional O(nlogn)
  mergeSort(this->head);
  calculateHead();
}

//Función que almacena en un Archivo las IPs Ordenadas, recibe como parámetro una Lista Doblemente Ligada referenciadda y constante y no tiene valor de retorno.
void DoubleLinkedList::bitacoraOrdenada(const DoubleLinkedList &list) { //Complejidad Computacional O(n)
  ofstream archivoBitacoraOrdenada;
  archivoBitacoraOrdenada.open("bitacoraOrdenada.txt", ios::out);
  archivoBitacoraOrdenada << list;
  archivoBitacoraOrdenada.close();
}