#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100;

int n, m; // number of vertices and edges
bool visited[MAXN + 1]; // visited[i] is true if node i has been visited
vector<int> adj[MAXN + 1]; // adj[i] stores the neighbors of node i

// add an edge to the graph
void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// find the minimum spanning tree using Prim's algorithm
vector<pair<int, int>> prim() {
    vector<pair<int, int>> mst; // stores the edges in the minimum spanning tree
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // priority queue for choosing edges

    // start from node 1
    visited[1] = true;
    for (int v : adj[1]) {
        pq.push(make_pair(1, v));
    }

    // repeatedly choose the next cheapest edge
    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int u = p.first;
        int v = p.second;
        if (visited[v]) {
            continue;
        }
        visited[v] = true;
        mst.push_back(p);
        for (int w : adj[v]) {
            if (!visited[w]) {
                pq.push(make_pair(v, w));
            }
        }
    }

    return mst;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    // initialize visited array
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    // find the minimum spanning tree
    vector<pair<int, int>> mst = prim();

    // output the edges of the minimum spanning tree
    for (int i = 0; i < n - 1; i++) {
        cout << mst[i].first << " " << mst[i].second << endl;
    }

    return 0;
}
