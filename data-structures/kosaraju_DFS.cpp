#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

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

    void DFS(int vertex, vector<bool>& visited, stack<int>& stack) {
        visited[vertex] = true;

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited, stack);
            }
        }

        stack.push(vertex);
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

    vector<unordered_set<int>> findSCCs() {
        vector<bool> visited(vertices, false);
        stack<int> stack;
        
        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                DFS(i, visited, stack);
            }
        }

        vector<unordered_set<int>> sccList;
        visited.assign(vertices, false);

        while (!stack.empty()) {
            int vertex = stack.top();
            stack.pop();

            if (!visited[vertex]) {
                unordered_set<int> scc;
                DFSReverse(vertex, visited, scc);
                sccList.push_back(scc);
            }
        }

        return sccList;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
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
