#include <bits/stdc++.h>
using namespace std;

int stair[302];
int D[302][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> stair[i];
    D[1][1] = stair[1];
    D[2][1] = stair[2];
    D[2][2] = stair[1] + stair[2];
    for(int i = 3; i <= n; i++) {
        D[i][1] = max(D[i-2][1], D[i-2][2]) + stair[i];
        D[i][2] = D[i-1][1] + stair[i];
    }

    cout << max(D[n][1], D[n][2]);
}

// https://www.acmicpc.net/problem/2579