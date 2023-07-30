#ifndef BELLMANFORD_HPP
#define BELLMANFORD_HPP

#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    }
};

void bellmanFordAlg(const vector<vector<pair<int, int>>>& grafo, int tam, int quantidade);

#endif