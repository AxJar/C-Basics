#include<iostream>
//https://www.tutorialspoint.com/cplusplus-program-to-implement-avl-tree
// Los arboles AVL son los que requieren de un balanceo
using namespace std;

// Define los nodos como estructuras
struct avl { //Estructura del arbol AVL
    int d;  // Guarda el dato
    struct avl* l;  // Rama izquierda
    struct avl* r;  // Rama derecha
}*r; // Alias // Se usa para no escribir tanto codigo

class avl_tree {
public:
    // Define todos sus metodos
    int height(avl*);
    int difference(avl*);
    avl* rr_rotat(avl*);
    avl* ll_rotat(avl*);
    avl* lr_rotat(avl*);
    avl* rl_rotat(avl*);
    avl* balance(avl*);
    avl* insert(avl*, int);
    void show(avl*, int);
    void inorder(avl*);
    void preorder(avl*);
    void postorder(avl*);
    avl_tree() {
        r = NULL;
    }
};
// Metodo recursivo que saca la altura del sub arbol
int avl_tree::height(avl* t) {
    int h = 0;
    if (t != NULL) {
        int l_height = height(t->l);
        int r_height = height(t->r);
        int max_height = max(l_height, r_height); // Regresa la altura mayor entre las 2 ramas
        h = max_height + 1;
    }
    return h;
}
// Metodo que saca la diferencia del sub arbol
int avl_tree::difference(avl* t) { // Checa las alturas, mediante el metodo de altura
    int l_height = height(t->l); // Revisa altura rama izquierda
    int r_height = height(t->r); // Revisa altura rama derecha
    int b_factor = l_height - r_height; // Si el lado derecho es mas largo es negativo
    return b_factor;                    // Si el lado izquierdo es mas largo es positivo
}
avl* avl_tree::rr_rotat(avl* parent) { // Rotacion simple a la derecha
    avl* t;
    t = parent->r;
    parent->r = t->l;
    t->l = parent;
    cout << "Right Rotation" << std::endl;
    return t;
}
avl* avl_tree::ll_rotat(avl* parent) {  // Rotacion simple a la izquierda
    avl* t;
    t = parent->l;
    parent->l = t->r;
    t->r = parent;
    cout << "Left Rotation" << std::endl;
    return t;
}
avl* avl_tree::lr_rotat(avl* parent) { // Rotacion doble
    avl* t;
    t = parent->l;
    parent->l = rr_rotat(t);
    cout << "Left-Right Rotation" << std::endl;
    return ll_rotat(parent);
}
avl* avl_tree::rl_rotat(avl* parent) { // Rotacion doble
    avl* t;
    t = parent->r;
    parent->r = ll_rotat(t);
    cout << "Right-Left Rotation" << std::endl;
    return rr_rotat(parent);
}
// Metodo que balancea el sub arbol
// Va revisando rama por rama(de abajo para arriba) , hasta ver donde requiere balanceo
avl* avl_tree::balance(avl* t) {  // Recibe apuntador
    int bal_factor = difference(t); // Saca factor de balanceo
    if (bal_factor > 1) {  // Pregunta si el factor es mayor que 1
        if (difference(t->l) > 0)
            t = ll_rotat(t);
        else
            t = lr_rotat(t);
    }
    else if (bal_factor < -1) { // Pregunta si el factor es menor que -1
        if (difference(t->r) > 0)
            t = rl_rotat(t);
        else
            t = rr_rotat(t);
    }
    return t;
}
// Metodo Recursivo que inserta un sub arbol
avl* avl_tree::insert(avl* r, int v) {
    if (r == NULL) { // Si r es nulo , entra, si no , pasa al else
        r = new avl; // Crea un Nodo tipo struct
        r->d = v; //  En el nodo creado guarda el numero dado como "v"
        r->l = NULL; // rama izquierda nula
        r->r = NULL; // rama derecha nula
        return r; // Regresa apuntador r
    }
    else if (v < r->d) { // Si r ya no es nulo,pregunta si el dato recibido es menor que r
        // Datos menores van a la rama izquierda
        r->l = insert(r->l, v);
        r = balance(r);
    }
    else if (v >= r->d) { // Si el dato recibido no es menor , pregunta si es mayor que r
        // Datos mayores van a la rama derecha
        r->r = insert(r->r, v); // Llamada recursiva para que genere un nuevo nodo con el dato ya recibido, y la cuelgue
        r = balance(r); // Como se acaba de insertar , se tiene que balancear
    } return r;
}
void avl_tree::show(avl* p, int l) {
    int i;
    if (p != NULL) {
        show(p->r, l + 1);
        cout << " ";
        if (p == r)
            cout << "Root -> ";
        for (i = 0; i < l && p != r; i++)
            cout << " ";
        cout << p->d;
        show(p->l, l + 1);
    }
}
void avl_tree::inorder(avl* t) {
    if (t == NULL)
        return;
    inorder(t->l);
    cout << t->d << " ";
    inorder(t->r);
}
void avl_tree::preorder(avl* t) {
    if (t == NULL)
        return;
    cout << t->d << " ";
    preorder(t->l);
    preorder(t->r);
}
void avl_tree::postorder(avl* t) {
    if (t == NULL)
        return;
    postorder(t->l);
    postorder(t->r);
    cout << t->d << " ";
}

int main() {
    avl_tree avl;
    int c, i;
    while (1) {
        cout << "1.Insert Element into the tree" << endl;
        cout << "2.show Balanced AVL Tree" << endl;
        cout << "3.InOrder traversal" << endl;
        cout << "4.PreOrder traversal" << endl;
        cout << "5.PostOrder traversal" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> c;
        switch (c) {
            case 1:
                cout << "Enter value to be inserted: ";
                cin >> i;
                r = avl.insert(r, i);
                break;
            case 2:
                if (r == NULL) {
                    cout << "Tree is Empty" << endl;
                    continue;
                }
                cout << "Balanced AVL Tree:" << endl;
                avl.show(r, 1);
                cout << endl;
                break;
            case 3:
                cout << "Inorder Traversal:" << endl;
                avl.inorder(r);
                cout << endl;
                break;
            case 4:
                cout << "Preorder Traversal:" << endl;
                avl.preorder(r);
                cout << endl;
                break;
            case 5:
                cout << "Postorder Traversal:" << endl;
                avl.postorder(r);
                cout << endl;
                break;
            case 6:
                exit(1);
                break;
            default:
                cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}