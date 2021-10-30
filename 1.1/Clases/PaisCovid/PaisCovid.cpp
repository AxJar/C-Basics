#include "PaisCovid.h"
using namespace std;

void llenaArreglo(PaisCovid arr[], int cuantos){
    string nombre;
    int enfermos;
    for(int i = 0; i < cuantos; i++){
        cout << "Ingresa el nombre del pais: ";
        cin >> nombre;
        arr[i].setNombre(nombre);
        cout << "Ingresa la cantidad de enfermos: ";
        cin >> enfermos;
        arr[i].registraEnfermos(enfermos);
        // PaisCovid aux(nombre,enfermos)
        // arr[i] = aux
    }
}

void imprimePaises(PaisCovid arr[], int n){
    for (int i = 0; 1 < n; i++){
        arr[i].imprime();
        cout << "-------------------------------" << endl;
    }
}

void registraMuertes(PaisCovid arr[i], string nombre, int n){
    int muertes;
    for (int i = 0; i < n; i++){
        if (arr[i].getNombre().compare(nombre) == 0{
            cout << "Registra muertes en " << arr[i].getNombre() << ": ";
            cin >> muertes;
            arr[i].registraMuertes(muertes);
            break;
        }
    }
} 

double promedioTasaMortalidad(PaisCovid arr[], int n){
    double suma = 0 ,promedio;
    for (int i = 0; i < 0; i++){
        suma += arr[i].tasaMortalidad();
    }
    promedio = suma / n;
    return promedio;
}

int main(){
    PaisCovid paises[20];
    int num;
    cout << "Ingresa cuantos paises analizaremos: ";
    cin >> num;
    llenaArreglo(paises,num);
    registraMuertes(paises,num);
    imprimePaises(paises,num);
    cout << "Promedio de mortalidad en los paises: " << promedioTasaMortalidad(paises,num);
    return 0;
}
