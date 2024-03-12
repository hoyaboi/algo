#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 

int cnt = 0;
string board[12];
bool vis[12][6];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 12; i++) cin >> board[i];

    while(1) {
        bool pos = false;
        queue<pair<int, int>> que, tmp;

        for(int i = 0; i < 12; i++) fill(vis[i], vis[i] + 6, 0);

        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 6; j++) {
                if(vis[i][j] || board[i][j] == '.') continue;
                vis[i][j] = true;
                que.push({i, j}); tmp.push({i, j});
                while(!que.empty()) {
                    pair<int, int> cur = que.front(); que.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
                        if(vis[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;
                        vis[nx][ny] = true;
                        que.push({nx, ny}); tmp.push({nx, ny});
                    }
                }
                if(tmp.size() >= 4) {
                    pos = true;
                    while(!tmp.empty()) {
                        board[tmp.front().X][tmp.front().Y] = '.';
                        tmp.pop();
                    }
                }
                while(!tmp.empty()) tmp.pop();
            }
        }

        for(int j = 0; j < 6; j++) {
            queue<char> q;
            for(int i = 11; i >= 0; i--) {
                if(board[i][j] != '.') {
                    q.push(board[i][j]);
                    board[i][j] = '.';
                }
            }
            int idx = 11;
            while(!q.empty()) {
                board[idx][j] = q.front();
                q.pop();
                idx--;
            }
        }

        if(!pos) break;
        cnt++;
    }
    cout << cnt;
}


// https://www.acmicpc.net/problem/11559