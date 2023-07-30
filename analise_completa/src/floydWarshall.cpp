#include "floydWarshall.hpp"

void printPath(const vector<vector<int>>& predecessores, int origem, int destino) {
    if (predecessores[origem][destino] == -1) {
        cout << "Caminho não encontrado." << endl;
        return;
    }

    vector<int> caminho;
    int atual = origem;
    caminho.push_back(atual);

    while (atual != destino) {
        atual = predecessores[atual][destino];
        caminho.push_back(atual);
    }

    cout << "Caminho mínimo entre " << origem << " e " << destino << ": ";
    for (std::vector<int>::size_type i = 0; i < caminho.size(); i++) {
        cout << caminho[i];
        if (i != caminho.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
}


void floydWarshallAlg(vector<vector<pair<int, int>>>& grafo, int tam) {
    vector<vector<int>> distancias(tam, vector<int>(tam, numeric_limits<int>::max()));
    vector<vector<int>> predecessores(tam, vector<int>(tam, -1));

    for (int i = 0; i < tam; i++) {
        distancias[i][i] = 0;
        for (const auto& aresta : grafo[i]) {
            int vertice = aresta.first;
            int peso = aresta.second;
            distancias[i][vertice] = peso;
            predecessores[i][vertice] = i;
        }
    }

    for (int k = 0; k < tam; k++) {
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                if (distancias[i][k] != numeric_limits<int>::max() &&
                    distancias[k][j] != numeric_limits<int>::max() &&
                    distancias[i][k] + distancias[k][j] < distancias[i][j]) {
                    distancias[i][j] = distancias[i][k] + distancias[k][j];
                    predecessores[i][j] = predecessores[k][j];
                }
            }
        }
    }

    // for (int i = 0; i < tam; i++) {
    //     for (int j = 0; j < tam; j++) {
    //         if (distancias[i][j] == numeric_limits<int>::max()) {
    //             cout << "INF ";
    //         } else {
    //             cout << distancias[i][j] << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i < tam; i++) {
    //     for (int j = 0; j < tam; j++) {
    //         if (i != j) {
    //             printPath(predecessores, i, j);
    //         }
    //     }
    // }
}



