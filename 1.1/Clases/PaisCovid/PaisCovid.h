#ifndef PAISCOVID_H
#define PAISCOVID_H
#include <iostream>
#include <string>

class PaisCovid{
    private:
        std::string nombre;
        int enfermos;
        int curados;
        int muertes;
    public:
        //constructores
        PaisCovid();
        PaisCovid(std::string, int); // numero de enfermos
        //getters
        std::string getNombre() const;
        int getEnfermos()const;
        int getMuertes()const;
        int getCurados()const;
        //setters
        void setNombre(std::string);
        void registraEnfermos(int);
        void registraCurados(int);
        void registraMuertes(int);
        int infectadosTotales();
        double tasaMortalidad();
        void imprime();
};

PaisCovid::PaisCovid(){
    nombre = "Desconocido";
    enfermos = 0;
    curados = 0;
    muertes = 0;
}

PaisCovid::PaisCovid(std::string name, int sick){
    nombre = name;
    enfermos = sick;
    curados = 0;
    muertes = 0;
}

PaisCovid:PaisCovid(std::string name, int sick, int cure, int deceased){
    nombre = name
    enfermos = sick
    curados = cure
    muertes = deceased
}


std::string PaisCovid::getNombre()const {
    return nombre;
}

int PaisCovid::getEnfermos()const {
    return enfermos;
}

int PaisCovid::getCurados()const {
    return curados;
}

int PaisCovid::getMuertes()const {
    return muertes;
}

void PaisCovid::setNombre(std::string _nombre){
    nombre = _nombre;
}

void PaisCovid::registraEnfermos(int sick){
    if (sick > 0){
        enfermos += sick;
    }
}

void PaisCovid::registraCurados(int cured){
    if (cured > 0 && cured <= enfermos){
        enfermos -= cured;
        curados += cured;
    }
}

void PaisCovid::registraMuertes(int deceased){
    if (deceased > 0 && deceased <= enfermos){
        muertes += deceased;
        enfermos-= deceased;
    }
}

int PaisCovid::infectadosTotales(){
    return enfermos + curados + muertes;
}

double PaisCovid::tasaMortalidad(){
    return (muertes * 100.0) / infectadosTotales();
}

void PaisCovid::imprime(){
    std::cout << "Pais: "<< nombre << std::endl;
    std::cout << "Infectados totales: "<< infectadosTotales() << std::endl;
    std::cout << "Tasa de mortalidad: "<< tasaMortalidad() << std::endl;
}

#endif // PAISCOVID_H