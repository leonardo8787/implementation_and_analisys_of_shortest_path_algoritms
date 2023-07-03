#include "dijkstra.hpp"

void dijkstraAlg(const vector<vector<pair<int, int>>>& grafo, int tam, int quantidade) {
    vector<int> caminho;
    vector<int> distancias(tam, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> fila;

    distancias[quantidade] = 0;
    fila.push({quantidade, 0});

    while (!fila.empty()) {
        auto p = fila.top();
        fila.pop();
        int vertice = p.first;
        int peso = p.second;

        if (peso > distancias[vertice])
            continue;

        for (const auto& vizinho : grafo[vertice]) {
            int vizinhoVertice = vizinho.first;
            int vizinhoPeso = vizinho.second;
            int novaDistancia = distancias[vertice] + vizinhoPeso;
            if (novaDistancia < distancias[vizinhoVertice]) {
                distancias[vizinhoVertice] = novaDistancia;
                fila.push({vizinhoVertice, novaDistancia});
            }
        }
    }

    for (int i = 1; i <= quantidade; i++) {
        int aux=distancias[i];
        if(i==1)
            aux=0;
        else if(aux==INT_MAX or aux==0) aux=-1;
        cout<<"->"<<aux;
    }
}

