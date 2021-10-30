#include <iostream>
#include <string>
using namespace std;

//incluye la clase que requieres en el main
#include"Personaje.h"
#include"Punto.h"

int main() {
    //Crea un Punto en las coordenadas 10, 10 de la pantalla
    Punto p1(10,10);
    // Crea un Personaje en la variable pikachu con esa posición, el nombre del Personaje es "Pikachu"
    Personaje pikachu("Pikachu",p1);
    //Muestra el personaje llamando a imprime
    pikachu.imprime();
    //Mueve a Pikachu directamente a las coordenadas 40,50
    pikachu.cambiaPosicion(40,50);
    //Muestra a pikachu nuevamente
    pikachu.imprime();
    //Realiza un pequeño menú que se repita donde con h/H indiquen que se mueva en horizontal pikachu y con v/V en vertical
    //y con s/S salir del menú
    // Que tambien diga el usuario cuánto va a avanzar, despues de moverlo imprime de nuevo el pikachu.
    char movimiento;//para recibir la instrucción
    int avance; //para recibir cuanto va a avanzar
    do{ //para repetir el menú
        cin >> movimiento;
        switch(movimiento){
            case 'h':
            case 'H':
                //REcibe el avance que quieres para el personaje
                cin >> avance;
                //mueve el personaje en horizontal
                pikachu.avanzaHor(avance);
                //imprime el personaje
                pikachu.imprime();
                break;
            case 'v':
            case 'V':
                //REcibe el avance que quieres para el personaje
                cin >> avance;
                //mueve el personaje en horizontal
                pikachu.avanzaVer(avance);
                //imprime el personaje
                pikachu.imprime();
                break;
            case 's':
            case 'S':
                cout << "Termina avance" << endl;
                break;
            default:
                cout << "Opcion invalida";
        }
    }while(movimiento!='S' && movimiento!='s');
    //imprime p1 con el método adecuado, verás que no ha cambiado, ¿por qué? Y el punto del personaje si estuvo cambiando...
    p1.imprimePunto();
    return 0;
}
