#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5+5;
vector<int> adj[N];
int visited[N], parent[N];
int n,m;

bool bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    parent[src] = -1;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it: adj[node])
        {
            if(!visited[it])
            {
                visited[it] = 1;
                parent[it] = node;
                q.push(it);
            }
            else if(it!=parent[node])
            {
                vector<int> v;
                v.push_back(node);
                while(node!=it)
                {
                    node = parent[node];
                    v.push_back(node);
                }
                v.push_back(it);
                cout<<v.size()<<endl;
                for(auto i: v) cout<<i<<" ";
                return true;
            }
        }
    }
    return false;
}

signed main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(bfs(i))
            {
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}

