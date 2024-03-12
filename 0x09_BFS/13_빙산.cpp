#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m, cnt;
int now[300][300], fut[300][300], vis[300][300];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool seperate();
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n>> m;
    queue<pair<int, int>> que, tmp;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> now[i][j];
            fut[i][j] = now[i][j];
            if(now[i][j]) que.push({i, j});
        }
    while(1) {
        while(!que.empty()) {
            pair<int, int> cur = que.front(); que.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(now[nx][ny] == 0 && fut[cur.X][cur.Y] > 0) fut[cur.X][cur.Y]--;
            }
            if(fut[cur.X][cur.Y]) tmp.push({cur.X, cur.Y});
        }
        swap(que, tmp);
        if(que.empty()) {
            cout << 0;
            return 0;
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                now[i][j] = fut[i][j];
        cnt++;
        if(seperate()) {
            cout << cnt;
            return 0;
        }
    }
}
bool seperate() {
    for(int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);
    queue<pair<int, int>> que;
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(vis[i][j] || now[i][j] == 0) continue;
            que.push({i, j});
            cnt++;
            while(!que.empty()) {
                pair<int, int> cur = que.front(); que.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(now[nx][ny] == 0 || vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    que.push({nx, ny});
                }
            }
        }
    return cnt > 1;
}

// https://www.acmicpc.net/problem/2573