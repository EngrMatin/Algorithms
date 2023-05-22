#include<bits/stdc++.h>
using namespace std;

int n;
char table[40][40];
bool visited[40][40];

// structure to represent cell position
struct pos{
    int x, y;
};

// function to check if a cell is valid to visit
bool isValid(int x, int y){
    return (x>=0 && x<n && y>=0 && y<n && table[x][y]!='O' && !visited[x][y]);
}

// function to find shortest path from start to end
int bfs(pos start, pos end){
    queue<pair<pos, int>> q; // queue to store cell position and its distance
    q.push(make_pair(start, 0));
    visited[start.x][start.y] = true;

    while(!q.empty()){
        pos curr = q.front().first;
        int dist = q.front().second;
        q.pop();

        if(curr.x==end.x && curr.y==end.y){ // if reached to end position
            return dist;
        }

        // checking all 4 adjacent cells
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int x = curr.x + dx[i];
            int y = curr.y + dy[i];
            if(isValid(x, y)){
                visited[x][y] = true;
                q.push(make_pair(pos{x,y}, dist+1));
            }
        }
    }

    return -1; // if no path found
}

// function to mark the path from start to end
void markPath(pos start, pos end){
    while(start.x!=end.x || start.y!=end.y){
        table[start.x][start.y] = '+';
        if(start.x < end.x) start.x++;
        else if(start.x > end.x) start.x--;
        else if(start.y < end.y) start.y++;
        else start.y--;
    }
    table[end.x][end.y] = '+';
}

int main(){
    cin >> n;

    // taking input
    pos start, end;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> table[i][j];
            if(table[i][j]=='@') start = {i, j};
            if(table[i][j]=='X') end = {i, j};
        }
    }

    // finding shortest path
    int dist = bfs(start, end);

    if(dist==-1){
        cout << "N\n";
        return 0;
    }

    // marking path
    markPath(start, end);

    // output
    cout << "Y\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << table[i][j];
        }
        cout << "\n";
    }

    return 0;
}
