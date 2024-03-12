#include <bits/stdc++.h>
using namespace std;

int n, m, k;
pair<int, int> loc;
int board[22][22], dice[6];
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

int moveDice(int);
void rotate(int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> loc.first >> loc.second >> k;
    vector<int> cmd(k);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> board[i][j];
    for(int& i : cmd) cin >> i;
    for(int i = 0; i < k; i++) {
        int ans = moveDice(cmd[i]);
        if(ans >= 0) cout << ans << "\n";
    }
}
int moveDice(int cmd) {
    // if(cmd에 따라 이동한 dice의 위차가 board 범위를 벗어나면) -1 리턴
    pair<int, int> cur;
    cur.first = loc.first + dx[cmd];
    cur.second = loc.second + dy[cmd];
    if(cur.first < 0 || cur.first >= n || cur.second < 0 || cur.second >= m) return -1;
    loc = cur;

    // else cmd에 따라 이동
    if(cmd == 1) rotate(5, 4);
    else if(cmd == 2) rotate(4, 5);
    else if(cmd == 3) rotate(3, 2);
    else rotate(2, 3);
    
    // board와 dice 상태 업데이트
    if(board[cur.first][cur.second] == 0) 
        board[cur.first][cur.second] = dice[1];
    else {
        dice[1] = board[cur.first][cur.second];
        board[cur.first][cur.second] = 0;
    }

    // dice의 윗 면 return
    return dice[0];
}
void rotate(int a, int b) {
    int tmp = dice[1];
    dice[1] = dice[b];
    dice[b] = dice[0];
    dice[0] = dice[a];
    dice[a] = tmp;
}

// https://www.acmicpc.net/problem/14499