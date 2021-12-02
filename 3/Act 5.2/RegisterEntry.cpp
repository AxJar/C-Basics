//Inclusión de las Librerías y Cabeceras correspondientes.
#include "RegisterEntry.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>

//Ajuste a Estándar.
using namespace std;

// Constructor que recibe un string conteniendo un registro de formato MMM DD HH:MM:SS IP RAZONFALLO e inicializa los atributos de la clase RegisterEntry.
// Complejidad: O(1)
//Recibe como parámetro un string constante referenciado.
RegisterEntry::RegisterEntry(const string &textRegistry) {

    string month;
    string dateError;
    string day;
    string time;
    string ip;

    // Ciclo para dividir cada renglón por espacio.
    int stringPosition = 0;
    string message;
    istringstream ss(textRegistry);
    do {
        string word;
        string auxiliar;
        ss >> word;
        if (stringPosition == 0) {
            month = word;
            dateError = dateError + month;
        } else {
            if (stringPosition == 1) {
                day = word;
                dateError = dateError + " " + day;
            } else {
                if (stringPosition == 2) {
                    time = word;
                    dateError = dateError + " " + time;
                } else {
                    if (stringPosition == 3) {
                        setIpString(word);
                        dateError = dateError + " -";
                    } else {
                        if (stringPosition > 3) {
                            auxiliar = word;
                            dateError = dateError + " " + auxiliar;
                        }
                    }
                }
            }
        }
        stringPosition++;
    } while (ss);
    this->datesVector.emplace_back(dateToInt(month, day, time), dateError);
    this->accessCount = 1;
}

// Constructor default
// Complejidad: O(1)
//No recibe parámetros.
RegisterEntry::RegisterEntry() = default;

// Método para transformar los strings de la fecha a entero.
// Complejidad: O(1)
// Recibe como parámetros tres strings referenciados y retorna un valor entero.
int RegisterEntry::dateToInt(string &month, string &day, string &time) {
    int monthInt;
    int dayInt = stoi(day);
    int hourInt;
    int minuteInt;
    int secondsInt;

    static const map<string, int> monthsTable{
            {
                    {"Jan", 0},
                    {"Feb", 1},
                    {"Mar", 2},
                    {"Apr", 3},
                    {"May", 4},
                    {"Jun", 5},
                    {"Jul", 6},
                    {"Aug", 7},
                    {"Sep", 8},
                    {"Oct", 9},
                    {"Nov", 10},
                    {"Dec", 11}
            }
    };

    monthInt = monthsTable.find(month)->second;

    // Ciclo para separar el tiempo en horas, minutos y segundos.
    stringstream ss(time);
    string part;
    int stringPosition = 0;

    // Separar por .
    while (getline(ss, part, ':')) {
        if (stringPosition == 0) {
            hourInt = stoi(part);
        } else {
            if (stringPosition == 1) {
                minuteInt = stoi(part);
            } else {
                if (stringPosition == 2) {
                    secondsInt = stoi(part);
                }
            }
        }
        stringPosition++;
    }

    int tempDateInt = (monthInt * 31 * 24 * 60 * 60 + (dayInt * 24 * 60 * 60) + (hourInt * 60 * 60) + (minuteInt * 60) +
                       secondsInt);
    return tempDateInt;
}

// Método para actualizar el registro si un registro con la misma ip existe.
// Complejidad: O(n)
// Recibe como parámetros un string constante referenciado y un entero, no tiene valor de retorno.
void RegisterEntry::addRegister(const string &dateString, int dateInt) {
    this->datesVector.emplace_back(dateInt, dateString);
    sort(this->datesVector.begin(), this->datesVector.end());
    this->accessCount++;
}

// Getters y setters

// Complejidad: O(1)
// No recibe parámetros, y retorna un string constante referenciado.
const string &RegisterEntry::getTextRegistry() const {
    return textRegistry;
}

// Complejidad: O(1).
// Recibe un string constante referenciado y no tiene valor de retorno.
void RegisterEntry::setTextRegistry(const string &textRegistry) {
    RegisterEntry::textRegistry = textRegistry;
}

// Complejidad: O(1).
//No recibe parámetros y retorna un string constante referenciado.
const string &RegisterEntry::getIpString() const {
    return ipString;
}

// Complejidad: O(1).
// Recibe como parámetro un string constante refernciado y no tiene valor de retrono.
void RegisterEntry::setIpString(const string &ipString) {
    RegisterEntry::ipString = ipString;
}

// Complejidad: O(1).
// No recibe parámetros y retorna un valor entero.
int RegisterEntry::getAccessCount() const {
    return accessCount;
}

// Complejidad: O(1).
// No recibe parámetros y retorna un valor entero.
int RegisterEntry::getDateInt() {
    return this->datesVector[0].dateInt;
}

// Complejidad: O(1).
// No recibe parámetros y retorna un string.
string RegisterEntry::getDateString() {
    return this->datesVector[0].dateString;
}

// Salida de stream para desplegar él registre en formato de número de accesos y las fechas y razón de fallo en formato MMM DD HH:MM:SS - RAZONFALLO.
// Complejidad: O(n)
//Recibe como parámetros un ostream referenciado y un RegisterEntry constante referenciado, para retornar un ostream referenciado.
ostream &operator<<(ostream &os, const RegisterEntry &entry) {
    string listOfDates;
    for (auto it = begin(entry.datesVector); it != end(entry.datesVector); ++it) {
        listOfDates += "    " + it->dateString + "\n";
    }
    os << "\n" << " IP: " << entry.ipString << endl << " Número de accesos: " << entry.accessCount << endl
       << " Fechas: " << endl << listOfDates;
    return os;
}