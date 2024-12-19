#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjList;
    vector<vector<int>> revAdjList;

    Graph(int V) : vertices(V), adjList(V), revAdjList(V) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        revAdjList[v].push_back(u);
    }

    vector<unordered_set<int>> findSCCs() {
        vector<int> order;
        vector<bool> visited(vertices, false);

        // Step 1: First pass - fill the order
        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                fillOrder(i, visited, order);
            }
        }

        // Step 2: Reverse the graph

        // Step 3: Second pass - find SCCs
        vector<unordered_set<int>> sccList;
        visited.assign(vertices, false);

        for (int i = order.size() - 1; i >= 0; --i) {
            int vertex = order[i];

            if (!visited[vertex]) {
                unordered_set<int> scc;
                DFSReverse(vertex, visited, scc);
                sccList.push_back(scc);
            }
        }

        return sccList;
    }

private:
    void fillOrder(int vertex, vector<bool>& visited, vector<int>& order) {
        visited[vertex] = true;

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                fillOrder(neighbor, visited, order);
            }
        }

        order.push_back(vertex);
    }

    void DFSReverse(int vertex, vector<bool>& visited, unordered_set<int>& scc) {
        visited[vertex] = true;
        scc.insert(vertex);

        for (int neighbor : revAdjList[vertex]) {
            if (!visited[neighbor]) {
                DFSReverse(neighbor, visited, scc);
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(3, 2);
    g.addEdge(2, 0);
    g.addEdge(3, 4);
    vector<unordered_set<int>> sccList = g.findSCCs();
    cout << "Strongly Connected Components:\n";
    for (const auto& scc : sccList) {
        for (int vertex : scc) {
            cout << vertex << " ";
        }
        cout << "\n";
    }

    return 0;
}
