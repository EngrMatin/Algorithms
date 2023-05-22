#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // dimensions of the floor

    vector<vector<int>> corns(n, vector<int>(m)); // corns in each tile
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> corns[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m)); // dynamic programming table
    dp[0][0] = corns[0][0]; // base case

    // fill the table row by row
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + corns[i][0];
    }
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j-1] + corns[0][j];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + corns[i][j];
        }
    }

    cout << dp[n-1][m-1] << endl; // maximum number of corns the mouse can take

    return 0;
}
