#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges;
    cin>>nodes>>edges;

    int adj[nodes+1][nodes+1];
    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<nodes; j++)
        {
            adj[i][j] = 0;
        }
    }

    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin>>u>>v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<nodes; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

/*

0 ---- 1 ---- 2 ---- 3
       |      |
       |      |
       5 ---- 4

no. of nodes = 6
no. of edges = 6

list of adj nodes ->

6 6

0 1
1 2
2 3
1 5
2 4
5 4

*/
