#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, i = 1; 
    while(true) {
        cin >> a >> b >> c; 
        if(a == 0 && b == 0 && c == 0) break;
        cout << "Case " << i++ << ": " << (c/b)*a + (c%b > a ? a : c%b) << "\n";
    }
}

// https://www.acmicpc.net/problem/4796