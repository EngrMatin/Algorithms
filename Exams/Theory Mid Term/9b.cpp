vector<vector<pair<int,int>>> adj; // adjacency list of weighted graph
int n; // number of nodes
int source; // source node
vector<int> dist(n, INF); // dist[i] stores the smallest distance from source to node i
vector<int> dist2(n, INF); // dist2[i] stores the 2nd smallest distance from source to node i

void dijkstra() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});
    dist[source] = 0;
    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(dist2[u] < d) continue; // if d is greater than 2nd smallest distance to u, no need to explore further
        for(auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            int new_dist = dist[u] + weight;
            if(new_dist < dist[v]) {
                dist2[v] = dist[v];
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
            else if(new_dist < dist2[v] && new_dist != dist[v]) {
                dist2[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

