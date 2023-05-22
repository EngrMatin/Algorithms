#include<bits/stdc++.h>
using namespace std;

const int N = 1002;
int maze[N][N], visited[N][N];
int level[N][N];
int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};


void bfs(pair<int,int> src)
{
    queue<pair<int,int>> q;
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;

    q.push(src);

    while(!q.empty())
    {
        pair<int,int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for(int i=0; i<4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair<int,int> adj_node = {new_x, new_y};

            if(new_x >= 0 && new_x < n && new_y >= 0 &&  new_y < m
               && maze[new_x][new_y] != -1 && visited[new_x][new_y] == 0)
            {
                visited[new_x][new_y] = 1;
                level[new_x][new_y] = level[x][y] + 1;
                q.push(adj_node);
            }
            else if((new_x == 0 || new_x == n-1 || new_y == 0 ||  new_y == m-1) && maze[new_x][new_y] != '#')
            {
                visited[new_x][new_y] = 1;
                level[new_x][new_y] = level[x][y] + 1;
                //q.push(adj_node);
                return;
            }

        }
    }
}

int main()
{
    cin >> n >> m;
    pair<int,int> src, mnstr, dst;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            maze[i][j] = 0;
            visited[i][j] = 0;
            level[i][j] = -1;
        }
    }

    for(int i=0; i<n; i++)
    {
        string input;
        cin>>input;

        for(int j=0; j<m; j++)
        {
            if(input[j] == '#')
            {
                maze[i][j] = -1;
            }
            else if(input[j] == 'A')
            {
                src = {i, j};
            }
            else if(input[j] == 'M')
            {
                mnstr = {i, j};
                maze[i][j] = -1;
            }
            if(i == 0 || i == n-1 || j == 0 || j == m-1)
            {
                dst = {i,j};
            }
        }
    }


    bfs(src);

    if(level[dst.first][dst.second] == -1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        cout<<level[dst.first][dst.second]<<endl;
    }

    return 0;
}


/*
Input:

5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######


Output:

YES
5
RRDDR


*/

