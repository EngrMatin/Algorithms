#include<bits/stdc++.h>
using namespace std;

const long long N = 1e8 + 5;

long long monsters[N];         // Space complexity: O(n)
long long dp[N];               // Space complexity: O(n)
long long ans;

long long coins(long long n)
{
    if(n == 0)
    {
        return 0;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    if(n == 1)
    {
        dp[n] = monsters[n];
        return monsters[n];
    }

    if(n == 2)
    {
        ans = max(monsters[n], monsters[n-1]);
        dp[n] = ans;
        return ans;
    }

    ans = max(coins(n - 1), coins(n - 2) + monsters[n]);

    dp[n] = ans;
    return ans;
}

int main()
{
    int t;
    cin >> t;

    for (int cs = 1; cs <= t; cs++)       // Time complexity: O(t)
    {
        long long n;
        cin >> n;

        for(int i = 1 ; i <= n ; i++)     // Time complexity: O(n)
        {
            cin >> monsters[i];
        }

        for(int i = 1 ; i <= n ; i++)     // Time complexity: O(n)
        {
            dp[i] = -1;
        }
        cout << coins(n) << endl;
        cout << "Case " << cs << ": " << coins(n) << endl;
    }


    return 0;
}
