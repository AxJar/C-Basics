//A01639289 | Joel Isaias Solano Ocampo

#ifndef ENVIO_H
#define ENVIO_H
#include "compra.h"

class Envio {
    public:
        Envio();
        Envio(int, Compra, string, bool);
        int getId();
        void setID(int);
        Compra getCompra();
        void setCompra(Compra);
        string getFecha();
        void setFecha(string);
        int getEstatus();
        void setEstatus(int);
        void imprime();
    private:
        int idEnvio;
        Compra compra;
        string fecha;
        bool estatus;
};

//Constructor por default
Envio::Envio(){
    idEnvio = 0;
    fecha = "_";
    estatus = 0;
}

//Constructor con parámetros
Envio::Envio(int id, Compra com, string fec, bool est){
    idEnvio = id;
    compra = com;
    fecha = fec;
    estatus = est;
}

//Getters y Setters de los atributos
int Envio::getId(){
    return idEnvio;
}

void Envio::setID(int id){
    idEnvio = id;
}

Compra Envio::getCompra(){
    return compra;
}

void Envio::setCompra(Compra com){
    compra = com;
}

string Envio::getFecha(){
    return fecha;
}

void Envio::setFecha(string fec){
    fecha = fec;
}

int Envio::getEstatus(){
    return estatus;
}

void Envio::setEstatus(int est){
    estatus = est;
}

void Envio::imprime(){
    cout << "------------------------------------------------" << endl;
    cout << "ID Envio: " << idEnvio << endl;
    compra.imprime();
    cout << "Fecha: " << fecha << endl;
    cout << "Estatus " << estatus << endl;
    cout << "------------------------------------------------" << endl;
}
#endif //ENVIO_H