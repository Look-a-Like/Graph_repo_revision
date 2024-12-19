#include <bits/stdc++.h>

using namespace std;

bool isSimpleGraph(const vector<vector<int>>& adjacencyList) {
    int vertices = adjacencyList.size();

    // Check for self-loops
    for (int i = 0; i < vertices; ++i) {
        for (int j : adjacencyList[i]) {
            if (i == j) {
                cout << "Graph is not simple. It contains a self-loop." << endl;
                return false;
            }
        }
    }

    // Check for multiple edges
    unordered_set<int> edgesSet;

    for (int i = 0; i < vertices; ++i) {
        for (int j : adjacencyList[i]) {
            int edgeHash = i * vertices + j;
            if (edgesSet.find(edgeHash) != edgesSet.end()) {
                cout << "Graph is not simple. It contains multiple edges between " << i << " and " << j << "." << endl;
                return false;
            } else {
                edgesSet.insert(edgeHash);
            }
        }
    }

    cout << "Graph is simple." << endl;
    return true;
}

int main() {
    // Example usage:
    vector<vector<int>> adjacencyList = {{1, 2}, {2, 3}, {3}, {0, 1}};

    isSimpleGraph(adjacencyList);

    return 0;
}
