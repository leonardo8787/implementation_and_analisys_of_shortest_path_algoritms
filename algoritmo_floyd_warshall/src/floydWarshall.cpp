#include "floydWarshall.hpp"

void floydWarshallAlg(const vector<vector<pair<int, int>>>& grafo, int tam) {
    vector<vector<int>> dist(tam, vector<int>(tam, INT_MAX));

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if (i == j)
                dist[i][j] = 0;
            else if (grafo[i][j].second != INT_MAX)
                dist[i][j] = grafo[i][j].second;
        }
    }

    for (int k = 0; k < tam; k++) {
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INT_MAX && dist[i][k] != INT_MAX))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INT_MAX" << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}


