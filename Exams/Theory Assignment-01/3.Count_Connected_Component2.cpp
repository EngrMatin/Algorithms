#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int node, vector<int> adj[], vector<bool>& visited) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbour : adj[curr])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

int countConnectedComponents(int n, vector<int> adj[]) {
    vector<bool> visited(n, false);
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            count++;
            bfs(i, adj, visited);
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int numComponents = countConnectedComponents(n, adj);

    cout << "Number of connected components: " << numComponents << endl;

    return 0;
}


/*

The program first reads in the number of nodes and edges in the graph from the user.
It then reads in the edges and constructs an adjacency list.
The function countConnectedComponents performs a BFS traversal starting from each unvisited node
and increments the count for each BFS traversal.
Finally, it returns the count of connected components.
The main function calls countConnectedComponents and outputs the result.
Note that this program assumes that the input graph is connected, i.e.,
there is at least one path between any two nodes in the graph.
If the graph is disconnected, this program will only count the number of connected components
in the largest connected component. If you want to count the number of connected components
in all parts of the graph, you'll need to modify the program to handle disconnected graphs.


no. of nodes = 6
no. of edges = 8


6 8

1 5
1 4
5 4
5 0
4 0
0 2
4 2
2 3

Output: 1 5 4 0 2 3


*/
