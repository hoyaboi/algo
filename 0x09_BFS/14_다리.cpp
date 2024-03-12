#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[102][102];
int vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    int min_dist = INT_MAX;
    
    // BFS로 섬마다 번호 부여 -> 부여하면서 OOB가 아니고 바다 경계이면 bound queue에 push
    queue<pair<int, int>> que, bound;
    int num = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] && !vis[i][j]) {
                num++;
                que.push({i, j});
            }
            while(!que.empty()) {
                pair<int, int> cur = que.front(); que.pop();
                board[cur.X][cur.Y] = num;
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) continue;
                    if(!board[nx][ny]) {
                        bound.push({cur.X, cur.Y});
                        continue;
                    }
                    vis[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }
        }
    }

    // bound que에서 하나씩 꺼내며 BFS 수행 -> 다른 섬 번호 만났을 때 거리 최솟값이면 업데이트
    // 꺼낼 때마다 vis 배열 초기화 필요
    while(!bound.empty()) {
        for(int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);
        pair<int, int> tmp = bound.front(); bound.pop();
        int island = board[tmp.X][tmp.Y];
        vis[tmp.X][tmp.Y] = 1;
        que.push({tmp.X, tmp.Y});
        while(!que.empty()) {
            pair<int, int> cur = que.front(); que.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) continue;
                if(island == board[nx][ny]) continue;
                if(board[nx][ny] != 0) {
                    while(!que.empty()) que.pop();
                    min_dist = min(vis[cur.X][cur.Y] - 1, min_dist);
                    continue;
                }
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                que.push({nx, ny});
            }
        }
    }

    cout << min_dist;
}

// https://www.acmicpc.net/problem/2146