#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second

int board[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, maxH = 0, ans = 1; cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(maxH < board[i][j]) maxH = board[i][j];
        }

    for(int h = 1; h <= maxH; h++) {
        int tmp[102][102], cnt = 0;
        memcpy(tmp, board, sizeof(int)*102*102);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                tmp[i][j] -= h;

        queue<pair<int, int>> que;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                if(tmp[i][j] > 0) {
                    que.push({i, j});
                    tmp[i][j] = -1;
                    cnt++;
                }
                while(!que.empty()) {
                    pair<int, int> cur = que.front(); que.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n || tmp[nx][ny] <= 0) continue;
                        que.push({nx, ny});
                        tmp[nx][ny] = -1;
                    }
                }
            }
        ans = max(ans, cnt);
    }
    cout << ans;
}

// https://www.acmicpc.net/problem/2468