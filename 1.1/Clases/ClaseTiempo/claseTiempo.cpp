#include<iostream>
#include<stdlib.h>
using namespace std;

class Tiempo{
    private:
        int horas,minutos,segundos;
    public:
        Tiempo(int,int,int); // Constructor 1
        Tiempo(int); // Constructor 2
        void mostrarTiempo();
};
// Constructor 1
Tiempo::Tiempo(int _horas,int _minutos,int _segundos){
    horas = _horas;
    minutos = _minutos;
    segundos = _segundos;
}
// Constructor 2
Tiempo::Tiempo(int tiempoSeg){
    horas = tiempoSeg / 3600; // Extraer horas
    tiempoSeg %= 3600;
    minutos = tiempoSeg / 60;  // Extraer minutos
    segundos = tiempoSeg % 60; // Extraer segundos
}  

void Tiempo::mostrarTiempo(){
    cout<<"La hora es: "<<horas<<":"<<minutos<<":"<<segundos<<endl;
}

int main(){
    Tiempo horaActual(16,23,30);
    Tiempo haceunaHora(55410);

    horaActual.mostrarTiempo();
    haceunaHora.mostrarTiempo();

    system("pause");
    return 0;
}