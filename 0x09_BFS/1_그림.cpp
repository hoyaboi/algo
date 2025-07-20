#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    int cnt = 0, maxArea = 0;
    queue<pair<int, int>> que;

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int area = 0;
            if(board[i][j]) {
                que.push({i, j});
                board[i][j] = 0;
                area++; cnt++;
            }
            while(!que.empty()) {
                pair<int, int> cur = que.front(); que.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(!board[nx][ny]) continue;
                    area++;
                    que.push({nx, ny});
                    board[nx][ny] = 0;
                }
            }
            maxArea = max(area, maxArea);
        }
    }
    cout << cnt << "\n" << maxArea;
}

// https://www.acmicpc.net/problem/1926