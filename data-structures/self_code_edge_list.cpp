#include<bits/stdc++.h>

using namespace std;

int main()
{
    cout<<"Enter the numeber of edges:";
    int n;
    cin>>n;
    vector<pair<int,int>> edges(n,{0,0});
    cout<<"Enter edges:"<<endl;
    int i=0,j=0;
    while(i!=-1 && j!=-1)
    {
        cin>>i>>j;
        edges.push_back({i,j});
    }
    cout<<"All the edges in the graph as given:"<<endl;
    for(auto it:edges)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
}