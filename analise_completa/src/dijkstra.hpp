#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <bits/stdc++.h>
using namespace std;

struct CompareD {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    }
};

void dijkstraAlg(const vector<vector<pair<int, int>>>& grafo, int tam, int quantidade);

#endif