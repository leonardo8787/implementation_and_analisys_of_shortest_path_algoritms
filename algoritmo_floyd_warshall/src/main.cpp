#include "floydWarshall.hpp"

int main() {
	// int V, tam; cin>>V>>tam;
	// int INF 99999;
	int graph[V][V] = { { 0, 5, INF, 10 },{ INF, 0, 3, INF },{ INF, INF, 0, 1 },{ INF, INF, INF, 0 } };
	floydWarshallAlg(graph);
	return 0;
}