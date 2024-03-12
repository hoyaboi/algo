#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> AR(n), BR(n);
    for(int& i : AR) cin >> i;
    for(int& i : BR) cin >> i;
    sort(AR.begin(), AR.end());
    sort(BR.begin(), BR.end(), [](auto& a, auto& b) {return a > b;});
    int sum = 0;
    for(int i = 0; i < n; i++) sum += AR[i] * BR[i];
    cout << sum;
}

// https://www.acmicpc.net/problem/1026