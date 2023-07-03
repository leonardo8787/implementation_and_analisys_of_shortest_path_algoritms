#ifndef FLOYDWARSHALL_HPP
#define FLOYDWARSHALL_HPP
#include <bits/stdc++.h>
using namespace std;
void printPath(const vector<vector<int>>& predecessores, int origem, int destino);
void floydWarshallAlg(vector<vector<pair<int, int>>>& grafo, int tam);
#endif