#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;
int n,m;
vector<pair<int,int> >adj[N]; // adjacency list
int mat[N][N]; // adjacency matrix

int main()
{
    cin>>n>>m;

    int u,v,w;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(int i=0;i<n;i++)
    {
        for(auto j:adj[i])
        {
            int v=j.first, w=j.second;
            mat[i][v]=w;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

