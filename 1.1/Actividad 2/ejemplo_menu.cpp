
#include <iostream>
using namespace std;

int main() {
    char opc;
    do{
    system("cls");
    cout<<"\t1. Opcion 1\n\t2. Opcion 2\n\t3. Opcion 3\n\t4. Salir\n\n"<<endl;
    cout << "Ingresa la opcion deseada: "; cin >> opc;
    switch(opc){
        case '1':
            cout << "Entraste a opcion 1"<<endl;
            break;
        case '2':
            cout << "Entraste a opcion 2"<<endl;
            break;
        case '3':
            cout << "Entraste a opcion 3"<<endl;
            break;
        case '4':
            cout << "Saliendo del programa"<<endl;
            break;
        default:
            cout << "Opcion invalida";
    }
    system("pause");
    }while(opc != '4');
}
