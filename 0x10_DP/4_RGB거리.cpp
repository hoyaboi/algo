#include <bits/stdc++.h>
using namespace std;

int D[1002][3], C[1002][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 3; j++) cin >> C[i][j];

    for(int i = 0; i < 3; i++) D[1][i] = C[1][i];

    for(int i = 2; i <= n; i++) {
        D[i][0] = min(D[i-1][1], D[i-1][2]) + C[i][0];
        D[i][1] = min(D[i-1][0], D[i-1][2]) + C[i][1];
        D[i][2] = min(D[i-1][0], D[i-1][1]) + C[i][2];
    }

    cout << min({D[n][0], D[n][1], D[n][2]});
}

// https://www.acmicpc.net/problem/1149