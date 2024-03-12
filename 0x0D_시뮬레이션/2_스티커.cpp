#include <bits/stdc++.h>
using namespace std;

int n, m, k, r, c;
bool sticker[12][12][102];
bool board[42][42];

void put(int);
void rotation(int);
bool isPossible(int, int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        cin >> r >> c;
        for(int j = 0; j < r; j++)
            for(int t = 0; t < c; t++)
                cin >> sticker[j][t][i];
        put(i);
    }

    int count = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j] == 1) count++;
    cout << count;
}
void put(int k) {
    int dir = 4;
    while(dir--) {
        for(int i = 0; i < n-r+1; i++) {
            for(int j = 0; j < m-c+1; j++) {
                if(isPossible(i, j, k)) {
                    for(int p = 0; p < r; p++)
                        for(int q = 0; q < c; q++)
                            if(sticker[p][q][k] == 1) board[p+i][q+j] = 1;
                    return;
                }
            }
        }
        rotation(k);
    }
}
void rotation(int k) {
    bool tmp[12][12];
    for(int i = 0; i < c; i++)
        for(int j = 0; j < r; j++)
            tmp[i][j] = sticker[r-j-1][i][k];
    int p = r; r = c; c = p;
    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 12; j++)
            sticker[i][j][k] = tmp[i][j];
}
bool isPossible(int n, int m, int k) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(sticker[i][j][k] == 1 && board[n+i][m+j] == 1) return false;
        }
    }
    return true;
}

// https://www.acmicpc.net/problem/18808