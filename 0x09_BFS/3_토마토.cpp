#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1002][1002];
int vis[1002][1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> m >> n;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<int, int>> que;
    int count = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) {
                vis[i][j] = 1;
                que.push({i, j});
            }
            if(board[i][j] == -1) vis[i][j] = -1;
        }

    while(!que.empty()) {
        pair<int, int> cur = que.front(); que.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] > 0 || board[nx][ny] != 0) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            que.push({nx, ny});
        }
    }

    bool isSame = true;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) {
            if(vis[i][j] == 0) {
                cout << -1;
                return 0;
            }
            else if(board[i][j] != vis[i][j]) isSame = false;
            if(count < vis[i][j]) count = vis[i][j];
        }
    if(!isSame) cout << count-1;
    else cout << 0;
}   

// https://www.acmicpc.net/problem/7576
