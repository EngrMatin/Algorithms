#include <vector>
#include <queue>

int countIslands(std::vector<std::vector<char>> grid) {
    int numIslands = 0;
    int rows = grid.size();
    if (rows == 0) return numIslands;
    int cols = grid[0].size();

    // Define possible moves
    std::vector<std::pair<int, int>> moves = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

    // Define a function to check if a position is within the grid and is land
    auto isLand = [&](int i, int j) {
        return i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] == '#';
    };

    // Define a function to mark all adjacent land cells as visited
    auto markAdjacent = [&](int i, int j) {
        std::queue<std::pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (auto [dx, dy] : moves) {
                int nx = x + dx, ny = y + dy;
                if (isLand(nx, ny)) {
                    grid[nx][ny] = '.';
                    q.push({nx, ny});
                }
            }
        }
    };

    // Iterate over all cells and count the number of connected components
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '#') {
                ++numIslands;
                markAdjacent(i, j);
            }
        }
    }

    return numIslands;
}

