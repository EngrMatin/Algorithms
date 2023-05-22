/* OK  Tabulation */

#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int main()
{
    int t, cs=0, n, k;
    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        int bush[n+1];

        for(int i = 1; i <= n; i++)
        {
            cin >> bush[i];
        }

//        cout <<"bush[i]="<< endl;
//        for(int i = 0; i <= n; i++)
//        {
//            cout << bush[i]<<" ";
//        }
//        cout << endl;
//
//        cout <<"1.dp[i][j]="<< endl;
//        for(int i = 0; i <= n; i++)
//        {
//            for(int j = 0; j <= k; j++)
//            {
//                cout << dp[i][j]<<" ";
//            }
//            cout << endl;
//        }
//        cout << endl;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= k; j++)
            {
                if(i == 1)
                {
                    if(j < bush[i])
                    {
                        dp[i][j] = 0;
                    }
                    else
                    {
                        dp[i][j] = bush[i];
                    }
                }
                else
                {
                    if(j < bush[i])
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i-1][j], bush[i] + dp[i-2][j-bush[i]]);
                    }
                }
            }
        }

        cout << "Scenario #" << ++cs << ": " << dp[n][k] << endl;

//        cout <<"2.dp[i][j]="<< endl;
//        for(int i = 0; i <= n; i++)
//        {
//            for(int j = 0; j <= k; j++)
//            {
//                cout << dp[i][j]<<" ";
//            }
//            cout << endl;
//        }
//        cout << endl;
    }

    return 0;
}

/*

Input:
2
5 100
50 10 20 30 40
5 87
21 45 30 12 14

Output:
Scenario #1: 90
Scenario #2: 65

1
5 100
50 10 20 30 40

2
5 100
50 10 20 40 30
5 87
21 45 30 12 14

*/

/*
Explanation:

The input consists of the number of test cases t, followed by t cases.
For each case, we have the number of bushes n, the maximum number of
blueberries k, and an array bush representing the number of blueberries
in each bush.
We use a two-dimensional dp array to store the maximum number of blueberries
we can pick up to a certain point j with a limit of l blueberries.
dp[j][l] represents the maximum number of blueberries we can pick up to
bush j with a limit of l blueberries.
We use a bottom-up approach to fill in the dp array.
We start from the base cases, where if there is only one bush,
the maximum number of blueberries we can pick is either the number of
blueberries in the bush if it is less than or equal to the limit or 0
if it is greater than the limit. If there are more than one bushes,
    we have two options: either we pick the j-th bush or we don't pick it.
    If we pick it, we add the number of blueberries in the j-th bush to
    the maximum number of blueberries we can pick up to the (j-2)-th bush
    with a limit of (l - the number of blueberries in the j-th bush).
    If we don't pick it, the maximum number of blueberries we can pick up
    to the j-th bush with a limit of l is the same as the maximum number
    of blueberries we can pick up to the (j-1)-th bush with a limit of l.
    We take the maximum of these two options as the maximum number of
    blueberries we can pick up to the j-th bush with a limit of l.
Finally, we output the result for each test case as "Scenario #i: "
followed by the maximum number of blueberries we can pick.

*/
