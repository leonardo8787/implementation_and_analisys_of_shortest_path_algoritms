#include <bits/stdc++.h>
using namespace std;

int randomInt(int min, int max) {
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(min, max);
    return uni(rng);
}

vector<vector<pair<int, int>>> generateRandomGraph(int n, int m) {
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u = randomInt(0, n - 1); 
        int v = randomInt(0, n - 1);  
        int weight = randomInt(1, 100); 
        graph[u].push_back({v, weight});
    }
    return graph;
}

int main() {
    int n, m; cin>>n>>m;
    vector<vector<pair<int, int>>> graph = generateRandomGraph(n, m);
    for (int i = 0; i < n; i++) {
        for (auto edge : graph[i]) {
            int v = edge.first;
            int weight = edge.second;
            cout<< v <<" "<<i<<" "<< weight<<endl;
        }
    }
    return 0;
}