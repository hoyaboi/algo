#include <bits/stdc++.h>
using namespace std;

int D[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    D[0] = 0;
    for(int i = 1; i <= n; i++) {
        D[i] = INT_MAX;
        for(int j = 1; j*j <= i; j++)
            D[i] = min(D[i], D[i - j*j] + 1);
    }
    cout << D[n] << "\n";
}

// https://www.acmicpc.net/problem/1699