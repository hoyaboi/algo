#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[102][102];
bool vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    queue<pair<int, int>> que;

    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        for(int j = 0; j < m; j++)
            board[i][j] = str[j] - '0';
    }

    que.push({0, 0});
    vis[0][0] = 1;
    while(!que.empty()) {
        pair<int, int> cur = que.front(); que.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || !board[nx][ny]) continue;
            board[nx][ny] = board[cur.X][cur.Y] + 1;
            vis[nx][ny] = 1;
            que.push({nx, ny});
        }
    }

    cout << board[n-1][m-1];
}

// https://www.acmicpc.net/problem/2178