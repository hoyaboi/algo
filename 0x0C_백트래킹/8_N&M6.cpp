#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans[10], arr[10];
bool isUsed[10];

void func(int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    func(0);
}
void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!isUsed[i] && ans[k-1] < arr[i]) {
            ans[k] = arr[i];
            isUsed[i] = 1;
            func(k+1);
            isUsed[i] = 0;
        }
    }
}

// https://www.acmicpc.net/problem/15655