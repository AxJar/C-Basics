//PROGRAMA:Programa que abre una bitácora desordenada; la guarda ordenada, y permite al usuario ver los hechos entre dos días que él decida por medio de su interacción con la consola.
//PROGRAMADORES: León Emiliano García Pérez (A00573074), Leonardo Luna Flores (A01633305), Axel Jarquín Morga(A01636324).
//FECHA DE ENTREGA: OCT 13, 2021.

//Innclusión de librerías.
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include "Lista.h"

//Ajuste a estandar
using namespace std;

//Función que crea un espacio en la consola, no recibe parámetros y no tiene valores de retorno.
void espacio(){
    cout << endl;
}

//Función que tokeniza un string, recibe como parámetro el string y retorna un vector de strings. 
vector<string> espaciadoNuevo (string linea){
    vector<string> tokens;
    stringstream check(linea);

    string intermedio;

    while(getline(check,intermedio,' ')){
        tokens.push_back(intermedio);
    }

    string ip = tokens[3];
    vector<string> tokensIP;
    stringstream check2(ip);
    string intermedio2;

    while(getline(check2,intermedio2,'.')){
        tokensIP.push_back(intermedio2);
    }

    string puerto = tokensIP[3];
    vector<string> tokensPuerto;
    stringstream check3(puerto);
    string intermedio3;

    while(getline(check3,intermedio3,':')){
        tokensPuerto.push_back(intermedio3);
    }

    vector<string> tokensFinal;

    tokensFinal.push_back(tokens[0]); //Mes
    tokensFinal.push_back(tokens[1]); //Día
    tokensFinal.push_back(tokens[2]); //Hora Completa

    tokensFinal.push_back(tokensIP[0]); //Primer Elemento IP
    tokensFinal.push_back(tokensIP[1]); //Segundo Elemento IP
    tokensFinal.push_back(tokensIP[2]); //Tercer Elemento IP

    tokensFinal.push_back(tokensPuerto[0]); //Cuarto Elemento IP
    tokensFinal.push_back(tokensPuerto[1]); //Puerto

    for (int i = 4 ; i < tokens.size() ; i++) //Todo lo que falta
        tokensFinal.push_back(tokens[i]);

    return tokensFinal;
}

//Función que muestra el contenido de un vector de strings, recibe dicho vector y no tiene valores de retorno. 
void muestraVector(vector<string> vect){
    for (int i = 0; i <= 2; i++){
        cout << vect[i];
        cout << " ";
    }

    for (int i = 3; i <=5  ; i++){
        cout << stoi(vect[i]);
        cout << ".";
    }

    cout << stoi(vect[6]);
    cout << ":";

    for (int i = 7; i <vect.size(); i++){
        cout << vect[i];
        cout << " ";
    }
    cout<<endl;
}

//Función que almacena en una lista los datos que se puedan extraer de un vector de strings, recibe como parámetros el vector de strings y la lista que va a almacernar el contenido de dicho vector (mediante almacenar el string y en valor long int), no tiene valor de retorno.
void vector_a_lista(vector<string> vect, lista &listaips){
    long int suma = 0;
    int potencia = 3;

    for (int i = 3; i <=6  ; i++){
        suma+=stoi(vect[i])*pow(1000,potencia);
        potencia--;
    }

    string sumastr = to_string(suma);
    vect[3] = sumastr;
    vect[4] = ":";
    vect[5] = "";
    vect[6] = "";

    string registro = "";

    for (int i = 0; i <vect.size(); i++)
        registro = registro + vect[i] + " ";

    registro.erase(28,1);
    registro.erase(29,3);

    for (int i = 19; i<30; i+=4){
        registro.insert(i,1,'.');
    }
    //Se inserta el vector en una lista
    listaips.insertarInicio(suma,registro);

}

//Función que muestra el contenido de un vector de vectores de string, recibe como parámetro dicho vector de vectores de string y no tiene valor de retorno.
void muestraMatriz(vector<vector<string>> matriz){
    espacio();
    for (int i = 0 ; i < matriz.size(); i++)
        muestraVector(matriz[i]);
}


//Función que implementa el almacenamiento de una matriz hacia la lista requerida para el presente problema/programa, recibe como parámetro el vector de vectores string que es analizada y la lista que va a contener los datos a extraer del vector de vectores, no tiene valores de retorno.
void generaMatrizLista(vector<vector<string>> matriz, lista &listaips){
    for (int i = 0 ; i < matriz.size(); i++)
        vector_a_lista(matriz[i], listaips);
}


//Función que lee el un archivo de texto y lo almacena en un vector de vectores. 
vector<vector<string>> lecturaUltra(){

    fstream prueba("prueba.txt", ios::in);
    string line;

    vector<vector<string>> res;

    if (prueba.is_open()){
        getline(prueba,line);
        while(prueba){
            vector<string> vect = espaciadoNuevo(line);
            res.push_back(vect);
            getline(prueba,line);
        }
        prueba.close();
    }
    return res;
}

//Función que da un valor único long int a una IP, recibe el string con dicha IP y retorna un valor long int
long int convertirIP(string IP){
    vector<string> tokens;
    stringstream check(IP);

    string intermedio;

    while(getline(check,intermedio,'.')){
        tokens.push_back(intermedio);
    }

    string ip = tokens[3];
    vector<string> tokensIP;
    stringstream check2(ip);
    string intermedio2;

    while(getline(check2,intermedio2,':')){
        tokensIP.push_back(intermedio2);
    }

    long int suma = 0;
    int potencia = 3;

    for (int i = 0; i <=2  ; i++){
        suma+=stoi(tokens[i])*pow(1000,potencia);
        potencia--;
    }

    suma+=stoi(tokensIP[0]);

    return suma;
}

//Función que contiene el main, no recibe parámetros y no tiene valor de retorno
int main (){

    //INICIO DEL PROGRAMA

    lista listaips;
    listaips.inicializa();
    //Crear matriz.

    vector<vector<string>> matriz;

    //Leer archivo de texto.
    matriz = lecturaUltra();

    //Muestra matriz con IP elevada
    cout<<"Registros sin ordenar "<<endl;
    muestraMatriz(matriz);

    //Genera Matriz de listas
    generaMatrizLista(matriz, listaips);

    espacio();

    //Ordena las ips de la lista
    listaips.Ordena();

    //Guarda las ips de la lista ///////////////////////////////////////////////////////
    listaips.guardarBitacora(); ////////////////////////////////////////////////////////

    //Muestra las ips ordenadas
    cout<<"Registros ordenados por Ips"<<endl;

    espacio();

    listaips.mostrarRegistro();

    //Main inicial donde el usuario interactua ingresando fechas deseadas.
    espacio();

    cout << "INREGSE SU BUSQUEDA: "<<endl;

    string ipInicial;
    string ipFinal;

    cout << "Ingrese Ip Inicial formato ###.###.###.###:####"<<endl;
    cin >> ipInicial;
    cout << "Ingrese Ip final formato ###.###.###.###:####"<<endl;
    cin >> ipFinal;

    long int ipintok = convertirIP(ipInicial);
    long int ipfintok = convertirIP(ipFinal);

    espacio();
    cout << "Busquedas encontradas de rango " << ipInicial << " a " << ipFinal <<endl;
    listaips.mostrarIPs(ipintok, ipfintok);

    return 0;

    //FIN DE PROGRAMA
}