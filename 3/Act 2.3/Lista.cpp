//Inclusión de la Lista a Implementar
#include "Lista.h"

//Inclusión de las Librerías necesarias durante la Implementación
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <string>

//Ajuste a Estandar
using namespace std;

//Función que inicializa la lista, no recibe parámetro y no tiene valores de retorno
void lista::inicializa(){
    h=nullptr;
    t=nullptr;
}

//Función que comprueba su una lista está vacía, no recibe parámetro y retorna el valor booleano que indica si la lista está vacía o no
bool lista::vacia(){
    if (h==nullptr && t==nullptr)
        return true;
    else
        return false;
}

//Función que indica el tamanio de la lista, no recibe parámetros y retorno el valor entero de la lista en función de su conteo de 0 a N
int lista::tamanio(){
    int cont = 0;
    nodo *aux;
    aux=t;
    while(aux!=nullptr){
        cont++;
        aux=aux->sig;
    }
    return (cont-1);
}

//Función que muestra el contenido de una lista en su valor long int y su contenido string, no recibe parámetros y no tiene valor de retorno
void lista::mostrar(){
    nodo *aux;
    aux=h;
    while(aux!=nullptr){
        cout<<aux->data<<"-"<<aux->registro<<endl;
        aux=aux->sig;
    }
}

//Función que muestra el contenido de una lista en su contenido string, no recibe parámetros y no tiene valor de retorno
void lista::mostrarRegistro(){
    nodo *aux;
    aux=h;
    while(aux!=nullptr){
        cout<<aux->registro<<endl;
        aux=aux->sig;
    }
}

//Función que inserta al inicio de la lista un nodo, recibe el long int del nodo, su string y no tiene valor de retorno
void lista::insertarInicio(long int data, string registro){
    nodo *temp=new nodo;
    temp->data = data;
    temp->registro = registro;
    temp->sig=nullptr;
    temp->ant=nullptr;

    if (vacia()){
        h = temp;
        t = temp;
    }
    else {
        temp->sig=h;
        h->ant = temp;
        h = temp;
    }
}

//Función que inserta al final de la lista un nodo, recibe el long int del nodo, su string y no tiene valor de retorno
void lista::insertarFinal(long int data, string registro){
    nodo *temp=new nodo;
    temp->data = data;
    temp->registro = registro;
    temp->sig=nullptr;
    temp->ant=nullptr;

    if (vacia()){
        h = temp;
        t = temp;
    }
    else {
        t->sig = temp;
        temp->ant=t;
        t=temp;
    }
}

//Función que inserta a un índice N (0-N) de la lista un nodo, recibe el int que indica el índice, long int del nodo, su string y no tiene valor de retorno
void lista::insertarIndice(int index, long int data, string registro){
    nodo *temp=new nodo;
    temp->data = data;
    temp->registro = registro;
    temp->sig=nullptr;
    temp->ant=nullptr;

    if (vacia()){
        h = temp;
        t = temp;
    }
    else{
        if (index==0)
            insertarInicio(data,registro);
        else if (index==tamanio())
            insertarFinal(data,registro);
        else if (index>0 && index<tamanio()){
            nodo *aux;
            aux = h;
            for (int i=0; i<index; i++)
                aux = aux ->sig;
            aux->ant->sig=temp;
            temp->sig=aux;
            temp->ant=aux->ant;
            aux->ant=temp;
        }
        else{
            cout<<"ERROR"<<endl;
        }
    }
}

