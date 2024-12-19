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

    void fix(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && adjacencyMatrix[i][j] == 0) {
                    adjacencyMatrix[i][j] = INT_MAX;
                }
            }
        }
    }

    void printGraph() {
        std::cout << "Weighted Adjacency Matrix:\n";
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (adjacencyMatrix[i][j] == INT_MAX) {
                    cout << "INF"
                         << " ";
                } else {
                    std::cout << adjacencyMatrix[i][j] << " ";
                }
            }
            std::cout << "\n";
        }
    }

    vector<vector<int>> floyd_warshall(int n) {
        vector<vector<int>> distance(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    distance[i][j] = 0;
                } else if (adjacencyMatrix[i][j]) {
                    distance[i][j] = adjacencyMatrix[i][j];
                } else {
                    distance[i][j] = INT_MAX;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    distance[j][k] = min(distance[j][k], distance[j][i] + distance[i][k]);
                }
            }
        }
        return distance;
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
    vector<vector<int>> d = graph.floyd_warshall(numVertices);
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (d[i][j] == INT_MAX) {
                cout << "INF"
                     << " ";
            } else {
                cout << d[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
