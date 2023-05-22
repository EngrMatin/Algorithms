#include <iostream>
#include <vector>

using namespace std;

void print_combinations(int n, vector<int> curr)
{
    if (n == 0)
    {
        for (int x : curr)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    // Recursive case: try all possible values of the next number in the combination
    for (int i=1; i<=n; i++)
    {
        curr.push_back(i);
        print_combinations(n-i, curr);
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

    print_combinations(n, curr);

    return 0;
}
