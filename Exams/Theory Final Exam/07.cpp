#include <bits/stdc++.h>
using namespace std;

int brute(int id)
{
    if(id >= n)
    {
        return 0;
    }

    return max({1 + brute(id+1), 2 + brute(id+3), 3 + brute(id+5)});
}

brute(0);
