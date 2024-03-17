#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> num(n);
    for(int& i : num) cin >> i;
    sort(num.begin(), num.end());

    int prev = 0;
    for(int i = 0; i < n; i++) {
        if(num[i] > prev+1) {
            cout << prev+1;
            return 0;
        }
        prev += num[i];
    }
    cout << prev+1;
    return 0;
}

// https://www.acmicpc.net/problem/2437