#include <iostream>
using namespace std;

// Funciones
int elMayor(int arreglo[], int cant){
    // Regresa el valor mayor del arreglo
    int mayor = arreglo[0];
    for(int i = 1; i < cant; i++ ){
        if (arreglo[i] > mayor){
            mayor = arreglo[i];
        }
    }
    return mayor;
}

int main(){
    // Crear un arreglo con 5 datos y determinar cual es el mayor
    int tam = 5;
    int arr[tam];
    cout << "Ingresa los datos para llenar una lista de 5 datos" << endl;
    for (int i = 0; i < tam; i++){
        cout << "Ingresa el valor que estara en la posicion " << i + 1 << ": ";
        cin >> arr[i];
    }
    for (int i = 0; i < tam; i++){
        cout << arr[i] << " ";
    }
    cout << "\n" << elMayor(arr, tam) << " es el valor mayor de tu lista" << endl;
}
