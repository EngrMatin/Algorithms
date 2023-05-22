#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n;

    vector<int> parent(n+1, 0);

    for(int i=1; i<=n; i++)
    {
        cin >> parent[i];
    }

    cin >> m;

    while(m--)
    {
        int a, b;
        cin >> a >> b;

        while(b != 0)
        {
            if(a == b)
            {
                cout << 1 << endl;
                break;
            }
            b = parent[b];
        }

        if(b == 0)
        {
            cout << 0 << endl;
        }
    }
    return 0;
}
