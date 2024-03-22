#include <bits/stdc++.h>
using namespace std;

void func(int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n) {
        int e = 1;
        for(int i = 0; i < n; i++) e *= 3;
        func(e);
        cout << "\n";
    }
}
void func(int k) {
    if (k == 1) {
        cout << "-";
        return;
    }
    func(k / 3);
    for (int i = 0; i < k / 3; i++) cout << " ";
    func(k / 3);
}
// https://www.acmicpc.net/problem/4779