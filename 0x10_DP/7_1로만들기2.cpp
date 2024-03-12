#include <bits/stdc++.h>
using namespace std;

int D[1000002];
int path[1000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    D[1] = 0;
    D[2] = 1;
    path[2] = 1;
    for(int i = 3; i <= n; i++) {
        D[i] = D[i-1] + 1;
        path[i] = i-1;
        if(i%2 == 0 && D[i/2] + 1 < D[i]) {
            D[i] = D[i/2] + 1;
            path[i] = i/2;
        }
        if(i%3 == 0 && D[i/3] + 1 < D[i]) {
            D[i] = D[i/3] + 1;
            path[i] = i/3;
        }
    }
    cout << D[n] << "\n";

    int i = n;
    cout << i << " ";
    while(path[i] != 0) {
        cout << path[i] << " ";
        i = path[i];
    }
}

// https://www.acmicpc.net/problem/12852