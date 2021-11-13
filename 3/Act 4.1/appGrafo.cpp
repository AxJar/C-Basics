#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Se encarga de manejar la fuente y el destino
struct Edge {
    int src, dest;
};

class Graph{
public:
    vector<vector<int>> adjList; //Matriz // Lista de adyacencia
    //https://stackoverflow.com/questions/15999123/const-before-parameter-vs-const-after-function-name-c
    Graph(vector<Edge> const& edges, int N)  // Constructor que mete los datos
    {
        adjList.resize(N); // Establece el tamaño de la lista
        for (auto& edge : edges) // "auto" permite que el compilador infiera que tipo de datos es
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};

// Depth First Search Recursivo
//https://www.techiedelight.com/depth-first-search/
void DFS(Graph const& graph, int v, vector<bool>& discovered)
{
    discovered[v] = true;
    cout << v << " ";
    // do for every edge (v -> u)
    for (int u : graph.adjList[v])
    {
        if (!discovered[u])
            DFS(graph, u, discovered);
    }
}

// Breadth First Search Iterativo
//https://www.techiedelight.com/breadth-first-search/
void BFS(Graph const& graph, int v, vector<bool>& discovered)
{
    queue<int> q;
    discovered[v] = true;
    q.push(v);
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        cout << v << " ";
        // do for every edge (v -> u)
        for (int u : graph.adjList[v])
            if (!discovered[u])
            {
                discovered[u] = true;
                q.push(u);
            }
    }
}

int main(){
    // Se declaran los "caminos" , edges
    vector<Edge> edges = {
            //0 is unconnected node
            {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
            {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}
    };

    int N = 13; // Se declara el tamaño de la lista

    Graph graph(edges, N);

    vector<bool> discovered(N); // Vector de booleanos que nos ayudara a saber si un nodo esta o no esta descubierto

    for (int i = 0; i < N; i++)
        if (!discovered[i])
            DFS(graph, i, discovered);


    std::cout << std::endl;

    vector<bool> discoveredB(N, false);
    for (int i = 0; i < N; i++) {
        if (!discoveredB[i]) {
            BFS(graph, i, discoveredB);
        }
    }

    return 0;
}