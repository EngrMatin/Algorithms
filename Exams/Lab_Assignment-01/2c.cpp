#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
char grid[N][N];
int visited[N][N];
int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int startx, starty;

struct Node {
    int x, y;
    string path;
};

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && !visited[x][y];
}

void bfs() {
    queue<Node> q;
    q.push({startx, starty, ""});
    visited[startx][starty] = true;

    while (!q.empty()) {
        Node node = q.front();
        q.pop();

        if (node.x == 0 || node.x == n-1 || node.y == 0 || node.y == m-1) {
            cout << "YES\n" << node.path.size() << endl << node.path << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nextx = node.x + dx[i];
            int nexty = node.y + dy[i];

            if (is_valid(nextx, nexty)) {
                visited[nextx][nexty] = true;
                q.push({nextx, nexty, node.path + (i==0?"U":(i==1?"D":(i==2?"L":"R")))});
            }
        }
    }

    cout << "NO\n";
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                startx = i;
                starty = j;
            }
        }
    }

    bfs();

    return 0;
}
