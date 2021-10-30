// Clase hecha por Axel Jarquin Morga // A01636324

#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto{
    public:
        Producto();
        Producto(int, string, float);
        int getidProducto() const;
        string getNombre() const;
        float getPrecio() const;
        void setidProducto(int);
        void setNombre(string);
        void setPrecio(float);
        void imprime();
    private:
        int idProducto;
        string nombre;
        float precio;

};

Producto::Producto(){
    idProducto = 0;
    nombre = "_";
    precio = 0;
}

Producto::Producto(int id, string nom, float p){
    idProducto = id;
    nombre = nom;
    precio = p;
}

int Producto::getidProducto() const{
    return idProducto;
}

string Producto::getNombre() const{
    return nombre;
}

float Producto::getPrecio() const{
    return precio;
}

void Producto::setidProducto(int id){
    idProducto = id;
}

void Producto::setNombre(string nom){
    nombre = nom;
}

void Producto::setPrecio(float p){
    precio = p;
}

void Producto::imprime(){
    cout << "------------------------------------------------" << endl;
    cout << "ID Producto: " << idProducto << endl;
    cout << "Nombre Producto: " << nombre << endl;
    cout << "Precio Producto: " << precio << endl;
    cout << "------------------------------------------------" << endl;
}

#endif 