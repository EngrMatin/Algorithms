#include <bits/stdc++.h>
using namespace std;

#define quick std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int M = 1e9 + 7;
const int N = 1e5+5;

int longestp(int i, int j, vector<string> &a, vector<vector<int>> &memoize)
{
    if(memoize[i][j] != -1)
    {
        return memoize[i][j];
    }

    int h = a.size();
    int w = a[0].size();
    int ans = 1;

    for(auto x :{-1,0,1})
    {
        for(auto y:{-1,0,1})
        {
            if(x==0 && y==0){continue;}
            if(i+x<h && i+x>=0 && j+y>=0 && j+y<w && a[i+x][j+y]-a[i][j]==1)
            {
                ans=max(ans,1+longestp(i+x,j+y,a,memoize));
            }
        }
    }

    memoize[i][j]=ans;
    return ans;
}

void solve()
{
    while(true)
    {
        int h,w,ans=0,ct=1;
        cin>>h>>w;
        if(h==0 && w==0)
        {
            break;
        }

        vector<string>a(h);
        vector<vector<int>> memoize(51,vector<int>(51,-1));
        for(int i = 0; i < h; i++)
        {
            cin>>a[i];
        }

        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                if(a[i][j]=='A')
                {
                    ans = max(ans,longestp(i,j,a,memoize));
                }
            }
        }

        cout<<"Case "<<ct<<": "<<ans<<"\n";
    }
}

signed main()
{
    quick int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}
