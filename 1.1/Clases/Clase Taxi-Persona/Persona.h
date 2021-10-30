#ifndef PERSONA_H
#define PERSONA_H
#include <string>

class Persona{
    public:
        Persona();
        Persona(std::string, std::string);
        std::string getNombre() const;
        void setNombre(std::string);
        std::string getCelular() const;
        void setCelular(std::string);
    private:
        std::string nombre;
        std::string celular;
};

Persona::Persona(){
    nombre = "N/A";
    celular = "N/A";
}

Persona::Persona(std::string nom,std::string cel){
    nombre = nom:
    celular = cel;
}

std::string Persona::getNombre()const{
    return nombre;
}

std::string Persona::getCelular()const{
    return celular;
}

void Persona::setNombre(std::string nom){
    nombre = nom;
}

void Persona::setCelular(std::string cel){
    celular = cel;
}

