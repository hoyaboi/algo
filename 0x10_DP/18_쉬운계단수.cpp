#include <bits/stdc++.h>
using namespace std;

long long D[102][11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i < 10; i++) D[1][i] = 1;
    for(int i = 2; i <= n; i++) {
        D[i][0] = D[i-1][1];
        for(int j = 1; j < 9; j++)
            D[i][j] = D[i-1][j-1] + D[i-1][j+1] ;
        D[i][9] = D[i-1][8];
        for(int j = 0; j < 10; j++) D[i][j] %= 1000000000;
    }
    long long ans = 0;
    for(int i = 0; i < 10; i++) ans += D[n][i];
    cout << ans % 1000000000;
}

// https://www.acmicpc.net/problem/10844