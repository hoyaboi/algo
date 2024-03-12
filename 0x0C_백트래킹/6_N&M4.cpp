#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func(int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}
void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(k != 0 && arr[k-1] > i) continue;
        arr[k] = i;
        func(k+1);
    }
}

// https://www.acmicpc.net/problem/15652