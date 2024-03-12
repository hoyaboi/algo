#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 

int board[52][52];
bool visit[52][52];
int m, n, k;

void bfs(int, int);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int count = 0;
        cin >> m >> n >> k;
        while(k--) {
            int x, y; cin >> y >> x;
            board[x][y] = 1;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 1 && !visit[i][j]) {
                    bfs(i, j);
                    count++;
                }
            }
        }
        cout << count << "\n";
        for(int i = 0; i < n; i++) {
            fill(board[i], board[i] + m, 0);
            fill(visit[i], visit[i] + m, 0);
        }
    }
}
void bfs(int x, int y) {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<int, int>> que;

    visit[x][y] = 1;
    que.push({x, y});
    while(!que.empty()) {
        pair<int, int> cur = que.front(); que.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visit[nx][ny] || board[nx][ny] != 1) continue;
            visit[nx][ny] = 1;
            que.push({nx, ny});
        }
    }
}

// https://www.acmicpc.net/problem/1012