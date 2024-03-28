#include <bits/stdc++.h>
using namespace std;

int D[10002], R[102];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> R[i];

    D[0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = R[i]; j <= k; j++)
            D[j] += D[j - R[i]];

    cout << D[k];
}

// https://www.acmicpc.net/problem/2293