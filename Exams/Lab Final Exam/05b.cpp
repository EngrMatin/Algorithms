/* OK */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[n-i-1][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = grid[0][0];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for (int j = 1; j < m; j++)
    {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }

    cout << dp[n-1][m-1] << endl;

    return 0;
}

/*
2 3
3 2 4
1 5 1

2 3
1 5 1
3 2 4


*/
