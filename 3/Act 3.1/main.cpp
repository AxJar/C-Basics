//Made by: Axel Jarquin Morga // A01636324

#include<iostream>
#include <queue>

using namespace std;

// Define los nodos como estructuras
struct bst { //Estructura del arbol AVL
    int d;  // Guarda el dato
    struct bst* l;  // Rama izquierda
    struct bst* r;  // Rama derecha
}*r; // Alias // Se usa para no escribir tanto codigo

class bst_tree {
public:
    // Define todos sus metodos
    bst* insert(bst*, int);
    void inorder(bst*);
    void preorder(bst*);
    void postorder(bst*);
    void level();
    int height(bst*);
    void ancestors(int value);
    int whatLevelAmI(int value);
    bst_tree() {
        r = NULL;
    }
};

// Metodo Recursivo que inserta un sub arbol
bst* bst_tree::insert(bst* r, int v) {
    if (r == NULL) { // Si r es nulo , entra, si no , pasa al else
        r = new bst; // Crea un Nodo tipo struct
        r->d = v; //  En el nodo creado guarda el numero dado como "v"
        r->l = NULL; // rama izquierda nula
        r->r = NULL; // rama derecha nula
        return r; // Regresa apuntador r
    }
    else if (v < r->d) { // Si r ya no es nulo,pregunta si el dato recibido es menor que r
        // Datos menores van a la rama izquierda
        r->l = insert(r->l, v);
    }
    else if (v >= r->d) { // Si el dato recibido no es menor , pregunta si es mayor que r
        // Datos mayores van a la rama derecha
        r->r = insert(r->r, v); // Llamada recursiva para que genere un nuevo nodo con el dato ya recibido, y la cuelgue
    } return r;
}

// Complejidad constante O(n)
void bst_tree::preorder(bst* t) {
    if (t == NULL)
        return;
    cout << t->d << " ";
    preorder(t->l);
    preorder(t->r);
}

// Complejidad constante O(n)
void bst_tree::inorder(bst* t) {
    if (t == NULL)
        return;
    inorder(t->l);
    cout << t->d << " ";
    inorder(t->r);
}

// Complejidad lineal O(N)
void bst_tree::postorder(bst* t) {
    if (t == NULL)
        return;
    postorder(t->l);
    postorder(t->r);
    cout << t->d << " ";
}

// Complejidad lineal O(N)
void bst_tree::level(){
    bst* t;
    queue <bst*> toVisit;
    toVisit.push(r);
    while(!toVisit.empty()){
        t = toVisit.front();
        toVisit.pop();
        if(t){
            cout << t->d << " ";
            toVisit.push(t->l);
            toVisit.push(t->r);
        }
    }
    cout << '\n';
}

// Complejidad constante O(n)
int bst_tree::height(bst* t) {
    int h = 0;
    if (t != NULL) {
        int l_height = height(t->l);
        int r_height = height(t->r);
        int max_height = max(l_height, r_height); // Regresa la altura mayor entre las 2 ramas
        h = max_height + 1;
    }
    return h;
}

// Complejidad O(log(N))
void bst_tree::ancestors(int value){
    bst* t = r;
    queue <int> ancestors;
    while(t){
        ancestors.push(t->d);
        if(t->d == value){
            while(!ancestors.empty()){
                cout << ancestors.front() << " ";
                ancestors.pop();
            }
            cout << '\n';
            return;
        }
        if(t->d < value)
            t = t->r;
        else
            t = t->l;
    }
    cout << '\n';
}

// Complejidad O(log(N))
int bst_tree::whatLevelAmI(int value){
    bst* t = r;
    int lvl = 0;
    while(t){
        lvl++;
        if(t->d == value){
            return lvl;
        }
        if(t->d < value)
            t = t->r;
        else
            t = t->l;
    }
    return -1;
}

int main() {
    bst_tree bst;

    // Valores insertados hardcodeados // Caso de prueba
    r = bst.insert(r, 21);
    r = bst.insert(r, 13);
    r = bst.insert(r, 10);
    r = bst.insert(r, 18);
    r = bst.insert(r, 33);
    r = bst.insert(r, 25);
    r = bst.insert(r, 40);
    cout << "Preorder Traversal:" << endl;
    bst.preorder(r);
    cout << '\n';
    cout << "Inorder Traversal:" << endl;
    bst.inorder(r);
    cout << '\n';
    cout << "Postorder Traversal:" << endl;
    bst.postorder(r);
    cout << '\n';
    cout << "Level by Level:" << endl;
    bst.level();
    cout <<"The height of the tree is "<<bst.height(r)<< endl;
    cout << "Ancestors:" << endl;
    bst.ancestors(25);
    cout << "The value is at the level "<< bst.whatLevelAmI(13)<<endl;


    /*int c,i,a,b;
    while (1) {
        cout << "1.Insert Element into the tree" << endl;
        cout << "2.PreOrder traversal" << endl;
        cout << "3.InOrder traversal" << endl;
        cout << "4.PostOrder traversal" << endl;
        cout << "5.Level by level traversal" << endl;
        cout << "6.Get tree height" << endl;
        cout << "7.Get the ancestors of a value" << endl;
        cout << "8.Get the level of a value" << endl;
        cout << "9.Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> c;
        switch (c) {
            case 1:
                cout << "Enter value to be inserted: ";
                cin >> i;
                r = bst.insert(r, i);
                cout << '\n';
                break;
            case 2:
                cout << "Preorder Traversal:" << endl;
                bst.preorder(r);
                cout << endl;
                cout << '\n';
                break;
            case 3:
                cout << "Inorder Traversal:" << endl;
                bst.inorder(r);
                cout << endl;
                cout << '\n';
                break;

            case 4:
                cout << "Postorder Traversal:" << endl;
                bst.postorder(r);
                cout << endl;
                cout << '\n';
                break;

            case 5:
                cout << "Level by Level:" << endl;
                bst.level();
                cout << endl;
                break;

            case 6:
                cout << "Height:" << endl;
                    cout <<"The height of the tree is "<<bst.height(r)<< endl;
                    cout << '\n';
                    break;

            case 7:
                cout << "Ancestors:" << endl;
                cout << "Enter the value you want to know its ancestors: ";
                cin >> a;
                bst.ancestors(a);
                cout << endl;
                cout << '\n';
                break;

            case 8:
                cout << "What level am i:" << endl;
                cout << "Enter the value of which you want to know its level: ";
                cin >> b;
                cout << "The value is at the level "<< bst.whatLevelAmI(b)<<endl;
                cout << '\n';
                break;

            case 9:
                exit(1);
                break;
            default:
                cout << "Wrong Choice" << endl;
                cout << '\n';
        }
    }*/
    return 0;
}