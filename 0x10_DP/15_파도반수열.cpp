#include <bits/stdc++.h>
using namespace std;

long long D[102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    D[1] = D[2] = D[3] = 1;
    for(int i = 4; i <= 100; i++)
        D[i] = D[i-2] + D[i-3];

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << D[n] << "\n";
    }
}

// https://www.acmicpc.net/problem/9461