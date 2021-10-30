//
//  starter.cpp
//  claseTaxiTutoring
//
//  Created by Yolanda Martinez on 2/21/19.
//  Copyright © 2019 com.itesm. All rights reserved.
//


#include <iostream>
using namespace std;

#include "Taxi.h"

int main() {
    char opcion;
    
    cin >> opcion;
    
    switch (opcion) {
        case 'a':  // constructor default y métodos de acceso
        {
            // Crea un objeto de la clase Taxi con el constructor default
            // muestra el id del Taxi (obtenlo del objeto creado), termina con endl
            cout <<      << endl;
            // muestra el nombre del responsable, un espacio y el celular del responsable, al final endl
            cout <<     << " " <<    << endl;
            break;
        }
        case 'b':  // constructor con parámetros y métodos de acceso
        {
            // Crea un objeto Persona con el constructor con parámetros y ponle nombre = "Jorge", numCel = "24681209"
            // Crea un objeto Taxi con id = 123 y responsable = el objeto persona que acabas de definir
            // muestra el id del Taxi (obtenlo del objeto creado), termina con endl
            cout <<      << endl;
            // muestra el nombre del responsable, un espacio y el celular del responsable, al final endl
            cout <<     << " " <<    << endl;
            break;
        }
        case 'c':  // métodos de modificación y métodos de acceso
        {
             // Crea un objeto Taxi con el constructor default
            // Crea un objeto Persona con el constructor con parámetros y ponle de valores nombre = "Martha" y numCel = "54637654"
            // Modifica el objeto Taxi poniendo como id = 987 y como responsable al objeto persona que acabas de crear (Martha)
            // muestra el id del Taxi (obtenlo del objeto creado), termina con endl
            cout <<      << endl;
            // muestra el nombre del responsable, un espacio y el celular del responsable, al final endl
            cout <<     << " " <<    << endl;
            break;
        }
    }
    return 0;
}

