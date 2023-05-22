#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void print_combinations(int n, vector<int> curr, set<vector<int>>& seen)
{
    if (n == 0)
    {
        // Base case: the sum is zero, so we print the current combination
        sort(curr.begin(), curr.end());  // sort the combination
        if (seen.count(curr) == 0) // check if the combination has already been seen
        {
            seen.insert(curr);  // add the combination to the set of seen combinations
            cout << "{ ";
            for (int i = 0; i < curr.size(); i++)
            {
                cout << curr[i];
                if (i < curr.size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << " }" << endl;
        }
        return;
    }

    // Recursive case: try all possible values of the next number in the combination
    for (int i = 1; i <= n; i++)
    {
        curr.push_back(i);
        print_combinations(n - i, curr, seen);
        curr.pop_back();
    }
}

int main()
{
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;

    cout << "Combinations of numbers between 1 and " << n << " that add up to " << n << ":" << endl;
    vector<int> curr;
    set<vector<int>> seen;  // set of seen combinations
    print_combinations(n, curr, seen);

    return 0;
}
