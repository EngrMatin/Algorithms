#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int dp[n+1][3][3];
    memset(dp, 0, sizeof(dp));

    // Base cases
    dp[1][1][1] = 1;
    dp[1][2][1] = 1;

    for(int i=2; i<=n; i++){
        // Case when we append 1
        dp[i][1][1] = dp[i-1][2][1] + dp[i-1][2][2];
        dp[i][1][2] = dp[i-1][1][1];

        // Case when we append 2
        dp[i][2][1] = dp[i-1][1][1] + dp[i-1][1][2];
        dp[i][2][2] = dp[i-1][2][1];

        // Summing up the cases for k=0,1
        dp[i][1][0] = dp[i-1][1][1] + dp[i-1][1][2];
        dp[i][2][0] = dp[i-1][2][1] + dp[i-1][2][2];
    }

    int ans = dp[n][1][0] + dp[n][2][0];
    cout << ans << endl;

    return 0;
}
