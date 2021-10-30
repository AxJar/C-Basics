#include <iostream>
using namespace std;

int main(){
    float producto,iva,p_f;
    cout << "Introduzca el precio base del producto: ";
    cin >> producto;
    cout << "Introduzca el porcentaje de impuesto que debe aplicarse en decimal: ";
    cin >> iva;
    p_f = producto + (producto * iva);
    cout << "El precio del producto con el " << iva << " de IVA es: $ " << p_f << endl;
}