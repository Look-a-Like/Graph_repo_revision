#include<bits/stdc++.h>

using namespace std;

vector<bool> visited;
queue<int> q;
vector<int> d;

void BFS(int x, vector<int> adj[]) {
    visited[x] = true;
    cout << x << " ";
    d[x] = 0;
    q.push(x);

    while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (auto it : adj[s]) {
            if (!visited[it]) {
                visited[it] = true;
                cout << it << " ";
                d[it] = d[s] + 1;
                q.push(it);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements:";
    cin >> n;

    vector<int> adj[n+1];
    cout << "Enter the edges (enter -1 -1 to stop):" << endl;
    
    int i = 0, j = 0;
    while (i != -1 && j != -1) {
        cin >> i >> j;
        if (i != -1 && j != -1) {
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
    visited.assign(n+1, false);
    d.assign(n+1, 0);
    cout << "Enter the starting vertex for BFS: ";
    int start;
    cin >> start;

    BFS(start, adj);

    return 0;
}
