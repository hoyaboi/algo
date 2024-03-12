#include <bits/stdc++.h>
using namespace std;

int board[32][32][32];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        int l, r, c; cin >> l >> r >> c;
        if(!l&&!r&&!c) break;

        for(int i = 0; i < l; i++)
            for(int j = 0; j < r; j++)
                fill(board[i][j], board[i][j] + c, 0);

        queue<tuple<int, int, int>> que;
        tuple<int, int, int> E;

        for(int i = 0; i < l; i++) {
            for(int j = 0; j < r; j++) {
                string tmp; cin >> tmp;
                for(int k = 0; k < c; k++) {
                    if(tmp[k] == '#') board[i][j][k] = -1;
                    if(tmp[k] == 'S') {
                        que.push({i, j, k});
                        board[i][j][k] = 1;
                    }
                    if(tmp[k] == 'E') E = {i, j, k};
                }
            }
        }

        while(!que.empty()) {
            auto cur = que.front(); que.pop();
            int x, y, z;
            tie(z, x, y) = cur;
            for(int dir = 0; dir < 6; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                int nz = z + dz[dir];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
                if(board[nz][nx][ny] < 0 || board[nz][nx][ny]) continue;
                board[nz][nx][ny] = board[z][x][y] + 1;
                que.push({nz, nx, ny});
            }
        }

        tie(l, r, c) = E;
        if(board[l][r][c]) cout << "Escaped in " << board[l][r][c]-1 << " minute(s).\n";
        else cout << "Trapped!\n";
    }
}

// https://www.acmicpc.net/problem/6593