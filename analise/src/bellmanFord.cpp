#include "bellmanFord.hpp"

void bellmanFordAlg(const vector<vector<pair<int, int>>>& grafo, int tam, int quantidade) {
    vector<int> caminho;
    vector<int> distancias(tam, INT_MAX);
    
    distancias[quantidade-1] = 0;

    for (int i = 1; i <= quantidade; i++) {
        for (int j = 0; j < tam; j++) {
            for (const auto& vizinho : grafo[j]) {
                int vizinhoVertice = vizinho.first;
                int vizinhoPeso = vizinho.second;
                if (distancias[j] != INT_MAX && distancias[j] + vizinhoPeso < distancias[vizinhoVertice])
                    distancias[vizinhoVertice] = distancias[j] + vizinhoPeso;
            }
        }
    }

    bool temCicloNegativo = false;

    for (int i = 1; i <= quantidade; i++) {
        for (int j = 0; j < tam; j++) {
            for (const auto& vizinho : grafo[j]) {
                int vizinhoVertice = vizinho.first;
                int vizinhoPeso = vizinho.second;
                if (distancias[j] != INT_MAX && distancias[j] + vizinhoPeso < distancias[vizinhoVertice]) {
                    temCicloNegativo = true;
                    break;
                }
            }
            if (temCicloNegativo) break;
        }
        if (temCicloNegativo) break;
    }
    
    if (temCicloNegativo)
        cout << "O grafo contém ciclos negativos" << endl;
    else
        cout << "O grafo não contém ciclos negativos" << endl;
    
    // for (int i = 1; i <= quantidade; i++) {
    //     int aux = distancias[i-1]; // Ajuste do índice
    //     if (i == 1){ 
    //         aux = 0;
    //     	cout << "->" << aux;
    //     }else if (aux == INT_MAX || aux == 0){
    //         cout << "->" << "x";
    //     } else {
    //         cout << "->" << aux;
    //     }
    // }
}
