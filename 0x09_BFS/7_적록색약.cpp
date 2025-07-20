#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board1[102][102], board2[102][102], vis[102][102], n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int board[102][102]) {
    int cnt = 0;
    queue<pair<int, int>> que;
    memset(vis, 0, sizeof(vis));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] && !vis[i][j]) {
                que.push({i, j});
                vis[i][j] = 1;
                cnt++;
            }
            while(!que.empty()) {
                pair<int, int> cur = que.front(); que.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) continue;
                    if(board[nx][ny] != board[cur.X][cur.Y]) continue;
                    vis[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }
        }
    }

    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            char c; cin >> c;
            if(c == 'R') board1[i][j] = 1;
            else if(c == 'G') board1[i][j] = 2;
            else board1[i][j] = 3;
        }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(board1[i][j] == 1 || board1[i][j] == 2) board2[i][j] = 1;
            else board2[i][j] = 2;
        }

    int cnt1 = bfs(board1);
    int cnt2 = bfs(board2);

    cout << cnt1 << " " << cnt2;
}

// https://www.acmicpc.net/problem/10026