#include <bits/stdc++.h>
using namespace std;

int calender(int, int, int, int);
int GCD(int, int);
int LCM(int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int m, n, x, y; cin >> m >> n >> x >> y;
        cout << calender(m, n, x, y) << "\n";
    }
}
int calender(int m, int n, int x, int y) {
    int l = LCM(m, n);
    for(int i = x; i <= l; i += m)
        if(i % n == y % n) return i;
    return -1;
}
int GCD(int a, int b) {
    if(b == 0) return a;
    return GCD(b, a % b);
}
int LCM(int a, int b) {
    return a / GCD(a, b) * b;
}


// https://www.acmicpc.net/problem/6064