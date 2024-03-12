#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 

char board[1002][1002];
int escape[1002][1002];
int fire[1002][1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < tmp.length(); j++) 
            board[i][j] = tmp[j];
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<int, int>> que1;
    queue<pair<int, int>> que2;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'J') {
                escape[i][j] = 1;
                que1.push({i, j});
            } else if(board[i][j] == 'F') {
                fire[i][j] = 1;
                que2.push({i, j});
            }
        }

    while(!que2.empty()) {
        pair<int, int> cur = que2.front(); que2.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '#' || fire[nx][ny] > 0) continue;
            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            que2.push({nx, ny});
        }
    }

    while(!que1.empty()) {
        pair<int, int> cur = que1.front(); que1.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << escape[cur.X][cur.Y];
                return 0;
            }
            if(board[nx][ny] == '#' || escape[nx][ny] > 0) continue;
            if(fire[nx][ny] != 0 && escape[cur.X][cur.Y] + 1 >= fire[nx][ny]) continue;
            escape[nx][ny] = escape[cur.X][cur.Y] + 1;
            que1.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}

// https://www.acmicpc.net/problem/4179