#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> adj[N];
bool visited[N];
int parent[N];

void dfs(int node, int par)
{
    visited[node] = true;
    parent[node] = par;

    for (int i = 0; i < adj[node].size(); i++)
    {
        int neighbor = adj[node][i];
        if (!visited[neighbor])
        {
            dfs(neighbor, node);
        }
        else if (visited[neighbor] && parent[node] != neighbor)
        {
            vector<int> cycle;
            cycle.push_back(neighbor);
            int cur = node;
            while (cur != neighbor)
            {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(neighbor);

            cout << cycle.size() << endl;
            for (int i = cycle.size() - 1; i >= 0; i--)
            {
                cout << cycle[i] << " ";
            }
            exit(0);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1);
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}

/*
Input:
5 6
1 3
1 2
5 3
1 5
2 4
4 5

Output:
4
3 5 1 3

Test Case 1:
Input:
10 20
8 5
6 10
3 6
3 1
8 6
9 10
2 1
6 7
4 3
1 9
3 7
2 6
4 1
2 5
8 4
1 8
10 8
5 4
7 1
7 9

Output:
6
1 3 6 10 9 1

Test Case 2:
Input:
10 20
9 8
9 5
6 4
5 10
7 5
7 8
3 4
6 5
2 1
10 4
6 1
9 7
7 3
4 5
2 9
5 3
2 3
8 5
6 7
3 8

Output:
5
9 8 7 5 9

Test Case 3:
Input:
10 20
7 3
10 5
7 1
3 10
4 7
4 10
6 5
1 5
10 9
9 6
5 4
8 10
7 9
9 4
10 1
8 5
7 8
10 6
9 8
6 3

Output:
5
10 5 6 9 10


Test Case 4:
Input:
10 20
5 9
8 9
9 10
7 1
6 3
9 6
1 3
7 8
1 8
8 6
6 1
3 9
1 9
4 9
8 5
6 10
1 5
3 8
7 2
8 10

Output:
4
8 9 5 8

Test Case 5:
Input:
10 8
3 4
7 8
5 4
6 7
9 8
5 6
3 2
1 2

Output:
IMPOSSIBLE


Test Case 12:
Input:
4 4
1 2
2 3
3 4
2 4

Output:
4
2 3 4 2


Test Case 13:
Input:
4 3
2 3
3 4
2 4

Output:
4
2 3 4 2

Test Case 15:
Input:
5 4
1 2
2 3
1 3
4 5

Output:
4
1 3 2 1

Test Case 17:
Input:
5 4
1 2
3 4
5 4
5 3

Output:
4
3 5 4 3

Test Case 18:
Input:
8 8
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1

Output:
9
1 8 7 6 5 4 3 2 1

Test Case 19:
Input:
5 5
1 2
1 3
2 4
4 3
1 5

Output:
5
1 3 4 2 1

*/
