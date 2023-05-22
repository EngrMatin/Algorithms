#include <iostream>
#include <vector>
using namespace std;

void printCombination(vector<int> const &out)      // Function to print the contents of a given array
{
    for (int i: out)
    {
        cout << i << " ";
    }
    cout << endl;
}
                                     // Recursive function to print all combinations of numbers from `i` to `n` having sum `n`
void getCombinations(int i, int n, vector<int> &out)
{
    if (n == 0)                     // if the sum becomes `n`, print the combination
    {
        printCombination(out);
    }
                                    // start from the previous element in the combination till `n`
    for (int j = i; j <= n; j++)
    {
        out.push_back(j);                   // include current element from the combination
        getCombinations(j, n - j, out);     // recur with a reduced sum
        out.pop_back();                     // backtrack: remove the current element from the combination
    }
}

int main()
{
    int n = 5;
    vector<int> out;
    getCombinations(1, n, out);           // recur all combinations of numbers from 1 to `n` having sum `n`

    return 0;
}
