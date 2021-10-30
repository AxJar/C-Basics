# include <iostream>
# include <string>
using namespace std;

#include "CtaBanc.h"


CtaBanc::CtaBanc(){
    nombre = "";
    saldo = 0;
}

CtaBanc::CtaBanc(string nom, double sal){
    nombre = nom;
    saldo = sal;
}

string CtaBanc::getNombre(){
    return nombre;
}

double CtaBanc::getSaldo(){
    return saldo;
}
void CtaBanc::setNombre(string nom){
    nombre = nom;
}

void CtaBanc::setSaldo(double sal){
    saldo = sal;
}

void CtaBanc::deposita(double cant){
    saldo += cant;       // saldo = saldo + cant

}

bool CtaBanc::retira(double cant){
    if (cant > saldo){
        return false;
    }
    else{
        saldo -= cant;  // saldo = saldo - cant
        return true;
    }
}

void CtaBanc::muestra(){
    cout << "Nombre "<< nombre <<" saldo "<< saldo <<endl;
}


int main(){
    CtaBanc cliente;
    string nom;
    double saldoIni, cantidad;
    char opcion;

    cout << "Nombre del cliente ";
    cin >> nom;
    cout << "Saldo inicial de la cuenta ";
    cin >> saldoIni;
    cliente.setNombre(nom);
    cliente.setSaldo(saldoIni);
    do{
        cout << "a) depositar b) retirar c) consultar saldo d) terminar" << endl;
        cin >> opcion;
        switch(opcion) {
            case 'a': {
                cout << "Cantidad? ";
                cin >> cantidad;
                cliente.deposita(cantidad);
                break;
            }
            case 'b':{
                cout << "Cantidad? ";
                cin >> cantidad;
                bool respuesta = cliente.retira(cantidad);
                if (respuesta == false){
                    cout << "No hay saldo suficiente" << endl;
                }
                break;
            }
            case 'c': {
                cliente.muestra();
                break;
            }
        }
    } while (opcion != 'd');

    return 0;
};

