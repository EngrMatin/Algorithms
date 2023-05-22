#include <bits/stdc++.h>
using namespace std;

int countWaysToColorTrees(int n)
{
    // Initialize variables to keep track of previous color combinations
    int prev1 = 0; // number of ways to color the previous tree with the same color
    int prev2 = 3; // number of ways to color the previous tree with a different color

    // Iterate through each tree and calculate the number of ways to color it
    for (int i = 2; i <= n; i++)
    {
        // Calculate the number of ways to color the current tree using the previous color combinations
        int curr1 = prev2; // The current tree can have the same color as the previous tree with a different color
        int curr2 = prev1 * 2 + prev2; // The current tree can have a different color than the previous tree

        // Update the previous color combinations for the next iteration
        prev1 = curr1;
        prev2 = curr2;
    }

    // The total number of ways to color n trees is the sum of the previous color combinations
    return prev1 + prev2;
}

int main()
{
    int n = 3; // Number of trees
    int numWays = countWaysToColorTrees(n);
    cout << "Number of ways to color " << n << " trees: " << numWays << endl;
    return 0;
}
