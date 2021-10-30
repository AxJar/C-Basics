//
// Created by Axel JM on 13/10/2021.
//

#ifndef INC_2_3_LISTA_H
#define INC_2_3_LISTA_H

//Inclusión de Librerías en la Clase
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <string>

//Ajuste a estandar
using namespace std;

//Definición de la Clase Nodo
class nodo{

public:
    nodo *sig;
    nodo *ant;
    long int data;
    string registro;

    friend class lista;

private:
};

//Definición de la Clase Lista
class lista{

    nodo *h;
    nodo *t;

private:


public:
    void inicializa();
    bool vacia();
    int tamanio();
    void mostrar();

    void mostrarRegistro();

    void insertarInicio(long int, string);
    void insertarFinal(long int, string);
    void insertarIndice(int, long int, string);
    void eliminar(int);
    void anular();
    long int recuperaValor(int);
    string recuperaRegistro(int);
    int localizaValor(long int);
    int localizaRegistro(string);
    void Ordena();
    void guardarBitacora();
    void mostrarIPs(long int, long int);
};

#endif //INC_2_3_LISTA_H
