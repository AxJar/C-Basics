//PROGRAMA QUE: Analiza una Bitácora de IPs y trabaja con sus primeros valores para la creación de un Grafo en función de una estructura definida por el profesor.

//PROGRAMADORES: León Emiliano García Pérez (A00573074), Leonardo Luna Flores (A01633305), Axel Jarquín Morga(A01636324).

//FECHA DE ENTREGA: Domingo, Noviembre 21, 2021

//Inclusión de las librerías pertinentes
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <bits/stdc++.h>
#include <fstream>
#include "DoubleLinkedList.h"

//Ajuste a estándar
using namespace std;

//Función que crea un espacio en la consola, no recibe parámetros y no tiene valores de retorno.
void intro(){
    cout<<endl;
}

//Función que solicita el nombre del archivo a trabajar, no tiene valores de entrada y retorna un string con el nombre ingresado.
string nombreArchivo(){
    intro();
    string nombreArchivo;
    cout<<"Ingrese el nombre del archivo a analizar: ";
    cin>>nombreArchivo;
    intro();
    return nombreArchivo;
}

//Definición de estructura Edge con presencia de dos enteros.
struct Edge{
    int src, dest;
};

//Definición de estructura FanOut con presencia de un Edge y un entero.
struct FanOut{
    Edge edge;
    int conexiones;
};

//Definición de estructura NodoMain con presencia de dos enteros.
struct NodoMain{
    int valor, conexion;
};

//Función que imprime datos tipo Edge, recibe un dato tipo Edge de parámetro sin valor de retorno
void imprimeEdges(Edge edge){
    cout<<edge.src<<"-"<<edge.dest<<endl;
}

//Función que imprime datos tipo FanOut, recibe un dato FanOut de parámetro sin valor de retorno
void imprimeFanOut(FanOut FO){
    intro();
    cout<<"Conexión entre "<<FO.edge.src<<" a "<<FO.edge.dest<<" ["<<FO.conexiones<<" conexiones]"<<endl;
    intro();
}

//Función que imprime datos tipo NodoMain,recibe un dato NodoMain de parámetro sin valor de retorno
void imprimeNodoMain(NodoMain nM){
    intro();
    cout<<"Nodo con valor "<<nM.valor<<" ["<< nM.conexion<<" conexiones]"<<endl;
    intro();
}

//Definición de la clase Graph.
class Graph{
public:
    vector<vector<int>> adjList;

