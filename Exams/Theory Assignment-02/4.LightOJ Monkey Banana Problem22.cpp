#include <bits/stdc++.h>
using namespace std;

const int N = 105;
long long dp[N][N];

long long solve(int row, int col, int n, const vector<vector<int>>& arr)
{
    if (row == 2 * n - 1)
    {
        return 0;
    }
    if (col < 0)
    {
        return 0;
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    long long ans = arr[row][col];

    if (row < n - 1)
    {
        ans += max(solve(row + 1, col, n, arr), solve(row + 1, col + 1, n, arr));
    }
    else
    {
        ans += max(solve(row + 1, col, n, arr), solve(row + 1, col - 1, n, arr));
    }

    dp[row][col] = ans;
    return ans;
}

int main()
{
    int t;
    cin >> t;

    int cs = 0;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> arr(2 * n - 1, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> arr[i][j];
            }
        }

        int m = n - 1;
        for (int i = n; i < 2 * n - 1; i++, m--)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        cout<<"dp[i][j]="<<endl;
        for (int i = 0; i <= 2*n; i++)
        {
            for (int j = 0; j <= 2*n; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

        cout<<"arr[i][j]="<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout<< arr[i][j]<<" ";
            }
            cout<<endl;
        }

        m = n - 1;
        for (int i = n; i < 2 * n - 1; i++, m--)
        {
            for (int j = 0; j < m; j++)
            {
                cout<< arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

        memset(dp, -1, sizeof(dp));

        cout<<"dp[i][j]="<<endl;
        for (int i = 0; i <= 2*n; i++)
        {
            for (int j = 0; j <= 2*n; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

        cout << "Case " << ++cs << ": " << solve(0, 0, n, arr) << endl;

        cout<<"dp[i][j]="<<endl;
        for (int i = 0; i <= 2*n; i++)
        {
            for (int j = 0; j <= 2*n; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

        cout<<"arr[i][j]="<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout<< arr[i][j]<<" ";
            }
            cout<<endl;
        }

        m = n - 1;
        for (int i = n; i < 2 * n - 1; i++, m--)
        {
            for (int j = 0; j < m; j++)
            {
                cout<< arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
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

1
4
7
6 4
2 5 10
9 8 12 2
2 12 7
8 2
10

*/


