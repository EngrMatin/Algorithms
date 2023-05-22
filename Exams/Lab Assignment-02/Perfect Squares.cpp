#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
            // Create a vector to store the minimum number of perfect squares needed to sum up to each number from 0 to n
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;               // Zero perfect squares are needed to sum up to 0

                                 // Loop through each number from 1 to n
        for (int i = 1; i <= n; i++)
        {
                                // Loop through each perfect square less than or equal to i
            for (int j = 1; j * j <= i; j++)
            {
                               // Update the minimum number of perfect squares needed to sum up to i
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];          // Return the minimum number of perfect squares needed to sum up to n
    }
};

