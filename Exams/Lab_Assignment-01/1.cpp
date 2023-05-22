#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> adj_list[N];
int visited[N];
int dist[N];

void dfs(int node)
{
    visited[node] = 1;
    for(int adj_node: adj_list[node])
    {
        if(visited[adj_node] == 0)
        {
            dfs(adj_node);
        }

        dist[node] = min(dist[node], dist[adj_node] + 1);
    }
}

int main()
{
    int nodes, edges;
    cin>>nodes>>edges;

    for (int i = 0; i < nodes; i++)
    {
        adj_list[i].clear();
        visited[i] = 0;
        dist[i] = INT_MAX;
    }


    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
    }

    int source;
    cin >> source;

    dist[source] = 0;

    dfs(source);

    for (int i = 0; i < nodes; i++)
    {
        cout << "Distance of node " << i << " from source node " << source << " is " << dist[i] << endl;
    }

    return 0;
}







/*

Input:
4 4

1 3
2 1
4 2
3 4
1

4 4

0 2
1 0
3 1
2 3
0

Rahat Khan Pathan

Input:
7 9

0 1
0 2
1 3
1 4
3 6
4 6
2 5
5 4
5 6
0

7 9

0 1
2 0
1 3
1 4
3 6
4 6
5 2
5 4
6 5
0

Output:
Source - 0
0 - 0
1 - 1
2 - 1
3 - 2
4 - 2
5 - 2
6 - 3

aita ki queue deya solve korle number debe
না

dfs ta ki stack use kore kore jabe? naki recursion use korei korte hobe?
jkono ek vabe korte paren somossha nei

আপনাকে একটা Directed Acyclic Graph (DAG) এর জন্য Single Source Shortest Path (SSSP) বের করতে বলছে DFS ইউজ করে। যেখানে Graph এবং Source ইনপুট হিসেবে নিবেন।
*/
