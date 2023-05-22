#include <bits/stdc++.h>
using namespace std;

// Data structure to store a cell's coordinates and its distance from the starting cell
struct Cell
{
    int x, y, dist;
};

// Check if a given cell (x, y) is inside the board boundaries
bool isInsideBoard(int x, int y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

// Function to find the shortest path of a knight from source to destination using BFS
int shortestPath(int srcX, int srcY, int dstX, int dstY)
{
    // Possible moves of a knight on the board
    const int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    const int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    // Mark all the cells as not visited
    vector<vector<bool>> visited(8, vector<bool>(8, false));

    // Create a queue for BFS and enqueue the starting cell
    queue<Cell> q;
    q.push({srcX, srcY, 0});
    visited[srcX][srcY] = true;

    // Run BFS until the destination cell is found
    while (!q.empty())
    {
        Cell curr = q.front();
        q.pop();

        // If the destination cell is found, return its distance from the starting cell
        if (curr.x == dstX && curr.y == dstY)
        {
            return curr.dist;
        }

        // Generate all possible moves of the knight and enqueue the valid ones
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

    // If the destination cell cannot be reached, return -1
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
