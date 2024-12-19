#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of edges:";
    cin>>n;
    vector<int> adj[n+1]; //non-weighted graph
    vector<pair<int,int>> a[n+1];
    int i=0,j=0;
    /*
    cout<<"Enter the edges(-1 -1 to stop:)"<<endl;
    while(i!=-1 && j!=-1)
    {
        cin>>i>>j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }*/
    cout<<"Enter edges with weight(-1 -1 -1 to stop):"<<endl;
    int weight=0;
    while(i!=-1 && j!=-1)
    {
        cin>>i>>j>>weight;
        a[i].push_back({j,weight});
        a[j].push_back({i,weight});
    }
    /*
    cout<<"The adjancency list of the graph"<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<i;
        for(auto it: adj[i])
        {
            cout<<"->"<<it;
        }
        cout<<endl;
    }*/
    cout<<"The adjacency list of graphs with weights:"<<endl;
    for(i=1;i<=n;i++)
    {
        for(auto it: a[i])
        {
            cout<<i<<"->"<<it.first<<" "<<it.second<<" ";
        }
        cout<<endl;
    }
}