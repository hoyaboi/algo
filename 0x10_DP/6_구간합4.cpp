#include <bits/stdc++.h>
using namespace std;

int D[1000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int num; cin >> num;
        D[i] = D[i-1] + num;
    }
    while(m--) {
        int start, end; cin >> start >> end;
        cout << D[end] - D[start - 1] << "\n";
    }
}

// https://www.acmicpc.net/problem/11659