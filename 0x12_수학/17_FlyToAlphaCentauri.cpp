#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        ll x, y; cin >> x >> y;
        int n = y - x;
        for(ll i = 0; i*i <= n; i++) {
            if(i*(i+1) < n && n <= (i+1)*(i+2))
                if(i*(i+1) + i+1 < n) cout << i*2 + 2 << "\n";
                else cout << i*2 + 1 << "\n";
        }
    }
}

// https://www.acmicpc.net/problem/1011