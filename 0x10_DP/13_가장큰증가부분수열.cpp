#include <bits/stdc++.h>
using namespace std;

int R[1002], D[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> R[i];
        D[i] = R[i];
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
            if(R[i] > R[j]) D[i] = max(D[i], D[j] + R[i]);

    cout << *max_element(D, D + n);
}

// https://www.acmicpc.net/problem/11055