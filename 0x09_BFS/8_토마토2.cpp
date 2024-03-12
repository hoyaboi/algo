#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 
#define Z third

int box[102][102][102];
int vis[102][102][102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, h; cin >> n >> m >> h;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++) cin >> box[j][k][i];

    int dx[6] = {1, 0, -1, 0, 0, 0};
    int dy[6] = {0, 1, 0, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};
    queue<tuple<int, int, int>> que;

    for(int i = 0; i < h; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++) {
                if(box[j][k][i] == 1) {
                    vis[j][k][i] = 1;
                    que.push({j, k, i});
                }
                if(box[j][k][i] == -1) vis[j][k][i] = -1;
            }
    while(!que.empty()) {
        auto cur = que.front(); que.pop();
        int x, y, z;
        tie(x, y, z) = cur;
        for(int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
            if(box[nx][ny][nz] != 0 || vis[nx][ny][nz] > 0) continue;
            vis[nx][ny][nz] = vis[x][y][z] + 1;
            que.push({nx, ny, nz});
        }
    }
    int count = 0;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++) {
                if(vis[j][k][i] == 0) {
                    cout << -1;
                    return 0;
                }
                count = max(count, vis[j][k][i]);
            }
    cout << count-1;
}

// https://www.acmicpc.net/problem/7569