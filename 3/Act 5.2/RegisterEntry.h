// Clase que contiene una IP, la cantidad de veces que se repite, además de su fecha y razón de fallo. Formado de strings y enteros para poder mapear respectivamente y realizar operaciones numéricas y pasarlo de vuelta a strings.

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
    int accessCount{};

    // Vector de estructura datePair que contiene la fecha tanto en entero como en string
    vector<datePair> datesVector;

public:
    // Constructor que recibe un string conteniendo un registro de formato MMM DD HH:MM:SS IP RAZONFALLO e inicializa los atributos de la clase RegisterEntry.
    // Complejidad: O(1)
    //Recibe como parámetro un string constante referenciado.
    explicit RegisterEntry(const string &textRegistry);

    // Constructor default
    // Complejidad: O(1)
    //No recibe parámetros.
    RegisterEntry();

    // Método para transformar los strings de la fecha a entero.
    // Complejidad: O(1)
    // Recibe como parámetros tres strings referenciados y retorna un valor entero.
    static int dateToInt(string &month, string &day, string &time);

    // Método para actualizar el registro si un registro con la misma ip existe.
    // Complejidad: O(n)
    // Recibe como parámetros un string constante referenciado y un entero, no tiene valor de retorno.
    void addRegister(const string &dateString, int dateInt);

    // Getters y setters

    // Complexity: O(1)
    const string &getTextRegistry() const;

    // Complejidad: O(1).
    // Recibe un string constante referenciado y no tiene valor de retorno.
    void setTextRegistry(const string &textRegistry);

    // Complejidad: O(1).
    //No recibe parámetros y retorna un string constante referenciado.
    const string &getIpString() const;

    // Complejidad: O(1).
    // Recibe como parámetro un string constante referenciado y no tiene valor de retorno.
    void setIpString(const string &ipString);

    // Complejidad: O(1).
    // No recibe parámetros y retorna un valor entero.
    int getAccessCount() const;

    // Complejidad: O(1).
    // No recibe parámetros y retorna un valor entero.
    int getDateInt();

    // Complejidad: O(1).
    // No recibe parámetros y retorna un string.
    string getDateString();

    // Salida de stream para desplegar él registre en formato de número de accesos y las fechas y razón de fallo en formato MMM DD HH:MM:SS - RAZONFALLO.
    // Complejidad: O(n)
    //Recibe como parámetros un ostream referenciado y un RegisterEntry constante referenciado, para retornar un ostream referenciado.
    friend ostream &operator<<(ostream &os, const RegisterEntry &entry);
};

#endif //ACT_5_2_REGISTERENTRY_H
