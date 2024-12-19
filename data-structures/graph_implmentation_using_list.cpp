#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}
void printGraph(vector<int> adj[], int V) {
  for (int d = 0; d < V; ++d) {
    cout << "\n Vertex "<< d << ":";
    for (auto x : adj[d])
    cout << "-> " << x;
    printf("\n");
  }
}

int main() {
  int v;
  cout<<"Enter the number of vertices:";
  cin>>v;
  vector<int> adj[v];
  int j1,j2;
  int check=0;
  while(check==0)
  {
    cin>>j1>>j2;
    if(j1==-1 && j2==-1)
    {
        check=1;
        break;
    }
    if(j1>v || j2>v)
    {
        cout<<"Exceeded the number of edges"<<endl;
        continue;
    }
    addEdge(adj,j1,j2);
  }
  printGraph(adj,v);
}