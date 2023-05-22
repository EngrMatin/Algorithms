#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, ans = 0;
int a[N], cnt[N];
vector<int> adj[N];

void dfs(int u, int p, int len)
{
    if(a[u])
    {
        len++;
    }
    else
    {
        len = 0;
    }

    if(len>m)
    {
        return;
    }

    if(u!=1 && adj[u].size() == 1)
    {
        ans++;
        return;
    }

    for(int v: adj[u])
    {
        if(v!=p)
        {
            dfs(v, u, len);
        }
    }
}

int main()
{
    cin >>n>> m;

    for(int i=1; i<=n; i++)
    {
        cin >>a[i];
    }

    for(int i=1; i<n; i++)
    {
        int u, v;
        cin >>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);
    cout <<ans<<endl;
    return 0;
}

/*
Explanation:

We start by reading the input: the number of vertices n, the maximum number of consecutive vertices
with cats m, the presence of cats in each vertex a, and the edges of the tree adj.

The idea of the solution is to use a depth-first search (DFS) to traverse the tree and count the
number of leaves that meet the conditions of the problem.

We define a function dfs that takes three parameters: the current vertex u, its parent p, and the
length of the current path len. We initialize len to 0 and increment it if the current vertex
contains a cat (a[u] is 1), or reset it to 0 otherwise. If len exceeds m, we return without
exploring the subtree rooted at u.

If the current vertex u is not the root (i.e., u != 1) and has only one child
(i.e., adj[u].size() == 1), then u is a leaf, and we increment the answer ans.

Finally, we call dfs with the root vertex 1, the parent 0 (which does not exist), and the initial
path length 0. Then we output the answer ans.

Note that the solution has a time complexity of O(n), which is sufficient to pass the given
time limit of 2 seconds for all input sizes.


*/

