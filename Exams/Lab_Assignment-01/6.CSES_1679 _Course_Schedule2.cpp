#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[100005];
bool visited[100005];
vector<int> v;

void dfs(int node)
{
    if(visited[node])
    {
        return;
    }
    visited[node]=1;
    for(auto i: adj_list[node])
    {
        dfs(i);
    }
    v.push_back(node);
}

int v1[100005];

bool cycle(int node)
{
    v1[node]=1;
    for(auto i: adj_list[node])
    {
        if(!v1[i])
        {
            if(cycle(i))
            {
                return 1;
            }
        }
        else if(v1[i]==1)
        {
            return 1;
        }
    }

    v1[node] = 2;
    return 0;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;

        adj_list[b].push_back(a);
    }

    for(int i=1; i<n+1; i++)
    {
        if(!v1[i] && cycle(i))
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
        if(!visited[i])
        {
            dfs(i);
        }
    }
    for(auto i: v)
    {
        cout<<i<<" ";
    }
    return 0;
}



/*
Input:
5 3
1 2
3 1
4 5

Expected Output:
3 4 1 5 2


*/
