/* OK */

class Solution
{
public:

    int bestTeamScore(vector<int>& scores, vector<int>& ages)
    {
        int n=scores.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({scores[i],ages[i]});
        }

        sort(v.begin(), v.end());
        vector<vector<int>> dp(n, vector<int>(1010,-1));
        return helper(v, 0, 0, dp);
    }

    int helper(vector<pair<int,int>>&v, int i, int mx, vector<vector<int>>&dp)
    {
        if(i>=v.size())
        {
            return 0;
        }

        if(dp[i][mx]!=-1)
        {
            return dp[i][mx];
        }

        if(v[i].second>=mx)
        {
            int op1 = helper(v, i+1, mx, dp);
            int op2 = v[i].first + helper(v, i+1, v[i].second, dp);
            return dp[i][mx]=max(op1,op2);
        }
        else
        {
            return dp[i][mx]=helper(v, i+1, mx, dp);
        }
    }
};

/*
If the age of the current player is greater than or equal to mx, we can either choose or not choose this player. If we choose this player, then the score we get is v[i].first + helper(v, i+1, v[i].second, dp) (where v[i].first represents the score of the player and v[i].second represents the age of the player). If we do not choose this player, then the score we get is helper(v, i+1, mx, dp). Return the maximum of these two values.
If the age of the current player is less than mx, we cannot choose this player. Return helper(v, i+1, mx, dp).


*/
