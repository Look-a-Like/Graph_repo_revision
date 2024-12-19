#include <bits/stdc++.h>

using namespace std;


class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    Graph(int vertices) : numVertices(vertices), adjacencyMatrix(vertices, std::vector<int>(vertices, 0)) {}

    void addEdge(int from, int to, int weight) {
        // Assuming a bidirectional graph
        adjacencyMatrix[from][to] = weight;
        adjacencyMatrix[to][from] = weight;
    }
    void fix(int n){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(i!=j && adjacencyMatrix[i][j]==0){
            adjacencyMatrix[i][j]=INT_MAX;
          }
        }
      }
    }
    void printGraph() {
        std::cout << "Weighted Adjacency Matrix:\n";
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
              if(adjacencyMatrix[i][j]==INT_MAX){
                cout<<"INF"<<" ";
              }else{
                std::cout << adjacencyMatrix[i][j] << " ";}
            }
            std::cout << "\n";
        }
    }
};


int main() {
    // Example usage
    int numVertices = 5;
    Graph graph(numVertices);

    // Adding weighted edges
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 4, 1);
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 3, 7);
    graph.addEdge(3, 4, 2);
    graph.addEdge(0, 3, 9);

    graph.fix(5);
    // Printing the weighted adjacency matrix
    graph.printGraph();

    return 0;
}
