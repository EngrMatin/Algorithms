#include <bits/stdc++.h>
using namespace std;

struct Circle
{
    int x;
    int y;
    int r;
};

bool doOverlap(Circle c1, Circle c2)
{
    int distSq = (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
    int radSumSq = (c1.r + c2.r) * (c1.r + c2.r);
    return distSq <= radSumSq;
}

void DFS(int node, vector<int> adj[], vector<bool>& visited)
{
    visited[node] = true;
    for(int i = 0; i < adj[node].size(); i++)
    {
        int child = adj[node][i];
        if(!visited[child])
        {
            DFS(child, adj, visited);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<Circle> circles(n);
    for(int i = 0; i < n; i++)
    {
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }

    vector<int> adj[n];
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(doOverlap(circles[i], circles[j]))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<bool> visited(n, false);
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            DFS(i, adj, visited);
            count++;
        }
    }

    cout << count << endl;
    return 0;
}

/*
Input:
3
0 0 3
3 3 2
-3 3 2

Output:
1


Input:
4
1 1 2
3 3 2
-4 4 2
-6 6 2

Output:
2

*/

/*
Explanation:

We start by reading the input, which consists of the number of circles, followed by the x, y, and radius of each circle. We store each circle as a structure that contains its x, y, and radius values.

Next, we create an adjacency list to represent the graph of circle groups. We iterate through all pairs of circles and check if they overlap using the doOverlap function. If they overlap, we add an edge between the corresponding vertices in the adjacency list.

Once we have constructed the adjacency list, we perform a DFS traversal starting from each unvisited vertex to count the number of connected components in the graph. We keep track of the visited vertices using a boolean vector, and increment the count every time we start a new DFS traversal.

Finally, we output the count, which represents the number of circle groups in the input.

The time complexity of this solution is O(n^2), where n is the number of circles, due to the nested loop used to create the adjacency list. The space complexity is also O(n^2) due to the adjacency list. However, in practice, the number of circle groups is likely to be much smaller than n, so this solution should be efficient for most inputs.

*/
