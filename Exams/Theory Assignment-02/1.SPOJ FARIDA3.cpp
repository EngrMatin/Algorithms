#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t; // number of test cases

    // Loop for each test case
    for (int case_num = 1; case_num <= t; case_num++) {
        int n;
        cin >> n; // number of monsters for current test case

        // If no monsters, print 0 and continue to the next test case
        if (n == 0) {
            cout << "Case " << case_num << ": " << 0 << endl;
            continue;
        }

        vector<long long> coins(n); // vector to store coins of each monster
        for (int i = 0; i < n; i++) {
            cin >> coins[i]; // input coins for each monster
        }

        // Dynamic programming approach
        // dp[i] stores the maximum number of coins till ith monster
        vector<long long> dp(n);
        dp[0] = coins[0];
        dp[1] = max(coins[0], coins[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + coins[i]);
        }

        cout << "Case " << case_num << ": " << dp[n - 1] << endl;
    }

    return 0;
}
