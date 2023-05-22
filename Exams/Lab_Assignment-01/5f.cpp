#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int n, m;
vector<int> adj[MAXN + 5];
int parent[MAXN + 5];
bool visited[MAXN + 5];

pair<int, vector<int>> bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = curr;
                q.push(neighbor);
            } else if (neighbor != parent[curr]) {
                // Found a cycle!
                vector<int> path = {neighbor, curr};
                int u = curr;
                while (u != neighbor) {
                    u = parent[u];
                    path.push_back(u);
                }
                path.push_back(neighbor);
                return {path.size(), path};
            }
        }
    }

    return {0, {}};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            auto [len, path] = bfs(i);
            if (len) {
                cout << len << "\n";
                for (int node : path) {
                    cout << node << " ";
                }
                cout << "\n";
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
