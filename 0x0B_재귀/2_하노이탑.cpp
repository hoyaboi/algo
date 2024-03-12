#include <bits/stdc++.h>
using namespace std;

void tower(int, int, int);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k; cin >> k;
    cout << (1 << k) - 1 << "\n";
    tower(1, 3, k);
}
void tower(int a, int b, int k) {
    if(k == 1) {
        cout << a << " " << b << "\n";
        return;
    }
    tower(a, 6-a-b, k-1);
    cout << a << " " << b << "\n";
    tower(6-a-b, b, k-1);
}

// https://www.acmicpc.net/problem/11729