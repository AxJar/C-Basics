#ifndef DEPTO_H
#define DEPTO_H

class Depto {
public:
    Depto();
    Depto(int i, string n);
    int getIdDep()const;
    void setIdDep(int i);
    string getNombre()const;
    void setNombre(string n);
    void imprime();
private:
    int idDep;
    string nombre;
};

//Constructor por Default
Depto::Depto(){
    idDep = 0;
    nombre = '-';
}
//Constructor con parámetros
Depto::Depto(int i, string n){
    idDep = i;
    nombre = n;
}

//GETTERS Y SETTERS de los atributos
int Depto::getIdDep() const{
    return idDep;
}
void Depto::setIdDep(int i){
    idDep = i;
}
string Depto::getNombre() const{
    return nombre;
}
void Depto::setNombre(string n){
    nombre = n;
}

void Depto::imprime(){
    cout << idDep << " - " << nombre << endl;
}

#endif //DEPTO_H
