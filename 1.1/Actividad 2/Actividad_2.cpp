#include <iostream>
#include <string>
#include <math.h>
using namespace std;
/*
Axel Jarquin Morga // A01636324
Francisco José Ramírez Aldaco // A01634262
*/

// Funciones

int numeroImpar(){
    int n;
    for(;;) 
    {
        cout << "Ingresa un numero: " << "\n";
        cin >> n;
        if (n % 2 != 0) 
        {
            break;
        } else 
        {
            cout << "El numero que ingresaste es par." << "\n";
        }
    }
    cout << "El numero que ingresaste es impar." << "\n";
    return 0;
}

/*
Casos de prueba:
1. (Ingresa un numero) => (2) => cout << "El numero que ingresaste es par" porque 2 % 2 = 0 entonces es par, (4) => cout << "El numero que ingresaste es par" porque 4 % 2 = 0 entonces es par, (7) => cout << "El numero que ingresaste es impar." y se rompe el ciclo
2. (Ingresa un numero) => (10) => cout << "El numero que ingresaste es par" porque 10 % 2 = 0 entonces es par ,(20) => cout << "El numero que ingresaste es par" porque 20 % 2 = 0 entonces es par ,(43) => cout << "El numero que ingresaste es impar." y se rompe el ciclo
*/

int sumaPares()
{
    int i, sum = 0;
    for (i = 0; i <= 100; i++)
    {
        if (i % 2 == 0)
        {
            sum = sum + i;
        }
    }
    cout << "La suma de numeros pares entre 0 y el 100 es " << sum << "\n";
    return 0;
}

/*
Caso de prueba:
1.  suma todos los números enteros pares entre el 0 y el 100 , es decir todos los números que n % 2 == 0 
    suma de números enteros entre 0 y 100 ==  2550
*/

void mediaAritmetica(int nums) 
{
    float suma, media, temp;
    temp = 0;
    suma = 0;
    for (int i = 0; i < nums; i++) 
    {
        cin >> temp;
        suma += temp;
    }
    media = suma / nums;
    cout << "La media aritmetica es: " << media << endl; 
}

/*
Casos de prueba:
1. 5 números, 4,5,6,7,8. Su media aritmética es 6, porque (4+5+6+7+8)/5 = 6
2. 4 números, 28,34,96,21. Su media aritmética es 44.75, porque (28+34+96+21)/4 = 44.75
*/


void mediaGeometricaArmonica() {
    float mediaArmonica, mediaGeometrica, prod, inv_sum, temp;
    inv_sum = 0;
    prod = 1;
    float cont = 0;
    cin >> temp;
    while (temp != 0) {
        cont += 1;
        prod *= temp;
        inv_sum += 1/temp;
        cin >> temp;
    } 
    mediaGeometrica = pow(prod,1/cont);
    mediaArmonica = cont / inv_sum;
    cout << "La media geometrica es: " << mediaGeometrica << endl;
    cout << "La media armonica es: " << mediaArmonica << endl; 
    return;
}

/*
Casos de prueba:
1. input: 3,4,5,6; media geométrica: (3*4*5*6)^(1/4) = 4.35588; media armónica: 4/(1/3 + 1/4 + 1/5 + 1/6) = 4.21053
2. input: 24,57,35,68,46; media geométrica: (24*57*35*68*46)^(1/5) = 43.1603; media armónica: 5/(1/24 + 1/57 + 1/35 + 1/68 + 1/46) = 40.2489
*/

int main() {
    int opc;
    while (opc != 5) {
        cout << "Menu:\n(1) numeroImpar\n(2) mediaAritmetica\n(3) sumaPares\n(4) mediaGeometricaArmonica\n(5) Salir." << endl;
        cout << "\nIngrese la opcion deseada: ";
        cin >> opc;
        switch (opc){
            case 1:
                numeroImpar();
                break;
            case 2:
                cout << "Escribe la cantidad de numeros a ingresar: ";
                int nums;
                cin >> nums;
                mediaAritmetica(nums);
                break;
            case 3:
                sumaPares();
                break;
            case 4:
                cout << "Escribe los numeros cuya media se va a calcular, uno a uno, y cuando hayas terminado escribe 0." << endl;
                mediaGeometricaArmonica();
                break;
            case 5:
                cout << "Gracias por usar este programa";
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    }
    return 0;
}