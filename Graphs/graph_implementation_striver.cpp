#include<bits/stdc++.h>

using namespace std;

vector<int> BFS(int v,vector<int> adj[])
{
    int vis[v+1]={0};
    vis[0]=1;
    queue<int> q;
    q.push(0);
    vector<int> ans;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }
    }
}

int main()
{
    int v,e;
    cout<<"Enter the number of vertices and edges:";
    cin>>v>>e;
    vector<int>adj[v+1];;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    vector<int> traversal=BFS(v,adj);
    for(auto it: traversal)
    {
        cout<<it<<" ";
    }
    return 0;
}