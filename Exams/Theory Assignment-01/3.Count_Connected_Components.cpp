#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];

vector<int> adj_list[N];

void dfs(int node)
{
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

    int count=0;
    for(int i=0; i<nodes; i++)
    {
       if(visited[i]==0)
       {
           dfs(i);
           count++;
       }
    }

    cout<<"\nNumber of connected components= "<<count<<endl;

    return 0;
}

/*

5 4

1 2
2 3
3 1
4 5


6 4

1 2
2 3
3 1
4 5



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
