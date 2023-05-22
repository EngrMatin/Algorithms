#include <bits/stdc++.h>
using namespace std;

struct Cell
{
    int x, y, dist;
};

bool isInsideBoard(int x, int y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

int shortestPath(int srcX, int srcY, int dstX, int dstY)
{
    const int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    const int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    vector<vector<bool>> visited(8, vector<bool>(8, false));

    queue<Cell> q;
    q.push({srcX, srcY, 0});
    visited[srcX][srcY] = true;

    while (!q.empty())
    {
        Cell curr = q.front();
        q.pop();

        if (curr.x == dstX && curr.y == dstY)
        {
            return curr.dist;
        }

        for (int i = 0; i < 8; i++)
        {
            int newX = curr.x + dx[i];
            int newY = curr.y + dy[i];

            if (isInsideBoard(newX, newY) && !visited[newX][newY])
            {
                visited[newX][newY] = true;
                q.push({newX, newY, curr.dist + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int srcX, srcY, dstX, dstY;
    cin>>srcX>>srcY;
    cin>>dstX>>dstY;

    int minMoves = shortestPath(srcX, srcY, dstX, dstY);

    if (minMoves == -1)
    {
        cout << "Destination cell is not reachable" << endl;
    }
    else
    {
        cout << "Minimum moves from (" << srcX << ", " << srcY << ") to (" << dstX << ", " << dstY << ") is " << minMoves << endl;
    }

    return 0;
}

