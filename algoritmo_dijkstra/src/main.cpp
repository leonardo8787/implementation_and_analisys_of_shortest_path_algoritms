#include "dijkstra.hpp"

int main() {
    int no, tam;
    cin >> no >> tam;
    vector<vector<pair<int, int>>> grafo(tam);
    for (int i = 1; i <= tam; i++) {
        int vertice, aresta, peso;
        cin >> vertice >> aresta >> peso;
        grafo[vertice].push_back({aresta, peso});
    }
    dijkstraAlg(grafo, tam, no);
    return 0;
}
