#include "floydWarshall.hpp"

int main() {
	// int V, tam; cin>>V>>tam;
	// int INF 99999;
	int graph[V][V] = { { 0, 5, INF, 10 },{ INF, 0, 3, INF },{ INF, INF, 0, 1 },{ INF, INF, INF, 0 } };
    auto start = std::chrono::high_resolution_clock::now();
    floydWarshallAlg(graph);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    double seconds = duration.count();
    std::cout << "Tempo de execução: " << seconds << " segundos" << std::endl;
	return 0;
}