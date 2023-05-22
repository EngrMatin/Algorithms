 /* OK */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tallestBillboard(vector<int>& rods)
    {
        unordered_map<int, int> dp;
        dp[0] = 0;
        for (int x : rods)
        {
            unordered_map<int, int> cur(dp);
            for (auto it: cur)
            {
                int d = it.first;
                dp[d + x] = max(dp[d + x],cur[d]);
                dp[abs(d - x)] = max(dp[abs(d - x)], cur[d] + min(d, x));
            }
        }
        return dp[0];
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
