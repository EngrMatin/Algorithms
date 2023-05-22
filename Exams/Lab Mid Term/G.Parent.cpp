#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

vector<int> adj[MAXN]; // adjacency list of the tree
int parent[MAXN]; // parent of each node in the tree

bool isParent(int u, int v)
{
    while (v != 0)
    { // iterate up the tree until we reach the root
        if (u == v) return true; // if u is a parent of v, return true
        v = parent[v];
    }
    return false; // if we reach the root and haven't found u, return false
}

int main()
{
    int n, m;
    cin >> n;

    for (int i=1; i<=n; i++)
    {
        cin >> parent[i];

        if (parent[i] != 0)
        { // if i isn't the root
            adj[parent[i]].push_back(i); // add an edge from parent[i] to i
            adj[i].push_back(parent[i]); // add an edge from i to parent[i]
        }
    }

    cin >> m;

    for (int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;

        if(isParent(u, v))
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}

