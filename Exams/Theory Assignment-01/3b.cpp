#include<bits/stdc++.h>
using namespace std;

bool hasCycle(vector<vector<int>>& adj_list, int nodes)
{
    vector<int> inDegree(nodes, 0);
    for (int i = 0; i < nodes; i++)
    {
        for (auto neighbor : adj_list[i])
        {
            inDegree[neighbor]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < nodes; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        for (auto neighbor : adj_list[node])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    return count != nodes;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> adj_list(nodes);
    for (int i = 0; i < edges; i++)
    {
        int from, to;
        cin >> from >> to;
        adj_list[from].push_back(to);
    }

    if (hasCycle(adj_list, nodes))
    {
        cout << "The graph has a cycle." << endl;
    }
    else
    {
        cout << "The graph does not have a cycle." << endl;
    }

    return 0;
}

