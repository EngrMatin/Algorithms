#include<bits/stdc++.h>
using namespace std;

const int N = 100;

vector<int> adj[N+1];
int dp[N+1], longestPath = 0, endNode = -1;

void dfs(int u)
{
    for(int v : adj[u])
    {
        dfs(v);
    }

    for(int v : adj[u])
    {
        dp[u] = max(dp[u], dp[v] + 1);
    }

    if(dp[u] > longestPath)
    {
        longestPath = dp[u];
        endNode = u;
    }
}

void printPath(int u, vector<int> &path)
{
    path.push_back(u);
    if(dp[u] == 0)
    {
        for(int i=path.size()-1; i>=0; i--)
        {
            cout << path[i];
            if(i > 0) cout << " -> ";
        }
        cout << endl;
    }
    else
    {
        for(int v : adj[u])
        {
            if(dp[v] == dp[u] - 1)
            {
                printPath(v, path);
            }
        }
    }
    path.pop_back();
}

int main()
{
    memset(dp, 0, sizeof(dp));
    for(int i=2; i<=N+1; i++)
    {
        for(int j=2*i; j<=N+1; j+=i)
        {
            adj[i].push_back(j);
        }
    }

    for(int i=2; i<=N+1; i++)
    {
        if(dp[i]==0)
        {
            dfs(i);
        }
    }

    vector<int> path;
    printPath(endNode, path);

    return 0;
}

