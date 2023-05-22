#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int cs = 1; cs <= t; cs++)   // Time complexity: O(t)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            cout << "Case " << cs << ": " << 0 << endl;
            continue;
        }

        vector<long long> coins(n);    // Space complexity: O(n)
        for (int i = 0; i < n; i++)    // Time complexity: O(n)
        {
            cin >> coins[i];
        }

        vector<long long> dp(n);       // Space complexity: O(n)
        dp[0] = coins[0];
        dp[1] = max(coins[0], coins[1]);

        for (int i = 2; i < n; i++)    // Time complexity: O(n-2) = O(n)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + coins[i]);
        }

        cout << "Case " << cs << ": " << dp[n - 1] << endl;
    }

    return 0;
}

/*
Hence, the time complexity of the above code is O(t)( O(n)+O(n) ) = O(t*n)
and the space complexity is O(t)( O(n)+O(n) ) = O(t*n)
*/

/*

Input:
2
5
1 2 3 4 5
1
10

Output:
Case 1: 9
Case 2: 10

*/



