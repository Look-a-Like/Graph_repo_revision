#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    vector<int> adj[n];
    cout<<"Enter the edges(-1 -1 to stop):"<<endl;
    int i=0,j=0;
    while(i!=-1 && j!=-1)
    {
        cin>>i>>j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    
}