#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    int cnt = 0;
    for(int i = n-1; i >= 0; i--)
        if(a[i] <= k) {
            cnt += k / a[i];
            k -= k/a[i] * a[i];
        }
    cout << cnt;
}

// https://www.acmicpc.net/problem/11047