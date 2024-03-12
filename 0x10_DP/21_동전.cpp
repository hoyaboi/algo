#include <bits/stdc++.h>
using namespace std;

int D[10002];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        fill(D, D + 10002, 0);
        int n; cin >> n;
        vector<int> money(n);
        for(int& i : money) cin >> i;
        int m; cin >> m;

        D[0] = 1;
        for(int i = 0; i < n; i++)
            for(int j = money[i]; j <= m; j++)
                D[j] += D[j - money[i]];

        cout << D[m] << "\n";
    }
}

// https://www.acmicpc.net/problem/9084