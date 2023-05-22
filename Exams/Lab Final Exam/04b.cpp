class Solution
{
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k)
  {
     vector<pair<int,int>> adj[n+1];
     vector<int> dis(n+1, 1e4);
     dis[k] = 0;
     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

     for (auto it : times)
     {
         adj[it[0]].push_back({it[1], it[2]});
     }

     pq.push({0, k});

     int ans = 0;
     while (!pq.empty())
     {
        auto it = pq.top();
        pq.pop();

        int distance = it.first;
        int node = it.second;
        for (auto i : adj[node])
        {
           if (distance + i.second < dis[i.first])
           {
               dis[i.first] = distance + i.second;
               pq.push({distance + i.second, i.first});
           }
        }
     }

     for (int i = 1; i <= n; i++)
     {
        if (dis[i] == 1e4)
        {
            return -1;
        }

        ans = max(ans, dis[i]);
     }

     return ans;
  }
};

/*
O( ElogV )

*/
