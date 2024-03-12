#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 2; i * i <= n;) {
        if(n % i == 0) {
            cout << i << "\n";
            n /= i;
        }
        else i++;
    }
    if(n != 1) cout << n;
}

// https://www.acmicpc.net/problem/11653