#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second

char board[22][22];
bool isUsed[100];
int n, m, cnt;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void tracking(int, int, int);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    isUsed[board[0][0]] = 1;

    tracking(1, 0, 0);
    cout << cnt  << "\n";
}
void tracking(int k, int x, int y) {
    cnt = max(cnt, k);
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(isUsed[board[nx][ny]]) continue;     
        isUsed[board[nx][ny]] = 1;
        tracking(k+1, nx, ny);
        isUsed[board[nx][ny]] = 0;
    }
}

// https://www.acmicpc.net/problem/1987