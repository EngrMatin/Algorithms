#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int node)
{
    visited[node] = true;
    for(int i = 0; i < adj[node].size(); i++)
    {
        int v = adj[node][i];
        if(!visited[v])
        {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int connectedComponents = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            connectedComponents++;
            dfs(i);
        }
    }

    cout << "Number of connected components: " << connectedComponents << endl;

    return 0;
}

/*

In this program, we first declare a constant MAXN which represents the maximum number of nodes
in the graph. We also declare a visited array which keeps track of whether a node has been visited
or not during DFS traversal.
Then we define a dfs function which performs DFS traversal of the graph starting from the given node.
It marks the node as visited and recursively visits all its unvisited neighbors.
In the main function, we first read in the number of nodes n and number of edges m in the graph.
We then read in the edges and add them to the adjacency list.
We then initialize a variable connectedComponents to 0 and loop through all the nodes in the graph.
If a node has not been visited, we increment connectedComponents by 1 and perform a DFS traversal
starting from that node.
Finally, we output the number of connected components in the graph.
Note: This program assumes that the nodes are numbered from 1 to n. If the nodes are numbered
differently, the program needs to be modified accordingly.


*/
