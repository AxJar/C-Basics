#include <stack>
#include <iostream>

int main() {
    char valores[5] {1,2,'+',4,'+'};

    std::stack<char> MyStack;

    for (int i = 0; i <= 4; ++i) {
        // Preguntar si es un numero o si es un operando

        // Si es un operador , lo que tengo que hacer es sacar 2 numeros y ejecutar la operacion
        if (valores[i] == '+'){
            int temp1 = MyStack.top();
            MyStack.pop();
            int temp2 = MyStack.top();
            MyStack.pop();

            int res = temp1 + temp2;

            MyStack.push(res);
        }
        // De lo contrario , si es un numero , simplemente lo meto a la pila
        else
            MyStack.push(valores[i]);
    }
    std::cout << MyStack.top();
    MyStack.pop();
}
