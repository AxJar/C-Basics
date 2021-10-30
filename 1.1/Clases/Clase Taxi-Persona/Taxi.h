#ifndef TAXI_H
#define TAXI_H
#include "Persona.h"

class Taxi{
    public:
        Taxi();   // Constructor por defatult
        Taxi(Persona, int );           // Constructor con parametros
        Persona getResponsable() const;
        void setResponsable(Persona);
        int getIden() const;
        void setIden(int);
        
    private:
        Persona responsable;
        int iden;
};

Taxi::Taxi(){
    Persona aux("-","-");
    responsable = aux;
    iden = 0
}

Taxi::Taxi(Persona resp, int id){
    responsable = resp;
    iden = id;
}