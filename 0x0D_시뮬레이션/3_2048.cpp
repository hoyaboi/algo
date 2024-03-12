#include <bits/stdc++.h>
using namespace std;

int n, board[22][22], board2[22][22], tmp[22][22];

int move(int);
void rotate();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> board[i][j];
    
    int m = 0;
    for(int i = 0; i < 1<<(2*10); i++) {
        for(int p = 0; p < n; p++)
            for(int q = 0; q < n; q++)
                board2[p][q] = board[p][q];
        int tmp = i;
        for(int j = 0; j < 5; j++) {
            int dir = tmp % 4;
            tmp /= 4;
            m = max(m, move(dir));
        }
    }
    cout << m;
}
int move(int dir) {
    while(dir--) rotate();
    for(int i = 0; i < n; i++) {
        queue<int> que;
        int index = 0;
        for(int j = 0; j < n; j++) {
            if(!board2[i][j]) continue;
            que.push(board2[i][j]);
        }
        fill(board2[i], board2[i] + n, 0);
        while(!que.empty()) {
            int tmp = que.front(); que.pop();
            if(que.empty() || tmp != que.front()) board2[i][index] = tmp;
            else {
                que.pop();
                board2[i][index] = 2*tmp;
            }
            index++;
        }
    }
    int m = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            m = max(m, board2[i][j]);
    return m;
}
void rotate() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            tmp[j][n-i-1] = board2[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board2[i][j] = tmp[i][j];
}

// https://www.acmicpc.net/problem/12100