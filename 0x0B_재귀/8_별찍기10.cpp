#include <bits/stdc++.h>
using namespace std;

char board[2200][2200];

void func(int, int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k; cin >> k;
    for(int i = 0; i < k; i++)
        fill(board[i], board[i] + k, ' ');
    func(0, 0, k);
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) cout << board[i][j];
        cout << "\n";
    }
}
void func(int n, int m, int k) {
    if(k == 1) {
        board[n][m] = '*';
        return;
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int x = n + k/3 * i, y = m + k/3 * j;
            if(i != 1 || j != 1) func(x, y, k/3);
        }
    }
}

// https://www.acmicpc.net/problem/2447