#include <bits/stdc++.h>
using namespace std;

int k, w, h;
int board[202][202], vis[202][202][32];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dhx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dhy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> w >> h;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++) 
            cin >> board[i][j];
    queue<tuple<int, int, int>> que;
    vis[0][0][0] = 1;
    que.push({0, 0, 0});
    while(!que.empty()) {
        int curX, curY, curH;
        tie(curX, curY, curH) = que.front(); que.pop();
        if(curH < k) {
            for(int dir = 0; dir < 8; dir++) {
                int nx = curX + dhx[dir];
                int ny = curY + dhy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(board[nx][ny] || vis[nx][ny][curH + 1]) continue;
                vis[nx][ny][curH + 1] = vis[curX][curY][curH] + 1;
                que.push({nx, ny, curH + 1});
            }
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(board[nx][ny] || vis[nx][ny][curH]) continue;
            vis[nx][ny][curH] = vis[curX][curY][curH] + 1;
            que.push({nx, ny, curH});
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i <= k; i++)
        if(vis[h-1][w-1][i]) ans = min(ans, vis[h-1][w-1][i]);
    if(ans != INT_MAX) cout << ans-1;
    else cout << -1;
}

// https://www.acmicpc.net/problem/1600