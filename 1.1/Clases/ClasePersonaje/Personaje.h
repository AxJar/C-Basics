//Completa lo que haga falta de la clase Personaje, ésta clase representa un personaje dentro de la pantalla
// Tiene un punto que representa la posición del personaje y puede avanzar.
#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>
#include "Punto.h"

class Personaje {
    public:
        //Constructor por default
        Personaje();
        //Constructor con parámetros, recibe un objeto Punto
        Personaje(std::string n, Punto p);
        //Getters y Setters de los atributos
        string getNombre() const;
        Punto getPosicion() const;
        void setNombre(string);
        void setPosicion(Punto);
        // Método cambia posición, recibe datos en x e y y actualiza los valores de x, así como de y del atributo posición
        void cambiaPosicion(int, int);
        //Método que avanza al personaje en horizontal, actualiza la coordenada x del atributo posición
        void avanzaHor(int);
        //Método que avanza al personaje en vertical, actualiza la coordenada y del atributo posicion
        void avanzaVer(int);
        //Imprime el nombre y posición del personaje
        void imprime();
    private:
        std::string nombre;
        Punto posicion;
        
};

//Constructor default inicia el nombre a "Creatura"
Personaje::Personaje(){
    nombre = "Creatura";
    Punto nuevo(0,0);
    posicion = nuevo;
}

//Constructor con parámetros, inicia los atributos a lo que recibe como parámetro
Personaje::Personaje(string nombre_,Punto posicion_){
    nombre = nombre_;
    posicion = posicion_;
}

// Setter de nombre
void Personaje::setNombre(string nombre_){
    nombre = nombre_;
}

// Getter de nombre
string Personaje::getNombre() const{
    return nombre;
}

//Setter de posicion - recibe un Punto
void Personaje::setPosicion(Punto posicion_){
    posicion = posicion_;
}

//Getter de posicion - devuelve un Punto
Punto Personaje::getPosicion() const{
    return posicion;
}


//Cambia las coordenadas de su atributo posición
void Personaje::cambiaPosicion(int x, int y){
    Punto cambia(x,y);
    posicion = cambia;
}

//Actualiza la coordenada X de la posición sumándole el incremento que recibe
void Personaje::avanzaHor(int inc){
    int var = posicion.getX();
    posicion.setX(var + inc);

}
//Actualiza la coordenada Y de la posición sumándole el incremento que recibe
void Personaje::avanzaVer(int inc){
    int var = posicion.getY();
    posicion.setY(var + inc);
}

//Imprime el personaje, no modifiques este método
void Personaje::imprime(){
    std::cout << nombre << " esta en la coordenada ";
    posicion.imprimePunto();
}

#endif //PERSONAJE_H