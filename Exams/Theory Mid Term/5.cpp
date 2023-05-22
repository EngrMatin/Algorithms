#include <iostream>
#include <cstring>
using namespace std;

const int MAX_H = 50;
const int MAX_W = 50;

char grid[MAX_H][MAX_W];
bool visited[MAX_H][MAX_W];
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
int h, w, ans;

void dfs(int x, int y, int depth) {
    ans = max(ans, depth);
    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] == grid[x][y] + 1) {
            dfs(nx, ny, depth + 1);
        }
    }
    visited[x][y] = false;
}

int main() {
    int caseNum = 1;
    while (cin >> h >> w && h != 0 && w != 0) {
        ans = 0;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grid[i][j];
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 'A') {
                    dfs(i, j, 1);
                }
            }
        }
        cout << "Case " << caseNum++ << ": " << ans << endl;
    }
    return 0;
}

