#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;

int board[52][52], vis[52][52];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int l, w; cin >> l >> w;
    vector<pii> vec;
    for(int i = 0; i < l; i++) {
        string tmp; cin >> tmp;
        for(int j = 0; j < w; j++)
            if(tmp[j] == 'L') {
                board[i][j] = 1;
                vec.push_back({i, j});
            }
    }
    queue<pii> que;
    int ans = 0;
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < l; j++) memset(vis[j], 0, w * sizeof(int));
        que.push(vec[i]);
        vis[vec[i].X][vec[i].Y] = 1;

        while(!que.empty()) {
            pii cur = que.front(); que.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= l || ny < 0 || ny >= w) continue;
                if(!board[nx][ny] || vis[nx][ny]) continue;
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                ans = max(vis[nx][ny], ans);
                que.push({nx, ny});
            }
        }
    }
    cout << ans - 1;
}

// https://www.acmicpc.net/problem/2589