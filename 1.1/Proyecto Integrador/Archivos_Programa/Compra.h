//A01639289 | Joel Isaias Solano Ocampo

#ifndef COMPRA_H
#define COMPRA_H
#include "Cliente.h"
#include "Producto.h"

class Compra {
    public:
        Compra();
        Compra(int, Cliente, Producto);
        int getId();
        void setID(int);
        Cliente getCliente();
        void setCliente(Cliente);
        Producto getProducto();
        void setProducto(Producto);
        void imprime();
    private:
        int idCompra;
        Cliente cliente;
        Producto producto;
};

//Constructor por default
Compra::Compra(){
    idCompra = 0;
}

//Constructor con parámetros
Compra::Compra(int id, Cliente cli, Producto pro){
    idCompra = id;
    cliente = cli;
    producto = pro;
}

//Getters y Setters de los atributos
int Compra::getId(){
    return idCompra;
}

void Compra::setID(int id){
    idCompra = id;
}

Cliente Compra::getCliente(){
    return cliente;
}

void Compra::setCliente(Cliente cli){
    cliente = cli;
}

Producto Compra::getProducto(){
    return producto;
}

void Compra::setProducto(Producto pro){
    producto = pro;
}

void Compra::imprime(){
    cout << "------------------------------------------------" << endl;
    cout << "Id Compra: " << idCompra << endl;
    cliente.imprime();
    producto.imprime();
    cout << "------------------------------------------------" << endl;
}

#endif //COMPRA_H