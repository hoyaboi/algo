#include <bits/stdc++.h>
using namespace std;

long long D[92][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    D[1][0] = 0;
    D[1][1] = 1;
    for(int i = 2; i <= n; i++) {
        D[i][0] = D[i-1][0] + D[i-1][1];
        D[i][1] = D[i-1][0];
    }
    cout << D[n][0] + D[n][1];
}

// https://www.acmicpc.net/problem/2193