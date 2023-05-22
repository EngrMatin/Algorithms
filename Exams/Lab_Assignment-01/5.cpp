#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N];
int visited[N], parent[N];

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    parent[node] = -1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int i = 0; i < adj[v].size(); i++)
        {
            int w = adj[v][i];
            if (!visited[w])
            {
                visited[w] = 1;
                q.push(w);
                parent[w] = v;
            }
            else if (parent[v] != w)
            {
                vector<int> cycle;
                cycle.push_back(w);
                int x = v;
                while (x != w)
                {
                    cycle.push_back(x);
                    x = parent[x];
                }
                cycle.push_back(w);

                cout << cycle.size() << endl;
                for (int i = cycle.size()-1; i >= 0; i--)
                {
                    cout << cycle[i] << " ";
                }
                exit(0);
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bfs(i);
        }
    }

    return 0;
}
