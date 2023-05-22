#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tallestBillboard(vector<int>& rods)
    {
        // Initialize a memoization map to store intermediate results
        unordered_map<int, int> memo;
        return helper(rods, 0, 0, 0, memo);
    }

    int helper(vector<int>& rods, int i, int leftSum, int rightSum, unordered_map<int, int>& memo)
    {
        int n = rods.size();

        // Base case: when all rods are processed, check if the left and right sums are equal
        if (i == n) {
            if (leftSum == rightSum) return leftSum; // If left sum is equal to right sum, return either sum
            else return INT_MIN; // Otherwise, return a very small value to indicate invalid result
        }

        int key = (leftSum - rightSum) * 1000 + i; // Generate a unique key for memoization

        // Check if the result for current state is already computed and stored in memo
        if (memo.count(key))
        {
            return memo[key];
        }

        // Three possible scenarios for each rod: put it on the left, put it on the right, or skip it
        int putLeft = helper(rods, i + 1, leftSum + rods[i], rightSum, memo);
        int putRight = helper(rods, i + 1, leftSum, rightSum + rods[i], memo);
        int skip = helper(rods, i + 1, leftSum, rightSum, memo);

        // Choose the maximum height from the three scenarios
        int maxHeight = max(putLeft, max(putRight, skip));

        memo[key] = maxHeight; // Store the result in memo before returning
        return maxHeight;
    }
};

int main()
{
    Solution s;

    // Test case 1
    vector<int> rods1 = {1, 2, 3, 6};
    cout << "Input: rods = [1, 2, 3, 6]" << endl;
    cout << "Output: " << s.tallestBillboard(rods1) << endl;

    // Test case 2
    vector<int> rods2 = {1, 2, 3, 4, 5, 6};
    cout << "Input: rods = [1, 2, 3, 4, 5, 6]" << endl;
    cout << "Output: " << s.tallestBillboard(rods2) << endl;

    // Test case 3
    vector<int> rods3 = {1, 2};
    cout << "Input: rods = [1, 2]" << endl;
    cout << "Output: " << s.tallestBillboard(rods3) << endl;

    return 0;
}
