#include <bits/stdc++.h>
using namespace std;

int R[100002], D[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> R[i];
    sort(R, R + n);
    for(int i = 1; i <= n; i++) D[i] = R[n-i] * i;
    cout << *max_element(D + 1, D + n + 1);
}

// https://www.acmicpc.net/problem/2217