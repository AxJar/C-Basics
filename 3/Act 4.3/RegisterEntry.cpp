//Inclusión de las Librerías y Clases
#include "RegisterEntry.h"
#include <iostream>
#include <sstream>

//Ajuste a estandar
using namespace std;

//Constructor la lista de registros, recibe como parámetro un string constante referenciado
RegisterEntry::RegisterEntry(const string &textRegistry) { //Complejidad Computacional: O(1)

    //Ciclo para separar un string por espacio
    int stringPosition = 0;
    istringstream ss(textRegistry);
    do {
        string word;
        ss >> word;
        if (stringPosition == 3) {
            setIp(ipReader(word));
            stringstream ssPort(word);
            string partPort;
            bool ipWoPort = false;

            while (getline(ssPort, partPort, ':')) {
                if (!ipWoPort) {
                    setStringIp(partPort);
                    ipWoPort = true;
                }
            }

        }
        stringPosition++;
    } while (ss);
}

//Constructor defawult
RegisterEntry::RegisterEntry() = default; //Complejidad Computacional: O(1)

//Función para leer la ip, recibe como parámetro un string constante referenciado y retorno un unsigned long long
unsigned long long RegisterEntry::ipReader(const string &stringIp) { //Complejidad Computacional: O(n)
    stringstream ss(stringIp);
    string part;
    unsigned long long ip;
    unsigned long long firstPosIp;
    unsigned long long secondPosIp;
    unsigned long long thirdPosIp;
    unsigned long long fourthPosIp;

    // Cyclo para separar la ip por sus respectivos separadores
    int ipPos = 0;

    // El separador es un punto en este caso
    while (getline(ss, part, '.')) {
        if (ipPos == 0) {
            firstPosIp = stoi(part);
        } else {
            if (ipPos == 1) {
                secondPosIp = stoi(part);
            } else {
                if (ipPos == 2) {
                    thirdPosIp = stoi(part);
                } else {
                    if (ipPos == 3) {
                        // Sepearar por dos puntos para el puerto
                        stringstream ssPort(part);
                        string partPort;
                        int ipPortPos = 0;

                        while (getline(ssPort, partPort, ':')) {
                            if (ipPortPos == 0) {
                                fourthPosIp = stoi(partPort);
                            }
                            ipPortPos++;
                        }
                    }
                }
            }
        }
        ipPos++;
    }

    // Operacion para convertir cada ip en su respectiva posicion a su decimal equivalente
    ip = ((((firstPosIp * 1000 + secondPosIp) * 1000 + thirdPosIp) * 1000) + fourthPosIp);
    return ip;
}

//Función para recibir la ip no recibe parámetros, va hacia constante, retorna un unsigned long long
unsigned long long int RegisterEntry::getIp() const { //Complejidad Computacional: O(1)
    return ip;
}

//Función para definir la ip recibe un unsigned long long y no tiene valor de retorno.
void RegisterEntry::setIp(unsigned long long int ip) { //Complejidad Computacional: O(1)
    RegisterEntry::ip = ip;
}

//Función para recibir la ip no recibe parámetros, va hacia constante, retorna una constante
const string &RegisterEntry::getStringIp() const { //Complejidad Computacional: O(1)
    return stringIp;
}

//Función para definir la ip en forma de string, recibe un string constante refernciado y no tiene valor de retorno.
void RegisterEntry::setStringIp(const string &stringIp) { //Complejidad Computacional: O(1)
    RegisterEntry::stringIp = stringIp;
}

//Función escribir la ip en el archivo recibe un ostream refernciado y una register entry constante referenciado y retorna un ostream
ostream &operator<<(ostream &os, const RegisterEntry &entry) { //Complejidad Computacional: O(1)
    os << entry.stringIp;
    return os;
}