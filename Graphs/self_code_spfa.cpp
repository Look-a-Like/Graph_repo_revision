#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

struct Edge {
    int to, weight;
};

void addEdge(vector<vector<Edge>>& graph, int from, int to, int weight) {
    graph[from].push_back({to, weight});
}

vector<int> SPFA(const vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, INF);
    vector<bool> inQueue(n, false);

    distance[start] = 0;
    queue<int> q;
    q.push(start);
    inQueue[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        inQueue[current] = false;

        for (const Edge& e : graph[current]) {
            int newDist = distance[current] + e.weight;
            if (newDist < distance[e.to]) {
                distance[e.to] = newDist;
                if (!inQueue[e.to]) {
                    q.push(e.to);
                    inQueue[e.to] = true;
                }
            }
        }
    }

    return distance;
}

int main() {
    int n;
    cout<<"Enter the edges:";
    cin>>n;
    vector<vector<Edge>> graph(n);
    int i=0,j=0,w=0;
    while(i!=-1 && j!=-1 && w!=-1){
        cout<<"Enter start end weight(-1 -1 -1 to stop):";
        cin>>i>>j>>w;
        if(i!=-1 && j!=-1 && w!=-1){
            addEdge(graph,i,j,w);
        }
    }
    int startNode = 0;

    vector<int> shortestPaths = SPFA(graph, startNode);

    // Output shortest paths
    for (int i = 0; i < n; ++i) {
        cout << "Shortest path from " << startNode << " to " << i << ": ";
        if (shortestPaths[i] == INF)
            cout << "INF";
        else
            cout << shortestPaths[i];
        cout << endl;
    }

    return 0;
}
