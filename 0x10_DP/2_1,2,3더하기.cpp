#include <bits/stdc++.h>
using namespace std;

int arr[11];

int func(int);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << func(n) << "\n";
    }
}
int func(int n) {
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i = 4; i <= n; i++) 
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    return arr[n];
}

// https://www.acmicpc.net/problem/9095