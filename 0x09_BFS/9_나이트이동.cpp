#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 

int vis[300][300];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    while(n--) {
        int l; cin >> l;
        for(int i = 0; i < l; i++)
            fill(vis[i], vis[i]+l, 0);
        int m, n; cin >> m >> n;
        int p, q; cin >> p >> q;
        queue<pair<int, int>> que;

        vis[m][n] = 1;
        que.push({m, n});

        while(!que.empty()) {
            pair<int, int> cur = que.front(); que.pop();
            for(int dir = 0; dir < 8; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if(vis[nx][ny]) continue;
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                que.push({nx, ny});
            }
        }
        cout << vis[p][q]-1 << "\n";
    }
}

// https://www.acmicpc.net/problem/7562