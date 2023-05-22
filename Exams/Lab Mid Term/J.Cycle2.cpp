#include <bits/stdc++.h>
using namespace std;

const int INF = 100000;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin >> adj[i][j];

            if (adj[i][j] == -1)
            {
                adj[i][j] = INF;
            }
        }
    }

    vector<int> dist(n, INF);
    vector<int> prev(n, -1);
    int cycle_start = -1;

    for (int k=0; k<n; k++)
    {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (dist[i] + adj[i][j] < dist[j])
                {
                    dist[j] = dist[i] + adj[i][j];
                    prev[j] = i;
                    if (k == n-1)
                    {
                        cycle_start = j;
                    }
                }
            }
        }
    }

    if (cycle_start == -1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";

        vector<int> cycle;
        cycle.push_back(cycle_start);
        int cur = prev[cycle_start];

        while (cur != cycle_start)
        {
            cycle.push_back(cur);
            cur = prev[cur];
        }

        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << '\n';
        for (int v : cycle)
        {
            cout << v + 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}

