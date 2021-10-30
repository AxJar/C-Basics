#ifndef RECTANGULO_H
#define RECTANGULO_H
#include<string>
using namespace std;

class Rectangulo{
    public:
        // Constructores
        Rectangulo(); // Constructor por Default
        Rectangulo(double,double); // Recibimos los datos para iniciar los atributos
        // Getters
        double getAncho() const;
        double getLargo() const;
        // Setters (Siempre son de tipo "VOID")
        void setAncho(double);
        void setLargo(double);
        double area();
        double perimetro();
    private:
        double ancho;
        double largo;
        string color;
};

Rectangulo::Rectangulo(){  // " :: " los 2 puntos significan pertenencia
    ancho = 1;
    largo = 2;
}

Rectangulo::Rectangulo(double _ancho,double _largo){
    ancho = _ancho;
    largo = _largo;
}

double Rectangulo::getAncho() const{
    return ancho;
}

void Rectangulo::setAncho(double _ancho){
    ancho =_ancho;
}

double Rectangulo::perimetro(){
    double per = 2 * (ancho + largo);
    return per;
}


#endif // RECTANGULO_H
