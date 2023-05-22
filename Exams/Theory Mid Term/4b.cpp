#include <iostream>
#include <vector>

using namespace std;

void print_combinations(int n, vector<int> curr, int min_val)
{
    if (n == 0)
    {
        for (int i = 0; i < curr.size(); i++)
        {
            cout << curr[i]<< " ";
        }
        cout << endl;
        return;
    }

    for (int i=min_val; i<=n; i++)
    {
        curr.push_back(i);
        print_combinations(n-i, curr, i);
        curr.pop_back();
    }
}

int main()
{
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;

    cout << "Combinations of numbers between 1 and " << n << " having sum " << n << ":" << endl;

    vector<int> curr;

    print_combinations(n, curr, 1);

    return 0;
}
