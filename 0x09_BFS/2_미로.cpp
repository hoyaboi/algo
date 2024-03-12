#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502] ;
int dist[502][502];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    for(int i = 0; i < n; i++) fill(dist[i], dist[i]+m, -1);

    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < tmp.length(); j++)
            board[i][j] = tmp[j] - '0';
    }

    queue<pair<int, int>> que;
    dist[0][0] = 1;
    que.push({0, 0});

    while(!que.empty()) {
        pair<int, int> cur = que.front(); que.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0 || board[nx][ny] != 1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            que.push({nx, ny});
        }
    }
    cout << dist[n-1][m-1];
}

// https://www.acmicpc.net/problem/2178