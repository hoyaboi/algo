#include <bits/stdc++.h>
using namespace std;

bool board[1002][1002];
int D[1002][1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string tmp; cin >> tmp;
        for(int j = 1; j <= tmp.size(); j++)
            board[i][j] = tmp[j-1] - '0';
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(board[i][j]) D[i][j] = min({D[i-1][j], D[i][j-1], D[i-1][j-1]}) + 1;
    int M = *max_element(&D[1][1], &D[n][m]+1);
    cout << M * M;
}

// https://www.acmicpc.net/problem/1915