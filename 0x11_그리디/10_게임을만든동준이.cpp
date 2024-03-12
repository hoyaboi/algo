#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> R(n);
    for(int& i : R) cin >> i;
    int cnt = 0;
    for(int i = R.size()-2; i >= 0; i--)
        while(R[i] >= R[i+1]) {
            R[i]--;
            cnt++;
        }
    cout << cnt << "\n";
}

// https://www.acmicpc.net/problem/2847