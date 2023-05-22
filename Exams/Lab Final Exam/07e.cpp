#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 100005;
const int MOD = 1e9+7;

int dp[MAXN][3];

int main() {
    int n;
    cin >> n;

    memset(dp, 0, sizeof(dp));

    dp[1][0] = dp[1][1] = dp[1][2] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
    }

    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD << endl;

    return 0;
}