    //Constructor de la Clase Graph que recibe un vector de Edges Constante Referenciado y un valor entero.
    Graph(vector<Edge> const& edges, int N){
        adjList.resize(N);
        for (auto& edge : edges){
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};

//Función que implementa el constructor de un Graph que recibe un vector de Edges Constante Referenciado y un valor entero, retorna el Graph construido.
Graph loadGraph(vector<Edge> const& edges, int N){
    Graph graph(edges,N);
    return graph;
}

//Función que implementa el recorrido BFS, recibe un Graph Constante Referenciado, un valor entero y un vector referenciado de booleanos.
void BFS(Graph const& graph, int v, vector<bool>& discovered){ //Complejidad Computacional:  O(v+e), donde v es el número total de vertices y e el número total de edges en el Graph. Se recalca que O(e) puede ir desde O(1) hasta O(v^2) dependiendo de la densidad del Graph.
    queue<int> q;
    discovered[v] = true;
    q.push(v);
    while (!q.empty()){
        v = q.front();
        q.pop();
        cout << v << " ";
        for (int u : graph.adjList[v]){
            if (!discovered[u]){
                discovered[u] = true;
                q.push(u);
            }
        }
    }
}

//Función que implementa de manera simplificada (con menos parámetros) el recorrido BFS, recibe como parámetro un Graph constante referenciado y un entero N, no tiene valor de retorno.
void BFS(Graph const& graph, int N){ //Complejidad Computacional:  O(v+e), donde v es el número total de vertices y e el número total de edges en el Graph. Se recalca que O(e) puede ir desde O(1) hasta O(v^2) dependiendo de la densidad del Graph.
    vector<bool> discoveredB(N, false);
    cout<<"BFS: "<<endl;
    for (int i = 0; i < N; i++) {
        if (!discoveredB[i]) {
            BFS(graph, i, discoveredB);
        }
    }
    intro(); intro();
}

//Función que implementa el recorrido DFS, recibe un Graph Constante Referenciado, un valor entero y un vector referenciado de booleanos.
void DFS(Graph const& graph, int v, vector<bool>& discovered){ //Complejidad Computacional:  O(v+e), donde v es el número total de vertices y e el número total de edges en el Graph. Se recalca que O(e) puede ir desde O(1) hasta O(v^2) dependiendo de la densidad del Graph.
    discovered[v] = true;
    cout << v << " ";
    for (int u : graph.adjList[v]){
        if (!discovered[u])
            DFS(graph, u, discovered);
    }
}

//Función que implementa de manera simplificada (con menos parámetros) el recorrido DFS, recibe como parámetro un Graph constante referenciado y un entero N, no tiene valor de retorno.
void DFS(Graph const& graph, int N){ //Complejidad Computacional:  O(v+e), donde v es el número total de vertices y e el número total de edges en el Graph. Se recalca que O(e) puede ir desde O(1) hasta O(v^2) dependiendo de la densidad del Graph.
    vector<bool> discovered(N);
    cout<<"DFS: "<<endl;
    for (int i = 0; i < N; i++){
        if (!discovered[i])
            DFS(graph, i, discovered);
    }
    intro(); intro();
}

//Función que actualiza el vector de Edges y el valor entero de N, estos anteriores son llamados por referencia en los parámetros de la función, no tiene valor de retorno.
void actualizaEdgesYN(vector<Edge>& edges, int& N){ //Complejidad Computacional: O(n), donde n es el número de líneas que contiene el archivo a analizar. Se recalca que la complejidad puede ir desde O(1) hasta O(n) dependiendo de la longitud del archivo.
    int a, b, valMax;
    string linea, intermediate, bString, nombreArchivo;
    vector <string> tokens;
    nombreArchivo = "bitacoraOrdenada.txt";
    valMax = 0;
    ifstream archivo (nombreArchivo.c_str());
    while(getline(archivo,linea)){
        stringstream check1(linea);
        while(getline(check1, intermediate, '.')){
            tokens.push_back(intermediate);
        }
        bString = tokens[0];
        b = stoi(bString);
        if (b>=1 && b<99){
            a=1;
        } else if (b>=100 && b<199){
            a=10;
        } else if (b>=200 && b<299){
            a=20;
        } else if (b>=300 && b<399){
            a=30;
        } else if (b>=400 && b<499){
            a=40;
        } else if (b>=500 && b<599){
            a=50;
        } else if (b>=600 && b<699){
            a=60;
        } else if (b>=700 && b<799){
            a=70;
        } else if (b>=800 && b<899){
            a=80;
        } else if (b>=900 && b<999){
            a=90;
        }
        if (a>valMax){
            valMax=a;
        } else if (b>valMax){
            valMax=b;
        }
        if(a!=b){
            Edge edgeToPush = {a,b};
            edges.push_back(edgeToPush);
        }
        tokens.clear();
    }
    archivo.close();
    N=valMax+1;
}

//Función que Analiza las Conexiones, recibe como Parámetro el Vector de estas (El vector de Edges) y retorna un vector de FanOuts.
vector<FanOut> analizaConexiones(vector<Edge>& edges){ //Complejidad Computacional: O(n), donde n es la cantidad de elementos presentes dentro del vector. Se recalca que la Complejidad puede ir desde O(1) hasta O(n) dependiendo de la longitud del vector.
    vector <FanOut> conexiones;
    Edge temp;
    int count;
    temp ={0,0};
    count=0;
    for (int i=0;i<=edges.size();i++){
        if(temp.src!=edges[i].src || temp.dest!=edges[i].dest){
            FanOut fanOutToPush={temp,count};
            conexiones.push_back(fanOutToPush);
            count=0;
            temp=edges[i];
            count=1;
        }
        else if(temp.src==edges[i].src && temp.dest==edges[i].dest){
            count++;
        }
    }
    conexiones.erase(conexiones.begin());
    return conexiones;
}

//Función que encuentra los nodos main, los cuales son 1,10,20,30,40,50,60,70,80,90, Recibe un vector de Edges por referencia y tiene como salida un vector de nodos main.
vector<NodoMain> encuentraNodosMain(vector<Edge>& edges){ //Complejidad Computacional: O(n), donde n es la cantidad de elementos presentes dentro del vector. Se recalca que la Complejidad puede ir desde O(1) hasta O(n) dependiendo de la longitud del vector.
    vector <NodoMain> nodosMain;
    int valor,count;
    valor=0;
    count=0;
    for (int i=0;i<=edges.size();i++){
        if(valor!=edges[i].src){
            NodoMain nodoMainToPush{valor,count};
            nodosMain.push_back(nodoMainToPush);
            count=0;
            valor=edges[i].src;
            count=1;
        }
        else if(valor==edges[i].src){
            count++;
        }
    }
    nodosMain.erase(nodosMain.begin());
    return nodosMain;
}

//Función que encuentra el NodoMain con mayor cantidad de conexiones, recibe un Vector de NodoMoain y retorna un NodoMain
NodoMain determinarMayorNM(vector<NodoMain> nodosMain){ //Complejidad Computacional: O(n), donde n es la cantidad de elementos presentes dentro del vector. Se recalca que la Complejidad puede ir desde O(1) hasta O(n) dependiendo de la longitud del vector.
    NodoMain temp{0,0};
    for (int i=0;i<=nodosMain.size();i++){
        if(nodosMain[i].conexion>=temp.conexion){
            temp=nodosMain[i];
        }
    }
    return temp;
}

//Función que imprime los Nodos main, recibe un Vector de NodoMoain y no tiene valor de Retorno.
void imprimeNodosMain(vector<NodoMain>& nodosMain){
    intro();
    for (auto & i : nodosMain){
        cout<<i.valor<<" -> "<< i.conexion<< " conexiones"<<endl;
    }
    intro();
}

//Funcion que imprime las conexiones encontradas y la cantidad de veces encontradas, recibe un vector de fan outs por referencia y no tiene valor de retorno.
void imprimeConexiones(vector<FanOut>& enlaces){ //Complejidad Computacional: O(n), donde n es la cantidad de elementos presentes dentro del vector. Se recalca que la Complejidad puede ir desde O(1) hasta O(n) dependiendo de la longitud del vector.
    intro();
    cout<<"Las conexiones encontradas son las siguientes: "<<endl;
    intro();
    for (int i=0;i<=enlaces.size();i++){
        cout<<enlaces[i].edge.src<<"-"<<enlaces[i].edge.dest<<"  ["<<enlaces[i].conexiones<<" conexiones]"<<endl;
    }
    intro();
}

//Funcion que determina el mayor Fan out, recibe un vector de fan outs por referencia y retorna un fan out como salida.
FanOut determinarFOMayor(vector<FanOut>& enlaces){ //Complejidad Computacional: O(n), donde n es la cantidad de elementos presentes dentro del vector. Se recalca que la Complejidad puede ir desde O(1) hasta O(n) dependiendo de la longitud del vector.
    FanOut maxFO;
    maxFO={{0,0},0};
    for (int i=0;i<=enlaces.size();i++){
        if(enlaces[i].conexiones>=maxFO.conexiones){
            maxFO=enlaces[i];
        }
    }
    return maxFO;
}

//Función main de ejecución del programa, no recibe parámetro y retorna entero 0 al finalizar su ejecución.
int main() {
    //INICIO DE PROGRAMA

    //SE LEÉ BITÁCORA Y SE ORDENA
    string archivo = nombreArchivo();
    DoubleLinkedList listRegistries;
    ifstream is;
    is.open(archivo);
    string str;

    while (getline(is, str)) {
        // El string de cada registro se pasa como argumento a la lista ligada, el string se pasa al constructor dentro de la lista doblemente ligada para inicializar los objetos de RegisterEntry
        listRegistries.insertLast(str);
    }

    //SE ORDENA LA LISTA DE IPS
    listRegistries.mergeSort();

    //SE GUARDA LA LISTA DE IPS ORDENADA
    listRegistries.bitacoraOrdenada(listRegistries);

    //SE CREAN LOS EDGES PARA EL GRAFO
    vector<Edge> edges;
    int N;

    //SE LINKEAN LOS EDGES CON VALORES DEL 2 AL 99 SOBRE EL 1
    //SE LINKEAN DE LOS VALORES 10 LOS 100 A 199, 20 LOS 200 AL 299 Y ASÍ SUCESIVAMENTE
    actualizaEdgesYN(edges,N);

    //SE CREA UN GRAFO
    Graph graph(edges,N);

    //SE DESPLIEGA EL GRAFO RECORRIDO DFS Y BFS
    DFS(graph,N);
    BFS(graph,N);

    //VALORES DE LOS NODOS
    vector<FanOut> conexiones=analizaConexiones(edges);

    //FAN OUT DE CADA NODO - RECORRIDOS
    imprimeConexiones(conexiones);

    //NODO CON MAYOR FAN OUT CON OTRO NODO
    cout<<"El Mayor Fan Out (De UN nodo con OTRO) es el que presenta la...";
    FanOut fanOutMayor = determinarFOMayor(conexiones);
    imprimeFanOut(fanOutMayor);

    //NODOS MAIN
    cout<<"Los Nodos Main dentro de la conceptualización del Grafo presentan...";
    vector<NodoMain> nodosMain=encuentraNodosMain(edges);
    imprimeNodosMain(nodosMain);

    //EL MAYOR NODO MAIN
    cout<<"De los Nodos, el que presenta Mayor Cantidad de Interaccion (Mayor Cantidad de Conexiones con OTROS nodos) es él...";
    NodoMain nodoMainSuperior=determinarMayorNM(nodosMain);
    imprimeNodoMain(nodoMainSuperior);

    //FIN DEL PROGRAMA
    return 0;
}