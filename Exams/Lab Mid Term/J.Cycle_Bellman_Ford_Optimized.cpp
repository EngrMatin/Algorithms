#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const long long INF = LLONG_MAX;

int n;
long long adj[N][N];
long long dist[N];
int parent[N];
int path[10*N];
int path_length;

bool bellman_ford()
{
    memset(parent, -1, sizeof(parent));
    memset(dist, INF, sizeof(dist));
    dist[1] = 0;

    int last_relaxed = 1;
    for(int i=1; i<=n; i++)
    {
        bool relaxed = false;
        for(int u=1; u<=n; u++)
        {
            for(int v=1; v<=n; v++)
            {
                if(adj[u][v] != INF && dist[u] + adj[u][v] < dist[v])
                {
                    dist[v] = dist[u] + adj[u][v];
                    parent[v] = u;
                    last_relaxed = v;
                    relaxed = true;

                    if(i == n)
                    {
                        int curr = last_relaxed;
                        path_length = 0;
                        path[path_length++] = curr;

                        while(curr != last_relaxed || path_length == 1)
                        {
                            curr = parent[curr];
                            path[path_length++] = curr;
                        }

                        return true;
                    }
                }
            }
        }

        if (!relaxed) break;
    }

    return false;
}

int main()
{
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> adj[i][j];
        }
    }

    if (bellman_ford())
    {
        cout << "YES\n";
        cout << path_length << "\n";
        for (int i=path_length-1; i>=0; i--)
        {
            cout << path[i] <<" ";
        }
        cout << "\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}

/*

Input:

2
0 -1
-1 0

Output:

YES
3
1 2 1




*/
