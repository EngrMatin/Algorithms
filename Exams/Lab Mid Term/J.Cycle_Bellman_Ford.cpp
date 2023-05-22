#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 100000;

int n;
int adj[N][N];
int dist[N];
int parent[N];
vector<int> cycle;

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
                if(adj[u][v] != INF && dist[u]+adj[u][v] < dist[v])
                {
                    dist[v] = dist[u] + adj[u][v];
                    parent[v] = u;
                    last_relaxed = v;
                    relaxed = true;
                }
            }
        }
        if(!relaxed) break;
    }

    if(parent[last_relaxed] == -1)                  // no negative weight cycle
    {
        return false;
    }
                                                    // construct the cycle
    int curr = last_relaxed;
    cycle.push_back(curr);

    while(parent[curr] != last_relaxed)
    {
        curr = parent[curr];
        cycle.push_back(curr);
    }

    cycle.push_back(last_relaxed);

    return true;
}

int main()
{
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>adj[i][j];
        }
    }

    if(bellman_ford())
    {
        cout<<"YES\n";
        cout<<cycle.size()<<"\n";

        for(int i=0; i<cycle.size(); i++)
        {
            cout<<cycle[i]<<" ";
        }
        cout<<"\n";
    }
    else
    {
        cout<<"NO\n";
    }

    return 0;
}

