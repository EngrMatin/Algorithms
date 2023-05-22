#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<int> adj[100005];
int dist[100005];
bool vis[100005];

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
        dist[u] = min(dist[u], dist[v] + 1);
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        vis[i] = false;
    }
    dist[s] = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "Distance from node " << s << " to node " << i << ": ";
        if (dist[i] == INF) {
            cout << "INF\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
    return 0;
}

/*

7 9 0

0 1
0 2
1 3
1 4
3 6
4 6
2 5
5 4
5 6


*/
