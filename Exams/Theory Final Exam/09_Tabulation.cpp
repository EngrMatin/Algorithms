#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; // number of ads
    cin >> n;

    vector<pair<double, int>> ads(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ads[i].first >> ads[i].second;
    }

    vector<vector<int>> dp(n+1, vector<int>(101, 0));
    // dp[i][j] stores the maximum profit for the first i ads with a total price <= j

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            int profit = 0;
            if (j - ads[i-1].second >= 0)
            {
                profit = dp[i-1][j-ads[i-1].second] + (int)(ads[i-1].first*ads[i-1].second);
            }
            dp[i][j] = max(dp[i-1][j], profit);
        }
    }

    cout << dp[n][100] << endl; // maximum profit for a total price of 100
    return 0;
}
