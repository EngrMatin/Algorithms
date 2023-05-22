/* OK */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> graph[N];
int dp[N];

int dfs(int u)
{
    if (dp[u] != -1)
    {
        return dp[u];
    }

    dp[u] = 0;

    for (int v : graph[u])
    {
        dp[u] = max(dp[u], dfs(v) + 1);
    }

    return dp[u];
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
    }

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dfs(i));
    }

    cout << ans << endl;

    return 0;
}

/*
Explanation:

The problem is asking us to find the length of the longest directed path in a given directed
acyclic graph (DAG). One way to solve this problem is to use dynamic programming with memoization.
We can define dp[i] as the length of the longest directed path starting from vertex i. We can then
use a top-down approach and recursively calculate dp[i] for all vertices i.

To avoid recomputing the same values multiple times, we can use memoization. We initialize all
dp[i] values to -1, which indicates that they have not been calculated yet. When we calculate dp[i],
we first check if it has already been calculated (i.e., dp[i] != -1). If it has, we simply return
the precomputed value. Otherwise, we calculate dp[i] by iterating over all outgoing edges
(i.e., neighbors) of vertex i and taking the maximum of their corresponding dp values plus 1.

Once we have computed all dp[i] values, we can simply take the maximum value among them as the answer.

The time complexity of this solution is O(n + m), where n is the number of vertices and m is the
number of edges in the graph. The space complexity is also O(n + m),
since we need to store the graph and the dp array.
*/
