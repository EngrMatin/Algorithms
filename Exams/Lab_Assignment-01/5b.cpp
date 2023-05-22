#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> adj[n+1];
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> parent(n+1, -1);
  vector<bool> visited(n+1, false);
  int start = -1, end = -1;

  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      queue<int> q;
      q.push(i);
      visited[i] = true;

      while (!q.empty())
      {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node])
        {
          if (!visited[neighbor])
          {
            q.push(neighbor);
            visited[neighbor] = true;
            parent[neighbor] = node;
          }
          else if (neighbor != parent[node])
          {
            start = node;
            end = neighbor;
            break;
          }
        }

        if (start != -1) break;
      }
    }

    if (start != -1) break;
  }

  if (start == -1)
  {
    cout << "IMPOSSIBLE\n";
  }
  else
  {
    vector<int> path;
    for (int node = end; node != start; node = parent[node])
    {
      path.push_back(node);
    }
    path.push_back(start);
    path.push_back(end);

    cout << path.size() << "\n";
    for (int node : path)
    {
      cout << node << " ";
    }
    cout << "\n";
  }

  return 0;
}

