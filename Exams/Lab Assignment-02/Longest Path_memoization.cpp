
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int>parent_list[N];

int dp[N];

int root=1, target_node;

int max_distance(int node)
{
    if(node == root)
    {
        return 0;
    }

    if(dp[node] != -1)
    {
        return dp[node];
    }

    int ans = 0;
    for(int parent: parent_list[node])
    {
        int parent_dist = max_distance(parent);
        ans = max(ans, parent_dist);
    }
    ans++;
    dp[node] = ans;
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++)
    {
        int u, v;
        cin >> u >> v;
        parent_list[v].push_back(u);
    }

    for(int i = 1 ; i <= n ; i++)
    {
        dp[i] = -1;
    }

    cin >> root >> target_node;

    cout<< max_distance(target_node) << endl;

    return 0;
}
