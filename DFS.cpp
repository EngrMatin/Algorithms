#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];

vector<int> adj_list[N];   //list of vector or array of vector

void dfs(int node)
{
    cout<<node<<" ";
    visited[node] = 1;

//    for(int adj_node: adj_list[node])
//    {
//        if(visited[adj_node] == 0)
//        {
//            dfs(adj_node);
//        }
//    }

    for(int i=0; i<adj_list[node].size(); i++)
    {
        if(visited[adj_list[node][i]] == 0)
        {
            dfs(adj_list[node][i]);
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

    int source = 0;
    dfs(source);

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


6 8

1 5
1 4
5 4
5 0
4 0
0 2
4 2
2 3


*/
