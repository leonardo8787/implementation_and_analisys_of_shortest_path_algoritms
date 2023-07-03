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
    auto start = std::chrono::high_resolution_clock::now();
    dijkstraAlg(grafo, tam, no);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    double seconds = duration.count();
    std::cout << "Tempo de execução: " << seconds << " segundos" << std::endl;
    return 0;
}
