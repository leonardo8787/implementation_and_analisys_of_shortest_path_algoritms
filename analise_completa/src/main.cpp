#include <bits/stdc++.h>
using namespace std;

#include "bellmanFord.hpp"
#include "dijkstra.hpp"
#include "floydWarshall.hpp"

int randomInt(int min, int max);
vector<vector<pair<int, int>>> generateRandomGraph(int tam, int arestas);
void printGraph(const vector<vector<pair<int, int>>>& grafo);
void writeVectorToFile(const vector<pair<string, double>>& data, const string& filename);

int main() {
    int no, tam;
    cin >> no >> tam;
    cout<<"Testar quantas vezes ?"<<" ";
    int tamVezes; cin>>tamVezes;

    vector<vector<pair<int, int>>> grafo = generateRandomGraph(tam, tam);

    printGraph(grafo);

    cout<<endl<<endl<<"============================"<<endl<<endl;
    vector<pair<string, double>> temposDijkstra;
    vector<pair<string, double>> temposBellman;
    vector<pair<string, double>> temposFloyd;
    vector<pair<string, double>> temposTotal;


    cout<<"dijkstra"<<endl;
    for(int i=0; i<tamVezes; i++){
        auto start1 = std::chrono::high_resolution_clock::now();
        dijkstraAlg(grafo, tam, no);
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration1 = end1 - start1;
        double seconds1 = duration1.count();
        std::cout << "Tempo de execução: " << seconds1 << " segundos" << std::endl;
        temposDijkstra.push_back({"dijkstra", seconds1});
    }

    cout<<endl<<"bellmanFord"<<endl;
    for(int i=0; i<tamVezes; i++){
        auto start2 = std::chrono::high_resolution_clock::now();
        bellmanFordAlg(grafo, tam, no);
        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration2 = end2 - start2;
        double seconds2 = duration2.count();
        std::cout << "Tempo de execução: " << seconds2 << " segundos" << std::endl;
        temposBellman.push_back({"bellmanFord", seconds2});
    }

    cout<<endl<<"floydWarshall"<<endl;
    for(int i=0; i<tamVezes; i++){
        auto start3 = std::chrono::high_resolution_clock::now();
        floydWarshallAlg(grafo, tam);
        auto end3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration3 = end3 - start3;
        double seconds3 = duration3.count();
        std::cout << "Tempo de execução: " << seconds3 << " segundos" << std::endl;
        temposFloyd.push_back({"floydWarshall", seconds3});
    }

    writeVectorToFile(temposDijkstra, "temposDijkstra.txt");
    writeVectorToFile(temposBellman, "temposBellman.txt");
    writeVectorToFile(temposFloyd, "temposFloyd.txt");

    long long int somaDijkstra=0;
    long long int somaBellman=0;
    long long int somaFloyd=0;

    for(auto i:temposDijkstra){
        somaDijkstra+=i.second;
        somaDijkstra=somaDijkstra/tamVezes;
    }

    for(auto i:temposFloyd){
        somaFloyd+=i.second;
        somaFloyd=somaFloyd/tamVezes;
    }
    
    for(auto i:temposBellman){
        somaBellman+=i.second;
        somaBellman=somaBellman/tamVezes;
    }

    temposTotal.push_back({"dijkstra", somaDijkstra});
    temposTotal.push_back({"bellmanFord", somaBellman});
    temposTotal.push_back({"floydWarshall", somaFloyd});

    sort(temposTotal.begin(), temposTotal.end());

    cout<<endl<<endl<<"Melhores tempos:";
    for(auto i:temposTotal)
        cout<<" "<<i.first;

    cout<<endl;

    return 0;
}

int randomInt(int min, int max) {
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(min, max);
    return uni(rng);
}

vector<vector<pair<int, int>>> generateRandomGraph(int tam, int arestas) {
    vector<vector<pair<int, int>>> grafo(tam);

    for (int i = 0; i < arestas; i++) {
        int vertice = randomInt(0, tam - 1);
        int aresta = randomInt(0, tam - 1);
        int peso = randomInt(-100, 100);
        grafo[vertice].push_back({aresta, peso});
    }

    return grafo;
}

void printGraph(const vector<vector<pair<int, int>>>& grafo) {
    int tam = grafo.size();
    for (int i = 0; i < tam; i++) {
        for (const auto& aresta : grafo[i]) {
            int vertice = aresta.first;
            int peso = aresta.second;
            cout << "Vertice: " << i << " -> " << vertice << ", Peso: " << peso << endl;
        }
    }
}

void writeVectorToFile(const vector<pair<string, double>>& data, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const auto& item : data) {
            outputFile << item.second << endl;
        }
        outputFile.close();
        cout << "Dados escritos em " << filename << endl;
    } else {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
    }
}