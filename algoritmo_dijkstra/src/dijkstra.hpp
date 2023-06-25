#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct Compare {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    }
};

void dijkstraAlg(const vector<vector<pair<int, int>>>& grafo, int tam, int quantidade);

#endif