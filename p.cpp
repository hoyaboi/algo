#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1002][1002], vis[1002][1002][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    queue<tuple<int, int, int>> que;

    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        for(int j = 1; j <= m; j++) board[i][j] = s[j] - '0';
    }

    vis[1][1][0] = 1;
    que.push({1, 1, 0});
    while(!que.empty()) {
        int x, y, c; tie(x, y, c) = que.front(); que.pop();
        if(x == n && y == m) {
            cout << vis[x][y][c];
            return 0;
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            if(board[nx][ny] && !c) {
                vis[nx][ny][c+1] = vis[nx][ny][c] + 1;
                que.push({nx, ny, c+1});
            }
            if(!board[nx][ny] && !vis[nx][ny][c]) {
                vis[nx][ny][c] = vis[x][y][c] + 1;
                que.push({nx, ny, c});
            }
        }
    }
    cout << -1;
}

