/* OK Memoization */

#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, k, memo[N][N], bushes[N];

int maxBlueberries(int idx, int rem)
{
    if (idx >= n || rem == 0)
    {
        return 0;
    }

    if (memo[idx][rem] != -1)
    {
        return memo[idx][rem];
    }

    cout<<endl<<"Call: "<<idx+1<<" idx= "<<idx<<"  "<<"rem= "<<rem<<"  "<<"bushes[idx]= "<<bushes[idx]<<endl;

    int ans = maxBlueberries(idx+1, rem);

    cout<<"2.idx= "<<idx<<"  "<<"rem= "<<rem<<"  "<<"bushes[idx]= "<<bushes[idx]<<endl;
    cout<<"2.ans= "<<ans<<endl;

    if (rem >= bushes[idx])
    {
        ans = max(ans, maxBlueberries(idx+2, rem - bushes[idx]) + bushes[idx]);
    }

    cout<<"3.idx= "<<idx<<"  "<<"rem= "<<rem<<"  "<<"bushes[idx]= "<<bushes[idx]<<endl;
    cout<<"3.ans= "<<ans<<endl;

    memo[idx][rem] = ans;

    cout <<"1.memo[idx][rem] ="<< endl;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            cout << memo[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;

    return ans;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        memset(memo, -1, sizeof memo);
        cin >> n >> k;

        for (int j = 0; j < n; j++)
        {
            cin >> bushes[j];
        }

        cout << "Scenario #" << i << ": " << maxBlueberries(0, k) << endl;

        cout <<"2.memo[idx][rem] ="<< endl;
        for(int x = 0; x <= n; x++)
        {
            for(int y = 0; y <= k; y++)
            {
                cout << memo[x][y]<<" ";
            }
            cout << endl;
        }
        cout << endl;
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

