#include <bits/stdc++.h>
using namespace std;

int R[10002], D[10002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> R[i];
    D[0] = 0;
    D[1] = R[1];
    if(n > 1) D[2] = R[1] + R[2];
    for(int i = 3; i <= n; i++)
        D[i] = max({D[i-1], D[i-2] + R[i], D[i-3] + R[i-1] + R[i]});
    cout << D[n];
}

// https://www.acmicpc.net/problem/2156