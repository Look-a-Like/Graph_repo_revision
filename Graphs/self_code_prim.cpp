#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int from, to, weight;
};

void addEdge(vector<vector<Edge>>& graph, int from, int to, int weight) {
    graph[from].push_back({from, to, weight});
}

vector<Edge> prim(const vector<vector<Edge>>& graph, int s, int ele) {
    int n = graph.size();
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<Edge> mst;

    key[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (Edge edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                mst.push_back({u, v, weight});
            }
        }
    }

    return mst;
}

int main() {
    int n;
    cout << "Enter the number of elements:";
    cin >> n;
    vector<vector<Edge>> graph(n + 1);
    int i = 0, j = 0, w = 0;
    cout << "Enter start end weight(-1 -1 -1 to stop):";
    while (i != -1 && j != -1 && w != -1) {
        cin >> i >> j >> w;
        if (i != -1 && j != -1 && w != -1) {
            addEdge(graph, i, j, w);
        }
    }

    vector<Edge> mstEdges = prim(graph, 0, n);

    cout << "Minimum Spanning Tree edges:" << endl;
    for (const auto& edge : mstEdges) {
        cout << edge.from << " " << edge.to << " " << edge.weight << endl;
    }

    return 0;
}
