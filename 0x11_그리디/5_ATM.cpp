#include <bits/stdc++.h>
using namespace std;

int R[1002], D[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> R[i];
    sort(R, R + n);
    int sum = R[0];
    D[0] = R[0];
    for(int i = 1; i < n; i++) {
        D[i] = D[i-1] + R[i];
        sum += D[i];
    }
    cout << sum;
}

// https://www.acmicpc.net/problem/11399