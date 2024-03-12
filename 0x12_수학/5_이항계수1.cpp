#include <bits/stdc++.h>
using namespace std;

int D[1002][1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) D[i][0] = D[i][i] = 1;
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i && j <= k; j++) D[i][j] = (D[i-1][j-1] + D[i-1][j]) % 10007;
    cout << D[n][k];
}

// https://www.acmicpc.net/problem/11050