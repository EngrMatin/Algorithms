#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sequence[i];
    }

    unordered_map<int, int> freq;
    for (int num : sequence)
    {
        freq[num]++;
    }

    vector<long long> dp(100001);
    dp[0] = 0;
    dp[1] = (long long)freq[1];

    for (int i = 2; i <= 100000; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + (long long)i * freq[i]);
    }

    cout << dp[100000] << endl;

    return 0;
}

