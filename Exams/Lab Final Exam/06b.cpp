#include <bits/stdc++.h>
using namespace std;

int countWaysToColorTrees(int n)
{
    int prev1 = 0;
    int prev2 = 3;

    for (int i = 2; i <= n; i++)
    {
        int curr1 = prev2;
        int curr2 = prev1 * 2 + prev2;

        prev1 = curr1;
        prev2 = curr2;
    }

    return prev1 + prev2;
}

int main()
{
    int n = 5;

    cout << "Number of ways to color " << n << " trees: " << countWaysToColorTrees(n) << endl;
    return 0;
}
