#include <bits/stdc++.h>
using namespace std;

int D[1002][1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b; cin >> a >> b;
    int size_a = a.size();
    int size_b = b.size();

    for(int i = 1; i <= size_a; i++)
        for(int j = 1; j <= size_b; j++) {
            if(a[i-1] == b[j-1]) D[i][j] = D[i-1][j-1] + 1;
            else D[i][j] = max(D[i-1][j], D[i][j-1]);
        }
    cout << D[size_a][size_b];
}

// https://www.acmicpc.net/problem/9251