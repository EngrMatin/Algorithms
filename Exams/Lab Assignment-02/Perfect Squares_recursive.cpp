/* OK */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
                       // Create a memoization map to store the results for previously calculated inputs
        unordered_map<int, int> memo;
        return helper(n, memo);
    }

    int helper(int n, unordered_map<int, int>& memo)
    {
                      // Base case: if n is a perfect square, return 1
        int root = sqrt(n);
        if (root * root == n)
        {
            return 1;
        }

                      // If the result for n is already calculated, return it from memo
        if (memo.find(n) != memo.end())
        {
            return memo[n];
        }

        int minSquares = INT_MAX;
                      // Loop through each perfect square less than or equal to n
        for (int i = 1; i * i <= n; i++)
        {
                      // Recursively calculate the result for n - i*i
            int squares = helper(n - i * i, memo);
                      // Update the minimum number of perfect squares needed to sum up to n
            minSquares = min(minSquares, squares);
        }

                      // Memoize the result for n and return it
        memo[n] = minSquares + 1;
        return minSquares + 1;
    }
};

/*

The time and space complexity of the provided solution is as follows:

Time complexity:
The time complexity of this solution is O(n * sqrt(n)). The loop in the helper function iterates over all perfect squares
from 1 to sqrt(n) and then recursively calls the helper function on the difference between n and each of these squares.
The number of recursive calls is bounded by the number of perfect squares less than or equal to n, which is sqrt(n).
Therefore, the total number of iterations is sqrt(n) * (1 + sqrt(n) + (1 + sqrt(n))^2 + ... + (1 + sqrt(n))^k),
where k is the maximum number of recursive calls. This geometric series can be bounded by O(sqrt(n) * sqrt(n)) = O(n).

Space complexity:
The space complexity of this solution is also O(n). This is because the memoization map can store up to n key-value pairs,
 where the keys are integers less than or equal to n and the values are integers. In the worst case scenario,
 where none of the previous recursive calls have calculated the value for n, the entire map will be filled up with n
 key-value pairs. Therefore, the space complexity of this solution is O(n).

*/
