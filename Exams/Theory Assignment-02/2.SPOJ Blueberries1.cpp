/*  OK Knapsack */
#include<bits/stdc++.h>
using namespace std;

int n,k;
int dp[1010][1010];
int bushes[1010];

int blueberries(int limit, int i)
{
    if(i>=n)
    {
        return 0;
    }
    if(dp[i][limit]!=-1)
    {
        return  dp[i][limit];
    }

    int b1=0,b2=0;
    if(limit+bushes[i]<=k)
    {
        b1= bushes[i] + blueberries(limit+bushes[i], i+2);
    }

    b2=blueberries(limit, i+1);

    dp[i][limit] = max(b1,b2);

    return max(b1,b2);
}

int main()
{
    int t, cs=1;
    cin>>t;
    //scanf("%d",&t);

    while(t--)
    {
        cin>>n>>k;
        //scanf("%d %d",&n,&k);

        for(int i=0; i<n; i++)
        {
            cin>>bushes[i];
            //scanf("%d",&bushes[i]);
        }

        memset(dp,-1,sizeof(dp));

        cout << "Scenario #" << cs++ << ": " << blueberries(0,0) << endl;
        //printf("Scenario #%d: %d\n",cs++,blueberries(0,0));
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

2
5 100
50 10 20 40 30
5 87
21 45 30 12 14

*/
