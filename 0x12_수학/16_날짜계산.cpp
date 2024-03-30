#include <bits/stdc++.h>
using namespace std;

int year[16][30][20];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int e, s, m;
    for(int i = 1; i <= 7980; i++) {
        e = (i%15 == 0) ? 15 : i%15;
        s = (i%28 == 0) ? 28 : i%28;
        m = (i%19 == 0) ? 19 : i%19;
        year[e][s][m] = i;
    }
    cin >> e >> s >> m;
    cout << year[e][s][m];
}

// https://www.acmicpc.net/problem/1476