#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, cnt;
int x[N], y[N], radius[N], visited[N];

bool overlap(int i, int j)
{
    int dx = x[i] - x[j];
    int dy = y[i] - y[j];
    int sum = radius[i] + radius[j];

    return dx*dx + dy*dy <= sum*sum;
}

void dfs(int u)
{
    visited[u] = 1;
    for (int v = 1; v <= n; ++v)
    {
        if (!visited[v] && overlap(u, v))
        {
            dfs(v);
        }
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i] >> y[i] >> radius[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            ++cnt;
            dfs(i);
        }
    }

    cout << cnt << endl;
    return 0;
}