//Función que elimina un nodo de la lista, recibe como parámetro el entero que indica el índice en la lista y no tiene valor de retorno.
void lista::eliminar(int index){
    nodo *aux;

    if (index==0){
        aux=h;
        h=h->sig;
        delete(aux);

    }
    else if (index==tamanio()){
        aux=t;
        t = t->ant;
        delete(aux);
    }
    else if (index>0 && index<tamanio()){
        aux = h;
        for (int i=0; i<index; i++)
            aux = aux ->sig;
        aux->ant->sig=aux->sig;
        t->ant=aux->ant;
        delete(aux);
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

//Función que anula los nodos en la lista, no recibe parámetros y no tiene valor de retorno.
void lista::anular(){
    nodo *aux;
    while (h!=nullptr){
        aux=h;
        h=h->sig;
        delete(aux);
    }
}

//Función que retorna el valor lon int único del nodo, recibe como parámetro el índicode (0-N) y retorna el long int único del nodo.
long int lista::recuperaValor(int index){
    nodo *aux;
    aux = h;
    if (index>0 && index<tamanio()){
        for (int i=0; i<index; i++)
            aux = aux ->sig;
        return aux->data;
    }
    else{
        return -1;
    }
}

//Función que retorna el string de registro del nodo, recibe como parámetro el índicode (0-N) y retorna el string de registro del nodo.
string lista::recuperaRegistro(int index){
    nodo *aux;
    aux = h;
    if (index>0 && index<tamanio()){
        for (int i=0; i<index; i++)
            aux = aux ->sig;
        return aux->registro;
    }
    else{
        return " ";
    }
}

//Función que recibe que indica en qué indice se encuentra el nodo que contiene el lon int data solicitado, recibe como parámetro el long int a buscar y retorno el valor entorno del índice (0 a N)
int lista::localizaValor(long int data){
    int cont = 0;
    nodo *aux;
    aux = h;
    while(aux!=nullptr){
        if (aux->data==data)
            return cont;
        cont++;
        aux = aux ->sig;
    }
    return -1;
}

//Función que recibe que indica en qué indice se encuentra el nodo que contiene el string de registro solicitado, recibe como parámetro el string a buscar y retorno el valor entorno del índice (0 a N)
int lista::localizaRegistro(string registro){
    int cont = 0;
    nodo *aux;
    aux = h;
    while(aux!=nullptr){
        if (aux->registro==registro)
            return cont;
        cont++;
        aux = aux ->sig;
    }
    return -1;
}

// Función que ordena los elementos de la lista incluido su parte entera que es la utilizada para ordenar, y su parte string que es la que se refleja en pantalla. No recibe parametros y no tiene valores de retorno.
void lista::Ordena(){
    nodo *aux, *aux2;
    long int temp1;
    string temp2;
    aux = h;

    while(aux-> sig !=nullptr)
    {
        aux2 = aux->sig;
        while(aux2 != nullptr)
        {
            if(aux2->data < aux->data)
            {
                temp1 = aux->data; temp2 = aux->registro;
                aux->data = aux2->data; aux->registro = aux2->registro;
                aux2->data = temp1; aux2->registro = temp2;
            }
            aux2 = aux2->sig;
        }
        aux = aux->sig;
    }
}

///Función que guarda la lista en el orden en el que está hacia un archivo de texto, no recibe parámetros y no tiene valores de retorno
void lista::guardarBitacora(){
    string nombreArchivo="OrdenadaPorIps.txt";
    ofstream archivo;

    archivo.open(nombreArchivo.c_str(),fstream::out);

    nodo *aux;
    aux = h;
    while(aux!=nullptr){
        archivo<<aux->registro<<endl;
        aux = aux ->sig;
    }
    archivo.close();
}

//Función que almacena en un archivo de texto las IPS comprendidas entre dos valores únicos long int de IP, recibe como parámetro el inicio y fin de IPs en long int y no tiene valor de retorno
void lista::mostrarIPs(long int IP1, long int IP2){
    string nombreArchivo="BusquedaIPs.txt";
    ofstream archivo;
    archivo.open(nombreArchivo.c_str(),fstream::out);

    nodo *aux;
    aux = h;
    while(aux!=nullptr){
        if ((aux->data)>=IP1 && (aux->data)<=IP2){
            cout<<aux->registro<<endl;
            archivo<<aux->registro<<endl;
        }
        aux = aux ->sig;
    }
    archivo.close();
}