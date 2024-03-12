#include <bits/stdc++.h>
using namespace std;

char board[3100][6200];
void func(int, int, int);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++)
        fill(board[i], board[i] + 2*n-1, ' ');
    func(0, 0, n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2*n-1; j++) cout << board[i][j];
        cout << "\n";
    }
}
void func(int x, int y, int n) {
    if(n == 3) {
        board[x][y+2] = '*';
        board[x+1][y+1] = board[x+1][y+3] = '*';
        for(int i = 0; i < 2*n-1; i++) board[x+2][y+i] = '*';
        return;
    }
    func(x, y + n/2, n/2);
    func(x + n/2, y, n/2);
    func(x + n/2, y + n, n/2);
}

// https://www.acmicpc.net/problem/2448