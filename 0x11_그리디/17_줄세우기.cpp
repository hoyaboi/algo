#include <bits/stdc++.h>
using namespace std;

int D[1000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int length = 0;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        D[num] = D[num-1] + 1;
        length = max(length, D[num]);
    }
    cout << n-length;
}

// https://www.acmicpc.net/problem/7570