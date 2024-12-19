#include<bits/stdc++.h>

using namespace std;

vector<int> colour;
vector<bool> visited;
bool checking_bipartite(vector<int> adj[],int size)
{
    colour[1]=0;
    queue<int> q;
    visited.resize(size,false);
    for(int i=1;i<size;i++){
        if(visited[i]==false){
    q.push(i);
        }
    visited[1]=true;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            visited[it]=true;
            if(colour[it]==-1)
            {
                q.push(it);
                if(colour[node])
                {
                    colour[it]=0;
                }else{
                    colour[it]=1;
                }
            }
            if(colour[it]==colour[node])
            {
                return false;
            }
        }
    }
}
return true;
}

int main()
{
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    vector<int> adj[n+1];
    cout<<"Enter the edges(-1 -1 to stop):"<<endl;
    int i=0,j=0;
    int count=0;
    while(i!=-1 && j!=-1)
    {
        cin>>i>>j;
        adj[i].push_back(j);
        adj[j].push_back(i);
        count++;
    }
    colour.assign(n+1,-1);
    cout<<checking_bipartite(adj,count)<<endl;
}