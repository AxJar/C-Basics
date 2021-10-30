#include <iostream>
#include <vector>
#include "Figura.h"
#include "Rectangulo.h"
#include "Cuadrado.h"
#include "Caja.h"


using namespace std;

int main(){
    //             nombre   tamaño
    vector<Figura *> figuras(4);
    figuras[0] = new Rectangulo(5.0,7.0);
    figuras[1] = new Cuadrado(15.0);
    figuras[2] = new Caja(2.0,3.0,6.0);

    for(int i = 0; i < 4; i++){
        Figura* fig1 = figuras[i];
        fig1 -> imprimir(); // apuntador
        cout << "El perimetro de la figura 1 es: "<< fig1 -> perimetro()<<endl;
        cout << "El area de la figura 1 es: "<< fig1 -> area()<<endl;
        cout << "El volumen de la figura 1 es: "<< fig1 -> volumen()<<endl;
        if(Cuadrado* c = dynamic_cast < Cuadrado* > (fig1)){
            c -> saludar();
        };
        cout << endl;
    };


/*     Figura fig1;
    fig1.imprimir();
    cout << "El perimetro de la figura 1 es: "<< fig1.perimetro()<<endl;
    cout << "El area de la figura 1 es: "<< fig1.area()<<endl;
    cout << "El volumen de la figura 1 es: "<< fig1.volumen()<<endl;
    cout << endl; 
    
    Rectangulo rec1(7.0,4.0);
    rec1.imprimir();
    cout << "El perimetro de la figura 1 es: "<< rec1.perimetro()<<endl;
    cout << "El area de la figura 1 es: "<< rec1.area()<<endl;
    cout << "El volumen de la figura 1 es: "<< rec1.volumen()<<endl;
    cout << endl;

    Cuadrado cua1(5.0);
    cua1.imprimir();
    cout << "El perimetro de la figura 1 es: "<< cua1.perimetro()<<endl;
    cout << "El area de la figura 1 es: "<< cua1.area()<<endl;
    cout << "El volumen de la figura 1 es: "<< cua1.volumen()<<endl;
    cout << endl;

    Caja caja1;
    caja1.imprimir();
    cout << "El perimetro de la figura 1 es: "<< caja1.perimetro()<<endl;
    cout << "El area de la figura 1 es: "<< caja1.area()<<endl;
    cout << "El volumen de la figura 1 es: "<< caja1.volumen()<<endl;
    cout << endl; */
};

