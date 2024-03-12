#include <bits/stdc++.h>
using namespace std;

int start[50000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1, j = 1; j <= 100000000; j = ++i * (i+1) / 2) start[i] = j;
    int n; cin >> n;
    for(int i = 1; i <= 50000; i++)
        if(n <= start[i]) {
            int tmp = start[i] - n;
            if(i % 2 == 0) cout << i-tmp << "/" << 1+tmp;
            else cout << 1+tmp << "/" << i-tmp;
            break;
        }
}

// https://www.acmicpc.net/problem/1193