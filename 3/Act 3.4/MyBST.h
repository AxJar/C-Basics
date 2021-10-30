#ifndef MYBST_H
#define MYBST_H

//Inclusión de las Librerías y Clases 
#include <iostream>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

//Definición de Estructura del BST para IPs
struct MyNodeBST {
  int data;
  string ip;
  MyNodeBST *left, *right;
  explicit MyNodeBST(int data, string ip) {
    this->data = data;
    this->ip = move(ip);
    this->left = this->right = nullptr;
  }
};

class MyBST {
private:
    // Atributo con funcionalidad hacia el Top de IPs más buscadas
    int top;

    // Número de elementos en el BST 
    int size;

    // Apuntador a la raíz del BST
    MyNodeBST *root;

    //Función que busca nodos en el BST, recibe como parámetros un entero y un nodo apuntado, retorna un valor boolenao.
    bool search(int data, MyNodeBST *current); //Complejidad Computacional: O(n)

    //Función que elimina un nodo en el BST, recibe como parámetros un nodo apuntado, un entero y un valor booleano referenciado y retorna un nodo apuntado
    MyNodeBST *remove(MyNodeBST *node, int data, bool &success); //Complejidad Computacional: O(n)

    //Función que imprime el BST en postorder, recibe como parámetro un nodo apuntado y no tiene valor de retorno.
    void postorder(MyNodeBST *current); //Complejidad Computacional: O(n)

    //Función que imprime el BST en preorder, recibe como parámetro un nodo apuntado y no tiene valor de retorno.
    void preorder(MyNodeBST *current); //Complejidad Computacional: O(n)

    //Función que imprime el BST en reverseInorder, , recibe como parámetro un nodo apuntado y no tiene valor de retorno.
    void reverseInorder(MyNodeBST *current, int &count); //Complejidad Computacional: O(n)

    //Función que despliega el reverseInorder del Top 5 IPs mas repetidas, recibe como parámetro un nodo apuntado y un entero referenciado, no tiene valor de retorno.
    void reverseInorderTopFive(MyNodeBST *current, int &count); //Complejidad Computacional: O(n)

    //Función que encuentra el valor minimo en el BST, recibe como parámetro un nodo apuntado y retorna un nodo apuntado.
    static MyNodeBST *minValueNode(MyNodeBST *node); //Complejidad Computacional: O(n)

    //Función que retorna la altura del BST, no recibe parámetros y no tiene valor de retorno.
    int height(MyNodeBST *node); //Complejidad Computacional: O(n)

    //Función que corrobora ancestros, recibe como parámetro un nodo apuntado, un entero y un string referenciado, retorna un valor booleano. 
    bool ancestors(MyNodeBST *node, int data, string &output); //Complejidad Computacional: O(n)

    //Función que retorna el nivel de un nodo dado, recibe como parámetro un nodo apuntado y dos enteros, retorna un valor entero. 
    int whatLevelAmI(MyNodeBST *node, int data, int level); //Complejidad Computacional: O(n)

public:
    //Constructor de la clase BST, establece el peso en cero y la raíz como apuntador nulo.
    MyBST(); //Complejidad Computacional: O(1)

    //Función que inserta nodos en el BST, recibe como parámetros un entero y un string constante referenciado, retorna un valor boolenao
    bool insert(int key, const string &ip); // Complejidad: O(n)

    // Este método imprime reverseInorder del BST.
    // Complejidad: O(n)
    void reverseInorder(); //Complejidad Computacional: O(n)

    //Función que implementa el despliegue el Top 5 de IPs mas repetidas, no recibe parámetros y no tiene valor de retorna.
    void topFive(); //Complejidad Computacional: O(n)

};

#endif //MYBST_H