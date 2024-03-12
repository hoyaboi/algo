#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b; cin >> a >> b;
    for(int i = 1; b > a; i++) {
        if(b > 10) {
            int pos = b / 10 * 10;
            if(b - pos == 1) b /= 10;
            else if((b - pos) % 2 == 0) b /= 2;
            else break;
        }
        else {
            if(b % 2 != 0) break;
            b /= 2;
        }
        if(b == a) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
}

// https://www.acmicpc.net/problem/16953