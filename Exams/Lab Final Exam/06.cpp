#include <bits/stdc++.h>
using namespace std;

int num_ways(int n, int prev_color)
{
    if (n == 0)
    {
        return 1;
    }

    int count = 0;

    for (int i = 1; i <= 3; i++)      //as number of colors = 3
    {
        if (i != prev_color)
        {
            count += num_ways(n - 1, i);
        }
    }

    return count;
}

int main()
{
    int n = 3;

    int count = num_ways(n, 0);
    cout << "Number of ways to color " << n << " trees: " << count << endl;

    return 0;
}

