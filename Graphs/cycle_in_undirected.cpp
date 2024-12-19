#include<bits/stdc++.h>

using namespace std;

vector<bool> vis;
queue<pair<int,int>> q;

bool checkCyclic(int c,vector<int> adj[])
{

 q.push({c,-1});
    while(!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push({it,node});
            }
            else if(parent!=it)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    vector<int> adj[n+1];
    cout<<"Enter the edges(-1 -1 to stop):"<<endl;
    int i=0,j=0;
    while(i!=-1 && j!=-1)
    {
        cin>>i>>j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    vis.assign(n+1,false);
    cout<<"Checking which of the following elements are in cyclic in the given graph"<<endl;
    bool check=0;
    int nc=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(checkCyclic(i,adj))
            {
                check=1;
                nc++;
                cout<<i<<" ";
            }
        }
    }
    cout<<endl;
    if(check)
    {
        cout<<"There are "<<nc<<" circles"<<endl;
    }else{
        cout<<"There are no circles in the given graph"<<endl;
    }
   
}