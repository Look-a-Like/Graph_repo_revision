#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int from, to, weight;
};

void addEdge(vector<vector<Edge>>& graph, int from, int to, int weight) {
    graph[from].push_back({from, to, weight});
}

vector<int> dijkstra(const vector<vector<Edge>>& graph, int s, int ele) {
    int n = graph.size();
    vector<int> d(n, INT_MAX);
    d[s] = 0;
    vector<bool> processed(ele + 1, false);
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (Edge edge : graph[a]) {
            int b = edge.to;
            int w = edge.weight;
            if (d[a] + w < d[b]) {
                d[b] = d[a] + w;
                q.push({-d[b], b});
            }
        }
    }
    return d;
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
    vector<int> dist = dijkstra(graph, 0, n);
    for (int i = 0; i < dist.size()-1; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}
