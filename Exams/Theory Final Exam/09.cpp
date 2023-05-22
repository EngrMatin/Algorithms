#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int P = 105;

int n;
double f[N];
int p[N];

int dp[N][P];

int solve(int i, int rem)
{
    if (i == n)
    {
        return 0;
    }

    if (dp[i][rem] != -1)
    {
        return dp[i][rem];
    }

    int ans = solve(i+1, rem);

    int newRem = min(rem, (int) (100.0 - f[i]*100.0));
    if (newRem >= 0)
    {
        ans = max(ans, p[i] + solve(i+1, newRem));
    }
    dp[i][rem] = ans;

    return ans;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i] >> p[i];
    }

    memset(dp, -1, sizeof(dp));

    int ans = solve(0, 100);

    cout << ans << endl;
    return 0;
}
