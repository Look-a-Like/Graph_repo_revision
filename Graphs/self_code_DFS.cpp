#include<bits/stdc++.h>

using namespace std;

vector<bool> visited;

void DFS(int s,vector<int> adj[])
{
    if(visited[s]) return;
    cout<<s<<" ";
    visited[s]=true;
    for(auto it:adj[s])
    {
        DFS(it,adj);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    vector<int> adj[n+1];
    cout<<"Enter the edges:"<<endl;
    int i=0,j=0;
    while(i!=-1 &&j!=-1)
    {
        cin>>i>>j;
        adj[i].push_back(j);
    }
    visited.assign(n+1,false);
    DFS(1,adj);
    cout<<endl;
}