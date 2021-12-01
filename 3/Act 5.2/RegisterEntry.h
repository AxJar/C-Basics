#ifndef ACT_5_2_REGISTERENTRY_H
#define ACT_5_2_REGISTERENTRY_H

//Inclusión de las Librerías y Cabeceras correspondientes.
#include <iostream>
#include <string>
#include <utility>
#include <vector>

//Ajuste a Estándar.
using namespace std;

// Definición de una estructura que contiene un par de atributos, siendo la fecha en entero y en string.
struct datePair {
    int dateInt;
    string dateString;

    // Constructor de la estructura, asigna valores.
    // Complejidad: O(n)
    datePair(int dateInt, string dateString) : dateInt(dateInt), dateString(move(dateString)) {};

    // Sobrecarga de operador para comparar la fecha utilizado el entero de la estructura.
    // Complejidad: O(1)
    bool operator<(const datePair &str) const {
        return (dateInt < str.dateInt);
    }
};

class RegisterEntry {
private:

    // String que contiene todo el registro
    string textRegistry;

    // String que contiene la ip
    string ipString;

    // Número de veces que se repite la ip
    int accessCount;

    // Vector de estructura datePair que contiene la fecha tanto en entero como en string
    vector<datePair> datesVector;

public:

    // Constructor que recibe un string conteniendo un registro de formato MMM DD HH:MM:SS IP RAZONFALLO e inicializa los atributos de la clase RegisterEntry.
    // Complejidad: O(1)
    explicit RegisterEntry(const string &textRegistry);

    // Constructor default
    // Complejidad: O(1)
    RegisterEntry();

    // Método para transformar los strings de la fecha a entero.
    // Complejidad: O(1)
    static int dateToInt(string &month, string &day, string &time);

    // Método para actualizar el registro si un registro con la misma ip existe.
    // Complejidad: O(n)
    void addRegister(const string &dateString, int dateInt);

    // Getters y setters
    // Complexity: O(1)
    const string &getTextRegistry() const;

    void setTextRegistry(const string &textRegistry);

    const string &getIpString() const;

    void setIpString(const string &ipString);

    int getAccessCount() const;

    int getDateInt();

    string getDateString();

    // Salida de stream para desplegar él registre en formato de número de accesos y las fechas y razón de fallo en formato MMM DD HH:MM:SS - RAZONFALLO.
    // Complejidad: O(n)
    friend ostream &operator<<(ostream &os, const RegisterEntry &entry);
};

#endif //ACT_5_2_REGISTERENTRY_H
