#include<bits/stdc++.h>
using namespace std;

string int_to_binary(int decimal)
{
    string binary = "";
    while (decimal > 0)
    {
        if (decimal % 2 == 0)
        {
            binary = '0' + binary;
        }
        else
        {
            binary = '1' + binary;
        }
        decimal /= 2;
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
