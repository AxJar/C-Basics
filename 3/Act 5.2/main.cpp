//PROGRAMA: Programa que analiza un registro de IPs en un archivo TXT y utilizando hashing crea la correspondiente Tabla Hash con registros del dominio de la ip, conteniendo el numero de accesos y los detalles de determinada IP.
//PROGRAMADORES: León Emiliano García Pérez (A00573074), Leonardo Luna Flores (A01633305), Axel Jarquín Morga(A01636324).
//FECHA DE ENTREGA: 1 de Diciembre de 2021.

//Inclusión de las Librerías y Cabeceras correspondientes.
#include <iostream>
#include <vector>
#include <fstream>
#include "MyHashTable.h"
#include "RegisterEntry.h"

//Ajuste a Estándar.
using namespace std;

//Código Main Driver del Programa 
int main() {

    //INICIO DEL PROGRAMA

    // Nombre del archivo a leer que contiene los registros.
    string regFile = "bitacora.txt";

    // Inicializar la tabla de Ips.
    MyHashTable hashTableOfIps;

    // Abrir archivo de texto y añadir Ips con sus detalles a la tabla hash.
    try {
        ifstream is;
        is.open(regFile);
        if (!is) throw ios::failure("Cannot find file");
        string str;

        // Obtener información de cada linea e inicializar cada registerEntry.
        while (getline(is, str)) {
            // Inicializar objeto
            RegisterEntry currentReg(str);
            // Añadir Ips con sus detalles a la tabla hash
            hashTableOfIps.put(currentReg.getIpString(), currentReg);
        }
    } catch (const exception &error) {
        cerr << error.what() << endl;
    }

    // Ciclo para preguntar búsquedas hasta parar por el usuario.
    bool continueSearch = true;
    while (continueSearch) {
        string IpaBuscar;
        string input;
        bool correctInput = false;

        cout << "Escribe la IP que quieres consultar: " << endl;
        cin >> IpaBuscar;

        // Imprimir la información de la IP si coincide con algun elemento de la tabla
        cout << hashTableOfIps.get(IpaBuscar) << endl;

        // Ciclo para validar continuidad del programa.
        while (!correctInput) {
            cout << "¿Deseas buscar otra IP? Y/N: " << endl;
            cin >> input;

            if (input == "Y" || input == "y") {
                correctInput = true;
                continueSearch = true;
            } else if (input == "N" || input == "n") {
                correctInput = true;
                continueSearch = false;
            } else {
                correctInput = false;
            }
        }
    }

    //FIN DE PROGRAMA
    return 0;
}
