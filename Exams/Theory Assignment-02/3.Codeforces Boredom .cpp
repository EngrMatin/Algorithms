#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Read the sequence of integers
    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    // Count the frequency of each integer in the sequence
    unordered_map<int, int> freq;
    for (int num : sequence) {
        freq[num]++;
    }

    // Dynamic programming to find the maximum points
    vector<int> dp(100001); // dp[i] stores the maximum points for the sequence ending at i
    dp[0] = 0;
    dp[1] = freq[1]; // Points earned by choosing only number 1

    for (int i = 2; i <= 100000; i++) {
        // Choose the maximum points between skipping i or choosing i
        dp[i] = max(dp[i - 1], dp[i - 2] + i * freq[i]);
    }

    // Print the maximum points
    cout << dp[100000] << endl;

    return 0;
}

