// Clase hecha por Axel Jarquin Morga // A01636324

#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente{
    public:
        Cliente();
        Cliente(int, string, string);
        int getidCliente() const;
        string getNombre() const;
        string getDireccion() const;
        void setidCliente(int);
        void setNombre(string);
        void setDireccion(string);
        void imprime();
    private:
        int idCliente;
        string nombre;
        string direccion;
};

Cliente::Cliente(){
    idCliente = 0;
    nombre = "_";
    direccion = "_";
}

Cliente::Cliente(int id,string nom, string dir){
    idCliente = id;
    nombre = nom;
    direccion = dir;
}

int Cliente::getidCliente() const{
    return idCliente;
}

string Cliente::getNombre() const{
    return nombre;
}

string Cliente::getDireccion() const{
    return direccion;
}

void Cliente::setidCliente(int id){
    idCliente = id;
}

void Cliente::setNombre(string nom){
    nombre = nom;
}

void Cliente::setDireccion(string dir){
    direccion = dir;
}

void Cliente::imprime(){
    cout << "------------------------------------------------" << endl;
    cout << "Nombre Cliente: " << nombre << endl;
    cout << "Direccion Cliente: " << direccion << endl;
    cout << "------------------------------------------------" << endl;
}

#endif 