#include <bits/stdc++.h>
using namespace std;

int R[2002];
bool D[2002][2002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> R[i];

    for(int i = 1; i <= n; i++) {
        D[i][i] = 1;
        if(R[i-1] == R[i]) D[i-1][i] = 1;
    }
    for(int gap = 2; gap < n; gap++)
        for(int i = 1; i <= n - gap; i++)
            if(R[i] == R[i+gap] && D[i+1][i+gap-1])
                D[i][i+gap] = 1;

    int m; cin >> m;
    while(m--) {
        int s, e; cin >> s >> e;
        cout << D[s][e] << "\n";
    }
}

// https://www.acmicpc.net/problem/10942