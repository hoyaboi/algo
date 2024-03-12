#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second

int board[1002][1002], vis[1002][1002][2];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string tmp; cin >> tmp;
        for(int j = 0; j < m; j++) board[i][j] = tmp[j] - '0';
    }
    queue<tuple<int, int, int>> que;
    vis[0][0][0] = 1;
    que.push({0, 0, 0});

    while(!que.empty()) {
        int x, y, crash;
        tie(x, y, crash) = que.front(); que.pop();
        if(x == n-1 && y == m-1) {
            cout << vis[x][y][crash];
            return 0;
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] && !crash) {
                vis[nx][ny][crash+1] = vis[x][y][crash] + 1;
                que.push({nx, ny, crash+1});
            }
            if(!board[nx][ny] && !vis[nx][ny][crash]) {
                vis[nx][ny][crash] = vis[x][y][crash] + 1;
                que.push({nx, ny, crash});
            }
        }
    }
    cout << -1;
}

// https://www.acmicpc.net/problem/2206