/*  OK  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<unordered_map<int,int>> dp;
    int tallestBillboard(vector<int>& rods)
    {
        dp.assign(21,{});
        return helper(0, rods, 0);
    }

    int helper(int i, vector<int>& v, int diff)
    {
        if(i==v.size())
        {
            if(diff==0)
            {
                return 0;
            }
            return INT_MIN;
        }

        if(dp[i].find(diff)!= dp[i].end())
        {
            return dp[i][diff];
        }

        int op1 = helper(i+1, v, diff);
        int op2 = v[i] + helper(i+1, v, diff+v[i]);
        int op3 = helper(i+1, v, diff-v[i]);

        return dp[i][diff] = max({op1,op2,op3});
    }
};

int main()
{
    Solution s;

    // Test case 1
    vector<int> rods1 = {1, 2, 3, 6};
    cout << "Input: rods = [1, 2, 3, 6]" << endl;
    cout << "Output: " << s.tallestBillboard(rods1) << endl;

    // Test case 2
    vector<int> rods2 = {1, 2, 3, 4, 5, 6};
    cout << "Input: rods = [1, 2, 3, 4, 5, 6]" << endl;
    cout << "Output: " << s.tallestBillboard(rods2) << endl;

    // Test case 3
    vector<int> rods3 = {1, 2};
    cout << "Input: rods = [1, 2]" << endl;
    cout << "Output: " << s.tallestBillboard(rods3) << endl;

    return 0;
}

/*
'op1' represents the maximum height that can be obtained by not using the current rod
i.e., by skipping the current rod and calling the helper function recursively with the
next index (i+1) and the same 'diff'.

'op2' represents the maximum height that can be obtained by using the current rod on the
positive side of the height difference i.e., by adding the current rod height (v[i]) to
the 'diff', and calling the helper function recursively with the next index (i+1).

'op3' represents the maximum height that can be obtained by using the current rod on the
negative side of the height difference i.e., by subtracting the current rod height (v[i])
from the 'diff', and calling the helper function recursively with the next index (i+1).

Time Complexity:
The time complexity of the solution is O(n * diff), where 'n' is the size of the rods
vector and 'diff' is the maximum possible difference between the heights of the two steel
supports. This is because the solution uses memoization to store the results of subproblems,
and there are 'n' possible values for 'i' and 'diff'.

Space Complexity:
The space complexity of the solution is O(n * diff), as the memoization table 'dp' has
'n' rows (representing 'i') and 'diff' columns, where 'diff' is the maximum possible
difference between the heights of the two steel supports.


*/
