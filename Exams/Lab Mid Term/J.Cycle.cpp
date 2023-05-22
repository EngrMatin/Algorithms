#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n;
int graph[101][101], dist[101][101], parent[101][101];

void find_negative_cycle()
{
    for (int k=1; k<=n; k++)
    {
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }

    for (int k=1; k<=n; k++)
    {
        if (dist[k][k] < 0)
        {
            vector<int> cycle;
            int cur = k;

            for (int i=1; i<=n; i++)
            {
                cur = parent[cur][k];
            }

            int start = cur;
            cycle.push_back(cur);

            while (cur != start || cycle.size() == 1)
            {
                cur = parent[cur][k];
                cycle.push_back(cur);
            }

            reverse(cycle.begin(), cycle.end());

            cout << "YES\n";
            cout << cycle.size() << "\n";
            for (int v : cycle)
            {
                cout << v << " ";
            }
            cout << "\n";

            return;
        }
    }

    cout << "NO\n";
}

int main()
{
    cin >> n;

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            cin >> graph[i][j];

            if (graph[i][j] == 100000)
            {
                dist[i][j] = INF;
            }
            else
            {
                dist[i][j] = graph[i][j];
            }

            parent[i][j] = i;
        }
    }

    find_negative_cycle();

    return 0;
}


