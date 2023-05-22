#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int INF = 1e9;

int dijkstra_2nd_shortest_path(vector<vector<pair<int, int>>>& graph, int source, int destination)
{
    vector<int> dist(graph.size(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    set<int> visited;

    // initialize distances and priority queue
    dist[source] = 0;
    pq.push(make_pair(0, source));

    // Dijkstra's algorithm
    while (!pq.empty())
    {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();

        if (u == destination)
        {
            break;
        }

        visited.insert(u);

        for (auto& vw : graph[u])
        {
            int v = vw.first, w = vw.second;

            if (visited.find(v) == visited.end())
            {
                int alt = dist[u] + w;
                if (alt < dist[v])
                {
                    dist[v] = alt;
                    pq.push(make_pair(alt, v));
                }
            }
        }
    }

    // remove the first shortest path from the graph
    pair<int, int> removed_edge = make_pair(-1, -1);

    for (int u : visited)
    {
        for (auto& vw : graph[u])
        {
            int v = vw.first, w = vw.second;

            if (dist[u] + w == dist[v] && make_pair(u, v) != removed_edge)
            {
                graph[u].erase(vw);
                removed_edge = make_pair(u, v);
                break;
            }
        }
    }

    // re-run Dijkstra's algorithm to get the 2nd shortest path
    dist.assign(graph.size(), INF);
    visited.clear();
    pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();

    dist[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();

        if (u == destination)
        {
            break;
        }

        visited.insert(u);

        for (auto& vw : graph[u])
        {
            int v = vw.first, w = vw.second;

            if (visited.find(v) == visited.end())
            {
                int alt = dist[u] + w;
                if (alt < dist[v])
                {
                    dist[v] = alt;
                    pq.push(make_pair(alt, v));
                }
            }
        }
    }

    return dist[destination];
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++)
    {
        char u, v;
        int w;
        cin >> u >> v >> w;

        graph[u - 'A'].push_back(make_pair(v - 'A', w));
        graph[v - 'A'].push_back(make_pair(u - 'A', w));
    }

    int source = 'A' - 'A';
    int destination = 'D' - 'A';
    int shortest_dist = dijkstra_2nd_shortest_path(graph, source, destination);

    cout << "2nd shortest distance from A to D is: " << shortest_dist << endl;

    return 0;
}

