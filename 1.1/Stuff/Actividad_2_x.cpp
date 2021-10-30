
// A01639289
// A01634064

#include <stdio.h>
#include <stdlib.h>   
#include <iostream>
#include <iomanip>
using namespace std;

int operaNumeros(){
    float num1, num2;
    char opc;
    cout << "Ingresa un numero:" << endl;
    cin >> num1;
    cout << "Ingresa otro numero:" << endl;
    cin >> num2;
    cout << "operaNumeros:\nS) Suma.\nR) Resta.\nM) Multiplicacion.\n\nElige una opcion: ";
    cin >> opc;
    switch (opc){
    case 'S':
        cout << num1 << "+" << num2 << "=" << num1+num2 << endl;
        break;
    case 'R':
        cout << num1 << "-" << num2 << "=" << num1-num2 << endl;
        break;
    case 'M':
        cout << num1 << "*" << num2 << "=" << num1*num2 << endl;
        break;
    default:
        cout << "Opcion no valida." << endl;
        break;
    }
    return 0;
}

int numeroImpar(){
    int num;
    for(;;) {
        cout << "Ingresa un numero: " << endl;
        cin >> num;
        if (num%2 != 0) {
            break;
        } else {
            cout << "Tu numero es par." << endl;
        }
    }
    cout << "Tu numero es impar." << endl;
    return 0;
}

int sumaPares(){
    int i, suma = 0;
    for (i=0;i<=100;i++){
        if (i%2==0){
            suma = suma + i;
        }
    }
    cout << "La suma de numeros pares entre 0 y el 100 es " << suma << endl;
    return 0;
}

int conversionCelsiusFarenheit(){
    float inc,cel,fah;
    int num, i;
    printf("Dame los grados celcius: ");
    cin>> cel;
    printf("Dame el numero de conversiones que se haran: ");
    cin>> num;
    printf("Dame el incremento entre los valores Celsius: ");
    cin>> inc;
    cout<<"Celcius\tFahrenheit"<<endl;
    for (i=0;i<num;i++){
        fah = (1.8*cel)+32.0;
        printf("%.2f",cel);
        cout << "\t";
        printf("%.2f",fah);
        cout << endl;
        cel = cel + inc;
    }
    return 0;
}

int main(){
    int opc = 0;
    do{
        cout << "Menu:\n1) operaNumeros.\n2) numeroImpar.\n3) sumaPares.\n4) conversionCelsiusFarenheit.\n5) Salir.\n\nElige una opcion: ";
        cin >> opc;
        switch (opc){
        case 1:
            operaNumeros();
            break;
        case 2:
            numeroImpar();
            break;
        case 3:
            sumaPares();
            break;
        case 4:
            conversionCelsiusFarenheit();
            break;
        case 5:
            //salir
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
        }
    }while(opc!=5);
    return 0;
}