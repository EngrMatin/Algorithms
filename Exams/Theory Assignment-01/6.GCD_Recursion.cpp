#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
     if(a%b == 0)
     {
         return b;
     }
     else
     {
         int remainder = a%b;
         a = b;
         b = remainder;

         gcd(a,b);
     }
}

int main()
{
    int x, y;
    cin>>x>>y;

    int ans = gcd(x, y);
    cout<<ans<<endl;

    return 0;
}
