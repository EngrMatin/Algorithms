#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int dp[105][10005];

    int helper(vector<int>& arr, int i, int n, int sum)
    {
        if(sum == 0)                // base case
        {
            return 0;
        }

        if(i >= n || sum < 0)
        {
            return INT_MAX - 1000;
        }

        if(dp[i][sum] != -1)        // if already calculated
        {
            return dp[i][sum];
        }

                         // at each ith element we have two options either include or exclude
        int mini = INT_MAX;

        if(arr[i] <= sum)
        {
            mini = min(mini, 1 + helper(arr, i, n, sum - arr[i]));    // inclusion part
        }

        mini = min(mini, helper(arr, i + 1, n, sum));                 // exclusion part

        dp[i][sum] = mini;                                       // store the res in dp

        return mini;
    }

    int numSquares(int n)
    {
        vector<int> arr;

        for(int i = 1; i * i <= n; i++)            // find all the squares between 1 to n
        {
            arr.push_back(i * i);
        }

        memset(dp, -1, sizeof(dp));                // initialize dp with -1

        return helper(arr, 0, arr.size(), n);
    }
};

/*

Time Complexity :- O(N * sqrt(N))

Space Complexity :- O(N * sqrt(N))

*/
