#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int tc, cs = 0, n, k, m, t;
    cin>>tc;
    //scanf (" %d", &tc);

    while (tc--)
    {
        cin>>n;
        //scanf (" %d", &n);
        long long dp[2*n+1][2*n+1], i;
        for (i = 0; i <= 2*n; i++)
        {
            dp[i][0] = 0;
            dp[0][i] = 0;
        }

        for (i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cin>>dp[i][j];
                //scanf (" %lld", &dp[i][j]);
            }
        }
        m = n-1;
        for ( ; i < 2*n; i++, m--)
        {
            for (int j = 1; j <= m; j++)
            {
                cin>>dp[i][j];
                //scanf (" %lld", &dp[i][j]);
            }
        }

        for (i = 1; i <= n; i++)
        {
           for (int j = 1; j <= i; j++)
           {
              if (j == i)
              {
                  dp[i][j] += dp[i-1][j-1];
              }
              else
              {
                  dp[i][j] += max (dp[i-1][j-1], dp[i-1][j]);
              }
           }
        }
        m = n-1;
        for ( ; i < 2*n; i++, m--)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] += max (dp[i-1][j], dp[i-1][j+1]);
            }
        }
        cout << "Case " << ++cs << ": " << dp[2*n-1][1] << endl;
        //printf ("Case %d: %lld\n", ++cs, dp[2*n-1][1]);
     }
     return 0;
}

/*
Input:

2
4
7
6 4
2 5 10
9 8 12 2
2 12 7
8 2
10
2
1
2 3
1


Output:

Case 1: 63
Case 2: 5


*/
