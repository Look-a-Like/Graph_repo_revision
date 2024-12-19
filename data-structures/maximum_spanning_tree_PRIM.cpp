#include <iostream>
#include <list>
#include <climits>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>>* adj;

public:
    explicit Graph(int V);
    void addEdge(int u, int v, int w);
    void primMST();
    int maxKey(const int key[], const bool mstSet[]) const;
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

int Graph::maxKey(const int key[], const bool mstSet[]) const {
    int max = INT_MIN, max_index;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] > max) {
            max = key[v];
            max_index = v;
        }
    }
    return max_index;
}

void Graph::primMST() {
    int* parent = new int[V];
    int* key = new int[V];
    bool* mstSet = new bool[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MIN;  // Initialize with INT_MIN for maximum spanning tree
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = maxKey(key, mstSet);
        mstSet[u] = true;

        for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = it->first;
            int weight = it->second;
            if (!mstSet[v] && weight > key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << key[i] << endl;
    }
}

int main() {
    int V = 4;
    Graph g(V);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 3, 3);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 5);

    g.primMST();

    return 0;
}
