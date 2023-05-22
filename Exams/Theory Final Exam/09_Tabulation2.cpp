#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate maximum profit using tabulation
int maximizeProfit(vector<pair<float, int>>& ads, int n)
{
    // Sort ads in descending order based on price
    sort(ads.begin(), ads.end(), [](const pair<float, int>& a, const pair<float, int>& b)
    {
        return a.second > b.second;
    });

    // Initialize dp table to store maximum profit for each fraction of the screen
    vector<int> dp(101, 0);

    // Iterate through ads and update dp table
    for (int i = 0; i < n; i++)
    {
        for (int j = 100; j >= ads[i].first * 100; j--)
        {
            dp[j] = max(dp[j], dp[j - ads[i].first * 100] + ads[i].second);
        }
    }

    // Return maximum profit
    return dp[100];
}

int main()
{
    int n;
    cout << "Enter the number of potential ad buyers: ";
    cin >> n;

    vector<pair<float, int>> ads(n);
    cout << "Enter the fraction of the screen and price for each ad buyer:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> ads[i].first >> ads[i].second;
    }

    int maxProfit = maximizeProfit(ads, n);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
