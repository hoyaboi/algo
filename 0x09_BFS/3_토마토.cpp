#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int m, n; cin >> m >> n;
    queue<pair<int, int>> que;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) que.push({i, j});
        }

    while(!que.empty()) {
        pair<int, int> cur = que.front(); que.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny]) continue;
            board[nx][ny] = board[cur.X][cur.Y] + 1;
            que.push({nx, ny});
        }
    }

    int day = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!board[i][j]) {
                cout << -1;
                return 0;
            }
            day = max(board[i][j], day);
        }
    }
    if(day == 1) cout << 0;
    else cout << day-1;
}

// https://www.acmicpc.net/problem/7576
