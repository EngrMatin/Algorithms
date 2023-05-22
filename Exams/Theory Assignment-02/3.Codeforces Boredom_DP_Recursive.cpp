#include <bits/stdc++.h>
using namespace std;

vector<int> sequence;
vector<long long> dp;

long long solve(int idx, unordered_map<int, int>& freq)
{
    if (idx <= 0)
    {
        return 0;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    long long score = (long long)idx * freq[idx];

    long long option1 = solve(idx - 1, freq);
    long long option2 = solve(idx - 2, freq) + score;

    return dp[idx] = max(option1, option2);
}

int main()
{
    int n;
    cin >> n;

    sequence.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sequence[i];
    }

    unordered_map<int, int> freq;
    for (int num : sequence)
    {
        freq[num]++;
    }

    dp.resize(100001, -1);
    dp[0] = 0;
    dp[1] = (long long)freq[1];

    cout << solve(100000, freq) << endl;

    return 0;
}
