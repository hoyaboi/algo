#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 

int fire[1002][1002], escape[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> m >> n;
        queue<pair<int, int>> que_fire, que_esc;
        for(int i = 0; i < n; i++) {
            fill(fire[i], fire[i] + m, 0);
            fill(escape[i], escape[i] + m, 0);
            string tmp; cin >> tmp;
            for(int j = 0; j < m; j++)
                switch(tmp[j]) {
                case '#':
                    fire[i][j] = -1;
                    escape[i][j] = -1;
                    break;
                case '*':
                    fire[i][j] = 1;
                    que_fire.push({i, j});
                    break;
                case '@':
                    escape[i][j] = 1;
                    que_esc.push({i, j});
                    break;
                }
        }
        while(!que_fire.empty()) {
            pair<int, int> cur = que_fire.front(); que_fire.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(fire[nx][ny] == -1 || fire[nx][ny]) continue;
                fire[nx][ny] = fire[cur.X][cur.Y] + 1;
                que_fire.push({nx, ny});
            }
        }
        bool isEscape = false;
        while(!que_esc.empty() && !isEscape) {
            pair<int, int> cur = que_esc.front(); que_esc.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    cout << escape[cur.X][cur.Y] << "\n";
                    isEscape = true;
                    break;
                }
                if(escape[nx][ny] == -1 || escape[nx][ny]) continue;
                if(fire[nx][ny] != 0 && fire[nx][ny] <= escape[cur.X][cur.Y] + 1) continue;
                escape[nx][ny] = escape[cur.X][cur.Y] + 1;
                que_esc.push({nx, ny});
            }
        }
        if(!isEscape) cout << "IMPOSSIBLE\n";
    }
}

// https://www.acmicpc.net/problem/5427