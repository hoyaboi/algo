#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1002][1002];
int fire[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int r, c; cin >> r >> c;
    queue<pair<int, int>> queJ, queF;

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) {
            char c; cin >> c;
            if(c == '#') board[i][j] = fire[i][j] = -1;
            else if(c == 'J') {
                board[i][j] = 1;
                queJ.push({i, j});
            }
            else if(c == 'F') {
                fire[i][j] = 1;
                queF.push({i, j});
            }
        }

    while(!queF.empty()) {
        pair<int, int> cur = queF.front(); queF.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c || fire[nx][ny]) continue;
            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            queF.push({nx, ny});
        }
    }

    while(!queJ.empty()) {
        pair<int, int> cur = queJ.front(); queJ.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(board[nx][ny]) continue;
            if(nx < 0 || ny < 0 || nx >= r || ny >= c) {
                if(fire[cur.X][cur.Y] == 0 || fire[cur.X][cur.Y] > board[cur.X][cur.Y]) {
                    cout << board[cur.X][cur.Y];
                    return 0;
                }
                continue;
            }
            board[nx][ny] = board[cur.X][cur.Y] + 1;
            queJ.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}

// https://www.acmicpc.net/problem/4179