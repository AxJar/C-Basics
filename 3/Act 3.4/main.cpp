//PROGRAMA: Programa que abre un registro de IPs, analiza el contenido de dicho archivo TXT y muestra las IPs más repetidas dentro del registro.
//PROGRAMADORES: León Emiliano García Pérez (A00573074), Leonardo Luna Flores (A01633305), Axel Jarquín Morga(A01636324).
//FECHA DE ENTREGA: OCT 30, 2021.

//Inclusión de las Librerías y Clases
#include <iostream>
#include <fstream>
#include "DoubleLinkedList.h"
#include "MyBST.h"

using namespace std;

int main() {
    //INICIO DEL PROGRAMA

    // IPs Ordenadas por Búsqueda en Archivo Origen - Sobre este se realiza la búsqueda de repeticiones
    string archivo = "BusquedaPorIps.txt"; //ARCHIVO RESULTANTE DE LA ACTIVIDAD INTEGRADORA ANTERIOR
    DoubleLinkedList listRegistries;

    // Abre el archivo de texto y crea una lista de direcciones IP sin puertos
    try {
        ifstream is;
        is.open(archivo);
        if (!is) throw ios::failure("No se puede encontrar el archivo");
        string str;
        // Obtiene cada línea del archivo y crea una lista doblemente ligada
        while (getline(is, str)) {
            // El string de cada registro se pasa como argumento a la lista ligada, el string se pasa al constructor dentro de la lista doblemente ligada para inicializar los objetos de RegisterEntry
            listRegistries.insertLast(str);
        }

    } catch (const exception &error) {
        cerr << error.what() << endl;
    }

    // Ordena la lista de IPs
    listRegistries.mergeSort();

    // Guarda la lista de IPs ordenada
    listRegistries.bitacoraOrdenada(listRegistries);

    // Crea un BST a partir de la lista de IPs ordenadas
    MyBST ipTree;

    string archivoOrdenado = "bitacoraOrdenada.txt";

    // Abre el archivo de texto y almacena el número de repeticiones de cada IP con su ip correspondiente, como un string, en el BST
    try {
        ifstream is;
        is.open(archivoOrdenado);
        if (!is) throw ios::failure("Cannot find file");
        string ipString;
        string pastIpString;
        // Contador de repeticiones
        int counter = 0;
        // Ciclo para crear el BST de IPs
        while (getline(is, ipString)) {
            if (ipString == pastIpString || pastIpString.empty()) {
                counter++;
            } else {
                // Agrega la  IP con el número de repeticiones como key
                ipTree.insert(counter, pastIpString);
                counter = 0;
            }
            pastIpString = ipString;
        }

    } catch (const exception &error) {
        cerr << error.what() << endl;
    }
    cout<<endl;

    cout<<"Analizando el archivo: "<< archivo<< " ,se encuentra que se tienen:"<<endl;

    cout<<endl;

    // Muestra el número de repeticiones en orden descendente.
    cout<<"IPs repetidas: "<<endl;
    cout<<endl;
    ipTree.reverseInorder();

    // Muestra las cinco IPs que mas se repiten

    cout << endl << "Top 5 IPs con mas repeticiones: " << endl;
    cout<<endl;
    ipTree.topFive();
    cout<<endl;
    //FIN DEL PROGRAMA
    return 0;
}