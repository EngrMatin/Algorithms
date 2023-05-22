
#include <iostream>
#include <vector>
using namespace std;

int maxCorns(vector<vector<int>>& floor)
{
    int m = floor.size();
    int n = floor[0].size();

    // Create a 2D vector to store the maximum number of corns that can be collected at each tile
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Fill in the first row and first column of the dp table
    dp[0][0] = floor[0][0];
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = dp[i-1][0] + floor[i][0];
    }
    for (int j = 1; j < n; j++)
    {
        dp[0][j] = dp[0][j-1] + floor[0][j];
    }

    // Fill in the rest of the dp table
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + floor[i][j];
        }
    }

    // Return the maximum number of corns that can be collected
    return dp[m-1][n-1];
}

int main()
{
    vector<vector<int>> floor = {{3, 2, 4},
                                 {1, 5, 1}};
    cout << maxCorns(floor) << endl; // Output: 12
    return 0;
}
