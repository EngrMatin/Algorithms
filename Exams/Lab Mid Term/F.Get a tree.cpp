#include <bits/stdc++.h>
using namespace std;

const int N = 105;

vector<int> adj[N];
bool visited[N];

void dfs(int node)
{
    visited[node] = true;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    for (int u = 1; u <= n; u++)
    {
        if (!visited[u])
        {
            continue;
        }

        for (int v : adj[u])
        {
            if (u < v && visited[v])
            {
                cout << u << " " << v << "\n";
            }
        }
    }

    return 0;
}

