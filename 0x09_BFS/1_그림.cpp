#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int board[502][502] = {};
    bool vis[502][502] = {};
    int n, m; cin >> n >> m;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int count = 0, maxArea = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    queue<pair<int, int>> que;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j]|| board[i][j] == 0) continue;
            vis[i][j] = 1;
            que.push({i, j});
            int area = 1;
            while(!que.empty()) {
                pair<int, int> cur = que.front(); que.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] || board[nx][ny] != 1) continue;
                    area++;
                    vis[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }
            count++;
            if(area > maxArea) maxArea = area;
        }
    }
    cout << count << "\n" << maxArea;
}

// https://www.acmicpc.net/problem/1926