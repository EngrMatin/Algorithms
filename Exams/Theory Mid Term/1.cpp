#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int nodes = 100;
    vector<vector<int>> adj_list(nodes + 2);

    for (int i=2; i<=nodes+1; i++)
    {
        for (int j=i*2; j<=nodes+1; j+=i)
        {
            adj_list[i].push_back(j);
        }
    }


    for (int i=2; i<=nodes+1; i++)
    {
        cout <<i<<": ";
        for (int j: adj_list[i])
        {
            cout <<j<<" ";
        }
        cout << endl;
    }

    return 0;
}

