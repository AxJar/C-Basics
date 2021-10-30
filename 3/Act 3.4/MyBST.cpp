//Inclusión de las Librerías y Clases 
#include "MyBST.h"
#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

//Constructor de la clase BST, establece el peso en cero y la raíz como apuntador nulo.
MyBST::MyBST() { //Complejidad Computacional: O(1)
  this->size = 0;
  this->root = nullptr;
}

//Función que busca nodos en el BST, recibe como parámetros un entero y un nodo apuntado, retorna un valor boolenao
bool MyBST::search(int data, MyNodeBST *current) { //Complejidad Computacional: O(n)
  if (current == nullptr) {
    return false;
  } else if (current->data == data) {
    return true;
  }
  if (data < current->data) {
    return search(data, current->left);
  } else {
    return search(data, current->right);
  }
}

//Función que inserta nodos en el BST, recibe como parámetros un entero y un string constante referenciado, retorna un valor boolenao
bool MyBST::insert(int key, const string &ip) { // Complejidad: O(n)
  if (this->root == nullptr) {
    this->root = new MyNodeBST(key, ip);
    size++;
    return true;
  } else {
    MyNodeBST *current = this->root, *prev = nullptr;

    while (current != nullptr) {
      prev = current;
      if (key == current->data) {
        return false;
      } else {
        current = key < current->data ? current->left : current->right;
      }
    }
       
    if (key < prev->data) {
      prev->left = new MyNodeBST(key, ip);
    } else {
      prev->right = new MyNodeBST(key, ip);
    }
    
    this->size++;
    return true;
  }
}

//Función que encuentra el valor minimo en el BST, recibe como parámetro un nodo apuntado y retorna un nodo apuntado
MyNodeBST *MyBST::minValueNode(MyNodeBST *node) { //Complejidad Computacional: O(n)
  MyNodeBST *current = node;
  while (current && current->left != nullptr)
    current = current->left;
  return current;
}

//Función que elimina un nodo en el BST, recibe como parámetros un nodo apuntado, un entero y un valor booleano referenciado y retorna un nodo apuntado
MyNodeBST *MyBST::remove(MyNodeBST *node, int data, bool &success) { //Complejidad Computacional: O(n)
  if (node == nullptr) {
    success = false;
    return node;
  }
  if (data < node->data) {
        node->left = remove(node->left, data, success);
  } else if (data > node->data) {
        node->right = remove(node->right, data, success);
  } else {
    if (node->left == nullptr) {
      MyNodeBST *temp = node->right;
      delete node;
      success = true;
      return temp;
    } else if (node->right == nullptr) {
      MyNodeBST *temp = node->left;
      delete node;
      success = true;
      return temp;
    }
    MyNodeBST *temp = minValueNode(node->right);
    node->data = temp->data;
    root->right = remove(node->right, temp->data, success);
  }

  return node;
}

//Función que imprime el BST en postorder, recibe como parámetro un nodo apuntado y no tiene valor de retorno.
void MyBST::postorder(MyNodeBST *current) { //Complejidad Computacional: O(n)
  if (current != nullptr) {
    postorder(current->left);
    postorder(current->right);
    cout << current->data << ",";
  }
}

//Función que imprime el BST en preorder, recibe como parámetro un nodo apuntado y no tiene valor de retorno.
void MyBST::preorder(MyNodeBST *current) { //Complejidad Computacional: O(n)
    if (current != nullptr) {
      cout << current->data << ",";
      this->preorder(current->left);
      this->preorder(current->right);
    }
}

//Función que imprime el BST en reverseInorder, , recibe como parámetro un nodo apuntado y no tiene valor de retorno.
void MyBST::reverseInorder(MyNodeBST *current, int &count) { //Complejidad Computacional: O(n)
    if (count > 0 || count == -1) {
        if (count != -1) {
            count--;
        }
        if (current != nullptr) {
            reverseInorder(current->right, count);
            if (current->data!=0)
              cout<<"IP: "<< current->ip << " --- Repeticiones: "<< current->data << endl;
            reverseInorder(current->left, count);
        }
    }
}

//Funcion que implementa el reverseInorder, no recibe parámetros y no tiene valor de retorno.
void MyBST::reverseInorder() { //Complejidad Computacional: O(n)
  int count = -1;
  reverseInorder(this->root, count);
}

//Función que retorna la altura del BST, no recibe parámetros y no tiene valor de retorno.
int MyBST::height(MyNodeBST *node) { //Complejidad Computacional: O(n)
  if (node == nullptr) {
    return 0;
  } else {
    int leftHeight = height(node->left);
    int rightHeight = height(node->left);

    if (leftHeight < rightHeight) {
      return (rightHeight + 1);
    } else {
          return (leftHeight + 1);
    }

  }
}

//Función que corrobora ancestros, recibe como parámetro un nodo apuntado, un entero y un string referenciado, retorna un valor booleano. 
bool MyBST::ancestors(MyNodeBST *node, int data, string &output) { //Complejidad Computacional: O(n)
  if (node == nullptr) {
    return false;
  }
  if (node->data == data) {
    return true;
  }
  if (ancestors(node->left, data, output) || ancestors(node->right, data, output)) {
    output.insert(0, to_string(node->data) + ",");
    return true;
  } else {
    return false;
  }
}

//Función que retorna el nivel de un nodo dado, recibe como parámetro un nodo apuntado y dos enteros, retorna un valor entero. 
int MyBST::whatLevelAmI(MyNodeBST *node, int data, int level) { //Complejidad Computacional: O(n)
  if (node == nullptr) {
    return -1;
  }
  if (node->data == data) {
    return level;
  }
  int nextLevel = whatLevelAmI(node->left, data, level + 1);
  if (nextLevel != 0) {
    return nextLevel;
  }
  nextLevel = whatLevelAmI(node->right, data, level + 1);
  return nextLevel;
}

//Función que implementa el despliegue el Top 5 de IPs mas repetidas, no recibe parámetros y no tiene valor de retorna.
void MyBST::topFive() { //Complejidad Computacional: O(n)
  int count = -1;
  reverseInorderTopFive(this->root, count);
  top=0;
}

//Función que despliega el reverseInorder del Top 5 IPs mas repetidas, recibe como parámetro un nodo apuntado y un entero referenciado, no tiene valor de retorno.
void MyBST::reverseInorderTopFive(MyNodeBST *current, int &count) { //Complejidad Computacional: O(n)
  if (count > 0 || count == -1) {
    if (count != -1) {
      count--;
    }
    if (current != nullptr) {
      reverseInorderTopFive(current->right, count);
      if (top<5 && current->data!=0){
        cout<<"IP: "<< current->ip << " --- Repeticiones: "<< current->data << endl;
        top++;
      }
      reverseInorderTopFive(current->left, count);
    }
  }
}