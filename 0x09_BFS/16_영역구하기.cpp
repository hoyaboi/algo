#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second

int board[102][102];
int vis[102][102];
int m, n, k;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    while(k--) {
        pair<int, int> start, end;
        cin >> start.X >> start.Y >> end.X >> end.Y;
        for(int i = start.Y ; i < end.Y; i++)
            for(int j = start.X; j < end.X; j++)
                board[i][j] = 1;
    }
    queue<pair<int, int>> que;
    vector<int> maxArea;
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 0 && !vis[i][j]) {
                cnt++;
                que.push({i, j});
                int area = vis[i][j] = 1;
                while(!que.empty()) {
                    int nx, ny;
                    pair<int, int> cur = que.front(); que.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        nx = cur.X + dx[dir];
                        ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if(board[nx][ny] || vis[nx][ny]) continue;
                        que.push({nx, ny});
                        vis[nx][ny] = ++area;
                    }
                    if(que.empty()) maxArea.push_back(vis[cur.X][cur.Y]);
                }
            }
        }
    }
    sort(maxArea.begin(), maxArea.end());
    cout << cnt << "\n";
    for(int i : maxArea) cout << i << " ";
}

// https://www.acmicpc.net/problem/2583