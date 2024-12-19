#include<bits/stdc++.h>

using namespace std;

vector<int> parent;

int findSet(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = findSet(parent[v]);
}

void unionSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b)
        parent[b] = a;
}

int main(){
    int n;
    cout<<"Enter the number of nodes:";
    cin>>n;
    vector<vector<int>> adj;
    int i=0, j=0, w=0;
    
    cout<<"Enter start end weight(-1 -1 -1 to stop):"<<endl;
    
    while(i!=-1 && j!=-1 && w!=-1){
        cin>>i>>j>>w;
        if(i!=-1 && j!=-1 && w!=-1){
            adj.push_back({i, j, w});
        }
    }
    sort(adj.begin(), adj.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    vector<vector<int>> mst;
    for (const auto& edge : adj) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        if (findSet(u) != findSet(v)) {
            mst.push_back({u, v, weight});
            unionSets(u, v);
        }
    }
    cout << "Minimum Spanning Tree:" << endl;
    for(const auto& edge : mst){
        cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;
    }

    return 0;
}