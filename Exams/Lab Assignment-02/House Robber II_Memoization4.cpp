/* OK */
class Solution
{
public:
    int dp[105];
    vector<int> num;

    int rob(vector<int>& nums)
    {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        num = nums;
        int ans;
        if(n == 1)
        {
            ans = helper(0, n);
        }
        else
        {
            ans = helper(0, n-1);
            memset(dp, -1, sizeof(dp));
            ans = max(ans, helper(1, n));
            memset(dp, -1, sizeof(dp));
            ans = max(ans, helper(2, n));
        }

        return ans;
    }

    int helper(int idx, int n)
    {
        if(idx >= n)
        {
            return 0;
        }

        if(dp[idx] != -1)
        {
            return dp[idx];
        }

        int ans = num[idx];
        ans = max(ans, num[idx] + helper(idx + 2, n));
        ans = max(ans, num[idx] + helper(idx + 3, n));

        dp[idx] = ans;

        return ans;
    }
};
