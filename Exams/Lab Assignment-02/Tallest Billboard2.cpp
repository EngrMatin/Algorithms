
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int f(int i,int diff,vector<int>& rods,int n,vector<vector<int>>& dp)
	{
		if(i==n)
        {
			if(!diff) return 0;
			return -1e9;
		}
		if(dp[i][5000+diff]!=-1) return dp[i][5000+diff];

		int op1=rods[i]+f(i+1,diff+rods[i],rods,n,dp);
		int op2=f(i+1,diff-rods[i],rods,n,dp);
		int op3=f(i+1,diff,rods,n,dp);

		return dp[i][5000+diff]=max(max(op1,op2),op3);
	}

	int tallestBillboard(vector<int>& rods)
	{
		int n=rods.size();
		vector<vector<int>> dp(n,vector<int>(10000,-1));
		return f(0,0,rods,n,dp);
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
