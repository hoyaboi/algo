#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10], ans[10];

void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }
    int tmp = 0;
    for(int i = 0; i < n; i++) {
        if(tmp == arr[i]) continue;
        if(k != 0 && ans[k-1] > arr[i]) continue;
        tmp = ans[k] = arr[i];
        func(k+1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    func(0);
}

// https://www.acmicpc.net/problem/15666