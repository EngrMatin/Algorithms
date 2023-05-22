#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];

vector<int> adj_list[N];   //list of vector or array of vector

void dfs(int node)
{
    cout<<node<<" ";
    visited[node] = 1;

    for(int adj_node: adj_list[node])
    {
        if(visited[adj_node] == 0)
        {
            dfs(adj_node);
        }
    }
}

int main()
{
    int nodes, edges;
    cin>>nodes>>edges;

    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin>>u>>v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int source = 1;
    dfs(source);

    return 0;
}

/*

no. of nodes = 6
no. of edges = 8


6 8

1 5
1 4
5 4
5 0
4 0
0 2
4 2
2 3

Output: 1 5 4 0 2 3


*/
