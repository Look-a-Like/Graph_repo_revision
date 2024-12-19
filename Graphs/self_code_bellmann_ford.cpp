#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int from, to, weight;
};

void addEdge(vector<Edge>& edges, int from, int to, int weight) {
    edges.push_back({from, to, weight});
}

vector<int> bellmanFord(const vector<Edge>& edges, int numVertices, int start) {
    vector<int> distance(numVertices, INT_MAX);
    distance[start] = 0;

    for (int i = 0; i < numVertices - 1; ++i) {
        for (const Edge& edge : edges) {
            if (distance[edge.from] != INT_MAX && distance[edge.from] + edge.weight < distance[edge.to]) {
                distance[edge.to] = distance[edge.from] + edge.weight;
            }
        }
    }

    // Check for negative cycles
    for (const Edge& edge : edges) {
        if (distance[edge.from] != INT_MAX && distance[edge.from] + edge.weight < distance[edge.to]) {
            // Negative cycle detected
            cerr << "Negative cycle detected!" << endl;
            exit(1);
        }
    }

    return distance;
}

int main() {
    int numVertices;
    cout<<"Enter the number of edges:";
    cin>>numVertices;
    vector<Edge> edges;
    int i=0,j=0,w=0;
    while(i!=-1 && j!=-1 &&w!=-1){
        cout<<"Enter start end weight_-1 -1 -1 to stop):";
        cin>>i>>j>>w;
       if(i!=-1 && j!=-1 && w!=-1)
       {
        addEdge(edges,i,j,w);
       } 
    }
    /*
    addEdge(edges, 0, 1, 5);
    addEdge(edges, 0, 2, 3);
    addEdge(edges, 1, 3, 3);
    addEdge(edges, 1, 4, 2);
    addEdge(edges, 2, 3, 1);
    addEdge(edges, 3, 4, 2);
    addEdge(edges, 0, 3, 7);*/

    int startNode = 0;

    vector<int> shortestPaths = bellmanFord(edges, numVertices, startNode);
    for (int i = 0; i < numVertices; ++i) {
        cout << "Shortest path from " << startNode << " to " << i << ": ";
        if (shortestPaths[i] == INT_MAX)
            cout << "INF";
        else
            cout << shortestPaths[i];
        cout << endl;
    }

    return 0;
}
