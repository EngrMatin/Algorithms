#include<bits/stdc++.h>
using namespace std;

bool hasCycleBFS(int V, vector<vector<int>>& adjList)
{
    vector<int> inDegree(V, 0); // array to store in-degree of each vertex
    queue<int> q; // queue to store vertices with in-degree 0

    // calculate in-degree of each vertex
    for(int u = 0; u < V; u++)
    {
        for(int v : adjList[u])
        {
            inDegree[v]++;
        }
    }

    // add vertices with in-degree 0 to the queue
    for(int u = 0; u < V; u++)
    {
        if(inDegree[u] == 0)
        {
            q.push(u);
        }
    }

    // BFS algorithm to detect cycles
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : adjList[u])
        {
            if(--inDegree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    // check if there are any vertices left with non-zero in-degree
    for(int u = 0; u < V; u++)
    {
        if(inDegree[u] != 0)
        {
            return true; // graph contains a cycle
        }
    }

    return false; // graph does not contain a cycle
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adjList(V);
    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    if(hasCycleBFS(V, adjList))
    {
        cout << "Graph contains a cycle" << endl;
    }
    else
    {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}

