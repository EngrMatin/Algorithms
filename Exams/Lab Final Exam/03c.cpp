#include <bits/stdc++.h>
using namespace std;

int countIslands(vector<vector<char>> grid);

int main()
{
    vector<vector<char>> grid1 =
    {
        {'#', '#', '.', '.', '.',},
        {'#', '#', '.', '.', '.',},
        {'.', '.', '#', '.', '.',},
        {'.', '.', '.', '#', '#',},
        {'.', '.', '.', '#', '#',},
    };
    int islands1 = countIslands(grid1);
    cout << "Number of Islands in Grid 1: " << islands1 << endl;

    vector<vector<char>> grid2 =
    {
        {'#', '#', '.', '.', '.',},
        {'#', '#', '.', '.', '.',},
        {'.', '.', '.', '.', '.',},
        {'.', '.', '.', '#', '#',},
        {'.', '.', '.', '#', '#',},
    };
    int islands2 = countIslands(grid2);
    cout << "Number of Islands in Grid 2: " << islands2 << endl;

    vector<vector<char>> grid3 =
    {
        {'#', '.', '.', '.', '#',},
        {'.', '#', '.', '#', '.',},
        {'.', '.', '#', '.', '.',},
        {'.', '#', '.', '#', '.',},
        {'#', '.', '.', '.', '#',},
    };
    int islands3 = countIslands(grid3);
    cout << "Number of Islands in Grid 3: " << islands3 << endl;

    return 0;
}

int countIslands(vector<vector<char>> grid)
{
    int numIslands = 0;
    int rows = grid.size();

    if (rows == 0)
    {
        return numIslands;
    }

    int cols = grid[0].size();

    vector<pair<int, int>> moves = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

    auto isLand = [&](int i, int j)
    {
        return i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] == '#';
    };

    auto markAdjacent = [&](int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty())
        {
            auto [x, y] = q.front(); q.pop();
            for (auto [dx, dy] : moves)
            {
                int nx = x + dx, ny = y + dy;
                if (isLand(nx, ny))
                {
                    grid[nx][ny] = '.';
                    q.push({nx, ny});
                }
            }
        }
    };

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == '#')
            {
                ++numIslands;
                markAdjacent(i, j);
            }
        }
    }

    return numIslands;
}
