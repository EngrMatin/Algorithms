/*  OK  */

#include<bits/stdc++.h>
using namespace std;

int n,k;
int dp[1010][1010];
int bushes[1010];

int blueberries(int score, int i)
{
    cout<<"1.score= "<<score<<" i= "<<i<<endl;
    if(i>=n)
    {
        return 0;
    }

    if(dp[i][score] != -1)
    {
        return  dp[i][score];
    }
    cout<<"2.bushes[i]= "<<bushes[i]<<" score= "<<score<<endl;
    int b1=0, b2=0;
    if(score+bushes[i] <= k)
    {
        b1 = bushes[i] + blueberries(score+bushes[i], i+2);
    }
    cout<<"3.bushes[i]= "<<bushes[i]<<" score= "<<score<<endl;
    b2 = blueberries(score, i+1);
    cout<<"4.b1= "<<b1<<" b2= "<<b2<<endl;
    dp[i][score] = max(b1, b2);
    cout<<"5.b1= "<<b1<<" b2= "<<b2<<" dp[i][score]= "<<dp[i][score]<<endl;
    return max(b1,b2);
}

int main()
{
    int t, cs=1;
    cin>>t;

    while(t--)
    {
        cin>>n>>k;

        for(int i=0; i<n; i++)
        {
            cin>>bushes[i];
        }

        memset(dp,-1,sizeof(dp));

        cout << "Scenario #" << cs++ << ": " << endl << blueberries(0,0) << endl;
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

