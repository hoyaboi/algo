#include <bits/stdc++.h>
using namespace std;

int n;
int D[40];

char func(int n, int k) {
    if(k == 3) {
        if(n == 1) return 'm';
        else return 'o';
    }
    int prev = D[k-1];
    if(n <= prev) return func(n, k-1);
    else if(n-prev-k > 0) return func(n-prev-k, k-1);
    else if(n-prev == 1) return 'm';
    else return 'o';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    D[3] = 3;
    int k = 3;
    for(int i = 4; D[i-1] < n; i++) {
        k = i;
        D[i] = 2*D[i-1] + i;
    }
    
    cout << func(n, k);
}

// https://www.acmicpc.net/problem/5904