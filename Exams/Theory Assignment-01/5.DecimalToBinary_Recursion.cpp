#include<bits/stdc++.h>
using namespace std;

string binary = "";

string int_to_binary(int a)
{
    if (a % 2 == 0)
    {
        binary = '0' + binary;
    }
    else
    {
        binary = '1' + binary;
    }

    if(a/2>0)
    {
        int_to_binary(a/2);
    }
    return binary;
}

int main()
{
    int x;
    cin>>x;

    string ans = int_to_binary(x);
    cout<<ans<<endl;

    return 0;
}
