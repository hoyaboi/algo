#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int board[502][502];
    bool vis[502][502];
    int m, n;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    stack<pair<int, int>> stk;
    vis[0][0] = 1;
    stk.push({0, 0});
    
    while(!stk.empty()) {
        pair<int, int> cur = stk.top(); stk.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1;
            stk.push({nx, ny});
        }
    }
}

// 거리 계산 불가, stack 사용