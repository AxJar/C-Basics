#include <iostream>
#include <vector>
#include "Orden.h"
#include "Search.h"

using namespace std;

int main() {
    cout << "------Ordenamiento------" << endl;

    vector<int> vector_1{20, 48, 16, 35, 84, 89, 56};
    cout << "Vector 1 original: ";
    for (size_t i = 0; i < vector_1.size(); ++i) {
        cout << vector_1.at(i) << " ";
    }
    cout << endl;
    Orden::ordIntercambio(vector_1);
    cout << "Vector 1 ordenado por intercambio: ";
    for (size_t i = 0; i < vector_1.size(); ++i) {
        cout << vector_1.at(i) << " ";
    }
    cout << endl;
    cout << endl;

    vector<int> vector_2{51, 18, 65, 54, 92, 35, 4};
    cout << "Vector 2 original: ";
    for (size_t i = 0; i < vector_2.size(); ++i) {
        cout << vector_2.at(i) << " ";
    }
    cout << endl;
    Orden::ordBurbuja(vector_2);
    cout << "Vector 2 ordenado por burbuja: ";
    for (size_t i = 0; i < vector_2.size(); ++i) {
        cout << vector_2.at(i) << " ";
    }
    cout << endl;
    cout << endl;

    vector<int> vector_3{12, 54, 96, 99, 87, 21, 24};
    cout << "Vector 3 original: ";
    for (size_t i = 0; i < vector_3.size(); ++i) {
        cout << vector_3.at(i) << " ";
    }
    cout << endl;
    Orden::ordMerge(vector_3,0, (vector_3.size() -1));
    cout << "Vector 3 ordenado por merge: ";
    for (size_t i = 0; i < vector_3.size(); ++i) {
        cout << vector_3.at(i) << " ";
    }
    cout << endl;
    cout << endl;

    cout << "------Busqueda Binaria------" << endl;

    int w = Search::busqBinaria(vector_1,35);
    cout << "Buscando 35 en vector 1 ordenado: ";
    for (size_t i = 0; i < vector_1.size(); ++i) {
        cout << vector_1.at(i) << " ";
    }
    cout << endl;
    if (w == -1)
        cout << "No se encontro el numero";
    else
        cout << "Se encontro el numero en el indice " << w;

    cout << endl;
    cout << endl;

    int y = Search::busqBinaria(vector_1,99);
    cout << "Buscando 99 en vector 1 ordenado: ";
    for (size_t i = 0; i < vector_1.size(); ++i) {
        cout << vector_1.at(i) << " ";
    }
    cout << endl;
    if (y == -1)
        cout << "No se encontro el numero ";
    else
        cout << "Se encontro el numero en el indice " << y;

    cout << endl;
    cout << endl;

    cout << "------Busqueda Secuencial------" << endl;

    int b = Search::busqSecuencial(vector_2, 4);
    cout << "Buscando 4 en vector 1 ordenado: ";
    for (size_t i = 0; i < vector_2.size(); ++i) {
        cout << vector_2.at(i) << " ";
    }
    cout << endl;
    if (b == -1)
        cout << "No se encontro el numero" ;
    else
        cout << "Se encontro el numero en el indice " << b;

    cout << endl;
    cout << endl;

    int c = Search::busqSecuencial(vector_2 ,80);
    cout << "Buscando 80 en vector 1 ordenado: ";
    for (size_t i = 0; i < vector_2.size(); ++i) {
        cout << vector_2.at(i) << " ";
    }
    cout << endl;
    if (c == -1)
        cout << "No se encontro el numero ";
    else
        cout << "Se encontro el numero en el indice " << c;

    cout << endl;
    cout << endl;




}
