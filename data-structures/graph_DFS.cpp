#include<bits/stdc++.h>

using namespace std;

void addedge(vector<int> adj[],int n,int w)
{
    adj[w].push_back(n);
    adj[n].push_back(w);
}

void DFSUtil(int i,vector<int> adj[],vector<bool> &visited)
{
    visited[i]=true;
    cout<<i<<" ";
    for (int j=0; i<adj[i].size(); j++)
        if (visited[adj[i][j]] == false)
        DFSUtil(adj[i][j], adj, visited);
}

void DFS(vector<int> adj[],int v)
{
    vector<bool> visited;
    visited.resize(v,false);
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            DFSUtil(i,adj,visited);
        }
    }
}


int main()
{
    int v;
    cout<<"Enter the number of vertices in the graph:";
    cin>>v;
    vector<int> adj[v];
    int j1,j2;
    int check=0;
    cout<<"Add edges according start and end(-1 -1 to stop):"<<endl;
    while(check==0)
    {
        cin>>j1>>j2;
        if(j1==-1 && j2==-1)
        {
            check=-1;
            break;
        }
        if(j1>v || j2>v)
        {
            cout<<"That many vertices are not present"<<endl;
            continue;
        }
        addedge(adj,j1,j2);
    }
    DFS(adj,v);
}